#!/bin/bash

# Change to the directory
cd "c:\Users\Night\OneDrive\Documents\ml in C\"

# Compile the C source file
gcc neunet.c -o neunet

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled program
    ./neunet
else
    echo "Compilation failed. Please check for errors."
fi
