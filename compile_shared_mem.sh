#!/bin/bash

g++ -g server.cpp -o server sharedmem.pb.cc protobuf/src/.libs/libprotobuf.so
g++ -g writer.cpp -o writer sharedmem.pb.cc protobuf/src/.libs/libprotobuf.so
g++ -g reader.cpp -o reader sharedmem.pb.cc protobuf/src/.libs/libprotobuf.so 
