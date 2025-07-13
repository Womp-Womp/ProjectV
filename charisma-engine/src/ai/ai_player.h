#ifndef AI_PLAYER_H
#define AI_PLAYER_H

class AIPlayer {
public:
    AIPlayer();

    void takeTurn();

private:
    void manageEconomy();
    void produceUnits();
    void attackEnemies();
};

#endif // AI_PLAYER_H
