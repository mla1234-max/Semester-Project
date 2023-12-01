#include <iostream>
#include <string.h>

using namespace std;

void RemoveInventory(float invChart[7][4], string invName[7], int section);
void CheckInventory(float invChart[7][4], string invName[7]);
void AddInventory(float invChart[7][4], string invName[7], int section);
void AddUpTotal(float invChart[7][4], string invName[7]);
void EditInv(float invChart[7][4], string invName[7], int section);
int main() {
    string invName[7] = {{"XXXXXXXXXX"},
                        {"XXXXXXXXXX"},
                        {"XXXXXXXXXX"},
                        {"XXXXXXXXXX"},
                        {"XXXXXXXXXX"},
                        {"XXXXXXXXXX"},
                        {"XXXXXXXXXX"}};
    float invChart[7][4] = {{'X','X','X','X'},
                            {'X','X','X','X'},
                            {'X','X','X','X'},
                            {'X','X','X','X'},
                            {'X','X','X','X'},
                            {'X','X','X','X'},
                            {'X','X','X','X'}};
    int selection = 0;
    int section;
    char enterAgain = 'N';
    do {
        cout << "[1] Check inventory\n"
             << "[2] Add to inventory\n"
             << "[3] Remove from inventory\n"
             << "[4] Add up total values\n"
             << "[5] Edit inventory\n"
             << "[6] Exit\n"
             << "Select an action: ";
        cin >> selection;
        while (selection < 1 || selection > 6) {
            cout << "Enter a value between 1 and 6:";
            cin >> selection;
        }
        switch(selection) {
        
        case 1:
            CheckInventory(invChart, invName);
            break;
        case 2:
            AddInventory(invChart, invName, section);
            break;
        case 3:
            RemoveInventory(invChart, invName, section);
            break;
        case 4:
            AddUpTotal(invChart, invName);
            break;
        case 5:
            EditInv(invChart, invName, section);
            break;
        case 6:
            return 0;
        }
    } while(selection != 6);
}

void RemoveInventory(float invChart[7][4], string invName[7], int section) {
    
    double removeAmount;
    cout << "Enter the section of inventory (1 to 7): ";
    cin >> section;
    
    if((invName[section - 1] != "XXXXXXXXXX") && (invChart[section - 1][1] != 'X') && (invChart[section - 1][2] != 'X') && (invChart[section - 1][3] == 1.0)) {
        
        invName[section - 1] = "XXXXXXXXXX";
        invChart[section - 1][0] = 'X';
        invChart[section - 1][1] = 'X';
        invChart[section - 1][2] = 'X';
        invChart[section - 1][3] = 'X';
        cout << "Your item has been removed.\n";
    }
    else if ((invName[section - 1] != "XXXXXXXXXX") && (invChart[section - 1][1] != 'X') && (invChart[section - 1][2] != 'X') && (invChart[section - 1][3] > 1.0)) {
        cout << "How much of this item do you want to remove (in decimal form)?: ";
        cin >> removeAmount;
        
        while (removeAmount < 1 && removeAmount > invChart[section - 1][3]) {
            cout << "Please select a valid remove amount: ";
            cin >> removeAmount;
        }
        
        if (removeAmount < invChart[section - 1][3]) {
            invChart[section - 1][3] = invChart[section - 1][3] - removeAmount;
            cout << "Your item's specified amount has been removed.\n";
        }
        else {
            invName[section - 1] = "XXXXXXXXXX";
            invChart[section - 1][0] = 'X';
            invChart[section - 1][1] = 'X';
            invChart[section - 1][2] = 'X';
            invChart[section - 1][3] = 'X';
            cout << "Your item has been removed.\n";
        }
    }
    else if ((invName[section - 1] != "XXXXXXXXXX") && (invChart[section - 1][1] != 'X') && (invChart[section - 1][2] != 'X') && (invChart[section - 1][3] != 'X')) {
        invName[section - 1] = "XXXXXXXXXX";
            invChart[section - 1][0] = 'X';
            invChart[section - 1][1] = 'X';
            invChart[section - 1][2] = 'X';
            invChart[section - 1][3] = 'X';
            cout << "Your item has been removed.\n";
    }
    else {
        cout << "Sorry, this section is already empty";
    }
}

void AddInventory(float invChart[7][4], string invName[7], int section) {
    string name;
    double weight;
    double price;
    double amount;
    
    cout << "Enter the section of inventory (1 to 7): ";
    cin >> section;
    
    if((invName[section - 1] == "XXXXXXXXXX") && (invChart[section - 1][1] == 'X') && (invChart[section - 1][2] == 'X') && (invChart[section - 1][3] == 'X')) {

        cout << "Enter item name (Use underscore _ as space): ";
        cin >> name;
        cout << "Enter item weight (pounds) in decimal form: ";
        cin >> weight;
        while (weight < 0) {
            cout << "Please enter a valid weight: ";
            cin >> weight;
        }
        cout << "Enter item price (dollars.cents): ";
        cin >> price;
        while (price < 0) {
            cout << "Please enter a valid price: ";
            cin >> price;
        }
        cout << "Enter item amount in decimal form: ";
        cin >> amount;
        while (amount < 0) {
            cout << "Please enter a valid amount: ";
            cin >> amount;
        }
        
        invName[section - 1] = name;
        invChart[section - 1][0] = ' ';
        invChart[section - 1][1] = weight;
        invChart[section - 1][2] = price;
        invChart[section - 1][3] = amount;
        cout << "Your item of name: " << name << ", weight: " << weight << ", price: " << price << ", amount: " << amount << " has been added.\n";
    }
    else {
        cout << "Enter item name (Use underscore _ as space): ";
        cin >> name;
        cout << "Enter item weight: ";
        cin >> weight;
        cout << "Enter item price: ";
        cin >> price;
        cout << "Enter item amount: ";
        cin >> amount;
        
        if ((name == invName[section - 1]) && (weight == invChart[section - 1][1]) && (price == invChart[section - 1][2])) {
            invName[section - 1] = name;
            invChart[section - 1][0] = ' ';
            invChart[section - 1][1] = weight;
            invChart[section - 1][2] = price;
            invChart[section - 1][3] = invChart[section - 1][3] + amount;
            cout << "Your item of name: " << name << ", weight: " << weight << ", price: " << price << ", amount: " << amount << " has been added to your current amount.\n";
        }
        else {
            cout << "Sorry, this section is already taken.";
        }
    }
}

void CheckInventory(float invChart[7][4], string invName[7]) {
    cout << "STATUS OF INVENTORY:";
    for(int i = 0; i < 7; i++) {
        cout << "\nSection " << i + 1 << ": ";
        for(int j = 0; j < 4; j++) {
            if (invChart[i][j] != 'X' && invName[i] != "XXXXXXXXXX") {
                if (j == 0) {
                    cout << "name: " << invName[i] << " |";    
                }
                else if (j == 1) {
                    cout << " weight: " << invChart[i][j] << " |";
                }
                else if (j == 2) {
                    cout << " price: " << invChart[i][j] << " |";
                }
                else {
                    cout << " amount: " << invChart[i][j];
                }
            }
            else {
                cout << "  ";
            }
        }
    }
    cout << "\n";
}

void AddUpTotal(float invChart[7][4], string invName[7]) {
    double weightTotal = 0.0;
    double priceTotal = 0.0;
    double amountTotal = 0.0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (invChart[i][j] == 'X') {
                invChart[i][j] = 0.0;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        weightTotal = weightTotal + (invChart[i][1] * invChart[i][3]);
    }
    for (int i = 0; i < 7; i++) {
        priceTotal = priceTotal + (invChart[i][2] * invChart[i][3]);
    }
    for (int i = 0; i < 7; i++) {
        amountTotal = amountTotal + invChart[i][3];
    }
    if (amountTotal == 1) {
        cout << "Your inventory consists of " << amountTotal << " item, in total weighing " << weightTotal << " pounds and costing $" << priceTotal;
    }
    else {
        cout << "Your inventory consists of " << amountTotal << " items, in total weighing " << weightTotal << " pounds and costing $" << priceTotal;
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (invName[i] == "XXXXXXXXXX") {
                invChart[i][j] = 'X';
            }
        }
    }
}
void EditInv(float invChart[7][4], string invName[7], int section) {
    int selection;
    string name;
    float weight;
    float price;
    float amount;
    char response;
    
    cout << "Name the section you want to edit (1 to 7): ";
    cin >> section;
    while (invName[section - 1] == "XXXXXXXXXX") {
        cout << "Please enter a section containing inventory: ";
        cin >> section;
    }
    cout << "What do you want to edit?\n"
         << "[1] Name\n"
         << "[2] Weight\n"
         << "[3] Price\n"
         << "[4] Amount\n"
         << "Your selection: ";
    cin >> selection;
    while (selection < 1 || selection > 4) {
        cout << "Please select a valid option";
        cin >> selection;
    }
    
    switch (selection) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            break;
        case 2:
            cout << "Enter weight: ";
            cin >> weight;
            break;
        case 3:
            cout << "Enter price: ";
            cin >> price;
            break;
        case 4:
            cout << "Enter amount: ";
            cin >> amount;
            break;
    }
    if (invName[section - 1] == name) {
        do {
            cout << "You have entered the same name. Would you like to keep it (Y or anything else)? ";
            cin >> response;
            if (response != 'Y' && response != 'y') {
                cout << "Enter name: ";
                cin >> name;
            }
            else {
                cout << "Your edit has been made\n";
            }
        } while (invName[section - 1] == name && response != 'Y' && response != 'y');
        invName[section - 1] = name;
    }
    else if (invChart[section - 1][1] == weight) {
        do {
            cout << "You have entered the same weight. Would you like to keep it (Y or anything else)? ";
            cin >> response;
            if (response != 'Y' && response != 'y') {
                cout << "Enter weight: ";
                cin >> weight;
            }
            else {
                cout << "Your edit has been made\n";
            }
        } while (invChart[section - 1][1] == weight && response != 'Y' && response != 'y');
        invChart[section - 1][1] = weight;
    }
    else if (invChart[section - 1][2] == price) {
        do {
            cout << "You have entered the same price. Would you like to keep it (Y or anything else)? ";
            cin >> response;
            if (response != 'Y' && response != 'y') {
                cout << "Enter price: ";
                cin >> price;
            }
            else {
                cout << "Your edit has been made\n";
            }
        } while (invChart[section - 1][2] == price && response != 'Y' && response != 'y');
        invChart[section - 1][2] = price;
    }
    else if (invChart[section - 1][3] == amount) {
        do {
            cout << "You have entered the same amount. Would you like to keep it (Y or anything else)? ";
            cin >> response;
            if (response != 'Y' && response != 'y') {
                cout << "Enter amount: ";
                cin >> amount;
            }
            else {
                cout << "Your edit has been made\n";
            }
        } while (invChart[section - 1][3] == amount && response != 'Y' && response != 'y');
        invChart[section - 1][3] = amount;
    }
    else {
        if (selection == 1) {
            invName[section - 1] = name;
        }
        else if (selection == 2) {
            invChart[section - 1][1] = weight;
        }
        else if (selection == 3) {
            invChart[section - 1][2] = price;
        }
        else {
            invChart[section - 1][3] = amount;
        }
        
        cout << "Your edit has been made\n";
    }
}
