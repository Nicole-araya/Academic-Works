#include "Node.h"

Node::Node() {
	parent = NULL;
	numItems = 0;
	childArray = new Node *[ORDER];
	itemArray = new NodeData * [ORDER - 1];

	for (int i = 0; i < ORDER; i++) {
		childArray[i] = NULL;
		if(i < ORDER - 1) itemArray[i] = NULL;
	}
}

void Node::setParent(Node* nodo)
{
	parent = nodo;
}



void Node::connectChild(int childNum, Node *child){
	childArray[childNum] = child;
	if(child != NULL)
		child->parent = this;
}

Node* Node::disconnectChild(int childNum){
	Node* tempNode = childArray[childNum];
	childArray[childNum] = NULL;
	return tempNode;
}

Node* Node::getChild(int childNum){
	return childArray[childNum];
}

Node* Node::getParent(){
	return parent;
}

bool Node::isLeaf(){
	return  (childArray[0] == NULL) ? true : false;
}

int Node::getNumItems(){
	return numItems;
}

void Node::setNumItems(int theValue){
	numItems = theValue;
}

NodeData* Node::getItem(int index){
	return itemArray[index];
}

NodeData* Node::setItem(int index, NodeData* theValue){
	itemArray[index] = theValue;
	return itemArray[index];
}

bool Node::isFull(){
	return (numItems == ORDER - 1) ? true : false;
}
int Node::insertItem(NodeData* newItem){
	numItems++; 
	int newKey = newItem->dData;

	for(int j = ORDER - 2; j >= 0; j--)
	{ 
		if(itemArray[j] == NULL)
			continue; 
		else 
		{
			int itsKey = itemArray[j]->dData;
			if(newKey < itsKey)
				itemArray[j + 1] = itemArray[j]; 
			else{
				itemArray[j + 1] = newItem; 
				return j + 1; 
			} 
		} 
	} 
	itemArray[0] = newItem; 
	return 0;
}

void Node::insertatfront(NodeData* newItem){
	int newKey = newItem->dData; 
	numItems++;
	for(int j = numItems - 1; j > 0; j--){
		itemArray[j] = itemArray[j - 1];
		connectChild(j + 1, disconnectChild(j));
	}
	connectChild(1, disconnectChild(0));
	itemArray[0] = newItem;
	connectChild(0, NULL);
}

NodeData* Node::removeItem(){
	NodeData* temp = itemArray[numItems - 1]; 
	itemArray[numItems - 1] = NULL;
	numItems--; 
	return temp; 
}

void Node::displayNode(){
	for(int j = 0; j < numItems; j++)
		itemArray[j]->displayItem(); 
}

void Node::displayvalue(int j){
	itemArray[j]->displayItem();
}

void Node::deletenodevalue(int theValue){
	int flag = -1;
	
	for(int i = 0; i < numItems; i++){
		if(theValue == itemArray[i]->dData){
			flag = i;
		}
		if(flag != -1 && i + 1 < numItems){
			itemArray[i]->dData = itemArray[i + 1]->dData;
		}
	}
	itemArray[numItems - 1] = NULL;
	numItems--; 
}

void Node::deletevalue(int theValue, string side){
	int flag = -1;
	
	for(int i = 0; i < numItems; i++){
		if(theValue == itemArray[i]->dData){
			flag = i;
		}
		if(flag != -1 && i + 1 < numItems){
			itemArray[i]->dData = itemArray[i + 1]->dData;
		}
	}
	itemArray[numItems - 1] = NULL;
	numItems--; 
}

Node* Node::getsibiling(int theValue){
	Node* x = NULL;
	Node* p = getParent();
	if(numItems != 0){
		for(int i = 0; i <= p->numItems; i++){
			if(p->childArray[i]->itemArray[0]->dData < theValue){
				x = p->childArray[i];
			}
		}
	} else if(numItems == 0){
		for(int i = 0; i <= p->numItems; i++){
			if(p->childArray[i]->itemArray[0] == NULL){
				
				if(i != 0){
					x = p->childArray[i - 1];
				}
			}
		}
	}
	return x;
}