#ifndef __Week14Labs__SeaGame__
#define __Week14Labs__SeaGame__

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

#endif /* defined(__Week14Labs__SeaGame__) */
