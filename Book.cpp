#ifndef __BOOK_CPP
#define __BOOK_CPP

#include "Book.h"


Book::Book(const std::vector<std::string>& equations)
{
    for (std::string equation : equations)
    {
        if (!Formula::validateFormula(equation))
        {
            std::cout << "Equation : '" << equation << "' is not valid !" << std::endl;
            continue;
        }

        this->formulas.push_back(new Formula(equation));
    }
}

Book::~Book()
{
    for (Formula* formula : this->formulas)
    {
        delete formula;
    }
}

std::vector<Formula*> Book::getFormulasForResult(const Element* element)
{
    std::vector<Formula*> result;
    for (Formula* formula : this->formulas)
    {
        if (formula->getResult()->getLabel() == element->getLabel())
        {
            result.push_back(formula);
        }
    }
    return result;
}

void Book::printFormulas() const
{
    for (Formula* formula : this->formulas)
    {
        formula->print();
    }
}

#endif