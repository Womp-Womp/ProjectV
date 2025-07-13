#ifndef SAVE_LOAD_SYSTEM_H
#define SAVE_LOAD_SYSTEM_H

#include <string>

class SaveLoadSystem {
public:
    SaveLoadSystem();

    void saveGame(const std::string &filepath);
    void loadGame(const std::string &filepath);
};

#endif // SAVE_LOAD_SYSTEM_H
