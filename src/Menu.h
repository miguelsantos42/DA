//
// Created by aqueiros_22 on 06-05-2024.
//

#ifndef PROJETO_DA_2_MENU_H
#define PROJETO_DA_2_MENU_H

#include "Data.h"

class Menu {
private:
    Data data;
public:
    Menu();
    void start();
    void readToyGraph();
    void readExtraFullyConnectedGraph();
    void readRealWorldGraph();
};


#endif //PROJETO_DA_2_MENU_H
