//THIS IS JUST AN EXAMPLE OF HOW WE COULD START USING THIS THING

#include "GameEngine.h"
#include <iostream>
#include <string>

int main() {
    GameEngine game;
    game.displayIntro();
    std::cin.get(); // Pause for intro
    std::string buildingType;
    std::string district;
    std::string utilityType;
    std::string transportType;

    int choice;
    while (true) {
        game.displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter building type (Flat, House, etc.): ";
                
                std::cin >> buildingType;
                game.createBuilding(buildingType, district = "A");
                break;

            case 2:
                std::cout << "Enter utility type (Power Plant, Water Supply, etc.): ";
                
                std::cin >> utilityType;
                game.createUtility(utilityType);
                break;

            case 3:
                game.changeTaxPolicy();
                break;

            case 4:
                std::cout << "Enter transport type (Bus, Train, etc.): ";
                
                std::cin >> transportType;
                game.addTransport(transportType);
                break;

            case 5:
                game.startSimulation();
                break;

            case 6:
                game.displayCitySummary();
                break;

            case 7:
                std::cout << "Exiting game.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
