CXX = g++
CXXFLAGS = -Wall --pedantic \
	# -DDEBUG
OBJS = compito.o liste.o tipo.o
EXEC = compito

-include dependencies.txt

build: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

.PHONY: clean cleanall gendep run
clean:
	rm -rf $(OBJS)

cleanall:
	rm -rf $(OBJS) $(EXEC) dependencies.txt

gendep:
	$(CXX) -MM *.cpp > dependencies.txt

run:
	./$(EXEC)