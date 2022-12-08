#ifndef NODE_H
#define NODE_H

#include <vector>

#include "types.h"
#include "properties.h"

class Node
{
private:
    bool m_needExec = false;
    std::map<std::string, IProperty*> m_properties = {};
public:
    void addProperty(std::string name, IProperty* property);
    void checkInputs();
    // TODO: `exec` instead of `evaluation`?
    virtual void evaluation();
    virtual void initProperties();
    std::vector<IProperty*> inputProperties();
    virtual VariantMap metaData();
    virtual void mutedEvaluation();
    std::vector<IProperty*> outputProperties();

    bool needExec();
    void setNeedExec(bool newValue);

    template<typename T> T property(std::string propertyName);
};

#endif // NODE_H
