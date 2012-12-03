#include <iostream>
#include <fstream>

#include "huffman.h"

using namespace std;

int main(int argc, char * const argv[]) {

	if(argc < 2)
	{
		cout << "Input file name missing" << endl;
		return -1;
	}
	
	
	if(0 == std::string("-x").compare(argv[1]))
	{
		if(argc < 3) 
		{
			cout << "File name missing" << endl;
			return -2;
		}
		
		cout << "Unpacking " << argv[2] << endl;
		Huffman huffman(argv[2]);
	}
	else
	{
	
		ifstream file;
		file.open(argv[1], ios::in | ios::binary | ios::ate);
		if(!file.is_open()) {
			cout << "Can't open " << argv[1] << endl;
			return -2;
		}
		
		int size = 0;
		size = (int)file.tellg();
		char * data = new char[size];
		
		file.seekg(0, ios::beg);
		file.read(data, size);
		file.close();
		
		Huffman huffman(data, size);
		string str(argv[1]);
		str.append(".huf");
		huffman.writeToFile(str);
		
		//Tree tree;
		//tree.generateTree(data, size);
		
		//cout << "Packed file size is " << treesize << "B" << endl;
		//cout << "Original size " << size << ", diff " << (size - treesize) << endl;
		//cout << "Pack percent " << (100.0f * ((float)treesize / (float)size)) << endl;
		
		delete [] data;
	}
	
	return 0;
	
}
