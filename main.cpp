#include <iostream>

#include "Element.h"
#include "Formula.h"
#include "Book.h"
#include "Alchemist.h"

int main()
{
    // Element* earth = new Earth();
    // Element* fire = new Fire();
    // std::cout << Element::canInteract(earth, fire) << std::endl;

    // Element* water = new Water();
    // std::cout << Element::canInteract(earth, water) << std::endl;

    // Element* air = new Air();
    // std::cout << Element::canInteract(fire, air) << std::endl;

    // Element* energy = new Energy();
    // std::cout << Element::canInteract(earth, energy) << std::endl;

    // Element* spirit = new Spirit();
    // std::cout << Element::canInteract(fire, spirit) << std::endl;

    // Element* metal = new Metal();
    // std::cout << Element::canInteract(water, metal) << std::endl;

    //--------------------------------------------------
    // Formula formula("Gold + Spirit + Energy = Philosopher's Stone");
    // formula.print();

    // std::cout << Formula::validateFormula("Water + Earth = Stone") << std::endl;
    // std::cout << Formula::validateFormula("Fire + Water + Earth = Gold") << std::endl;
    
    // std::cout << Formula::validateFormula("Air + Air = Spirit") << std::endl;
    // std::cout << Formula::validateFormula("Energy + Earth = Stone") << std::endl;

    // std::cout << Formula::validateFormula("Fire + Earth = Metal") << std::endl;
    // std::cout << Formula::validateFormula("Metal + Stone = Gold") << std::endl;
    //---------------------------------------------------

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

    // Book book(equations);
    // book.printFormulas();
    // std::cout << std::endl;

    // book.buildSuccessfulSequences();
    // book.printSuccessful();

    Alchemist bobcho("Bobchooo", 3, 4, 1, 10, equations);
    std::cout << bobcho.canWeCreate() << std::endl;
    bobcho.printInfo();
}