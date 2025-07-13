#include "save_load_system.h"
#include <iostream>
#include <fstream>

SaveLoadSystem::SaveLoadSystem() {
}

void SaveLoadSystem::saveGame(const std::string &filepath) {
    std::ofstream saveFile(filepath);
    if (saveFile.is_open()) {
        saveFile << "Game saved!" << std::endl;
        saveFile.close();
        std::cout << "Game saved to " << filepath << std::endl;
    } else {
        std::cerr << "Error: Unable to open save file " << filepath << std::endl;
    }
}

void SaveLoadSystem::loadGame(const std::string &filepath) {
    std::ifstream loadFile(filepath);
    if (loadFile.is_open()) {
        std::string line;
        while (getline(loadFile, line)) {
            std::cout << line << std::endl;
        }
        loadFile.close();
        std::cout << "Game loaded from " << filepath << std::endl;
    } else {
        std::cerr << "Error: Unable to open load file " << filepath << std::endl;
    }
}
