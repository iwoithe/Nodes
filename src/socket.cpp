#include "socket.h"

Node* Socket::node()
{
    return m_node;
}

void Socket::setNode(Node* n)
{
    m_node = n;
}

IProperty* Socket::property()
{
    return m_property;
}

void Socket::setProperty(IProperty* newProperty)
{
    m_property = newProperty;
}
