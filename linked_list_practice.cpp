#include <iostream>
/*This is practice for my Microsoft interview*/

/*Begin linked list practice: 10/20/2011 6:34*/
class node{
	public:
	node(int n) : val(n){}
	node* next;
	int val;
};

node* reverse(node* root)
{
	node* curr = root;
	node* nList = NULL;
	while(true)
	{
		if(!curr)
			return nList;
		else
		{
			node* temp = curr->next;
			curr->next = nList;
			nList = curr;
			curr = temp;
		}
	}
	return nList;
}

void printNodes(node* root)
{
	node* curr = root;
	while(curr)
	{
		std::cout << curr->val << "\n";
		curr = curr->next;
	}
}

/*Cyclic determination function*/
bool isCyclic(node* root)
{
	if(!root)
		return false;
	node* fast = root;
	node* slow = root;
	while(slow and fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast)
			return true;
	}
	return false;
}
/*End linked list practice*/


int main()
{
	using namespace std;
	/*Begin unit tests for linked list*/
	node* one = new node(1);
	node* two = new node(2);
	node* three = new node(3);
	one->next = two;
	two->next = three;
	three->next = NULL;
	cout << "The original list: \n";
	printNodes(one);
	node* rev = reverse(one);
	cout << "The reversed one: \n";
	printNodes(rev);
	/*End unit tests for singly linked list*/
	/*Create a cyclic linked list...
	Testing cyclic graph test...*/
	node* oneB = new node(3);
	node* twoB = new node(2);
	node* threeB = new node(1);
	oneB->next = twoB;
	twoB->next = threeB;
	threeB->next = oneB;
	cout << "Is our non-cylic graph cyclic?\n";
	cout << isCyclic(rev);
	cout << "\nHow about our cyclic graph?\n";
	cout << isCyclic(oneB);
	node* one2 = NULL;
	cout << "\nHow about an empty graph?\n";
	cout << isCyclic(one2);
	/*End cyclic graph unit tests*/
}