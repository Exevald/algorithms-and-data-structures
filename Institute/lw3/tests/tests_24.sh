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
./task_24.exe
if [ $? -eq 1 ]
then
  writeTestSuccess
else
  writeTestError
fi

# TEST 2: Invalid filename
./task_24.exe ./tests/invalidFileName.txt ./tests/invalidFileName.txt
if [ $? -eq 1 ]
then
  rm ./tests/invalidFileName.txt
  writeTestSuccess
else
  rm ./tests/invalidFileName.txt
  writeTestError
fi

# TEST 3: Invalid filename
./task_24.exe ./tests/invalidInputFile.txt ./tests/output.txt
if [ $? -eq 1 ]
then
  writeTestSuccess
else
  writeTestError
fi

# TEST 4: Trim and print valid tree
./task_24.exe ./tests/input.txt ./tests/output.txt
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