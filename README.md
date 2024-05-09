# get_next_lie
 Reading a line from a fd, return it.
 
![get_next_line](https://github.com/leebo155/get_next_line/assets/81127600/e61c2c00-048e-4a27-8710-8501e7b318b5)

## Introduction
 * This project make me learn a highly interesting new concept in C programming: static variables.
 * Repeated calls to get_next_line read the text file that the file descriptor points to, one line at a time.
 * Return the line that was read. If there is nothing else to read or if an error occurred, it return null ptr.

## Makefile
| Rules | Description |
| ----- | ----------- |
| all | Compile a library libgnl.a. |
| clean | Remove all the temporary generated files. |
| fclean | Remove all the generated files. |
| re | Remove all the generated files and compile a libgnl.a |
