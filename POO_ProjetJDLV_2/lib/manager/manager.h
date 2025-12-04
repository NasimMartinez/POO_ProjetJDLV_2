#pragma once
#include "../common/libs.h"
#include "../game/game.h"
#include "../fileManager/fileManager.h"
#include "consoleMode.h"
#include "graphicMode.h"

class Manager {
public:
    void run();

private:
    void runConsole(Game& game, const std::string& inputName);
    void runGraphical(Game& game);
  
      
};
