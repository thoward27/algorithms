CXX=g++-8
FLAGS=-std=c++11 -Wall -Wextra
SOURCES=functions functions_recursive sorts string SLL

%: source/Functions/functions.test.cpp source/Functions/%.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

sorts: source/Sorts/sorts.test.cpp source/Sorts/sorts.cpp source/Functions/functions.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

string: source/String/string.test.cpp source/String/string.cpp source/Functions/functions.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

%: source/Linear/%.test.cpp source/Linear/%.cpp
	$(CXX) $(FLAGS) $^ && ./a.out

all: functions functions_recursive sorts string

.PHONY: clean

clean:
	find . -name "*out" -delete