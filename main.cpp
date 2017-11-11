#include "aminoacid.h"
#include "nonstandartacid.h"
#include "deque/protein.h"
#include <QDebug>
#include <cassert>
#include <iostream>
#include <deque>
#include <string>
#include <typeinfo>
#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[]) {
//    qDebug() << "Test 1 (Initialization constructor with short name)";
//    try {
//        AminoAcid shortAcid("D");
//        qDebug() << shortAcid.getName();
//    } catch(...) {
//        qDebug() << "Invalid string";
//    }

//    qDebug() << "Test 2 (Initialization constructor with long name)";
//    try {
//        AminoAcid longAcid("Glutamine");
//        qDebug() << longAcid.getName();
//    } catch(...) {
//        qDebug() << "Invalid string";
//    }

//    qDebug() << "Test 3 (Initialization constructor with invalid name)";
//    try {
//        AminoAcid invalidAcid("qwewqewqe");
//    } catch(...) {
//        qDebug() << "Invalid string";
//    }

//    qDebug() << "Test 4 (Copy constructor)";
//    AminoAcid fromCopyAcid("V");
//    AminoAcid toCopyAcid(fromCopyAcid);
//    qDebug() << toCopyAcid.getName();

//    AminoAcid shortAcid("D");
//    qDebug() << "Test 5 (method getName())";
//    qDebug() << shortAcid.getName();

//    qDebug() << "Test 6 (method getLongName())";
//    qDebug() << shortAcid.getLongName();

//    qDebug() << "Test 7 (method setName())";
//    shortAcid.setName("T");
//    qDebug() << (shortAcid.getLongName());


 //Lab2
    AminoAcid AcidA("A");
    AminoAcid AcidC("C");
    AminoAcid AcidD("D");
    AminoAcid AcidE("E");
    AminoAcid AcidF("F");
    AminoAcid AcidG("G");
    {
    Protein protein1;
    try {
        protein1.back();
    } catch(...) {
        //qDebug() << "Deque is empty";
    }
    assert(protein1.isEmpty() == true);                  //isEmpty()
    protein1.pushBack(&AcidA);
    assert(protein1.size() == 1);                         //size()

    //assert(protein1.back()->getName() == "A");       //back()
    //assert(protein1.front()->getName() == "A");      //front()

    protein1.pushFront(&AcidC);
    protein1.pushFront(&AcidD);
    protein1.pushBack(&AcidE);

    //assert(protein1.back()->getName() == "E");        //back()
    //assert(protein1.front()->getName() == "D");       //front()
    assert(protein1.isEmpty() == false);                  //isEmpty()
    assert(protein1.size() == 4);                         //size()
    //assert(protein1.popFront()->getName() == "D");    //popFront()
    //assert(protein1.front()->getName() == "C");       //front()
    //assert(protein1.popBack()->getName() == "E");     //popBack()
    //assert(protein1.back()->getName() == "A");        //back()
    Protein proteinCopy(protein1);
    //assert(proteinCopy.back()->getName() == "A");     //copy constructor
    //assert(proteinCopy.front()->getName() == "C");
    }
    Protein proteinLeft;                                  //operator +=
    Protein proteinRight;
    Protein proteinTest;
    proteinLeft.pushBack(&AcidA);
    proteinLeft.pushBack(&AcidC);
    proteinLeft.pushBack(&AcidD);
    proteinLeft.pushBack(&AcidE);
    proteinLeft.pushBack(&AcidF);

    proteinRight.pushBack(&AcidE);
    proteinRight.pushBack(&AcidF);
    proteinRight.pushBack(&AcidG);
    proteinTest.pushBack(&AcidA);
    proteinTest.pushBack(&AcidC);
    proteinTest.pushBack(&AcidD);
    proteinTest.pushBack(&AcidE);
    proteinTest.pushBack(&AcidF);
    proteinTest.pushBack(&AcidG);
    proteinLeft += proteinRight;
    Protein multiProtein(proteinLeft);

    while(!multiProtein.isEmpty()) {
         assert(multiProtein.popBack()->getLongName() == proteinTest.popBack()->getLongName());
    }

    Protein testProteinRight(proteinRight);
    proteinRight += proteinRight;

    while(!proteinRight.isEmpty()) {
        assert(testProteinRight.popBack()->getLongName() == proteinRight.popBack()->getLongName());
    }

    //savedProtein.saveSequenceToFile("test.json");
    Protein loadedProtein;                            //loadJson
    loadedProtein.loadSequenceFromFile("test.json");

    while(!proteinRight.isEmpty()) {
    //    assert(savedProtein.popBack()->getLongName() == loadedProtein.popBack()->getLongName());
    }

    loadedProtein.loadSequenceFromFile("test.json");
    try {
        loadedProtein.loadSequenceFromFile("qwerty");
    } catch (QString filename) {
        //qDebug() << "File " + filename + " does not exists";
    }

    qDebug() << 0;

    NonStandartAcid nonAcid("gamma-carboxyglutamic");
    Protein p;
    Protein q;
    p.pushBack(&nonAcid);
    p.pushBack(&AcidA);
    qDebug() << "----";
    qDebug() << p.back()->getLongName() << " back()";
    qDebug() << p.front()->getLongName();
    qDebug() << "----";
    p.saveSequenceToFile("test2.json");
    q.loadSequenceFromFile("test2.json");
    qDebug() << "----";
    NonStandartAcid nonAcid2("3,3,5-triiodothyronine");
    qDebug() << "----";
    q.pushBack(&nonAcid2);

    qDebug() << "----";
    qDebug() << p.back()->getLongName() << "p back()";
    qDebug() << p.front()->getLongName();
    qDebug() << "----";
    qDebug() << q.back()->getLongName() << "q back()";
    qDebug() << q.front()->getLongName();
    qDebug() << "----";
    p += q;
    qDebug() << "----";
    while(!p.isEmpty()) {
        //qDebug() << p.popBack()->getName();
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    //AminoAcid AcidA("A");
    //qDebug() << AcidA.getLongName();

    return a.exec();
}
