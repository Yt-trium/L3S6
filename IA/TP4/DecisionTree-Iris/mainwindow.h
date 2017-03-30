#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTableWidgetItem>

#include "iris.h"
#include "irisdatasets.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    IrisDatasets *ID;

    void printInfo(QString line);
    void update_datasets_TW();

private slots:
    void on_loadDatasets_PB_clicked();
    void on_totalEntropy_PB_clicked();
    void on_SL_PB_clicked();
    void on_SW_PB_clicked();
    void on_PL_PB_clicked();
    void on_PW_PB_clicked();
    void on_part_PB_clicked();
    void on_count_PB_clicked();
    void on_partEntropy_PB_clicked();
};

#endif // MAINWINDOW_H
