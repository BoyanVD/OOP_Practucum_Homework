#ifndef __ALCHEMIST_CPP
#define __ALCHEMIST_CPP

#include "Alchemist.h"

Alchemist::Alchemist(std::string name, int earthQuantity, int fireQuantity, int waterQuantity, int airQuantity, const std::vector<std::string>& equations)
{
    this->name = name;
    this->elements.push_back({new Earth(), earthQuantity});
    this->elements.push_back({new Fire(), fireQuantity});
    this->elements.push_back({new Water(), waterQuantity});
    this->elements.push_back({new Air(), airQuantity});

    this->book = new Book(equations);
    this->success = false;
}

Alchemist::~Alchemist()
{
    for (std::pair<Element*, int> elem : elements)
    {
        delete elem.first;
    }
    delete this->book;
}

bool Alchemist::useElement(const Element* element, std::vector<std::pair<Element*, int>>& resources)
{
    for (std::pair<Element*, int> elem : resources)
    {
        if (elem.first->getLabel() == element->getLabel())
        {
            if (elem.second == 0)
                return false;
            
            --elem.second;
            return true;
        }
    }

    return false;
}

bool Alchemist::canCreatePhilosopherStone(const Element* root, std::vector<std::pair<Element*, int>> resources)
{
    if (root->isBase())
    {
        return this->useElement(root, resources);
    }

    std::vector<Formula*> possibleFormulas = this->book->getFormulasForResult(root);
    // bool canCreate = true;

    // for (std::pair<Element*, int> elem : resources)
    // {
    //     if (this->canCreatePhilosopherStone())
    // }
    for (Formula* formula : possibleFormulas)
    {
        std::vector<Element*> childElements = formula->getInteractionElements();
        bool canWeCreateUsingFormula = true;

        for (Element* element : childElements)
        {
            if (!this->canCreatePhilosopherStone(element, resources))
            {
                canWeCreateUsingFormula = false;
                break;
            }

        }

        if (canWeCreateUsingFormula)
        {
            this->path.push_back(formula);
            return true;
        }
    }

    return false;
}

bool Alchemist::canWeCreate()
{
    this->success = this->canCreatePhilosopherStone(new PhilosopherStone(), this->elements);
    return this->success;
}

void Alchemist::printInfo() const
{
    if (this->success)
    {
        std::cout << "We can construct Philosoper's stone with resources and formulas given !" << std::endl;
        std::cout << "Successful formulas sequence : " << std::endl;
    } else
    {
        std::cout << "We cannot construct Philosoper's stone with resources and formulas given !" << std::endl;
        std::cout << "Sequence until failure : " << std::endl;
    }

    for (Formula* formula : this->path)
    {
        formula->print();
    }

    std::cout << std::endl;

    // for (std::pair<Element*, int> elem : this->elements)
    // {
    //     std::cout << elem.first->getLabel() << " : " << elem.second << std::endl;
    // }
}
#endif