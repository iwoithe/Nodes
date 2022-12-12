#include "numbernode.h"

#include <iostream>

#include "../properties.h"

VariantMap NumberNode::metaData()
{
    return {
        {"name", Variant::fromValue("Value")},
        {"author", Variant::fromValue(VersionNumber(1, 0, 0))},
        {"version", Variant::fromValue("1.0.0")},
        {"category", Variant::fromValue("Input")},
        {"description", Variant::fromValue("Store a number value")}
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
