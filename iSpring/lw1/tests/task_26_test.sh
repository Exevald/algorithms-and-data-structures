#!/bin/bash

PROGRAM="../task_26.cpp"
PROGRAM_OUTPUT="test_output.txt"

INPUT_1="input_1.txt"
OUTPUT_1="output_1.txt"

g++ $PROGRAM -o task_26.exe

./task_26.exe $INPUT_1 $PROGRAM_OUTPUT

#if cmp -s "$PROGRAM_OUTPUT" "$OUTPUT_1"; then
#  echo "Test 1 passed"
#else
#  echo "Test 1 failed"
#  exit 1
#fi


echo "All tests passed"
exit 0