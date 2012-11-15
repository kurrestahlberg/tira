#include <iostream>
#include <fstream>

#include "tree.h"

using namespace std;

int main(int argc, char * const argv[]) {
	if(argc < 2) return -1;
	
	ifstream file;
	file.open(argv[1], ios::in | ios::binary | ios::ate);
	if(!file.is_open()) {
		return -2;
	}
	
	int size = 0;
	size = (int)file.tellg();
	char * data = new char[size];
	
	file.seekg(0, ios::beg);
	file.read(data, size);
	file.close();
	
	Tree tree;
	tree.generateTree(data, size);
	tree.dump();
	
	delete [] data;
	
	return 0;
	
}
