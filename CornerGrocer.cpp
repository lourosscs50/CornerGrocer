/*
 * Course:        CS-210 Programming Languages
 * Project:       Project Three – Corner Grocer
 * Student Name:  Lou Carron
 * Date:          December 13, 2025
 * Description:
 *   This program analyzes daily grocery purchase data for the Corner Grocer.
 *   It reads item names from an input text file, calculates the frequency of
 *   each item using a map, and allows the user to interact with the data
 *   through a menu-driven interface. The program supports searching for an
 *   individual item's frequency, displaying all item frequencies, printing
 *   a histogram, and exporting frequency data to an output file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include <cctype>

using namespace std;

// ---------- Helpers ----------
string ToLower(const string& s) {
    string out = s;
    for (char& ch : out) {
        ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
    }
    return out;
}

void PressEnterToContinue() {
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ---------- Core Functions ----------
void LoadData(const string& inputFile,
    map<string, int>& freqByKeyLower,
    map<string, string>& displayNameByKeyLower) {
    ifstream fin(inputFile);
    if (!fin.is_open()) {
        throw runtime_error("Could not open input file: " + inputFile);
    }

    string item;
    while (getline(fin, item)) {
        if (item.empty()) continue;

        string key = ToLower(item);

        // Save the first-seen display name for this normalized key
        if (displayNameByKeyLower.find(key) == displayNameByKeyLower.end()) {
            displayNameByKeyLower[key] = item;
        }

        freqByKeyLower[key]++;
    }

    fin.close();
}

void SaveFrequencyFile(const string& outputFile,
    const map<string, int>& freqByKeyLower,
    const map<string, string>& displayNameByKeyLower) {
    ofstream fout(outputFile);
    if (!fout.is_open()) {
        throw runtime_error("Could not create output file: " + outputFile);
    }

    // Format: ItemName count
    for (const auto& pair : freqByKeyLower) {
        const string& key = pair.first;
        int count = pair.second;

        auto dnIt = displayNameByKeyLower.find(key);
        string displayName = (dnIt != displayNameByKeyLower.end()) ? dnIt->second : key;

        fout << displayName << " " << count << "\n";
    }

    fout.close();
}

void PrintMenu() {
    cout << "\n===== Corner Grocer Menu =====\n";
    cout << "1. Look up an item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Choose an option (1-4): ";
}

int GetMenuChoice() {
    int choice;
    while (true) {
        if (cin >> choice && choice >= 1 && choice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear line
            return choice;
        }
        cout << "Invalid choice. Enter 1, 2, 3, or 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Option1_SearchItem(const map<string, int>& freqByKeyLower,
    const map<string, string>& displayNameByKeyLower) {
    cout << "Enter item name: ";
    string query;
    getline(cin, query);

    string key = ToLower(query);
    auto it = freqByKeyLower.find(key);

    if (it == freqByKeyLower.end()) {
        cout << query << " appears 0 times.\n";
    }
    else {
        auto dnIt = displayNameByKeyLower.find(key);
        string displayName = (dnIt != displayNameByKeyLower.end()) ? dnIt->second : query;
        cout << displayName << " appears " << it->second << " times.\n";
    }
}

void Option2_PrintAll(const map<string, int>& freqByKeyLower,
    const map<string, string>& displayNameByKeyLower) {
    cout << "\n--- All Item Frequencies ---\n";
    for (const auto& pair : freqByKeyLower) {
        const string& key = pair.first;
        int count = pair.second;

        auto dnIt = displayNameByKeyLower.find(key);
        string displayName = (dnIt != displayNameByKeyLower.end()) ? dnIt->second : key;

        cout << displayName << " " << count << "\n";
    }
}

void Option3_PrintHistogram(const map<string, int>& freqByKeyLower,
    const map<string, string>& displayNameByKeyLower) {
    cout << "\n--- Histogram ---\n";
    for (const auto& pair : freqByKeyLower) {
        const string& key = pair.first;
        int count = pair.second;

        auto dnIt = displayNameByKeyLower.find(key);
        string displayName = (dnIt != displayNameByKeyLower.end()) ? dnIt->second : key;

        cout << displayName << " ";
        for (int i = 0; i < count; i++) {
            cout << "*";
        }
        cout << "\n";
    }
}

int main() {
    map<string, int> freqByKeyLower;          // key: lowercase item, value: count
    map<string, string> displayNameByKeyLower; // key: lowercase item, value: first-seen original

    cout << "Enter input file name (example: CS210_Project_Three_Input_File.txt): ";
    string inputFile;
    getline(cin, inputFile);

    if (inputFile.empty()) {
        // If user just hits enter, you can choose a default
        inputFile = "CS210_Project_Three_Input_File.txt";
        cout << "No file entered. Using default: " << inputFile << "\n";
    }

    const string outputFile = "frequency.dat";

    try {
        LoadData(inputFile, freqByKeyLower, displayNameByKeyLower);
        SaveFrequencyFile(outputFile, freqByKeyLower, displayNameByKeyLower);

        cout << "\nLoaded data successfully.\n";
        cout << "Created output file: " << outputFile << "\n";

        while (true) {
            PrintMenu();
            int choice = GetMenuChoice();

            if (choice == 1) {
                Option1_SearchItem(freqByKeyLower, displayNameByKeyLower);
                PressEnterToContinue();
            }
            else if (choice == 2) {
                Option2_PrintAll(freqByKeyLower, displayNameByKeyLower);
                PressEnterToContinue();
            }
            else if (choice == 3) {
                Option3_PrintHistogram(freqByKeyLower, displayNameByKeyLower);
                PressEnterToContinue();
            }
            else { // 4
                cout << "Exiting program. Goodbye.\n";
                break;
            }
        }
    }
    catch (const exception& e) {
        cerr << "\nERROR: " << e.what() << "\n";
        cerr << "Make sure the input file is in the same folder as the .exe (or set working directory correctly).\n";
        return 1;
    }

    return 0;
}
