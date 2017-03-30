#include "irisdatasets.h"

IrisDatasets::IrisDatasets()
{
    IrisList = new QList<Iris>;
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
