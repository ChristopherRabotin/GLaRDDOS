#include "hordeviahttp.h"

HordeViaHTTP::HordeViaHTTP(){
    std::cout << "HTTP" << std::endl;
}
void HordeViaHTTP::connectToPortal(QString portal, QString room, QString extension){
    manager = new QNetworkAccessManager(this);
    reply = manager->get(QNetworkRequest(QUrl(portal+":"+extension+"/"+room)));
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(processReply(QNetworkReply*)));
    qDebug() << "going to {" << portal+":"+extension+"/"+room << "}";
    connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(processError(QNetworkReply::NetworkError)));
}

void HordeViaHTTP::processError(QNetworkReply::NetworkError grrr){
    qDebug() << "SCUMBAG STEVE'S ERROR " << grrr;
}

void HordeViaHTTP::processReply(QNetworkReply* reply){
    qDebug() << "GOOD GUY GREG REPLIED THIS: ";
    QStringList rpl = ((QString)reply->readAll()).split(" ");
    qDebug() << rpl;
    emit zulu(rpl);
}
