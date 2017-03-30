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

void MainWindow::on_totalEntropy_PB_clicked()
{
    qDebug() << "MainWindow::on_totalEntropy_PB_clicked";

    printInfo("[COMPUTE] Total entropy = " + QString::number(ID->getTotalEntropy(),'g',12));
}

void MainWindow::on_SL_PB_clicked()
{
    qDebug() << "MainWindow::on_SL_PB_clicked()";
    ID->sortSL();

    update_datasets_TW();
    printInfo("[SORT] Sort by SL");
}

void MainWindow::on_SW_PB_clicked()
{
    qDebug() << "MainWindow::on_SW_PB_clicked()";
    ID->sortSW();

    update_datasets_TW();
    printInfo("[SORT] Sort by SW");
}

void MainWindow::on_PL_PB_clicked()
{
    qDebug() << "MainWindow::on_PL_PB_clicked()";
    ID->sortPL();

    update_datasets_TW();
    printInfo("[SORT] Sort by PL");
}

void MainWindow::on_PW_PB_clicked()
{
    qDebug() << "MainWindow::on_PW_PB_clicked()";
    ID->sortPW();

    update_datasets_TW();
    printInfo("[SORT] Sort by PW");
}

void MainWindow::on_part_PB_clicked()
{
    qDebug() << "MainWindow::on_part_PB_clicked()";

    ID->part3();
    printInfo("[PART] Datasets partitioned in 3 subpart of " + QString::number(ID->getSize()/3) + " elements");
}

void MainWindow::on_count_PB_clicked()
{
    qDebug() << "MainWindow::on_count_PB_clicked()";

    printInfo("[COMPUTE] " + ID->subListReport());
}

void MainWindow::on_partEntropy_PB_clicked()
{
    qDebug() << "MainWindow::on_partEntropy_PB_clicked()";

    printInfo("[COMPUTE] " + QString::number(ID->entropieG1()));
    printInfo("[COMPUTE] " + QString::number(ID->entropieG2()));
    printInfo("[COMPUTE] " + QString::number(ID->entropieG3()));
}
