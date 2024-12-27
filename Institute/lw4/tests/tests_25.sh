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
./task_25.exe
if [ $? -eq 1 ]
then
  writeTestSuccess
else
  writeTestError
fi

# TEST 2: Find physical effect
./task_25.exe  ./tests/physicalQuantitiesInput.txt ./tests/physicalEffectsInput.txt 2 1 ./tests/output.txt
if [ $? ]
then
  writeTestSuccess
else
  writeTestError
fi

echo -e "${GREEN}All tests passed${NC}"