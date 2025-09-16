all: task_1

tmp:
	mkdir tmp

bin:
	mkdir bin

task_1: bin tmp bin/task_1 bin/solution_1
	./bin/task_1 <<< 23 > tmp/task_1
	./bin/solution_1 <<< 23 > tmp/solution_1
	diff tmp/task_1 tmp/solution_1

bin/task_1: task_1.cpp
	g++ task_1.cpp -o bin/task_1

bin/solution_1: solution_1.cpp
	g++ solution_1.cpp -o bin/solution_1
