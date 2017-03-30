#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ID = new IrisDatasets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printInfo(QString line)
{
    ui->info_LW->addItem(line);
    ui->statusBar->showMessage(line);
}

void MainWindow::update_datasets_TW()
{
    qDebug() << "MainWindow::update_datasets_TW";

    int size = ID->getSize();
    ui->datasets_TW->setRowCount(size);
    Iris iris;

    QTableWidgetItem *itm1, *itm2, *itm3, *itm4, *itm5;

    for(int i=0;i<size;i++)
    {
        iris = ID->get(i);
        itm1 = new QTableWidgetItem();
        itm2 = new QTableWidgetItem();
        itm3 = new QTableWidgetItem();
        itm4 = new QTableWidgetItem();
        itm5 = new QTableWidgetItem();

        itm1->setText(QString::number(iris.get_sepal_length()));
        itm2->setText(QString::number(iris.get_sepal_width()));
        itm3->setText(QString::number(iris.get_petal_length()));
        itm4->setText(QString::number(iris.get_petal_width()));
        itm5->setText(QString::number(iris.get_iris_class()));

        ui->datasets_TW->setItem(i,0,itm1);
        ui->datasets_TW->setItem(i,1,itm2);
        ui->datasets_TW->setItem(i,2,itm3);
        ui->datasets_TW->setItem(i,3,itm4);
        ui->datasets_TW->setItem(i,4,itm5);
    }
}

void MainWindow::on_loadDatasets_PB_clicked()
{
    qDebug() << "MainWindow::on_loadDatasets_PB_clicked";
    ID->loadDatasets("iris.csv");

    update_datasets_TW();
    printInfo("[LOAD] Datasets loaded with " + QString::number(ID->getSize()) + " elements");
}

void MainWindow::on_kmeans_PB_clicked()
{
    qDebug() << "MainWindow::on_kmeans_PB_clicked";
    KMeans* k;
    k = new KMeans(3,ID);
    k->init();
    k->compute();
    k->exporter();
}
