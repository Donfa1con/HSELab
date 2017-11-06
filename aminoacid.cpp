#include "aminoacid.h"
#include "aminoacidpairs.h"
#include <QDebug>

static QMap<QChar, QString> LONG_AMINO_ACID_PAIR = CREATE_LONG_AMINO_ACID_PAIR();
static QMap<QString, QChar> SHORT_AMINO_ACID_PAIR = CREATE_SHORT_AMINO_ACID_PAIR();

AminoAcid::AminoAcid(QString name) {
    this->setName(name);
}

AminoAcid::AminoAcid(const AminoAcid& obj) {
    this->name = obj.name;
}

QString AminoAcid::getLongName() {
    return LONG_AMINO_ACID_PAIR[name];
}

QString AminoAcid::getName() {
    return name;
}

void AminoAcid::setName(QString const& name) {
    if(name.size() == 1) {
        if(!LONG_AMINO_ACID_PAIR[name[0]][0].isLetter()) {
                 throw(std::exception());
        }
        this->name = name[0];
    } else {
        if(!SHORT_AMINO_ACID_PAIR[name].isLetter()) {
            throw(std::exception());
        }
        this->name = SHORT_AMINO_ACID_PAIR[name];
    }
}

AminoAcid& AminoAcid::operator = (const AminoAcid& right) {
    if (this == &right) {
        return *this;
    }
    this->name = right.name;
    return *this;
}
