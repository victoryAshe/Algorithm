// 22-1 자료구조 과제물 #14. 수식 트리 계산
#include <iostream>
using namespace std;

class TreeNode
{
public:
	int data;
	TreeNode* left, * right;
	TreeNode(int x, TreeNode* l, TreeNode* r)
	{
		data = x; left = l; right = r;
	}
};

int evaluate(TreeNode* node)
{
	if (node == NULL) return 0;
	if (node ->left == NULL && node->right == NULL)
		return node->data;
	else
	{
		int op1 = evaluate(node->left);
		int op2 = evaluate(node->right);
		switch (node->data)
		{
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
	}
	return 0;
}


void main()
{
	TreeNode* n1, * n2, * n3, * n4, * n5, * n6, * n7, * root;
	n1 = new TreeNode(3, NULL, NULL);
	n2 = new TreeNode(2, NULL, NULL);
	n3 = new TreeNode('*', n1, n2);
	n4 = new TreeNode(5, NULL, NULL);
	n5 = new TreeNode(6, NULL, NULL);
	n6 = new TreeNode('*', n4, n5);
	n7 = new TreeNode('+', n3, n6);
	root = n7;

	cout << evaluate(root) << endl;

}

