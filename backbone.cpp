#include <backbone.h>

namespace BB{
    QList<QHostAddress> sources, destinations;
    QString destinationsAsStrz, sourcesAsStrz;
    int sourceInitPort, destInitPort, maxPktsPerCombination;
    const int LOCAL_ARG_NUM = 8;
    const int HORDE_ARG_NUM = 4;
    bool rdSrcP, rdDstP, rdPkt, fRST;
    QList<SocketPlant> allOfThem;

    void parseHostNPort(QString str, QList<QHostAddress> *lst, int *port){
        QStringList srcz = str.split(",");
        for(int is=0; is < srcz.size(); is++){
            if(srcz.at(is).length() == 0) continue;
            if(srcz.at(is).count(":") > 0){
                *port = srcz.at(is).split(":").at(1).toInt();
                (*lst).append(QHostAddress(srcz.at(is).split(":").at(0)));
            }else{
                (*lst).append(QHostAddress(srcz.at(is)));
            }
        }
    }

    void updateArgs(QStringList argz, int shift){
        sourcesAsStrz = argz.at(0+shift);
        parseHostNPort(sourcesAsStrz,&sources,&sourceInitPort);
        destinationsAsStrz = argz.at(1+shift);
        parseHostNPort(destinationsAsStrz,&destinations,&destInitPort);
        maxPktsPerCombination = atoi(argz.at(2+shift).toStdString().c_str());
        rdSrcP = atoi(argz.at(3+shift).toStdString().c_str());
        rdDstP = atoi(argz.at(4+shift).toStdString().c_str());
        rdPkt = atoi(argz.at(5+shift).toStdString().c_str());
        fRST = atoi(argz.at(6+shift).toStdString().c_str());
    }
}
