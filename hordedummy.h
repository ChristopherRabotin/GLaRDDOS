#ifndef HORDEDUMMY_H
#define HORDEDUMMY_H
#include "hordefactory.h"
#include <QObject>

class HordeDummy : public HordeFactory, public virtual QObject
{
public:
    HordeDummy();
    void connectToPortal(QString portal, QString room, QString extension);
};

#endif // HORDEDUMMY_H
