#pragma once
#include "nonstandartacid.h"
#include "aminoacid.h"
#include <QString>
#include <vector>
#include <algorithm>

class NonStandartAcid : public AminoAcid
{
public:
    NonStandartAcid(QString const& name);
    NonStandartAcid(NonStandartAcid const& obj);
    void setName(const QString &name) override;
    QString getName();

public:
    QString name;
};
