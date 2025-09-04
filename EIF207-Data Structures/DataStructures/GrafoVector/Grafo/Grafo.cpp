#include <iostream>
#include "Graph.h"
int main(){
    Graph<int> idk;
    Edge<int> piko(new int(1), new int(5));
    Edge<int> adea(new int(3), new int(5));
    Edge<int> ainose(9, 54);



    idk.insertEdge(piko);
    idk.insertEdge(adea);
    idk.insertEdge(ainose);
    idk.eraseEdge(piko);
    cout<<idk.adyacente(3, 5)<<endl;

    cout<<idk.toString();
}
