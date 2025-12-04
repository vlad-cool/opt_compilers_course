.PHONY: all run

all: task task_opt

task: task.c 
	/home/vlad/Programs/chibicc/chibicc task.c -lm -o task

task_opt: task_opt.c 
	/home/vlad/Programs/chibicc/chibicc task_opt.c -lm -o task_opt

run: task task_opt
	time ./task 100 1000000
	time ./task_opt 100 1000000
