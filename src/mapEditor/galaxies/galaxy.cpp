#include "galaxy.h"

Galaxy::Galaxy()
{

}

const QString Galaxy::getElementName(){
    return "Galaxy";
}

const GalaxyData* Galaxy::getGalaxyData(){
    return &_galaxyData;
}

void moveTo(QVector3D coordinates){

}

GalaxyData* Galaxy::unsafeGetGalaxyData(){
    return &_galaxyData;
}
