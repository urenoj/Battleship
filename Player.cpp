#include <thread>
#include <chrono>

#include "Player.h"
#include "Ocean.h"

void Player::takeTurn(Player &enemy) {
  std::cout << name_ << " ships...";
  for (int i = 0; i < 27 - name_.length(); ++i) { std::cout << " "; }
  std::cout << enemy.name_ << "'s ships...\n";
  
  ocean_.displayHeaders(enemy.ocean());

  for (int i = 0; i < Ocean::SIDE; ++i) {
    ocean_.displayRow(i, true);             // yes show my ships
    std::cout << "     ";
    enemy.ocean().displayRow(i, false);     // don't show enemy's ships
    std::cout << "\n";
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  
  bool valid = false;
  char row = '\0';
  int col = 0;
  while (!valid) {
    std::cout << "Enter move: ";  std::cin >> row >> col;
    valid = enemy.ocean().validCoord(Coord(row, col));
  }
  Coord shot(row, col);
  enemy.ocean().tryShot(shot);
}

Ocean& Player::ocean() { return ocean_; }
