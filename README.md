# 42-get_next_line

##Tests commands

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c tester.c -o test_gnl
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c tester.c -o test_gnl_1
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c tester.c -o test_gnl_42
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 get_next_line.c get_next_line_utils.c tester.c -o test_gnl_10m
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c tester_bonus.c -o test_gnl_bonus
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line_bonus.c get_next_line_utils_bonus.c tester_bonus.c -o test_gnl_bonus_1
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c tester_bonus.c -o test_gnl_bonus_42
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 get_next_line_bonus.c get_next_line_utils_bonus.c tester_bonus.c -o test_gnl_bonus_10m
```
