#!/bin/bash

PROGRAM="../task_26.cpp"
PROGRAM_OUTPUT="test_output.txt"

INPUT_1="input_1.txt"
OUTPUT_1="output_1.txt"

INPUT_2="input_2.txt"
OUTPUT_2="output_2.txt"

INPUT_3="input_3.txt"
OUTPUT_3="output_3.txt"

g++ $PROGRAM -o task_26.exe -std=c++17


./task_26.exe $INPUT_1 $PROGRAM_OUTPUT;
if cmp -s "$PROGRAM_OUTPUT" "$OUTPUT_1"; then
    echo "Test 1 passed"
else
    echo "Test 1 failed"
    exit 1
fi

./task_26.exe $INPUT_2 $PROGRAM_OUTPUT;
if cmp -s "$PROGRAM_OUTPUT" "$OUTPUT_2"; then
    echo "Test 2 passed"
else
    echo "Test 2 failed"
    exit 1
fi

./task_26.exe $INPUT_3 $PROGRAM_OUTPUT;
if cmp -s "$PROGRAM_OUTPUT" "$OUTPUT_3"; then
    echo "Test 3 passed"
else
    echo "Test 3 failed"
    exit 1
fi

echo "All tests passed"
exit 0
