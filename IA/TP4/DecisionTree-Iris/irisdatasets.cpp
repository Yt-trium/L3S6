#include "irisdatasets.h"

IrisDatasets::IrisDatasets()
{
    IrisList = new QList<Iris>;
    IrisSubList1 = new QList<Iris>;
    IrisSubList2 = new QList<Iris>;
    IrisSubList3 = new QList<Iris>;
}

int IrisDatasets::loadDatasets(QString filename)
{
    qDebug() << "IrisDatasets::loadDatasets" << filename;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
        return 1;

    QTextStream in(&file);
    QString tmpData;
    QStringList data;

    IrisList->clear();
    Iris i;


    while(!in.atEnd())
    {
        in >> tmpData;
        data = tmpData.split(",");

        if(data.size() != 5)
            return 2;

        // qDebug() << tmpData << data.at(0) << data.at(1) << data.at(2) << data.at(3) << data.at(4);

        i = Iris();

        i.set(  data.at(0).toFloat(),
                data.at(1).toFloat(),
                data.at(2).toFloat(),
                data.at(3).toFloat(),
                data.at(4).toInt()  );

        IrisList->append(i);
    }

    return 0;
}

int IrisDatasets::getSize()
{
    return IrisList->size();
}

Iris IrisDatasets::get(int index)
{
    return IrisList->at(index);
}

float IrisDatasets::getTotalEntropy()
{
    float totalEntropy = 0.0;
    float p = 0.0;

    for(int i=0;i<IrisList->size();i++)
    {
        p = 1.0/150.0;
        totalEntropy += (p*(log2(p)));
        // qDebug() << p << totalEntropy;
    }

    return -totalEntropy;
}

void IrisDatasets::sortSL()
{
    /*
    qSort deprecated so let's use std::sort
    qSort(IrisList->begin(), IrisList->end(), variantLessThanSL);
    */

    auto variantLessThanSL = [](Iris v1, Iris v2) -> bool
    {
        return (v1.get_sepal_length() < v2.get_sepal_length());
    };
    std::sort(IrisList->begin(), IrisList->end(), variantLessThanSL);
}

void IrisDatasets::sortSW()
{
    auto variantLessThanSW = [](Iris v1, Iris v2) -> bool
    {
        return (v1.get_sepal_width() < v2.get_sepal_width());
    };
    std::sort(IrisList->begin(), IrisList->end(), variantLessThanSW);
}

void IrisDatasets::sortPL()
{
    auto variantLessThanPL = [](Iris v1, Iris v2) -> bool
    {
        return (v1.get_petal_length() < v2.get_petal_length());
    };
    std::sort(IrisList->begin(), IrisList->end(), variantLessThanPL);
}

void IrisDatasets::sortPW()
{
    auto variantLessThanPW = [](Iris v1, Iris v2) -> bool
    {
        return (v1.get_petal_width() < v2.get_petal_width());
    };
    std::sort(IrisList->begin(), IrisList->end(), variantLessThanPW);
}

void IrisDatasets::part3()
{
    int i;

    IrisSubList1->clear();
    IrisSubList2->clear();
    IrisSubList3->clear();

    for(i=0;i<IrisList->size()/3;i++)
        IrisSubList1->append(IrisList->at(i));

    for(i=(IrisList->size()/3);i<2*(IrisList->size()/3);i++)
        IrisSubList2->append(IrisList->at(i));

    for(i=2*(IrisList->size()/3);i<IrisList->size();i++)
        IrisSubList3->append(IrisList->at(i));

    // qDebug() << IrisList->size() << IrisSubList1->size() << IrisSubList2->size() << IrisSubList3->size();
}

QString IrisDatasets::subListReport()
{
    QString report = "";
    Iris n;
    int i,z;
    int a,b,c;
    a = 0; b = 0; c = 0;
    for(i=0;i<IrisSubList1->size();i++)
    {
        n = IrisSubList1->at(i);
        z = n.get_iris_class();
        switch(z)
        {
        case 1:
            a++;
            break;
        case 2:
            b++;
            break;
        case 3:
            c++;
            break;
        }
    }

    report +="Group 1 : \n" +
            QString::number(a) + " Iris 1\t" +
            QString::number(b) + " Iris 2\t" +
            QString::number(c) + " Iris 3\n";

    a = 0; b = 0; c = 0;
    for(i=0;i<IrisSubList2->size();i++)
    {
        n = IrisSubList2->at(i);
        z = n.get_iris_class();
        switch(z)
        {
        case 1:
            a++;
            break;
        case 2:
            b++;
            break;
        case 3:
            c++;
            break;
        }
    }

    report +="Group 2 : \n" +
            QString::number(a) + " Iris 1\t" +
            QString::number(b) + " Iris 2\t" +
            QString::number(c) + " Iris 3\n";


    a = 0; b = 0; c = 0;
    for(i=0;i<IrisSubList3->size();i++)
    {
        n = IrisSubList3->at(i);
        z = n.get_iris_class();
        switch(z)
        {
        case 1:
            a++;
            break;
        case 2:
            b++;
            break;
        case 3:
            c++;
            break;
        }
    }

    report +="Group 3 : \n" +
             QString::number(a) + " Iris 1\t" +
             QString::number(b) + " Iris 2\t" +
             QString::number(c) + " Iris 3";

    return report;
}

float IrisDatasets::entropieG1()
{
    float e = 0.0;

    Iris n;
    int i,z;
    int a,b,c;
    a = 0; b = 0; c = 0;

    for(i=0;i<IrisSubList1->size();i++)
    {
        n = IrisSubList1->at(i);
        z = n.get_iris_class();
        switch(z)
        {
        case 1:
            a++;
            break;
        case 2:
            b++;
            break;
        case 3:
            c++;
            break;
        }
    }

    float p1 = ((float)a)/50.0;
    float p2 = ((float)b)/50.0;
    float p3 = ((float)c)/50.0;

    for(int i=0;i<IrisSubList1->size();i++)
    {
        n = IrisSubList1->at(i);
        z = n.get_iris_class();

        switch(z)
        {
        case 1:
            e += (p1*(log2(p1)));
            break;
        case 2:
            e += (p2*(log2(p2)));
            break;
        case 3:
            e += (p3*(log2(p3)));
            break;
        }
        qDebug() << e << p1 << p2 << p3;
    }

    return -e;
}

float IrisDatasets::entropieG2()
{
    float e = 0.0;

    Iris n;
    int i,z;
    int a,b,c;
    a = 0; b = 0; c = 0;

    for(i=0;i<IrisSubList2->size();i++)
    {
        n = IrisSubList2->at(i);
        z = n.get_iris_class();
        switch(z)
        {
        case 1:
            a++;
            break;
        case 2:
            b++;
            break;
        case 3:
            c++;
            break;
        }
    }

    float p1 = ((float)a)/50.0;
    float p2 = ((float)b)/50.0;
    float p3 = ((float)c)/50.0;

    for(int i=0;i<IrisSubList2->size();i++)
    {
        n = IrisSubList2->at(i);
        z = n.get_iris_class();

        switch(z)
        {
        case 1:
            e += (p1*(log2(p1)));
            break;
        case 2:
            e += (p2*(log2(p2)));
            break;
        case 3:
            e += (p3*(log2(p3)));
            break;
        }
        qDebug() << e << p1 << p2 << p3;
    }

    return -e;
}

float IrisDatasets::entropieG3()
{
    float e = 0.0;

    Iris n;
    int i,z;
    int a,b,c;
    a = 0; b = 0; c = 0;

    for(i=0;i<IrisSubList3->size();i++)
    {
        n = IrisSubList3->at(i);
        z = n.get_iris_class();
        switch(z)
        {
        case 1:
            a++;
            break;
        case 2:
            b++;
            break;
        case 3:
            c++;
            break;
        }
    }

    float p1 = ((float)a)/50.0;
    float p2 = ((float)b)/50.0;
    float p3 = ((float)c)/50.0;

    for(int i=0;i<IrisSubList3->size();i++)
    {
        n = IrisSubList3->at(i);
        z = n.get_iris_class();

        switch(z)
        {
        case 1:
            e += (p1*(log2(p1)));
            break;
        case 2:
            e += (p2*(log2(p2)));
            break;
        case 3:
            e += (p3*(log2(p3)));
            break;
        }
        qDebug() << e << p1 << p2 << p3;
    }

    return -e;
}
