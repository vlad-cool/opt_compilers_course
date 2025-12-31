.PHONY: all run

all: task task_opt task_cfg

task: task.c 
	/home/vlad/Programs/chibicc/chibicc task.c -lm -o task

task_cfg: task_cfg.c 
	/home/vlad/Programs/chibicc/chibicc task_cfg.c -lm -o task_cfg

task_opt: task_opt.c 
	/home/vlad/Programs/chibicc/chibicc task_opt.c -lm -o task_opt

run: task task_cfg task_opt
	time ./task     100 10 20 30
	time ./task_cfg 100 10 20 30
	time ./task_opt 100 10 20 30
