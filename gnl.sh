#!bin/bash
CC="-fsanitize=address -Wall -Wextra -Werror -g -D"
C_FILES="get_next_line.c get_next_line_utils.c"
BONUS_C_FILES="get_next_line_bonus.c get_next_line_utils_bonus.c"
size=(1 2 6 7 8 1023 1024 1025 9999 10000 10001)

for i in "${size[@]}";
do
	echo BUFFERSIZE=$i
	gcc $CC BUFFERSIZE=$i main.c $C_FILES -o gnl_lldb;
	./gnl_lldb;
	gcc $CC BUFFERSIZE=$i -D BONUS=1 main.c $BONUS_C_FILES -o gnl_lldb;
	./gnl_lldb;
done
