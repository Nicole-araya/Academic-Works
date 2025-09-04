#pragma once
#include "NodeData.h"

const int ORDER = 4;
class Node{
private:
	int numItems;
	Node *parent;
	Node **childArray;//no se si dejarlo asi o ponerle solo un *
	NodeData **itemArray;

public: 
	Node();
	void setParent(Node* nodo);
	void connectChild(int childNum, Node* child);
	Node* disconnectChild(int childNum);
	Node* getChild(int childNum);
	Node* getParent();
	bool isLeaf();
	int getNumItems();
	void setNumItems(int theValue);
	NodeData* getItem(int index);
	NodeData* setItem(int index, NodeData* theValue);
	bool isFull();

	int insertItem(NodeData* newItem);
	void insertatfront(NodeData* newItem);
	NodeData* removeItem();

	void displayNode();
	void displayvalue(int j);
	void deletenodevalue(int theValue);
	void deletevalue(int theValue, string side);
	Node* getsibiling(int theValue);
};

