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
    Variant m_defaultVariant;
    Variant m_variant;
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

    Variant defaultVariant() { return m_defaultVariant; }
    void setDefaultValue(Variant v) { m_defaultVariant.setValue(v); }
    void setDefaultValue(VariantType v) { m_defaultVariant.setValue(v); }

    Node* node() { return m_node; }
    void setNode(Node* n) { m_node = n; }

    int type() { return m_type; }
    void setType(int type) { m_type = type; };

    Variant variant() const { return m_variant; }
    void setValue(Variant v) { m_variant.setValue(v); }
    void setValue(VariantType v) { m_variant.setValue(v); }
};

// Sub-classes also implement the UI
class IntegerProperty : public IProperty
{
};

#endif // PROPERTIES_H
