#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>

// Using /sys/dev/block/
// opendir and readdir to gather all info on the directories
// Find uevent file in the directory and determine if it is a partition
// Once found, read the size file to get the size
// Print the partition name and size

std::vector<std::string> findPartitions(std::string path) {
    DIR *dir;
    struct dirent *diread;
    std::vector<std::string> partitions;
    std::vector<std::string> devices;

    // Opens the directory and makes a list of all devices
    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
	    std::string new_path (path);
	    new_path += "/";
	    new_path += diread->d_name;
            devices.push_back(new_path);
	}
	closedir(dir);
    } else {
        perror("opendir");
    }

    // For each device, open the directory and read until the file name
    // is uevent, open the uevent file and determine if it is a partition
    // If so add the path to the results
    const char* uevent = "uevent";
    const char* part = "DEVTYPE=partition";
    int found{0};
    for (auto s : devices) {
	found = 0;
        if ((dir = opendir(s.c_str())) != nullptr) {
            while (!found && (diread = readdir(dir)) != nullptr) {
		if (strcmp(diread->d_name, uevent) == 0) {
		    std::string temp(s);
		    temp += "/uevent";
		    std::ifstream fs(temp);
		    std::string line;
		    if (fs.is_open()) {
			while (getline(fs, line)) {
			    if (strcmp(line.c_str(),part) == 0) {
				partitions.push_back(s);
			    }
			}
		    }
		    found = 1;
		}
	    }
	    closedir(dir);
	} else {
	    perror("opendir");
	}
    }
    return partitions;
}

// Gather the name and size from each partition
// Print the name, path, and size
void printInfo(std::vector<std::string> parts) {
    std::string name, size;
    for (auto s : parts) {
        std::string name_path (s);
	std::string size_path (s);
        // Get the size of the partition
        size_path += "/size";
	std::ifstream file(size_path);
	if (file.is_open()) {
	    getline(file, size);
	} else {
	    perror("ifstream opening");
	}

	// Get the name of the partition
	name_path += "/uevent";
	std::ifstream fs(name_path);
	std::string line;
	if (fs.is_open()) {
	    // Know format of uevent, skip two lines and take the third
	    getline(fs, line);
	    getline(fs, line);
	    // Now extract the name from this line
	    getline(fs, line);
	    name = line.substr(line.find("=") + 1);
  	} else {
	    perror("ifstream opening");
	}
	std::cout << "Partition: " << name << "\n";
	std::cout << "Path: " << s << "\n";
        std::cout << "Size: " << size << "\n\n";	
    } 
}

int main(int argc, char** argv) {
    std::vector<std::string> partitions = findPartitions("/sys/dev/block");
    printInfo(partitions);
    return 0;
}
