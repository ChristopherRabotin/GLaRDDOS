#include "hordeviafile.h"

HordeViaFile::HordeViaFile()
{
    std::cout << "File" << std::endl;
}

void HordeViaFile::connectToPortal(QString portal, QString room, QString extension){
// TODO
    // http://stackoverflow.com/questions/5090969/read-a-text-file-to-qstringlist
    // http://doc.qt.nokia.com/latest/qtextstream.html
    QFile fl(portal.remove("file://"));
    if(!fl.exists()){
        std::cerr << "Y U NO EXISTS " << portal.toStdString() << std::endl;
        return;
    }else if(!fl.open(QFile::ReadOnly)){
        std::cerr << "Y U NO LET ME READ " << portal.toStdString() << std::endl;
        return;
    }
    QTextStream strm(&fl);
    QString argz = strm.readLine();
    if (argz.isNull())
        std::cerr << "Y U SO EMPTY " << portal.toStdString() << std::endl;
    else
        emit zulu(argz.split(" "));
}
