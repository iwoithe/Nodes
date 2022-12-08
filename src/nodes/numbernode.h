#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "../node.h"

class NumberNode : public Node
{
public:
    VariantMap metaData() override;
    void initProperties() override;
    void mutedEvaluation() override;
    void evaluation() override;
};

#endif // NUMBERNODE_H
