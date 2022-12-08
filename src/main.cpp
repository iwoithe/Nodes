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

    numberNode1->property<IntegerProperty*>("number")->setValue(5);
    numberNode2->property<IntegerProperty*>("number")->setValue(3);

    numberNode1->property<IntegerProperty*>("number")->linkProperty(addNode->property<IntegerProperty*>("value1"));
    numberNode2->property<IntegerProperty*>("number")->linkProperty(addNode->property<IntegerProperty*>("value2"));
    addNode->property<IntegerProperty*>("result")->linkProperty(outputNode->property<IntegerProperty*>("input"));

    nodeTree->evaluate();

    return 0;
}
