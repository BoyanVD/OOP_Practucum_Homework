#ifndef __FORMULA_CPP
#define __FORMULA_CPP

#include "Formula.h"
#include "Constants.h"

Element* Formula::extractResultElement(const std::string& equation)
{
    size_t start = equation.find(EQUATION_RESULT_ELEMENT_DELIMETER) + EQUATION_RESULT_ELEMENT_DELIMETER.length();
    size_t end = std::string::npos;

    return ElementFactory::generate(equation.substr(start, end - 1));
}

std::vector<Element*> Formula::extractInteractionElements(const std::string& equation)
{
    size_t current = equation.find(EQUATION_INTERACTION_ELEMENTS_DELIMETER);
    size_t previous = 0;
    size_t end = equation.find(EQUATION_RESULT_ELEMENT_DELIMETER);
    std::vector<Element*> elements;

    // Extracting all, except the last one
    while (current != end && current != std::string::npos) 
    {
        std::string currentStr = equation.substr(previous, current - previous);

        elements.push_back(ElementFactory::generate(currentStr));
        previous = current + EQUATION_INTERACTION_ELEMENTS_DELIMETER.length();
        current = equation.find(EQUATION_INTERACTION_ELEMENTS_DELIMETER, previous);
    }

    current = equation.find(EQUATION_RESULT_ELEMENT_DELIMETER);
    elements.push_back(ElementFactory::generate(equation.substr(previous, current - previous)));

    return elements;
}

Formula::Formula(const std::string& equation)
{
    this->result = Formula::extractResultElement(equation);
    this->interactionElements = Formula::extractInteractionElements(equation);
}

Formula::~Formula()
{
    for (Element* element : this->interactionElements)
    {
        delete element;
    }
    delete this->result;
}

/*
* It isn't specified how to validate formulas with more than two interaction elements, that is why i validate
* if every element interacts with all the other elements. Also i assume that the equation input format is valid string.
*/
bool Formula::validateFormula(const std::string& equation)
{
    std::vector<Element*> interactionElements = Formula::extractInteractionElements(equation);
    for (size_t elementIndex = 0; elementIndex < interactionElements.size(); ++elementIndex)
    {
        for (size_t othersIndex = 0; othersIndex < interactionElements.size(); ++othersIndex)
        {
            if (othersIndex == elementIndex)
                continue;
            if (!Element::canInteract(interactionElements[elementIndex], interactionElements[othersIndex]))
                return false;
        }
    }
    return true;
}

bool Formula::isFormulaUsingOnlyBaseElements(const Formula* formula)
{
    for (Element* element : formula->getInteractionElements())
    {
        if (!element->isBase())
            return false;
    }
    return true;
}

void Formula::print() const
{
    size_t size = this->interactionElements.size();
    for (size_t index = 0; index < size; ++index)
    {
        std::cout << this->interactionElements[index]->getLabel();
        if (index != size - 1)
            std::cout << EQUATION_INTERACTION_ELEMENTS_DELIMETER;
    }
    std::cout << EQUATION_RESULT_ELEMENT_DELIMETER;
    std::cout << result->getLabel() << std::endl;
}

Element* Formula::getResult() const
{
    return this->result;
}

std::vector<Element*> Formula::getInteractionElements() const
{
    return this->interactionElements;
}

#endif