#ifndef HORDEVIAIRC_H
#define HORDEVIAIRC_H
#include <hordefactory.h>

class HordeViaIRC : public HordeFactory
{
public:
    HordeViaIRC();
    void connectToPortal(QString portal, QString room, QString extension);
/*signals:
    virtual void zulu(QStringList);*/
};

#endif // HORDEVIAIRC_H
