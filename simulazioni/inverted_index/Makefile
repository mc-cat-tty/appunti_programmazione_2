EXEC = inverted_index
OBJ = compito.o liste.o tipo.o

-include dependencies.txt

build: $(OBJ)
	g++ $(OBJ) -o $(EXEC) 

.PHONY: clean cleanall gendep gendoc run
clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXEC) dependencies.txt
	rm -rf docs/

gendep:
	g++ -MM *.cpp > dependencies.txt

gendoc:
	doxygen

run: $(EXEC)
	./$(EXEC)