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

    static std::vector<Formula*> getSuccessfulSequenceForFormulasSubset(const std::vector<Formula*>& subset, Formula* root); // builds the formulas tree for subset, containing unique results formulas
    // static std::vector<std::vector<Formula*>> getAllUniqueResultFormulasSubsets(const std::vector<Formula*> formulas);
    static bool doesFormulasSubsetContainFormulaWithSameResult(const std::vector<Formula*>& formulas, const Formula* formula);
public:
    Book(const std::vector<std::string>& equations);

    void buildSuccessfulSequences();
    void printSuccessful() const;
    void printFormulas() const;
    std::vector<Formula*> getFormulasForResult(const Element* element);

    ~Book();
};

#endif