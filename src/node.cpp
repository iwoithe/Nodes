#include "node.h"

#include <iostream>

#include "properties.h"


void Node::addProperty(std::string name, IProperty* property)
{
    property->setNode(this);
    m_properties[name] = property;
}

void Node::checkInputs()
{
    inputProperties();
}

void Node::evaluation() {}

void Node::initProperties() {}

std::vector<IProperty*> Node::inputProperties()
{
    std::vector<IProperty*> inputProps = {};
    for (const auto& [key, value] : m_properties) {
        if (value->type() == PropertyType::INPUT) {
            inputProps.push_back(value);
        }
    }

    return inputProps;
}

VariantMap Node::metaData()
{
    return {
        {"name", ""},
        {"author", ""},
        {"version", ""},
        {"category", ""},
        {"description", ""}
    };
}

void Node::mutedEvaluation() {}

std::vector<IProperty*> Node::outputProperties()
{
    std::vector<IProperty*> inputProps = {};
    for (const auto& [key, value] : m_properties) {
        if (value->type() == PropertyType::OUTPUT) {
            inputProps.push_back(value);
        }
    }

    return inputProps;
}

template<typename T> T Node::property(std::string propertyName)
{
    auto foundProperty = m_properties.find(propertyName);
    if (foundProperty != m_properties.end()) {
        return static_cast<T>(foundProperty->second);
    } else {
        return nullptr;
    }
}

bool Node::needExec()
{
    return m_needExec;
}

void Node::setNeedExec(bool newValue)
{
    m_needExec = newValue;
}

// See https://stackoverflow.com/a/8752879
template IntegerProperty* Node::property(std::string propertyName);
