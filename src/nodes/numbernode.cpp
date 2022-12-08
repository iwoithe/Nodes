#include "numbernode.h"

#include <iostream>

#include "../properties.h"

VariantMap NumberNode::metaData()
{
    return {
        {"name", "Value"},
        {"author", "Ilias Woithe"},
        {"version", "1.0.0"},
        {"category", "Input"},
        {"description", "Store a number value"}
    };
}

void NumberNode::initProperties()
{
    IntegerProperty* valueInput = new IntegerProperty();
    valueInput->setDefaultValue(0);
    valueInput->setType(PropertyType::OUTPUT);
    valueInput->setValue(0);
    addProperty("number", valueInput);
}

void NumberNode::mutedEvaluation() {}

void NumberNode::evaluation() {}
