#include <iostream>
#include "overWorld.h"

using namespace std;

int main() {
    Overworld overworld;

    if (!overworld.loadMap("overWorld/maps/startingRoom.txt")) {
        return 1; // Exit if map loading fails
    }
    overworld.displayMap();

    char input;
    while (true) {
        cout << "Enter movement (W/A/S/D to move, Q to quit): ";
        cin >> input;

        if (toupper(input) == 'Q') {
            cout << "Exiting game." << endl;
            return 0;
        }

        if (!overworld.movePlayer(input)) {
            cout << "Invalid input. Use W/A/S/D to move or Q to quit." << endl;
        }

        overworld.displayMap(); // Update the map display after movement
    }
}