CXX=g++-8
FLAGS=-std=c++11 -Wall -Wextra

SORTS=bubble insertion selection merge quick tree hybrid
LISTS=SLL CSLL DLL CDLL
TREES=BST RBTree Trie
ALGORITHMS=twostack

TARGETS=functions $(SORTS) String $(LISTS) Stack Queue Dequeue $(TREES) $(ALGORITHMS)

# Object Files
%.o: source/*/%.cpp
	$(CXX) -c $(if $(RECURSIVE),-DRECURSIVE=$(RECURSIVE)) $(FLAGS) $^

# Tests
functions: source/Functions/functions.test.cpp functions.o
	$(CXX) $(FLAGS) $^
	./a.out

$(SORTS): source/Sorts/sort.test.cpp functions.o BST.o RBTree.o
	$(CXX) $(FLAGS) $^ source/Sorts/$@.cpp
	./a.out

String: source/String/String.test.cpp String.o functions.o
	$(CXX) $(FLAGS) $^
	./a.out

$(LISTS): source/LinkedList/LinkedList.test.cpp 
	$(CXX) $(FLAGS) $^ source/LinkedList/$@.cpp && ./a.out

Queue: source/Queue/Queue.test.cpp Queue.o $(if $(LIST),$(LIST).o,SLL.o)
	$(CXX) $(FLAGS) $^
	./a.out

Stack: source/Stack/Stack.test.cpp Stack.o $(if $(LIST),$(LIST).o,SLL.o)
	$(CXX) $(FLAGS) $^
	./a.out

Dequeue: source/Queue/Dequeue.test.cpp Dequeue.o $(if $(LIST),$(LIST).o,DLL.o)
	$(CXX) $(FLAGS) $^
	./a.out

calculator: calculator.cpp Stack.o SLL.o String.o functions.o
	$(CXX) $(FLAGS) $^
	./a.out

%: source/*/%.test.cpp %.o functions.o Stack.o Queue.o $(if $(LIST),$(LIST).o,SLL.o)
	$(CXX) $(FLAGS) $^
	./a.out

%: source/Algorithms/%.test.cpp functions.o Stack.o Queue.o String.o $(if $(LIST),$(LIST).o,SLL.o)
	$(CXX) $(FLAGS) $^
	./a.out

all: $(TARGETS)

.PHONY: clean

clean:
	find . -name "*out" -delete
	find . -name "*.o" -delete
