# Linux
A collection of projects and functions related to the features of the Linux OS

-The contents of this repository include various programs that explore the features of the Linux OS
-There are shell scripts that explore the open processes and files on the system 
-There are C programs to examine and manipulate environment variables
-There are C programs to examine and process the current processes running on the system
-There is a C program to understand how input and output is redirected using file descriptors (redirect.c)
-There are two C programs exhibiting different methods of how to read directories (readdirs.c readdirs2.c)
-There is a C program for emulating pipes (pipe.c)
-There is a C program for checking the RSS usage of the disk (rss_usage.c) and a C++ program for printing paritions of the disk (print_partition.cpp)
-There are C programs for handling and distinguishing different signals, such as sigterm and sigquit
-There are C programs for understanding and using variable arguments
-Printf written in C
-Hexdump written in C
-There are text files which contain the dissection of the ELF file for a simple helloworld program

-The server and client programs, written in C, are centered around UNIX domain sockets and the abstract namespace ("unix_server.cpp" and "unix_client.cpp")
-The server and client send messages using Google protobuf, the inclusion of which was omitted to save space for my code in the repository
-"writeaddressbook" is a sample program which I used to understand protobuf before applying it to my UNIX domain server ("writer.cpp" and "reader.cpp")
-The protobuf definitions for the server can be found in "sharedmem.pb.cc" and similarly named files
