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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *count_PB;
    QPushButton *totalEntropy_PB;
    QGroupBox *sort_GP;
    QVBoxLayout *verticalLayout;
    QPushButton *SL_PB;
    QPushButton *SW_PB;
    QPushButton *PL_PB;
    QPushButton *PW_PB;
    QPushButton *loadDatasets_PB;
    QListWidget *info_LW;
    QPushButton *part_PB;
    QTableWidget *datasets_TW;
    QPushButton *partEntropy_PB;
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
        count_PB = new QPushButton(centralWidget);
        count_PB->setObjectName(QStringLiteral("count_PB"));

        gridLayout->addWidget(count_PB, 4, 0, 1, 1);

        totalEntropy_PB = new QPushButton(centralWidget);
        totalEntropy_PB->setObjectName(QStringLiteral("totalEntropy_PB"));

        gridLayout->addWidget(totalEntropy_PB, 2, 0, 1, 1);

        sort_GP = new QGroupBox(centralWidget);
        sort_GP->setObjectName(QStringLiteral("sort_GP"));
        verticalLayout = new QVBoxLayout(sort_GP);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        SL_PB = new QPushButton(sort_GP);
        SL_PB->setObjectName(QStringLiteral("SL_PB"));

        verticalLayout->addWidget(SL_PB);

        SW_PB = new QPushButton(sort_GP);
        SW_PB->setObjectName(QStringLiteral("SW_PB"));

        verticalLayout->addWidget(SW_PB);

        PL_PB = new QPushButton(sort_GP);
        PL_PB->setObjectName(QStringLiteral("PL_PB"));

        verticalLayout->addWidget(PL_PB);

        PW_PB = new QPushButton(sort_GP);
        PW_PB->setObjectName(QStringLiteral("PW_PB"));

        verticalLayout->addWidget(PW_PB);


        gridLayout->addWidget(sort_GP, 1, 1, 6, 1);

        loadDatasets_PB = new QPushButton(centralWidget);
        loadDatasets_PB->setObjectName(QStringLiteral("loadDatasets_PB"));

        gridLayout->addWidget(loadDatasets_PB, 1, 0, 1, 1);

        info_LW = new QListWidget(centralWidget);
        info_LW->setObjectName(QStringLiteral("info_LW"));

        gridLayout->addWidget(info_LW, 1, 2, 7, 1);

        part_PB = new QPushButton(centralWidget);
        part_PB->setObjectName(QStringLiteral("part_PB"));

        gridLayout->addWidget(part_PB, 3, 0, 1, 1);

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

        gridLayout->addWidget(datasets_TW, 8, 0, 1, 3);

        partEntropy_PB = new QPushButton(centralWidget);
        partEntropy_PB->setObjectName(QStringLiteral("partEntropy_PB"));

        gridLayout->addWidget(partEntropy_PB, 5, 0, 1, 1);

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
        count_PB->setText(QApplication::translate("MainWindow", "Count", Q_NULLPTR));
        totalEntropy_PB->setText(QApplication::translate("MainWindow", "Total entropy", Q_NULLPTR));
        sort_GP->setTitle(QApplication::translate("MainWindow", "Sort", Q_NULLPTR));
        SL_PB->setText(QApplication::translate("MainWindow", "SL", Q_NULLPTR));
        SW_PB->setText(QApplication::translate("MainWindow", "SW", Q_NULLPTR));
        PL_PB->setText(QApplication::translate("MainWindow", "PL", Q_NULLPTR));
        PW_PB->setText(QApplication::translate("MainWindow", "PW", Q_NULLPTR));
        loadDatasets_PB->setText(QApplication::translate("MainWindow", "Load datasets", Q_NULLPTR));
        part_PB->setText(QApplication::translate("MainWindow", "Part", Q_NULLPTR));
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
        partEntropy_PB->setText(QApplication::translate("MainWindow", "Part entropy", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
