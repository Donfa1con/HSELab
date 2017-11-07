#pragma once

#include <QString>
#include <QRegExp>


class AminoAcid
{
public:
    AminoAcid() = default;
    AminoAcid(QString name);
    AminoAcid(const AminoAcid & object);
    ~AminoAcid() = default;
    virtual QString getName();
    QString getLongName();
    virtual void setName(QString const& name);

    virtual AminoAcid& operator = (const AminoAcid& right); // 2 Laba
private:
    QChar name;
};
