#ifndef Battleship_Ocean_h
#define Battleship_Ocean_h

#include <iostream>
#include <list>
#include <vector>
#include "Coord.h"
#include "Ocean.h"

struct Ocean {
    Ocean();
    
    void addShips();
    
    bool overlaps(const std::string &shipName, char row1, int col1, char row2, int col2) const;
    bool validCoord(const Coord &coord) const;
    bool validShip(const std::string &shipName, char row1, int col1, char row2, int col2) const;
    
    void placeShip(const std::string &namePrompt, const std::string &shipName);
    
    friend std::ostream &operator << (std::ostream &os, const Ocean &ocean);
    
private:
    static const char EMPTY = '*', SPACE = ' ';
    static const int SIDE = 10;
    char ocean_[SIDE][SIDE];
    std::vector<Ship> ships_;
};

#endif
