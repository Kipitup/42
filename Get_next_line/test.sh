gcc -Wall -Werror -Wextra  get_next_line.c main.c Libft/ft_strclr.c Libft/ft_strjoin.c Libft/ft_strlen.c Libft/ft_memmove.c Libft/ft_strdup.c

echo "test simple_line :"
echo ""
./a.out tests/simple_line.txt
echo ""
echo "tests/sample.txt :"
echo ""
./a.out tests/sample.txt
echo ""
echo "tests/gnl7_2.txt :"
echo ""
./a.out tests/gnl7_2.txt
echo ""
