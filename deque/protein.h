#pragma once

#include "aminoacid.h"
#include "abstractacid.h"
#include "nonstandartacid.h"

#include <QFile>


class Protein
{
public:
    Protein();
    Protein(const Protein& object);
    ~Protein();
    void pushBack(AbstractAcid* acid);
    void pushFront(AbstractAcid* acid);
    AbstractAcid* popBack();
    AbstractAcid* popFront();
    AbstractAcid* front() const ;
    AbstractAcid* back() const ;
    Protein & operator+=(const Protein& right);
    void saveSequenceToFile(QString fileName);
    void loadSequenceFromFile(QString fileName);
    bool isEmpty() const ;
    size_t size() const ;
    QString getFormatedAcidNames();

private:
    size_t _size;
    struct Node {
        AbstractAcid* data;
        Node *next;
        Node *previous;
        Node(): next(nullptr), previous(nullptr) {}
        ~Node(){}
    } *tail, *head;
};
