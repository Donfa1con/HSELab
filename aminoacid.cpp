#include "aminoacid.h"
#include <QDebug>

#include <QMap>
#include <QString>
QMap<QChar, QString> LONG_AMINO_ACID_PAIR;
QMap<QString, QChar>SHORT_AMINO_ACID_PAIR;
void initPairs(){
    LONG_AMINO_ACID_PAIR['A'] = "Alanine";
    LONG_AMINO_ACID_PAIR['C'] = "Cysteine";
    LONG_AMINO_ACID_PAIR['D'] = "Aspartic acid";
    LONG_AMINO_ACID_PAIR['E'] = "Glutamic acid";
    LONG_AMINO_ACID_PAIR['F'] = "Phenylalanine";
    LONG_AMINO_ACID_PAIR['G'] = "Glycine";
    LONG_AMINO_ACID_PAIR['H'] = "Histidine";
    LONG_AMINO_ACID_PAIR['I'] = "Isoleucine";
    LONG_AMINO_ACID_PAIR['K'] = "Lysine";
    LONG_AMINO_ACID_PAIR['L'] = "Leucine";
    LONG_AMINO_ACID_PAIR['M'] = "Methionine";
    LONG_AMINO_ACID_PAIR['N'] = "Asparagine";
    LONG_AMINO_ACID_PAIR['P'] = "Proline";
    LONG_AMINO_ACID_PAIR['Q'] = "Glutamine";
    LONG_AMINO_ACID_PAIR['R'] = "Arginine";
    LONG_AMINO_ACID_PAIR['S'] = "Serine";
    LONG_AMINO_ACID_PAIR['T'] = "Threonine";
    LONG_AMINO_ACID_PAIR['V'] = "Valine";
    LONG_AMINO_ACID_PAIR['W'] = "Tryptophan";
    LONG_AMINO_ACID_PAIR['Y'] = "Tyrosine";
    SHORT_AMINO_ACID_PAIR["Alanine"] = 'A';
    SHORT_AMINO_ACID_PAIR["Cysteine"] = 'C';
    SHORT_AMINO_ACID_PAIR["Aspartic acid"] = 'D';
    SHORT_AMINO_ACID_PAIR["Glutamic acid"] = 'E';
    SHORT_AMINO_ACID_PAIR["Phenylalanine"] = 'F';
    SHORT_AMINO_ACID_PAIR["Glycine"] = 'G';
    SHORT_AMINO_ACID_PAIR["Histidine"] = 'H';
    SHORT_AMINO_ACID_PAIR["Alanine"] = 'A';
    SHORT_AMINO_ACID_PAIR["Isoleucine"] = 'I';
    SHORT_AMINO_ACID_PAIR["Lysine"] = 'K';
    SHORT_AMINO_ACID_PAIR["Leucine"] = 'L';
    SHORT_AMINO_ACID_PAIR["Methionine"] = 'M';
    SHORT_AMINO_ACID_PAIR["Asparagine"] = 'N';
    SHORT_AMINO_ACID_PAIR["Proline"] = 'P';
    SHORT_AMINO_ACID_PAIR["Glutamine"] = 'Q';
    SHORT_AMINO_ACID_PAIR["Arginine"] = 'R';
    SHORT_AMINO_ACID_PAIR["Serine"] = 'S';
    SHORT_AMINO_ACID_PAIR["Threonine"] = 'T';
    SHORT_AMINO_ACID_PAIR["Valine"] = 'V';
    SHORT_AMINO_ACID_PAIR["Tryptophan"] = 'W';
    SHORT_AMINO_ACID_PAIR["Tyrosine"] = 'Y';
    }

AminoAcid::AminoAcid(QString name) {
    if (LONG_AMINO_ACID_PAIR.isEmpty())
        initPairs();
    this->setName(name);
}

AminoAcid::AminoAcid(const AminoAcid& obj) {
    if (LONG_AMINO_ACID_PAIR.isEmpty())
        initPairs();
    this->name = obj.name;
}

QString AminoAcid::getLongName() {
    return LONG_AMINO_ACID_PAIR[name];
}

QString AminoAcid::getShortName() {
    return this->name;
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
