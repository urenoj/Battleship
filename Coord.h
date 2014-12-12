#ifndef __Week14Labs__Coord__
#define __Week14Labs__Coord__

#include <iostream>

struct Coord {
public:
    int row_;
    int col_;
    char val_;
  
    Coord(char row, int col) : col_(col), val_('\0') {   // convert A3 to 1,3
      row = toupper(row);
      row_ = row - 'A' + 1;
    }
  
    bool sameRow(const Coord &other) const { return row_ == other.row_; }
    bool sameCol(const Coord &other) const { return col_ == other.col_; }
  
    const Coord &min(const Coord &other) const {
    int r1 = row_, c1 = col_, r2 = other.row_, c2 = other.col_;
    return (r1*r1 + c1*c1 <= r2*r2 + c2*c2 ? *this : other);
  }
  
    friend bool operator==(const Coord &lhs, const Coord &rhs) {
        return lhs.row_ == rhs.row_ && lhs.col_ == rhs.col_;
    }
  
    friend bool operator!=(const Coord &lhs, const Coord &rhs) {
        return !(lhs == rhs);
    }
    friend std::ostream &operator << (std::ostream &os, const Coord &coord) {
        char row = coord.row_ - 1 + 'A';
        char col = coord.col_ + '0';
        return os << row << col << ' ' << coord.val_;
    }
};

#endif /* defined(__Week14Labs__Coord__) */
