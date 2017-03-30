#ifndef KMEANS_H
#define KMEANS_H

#include "irisdatasets.h"

typedef struct
{
    float a,b,c,d;
}d4;

class KMeans
{
public:
    KMeans(unsigned int c, IrisDatasets *id);

    void init();
    void compute();
    void exporter();

private:
    unsigned int k;
    QList<QList<Iris>*>* clusters;
    IrisDatasets *ID;
    QList<d4> *points;

    float RandomFloat(float a, float b);
    float distance(Iris i, d4 c);
    d4 moyenne(int idclu);
};

#endif // KMEANS_H
