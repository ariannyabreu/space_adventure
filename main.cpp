/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 1 - Space Adventure
 *
 * Program Description: This program is a console-based Space Adventure Game written in C++.
 * The player takes on the role of a spaceship captain, exploring various planets, managing resources like fuel,
 * and encountering random events in different star systems. The game uses concepts like arrays, vectors, pointers,
 * file I/O, and random events to create an interactive experience where players navigate space and manage resources.
 *
 * October 29, 2024
 * */

#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <format>
#include <fstream>
#include <string>
#include <cstdlib>

void printMenu();
std::string explorePlanet(const std::array<std::string, 5>& planets, int &fuel, int &resources);
void refuelShip(int *fuel);
void navigateSystem(std::vector<std::string>& events, int &fuel, int &resources);
void saveGame(const std::string& userName, const std::string& shipName, const std::string& currentPlanet, int fuel, int resources);
void loadGame(std::string& userName, std::string& shipName, std::string& currentPlanet, int& fuel, int& resources);

// random device and engine.
static std::random_device rd;
static std::default_random_engine engine{rd()};

int main() {
    std::string userName;
    std::string shipName;
    int fuel{100};
    int resources{50};
    std::string currentPlanet;
    bool isPlaying = true; // flag variable to control the loop.

    // Planets names.
    std::array<std::string, 5> planets = {"Mars", "Jupiter", "Venus", "Neptune", "Saturn"};

    // Random events.
    std::vector<std::string> events = {
            "You encountered an alien who is waving at you from his ship's small window.",
            "You encountered an alien who is offering you a resource boost!",
            "You encountered an alien who is offering you fuel! Fuel accepted!",
            "Alien Pirates Attacking!!!! You lose resources and fuel.",
            "Oh no! Space debris!",
            "The system seems quiet... nothing unusual happens."};

    std::cout << "Player name: ";
    std::getline(std::cin, userName);

    std::cout << "Ship name: ";
    std::getline(std::cin, shipName);

    std::cout << std::format("| Player: {} | Ship: {} | Initial Fuel: {} | Initial Resources: {} |",
                             userName, shipName, fuel, resources)<< std::endl;

    // Condition loop to stop when fuel is depleted.
    while (isPlaying) {
        printMenu();
        std::cout << "Enter you choice: ";
        int choice;
        std::cin >> choice;

        // Based on user's choice, call a function to handle the action.
        switch (choice) {
            case 1:
                // assign the string returned from the explorePlanet function to the currentPlanet variable.
                currentPlanet = explorePlanet(planets, fuel, resources);
                break;
            case 2:
                // pass the address of the variable fuel.
                refuelShip(&fuel);
                break;
            case 3:
                navigateSystem(events, fuel, resources);
                break;
            case 4:
                saveGame(userName, shipName, currentPlanet, fuel, resources);
                break;
            case 5:
                loadGame(userName, shipName, currentPlanet, fuel, resources);
                break;
            case 6:
                // give user the option to exit without saving.
                std::cout << "Exiting the game. Goodbye!\n";
                isPlaying = false;
                break;
            default:
                std::cout << "Invalid choice.";
                break;
        }
        if (fuel <= 0) {
            std::cout << "Game Over: Your fuel has been depleted. Your journey has ended.\n";
            isPlaying = false;
        }
    }
    return 0;
}

void printMenu() {
    std::cout << "\nChoose an Option:\n";
    std::cout << "1. Explore a Planet\n"
                 "2. Refuel at a Station\n"
                 "3. Navigate to a New System\n"
                 "4. Save Game\n"
                 "5. Load Game\n"
                 "6. Exit Game" << std::endl;
}

// explores a random planet, decreasing the fuel and increasing resources. Returns the name of the selected planet.
std::string explorePlanet(const std::array<std::string, 5>& planets, int &fuel, int &resources) {
    const int fuelConsumption = 5;
    const int resourcesGain = 10;
    fuel -= fuelConsumption;
    resources += resourcesGain;

    // local distribution to select random index within array size.
    static std::uniform_int_distribution<int> planetIndex{0, static_cast<int>(planets.size()) - 1};

    int index = planetIndex(engine);

    std::cout << std::format("Exploring planet {} ", planets.at(index));
    std::cout << "Fuel decreased by 5. Resources increased by 10.\n";
    std::cout << std::format("Fuel: {}, Resources {}", fuel, resources);

    return planets.at(index);
}

// Attempt to refuel the ship, by passing fuel as a pointer, with a chance of success.
void refuelShip(int *fuel) {
    const int fuelGain = 15;

    // local distribution to 50% chance.
    static std::uniform_int_distribution chances{0, 1};

    if (chances(engine) == 1) {
        // Dereference the pointer to increase the original fuel variable.
        *fuel += fuelGain;
        std::cout << "Refuel successfully! Fuel increased by " << fuelGain << ".\n";
    } else {
        std::cout << "No refueling station currently available. Try again later.\n";
    }
    std::cout << "Current fuel: " << *fuel << "\n";
}

// moves the player to a new system and trigger a random event.
void navigateSystem(std::vector<std::string>& events, int &fuel, int &resources) {

    // array of systems that will be picked randomly.
    const std::array<std::string, 10> systems = {"Alpha Centauri System", "Proxima Centauri System", "Sirius System",
                                                 "Vega System", "Betelgeuse System", "Andromeda System", "Altair System",
                                                 "Rigel System", "Arcturus System", "Polaris System"};

    // choose a system randomly.
    static std::uniform_int_distribution randomSystem{0, static_cast<int>(systems.size()) - 1};
    int systemsIndex = randomSystem(engine);

    std::cout << std::format("Buckle up! Navigating to {}... ", systems.at(systemsIndex)) << std::endl;

    // choose an event randomly.
    static std::uniform_int_distribution trigger{0, static_cast<int>(events.size()) - 1};
    int eventsIndex = trigger(engine);

    // print the random event.
    std::cout << events.at(eventsIndex) << std::endl;

    // Modify fuel and resources based on the random event.
    if (eventsIndex == 0) {
        // Alien waving.
        std::cout << "No impact on fuel or resources.\n";
    } else if (eventsIndex == 1) {
        // Alien offers resource boost.
        resources += 15;
        std::cout << "Resources increased by 15.\n";
    } else if (eventsIndex == 2) {
        // Alien offers fuel boost.
        fuel += 10;
        std::cout << "Fuel increased by 10.\n";
    } else if (eventsIndex == 3) {
        // Alien pirates attacking.
        fuel -= 20;
        resources -= 20;
        std::cout << "Fuel and resources decreased by 20 due to alien pirate attack.\n";
    } else if (eventsIndex == 4) {
        // Space debris.
        fuel -= 5;
        std::cout << "Fuel decreased by 5 due to space debris.\n";
    } else if (eventsIndex == 5) {
        // Nothing happens.
        std::cout << "No changes in fuel or resources.\n";
    }
    std::cout << std::format("Current Fuel: {}, Current Resources: {}\n", fuel, resources);
}

// writes the player name, the ship name, current planet, the fuel value concatenated to a text file extension .space
void saveGame(const std::string& userName, const std::string& shipName, const std::string& currentPlanet, int fuel,
              int resources) {

    std::string fileName = userName + "_" + shipName + ".space";

    if (std::ofstream output{fileName}) {
        output << userName << " " << shipName << " " << currentPlanet << " " << fuel << " " << resources << "\n";
        std::cout << "Game saved to " << fileName << "\n";
    } else {
        std::cerr << "Error: Could not open file for saving.\n";
        std::exit(EXIT_FAILURE);
    }
}

// Read from a saved file. Parameters are meant to be modified when loading data to update the game state.
void loadGame(std::string& userName, std::string& shipName, std::string& currentPlanet, int& fuel, int& resources) {

    std::string fileName = userName + "_" + shipName + ".space";

    if (std::ifstream input{fileName}) {
        if (input >> userName >> shipName >> currentPlanet >> fuel >> resources) {
            std::cout << "Game loaded successfully.\n";
            std::cout << "Welcome back, " << userName << "! You are currently at " << currentPlanet << ".\n";
            std::cout << std::format("Current Fuel: {}, Current Resources: {}\n", fuel, resources);

        } else {
            std::cerr << "Error: File format is incorrect.\n";
        }
    } else {
        std::cerr << "Error: Could not open save file.\n";
        std::exit(EXIT_FAILURE);
    }
}
