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

private:
    QList<Iris> *IrisList;
};

#endif // IRISDATASETS_H
