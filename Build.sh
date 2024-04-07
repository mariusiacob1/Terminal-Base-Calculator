#!/bin/bash

# Compile each source file separately
for filename in *.cpp; do
  # Extract filename without extension
  basefilename=$(basename -- "$filename")
  filename_no_extension="${basefilename%.*}"

  # Compile the specified C++ file
  echo "**Compile $filename**"
  if ! clang++ -std=c++17 -arch arm64 -c "$filename" -o "${filename_no_extension}.o"; then
    echo "Compilation failed."
    exit 1
  fi

  # Collect object files
  object_files+=("${filename_no_extension}.o")
done

# Link object files
echo "**Link object files**"
if ! clang++ -arch arm64 "${object_files[@]}" -o output; then
  echo "Linking failed."
  exit 1
fi

# Run the program
echo "**Running Program**"
echo " "
./output
echo " "

# Cleanup - Delete unneeded files
rm -f *.o output

# Letting the user know that the script has ended
echo "**SCRIPT TERMINATED**"
