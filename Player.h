#ifndef __Battleship__Player__
#define __Battleship__Player__

#include <iostream>
#include "Ocean.h"

struct Player {
public:
  Player(const std::string &name)
  : name_(name), ocean_(name) {}

  std::string name() const { return name_; }
  
  bool won(Player &enemy) { return enemy.ocean().allShipsSunk(); }
  void takeTurn(Player &enemy);
  Ocean &ocean();
  
private:
  std::string name_;  
  Ocean ocean_;
};

#endif /* defined(__Battleship__Player__) */
