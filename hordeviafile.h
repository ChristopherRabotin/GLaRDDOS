#ifndef HORDEVIAFILE_H
#define HORDEVIAFILE_H
#include "hordefactory.h"
#include <QTextStream>
#include <QFile>

class HordeViaFile : public HordeFactory, public virtual QObject
{
    Q_OBJECT
public:
    HordeViaFile();
    void connectToPortal(QString portal, QString room, QString extension);
signals:
    virtual void zulu(QStringList);
};

#endif // HORDEVIAFILE_H
