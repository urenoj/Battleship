#ifndef __Battleship__Ocean__
#define __Battleship__Ocean__

#include <iostream>
#include <list>
#include <vector>
#include "Ocean.h"
#include "Coord.h"
#include "Ship.h"

struct Ocean {
    Ocean();
    void addShips();
    friend std::ostream &operator<<(std::ostream &os, const Ocean &ocean);
  
    bool overlaps (const std::string &shipName, char row1, int col1, char row2, int col2) const;
    bool validCoord(const Coord &coord) const;
    bool validShip(const std::string &shipName, char row1, int col1, char row2, int col2) const;
    void placeShip(const std::string &namePrompt, const std::string &shipName);
  
    static const char EMPTY = '*', SPACE = ' ';
    static const int SIDE = 10;
    char ocean_[SIDE][SIDE];
    std::vector<Ship> ships_;
    
    void hitShips();
};

#endif /* defined(__Battleship__Ocean__) */
