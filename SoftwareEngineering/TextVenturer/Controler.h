#pragma once

#include "TextDisplay.h"

class CommandSystem;
class DefaultAction;
class Adventure;
class Game;       

class Controler
{
private:                          
    CommandSystem* commandSystem;

    DefaultAction* defaultAction;

    Adventure* adventure;

    TextDisplay* textDisplay;
	Game* game;

    TextDisplay::State state;
    int writepos;
    bool newLine;
    std::queue<std::string> textbuffer;

    std::string input;
    UINT inputPos;
    UINT inputScroll;

  std::vector<std::string> inputHistory;
    bool msgSaved;
    UINT historyIndex;

    void updateInput();
    void writeToBuffer(std::string msg);

public:
    Controler(TextDisplay* textDisplay, Game* game);
    virtual ~Controler();

    void pressChar(byte c);
    void pressKey(byte key);

    void update(float deltaTime);

    void write(std::string msg);

    void sendCommand(std::string msg);
    
    bool loadAdventure(std::string filename);
    bool loadAdventureState(std::string filename);
    bool saveAdventureState(std::string filename);
    void startAdventure();

    void unloadAdventure();
};

