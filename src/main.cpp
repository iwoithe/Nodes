#include <iostream>

#include "nodetree.h"

#include "nodes/addnode.h"
#include "nodes/numbernode.h"
#include "nodes/outputnode.h"

int main()
{
    NumberNode* numberNode1 = new NumberNode();
    NumberNode* numberNode2 = new NumberNode();
    AddNode* addNode = new AddNode();
    OutputNode* outputNode = new OutputNode();

    NodeTree* nodeTree = new NodeTree();
    nodeTree->addNode(numberNode1);
    nodeTree->addNode(numberNode2);
    nodeTree->addNode(addNode);
    nodeTree->addNode(outputNode);
    nodeTree->setOutputNode(outputNode);

    nodeTree->evaluate();

    return 0;
}
