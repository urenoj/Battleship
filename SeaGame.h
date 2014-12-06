#ifndef Battleship_SeaGame_h
#define Battleship_SeaGame_h

struct SeaGame {
    seaGame() { std::cout << "Welcome to the Sea War game. \n"; }

    void play() { ocean_.addShips(); }
    
private:
    Ocean ocean_;
};

#endif
