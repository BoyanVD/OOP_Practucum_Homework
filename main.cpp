#include <iostream>

#include "Constants.h"
#include "Alchemist.h"

int main()
{
    std::vector<std::string> equations;
    equations.push_back("Air + Air = Spirit");
    equations.push_back("Metal + Stone = Gold");
    equations.push_back("Fire + Earth = Metal");
    equations.push_back("Fire + Water + Earth = Gold");
    equations.push_back("Water + Earth = Stone");
    equations.push_back("Spirit + Air = Energy");
    equations.push_back("Water + Air = Energy");
    equations.push_back("Gold + Spirit + Energy = Philosopher's Stone");
    equations.push_back("Energy + Earth = Stone");

    Alchemist bobcho("Bobchooo", EARTH_DEMO_QUANTITY, FIRE_DEMO_QUANTITY, WATER_DEMO_QUANTITY, AIR_DEMO_QUANTITY, equations);
    bobcho.canWeCreatePS();
    bobcho.printInfo();
}