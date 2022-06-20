CXX = g++
CXXFLAGS = -std=c++2a -Wall --pedantic \
	# -DDEBUG
OBJS = tipo.o liste.o grafo.o compito.o
EXEC = compito

-include dependencies.txt

build: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

.PHONY: clean cleanall gendep gendoc run
clean:
	rm -rf $(OBJS)
cleanall:
	rm -rf $(OBJS) $(EXEC) dependencies.txt doc/
gendep:
	$(CXX) -MM *.cpp > dependencies.txt
gendoc:
	doxygen
run:
	./$(EXEC)