#ifndef __BOOK_H
#define __BOOK_H

#include <iostream>
#include <vector>
#include <string>
#include "Formula.h"

class Book
{
private:
    std::vector<Formula*> formulas;
    std::vector<std::vector<Formula*>> successfulFormulasSequences; // points to formulas vector, so no need to delete
    std::vector<Formula*> successful;

public:
    Book(const std::vector<std::string>& equations);

    void printFormulas() const;
    std::vector<Formula*> getFormulasForResult(const Element* element);

    ~Book();
};

#endif