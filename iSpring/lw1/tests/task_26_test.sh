#!/bin/bash

PROGRAM="../task_26.cpp"
PROGRAM_OUTPUT="task_26_output.txt"

INPUT_1="input_1.txt"
OUTPUT_1="output_1.txt"

g++ $PROGRAM -o $PROGRAM_OUTPUT

if cmp -s "$PROGRAM_OUTPUT" "$OUTPUT_1"; then
  echo "Test 1 passed"
else
  echo "Test 1 failed"
fi