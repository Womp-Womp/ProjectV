#include "game_loop.h"
#include <iostream>

GameLoop::GameLoop() {
    std::cout << "GameLoop created" << std::endl;
}

GameLoop::~GameLoop() {
    std::cout << "GameLoop destroyed" << std::endl;
}

void GameLoop::run() {
    std::cout << "GameLoop running" << std::endl;
    // Main game loop logic
}
