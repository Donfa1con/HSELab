#include "aminoacidpairs.h"

QMap<QChar, QString> CREATE_LONG_AMINO_ACID_PAIR() {
    QMap<QChar, QString> AMINO_ACID_PAIRS;
    AMINO_ACID_PAIRS['A'] = "Alanine";
    AMINO_ACID_PAIRS['C'] = "Cysteine";
    AMINO_ACID_PAIRS['D'] = "Aspartic acid";
    AMINO_ACID_PAIRS['E'] = "Glutamic acid";
    AMINO_ACID_PAIRS['F'] = "Phenylalanine";
    AMINO_ACID_PAIRS['G'] = "Glycine";
    AMINO_ACID_PAIRS['H'] = "Histidine";
    AMINO_ACID_PAIRS['I'] = "Isoleucine";
    AMINO_ACID_PAIRS['K'] = "Lysine";
    AMINO_ACID_PAIRS['L'] = "Leucine";
    AMINO_ACID_PAIRS['M'] = "Methionine";
    AMINO_ACID_PAIRS['N'] = "Asparagine";
    AMINO_ACID_PAIRS['P'] = "Proline";
    AMINO_ACID_PAIRS['Q'] = "Glutamine";
    AMINO_ACID_PAIRS['R'] = "Arginine";
    AMINO_ACID_PAIRS['S'] = "Serine";
    AMINO_ACID_PAIRS['T'] = "Threonine";
    AMINO_ACID_PAIRS['V'] = "Valine";
    AMINO_ACID_PAIRS['W'] = "Tryptophan";
    AMINO_ACID_PAIRS['Y'] = "Tyrosine";
    return AMINO_ACID_PAIRS;
}


QMap<QString, QChar> CREATE_SHORT_AMINO_ACID_PAIR() {
    QMap<QString, QChar> AMINO_ACID_PAIRS;
    AMINO_ACID_PAIRS["Alanine"] = 'A';
    AMINO_ACID_PAIRS["Cysteine"] = 'C';
    AMINO_ACID_PAIRS["Aspartic acid"] = 'D';
    AMINO_ACID_PAIRS["Glutamic acid"] = 'E';
    AMINO_ACID_PAIRS["Phenylalanine"] = 'F';
    AMINO_ACID_PAIRS["Glycine"] = 'G';
    AMINO_ACID_PAIRS["Histidine"] = 'H';
    AMINO_ACID_PAIRS["Alanine"] = 'A';
    AMINO_ACID_PAIRS["Isoleucine"] = 'I';
    AMINO_ACID_PAIRS["Lysine"] = 'K';
    AMINO_ACID_PAIRS["Leucine"] = 'L';
    AMINO_ACID_PAIRS["Methionine"] = 'M';
    AMINO_ACID_PAIRS["Asparagine"] = 'N';
    AMINO_ACID_PAIRS["Proline"] = 'P';
    AMINO_ACID_PAIRS["Glutamine"] = 'Q';
    AMINO_ACID_PAIRS["Arginine"] = 'R';
    AMINO_ACID_PAIRS["Serine"] = 'S';
    AMINO_ACID_PAIRS["Threonine"] = 'T';
    AMINO_ACID_PAIRS["Valine"] = 'V';
    AMINO_ACID_PAIRS["Tryptophan"] = 'W';
    AMINO_ACID_PAIRS["Tyrosine"] = 'Y';
    return AMINO_ACID_PAIRS;
}
