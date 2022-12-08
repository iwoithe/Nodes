#ifndef OUTPUTNODE_H
#define OUTPUTNODE_H

#include "../node.h"

class OutputNode : public Node
{
public:
    VariantMap metaData() override;
    void initProperties() override;
    void mutedEvaluation() override;
    void evaluation() override;
};

#endif // OUTPUTNODE_H
