#ifndef __ELEMENT_CPP
#define __ELEMENT_CPP

#include "Element.h"

const std::vector<std::string> Element::EMPTY_INTERACTION_ELEMENTS_LABELS = {};

const std::vector<std::string> Element::EARTH_INTERACTION_ELEMENTS_LABELS = {"Fire", "Air", "Water"};
const std::vector<std::string> Element::FIRE_INTERACTION_ELEMENTS_LABELS = {"Earth", "Fire", "Water"};
const std::vector<std::string> Element::WATER_INTERACTION_ELEMENTS_LABELS = {"Air", "Fire"};
const std::vector<std::string> Element::AIR_INTERACTION_ELEMENTS_LABELS = {"Air", "Water", "Fire", "Earth"};

Element* ElementFactory::generate(std::string label)
{
    if (label == "Air")
        return new Air();
    else if (label == "Water")
        return new Water();
    else if (label == "Earth")
        return new Earth();
    else if (label == "Fire")
        return new Fire();
    else if (label == "Metal")
        return new Metal();
    else if (label == "Stone")
        return new Stone();
    else if (label == "Energy")
        return new Energy();
    else if (label == "Spirit")
        return new Spirit();
    else if (label == "Gold")
        return new Gold();
    else if (label == "Philosopher's Stone")
        return new PhilosopherStone();

    return nullptr;
}

std::vector<std::string> Element::getInteractionElementsForElement(const Element* element)
{
    if (element->isBase())
        return getInteractionElementsByLabel(element->getLabel());
    
    std::vector<std::string> elements;
    std::vector<std::string> createdByElements = element->getCreatedByLabels();

    for (std::string label : createdByElements)
    {
        Element* element = ElementFactory::generate(label);
        std::vector<std::string> parentInteractionElements = Element::getInteractionElementsForElement(element);
        elements.insert(elements.end(), parentInteractionElements.begin(), parentInteractionElements.end());
    }

    return elements;
}

const std::vector<std::string>& Element::getInteractionElementsByLabel(const std::string& _label)
{
    if (_label == "Air")
        return AIR_INTERACTION_ELEMENTS_LABELS;
    else if (_label == "Water")
        return WATER_INTERACTION_ELEMENTS_LABELS;
    else if (_label == "Earth")
        return EARTH_INTERACTION_ELEMENTS_LABELS;
    else if (_label == "Fire")
        return FIRE_INTERACTION_ELEMENTS_LABELS;

    return EMPTY_INTERACTION_ELEMENTS_LABELS;
}

bool Element::contains(const std::vector<std::string>& vector, const std::string& str)
{
    for (std::string string : vector)
    {
        if (string == str)
            return true;
    }

    return false;
}

bool Element::canBaseInteractWith(const Element* base, const Element* other)
{
    if (other->isBase())
    {
        return contains(getInteractionElementsByLabel(base->getLabel()), other->getLabel());
    }

    std::vector<std::string> labels = other->getCreatedByLabels();
    for (std::string label : labels)
    {
        Element* element = ElementFactory::generate(label);
        if (!(Element::canBaseInteractWith(base, element)))
            return false;
    }

    return true;
}

bool Element::canCreatedInteractWith(const Element* created, const Element* other)
{
    if (other->isBase())
    {
        std::vector<std::string> interactionElements = Element::getInteractionElementsForElement(created);
        return contains(interactionElements, other->getLabel());
    }

    std::vector<std::string> labels = other->getCreatedByLabels();
    for (std::string label : labels)
    {
        Element* element = ElementFactory::generate(label);
        if (!(Element::canCreatedInteractWith(created, element)))
            return false;
    }

    return true;
}

bool Element::canInteractWith(const Element* other) const
{
    if (this->isBase())
        return canBaseInteractWith(this, other);
    else
        return canCreatedInteractWith(this, other);
}

#endif