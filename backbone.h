#ifndef BACKBONE_H
#define BACKBONE_H
#include <QList>
#include <QStringList>
#include <QHostAddress>
#include <iostream>
#include "socketplant.h"

namespace BB {

extern QList<QHostAddress> sources, destinations;
extern QString destinationsAsStrz, sourcesAsStrz;
extern int sourceInitPort, destInitPort, maxPktsPerCombination;
extern const int LOCAL_ARG_NUM, HORDE_ARG_NUM;
extern bool rdSrcP, rdDstP, rdPkt, fRST;
extern QList<SocketPlant> allOfThem;

extern void parseHostNPort(QString str, QList<QHostAddress> *lst, int *port);
extern void updateArgs(QStringList argz, int shift=0);

}
#endif // BACKBONE_H
