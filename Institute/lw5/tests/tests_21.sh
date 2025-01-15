#!/usr/bin/env bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

writeTestSuccess() {
  echo "Test passed"
}

writeTestError() {
    echo -e "${RED}Test failed${NC}"
    exit
}

# TEST 1: Invalid argument count
./task_21.exe
if [ $? -eq 1 ]
then
  writeTestSuccess
else
  writeTestError
fi

# TEST 2: Matrix size is not equal with number
./task_21.exe ./tests/invalidMatrixSizeInput.txt ./tests/output.txt
if [ $? -eq 1 ]
then
  writeTestSuccess
else
  writeTestError
fi

# TEST 3: Matrix size is not equal with number
./task_21.exe ./tests/invalidPlatformSizeInput.txt ./tests/output.txt
if [ $? -eq 1 ]
then
  writeTestSuccess
else
  writeTestError
fi

# TEST 4: Find shortest path
./task_21.exe ./tests/input.txt ./tests/output.txt
if [ $? ]
then
  writeTestSuccess
  if diff -q ./tests/output.txt ./tests/validOutputFile.txt
  then
    writeTestSuccess
  else
    writeTestError
  fi
else
  writeTestError
fi

echo -e "${GREEN}All tests passed${NC}"