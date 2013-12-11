//============================================================================
// Name        : WikipediaDumpConvertor.cpp
// Author      : Eric Tang
// Version     :
// Copyright   : GPL 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

inline void usage(const char *program) {
	printf("Usage: %s /a/path/to/wikipedia/abstract/file\n", program);
	exit(0);
}

int main(int argc, char **argv) {
	if (argc < 2)
		usage(argv[0]);

	std::ifstream file(argv[1], std::ios::binary);
	file.seekg(0, std::ios::end);
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

//	std::vector<unsigned char> buffer(size)
	long buffer_size = 100 * 1024 * 1024; // 100M buffer size
	char *buffer = new char[buffer_size];
	long read_size = 0;
	long size_to_read = 0;
	char *start, *end;

	size_to_read = size < buffer_size ? size : buffer_size;

	do {
		if (file.read(buffer, size_to_read)) {
			start = buffer;

			end = strstr(start, "<links>");
			while (end != NULL) {
				while (start < end)
					cout << *start++;

				end = strstr(end, "</links>");
				if (end == NULL)
					break;
				else {
					start = end + 8;
					end = strstr(start, "<links>");
				}
			}
		}
		else {
			cerr << "failed to file, exiting." << endl;
			break;
		}
		read_size += size_to_read;
		size_to_read = (size - read_size) < buffer_size ? (size - read_size) : buffer_size;
	} while (read_size < size);

	delete [] buffer;
	return EXIT_SUCCESS;
}
