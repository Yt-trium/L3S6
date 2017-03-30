#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "kmeans.h"

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
    void on_kmeans_PB_clicked();
};

#endif // MAINWINDOW_H
