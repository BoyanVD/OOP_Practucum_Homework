#ifndef __ALCHEMIST_H
#define __ALCHEMIST_H

#include <iostream>
#include <vector>
#include <string>

#include "Element.h"
#include "Book.h"
#include "Formula.h"

class Alchemist
{
private:
    std::string name; // :)
    std::vector<std::pair<Element*, int>> elements;
    Book* book;
    std::vector<Formula*> path;
    bool success;

    bool useElement(const Element* element, std::vector<std::pair<Element*, int>>& resources); //returns false if not enough quantity
    bool canCreatePhilosopherStone(const Element* root, std::vector<std::pair<Element*, int>> resources);
public:
    Alchemist(std::string name, int earthQuantity, int fireQuantity, int waterQuantity, int airQuantity, const std::vector<std::string>& equations);
    ~Alchemist();

    bool canWeCreate();
    void printInfo() const;
};


#endif