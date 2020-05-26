#ifndef __ELEMENT_H
#define __ELEMENT_H

#include <iostream>
#include <vector>
#include <string>

class Element
{
protected:
    static const std::vector<std::string> EMPTY_INTERACTION_ELEMENTS_LABELS;
    
    static const std::vector<std::string> EARTH_INTERACTION_ELEMENTS_LABELS;
    static const std::vector<std::string> FIRE_INTERACTION_ELEMENTS_LABELS;
    static const std::vector<std::string> WATER_INTERACTION_ELEMENTS_LABELS;
    static const std::vector<std::string> AIR_INTERACTION_ELEMENTS_LABELS;

    std::string label;
    std::vector<std::string> createdByLabels;

    static bool contains(const std::vector<std::string>& vector, const std::string& str);
private:
    static const std::vector<std::string>& getInteractionElementsByLabel(const std::string& _label);
    static bool canBaseInteractWith(const Element* base, const Element* other);
    static bool canCreatedInteractWith(const Element* created, const Element* other);
    static std::vector<std::string> getInteractionElementsForElement(const Element* element);

public:
    Element(const std::string& _label, const std::vector<std::string>& _createdByLabels) : label(_label), createdByLabels(_createdByLabels) {}

    virtual bool canInteractWith(const Element* other) const; // could remove virtual, but i will keep it for extensibility
    virtual bool isBase() const = 0;

    std::string getLabel() const
    {
        return label;
    }

    virtual std::vector<std::string> getCreatedByLabels() const
    {
        return createdByLabels;
    }

    static bool canInteract(const Element* left, const Element* right)
    {
        return (left->canInteractWith(right) && right->canInteractWith(left));
    }
};

class Earth : public Element
{
public:
    Earth() : Element("Earth", {}) {}

    virtual bool isBase() const override
    {
        return true;
    }
};

class Fire : public Element
{
public:
    Fire() : Element("Fire", {}) {}

    virtual bool isBase() const override
    {
        return true;
    }
};

class Water : public Element
{
public:
    Water() : Element("Water", {}) {}

    virtual bool isBase() const override
    {
        return true;
    }
};

class Air : public Element
{
public:
    Air() : Element("Air", {}) {}

    virtual bool isBase() const override
    {
        return true;
    }
};

class Metal : public Element
{
public:
    Metal() : Element("Metal", {"Fire", "Earth"}) {}

    virtual bool isBase() const override
    {
        return false;
    }
};

class Stone : public Element
{
public:
    Stone() : Element("Stone", {"Fire", "Water"}) {}

    virtual bool isBase() const override
    {
        return false;
    }
};

class Energy : public Element
{
public:
    Energy() : Element("Energy", {"Water", "Air"}) {}

    virtual bool isBase() const override
    {
        return false;
    }
};

class Spirit : public Element
{
public:
    Spirit() : Element("Spirit", {"Air"}) {}

    virtual bool isBase() const override
    {
        return false;
    }
};

class Gold : public Element
{
public:
    Gold() : Element("Gold", {"Metal"}) {}

    virtual bool isBase() const override
    {
        return false;
    }
};

class PhilosopherStone : public Element
{
public:
    PhilosopherStone() : Element("Philosopher's Stone", {"Earth", "Fire", "Water", "Air"}) {}

    virtual bool isBase() const override
    {
        return false;
    }
};

class ElementFactory
{
public:
    static Element* generate(std::string label);
};

#endif