EXEC = testa_modulo
CXXFLAGS = -Wall -g -DDEBUG
OBJ = main.o type.o tree.o

-include dependencies.txt

build: $(OBJ)
	g++ -o $(EXEC) $(OBJ)

run:
	./$(EXEC)

.PHONY: clean cleanall gendep
clean:
	rm -f *.o dependencies.txt

cleanall:
	rm -f *.o dependencies.txt $(EXEC)

gendep:
	g++ -MM main.cpp > dependencies.txt
