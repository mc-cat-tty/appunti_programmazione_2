CXX = g++
CXXFLAGS = -Wall -pedantic
EXEC = queue
OBJ = main.o queue.o

-include dependencies.txt

build: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

.PHONY: run clean cleanall gendep
run:
	./$(EXEC)

clean:
	rm -f $(OBJ)

cleanall:
	rm -f $(OBJ) $(EXEC) dependencies.txt

gendep:
	$(CXX) -MM *.cpp > dependencies.txt
 