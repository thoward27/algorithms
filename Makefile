CXX=g++-8
FLAGS=-std=c++11 -Wall -Wextra -fsanitize=address,leak

files = $(basename $(notdir $(filter-out $(wildcard source/**/*.test.cpp), $(wildcard source/$(1)/*.cpp))))
SORTS=$(call files,Sorts)
LISTS=$(call files,LinkedList)
TREES=$(call files,Trees)

ALGORITHMS=$(basename $(notdir $(wildcard source/Algorithms/*.cpp)))

TARGETS=$(call files,*) $(ALGORITHMS)

# Object Files
%.o: source/*/%.cpp
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

all: $(TARGETS)

.PHONY: clean
clean:
	find . -name "*out" -delete
	find . -name "*.o" -delete