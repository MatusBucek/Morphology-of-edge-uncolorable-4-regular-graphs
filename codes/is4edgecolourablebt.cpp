#include <iostream>

#include "../../ba-graph-master/test/invariants/implementation.h"
#include <invariants/colouring.hpp>
#include <graphs.hpp>


using namespace ba_graph;

Configuration cfg;

void processGraph(std::string &graphString, Graph &G, Factory &f, std::string *graphFile){
    std::string outputFileYes = *graphFile + ".is4ecbt.YES";
    std::string outputFileNo = *graphFile + ".is4ecbt.NO";
    std::ofstream outFileYes;
    std::ofstream outFileNo;
    outFileYes.open(outputFileYes, std::ios_base::app);
    outFileNo.open(outputFileNo, std::ios_base::app);
    if (is_edge_colourable_basic(G, 4)){
	outFileYes << graphString << std::endl;
    } else {
        outFileNo << graphString << std::endl;
    }
}

int main(int argc, char *argv[]){
    if (argc < 2) {
		std::cout << "is4edgecolourablebt <graph file>" << std::endl;
		exit(1);
	}
	std::string graphFile = argv[1];

    read_graph6_file<std::string>(graphFile, processGraph, &graphFile, NULL);

    return 0;
}
