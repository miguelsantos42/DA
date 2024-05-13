//
// Created by miguel on 08-05-2024.
//

#ifndef PROJETO_DA_2_SOLVER_H
#define PROJETO_DA_2_SOLVER_H


#include "../data_structures/Graph.h"

using namespace std;

class Solver {
public:
    double bestCost;
    vector<Vertex<string>*> bestPath;
    Solver();
    double tspBacktracking(Graph <string>* graph );
    void backtrackingDfs(Graph<string>* graph, Vertex<string>* current, double cost, vector<Vertex<string>*> &path);

};


#endif //PROJETO_DA_2_SOLVER_H
