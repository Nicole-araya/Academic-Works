#include "NodeData.h"
NodeData::NodeData(){}

NodeData::NodeData(int dd){
	dData = dd;
}

void NodeData::displayItem(){
	cout << dData << ", ";
}
