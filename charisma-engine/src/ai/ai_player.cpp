#include "ai_player.h"
#include <iostream>

AIPlayer::AIPlayer() {
}

void AIPlayer::takeTurn() {
    std::cout << "AI is taking its turn." << std::endl;
    manageEconomy();
    produceUnits();
    attackEnemies();
}

void AIPlayer::manageEconomy() {
    std::cout << "AI is managing its economy." << std::endl;
}

void AIPlayer::produceUnits() {
    std::cout << "AI is producing new units." << std::endl;
}

void AIPlayer::attackEnemies() {
    std::cout << "AI is attacking its enemies." << std::endl;
}
