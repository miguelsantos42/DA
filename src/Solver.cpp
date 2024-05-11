//
// Created by miguel on 08-05-2024.
//

#include "Solver.h"

using namespace std;

Solver::Solver() {
    this->bestCost = INT32_MAX;
}

void Solver::backtrackingDfs(Graph<string>* graph, Vertex<string>* current, double cost, vector<Vertex<string>*> &path) {
    // cancel if first node is reached before the end
    if(cost >= bestCost  || (path.size() != graph->getNumVertex() && current->isVisited() && current->getInfo() == "0")){
        return;
    }
    if(path.size() == graph->getNumVertex()){
        if(cost < bestCost && current->getInfo() == "0"){
            bestCost = cost;
            cout << "Found best of " << bestCost << "\n";
            cout << "Path:";
            for (auto i : path){
                cout << i->getInfo() << " ";
            }
            cout << "\n";
        }
        return;
    }
    for (auto neighbour: current->getAdj()) {
        if (neighbour->getDest()->isVisited())
            continue;
        neighbour->getDest()->setVisited(true);
        cost += neighbour->getWeight();
        path.push_back(neighbour->getDest());
        backtrackingDfs(graph, neighbour->getDest(), cost, path);
        neighbour->getDest()->setVisited(false);
        cost -= neighbour->getWeight();
        path.pop_back();
    }
}

double Solver::tspBacktracking(Graph<string>* graph) {
    vector<Vertex<string>*> path;
    backtrackingDfs(graph, graph->findVertex("0"), 0, path);
    return bestCost;
}