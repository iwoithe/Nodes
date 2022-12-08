#include "nodetree.h"

void NodeTree::addNode(Node* n)
{
    n->initProperties();
    m_nodes.push_back(n);
}

void NodeTree::evaluate()
{
    if (m_outputNode) {
        m_outputNode->checkInputs();
        m_outputNode->evaluation();
    }
}

void NodeTree::setInputNode(Node* n)
{
    m_inputNode = n;
}

void NodeTree::setOutputNode(Node* n)
{
    m_outputNode = n;
}
