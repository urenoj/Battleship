#ifndef __Battleship__SeaGame__
#define __Battleship__SeaGame__

#include <iostream>
#include "SeaGame.h"
#include "Ocean.h"

class SeaGame {
public:
    SeaGame();
  
    void play();
  
private:
    Ocean  ocean_;
};

#endif /* defined(__Battleship__SeaGame__) */
