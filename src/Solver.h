//
// Created by miguel on 08-05-2024.
//

#ifndef PROJETO_DA_2_SOLVER_H
#define PROJETO_DA_2_SOLVER_H


#include <unordered_map>
#include "../data_structures/Graph.h"

using namespace std;

class Solver {
public:
    double bestCost;
    vector<Vertex<string>*> bestPath;
    Solver();
    double tspBacktracking(Graph <string>* graph );
    void backtrackingDfs(Graph<string>* graph, Vertex<string>* current, double cost, vector<Vertex<string>*> &path);

    double getDistance(Graph<string> *graph, const vector<string> &path);

    void dfs(vector<Edge<string>*>& mst, Vertex<string>* vertex, unordered_map<string, bool>& visited, vector<string>& preorder);

    double triangularApproximation(Graph<string> *graph);
};


#endif //PROJETO_DA_2_SOLVER_H
