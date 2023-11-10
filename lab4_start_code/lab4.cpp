#include <iostream>

using namespace std;

const int MAX_RADAR_CAPACITY = 5;

// Task 1: Initialize the radar system
void initialize_radar_system(int radar[]) {
    // Initialize all radar elements to 0 (no alien detected).
    for (int i = 0; i < MAX_RADAR_CAPACITY; i++) {
        radar[i] = 0;
    }
}

// Task 2: Detect and track an incoming alien ship
bool detect_alien_ship(int radar[], int alienID) {
    for (int i = 0; i < MAX_RADAR_CAPACITY; i++) {
        if (radar[i] == 0) {
            radar[i] = alienID;
            return true;
        }
    }
    return false;
}

// Task 3: Engage in battle and eliminate all alien ships with a specific ID
int engage_in_battle(int radar[], int alienID) {
    int count = 0;
    for (int i = 0; i < MAX_RADAR_CAPACITY; i++) {
        if (radar[i] == alienID) {
            radar[i] = 0;
            count++;
        }
    }
    return count;
}

// Task 4: Count the total number of alien ships currently in radar
int count_total_alien_ships(int radar[]) {
    int count = 0;
    for (int i = 0; i < sizeof(radar[0]); i++) {
        if (radar[i] != 0) {
            count++;
        }
    }
    return count;
}

// Task 5: Display the current radar status
// tips: you need to display the radar status in the following format:
//      Radar Status: [1 1 1 0 0]
void display_radar_status(int radar[]) {
    ///////////////////
    // Your Code Here //
    
    std::cout << "Radar Status: [";
    
    // Iterate through the array and print each element
    for (int i = 0; i < MAX_RADAR_CAPACITY; i++) {
        // std::cout << MAX_RADAR_CAPACITY;
        std::cout << radar[i];
        
        // Add a space after each element, except the last one
        if (i != ( MAX_RADAR_CAPACITY - 1)) {
            std::cout << " ";
        }
    }
    
    std::cout << "]" << std::endl;
    
    ///////////////////
}

int main() {
    int radar[MAX_RADAR_CAPACITY];
    initialize_radar_system(radar);
    cout << "Alien Invasion Game Menu:" << endl;
    cout << "1. Detect and track an alien ship" << endl;
    cout << "2. Engage in battle and eliminate alien ships" << endl;
    cout << "3. Count total alien ships" << endl;
    cout << "4. Display radar status" << endl;
    cout << "0. Quit the game" << endl;
    int choice;
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        int alienID; // Declare alienID outside of the switch statement
        int eliminatedCount; // Declare eliminatedCount outside of the switch statement
        int totalAlienShips; // Declare totalAlienShips outside of the switch statement

        switch (choice) {
            case 1:
                cout << "Enter the ID of the alien ship to detect: ";
                cin >> alienID;
                if (detect_alien_ship(radar, alienID)) {
                    cout << "Alien ship with ID " << alienID << " detected and tracked." << endl;
                } else {
                    cout << "Radar is already full. Cannot track more aliens." << endl;
                }
                break;
            case 2:
                cout << "Enter the ID of the alien ship to engage in battle: ";
                cin >> alienID;
                eliminatedCount = engage_in_battle(radar, alienID);
                cout << "Eliminated " << eliminatedCount << " alien ship(s) with ID " << alienID << "." << endl;
                break;
            case 3:
                totalAlienShips = count_total_alien_ships(radar);
                cout << "Total number of detected alien ships: " << totalAlienShips << endl;
                break;
            case 4:
                display_radar_status(radar);
                break;
            case 0:
                cout << "Exiting the game. Goodbye!";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}

