# get_next_line
main.c / digit6 /str4lines3 is for the test

test commands:

make -C libft/ fclean && make -C libft/ 

gcc -Wall -Wextra -Werror -o get_next_line.o -c get_next_line.c

gcc -Wall -Wextra -Werror -o main.o -c main.c

gcc -o test_gnl main.o get_next_line.o -L libft/ -lft

./test_gnl digit6 str4lines3

The files in "submit" folder have been modified for norm.
