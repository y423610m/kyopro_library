#!/bin/bash

TEST_DIR="test"
PIXI_G="pixi run g"

PASSED=0
FAILED=0

for test_file in $(find "$TEST_DIR" -name "*.cpp" | sort); do
    test_dir=$(dirname "$test_file")
    name=$(basename "$test_file" .cpp)
    
    echo -n "Testing $name... "
    (cd "$test_dir" && $PIXI_G "$name.cpp" >/dev/null 2>&1 && ./a.out >/dev/null 2>&1)
    if [ $? -eq 0 ]; then
        echo "PASSED"
        PASSED=$((PASSED + 1))
    else
        echo "FAILED"
        FAILED=$((FAILED + 1))
    fi
done

echo ""
echo "Results: $PASSED passed, $FAILED failed"
exit $FAILED