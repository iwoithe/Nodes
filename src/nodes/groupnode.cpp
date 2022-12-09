#include "groupnode.h"

#include "../properties.h"

VariantMap GroupNode::metaData()
{
    return {
        {"name", "Add"},
        {"author", "Ilias Woithe"},
        {"version", "1.0.0"},
        {"category", "Math"},
        {"description", "Add two numbers together"}
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
    output->setValue(output->defaultValue());
}

void GroupNode::evaluation()
{
    m_nodeTree->evaluate();
    property<IntegerProperty*>("output")->setValue(m_nodeTree->outputNode()->property<IntegerProperty*>("input")->value());
    setNeedExec(false);
}

NodeTree* GroupNode::nodeTree()
{
    return m_nodeTree;
}
