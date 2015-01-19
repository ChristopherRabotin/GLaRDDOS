#ifndef HORDEFACTORY_H
#define HORDEFACTORY_H
#include <QStringList>

#include "backbone.h"

class HordeFactory: public virtual QObject
{
public:
    HordeFactory();
    virtual void connectToPortal(QString portal, QString room, QString extension) = 0;
    static HordeFactory* determinePortalColor(QString portal);
    void forceZulu(QStringList);
signals:
    void zulu(QStringList);
    // ATTENTION SIGNALS & SLOTS NON CONNECTÉS DANS HTTP
};

#endif // HORDEFACTORY_H
