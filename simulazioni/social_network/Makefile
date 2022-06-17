CXX = g++
CXXFLAGS = -Wall --pedantic \
	-DDEBUG
OBJS = compito.o grafi.o coda.o
EXEC = compito  # executable name

-include dependencies.txt

build: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

.PHONY: run
run:
	./$(EXEC)
clean:
	rm -rf $(OBJS)
cleanall:
	rm -rf $(OBJS) $(EXEC) docs/
gendep:
	$(CXX) -MM *.cpp > dependencies.txt
gendoc:
	doxygen
