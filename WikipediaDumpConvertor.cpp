//============================================================================
// Name        : WikipediaDumpConvertor.cpp
// Author      : Eric Tang
// Version     :
// Copyright   : GPL 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <vector>

inline void usage(const char *program) {
	printf("Usage: %s /a/path/to/wikipedia/abstract/file\n", program);
	exit(0);
}

int main(int argc, char **argv) {
	if (argc < 2)
		usage(argv[0]);

	std::ifstream file("myfile", std::ios::binary);
	file.seekg(0, std::ios::end);
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<unsigned char> buffer(size);
	if (file.read((char *)buffer.data(), size)) {

	}
	return EXIT_SUCCESS;
}
