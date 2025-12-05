#!/bin/bash

# Check for correct number of arguments
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <day.part> <input_filename>"
    echo "Example: $0 1.1 input.txt"
    exit 1
fi

# Parse day and part from the first argument
DAY_PART=$1
DAY=$(echo $DAY_PART | cut -d. -f1)
PART=$(echo $DAY_PART | cut -d. -f2)

# Format day with leading zero if needed
FORMATTED_DAY=$(printf "%02d" $DAY)

# Construct the target name and paths
TARGET="day${FORMATTED_DAY}_part${PART}"
DAY_DIR="day${FORMATTED_DAY}"
EXECUTABLE="build/${TARGET}"
INPUT_FILE="${DAY_DIR}/${2}"

# Check if the input file exists
if [ ! -f "$INPUT_FILE" ]; then
    echo "Error: Input file not found at ${INPUT_FILE}"
    exit 1
fi

# Build the specified target
echo "Building target: ${TARGET}"
cmake --build build --target ${TARGET}

# Check if build was successful
if [ $? -ne 0 ]; then
    echo "Error: Build failed for target ${TARGET}"
    exit 1
fi

# Run the executable with the specified input
echo "Running ${EXECUTABLE} with input ${INPUT_FILE}"
${EXECUTABLE} ${INPUT_FILE}
