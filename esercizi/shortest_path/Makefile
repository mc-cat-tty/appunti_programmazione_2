CXX = g++
CXXFLAGS = -std=c++20 -Wall --pedantic
EXEC = graph
OBJ = graph.o main.o priority_queue.o shortest_path.o

build: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

-include depedencies.txt

.PHONY: clean cleanall gendep gendoc
clean:
	rm -rf $(OBJ)

cleanall:
	rm -rf $(OBJ) $(EXEC) docs/ depedencies.txt

gendep:
	$(CXX) -MM *.cpp > depedencies.txt

gendoc:
	doxygen