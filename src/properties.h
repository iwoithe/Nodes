#ifndef PROPERTIES_H
#define PROPERTIES_H

#include "types.h"

enum PropertyType {
    INPUT,
    OUTPUT
};

class Node;
class Socket;

class AProperty
{
private:
    // For consistency, should primarily use the following
    // std::vector<AProperty*> m_connectedSockets;
    std::vector<AProperty*> m_connectedInputProperties;
    std::vector<AProperty*> m_connectedOutputProperties;
    Variant m_defaultValue;
    Variant m_value;
    Node* m_node;
    int m_type = PropertyType::INPUT;
public:
    void linkProperty(AProperty* property)
    {
        if (property->type() == PropertyType::INPUT) {
            m_connectedInputProperties.push_back(property);
        } else if (property->type() == PropertyType::OUTPUT) {
            m_connectedOutputProperties.push_back(property);
        }
    };
    std::vector<AProperty*> connectedInputProperties() { return m_connectedInputProperties; };
    std::vector<AProperty*> connectedOutputProperties() { return m_connectedOutputProperties; };

    Variant defaultValue() { return m_defaultValue; }
    void setDefaultValue(Variant newDefaultValue) { m_defaultValue = newDefaultValue; }

    Node* node() { return m_node; }
    void setNode(Node* n) { m_node = n; }

    int type() { return m_type; }
    void setType(int type) { m_type = type; };

    Variant value() { return m_value; }
    void setValue(Variant newValue) { m_value = newValue; }
};

template<typename T> class IProperty : public AProperty
{
private:
    T m_defaultValue;
    T m_value;
public:
    T defaultValue() { return m_defaultValue; }
    void setDefaultValue(T newDefaultValue) { m_defaultValue = newDefaultValue; }

    T value() { return m_value; }
    void setValue(T newValue) { m_value = newValue; }
};

// Sub-classes also implement the UI
class IntegerProperty : public IProperty<int> {};

#endif // PROPERTIES_H
