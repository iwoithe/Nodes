#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <iostream>
#include <vector>

#include "types.h"

enum PropertyType {
    INPUT,
    OUTPUT
};

class Node;

class IProperty
{
private:
    Variant m_defaultValue;
    // TODO: Change to m_variant as it now makes more sense
    Variant m_value;
    Node* m_node;
    int m_type = PropertyType::INPUT;
public:
    std::vector<IProperty*> m_linkedInputProperties;
    std::vector<IProperty*> m_linkedOutputProperties;

    void linkProperty(IProperty* property)
    {
        if (type() == PropertyType::OUTPUT && property->type() == PropertyType::INPUT) {
            m_linkedInputProperties.push_back(property);
            property->m_linkedOutputProperties.push_back(this);
        } else if (type() == PropertyType::INPUT && property->type() == PropertyType::OUTPUT) {
            m_linkedOutputProperties.push_back(property);
            property->m_linkedInputProperties.push_back(this);
        }
    };

    std::vector<IProperty*> linkedInputProperties() { return m_linkedInputProperties; };
    std::vector<IProperty*> linkedOutputProperties() { return m_linkedOutputProperties; };

    Variant defaultValue() { return m_defaultValue; }
    void setDefaultValue(Variant newDefaultValue) { m_defaultValue.setValue(newDefaultValue); }
    void setDefaultValue(VariantType newDefaultValue) { m_defaultValue.setValue(newDefaultValue); }

    Node* node() { return m_node; }
    void setNode(Node* n) { m_node = n; }

    int type() { return m_type; }
    void setType(int type) { m_type = type; };

    Variant value() { return m_value; }
    void setValue(Variant newValue) { m_value.setValue(newValue); }
    void setValue(VariantType newValue) { m_value.setValue(newValue); }
};

// Sub-classes also implement the UI
class IntegerProperty : public IProperty
{
};

#endif // PROPERTIES_H
