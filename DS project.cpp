#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_PLAYERS = 100;

// Structure to store player details
struct Player {
    string name;
    int runs;
};

// Function prototypes
void addPlayer(Player players[], int &count);
void displayPlayers(const Player players[], int count);
void calculateStats(const Player players[], int count);
void findHighestScorer(const Player players[], int count);
void searchPlayer(const Player players[], int count);
void rankPlayers(Player players[], int count);

int main() {
    Player players[MAX_PLAYERS];
    int count = 0;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "      CRICKET SCORE MANAGEMENT SYSTEM    \n";
        cout << "=========================================\n";
        cout << "1. Add Player\n";
        cout << "2. Display All Players\n";
        cout << "3. Show Total and Average Runs\n";
        cout << "4. Find Highest Scorer\n";
        cout << "5. Search Player\n";
        cout << "6. Rank Players by Runs\n";
        cout << "7. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPlayer(players, count);
                break;
            case 2:
                displayPlayers(players, count);
                break;
            case 3:
                calculateStats(players, count);
                break;
            case 4:
                findHighestScorer(players, count);
                break;
            case 5:
                searchPlayer(players, count);
                break;
            case 6:
                rankPlayers(players, count);
                break;
            case 7:
                cout << "\nExiting the program. Thank you!\n";
                break;
            default:
                cout << "\nInvalid choice! Please choose between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}

void addPlayer(Player players[], int &count) {
    if (count >= MAX_PLAYERS) {
        cout << "\nError: Player storage is full!\n";
        return;
    }
    cout << "\nEnter Player Name: ";
    cin.ignore();
    getline(cin, players[count].name);
    cout << "Enter Runs Scored: ";
    cin >> players[count].runs;
    
    count++;
    cout << "Player added successfully!\n";
}

void displayPlayers(const Player players[], int count) {
    if (count == 0) {
        cout << "\nNo records found! Please add players first.\n";
        return;
    }
    cout << "\n-----------------------------------------\n";
    cout << left << setw(20) << "Player Name" << setw(10) << "Runs" << endl;
    cout << "-----------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << left << setw(20) << players[i].name << setw(10) << players[i].runs << endl;
    }
    cout << "-----------------------------------------\n";
}

void calculateStats(const Player players[], int count) {
    if (count == 0) {
        cout << "\nNo records found! Please add players first.\n";
        return;
    }
    int totalRuns = 0;
    for (int i = 0; i < count; i++) {
        totalRuns += players[i].runs;
    }
    double averageRuns = (double)totalRuns / count;

    cout << "\n-----------------------------------------\n";
    cout << "Total Players: " << count << endl;
    cout << "Total Runs:    " << totalRuns << endl;
    cout << "Average Runs:  " << fixed << setprecision(2) << averageRuns << endl;
    cout << "-----------------------------------------\n";
}

void findHighestScorer(const Player players[], int count) {
    if (count == 0) {
        cout << "\nNo records found! Please add players first.\n";
        return;
    }
    int maxIndex = 0;
    for (int i = 1; i < count; i++) {
        if (players[i].runs > players[maxIndex].runs) {
            maxIndex = i;
        }
    }
    cout << "\n-----------------------------------------\n";
    cout << "HIGHEST SCORER:\n";
    cout << "Name: " << players[maxIndex].name << endl;
    cout << "Runs: " << players[maxIndex].runs << endl;
    cout << "-----------------------------------------\n";
}

void searchPlayer(const Player players[], int count) {
    if (count == 0) {
        cout << "\nNo records found! Please add players first.\n";
        return;
    }
    string searchName;
    cout << "\nEnter the name of the player to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (players[i].name == searchName) {
            cout << "\nPlayer Found!\n";
            cout << "Name: " << players[i].name << " | Runs: " << players[i].runs << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nPlayer '" << searchName << "' not found.\n";
    }
}

void rankPlayers(Player players[], int count) {
    if (count == 0) {
        cout << "\nNo records found! Please add players first.\n";
        return;
    }
    
    // Copy array to preserve original insertion order
    Player temp[MAX_PLAYERS];
    for (int i = 0; i < count; i++) {
        temp[i] = players[i];
    }

    // Bubble Sort in descending order by runs
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (temp[j].runs < temp[j + 1].runs) {
                Player t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    cout << "\n-----------------------------------------\n";
    cout << "PLAYER RANKINGS (BY RUNS)\n";
    cout << "-----------------------------------------\n";
    cout << left << setw(8) << "Rank" << setw(20) << "Player Name" << setw(10) << "Runs" << endl;
    cout << "-----------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << left << setw(8) << (i + 1) << setw(20) << temp[i].name << setw(10) << temp[i].runs << endl;
    }
    cout << "-----------------------------------------\n";
}
