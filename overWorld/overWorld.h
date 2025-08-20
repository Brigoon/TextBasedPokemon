#ifndef OVERWORLD_H
#define OVERWORLD_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Overworld {
private:
    std::vector<std::string> mapData;
    int playerX = -1; // Player's X position
    int playerY = -1; // Player's Y position

public:
    // Constructor
    Overworld() {}

    // Method to load the map from a file
    bool loadMap(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filePath << std::endl;
            return false;
        }

        std::string line;
        mapData.clear();
        playerX = -1;
        playerY = -1;

        int y = 0;
        while (std::getline(file, line)) {
            mapData.push_back(line);
            // Find the player's starting position (denoted by 's')
            size_t x = line.find('s');
            if (x != std::string::npos) {
                playerX = static_cast<int>(x);
                playerY = y;
            }
            y++;
        }

        file.close();

        if (playerX == -1 || playerY == -1) {
            std::cerr << "Error: Starting position 's' not found in the map." << std::endl;
            return false;
        }

        return true;
    }

    // Method to display the map with the player's position
    void displayMap() const {
        const int viewRadius = 5;

        int startY = std::max(0, playerY - viewRadius);
        int endY = std::min(static_cast<int>(mapData.size()), playerY + viewRadius + 1);
        int startX = std::max(0, playerX - viewRadius);
        int endX = std::min(playerX + viewRadius + 1, mapData.empty() ? 0 : static_cast<int>(mapData[0].size()));

        // Top border
        std::cout << " ";
        for (int x = startX; x < endX; ++x) {
            std::cout << "-";
        }
        std::cout << std::endl;

        for (int y = startY; y < endY; ++y) {
            std::cout << "|"; // Left border
            for (int x = startX; x < endX; ++x) {
                if (x == playerX && y == playerY) {
                    std::cout << 'P'; // Display the player as 'P'
                } else if (mapData[y][x] == 's') {
                    std::cout << ' '; // Display 's' as a space
                } else {
                    std::cout << mapData[y][x];
                }
            }
            std::cout << "|" << std::endl; // Right border
        }

        // Bottom border
        std::cout << " ";
        for (int x = startX; x < endX; ++x) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }

    // Method to move the player
    bool movePlayer(char direction) {
        int newX = playerX;
        int newY = playerY;

        switch (tolower(direction)) {
            case 'w': newY--; break; // Move up
            case 's': newY++; break; // Move down
            case 'a': newX--; break; // Move left
            case 'd': newX++; break; // Move right
            default:
                std::cerr << "Invalid direction! Use 'w', 'a', 's', or 'd'." << std::endl;
                return false;
        }

        // Check boundaries and obstacles
        if (newY >= 0 && newY < mapData.size() &&
            newX >= 0 && newX < mapData[newY].size() &&
            mapData[newY][newX] != '#') { // Assuming '#' represents an obstacle
            playerX = newX;
            playerY = newY;
            return true;
        } else {
            std::cerr << "Cannot move in that direction!" << std::endl;
            return false;
        }
    }

    // Getter for map data
    const std::vector<std::string>& getMapData() const {
        return mapData;
    }
};

#endif // OVERWORLD_H