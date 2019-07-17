CXX=g++-8
FLAGS=-std=c++11 -Wall -Wextra -fsanitize=address,leak

SORTS=bubble insertion selection merge quick tree hybrid heap
LISTS=SLL CSLL DLL CDLL
TREES=BST RBTree Trie MinHeap
ALGORITHMS=twostack

TARGETS=functions $(SORTS) String $(LISTS) Stack Queue Dequeue $(TREES) $(ALGORITHMS) Hashtable

# Object Files
%.o: source/*/%.cpp
	$(CXX) $(FLAGS) $(if $(RECURSIVE),-DRECURSIVE=$(RECURSIVE)) -c $^

# Dependencies
Hashtable: Hashtable.test.o String.o functions.o
Stack: Stack.test.o SLL.o
Queue: Queue.test.o SLL.o
Dequeue: Dequeue.test.o DLL.o
functions: functions.test.o
String: String.test.o functions.o
twostack: twostack.test.o Stack.o SLL.o String.o functions.o

# Complex Depedencies
.SECONDEXPANSION:
$(LISTS): LinkedList.test.o $$@.o
$(TREES): $$@.test.o $$@.o String.o functions.o
$(SORTS): sort.test.o $$@.o functions.o BST.o RBTree.o MinHeap.o

# Generic execution rule.
%: $$@.o
	$(CXX) $(FLAGS) $^ && ./a.out

all: $(TARGETS)

.PHONY: clean
clean:
	find . -name "*out" -delete
	find . -name "*.o" -delete
