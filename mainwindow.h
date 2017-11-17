#pragma once

#include <deque/protein.h>
#include <QMainWindow>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showProteinSequence();
private slots:
    void on_LoadProtein_clicked();
    void on_rmProtein_clicked();
    void on_addProtein_clicked();
    void on_SaveProtein_clicked();
    void on_sumSequence_clicked();
    void on_chooseNonStandardAcid_doubleClicked(const QModelIndex &index);
    void on_chooseAminoAcid_doubleClicked(const QModelIndex &index);
    void on_buttonDeleteEnd_clicked();
    void on_buttonDeleteFront_clicked();
private:
    Ui::MainWindow *ui;
    std::vector<Protein> proteinArray;
};
