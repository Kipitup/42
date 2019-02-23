gcc -Wall -Werror -Wextra  get_next_line.c main.c Libft/libft.a

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

#gcc -Wall -Werror -Wextra -fsanitize=address,undefined -g3 get_next_line.c main.c Libft/libft.a
