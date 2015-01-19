#ifndef SOCKETPLANT_H
#define SOCKETPLANT_H

#include <QObject>
#include <QRunnable>
#include <QtConcurrentRun>
#include <QTimer>
#include <QHostAddress>
#include <QDebug>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
/**
  ALL YOUR MIND ARE BELONG TO GLaRDDOS.
  WELCOME TO THE SocketPlant CLASS.
  IN THIS CLASS, GLaRDDOS SHOWS HOW TO BUILD FACTORIES WHICH
  GENERATE SPIES WHOSE ONLY GOAL IS TO PRETEND TO BE SENT FROM
  ANOTHER LEGION. ALL FACTORIES ARE IDENTICAL.
  */

#define PCKT_LEN 50
class SocketPlant : public QRunnable
{

public:
    explicit SocketPlant(QHostAddress *src, QHostAddress *dest, int srcPort, int destPort, QString payload, signed int pktsToSend, bool randomizeSrcPort, bool randomizeDestPort, bool randomizePkts, bool forceTCPRst);
    void run();
    void qcr();
    bool isTheCakeBaking();

signals:

public slots:
    void theCakeIsALie();
private:
    QHostAddress src, dest;
    unsigned short spID;
    unsigned int srcPort, destPort, maxElementsThruPortal, currentElementThruPortal;
    bool theCakeIsBaking, randomCakeIngredients, forcePortalRst, randomSourcePortal, randomDestPortal;
    /** the datagram buffer will contain ip header, tcp header,
        and payload. we'll point an ip header structure at its
        beginning, and a tcp header structure after that to
        write the header values into it */
    char datagram[PCKT_LEN];
    /** sin is source, din is destination. */
    struct sockaddr_in sin, din;
    int sd; // skt descriptor
    // TH3 H34DRZ
    struct iphdr *iph;
    struct tcphdr *tcph;
    // SHAKE DAT ASS, WATCH URS3LF, SHAKE DAT ASS, SH0W ME W4HT UR WR0KIN W1TH
    unsigned short checksum();
    void randomizePkt();
    void alterPortal();
};

#endif // SOCKETPLANT_H
