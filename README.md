# Space Adventure Game

## Project Overview
This is a console-based Space Adventure Game built in C++. The player takes on the role of a spaceship captain exploring the galaxy. The game features interactive choices, random events, and resource management, including fuel and resources. The player can explore planets, refuel their ship, navigate to new star systems, and save/load their progress.

---

## Game Description
The player is presented with a menu of actions each turn:
1. **Explore a Planet**: Reduces fuel and may increase resources based on random events.
2. **Refuel at a Station**: Attempts to refuel the ship, with a chance of the station being unavailable.
3. **Navigate to a New System**: Moves the player to a new system and triggers random events (e.g., encountering aliens or space pirates).
4. **Save Game**: Saves the current game state (player name, ship name, fuel, resources, and location) to a `.space` file.
5. **Load Game**: Loads a saved game state from a `.space` file.

The game ends when the player's fuel drops to zero.

---

## Project Requirements
### Implemented Features
1. **Basic Setup**:
   - Player and ship names are entered at the start.
   - Fuel and resources are initialized (100 fuel, 50 resources).
2. **Player Choices**:
   - Menu-driven gameplay with options to explore, refuel, navigate, save, and load.
3. **Functions**:
   - `explorePlanet`: Handles planet exploration and random events.
   - `refuelShip`: Attempts to refuel the ship with a chance of failure.
   - `navigateSystem`: Moves the player to a new system and triggers random events.
   - `saveGame`: Saves the game state to a `.space` file.
   - `loadGame`: Loads the game state from a `.space` file.
4. **Random Events**:
   - Random events are implemented using the `<random>` library.
5. **Arrays/Vectors**:
   - Planet names are stored in a `std::array`.
   - Random events are stored in a `std::vector`.
6. **Pointers**:
   - A raw pointer is used to modify fuel in the `refuelShip` function.
   - Most objects are passed by reference to avoid unnecessary copying.
7. **Game Over**:
   - The game ends when fuel reaches zero, using a flag variable to control the game loop.

---

## How to Run the Program
1. **Prerequisites**:
   - Ensure you have a C++ compiler (e.g., GCC, Clang) or an IDE like CLion installed.
2. **Compilation**:
   - Open the project in CLion or your preferred IDE.
   - Build the project using the IDE's build tools.
3. **Execution**:
   - Run the compiled executable from the terminal or IDE.
   - Follow the on-screen prompts to play the game.

---

## Completion Statement
- **Implemented Requirements**:
  - All core features (exploration, refueling, navigation, saving, loading) are implemented.
  - Random events, arrays/vectors, and pointers are used as specified.
  - The game loop ends gracefully when fuel is depleted.
- **Challenges**:
  - Implementing random events and ensuring they impacted gameplay meaningfully was challenging.
  - Managing file I/O for saving and loading required careful handling of data.
- **Help Received**:
  - Referenced the C++ documentation for the `<random>` library and file I/O.

---

## Citations
- **C++ Documentation**: Used for `<random>` library and file I/O.
- **Tutor Assistance**: Clarified pointer usage and reference passing.

---

## Code Structure
- **Header Comments**: File includes a comment header with the author's name, assignment details, and a brief description.
- **Comments**: Code is well-commented to explain functionality and improve readability.
  
---

## Files Included
1. `main.cpp`: Contains the main game loop and function calls.
2. `README.md`: This file.

---

## Author
- **Name**: Arianny Abreu Gonzalez
- Space Adventure Project
