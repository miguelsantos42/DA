//
// Created by aqueiros_22 on 06-05-2024.
//

#ifndef PROJETO_DA_2_DATA_H
#define PROJETO_DA_2_DATA_H

#include "../data_structures/Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;



class Data {
private:
    Graph<string>* graph;
public:
    Data();

    Graph<string>* getGraph();
    void clearGraph();
    void readToyGraphs(int x);
    void readExtra(int x);


    void readReal(int x);



};


#endif //PROJETO_DA_2_DATA_H
