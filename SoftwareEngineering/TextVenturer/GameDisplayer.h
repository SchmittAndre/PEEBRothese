#pragma once

class TextDisplay;
class Controler;

class GameDisplayer
{
private:
    Controler* controler;

protected:
    Controler* getControler();
    TextDisplay* getTextDisplay();

public:
    GameDisplayer(Controler* controler);
    ~GameDisplayer();

    virtual void pressChar(byte c) { };
    virtual void pressKey(byte key) { };

    virtual void update(float deltaTime) { };

    virtual void notifySwitch() { };
};