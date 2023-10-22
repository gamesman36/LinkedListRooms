#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

class Room {
public:
    string name;
    string description;
    Room* north;
    Room* south;

    Room(const string& roomName, const string& roomDescription)
        : name(roomName), description(roomDescription), north(nullptr), south(nullptr) {}
};

int main() {
    // Create two rooms
    Room cave("Cave", "You are in a dark and damp cave.");
    Room forest("Forest", "You find yourself in a lush and dense forest.");

    // Link the rooms
    cave.north = &forest;
    forest.south = &cave;

    // Start the game in the cave
    Room* currentRoom = &cave;

    // Game loop
    while (true) {
        cout << currentRoom->name << "\n" << currentRoom->description << "\n";
        cout << "Enter a direction (north, south) or 'quit' to exit: ";
        string direction;
        cin >> direction;

        if (direction == "north" && currentRoom->north != nullptr) {
            currentRoom = currentRoom->north;
        } else if (direction == "south" && currentRoom->south != nullptr) {
            currentRoom = currentRoom->south;
        } else if (direction == "quit") {
            cout << "Goodbye!\n";
            break; // Exit the game loop
        } else {
            cout << "Invalid direction. Try 'north' or 'south', or 'quit' to exit." << "\n";
        }
        
        cin.ignore(); // Clear the input buffer
    }

    return 0;
}