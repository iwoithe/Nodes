#include "outputnode.h"

#include <iostream>

VariantMap OutputNode::metaData()
{
    return {
        {"name", Variant::fromValue("Output")},
        {"author", Variant::fromValue("Ilias Woithe")},
        {"version", Variant::fromValue("1.0.0")},
        {"category", Variant::fromValue("Output")},
        {"description", Variant::fromValue("Prints any value inputted")}
    };
}

void OutputNode::initProperties()
{
    IntegerProperty* input = new IntegerProperty();
    input->setDefaultValue(0);
    input->setType(PropertyType::INPUT);
    input->setValue(0);
    addProperty("input", input);
}

void OutputNode::mutedEvaluation()
{
    // Can't mute the output node
    evaluation();
}

void OutputNode::evaluation()
{
    std::cout << "Output Value: " << property<IntegerProperty*>("input")->value().toInt() << std::endl;
}
