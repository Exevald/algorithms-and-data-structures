all:
	make build && make test

build:
	g++ -std=c++20 task_28.cpp -o task_28.exe

test:
	bash ./tests/tests_28.sh || (exit 1)
