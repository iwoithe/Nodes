#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <vector>
#include "types.h"

enum PropertyType {
    INPUT,
    OUTPUT
};

class Node;
class Socket;

// class IProperty
class IProperty
{
private:
    std::vector<IProperty*> m_connectedInputProperties;
    std::vector<IProperty*> m_connectedOutputProperties;
    Variant m_defaultValue;
    Variant m_value;
    Node* m_node;
    int m_type = PropertyType::INPUT;
public:
    void linkProperty(IProperty* property)
    {
        if (property->type() == PropertyType::INPUT) {
            m_connectedInputProperties.push_back(property);
        } else if (property->type() == PropertyType::OUTPUT) {
            m_connectedOutputProperties.push_back(property);
        }
    };
    std::vector<IProperty*> connectedInputProperties() { return m_connectedInputProperties; };
    std::vector<IProperty*> connectedOutputProperties() { return m_connectedOutputProperties; };

    Variant defaultValue() { return m_defaultValue; }
    void setDefaultValue(Variant newDefaultValue) { m_defaultValue = newDefaultValue; }

    Node* node() { return m_node; }
    void setNode(Node* n) { m_node = n; }

    int type() { return m_type; }
    void setType(int type) { m_type = type; };

    Variant value() { return m_value; }
    void setValue(Variant newValue) { m_value = newValue; }
};

// Sub-classes also implement the UI
class IntegerProperty : public IProperty
{
};

#endif // PROPERTIES_H
