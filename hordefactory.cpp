#include "hordefactory.h"
#include "hordeviahttp.h"
#include "hordeviairc.h"
#include "hordeviafile.h"
#include "hordedummy.h"

HordeFactory::HordeFactory(){
    std::cout << "OMGWTFBBQ HORDE MODE: ";
}

HordeFactory *HordeFactory::determinePortalColor(QString portal){
    if(portal == ""){
        return new HordeDummy();
    }else if(portal.startsWith("irc://")){
        return new HordeViaIRC();
    }else if (portal.startsWith("http://")) {
        return new HordeViaHTTP();
    }else if (portal.startsWith("file://")){
        return new HordeViaFile();
    }
    std::cout << "Mitchunderstood Horde!" << std::endl;
    return 0;
}

void HordeFactory::forceZulu(QStringList y){
    emit zulu(y);
}

void HordeFactory::zulu(QStringList){}
