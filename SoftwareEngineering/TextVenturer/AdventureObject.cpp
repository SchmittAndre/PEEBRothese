#include "stdafx.h"

#include "Player.h"

#include "AdventureObject.h"


AdventureObject::AdventureObject()
{
    description = "No description!";
}

AdventureObject::~AdventureObject()
{
}

AliasList& AdventureObject::getAliases()
{
    return aliases;
}

std::string AdventureObject::getName(bool definiteArticle, bool startOfSentence) const
{
    return aliases.getName(definiteArticle, startOfSentence);
}

std::string AdventureObject::getName(Player * player, bool startOfSentence) const
{
    return getName(player->knows((AdventureObject*)this), startOfSentence);
}

std::string AdventureObject::getNameOnly(bool startOfSentence) const
{
    return aliases.getNameOnly(startOfSentence);
}

bool AdventureObject::isNamePlural() const
{
    return aliases.isNamePlural();
}

void AdventureObject::setDescription(std::string description)
{
    this->description = description;
}

std::string AdventureObject::getDescription() const
{
    return description;
}
