all:
	make build && make test

build:
	g++ -std=c++20 CMatrixManager.cpp task_21.cpp -o task_21.exe

test:
	bash ./tests/tests_21.sh || (exit 1)