#include "groupnode.h"

#include "../properties.h"

VariantMap GroupNode::metaData()
{
    return {
        {"name", Variant::fromValue("Group")},
        {"author", Variant::fromValue("Ilias Woithe")},
        {"version", Variant::fromValue(VersionNumber(1, 0, 0))},
        {"category", Variant::fromValue("Group")},
        {"description", Variant::fromValue("A collection of nodes")}
    };
}

void GroupNode::initProperties()
{
    IntegerProperty* input = new IntegerProperty();
    input->setDefaultValue(0);
    input->setType(PropertyType::INPUT);
    input->setValue(0);
    addProperty("input", input);

    IntegerProperty* output = new IntegerProperty();
    output->setDefaultValue(0);
    output->setType(PropertyType::OUTPUT);
    output->setValue(0);
    addProperty("output", output);
}

void GroupNode::mutedEvaluation()
{
    IntegerProperty* output = property<IntegerProperty*>("output");
    output->setValue(output->defaultVariant());
}

void GroupNode::evaluation()
{
    m_nodeTree->evaluate();
    property<IntegerProperty*>("output")->setValue(m_nodeTree->outputNode()->property<IntegerProperty*>("input")->variant());
    setNeedExec(false);
}

NodeTree* GroupNode::nodeTree()
{
    return m_nodeTree;
}
