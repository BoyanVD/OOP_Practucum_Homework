#ifndef __BOOK_CPP
#define __BOOK_CPP

#include "Book.h"

bool Book::doesFormulasSubsetContainFormulaWithSameResult(const std::vector<Formula*>& formulas, const Formula* formula)
{
    for (Formula* f : formulas)
    {
        if (f->getResult()->getLabel() == formula->getResult()->getLabel())
            return true;
    }
    return false;
}

// std::vector<std::vector<Formula*>> Book::getAllUniqueResultFormulasSubsets(const std::vector<Formula*> formulas)
// {
//     std::vector<std::vector<Formula*>> sets;
//     unsigned numberOfSets = 0;

//     for (Formula* formula : formulas)
//     {
//         bool haveFoundSetForFormula = false;
//         for (std::vector<Formula*> set : sets)
//         {
//             if (!Book::doesFormulasSubsetContainFormulaWithSameResult(set, formula))
//             {
//                 set.push_back(formula);
//                 haveFoundSetForFormula = true;
//             }
//         }
//         if (!haveFoundSetForFormula)
//         {
//             std::vector<Formula*> tmp;
//             if (numberOfSets != 0)
//                 tmp.insert(tmp.end(), sets[numberOfSets - 1].begin(), sets[numberOfSets - 1].end());
//             tmp.push_back(formula);
//             sets.push_back(tmp);
//             ++numberOfSets;
//         }
//     }

//     return sets;
// }

std::vector<Formula*> Book::getSuccessfulSequenceForFormulasSubset(const std::vector<Formula*>& subset, Formula* root)
{
    if (Formula::isFormulaUsingOnlyBaseElements(root))
        return {root};

    std::vector<Formula*> result;
    std::vector<Element*> interactionElements = root->getInteractionElements();
    for (Element* elem : interactionElements)
    {
        if (elem->isBase())
            continue;

        for (Formula* formula : subset)
        {
            if (formula->getResult()->getLabel() != elem->getLabel())
                continue;

            std::vector<Formula*> childSuccessfulSequence = Book::getSuccessfulSequenceForFormulasSubset(subset, formula);
            result.insert(result.end(), childSuccessfulSequence.begin(), childSuccessfulSequence.end());
        }
    }

    result.push_back(root);

    return result;
}


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

void Book::buildSuccessfulSequences()
{
    // std::vector<std::vector<Formula*>> subsets = Book::getAllUniqueResultFormulasSubsets(this->formulas);

    // this->successfulFormulasSequences = subsets;
    // this->printSuccessful();
    // // std::cout << subsets.size() << std::endl;

    // for (std::vector<Formula*> set : subsets)
    // {
    //     Formula* root;
    //     for (Formula* formula : set)
    //     {
    //         if (formula->getResult()->getLabel() == "Philosopher's Stone")
    //         {
    //             root = formula;
    //             break;
    //         }
    //     }

    //     std::vector<Formula*> successful = Book::getSuccessfulSequenceForFormulasSubset(set, root);
    //     this->successfulFormulasSequences.push_back(successful);
    // }

    //-----------------------------------------------------------------------------------
    Formula* root;
    for (Formula* formula : this->formulas)
    {
        if (formula->getResult()->getLabel() == "Philosopher's Stone")
        {
            // formula->print();
            // std::cout << std::endl;

            root = formula;
            break;
        }
    }

    std::vector<Formula*> successfulSeq = Book::getSuccessfulSequenceForFormulasSubset(this->formulas, root);
    this->successful = successfulSeq;
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

void Book::printSuccessful() const
{
    // for (std::vector<Formula*> set : this->successfulFormulasSequences)
    // {
    //     for (Formula* formula : set)
    //     {
    //         formula->print();
    //     }
    // }

    for (Formula* f : this->successful)
        f->print();
}

void Book::printFormulas() const
{
    for (Formula* formula : this->formulas)
    {
        formula->print();
    }
}

#endif