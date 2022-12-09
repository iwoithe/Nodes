#include "outputnode.h"

#include <iostream>

VariantMap OutputNode::metaData()
{
    return {
        {"name", "Output"},
        {"author", "Ilias Woithe"},
        {"version", "1.0.0"},
        {"category", "Output"},
        {"description", "Prints any value inputted"}
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
    std::cout << "Output Value: " << std::get<int>(property<IntegerProperty*>("input")->value()) << std::endl;
}
