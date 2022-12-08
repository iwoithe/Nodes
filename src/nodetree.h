#ifndef NODETREE_H
#define NODETREE_H

#include "node.h"

#include <vector>

class NodeTree
{
private:
    Node* m_inputNode;
    Node* m_outputNode;
    std::vector<Node*> m_nodes;
public:
    void addNode(Node* n);
    void evaluate();
    void setInputNode(Node* n);
    void setOutputNode(Node* n);
};

#endif // NODETREE_H
