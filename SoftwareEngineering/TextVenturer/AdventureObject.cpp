#include "stdafx.h"

#include "Player.h"
#include "CustomAdventureAction.h"

#include "AdventureObject.h"

void AdventureObject::saveAdventureAction(FileStream & stream, CustomAdventureAction * action)
{
    stream.write(action != NULL);
    if (action)
        action->save(stream);
}

AdventureObject::AdventureObject()
{
    description = "No description!";
    onInspect = NULL;
}

AdventureObject::~AdventureObject()
{
    delete onInspect;
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
    return getName(player->knows(const_cast<AdventureObject*>(this)), startOfSentence);
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

CustomAdventureAction * AdventureObject::getOnInspect()
{
    return onInspect;
}

void AdventureObject::setOnInspect(CustomAdventureAction * onInspect)
{
    this->onInspect = onInspect;
}

void AdventureObject::setFlag(std::string flag)
{
    flags.insert(flag);
}

void AdventureObject::clearFlag(std::string flag)
{
    flags.erase(flag);
}

bool AdventureObject::testFlag(std::string flag)
{
    return flags.find(flag) != flags.end();
}

void AdventureObject::save(FileStream & stream, idlist<AdventureObject*> & objectIDs, idlist<CommandArray*> & commandArrayIDs)
{
    stream.write(static_cast<UINT>(getType()));
    aliases.save(stream);
    stream.write(description);
    saveAdventureAction(stream, onInspect);
    stream.write(flags);
}
