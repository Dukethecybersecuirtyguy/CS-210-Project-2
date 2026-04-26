/*
 * main.cpp
 * Date: April 21, 2026
 * Author: Caleb DeBord
 * Course: CS210
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits> // Included for input validation

using namespace std;

// I am creating the class required by the rubric
class ItemTracker {
private:
    // A map to hold my items (words) and their counts (numbers)
    map<string, int> itemFrequencies;

public:
    // Function to read the input file and populate the map
    void LoadData(string filename) {
        ifstream inFS;
        string item;

        inFS.open(filename);

        // Check to make sure the file actually opened
        if (!inFS.is_open()) {
            cout << "Error: Could not open the file." << endl;
            return;
        }

        // Loop through the file one word at a time
        while (inFS >> item) {
            // This adds the item to the map or adds 1 to the count if it is already there
            itemFrequencies[item]++;
        }
        
        inFS.close();
    }

    // Function to create the backup .dat file
    void BackupData(string filename) {
        ofstream outFS;
        outFS.open(filename);

        if (!outFS.is_open()) {
            cout << "Error: Could not create backup file." << endl;
            return;
        }

        // Using a standard iterator to loop through the map
        for (auto it = itemFrequencies.begin(); it != itemFrequencies.end(); ++it) {
            outFS << it->first << " " << it->second << endl;
        }

        outFS.close();
    }

    // Menu Option 1
    int GetItemFrequency(string targetItem) {
        // Check if the item is in the map using the count function
        if (itemFrequencies.count(targetItem) > 0) {
            return itemFrequencies[targetItem];
        }
        // If they didn't buy it, return 0
        return 0;
    }

    // Menu Option 2
    void PrintAllFrequencies() {
        cout << "\n--- All Items ---" << endl;
        // Loop through and print the key (first) and value (second)
        for (auto it = itemFrequencies.begin(); it != itemFrequencies.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
        cout << "-----------------\n" << endl;
    }

    // Menu Option 3
    void PrintHistogram() {
        cout << "\n--- Histogram ---" << endl;
        for (auto it = itemFrequencies.begin(); it != itemFrequencies.end(); ++it) {
            cout << it->first << " ";
            // Nested loop to print the stars for the number of times it was bought
            for (int i = 0; i < it->second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
        cout << "-----------------\n" << endl;
    }
};


int main() {
    ItemTracker grocerTracker;
    int menuChoice = 0;
    string searchItem;

    // Call the load function and backup function right away
    grocerTracker.LoadData("CS210_Project_Three_Input_File.txt");
    grocerTracker.BackupData("frequency.dat");

    // Loop until they type 4 to exit
    while (menuChoice != 4) {
        cout << "1. Search for an item" << endl;
        cout << "2. Print all items" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";

        cin >> menuChoice;

        // Input validation check to see if they typed a letter instead of a number
        if (cin.fail()) {
            cout << "Invalid input. Please type a number 1-4." << endl << endl;
            cin.clear(); // Clears the error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Empties the buffer
            continue; 
        }

        // Standard switch statement for the menu
        switch (menuChoice) {
            case 1:
                cout << "Enter item name: ";
                cin >> searchItem;
                cout << searchItem << " count: " << grocerTracker.GetItemFrequency(searchItem) << endl << endl;
                break;
            case 2:
                grocerTracker.PrintAllFrequencies();
                break;
            case 3:
                grocerTracker.PrintHistogram();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select 1-4." << endl << endl;
                break;
        }
    }

    return 0;
}