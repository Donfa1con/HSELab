#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <aminoacid.h>
#include <nonstandartacid.h>
#include <deque/protein.h>
#include <QDebug>
#include <QMessageBox>


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
    qDebug() << "LoadProtein_clicked";
    try {
        QString filePath = QFileDialog::getOpenFileName(this, "Load protein",QDir::currentPath(),"Text Files(*.json)");
        Protein loadProtein;
        qDebug() << "step_1";
        loadProtein.loadSequenceFromFile(filePath);
        qDebug() << "step_2";
        this->proteinArray.push_back(loadProtein);
        qDebug() << "step_3";
    } catch (...) {}
    if(this->proteinArray.size() == 2) {
        ui->sumSequence->setEnabled(true);
    }
    ui->rmProtein->setEnabled(true);
    if (this->proteinArray.size() == 1) {
        ui->SaveProtein->setEnabled(true);
        ui->showFirstAcid->setEnabled(true);
        ui->showLastAcid->setEnabled(true);
        ui->rmAcid->setEnabled(true);
    } else {
        ui->SaveProtein->setEnabled(false);
    }
}

void MainWindow::on_rmProtein_clicked()
{
    qDebug() << "rmProtein_clicked";
    this->proteinArray.pop_back();
    if(this->proteinArray.size() < 2) {
        ui->sumSequence->setEnabled(false);
    }
    if(proteinArray.isEmpty()) {
        ui->rmProtein->setEnabled(false);
        ui->showFirstAcid->setEnabled(false);
        ui->showLastAcid->setEnabled(false);
        ui->rmAcid->setEnabled(false);
    }
    if (this->proteinArray.size() == 1) {
        ui->SaveProtein->setEnabled(true);
    } else {
        ui->SaveProtein->setEnabled(false);
    }
    ui->addProtein->setEnabled(true);
    ui->LoadProtein->setEnabled(true);
}

void MainWindow::on_addProtein_clicked()
{
    qDebug() << "addProtein_clicked";
    Protein protein;
    qDebug() << "step_1";
    this->proteinArray.push_back(protein);
    qDebug() << "step_2";
    if(this->proteinArray.size() == 2) {
        ui->sumSequence->setEnabled(true);
    }
    ui->rmProtein->setEnabled(true);

    if (this->proteinArray.size() == 1) {
        ui->SaveProtein->setEnabled(true);
    } else {
        ui->SaveProtein->setEnabled(false);
    }
    ui->rmAcid->setEnabled(false);
    ui->showFirstAcid->setEnabled(false);
    ui->showLastAcid->setEnabled(false);
    ui->addProtein->setEnabled(false);
    ui->LoadProtein->setEnabled(false);
}


void MainWindow::on_SaveProtein_clicked()
{
    qDebug() << "SaveProtein_clicked";
    QString filePath = QFileDialog::getSaveFileName(this, "Save protein",QDir::currentPath(),"Text Files(*.json)");
    qDebug() << "step_1";
    proteinArray[0].saveSequenceToFile(filePath);
    qDebug() << "step_2";
}


void MainWindow::on_sumSequence_clicked()
{
    Protein newProtein(proteinArray.first());
    qDebug() << "sumSequence_clicked";
    for(auto it = proteinArray.begin() + 1; it != proteinArray.end(); it++) {
        qDebug() << "step_1";
        newProtein += (*it);
        qDebug() << "step_2";
        qDebug() << "step_3";
    }
    proteinArray.clear();
    proteinArray.push_back(newProtein);
    ui->SaveProtein->setEnabled(true);
    ui->sumSequence->setEnabled(false);
}


//void MainWindow::on_addAcid_clicked()
//{
//    qDebug() << "addAcid_clicked";
//    if(!ui->acidName->text().isEmpty()) {
//        qDebug() << "step_1";
//        try {
//            qDebug() << "step_2";
//            AminoAcid acid(ui->acidName->text());
//            proteinArray[proteinArray.size()-1].pushBack(&acid);
//            ui->rmAcid->setEnabled(true);
//            ui->showFirstAcid->setEnabled(true);
//            ui->showLastAcid->setEnabled(true);
//        } catch (...){
//            qDebug() << "step_3";
//            QMessageBox::warning(0, "Warning", "Acid " + ui->acidName->text() + " does not exist!");
//        }
//        ui->addProtein->setEnabled(true);
//        ui->LoadProtein->setEnabled(true);
//    }
//}


//void MainWindow::on_addNonAcid_clicked()
//{
//    qDebug() << "addNonAcid_clicked";
//    if(!ui->acidName->text().isEmpty()) {
//        qDebug() << "step_1";
//        try {
//            qDebug() << "step_2";
//            NonStandartAcid acid(ui->acidName->text());
//            proteinArray[proteinArray.size()-1].pushBack(&acid);
//            ui->rmAcid->setEnabled(true);
//            ui->showFirstAcid->setEnabled(true);
//            ui->showLastAcid->setEnabled(true);
//        } catch (...){
//            qDebug() << "step_3";
//            QMessageBox::warning(0, "Warning", "Acid " + ui->acidName->text() + " does not exist!");
//        }
//        ui->addProtein->setEnabled(true);
//        ui->LoadProtein->setEnabled(true);
//    }
//}

void MainWindow::on_rmAcid_clicked()
{
    qDebug() << "rmAcid_clicked";
    if(!proteinArray[proteinArray.size()-1].isEmpty()) {
        proteinArray[proteinArray.size()-1].popBack();
    }
    if(proteinArray.last().isEmpty()){
        ui->rmAcid->setEnabled(false);
        ui->showFirstAcid->setEnabled(false);
        ui->showLastAcid->setEnabled(false);
    }
}

void MainWindow::on_showLastAcid_clicked()
{
    qDebug() << "showLastAcid_clicked";
    QMessageBox::information(0, "Information", "Last acid is " +  proteinArray[proteinArray.size()-1].back()->getLongName());
}

void MainWindow::on_showFirstAcid_clicked()
{
    qDebug() << "showFirstAcid_clicked";
    QMessageBox::information(0, "Information", "First acid is " +  proteinArray[proteinArray.size()-1].front()->getLongName());
}
