#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

using namespace std; 

struct cbnode
{
	string val;
	cbnode* next;
};

cbnode* root;

void insert (string newval);
void remove ();
void print ();
int size = 0;
int buffermax;

int main ()
{
	int n;
	string in;
	cin >> buffermax;
	char cmd('0');
	
	root = NULL;
	
	do{
		cin >> cmd;
		switch (cmd){
			case 'A':
				cin >> n;
				for (; n; n--){
					cin >> in;
					insert (in);
				}
				break;

			case 'R':
				cin >> n;
				for (; n; n--){
					remove ();
				}
				break;

			case 'L':
				print ();
				break;
		}
	}while (cmd != 'Q');
	return 0;
}

void insert (string newval)
{
	if (root == NULL)
	{
		root = new cbnode();
		root->val = newval;
		root->next = root;
		size = 1;
	}
	else
	{
		if (size < buffermax){
			cbnode* chain = new cbnode();
			chain->next = root->next;
			chain->val = newval;
			root->next = chain;
			root = chain;
			size++;
		}
		else{
			root = root->next;
			root->val = newval;
		}
	}
}

void remove ()
{
	if (root->next == root)
	{
		delete root;
		root = NULL;
		size = 0;
	}
	else{
		cbnode* newnext = root->next->next;
		delete root->next;
		root->next = newnext;
		size--;	
	}
}

void print ()
{
	cbnode* walker = root->next;
	do{
		cout << walker->val << endl;
		walker = walker->next;
	}while (walker != root->next);
}
