#!/bin/bash

for file in *.c
do
  gcc -Wall -Werror -Wextra -pedantic -c "$file" -o "${file%.c}.o"
done
ar rcs liball.a *.o
ranlib liball.a
