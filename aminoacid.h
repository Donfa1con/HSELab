#pragma once

#include "abstractacid.h"
#include <QString>
#include <QRegExp>


class AminoAcid : public AbstractAcid
{
public:
    AminoAcid(QString name);
    AminoAcid(const AminoAcid & object);
    QString getLongName();
    QString getShortName();
    void setName(QString const& name);
    AminoAcid& operator = (const AminoAcid& right);
private:
    QChar name;
};
