class TreeNode;

class Tree {

public:
	Tree();
	~Tree();
	void generateTree(char * data, int size);
	
private:
	TreeNode * root;
	
	int * countCharacters(char * data, int size);
};