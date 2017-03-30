#include "kmeans.h"

KMeans::KMeans(unsigned int c, IrisDatasets *id)
{
    k = c;
    ID = id;

    clusters = new QList<QList<Iris>*>;

    for(uint i=0;i<k;i++)
        clusters->append(new QList<Iris>);

    points = new QList<d4>;
}

void KMeans::init()
{
    /* Création de points aléatoire dans les bornes
    sepal length: 4.3  7.9
     sepal width: 2.0  4.4
    petal length: 1.0  6.9
     petal width: 0.1  2.5
    */

    d4 x;
    for(uint i=0;i<k;i++)
    {
        x.a = RandomFloat(4.3,7.9);
        x.b = RandomFloat(2.0,4.4);
        x.c = RandomFloat(1.0,6.9);
        x.d = RandomFloat(0.1,2.5);

        // qDebug() << x.a << x.b << x.c << x.d;

        points->append(x);
    }
}

float KMeans::RandomFloat(float a, float b)
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

float KMeans::distance(Iris i, d4 c)
{   return
            (
    (c.a - i.get_sepal_length())*(c.a - i.get_sepal_length())+
    (c.b - i.get_sepal_width())*(c.b - i.get_sepal_width())+
    (c.c - i.get_petal_length())*(c.c - i.get_petal_length())+
    (c.d - i.get_petal_width())*(c.d - i.get_petal_width())
             );
}

void KMeans::compute()
{
    Iris ir;
    float dist, tmp;
    int clu;
    int continuer = 100;


    while(continuer > 0)
    {
        continuer--;

    for(int i=0;i<clusters->size();i++)
    clusters->at(i)->clear();

    // 2
    for(int i=0;i<ID->getSize();i++)
    {
        ir = ID->get(i);
        clu = 0;
        dist = distance(ir,points->at(0));

        for(uint j=1;j<k;j++)
        {
            tmp = distance(ir,points->at(j));
            if(tmp < dist)
            {
                dist = tmp;
                clu = j;
            }
        }
        clusters->at(clu)->append(ir);
    }

    qDebug() << clusters->at(0)->size();
    qDebug() << clusters->at(1)->size();
    qDebug() << clusters->at(2)->size();

    // 3
    int z = points->size();
    points->clear();

    for(int i=0;i<z;i++)
    {
        points->append(moyenne(i));
    }
    }
}

d4 KMeans::moyenne(int idclu)
{
    d4 m;
    m.a = 0.0;
    m.b = 0.0;
    m.c = 0.0;
    m.d = 0.0;

    for(int i=0;i<clusters->at(idclu)->size();i++)
    {
        Iris xx = clusters->at(idclu)->at(i);
        m.a += xx.get_sepal_length();
        m.b += xx.get_sepal_width();
        m.c += xx.get_petal_length();
        m.d += xx.get_petal_width();
    }

    m.a /= clusters->at(idclu)->size();
    m.b /= clusters->at(idclu)->size();
    m.c /= clusters->at(idclu)->size();
    m.d /= clusters->at(idclu)->size();

    return m;
}

void KMeans::exporter()
{

    QFile file("out.csv");
    if (!file.open(QIODevice::WriteOnly))
        return;
    QTextStream outStream(&file);

    QString tmpData;
    Iris x;

    for(int i=0;i<clusters->size();i++)
    {
        for(int j=0;j<clusters->at(i)->size();j++)
        {
            x = clusters->at(i)->at(j);
            tmpData =
                    QString::number(x.get_sepal_length()) + "," +
                    QString::number(x.get_sepal_width()) + "," +
                    QString::number(x.get_petal_length()) + "," +
                    QString::number(x.get_petal_width()) + "," +
                    QString::number(i) + "\n";
            outStream << tmpData;
        }
    }
}
