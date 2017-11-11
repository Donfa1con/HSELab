#pragma once
#include "nonstandartacid.h"
#include "abstractacid.h"
#include <QString>
#include <vector>
#include <algorithm>

class NonStandartAcid : public AbstractAcid
{
public:
    NonStandartAcid(QString const& name);
    NonStandartAcid(NonStandartAcid const& obj);
    ~NonStandartAcid() = default;
    void setName(const QString &name);
    QString getLongName();
private:
    QString name;
};
