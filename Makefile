CXX=g++-8
FLAGS=-std=c++11 -Wall -Wextra
TARGETS=functions functions_recursive sorts string SLL CSLL DLL CDLL Stack

%: source/Functions/functions.test.cpp source/Functions/%.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

sorts: source/Sorts/sorts.test.cpp source/Sorts/sorts.cpp source/Functions/functions.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

string: source/String/string.test.cpp source/String/string.cpp source/Functions/functions.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

%: source/Linear/LinkedList.test.cpp source/Linear/%.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

Stack: source/Linear/Stack.test.cpp source/Linear/Stack.cpp # source/Linear/SLL.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

all: $(TARGETS) 

.PHONY: clean

clean:
	find . -name "*out" -delete