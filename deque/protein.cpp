#include "protein.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <typeinfo>

Protein::~Protein() {
    while(_size) {
        delete this->popBack();
    }
}

Protein::Protein() {
    _size = 0;
    tail = nullptr;
    head = nullptr;
}

Protein::Protein(const Protein &object) {
    Protein::Node *iterator = object.head;
    this->_size = 0;
    while(iterator) {
        this->pushBack(iterator->data);
        iterator = iterator->next;
    }
}

AminoAcid* Protein::back() const {
    if(!_size) {
        throw(std::exception());
    }
    return this->tail->data;
}

AminoAcid* Protein::front() const {
    if(!_size) {
        throw(std::exception());
    }
    return this->head->data;
}

bool Protein::isEmpty() const {
    return !bool(_size);
}

size_t Protein::size() const {
    return _size;
}

void Protein::pushBack(AminoAcid* acid) {
    AminoAcid * newAcid;
    if(acid->getName().size() == 1) {
        newAcid = new AminoAcid(*acid);
    } else {
        newAcid = new NonStandartAcid(acid->getName());
    }
    Protein::Node *newTail = new Protein::Node();
    if(!_size) {
        head = newTail;
        tail = newTail;
    } else {
        newTail->previous = tail;
        tail->next = newTail;
        tail = newTail;
    }
    newTail->data = newAcid;
    _size++;
}

void Protein::pushFront(AminoAcid* acid) {
    AminoAcid * newAcid;
    if(acid->getName().size() == 1) {
        newAcid = new AminoAcid(*acid);
    } else {
        newAcid = new NonStandartAcid(acid->getName());
    }
    Protein::Node *newHead = new Protein::Node();
    if(!_size) {
        head = newHead;
        tail = newHead;
    } else {
        newHead->next = head;
        head->previous = newHead;
        head = newHead;
    }
    newHead->data = newAcid;
    _size++;
}

AminoAcid* Protein::popBack() {
    AminoAcid *popAcid;
    if(tail->data->getName().size() == 1) {
        popAcid = new AminoAcid(*tail->data);
    } else {
        popAcid = new NonStandartAcid(tail->data->getName());
    }
    if(!_size) {
        throw(std::exception());
    }
    delete tail->data;
    if(_size == 1) {
        delete tail;
        tail = nullptr;
        head = nullptr;
    } else {
        Protein::Node *tempNode = tail;
        tail = tail->previous;
        delete tempNode;
        tail->next = nullptr;
    }
    _size--;
    return popAcid;
}

AminoAcid* Protein::popFront() {
    AminoAcid *popAcid;
    if(head->data->getName().size() == 1) {
        popAcid = new AminoAcid(*head->data);
    } else {
        popAcid = new NonStandartAcid(head->data->getName());
    }
    if(!_size) {
        throw(std::exception());
    }

    delete head->data;
    if(_size == 1) {
        delete head;
        tail = nullptr;
        head = nullptr;
    } else {
        Protein::Node *tempNode = head;
        head = head->next;
        delete tempNode;
    }
    _size--;
    return popAcid;
}

Protein & Protein::operator+=(const Protein& right) {
    Protein::Node *iteratorRight;
    Protein::Node *iteratorLeft = this->tail;
    Protein::Node *startIteratorLeft;
    int iter = (this->_size > right.size() ? right.size() - 1 : this->_size - 1);
    if(this->_size && right.size()) {

        while(iter--) {
            iteratorLeft = iteratorLeft->previous;
        }

        startIteratorLeft = iteratorLeft;
        bool isOverlap = false;

        while(!isOverlap && startIteratorLeft) {
            isOverlap = true;
            iteratorLeft = startIteratorLeft;
            iteratorRight = right.head;

            while(iteratorLeft) {
                qDebug() << iteratorLeft->data->getName() << iteratorRight->data->getName();
                if(iteratorLeft->data->getName() != iteratorRight->data->getName()) {
                    isOverlap = false;
                }
                iteratorLeft = iteratorLeft->next;
                iteratorRight = iteratorRight->next;
            }

            startIteratorLeft = startIteratorLeft->next;
        }

        while(iteratorRight && isOverlap) {
            qDebug() << this->front()->getName();
            qDebug() << this->back()->getName();
            qDebug() << iteratorRight->data->getName() << 111;
            this->pushBack(iteratorRight->data);
            iteratorRight = iteratorRight->next;
        }
    }
    qDebug() << 222;
    qDebug() << this->front()->getName();
    qDebug() << this->back()->getName();
    qDebug() << 222;
    return *this;
}

//void Protein::saveSequenceToFile(QString fileName) {
//    QString aminoSequence = "";
//    Protein::Node *iterator = this->head;

//    while (iterator) {
//        aminoSequence += iterator->data->getName();
//        iterator = iterator->next;
//    }
//    QFile sequenceFile(fileName);

//    sequenceFile.open(QFile::WriteOnly);
//    sequenceFile.write(aminoSequence.toUtf8());
//    sequenceFile.close();
//}

void Protein::saveSequenceToFile(QString fileName) {
    QJsonArray aminoSequence;
    Protein::Node *iterator = this->head;

    while (iterator) {
        aminoSequence.push_back(QJsonValue((*iterator->data).getName()));
        iterator = iterator->next;
    }
    QJsonDocument doc(aminoSequence);
    QFile sequenceFile(fileName);
    sequenceFile.open(QFile::WriteOnly);
    sequenceFile.write(doc.toJson());
    sequenceFile.close();
}

//void Protein::loadSequenceFromFile(QString fileName) {
//    QFile sequenceFile(fileName);
//    if(!sequenceFile.exists()) {
//        throw(std::exception(), fileName);
//    }
//    sequenceFile.open(QFile::ReadOnly);

//    while(!this->isEmpty()) {
//        this->popBack();
//    }

//    QString aminoSequence(sequenceFile.readAll());

//    for(QChar acid: aminoSequence) {
//        AminoAcid tempAcid(acid);
//        this->pushBack(tempAcid);
//    }
//}

void Protein::loadSequenceFromFile(QString fileName) {
    QFile sequenceFile(fileName);
    if(!sequenceFile.exists()) {
        throw(std::exception(), fileName);
    }
    sequenceFile.open(QFile::ReadOnly);

    while(!this->isEmpty()) {
        this->popBack();
    }
    QString aminoSequence(sequenceFile.readAll());
    sequenceFile.close();

    QJsonDocument doc = QJsonDocument::fromJson(aminoSequence.toUtf8());
    QJsonArray array(doc.array());
    for(auto acid: array) {
        if(acid.toString().size() == 1) {
            AminoAcid *tempAcid = new AminoAcid(acid.toString());
            this->pushBack(tempAcid);
        } else {
            NonStandartAcid *tempAcid = new NonStandartAcid(acid.toString());
            this->pushBack(tempAcid);
        }
    }
}
