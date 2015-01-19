#ifndef HORDEVIAHTTP_H
#define HORDEVIAHTTP_H
#include <hordefactory.h>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QObject>
/**
  HordeViaHTTP uses "portal" as a host, "room" as the ressource and "extension" as the port number.
  */
class HordeViaHTTP : public HordeFactory, public virtual QObject
{
    Q_OBJECT
public:
    HordeViaHTTP();
    void connectToPortal(QString portal, QString room, QString extension);
private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
public slots:
    void processReply(QNetworkReply* rpl);
    void processError(QNetworkReply::NetworkError);
signals:
    virtual void zulu(QStringList);
};

#endif // HORDEVIAHTTP_H
