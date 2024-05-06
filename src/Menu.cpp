//
// Created by aqueiros_22 on 06-05-2024.
//
#include <iostream>
#include "Menu.h"

using namespace std;


Menu::Menu() {}

void Menu::start() {
    int option;
    cout << "Choose the type of graph to read:" << endl;
    cout << "1. Toy Graphs" << endl;
    cout << "2. Extra Fully Connected Graphs" << endl;
    cout << "3. Real-world Graphs" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1:
            readToyGraph();
            break;
        case 2:
            readExtraFullyConnectedGraph();
            break;
        case 3:
            readRealWorldGraph();
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }
}

void Menu::readToyGraph() {
    int option;
    cout << "Choose which toy graph to read:" << endl;
    cout << "1. Shipping" << endl;
    cout << "2. Stadiums" << endl;
    cout << "3. Tourism" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    data.readToyGraphs(option);
}

void Menu::readExtraFullyConnectedGraph() {
    int option;
    cout << "Choose which extra fully connected graph to read:" << endl;
    cout << "1. 25 Edges" << endl;
    cout << "2. 50 Edges" << endl;
    cout << "3. 75 Edges" << endl;
    cout << "4. 100 Edges" << endl;
    cout << "5. 200 Edges" << endl;
    cout << "6. 300 Edges" << endl;
    cout << "7. 400 Edges" << endl;
    cout << "8. 500 Edges" << endl;
    cout << "9. 600 Edges" << endl;
    cout << "10. 700 Edges" << endl;
    cout << "11. 800 Edges" << endl;
    cout << "12. 900 Edges" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    data.readExtra(option);
}

void Menu::readRealWorldGraph() {
    int option;
    cout << "Choose which real-world graph to read:" << endl;
    cout << "1. Graph 1" << endl;
    cout << "2. Graph 2" << endl;
    cout << "3. Graph 3" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    data.readReal(option);
}