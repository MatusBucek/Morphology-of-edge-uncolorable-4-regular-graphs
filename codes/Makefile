CFLAGS = -std=c++20 -fopenmp -I../../ba-graph-master/include
LDFLAGS = -lstdc++fs
DBGFLAGS = -g -O0 -pedantic -Wall -Wextra -DBA_GRAPH_DEBUG -D_GLIBCXX_DEBUG
COMPILE_DBG = $(CXX) $(CFLAGS) $(DBGFLAGS)
COMPILE = $(CXX) $(CFLAGS) -DNDEBUG -O3

all: is4edgecolourablesat is4edgecolourablebt


is4edgecolourablesat: is4edgecolourablesat.cpp
	$(COMPILE) is4edgecolourablesat.cpp -o is4edgecolourablesat $(LDFLAGS)
	
is4edgecolourablebt: is4edgecolourablebt.cpp
	$(COMPILE) is4edgecolourablebt.cpp -o is4edgecolourablebt $(LDFLAGS)	


clean:
	rm -rf is4edgecolourablesat is4edgecolourablebt


.PHONY: clean all
