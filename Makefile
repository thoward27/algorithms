CXX=g++-8
FLAGS=-std=c++11 -Wall -Wextra
TARGETS=functions functions_recursive sorts String SLL CSLL DLL CDLL Stack Queue Dequeue BST

%: source/Functions/functions.test.cpp source/Functions/%.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

sorts: source/Sorts/sorts.test.cpp source/Sorts/sorts.cpp source/Functions/functions.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

String: source/String/String.test.cpp source/String/String.cpp source/Functions/functions.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

%: source/LinkedList/LinkedList.test.cpp source/LinkedList/%.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

Stack: source/Stack/Stack.test.cpp source/Stack/Stack.cpp source/LinkedList/SLL.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

Queue: source/Queue/Queue.test.cpp source/Queue/Queue.cpp source/LinkedList/SLL.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

Dequeue: source/Queue/Dequeue.test.cpp source/Queue/Dequeue.cpp source/LinkedList/DLL.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

%: source/Trees/%.test.cpp source/Trees/%.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

all: $(TARGETS) 

.PHONY: clean

clean:
	find . -name "*out" -delete
