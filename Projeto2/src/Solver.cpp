//
// Created by miguel on 08-05-2024.
//

#include <cstdint>
#include "Solver.h"
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>

#define R 6371.0

using namespace std;

Solver::Solver() {
    this->bestCost = INT32_MAX;
}

void Solver::backtrackingDfs(Graph<string>* graph, Vertex<string>* current, double cost, vector<Vertex<string>*> &path) {
    if(cost >= bestCost  || (path.size() != graph->getNumVertex() && current->isVisited() && current->getInfo() == "0")){
        return;
    }
    if(path.size() == graph->getNumVertex()){
        if(cost < bestCost && current->getInfo() == "0"){
            bestCost = cost;
            bestPath = path;
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
    cout << "Best cost: " << bestCost << "\n";
    cout << "Best path: 0 ";
    for (auto i : bestPath){
        cout << i->getInfo() << " ";
    }
    cout << "\n";
    return bestCost;
}



double haversine(double lat1, double lon1, double lat2, double lon2) {

    lat1 = lat1 * M_PI / 180;
    lon1 = lon1 * M_PI / 180;
    lat2 = lat2 * M_PI / 180;
    lon2 = lon2 * M_PI / 180;
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    // Calculate the distance.
    double distance = R * c;

    return distance;
}
double Solver::getDistance(Graph<string>* graph, const vector<string> &path) {
    double result = 0.0;
    for (int i = 0; i < path.size() - 1 ;i++) {
        string v1 = path[i];
        string v2 = path[i+1];
        if(!graph->edgeExists(v1, v2)){
            result += haversine(graph->findVertex(v1)->getLatitude(), graph->findVertex(v1)->getLongitude(),graph->findVertex(v2)->getLatitude(),graph->findVertex(v2)->getLongitude());
            continue;
        }
        else {
            Vertex<string> *v = graph->findVertex(v1);
            for(auto edge: v->getAdj()){
                if(edge->getDest()->getInfo() == v2){
                    result += edge->getWeight();
                    break;
                }
            }
        }
    }
    string final = path.back();
    if(!graph->edgeExists(final,path[0])){
        result += haversine(graph->findVertex(final)->getLatitude(), graph->findVertex(final)->getLongitude(),graph->findVertex(path[0])->getLatitude(),graph->findVertex(path[0])->getLongitude());
    }
    else{
        Vertex<string> *v = graph->findVertex(final);
        if (v != nullptr){
            for(auto edge: v->getAdj()){
                if(edge->getDest()->getInfo() == path[0]){
                    result += edge->getWeight();
                }
            }
        }
    }
    return result;
}
double Solver::triangularApproximation(Graph<string>* graph) {
    double res=0.0;
    vector<Edge<string>*> mst = graph->prim();

    unordered_map<string, bool> visited;
    vector<string> preorder;
    dfs(mst, mst[0]->getOrig(), visited, preorder);
    cout << "Path: ";
    for(const auto& vertex : preorder) {
        cout << vertex << " ";
    }
    cout << "0" << endl;
    res= getDistance(graph, preorder);
    cout<<"Distance: "<<res<<endl;
    return res;
}

void Solver::dfs(vector<Edge<string>*>& mst, Vertex<string>* vertex, unordered_map<string, bool>& visited, vector<string>& preorder) {
    visited[vertex->getInfo()] = true;
    preorder.push_back(vertex->getInfo());
    for(auto edge: mst){
        if(edge->getOrig()->getInfo() == vertex->getInfo() && !visited[edge->getDest()->getInfo()]){
            dfs(mst, edge->getDest(), visited, preorder);
        }
    }
}

void Solver::realWorldTSP(Graph<string>* graph, string startVertex) {
    vector<Vertex<string>*> path;


    if (!isGraphConnected(graph)) {
        cout << "Não existem caminhos que conectem todos os vértices!!!" << endl;
        return;
    }


    Vertex<string>* start = graph->findVertex(startVertex);
    start->setVisited(true);
    path.push_back(start);
    resolveTSP(graph, start, 0, path);


    cout << "Best cost: " << bestCost << endl;
    cout << "Best path: ";
    for (auto i : bestPath){
        cout << i->getInfo() << " ";
    }
    cout << endl;
}

bool Solver::isGraphConnected(Graph<string>* graph) {
    if (graph->getNumVertex() == 0) return true;

    unordered_set<Vertex<string>*> visited;
    queue<Vertex<string>*> q;

    Vertex<string>* start = graph->getVertexSet()[0];  // Pega um vértice qualquer
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        Vertex<string>* v = q.front();
        q.pop();
        for (auto neighbor : v->getAdj()) {
            Vertex<string>* dest = neighbor->getDest();
            if (visited.find(dest) == visited.end()) {
                visited.insert(dest);
                q.push(dest);
            }
        }
    }

    return visited.size() == graph->getNumVertex();
}


void Solver::resolveTSP(Graph<string>* graph, Vertex<string>* current, double cost, vector<Vertex<string>*> &path) {
    if (cost >= bestCost) {
        return;
    }

    if (path.size() == graph->getNumVertex() && current->getInfo() == "0") {
        bestCost = cost;
        bestPath = path;
        return;
    }

    for (auto neighbour: current->getAdj()) {
        Vertex<string> *dest = neighbour->getDest();
        if (dest->isVisited()) continue;

        dest->setVisited(true);
        cost += neighbour->getWeight();
        path.push_back(dest);

        resolveTSP(graph, dest, cost, path);

        dest->setVisited(false);
        cost -= neighbour->getWeight();
        path.pop_back();
    }
}