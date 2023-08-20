#include "system.h"

System::System()
{

}

const QString System::getElementName(){
    return "System";
}

void System::setSystemData(std::shared_ptr<SystemData> data)
{
    _SystemData = data;
}

const SystemData *System::getSystemData()
{
    return _SystemData.get();
}

SystemData *System::editSystemData()
{
    return _SystemData.get();
}
