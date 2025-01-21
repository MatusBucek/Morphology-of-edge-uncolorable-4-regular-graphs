#include <iostream>
#include "../../ba-graph-master/test/invariants/implementation.h"
#include <invariants/colouring.hpp>
#include <graphs.hpp>
#include "sat.hpp"

using namespace ba_graph;

Configuration cfg;

void loadConfig()
{
	try {
		cfg.load_from_file("ba_graph.cfg");
	} catch(...) {
        cfg.load_from_string(R"delim({
            "storage": {
                "dir": "/home/vyskum_data"
            },
            "sat_solvers": [
                {
                    "output_type": "SAT_COMPETITION",
                    "execute_command": "/home/matus1503/Documents/RP/ba-graph/ba-graph-projects-main/is4edgecolourable/seqfrost"
                }
            ],
           
            "runtime_settings": {
                "tmp_dir": "/tmp",
                "num_threads": "1"
            }
        })delim");
	}
}

void processGraph(std::string &graphString, Graph &G, Factory &f, std::string *graphFile){
    SatSolver solver(cfg, 0);
    std::string outputFileYes = *graphFile + ".is4ecsat.YES";
    std::string outputFileNo = *graphFile + ".is4ecsat.NO";
    std::ofstream outFileYes;
    std::ofstream outFileNo;
    outFileYes.open(outputFileYes, std::ios_base::app);
    outFileNo.open(outputFileNo, std::ios_base::app);
    if (is_edge_colourable_sat(solver, G, 4)){
	  outFileYes << graphString << std::endl;
    } else {
        outFileNo << graphString << std::endl;
    }
}

int main(int argc, char *argv[]){
    loadConfig();

    if (argc < 2) {
		std::cout << "is4edgecolourablesat <graph file>" << std::endl;
		exit(1);
	}
	std::string graphFile = argv[1];

    read_graph6_file<std::string>(graphFile, processGraph, &graphFile, NULL);

    return 0;
}
