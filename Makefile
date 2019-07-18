CXX=g++
FLAGS=-std=c++11 -Wall -Wextra -fsanitize=address

files = $(basename $(notdir $(filter-out $(wildcard source/**/*.test.cpp), $(wildcard source/$(1)/*.cpp))))
SORTS=$(call files,Sorts)
LISTS=$(call files,LinkedList)
TREES=$(call files,Trees)

ALGORITHMS=$(basename $(notdir $(wildcard source/Algorithms/*.cpp)))

TARGETS=$(call files,*) $(ALGORITHMS)

# Object Files
%.o: source/*/%.cpp
<<<<<<< HEAD
	$(CXX) -c $(if $(RECURSIVE),-DRECURSIVE=$(RECURSIVE)) $(FLAGS) $^

# Tests
functions: source/Functions/functions.test.cpp functions.o
	$(CXX) $(FLAGS) $^
	./a.out

$(SORTS): source/Sorts/sort.test.cpp functions.o BST.o MinHeap.o
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

%: source/*/%.test.cpp %.o functions.o Stack.o Queue.o $(if $(LIST),$(LIST).o,SLL.o) String.o
	$(CXX) $(FLAGS) $^
	./a.out

lexographic: source/Algorithms/lexographic.test.cpp String.o functions.o Trie.o
	$(CXX) $(FLAGS) $^
	./a.out

%: source/Algorithms/%.test.cpp functions.o Stack.o Queue.o String.o $(if $(LIST),$(LIST).o,SLL.o)
	$(CXX) $(FLAGS) $^
	./a.out
=======
	$(CXX) $(FLAGS) $(if $(RECURSIVE),-DRECURSIVE=$(RECURSIVE)) -c $^

# Dependencies
Graph: Graph.test.o
Hashtable: Hashtable.test.o String.o functions.o
Stack: Stack.test.o SLL.o
Queue: Queue.test.o SLL.o
Dequeue: Dequeue.test.o DLL.o
functions: functions.test.o
String: String.test.o functions.o

# Algorithm Dependencies
twostack.test: twostack.test.o Stack.o SLL.o String.o functions.o
lexicographic.test: lexicographic.test.o Trie.o String.o functions.o

# Complex Depedencies
.SECONDEXPANSION:
$(LISTS): LinkedList.test.o $$@.o
$(TREES): $$@.test.o $$@.o String.o functions.o
$(SORTS): sort.test.o $$@.o functions.o BST.o RBTree.o MinHeap.o

# Generic execution rule.
%: $$@.o
	$(CXX) $(FLAGS) $^ && ./a.out

# Algorithms execution rule.
$(ALGORITHMS): $$@.o 
	$(CXX) $(FLAGS) $^ && ./a.out
>>>>>>> upstream/master

Hashtable: source/Hashing/Hashtable.test.cpp source/Hashing/Hashtable.cpp source/Hashing/SLL.cpp String.o functions.o
	$(CXX) $(FLAGS) $^
	./a.out

all: $(TARGETS)

.PHONY: clean
clean:
	find . -name "*out" -delete
	find . -name "*.o" -delete