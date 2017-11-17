#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <aminoacid.h>
#include <nonstandartacid.h>
#include <deque/protein.h>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoadProtein_clicked()
{
    try {
        QString filePath = QFileDialog::getOpenFileName(this, "Load protein",QDir::currentPath(),"Text Files(*.json)");
        Protein loadProtein;
        loadProtein.loadSequenceFromFile(filePath);
        if(proteinArray.back().isEmpty()) {
            proteinArray.pop_back();
        }
        this->proteinArray.push_back(loadProtein);
    } catch (...) {}

    if(this->proteinArray.size() == 2) {
        ui->sumSequence->setEnabled(true);
    }
    ui->rmProtein->setEnabled(true);
    if (this->proteinArray.size() == 1) {
        ui->SaveProtein->setEnabled(true);
    } else {
        ui->SaveProtein->setEnabled(false);
    }
    ui->buttonDeleteEnd->setEnabled(true);
    ui->buttonDeleteFront->setEnabled(true);

    emit this->showProteinSequence();
}

void MainWindow::on_rmProtein_clicked()
{
    this->proteinArray.pop_back();
    if(this->proteinArray.size() < 2) {
        ui->sumSequence->setEnabled(false);
    }
    if(proteinArray.empty()) {
        ui->rmProtein->setEnabled(false);
    }
    if (this->proteinArray.size() == 1) {
        ui->SaveProtein->setEnabled(true);
    } else {
        ui->SaveProtein->setEnabled(false);
    }
    if(proteinArray.empty()) {
        ui->buttonDeleteEnd->setEnabled(false);
        ui->buttonDeleteFront->setEnabled(false);
    }
    ui->addProtein->setEnabled(true);

    emit this->showProteinSequence();
}

void MainWindow::on_addProtein_clicked()
{
    Protein protein;
    this->proteinArray.push_back(protein);
    if(this->proteinArray.size() == 2) {
        ui->sumSequence->setEnabled(true);
    }
    ui->rmProtein->setEnabled(true);
    ui->SaveProtein->setEnabled(false);
    ui->addProtein->setEnabled(false);
    ui->buttonDeleteEnd->setEnabled(false);
    ui->buttonDeleteFront->setEnabled(false);

    emit this->showProteinSequence();
}

void MainWindow::on_SaveProtein_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save protein",QDir::currentPath(),"Text Files(*.json)");
    proteinArray.back().saveSequenceToFile(filePath);
}

void MainWindow::on_sumSequence_clicked()
{
//    Protein newProtein(proteinArray.first());
//    qDebug() << "sumSequence_clicked";
//    for(auto it = proteinArray.begin() + 1; it != proteinArray.end(); it++) {
//        qDebug() << "step_1";
//        newProtein += (*it);
//        qDebug() << "step_2";
//        qDebug() << "step_3";
//    }
//    proteinArray.clear();
//    proteinArray.push_back(newProtein);
    for(int i = proteinArray.size() - 2; i >= 0; --i) {
        proteinArray.at(i) += proteinArray.back();
        proteinArray.pop_back();
    }
    ui->SaveProtein->setEnabled(true);
    ui->addProtein->setEnabled(true);
    ui->sumSequence->setEnabled(false);

    emit this->showProteinSequence();
}

void MainWindow::on_chooseNonStandardAcid_doubleClicked(const QModelIndex &index)
{
    if (proteinArray.empty()) {
        Protein init;
        proteinArray.push_back(init);
    }
    NonStandartAcid acid(index.data().toString());
    if(ui->radioAddToTheEnd->isChecked()) {
        proteinArray.back().pushBack(&acid);
    } else {
        proteinArray.back().pushFront(&acid);
    }

    ui->buttonDeleteEnd->setEnabled(true);
    ui->buttonDeleteFront->setEnabled(true);
    ui->addProtein->setEnabled(true);
    ui->rmProtein->setEnabled(true);
    if(proteinArray.size() == 1) {
        ui->SaveProtein->setEnabled(true);
    }

    emit this->showProteinSequence();



}

void MainWindow::on_chooseAminoAcid_doubleClicked(const QModelIndex &index)
{
    if (proteinArray.empty()) {
        Protein init;
        proteinArray.push_back(init);
    }
    AminoAcid acid(QString((index.data().toString()[0])));
    if(ui->radioAddToTheEnd->isChecked()) {
        proteinArray.back().pushBack(&acid);
    } else {
        proteinArray.back().pushFront(&acid);
    }
    ui->buttonDeleteEnd->setEnabled(true);
    ui->buttonDeleteFront->setEnabled(true);
    ui->addProtein->setEnabled(true);
    ui->rmProtein->setEnabled(true);
    if(proteinArray.size() == 1) {
        ui->SaveProtein->setEnabled(true);
    }

    emit this->showProteinSequence();
}

void MainWindow::on_buttonDeleteEnd_clicked()
{
    proteinArray.back().popBack();
    if(proteinArray.back().isEmpty()) {
        ui->buttonDeleteEnd->setEnabled(false);
        ui->buttonDeleteFront->setEnabled(false);
    }
    if(proteinArray.back().isEmpty()) {
        ui->addProtein->setEnabled(false);
        ui->SaveProtein->setEnabled(false);
    }

    emit this->showProteinSequence();
}

void MainWindow::on_buttonDeleteFront_clicked()
{
    proteinArray.back().popFront();
    if(proteinArray.back().isEmpty()) {
        ui->buttonDeleteEnd->setEnabled(false);
        ui->buttonDeleteFront->setEnabled(false);
    }
    if(proteinArray.back().isEmpty()) {
        ui->addProtein->setEnabled(false);
        ui->SaveProtein->setEnabled(false);
    }

    emit this->showProteinSequence();
}

void MainWindow::showProteinSequence()
{
    QString browserText;
    for(int i = 0; i < proteinArray.size(); ++i) {
        browserText += "Protein #" + QString::number(i+1) +
                       " (size - " + QString::number(proteinArray[i].size()) + "):\n";
        if(!proteinArray[i].isEmpty()) {
            browserText += proteinArray[i].getFormatedAcidNames();
        }
    }
    ui->textBrowser->setText(browserText);
}
