#include "socket.h"

Node* Socket::node()
{
    return m_node;
}

void Socket::setNode(Node* n)
{
    m_node = n;
}

AProperty* Socket::property()
{
    return m_property;
}

void Socket::setProperty(AProperty* newProperty)
{
    m_property = newProperty;
}
