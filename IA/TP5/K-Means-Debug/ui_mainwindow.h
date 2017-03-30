/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *loadDatasets_PB;
    QTableWidget *datasets_TW;
    QListWidget *info_LW;
    QPushButton *kmeans_PB;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loadDatasets_PB = new QPushButton(centralWidget);
        loadDatasets_PB->setObjectName(QStringLiteral("loadDatasets_PB"));

        gridLayout->addWidget(loadDatasets_PB, 1, 0, 1, 1);

        datasets_TW = new QTableWidget(centralWidget);
        if (datasets_TW->columnCount() < 5)
            datasets_TW->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        datasets_TW->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        datasets_TW->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        datasets_TW->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        datasets_TW->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        datasets_TW->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        datasets_TW->setObjectName(QStringLiteral("datasets_TW"));

        gridLayout->addWidget(datasets_TW, 4, 0, 1, 2);

        info_LW = new QListWidget(centralWidget);
        info_LW->setObjectName(QStringLiteral("info_LW"));

        gridLayout->addWidget(info_LW, 1, 1, 3, 1);

        kmeans_PB = new QPushButton(centralWidget);
        kmeans_PB->setObjectName(QStringLiteral("kmeans_PB"));

        gridLayout->addWidget(kmeans_PB, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Decision Tree - Iris", Q_NULLPTR));
        loadDatasets_PB->setText(QApplication::translate("MainWindow", "Load datasets", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = datasets_TW->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "sepal length", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = datasets_TW->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "sepal width", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = datasets_TW->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "petal length", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = datasets_TW->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "petal width", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = datasets_TW->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "iris class", Q_NULLPTR));
        kmeans_PB->setText(QApplication::translate("MainWindow", "K-Means", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
