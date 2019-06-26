CXX=g++-8
FLAGS=-std=c++11 -Wall -Wextra
TARGETS=functions functions_recursive sorts String SLL CSLL DLL CDLL Stack Queue Dequeue

%: source/Functions/functions.test.cpp source/Functions/%.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

sorts: source/Sorts/sorts.test.cpp source/Sorts/sorts.cpp source/Functions/functions.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

String: source/String/String.test.cpp source/String/String.cpp source/Functions/functions.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

%: source/Linear/LinkedList.test.cpp source/Linear/%.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

Stack: source/Linear/Stack.test.cpp source/Linear/Stack.cpp source/Linear/SLL.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

Queue: source/Linear/Queue.test.cpp source/Linear/Queue.cpp source/Linear/DLL.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

Dequeue: source/Linear/Dequeue.test.cpp source/Linear/Dequeue.cpp source/Linear/DLL.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

%: source/Trees/%.test.cpp source/Trees/%.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

all: $(TARGETS) 

.PHONY: clean

clean:
	find . -name "*out" -delete
