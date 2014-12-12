#include "Ocean.h"
#include <string>

Ocean::Ocean() {
    for (int i = 0; i < SIDE; ++i) {
        for (int j = 0; j < SIDE; ++j) {
            ocean_[i][j] = EMPTY;
        }
    }
}

bool Ocean::overlaps(const std::string &shipName, char row1, int col1, char row2, int col2) const {
    Ship ship(shipName, Coord(row1, col1), Coord(row2, col2));
    for (Ship aship : ships_) {
        if (ship.intersects(aship)) { std::cout << "...overlaps another ship\n"; return true; }
    }
    return false;
}

bool Ocean::validCoord(const Coord &coord) const {
    bool valid = coord.row_ >= 0 && coord.row_ <= SIDE && coord.col_ >= 0 && coord.col_ <= SIDE;
    if (!valid) { std::cout << "...one or more invalid coordinates\n"; }
    return valid;
}
bool Ocean::validShip(const std::string &shipName, char row1, int col1, char row2, int col2) const {
    if (!validCoord(Coord(row1, col1)) || !validCoord(Coord(row2, col2))) { return false; }
    int length = (row1 == row2 ? col2 - col1 + 1 : row2 - row1 + 1);
    bool valid = length == shipName.length();
    if (!valid) { std::cout << "...ship length doesn't match ship name\n"; }
    return valid;
}

void Ocean::placeShip(const std::string &namePrompt, const std::string &shipName) {
    char   row1 = '\0', row2 = '\0';
    int    col1 = 0, col2 = 0;
    bool intersects = true;
  
    while (intersects) {
      std::cout << "Place your " << shipName << ": ";
      std::cin >> row1 >> col1 >> row2 >> col2;
      row1 = toupper(row1);
      row2 = toupper(row2);
      if (validShip(shipName, row1, col1, row2, col2)) {
          intersects = overlaps(shipName, row1, col1, row2, col2);
      }
    }
    
    ships_.push_back(Ship(shipName, Coord(row1, col1), Coord(row2, col2)));
    int r1 = row1 - 'A', r2 = row2 - 'A';
    int c1 = col1 - 1;
    
    if (r1 == r2) {
        for (int j = 0; j <= col2 - col1; ++j) {
            ocean_[r1][c1 + j] = shipName[j];
        }
    }
    else {
        for (int i = 0; i <= r2 - r1; ++i) {
            ocean_[r1 + i][c1] = shipName[i];
        }
    }
    std::cout << *this << "\n\n";
}

void Ocean::addShips() {
    std::cout << "List the starting and ending coordinates of each ship ";
    std::cout << "as RowCol RowCol: (e.g. A3 A5)\n";
    
    std::cout << "---------- Player Board ----------\n";
  
    placeShip("Place your aircraft carrier: ",   "AIRCR");
    placeShip("Now place your battleship: ",     "BATL");
    placeShip("Now place your cruiser: ",        "CRU");
    placeShip("Now place your submarine: ",      "SUB");
    placeShip("Finally, place your destroyer: ", "DE");
  
    std::cout << "All ships placed...\n";
}

std::ostream &operator<<(std::ostream &os, const Ocean &ocean) {
    os << "    1  2  3  4  5  6  7  8  9 10\n";
    os << "--+-----------------------------\n";
    for (int i = 0; i < Ocean::SIDE; ++i) {
        os << (char)('A' + i) << " |";
        
        for (int j = 0; j < Ocean::SIDE; ++j) {
            os << Ocean::SPACE << ocean.ocean_[i][j] << Ocean::SPACE;
        }
        
        os << "\n";
    }
    return os;
}
