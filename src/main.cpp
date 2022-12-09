#include <iostream>

#include "nodetree.h"

#include "nodes/addnode.h"
#include "nodes/groupnode.h"
#include "nodes/numbernode.h"
#include "nodes/outputnode.h"

int main()
{
    // TODO: Should probably split the examples into separate files

    // Example 1
    // ---------
    // NumberNode* numberNode1 = new NumberNode();
    // NumberNode* numberNode2 = new NumberNode();
    // AddNode* addNode = new AddNode();
    // OutputNode* outputNode = new OutputNode();

    // NodeTree* nodeTree = new NodeTree();
    // nodeTree->addNode(numberNode1);
    // nodeTree->addNode(numberNode2);
    // nodeTree->addNode(addNode);
    // nodeTree->addNode(outputNode);
    // nodeTree->setOutputNode(outputNode);

    // numberNode1->property<IntegerProperty*>("number")->setValue(5);
    // numberNode2->property<IntegerProperty*>("number")->setValue(3);

    // addNode->setIsMuted(true);

    // numberNode1->property<IntegerProperty*>("number")->linkProperty(addNode->property<IntegerProperty*>("value1"));
    // numberNode2->property<IntegerProperty*>("number")->linkProperty(addNode->property<IntegerProperty*>("value2"));
    // addNode->property<IntegerProperty*>("result")->linkProperty(outputNode->property<IntegerProperty*>("input"));

    // nodeTree->evaluate();

    // addNode->setIsMuted(false);
    // nodeTree->evaluate();

    // Example 2
    // ---------
    NumberNode* numberNode = new NumberNode();
    GroupNode* groupNode = new GroupNode();
    AddNode* addNode = new AddNode();
    OutputNode* outputNode = new OutputNode();

    // The top-level node tree
    NodeTree* nodeTree = new NodeTree();
    nodeTree->addNode(numberNode);
    nodeTree->addNode(addNode);
    nodeTree->addNode(groupNode);
    nodeTree->addNode(outputNode);
    nodeTree->setOutputNode(outputNode);

    // The node group
    NumberNode* groupNumberNode1 = new NumberNode();
    NumberNode* groupNumberNode2 = new NumberNode();
    AddNode* groupAddNode = new AddNode();
    OutputNode* groupOutputNode = new OutputNode();

    NodeTree* groupTree = groupNode->nodeTree();
    groupTree->addNode(groupNumberNode1);
    groupTree->addNode(groupNumberNode2);
    groupTree->addNode(groupAddNode);
    groupTree->addNode(groupOutputNode);
    groupTree->setOutputNode(groupOutputNode);

    groupNumberNode1->property<IntegerProperty*>("number")->setValue(-2);
    groupNumberNode2->property<IntegerProperty*>("number")->setValue(3);

    groupNumberNode1->property<IntegerProperty*>("number")->linkProperty(groupAddNode->property<IntegerProperty*>("value1"));
    groupNumberNode2->property<IntegerProperty*>("number")->linkProperty(groupAddNode->property<IntegerProperty*>("value2"));
    groupAddNode->property<IntegerProperty*>("result")->linkProperty(groupOutputNode->property<IntegerProperty*>("input"));

    // Back to the top-level node tree
    numberNode->property<IntegerProperty*>("number")->setValue(5);

    // Link the properties together
    numberNode->property<IntegerProperty*>("number")->linkProperty(addNode->property<IntegerProperty*>("value1"));
    groupNode->property<IntegerProperty*>("output")->linkProperty(addNode->property<IntegerProperty*>("value2"));
    // groupNode->nodeTree()->evaluate();

    addNode->property<IntegerProperty*>("result")->linkProperty(outputNode->property<IntegerProperty*>("input"));
    nodeTree->evaluate();

    // while (true) {
    //     int numberNodeValue;
    //     std::cout << "Enter a number: ";
    //     std::cin >> numberNodeValue;
    //     numberNode->property<IntegerProperty*>("number")->setValue(numberNodeValue);
    //     nodeTree->evaluate();
    // }

    return 0;
}
