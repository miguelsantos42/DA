//
// Created by aqueiros_22 on 06-05-2024.
//

#include "Data.h"

Data::Data() {
    graph = new Graph<string>();
}

Graph<string>* Data::getGraph() {
    return graph;
}
void Data::clearGraph() {
    delete graph;
    graph = new Graph<string>();
}

void Data::readToyGraphs(int x) {
    string filename;
    switch(x){
        case 1:
            filename = "../CSV/Toy-Graphs/shipping.csv";
            break;
        case 2:
            filename = "../CSV/Toy-Graphs/stadiums.csv";
            break;
        case 3:
            filename = "../CSV/Toy-Graphs/tourism.csv";
            break;
        default:
            cout << "Invalid option" << endl;
            return;
    }
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            string source;
            string dest;
            string weight;
            getline(ss, source, ',');
            getline(ss, dest, ',');
            getline(ss, weight, ',');
            if (x != 3) {
                graph->addVertex(source);
                graph->addVertex(dest);
                graph->addBidirectionalEdge(source, dest, stoi(weight));
            } else {
                string label_source, label_dest;
                getline(ss, label_source, ',');
                getline(ss, label_dest, ',');
                graph->addVertex(source);
                graph->addVertex(dest);
                graph->addBidirectionalEdge(source, dest, stoi(weight));
            }
        }
        file.close();
    } else {
        cout << "Error opening file" << endl;
    }
}

void Data::readExtra(int x) {
    string filename;
    switch(x){
        case 1:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_25.csv";
            break;
        case 2:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_50.csv";
            break;
        case 3:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_75.csv";
            break;
        case 4:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_100.csv";
            break;
        case 5:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_200.csv";
            break;
        case 6:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_300.csv";
            break;
        case 7:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_400.csv";
            break;
        case 8:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_500.csv";
            break;
        case 9:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_600.csv";
            break;
        case 10:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_700.csv";
            break;
        case 11:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_800.csv";
            break;
        case 12:
            filename = "../CSV/Extra_Fully_Connected_Graphs/edges_900.csv";
            break;
        default:
            cout << "Invalid option" << endl;
            return;
    }
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string source;
            string dest;
            string weight;
            getline(ss, source, ',');
            getline(ss, dest, ',');
            getline(ss, weight, ',');
            graph->addVertex(source);
            graph->addVertex(dest);
            graph->addBidirectionalEdge(source, dest, stod(weight));
        }
        file.close();
    } else {
        cout << "Error opening file" << endl;
    }
}

void Data::readReal(int x) {
    string f_edges;
    string f_nodes;
    switch (x) {
        case 1:
            f_edges = "../CSV/Real-world Graphs/graph1/edges.csv";
            f_nodes = "../CSV/Real-world Graphs/graph1/nodes.csv";
            break;
        case 2:
            f_edges = "../CSV/Real-world Graphs/graph2/edges.csv";
            f_nodes = "../CSV/Real-world Graphs/graph2/nodes.csv";
            break;
        case 3:
            f_edges = "../CSV/Real-world Graphs/graph3/edges.csv";
            f_nodes = "../CSV/Real-world Graphs/graph3/nodes.csv";
            break;
        default:
            cout << "Invalid option" << endl;
            return;
    }
    ifstream file_nodes(f_nodes);
    if (file_nodes.is_open()) {
        string l_nodes;
        getline(file_nodes, l_nodes);
        while (getline(file_nodes, l_nodes)) {
            stringstream ss(l_nodes);
            string id, longitude, latitude;
            getline(ss, id, ',');
            getline(ss, longitude, ',');
            getline(ss, latitude, ',');
            graph->addVertex(id, stod(latitude), stod(longitude));
        }
        file_nodes.close();
    } else {
        cout << "Error opening file" << endl;
    }
    ifstream file_edges(f_edges);
    if (file_edges.is_open()) {
        string l_edges;
        getline(file_edges, l_edges);
        while (getline(file_edges, l_edges)) {
            stringstream ss(l_edges);
            string source, dest, weight;
            getline(ss, source, ',');
            getline(ss, dest, ',');
            getline(ss, weight, ',');
            graph->addBidirectionalEdge(source, dest, stod(weight));
        }
        file_edges.close();
    } else {
        cout << "Error opening file" << endl;
    }

}

