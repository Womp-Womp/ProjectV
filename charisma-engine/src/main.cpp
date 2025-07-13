#include <SFML/Graphics.hpp>
#include "ai/ai_player.h"
#include "save_load_system.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Charisma Engine");
    AIPlayer aiPlayer;
    SaveLoadSystem saveLoadSystem;

    saveLoadSystem.saveGame("savegame.dat");
    saveLoadSystem.loadGame("savegame.dat");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        aiPlayer.takeTurn();

        window.clear();
        // Add rendering logic here
        window.display();
    }

    return 0;
}
