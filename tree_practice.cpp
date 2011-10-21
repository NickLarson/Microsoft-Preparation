#include <algorithm>
#include <iostream>
#include <stack>

/*This is practice for my Microsoft interview*/

/*Begin linked list practice: 10/20/2011 7:31pm*/

class root{
public:
	int val;
	root* left;
	root* right;
};

/*Iterative post order tree walk*/
void iterWalk(root* top)
{
	using namespace std;
	if(!top)
		cout << "empty\n";
	else
	{
		std::stack<root*> pile;
		root* curr = top;
		while(true)
		{
			if(curr)
			{
			std::cout << curr->val << "\n";
			pile.push(curr);
			curr = curr->left;
			}
			else
			{
			if(pile.empty())
				break;
			root* up = pile.top();
			pile.pop();
			curr = up->right;
			}
		}
	}
}
/*I'll try to simplify*/

void recurseWalk(root* top)
{
	if(!top)
		std::cout << "";
	else
	{
		root* curr = top;
		std::cout << curr->val << "\n";
		recurseWalk(curr->left);
		recurseWalk(curr->right);
	}
}

int ancestor(root* top, int a, int b)
{
	if(!top)
		return 0;
	root* curr = top;
	while(true)
	{
		if(a < curr->val && b < curr->val)
			curr = curr->left;
		if(b > curr->val && a > curr->val)
			curr = curr->right;
		else
			return curr->val;
	}
}

int main()
{
/*Prolly a better way to do this tree set up... pain in the ass!*/
	root* one = new root();
	root* two = new root();
	root* three = new root();
	root* four = new root();
	root* five = new root();
	root* six = new root();
	root* seven = new root();
	root* eight = new root();
	root* nine = new root();
	one->val = 7;
	two->val = 3;
	three->val = 9;
	four->val = 2;
	five->val = 4;
	six->val = 8;
	seven->val = 14;
	eight->val = 10;
	nine->val = 12;
	one->left = two;
	one->right = three;
	two->left = four;
	two->right = five;
	three->left = six;
	three->right = seven;
	seven->left = eight;
	seven->right = nine;
	std::cout << "Iterative tree walk (DFS)\n";
	iterWalk(one);
	std::cout << "\nRecursive tree walk (BFS)\n";
	recurseWalk(one);
	std::cout << "\nAncestor node of 2 and 4 is 3:\n";
	std::cout << ancestor(one, 2, 4);
	std::cout << "\nAncestor node of 4 and 2 is 3:\n";
	std::cout << ancestor(one, 4, 2);
	std::cout << "\nAncestor node of 12 and 4 is 7:\n";
	std::cout << ancestor(one, 12, 4);
	std::cout << "\nAncestor node of 10 and 8 is 9:\n";
	std::cout << ancestor(one, 10, 8);
	std::cout << "\nAncestor node of 0 and 15 is ???:\n";
	std::cout << ancestor(one, 0, 15);

/*Set up done... time to walk around le christmas tree*/
}