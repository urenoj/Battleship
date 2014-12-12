#include "SeaGame.h"

void testSeaGame() {
    SeaGame game1;
    SeaGame game2;
    
    game1.play();
    game2.play();
}

SeaGame::SeaGame() {
    std::cout << "Welcome to the Sea War Game.\n";
}

void SeaGame::play() {
    ocean_.addShips();
}
