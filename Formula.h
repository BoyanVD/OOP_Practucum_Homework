#ifndef __FORMULA_H
#define __FORMULA_H

#include <iostream>
#include <vector>
#include <string>

#include "Element.h"

class Formula
{
private:
    std::vector<Element*> interactionElements;
    Element* result;

    static Element* extractResultElement(const std::string& equation);
    static std::vector<Element*> extractInteractionElements(const std::string& equation);
public:
    Formula(const std::string& equation);
    ~Formula();

    static bool validateFormula(const std::string& equation);
    static bool isFormulaUsingOnlyBaseElements(const Formula* formula);
    void print() const;

    Element* getResult() const;
    std::vector<Element*> getInteractionElements() const;
};


#endif