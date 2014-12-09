#include "SeaGame.h"

void testSeaGame() {
  SeaGame game;
  game.play();
}

SeaGame::SeaGame() {
  std::cout << "Welcome to sea war game.\n";
}

void SeaGame::play() {
  ocean_.addShips();
}
