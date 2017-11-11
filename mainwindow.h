#pragma once

#include <deque/protein.h>
#include <QMainWindow>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QList<Protein> proteinArray;

private slots:
    void on_LoadProtein_clicked();

    void on_rmProtein_clicked();

    void on_addProtein_clicked();

    void on_SaveProtein_clicked();

    void on_sumSequence_clicked();

    void on_addAcid_clicked();

    void on_addNonAcid_clicked();

    void on_rmAcid_clicked();

    void on_showLastAcid_clicked();

    void on_showFirstAcid_clicked();

private:
    Ui::MainWindow *ui;
};
