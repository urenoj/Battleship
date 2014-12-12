#ifndef __Week14Labs__Ship__
#define __Week14Labs__Ship__

#include <iostream>
#include "Coord.h"


struct Ship {
    std::string name_;
    Coord bow_;
    Coord stern_;
  
    Ship(std::string name, char rowBow, int colBow, char rowStern, int colStern)
//	  : Ship(name, Coord(rowBow, colBow), Coord(rowBow, rowStern)) {}
    : name_(name), bow_(rowBow, colBow), stern_(rowStern, colStern) {
        Coord min = bow_.min(stern_);
        if (min != bow_) {
            stern_ = bow_;
            bow_ = min;
        }
    }
  
    Ship(std::string name, Coord bow, Coord stern)
    : name_(name), bow_(bow), stern_(stern) {
        Coord min = bow_.min(stern_);
        if (min != bow_) {
            stern_ = bow_;
            bow_ = min;
        }
    }
  
    bool intersects(const Coord &coord) const {
        int r = coord.row_, rb = bow_.row_, rs = stern_.row_;
        int c = coord.col_, cb = bow_.col_, cs = stern_.col_;
    
        return (c == cb && r >= rb && r <= rs) || (r == rb && c >= cb && c <= cs);
    }
    
    bool intersects(const Ship &other) const {
        int rb = bow_.row_, rs = stern_.row_;
        int cb = bow_.col_, cs = stern_.col_;
        int orb = other.bow_.row_, ors = other.stern_.row_;
        int ocb = other.bow_.col_, ocs = other.stern_.col_;
    
        return (isVertical()   && other.isVertical()   && cb == ocb && rb >= orb && rb <= ors) ||
            (isHorizontal() && other.isHorizontal() && rb == orb && cb >= ocb && cb <= ocs) ||
            (isVertical()   && other.isHorizontal() && rb <= orb && rs >= orb && cb >= ocb && cb <= ocs) ||
            (isHorizontal() && other.isVertical()   && cb <= ocb && cs >= ocs && rb >= orb && rb <= ors);
    }
 
    bool isVertical() const   { return bow_.sameCol(stern_); }
    bool isHorizontal() const { return !isVertical();        }
};

#endif /* defined(__Week14Labs__Ship__) */
