#ifndef ADDNODE_H
#define ADDNODE_H

#include "../node.h"

class AddNode : public Node
{
public:
    VariantMap metaData() override;
    void initProperties() override;
    void mutedEvaluation() override;
    void evaluation() override;
};

#endif // ADDNODE_H
