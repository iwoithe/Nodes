#ifndef SOCKET_H
#define SOCKET_H

#include "node.h"
#include "properties.h"

class Socket
{
private:
    Node* m_node;
    AProperty* m_property;
public:
    Node* node();
    void setNode(Node* n);

    AProperty* property();
    void setProperty(AProperty* newProperty);
};

#endif
