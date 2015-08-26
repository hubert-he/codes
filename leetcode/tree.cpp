#include <iostream>
#include <fstream>

using namespace std;


class Tree
{
public:
	Tree();
	~Tree();
private:
};

struct BinaryTreeNode
{
	int val;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};
class  BinaryTree
{
public:
	 BinaryTree(struct BinaryTreeNode *r = NULL) 
	 	{root = r;}
	~ BinaryTree();

	/* data */
	struct BinaryTreeNode *root;

};

void readBSTHelper(int min, int max, int &insertVal,
                   BinaryTree *&p, ifstream &fin) 
{
  if (insertVal > min && insertVal < max) {
    int val = insertVal;
    cout << val << endl;
    p = new BinaryTree(val);
    if (fin >> insertVal) {
      readBSTHelper(min, val, insertVal, p->left, fin);
      readBSTHelper(val, max, insertVal, p->right, fin);
    }
  }
}
 
void readBST(BinaryTree *&root, ifstream &fin) {
  int val;
  fin >> val;
  cout << val << endl;
  readBSTHelper(INT_MIN, INT_MAX, val, root, fin);
}


int main()
{
	ifstream fd;
	fd.open("treeseq.txt", ios::in);
	BinaryTree *root = NULL;
	readBST(root, fd);
	return 0;
}