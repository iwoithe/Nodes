#include "addnode.h"

#include "../properties.h"

VariantMap AddNode::metaData()
{
    return {
        {"name", "Add"},
        {"author", "Ilias Woithe"},
        {"version", "1.0.0"},
        {"category", "Math"},
        {"description", "Add two numbers together"}
    };
}

void AddNode::initProperties()
{
    IntegerProperty* value1 = new IntegerProperty();
    value1->setDefaultValue(0);
    value1->setType(PropertyType::INPUT);
    value1->setValue(0);
    addProperty<int>("value1", value1);

    IntegerProperty* value2 = new IntegerProperty();
    value2->setDefaultValue(0);
    value2->setType(PropertyType::INPUT);
    value2->setValue(0);
    addProperty<int>("value1", value2);

    IntegerProperty* result = new IntegerProperty();
    result->setDefaultValue(0);
    result->setType(PropertyType::OUTPUT);
    result->setValue(0);
    addProperty<int>("result", result);
}

void AddNode::mutedEvaluation()
{
    IntegerProperty* result = property<IntegerProperty*>("result");
    result->setValue(result->defaultValue());
}

void AddNode::evaluation()
{
    IntegerProperty* value1 = property<IntegerProperty*>("value1");
    IntegerProperty* value2 = property<IntegerProperty*>("value2");
    IntegerProperty* result = property<IntegerProperty*>("result");

    result->setValue(value1->value() + value2->value());
    setNeedExec(false);
}

/*

onEvaluation:

checkInputs()

evaluation()
for outputProperty in outputProperties():
    for socket in outputProperty->connectSockets():
        connectedProperty = socket->property()
        connectedProperty->setValue(outputProperty->value())

# Continue with next node

*/
