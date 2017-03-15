#pragma once

#include "AdventureObject.h"
#include "Inventory.h"
#include "CommandSystem.h"

class Command;
class CustomAdventureAction;
class Item;
class Player;
class Room;

class Location : public AdventureObject
{
//  friend Room;
public:
    struct LocatedCommandAction
    {
        bool anywhere;                  
        CommandAction commandAction;
        LocatedCommandAction(Command* command, CustomAdventureAction* action, bool anywhere);
    };

    class PInventory : public Inventory
    {
    public:
        enum Filter
        {
            ifBlacklist,
            ifWhitelist
        };
    private:
        strings prepAliasesList;    // strings for list/put          
        strings prepAliasesTake;    // strings also useable for take
        Inventory* filter;
        Filter mode;
    public:
        PInventory();
        ~PInventory();

        bool addPrepositionAlias(std::string alias, bool runOnTake = false);
        bool delPrepositionAlias(std::string alias);
        std::string getPrepositionName(bool runOnTake = false, bool startOfSentence = false) const;
        bool hasPrepositionAlias(std::string alias, bool runOnTake = false) const;

        bool addItem(Item* item);
        bool canAddItem(Item* item);
        void addItemForce(Item* item);

        bool isFiltered() const;
        Filter getFilterMode() const;
        void enableFilter(Filter mode);
        void disableFilter();
        void addToFilter(Item* item);
        bool delFromFilter(Item* item);
    };

private:
    std::vector<LocatedCommandAction> commands;
    std::unordered_map<std::string, PInventory*> inventories;

    CommandArray* locatedCommands;

    CustomAdventureAction* onGoto;
    CustomAdventureAction* onLeave;

public:
    Location();
    virtual ~Location();

    void addCommand(Command* command, CustomAdventureAction* action, bool anywhere);         

    PInventory* addInventory(std::string preposition);
    bool delInventory(std::string preposition);
    bool hasInventory(std::string preposition);
    size_t filledInventoryCount();
    PInventory* firstFilledInventory();
    std::vector<PInventory*> getInventories();

    CommandArray* getLocatedCommands();

    CustomAdventureAction* getOnGoto();
    CustomAdventureAction* getOnLeave();

    void setOnGoto(CustomAdventureAction* onGoto);
    void setOnLeave(CustomAdventureAction* onLeave);
    
    PInventory* getInventory(std::string preposition);

    std::string formatPrepositions(bool filledOnly = false);
    std::string formatPrepositions(Item* filterCheckItem);
};

