#pragma once

#include "aminoacid.h"
#include "nonstandartacid.h"

#include <QFile>


class Protein
{
public:
    Protein();
    Protein(const Protein& object);
    ~Protein();
    void pushBack(AminoAcid* acid);
    void pushFront(AminoAcid* acid);
    AminoAcid* popBack();
    AminoAcid* popFront();
    AminoAcid* front() const ;
    AminoAcid* back() const ;
    Protein & operator+=(const Protein& right);
    void saveSequenceToFile(QString fileName);
    void loadSequenceFromFile(QString fileName);
    bool isEmpty() const ;
    size_t size() const ;

private:
    size_t _size;
    struct Node {
        AminoAcid* data;
        Node *next;
        Node *previous;
        Node(): next(nullptr), previous(nullptr) {}
        ~Node(){}
    } *tail, *head;
};
