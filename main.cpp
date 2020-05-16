#include <iostream>

#include "Element.h"

int main()
{
    Element* earth = new Earth();
    Element* fire = new Fire();
    std::cout << Element::canInteract(earth, fire) << std::endl;

    Element* water = new Water();
    std::cout << Element::canInteract(earth, water) << std::endl;

    Element* air = new Air();
    std::cout << Element::canInteract(fire, air) << std::endl;

    Element* energy = new Energy();
    std::cout << Element::canInteract(earth, energy) << std::endl;

    Element* spirit = new Spirit();
    std::cout << Element::canInteract(fire, spirit) << std::endl;

    Element* metal = new Metal();
    std::cout << Element::canInteract(water, metal) << std::endl;
}