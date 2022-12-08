#ifndef SOCKET_H
#define SOCKET_H

#include "node.h"
#include "properties.h"

class Socket
{
private:
    Node* m_node;
    IProperty* m_property;
public:
    Node* node();
    void setNode(Node* n);

    IProperty* property();
    void setProperty(IProperty* newProperty);
};

#endif
