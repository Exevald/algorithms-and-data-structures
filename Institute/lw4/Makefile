all:
	make build && make test

build:
	g++ -std=c++20 CGraph.cpp task_25.cpp -o task_25.exe

test:
	bash ./tests/tests_25.sh || (exit 1)