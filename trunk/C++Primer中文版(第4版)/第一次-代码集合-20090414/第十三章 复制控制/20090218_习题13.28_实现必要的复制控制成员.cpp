#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
	TreeNode();
	TreeNode(const TreeNode &orig);
	~TreeNode();
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

TreeNode::TreeNode():
count(0), left(0), right(0)
{ }

TreeNode::TreeNode(const TreeNode &orig) :
value(orig.value)
{
	count = orig.count;
	if (orig.left)
		left = new TreeNode(*orig.left);
	else
		left = 0;
	if (orig.right)
		right = new TreeNode(*orig.right);
	else
		right = 0;
}

TreeNode::~TreeNode()
{
	if (left)
		delete left;
	if (right)
		delete right;
}

class BinStrTree {
public:
	BinStrTree();
	BinStrTree(const BinStrTree&);
	~BinStrTree();
private:
	TreeNode *root;
};

BinStrTree::BinStrTree() : root(0)
{ }

BinStrTree::BinStrTree(const BinStrTree &orig)
{
	if (orig.root)
		root = new TreeNode(*orig.root);
	else
		root = 0;
}

BinStrTree::~BinStrTree()
{
	if (root)
		delete root;
}

int main()
{
	return 0;
}