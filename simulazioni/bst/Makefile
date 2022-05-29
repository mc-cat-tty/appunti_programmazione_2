EXEC = compito
OBJ = compito.o bst.o carta.o
CXXFLAGS = -Wall --pedantic \
	# -DDEBUG
CXX = g++

-include dependencies.txt

build: $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

.PHONY: clean cleanall gendep gendoc run
clean:
	rm -f $(OBJ)
cleanall:
	rm -f $(OBJ) dependencies.txt docs/* $(EXEC)
gendep:
	$(CXX) -MM *.cpp > dependencies.txt

gendoc:
	doxygen

run:
	./$(EXEC)