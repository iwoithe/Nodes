#ifndef GROUPNODE_H
#define GROUPNODE_H

#include "../node.h"
#include "../nodetree.h"

class GroupNode : public Node
{
private:
    NodeTree* m_nodeTree = new NodeTree();
public:
    VariantMap metaData() override;
    void initProperties() override;
    void mutedEvaluation() override;
    void evaluation() override;

    NodeTree* nodeTree();
};

#endif // GROUPNODE_H
