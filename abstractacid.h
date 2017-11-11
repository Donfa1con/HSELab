#pragma once

#include <QString>

class AbstractAcid
{
public:
    virtual QString getLongName() = 0;
    virtual void setName(QString const& name) = 0;
};
