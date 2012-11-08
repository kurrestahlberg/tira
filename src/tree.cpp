#include "tree.h"

#include <iostream>

using namespace std;

Tree::Tree() {

}

Tree::~Tree() {

}

void Tree::generateTree(char * data, int size) {
	countCharacters(data, size);
}

int * Tree::countCharacters(char * data, int size) {
	int * characterCounts = new int[256];
	
	for(int k = 0; k < 256; k++) {
		characterCounts[k] = 0;
	}

	for(int i = 0; i < size; i++) {
		unsigned char d = (unsigned char)data[i];
		characterCounts[d]++;
	}
	
	int charcount = 0;
	for(int j = 0; j < 256; j++) {
		if(characterCounts[j] > 0) {
			cout << j << ": " << characterCounts[j] << endl;
			charcount++;
		}
	}
	
	cout << "Total different chars " << charcount << endl;
	
	return characterCounts;
}