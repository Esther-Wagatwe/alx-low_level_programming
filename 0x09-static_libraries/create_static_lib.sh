#bin/bash
gcc -Wall -pedantic -Werror -Wextra *.c
ar -rc liball.a *.c
ranlib liball.a
