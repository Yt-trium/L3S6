#ifndef IRISDATASETS_H
#define IRISDATASETS_H

#include <QFile>
#include <QDebug>
#include <cmath>

#include "iris.h"

class IrisDatasets
{
public:
    IrisDatasets();
    int loadDatasets(QString filename);
    int getSize();
    Iris get(int index);
    float getTotalEntropy();

    // Sort
    void sortSL();
    void sortSW();
    void sortPL();
    void sortPW();
    void part3();

    QString subListReport();
    float entropieG1();
    float entropieG2();
    float entropieG3();

private:
    QList<Iris> *IrisList;
    QList<Iris> *IrisSubList1;
    QList<Iris> *IrisSubList2;
    QList<Iris> *IrisSubList3;
};

#endif // IRISDATASETS_H
