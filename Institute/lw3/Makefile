all:
	make build && make test

build:
	g++ -std=c++20 task_24.cpp -o task_24.exe

test:
	bash ./tests/tests_24.sh || (exit 1)
