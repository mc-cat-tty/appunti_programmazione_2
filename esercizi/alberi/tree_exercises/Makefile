CXX = g++
CXXFLAGS = -Wall -g -DDEBUG
EXEC = esercizi_alberi
OBJ = main.o tree_module/type.o tree_module/tree.o queue/queue.o

-include dependencies.txt

build: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

.PHONY: run clean cleanall gendep
run:
	./$(EXEC)

clean:
	rm -f $(OBJ) dependencies.txt

cleanall:
	rm -f $(OBJ) $(EXEC) dependencies.txt

gendep:
	$(CXX) -MM main.cpp > dependencies.txt
