#pragma once
#include "Node.h"

class TwoFour
{
private:
	Node* root;

public:
	TwoFour();
	void insert(int dValue);
	void split(Node* node);
	Node* getNextChild(Node* theNode, int theValue);
	void displayTree(int i);
	void recDisplayTree(Node* thisNode, int level, int childNumbre);
	void inorderdisplay(Node* thisNode, int level, int childNumber);
	Node* find(int theValue);
	Node* findvalue(Node* theNode, int theValue);
	Node* deleteN(Node* currnode, int theValue);
	Node* deleteleaf_cases(Node* thisNode, int theValue);
	Node* balancetree(Node* currnode);
	Node* getinordernode(Node* thisNode);
};

