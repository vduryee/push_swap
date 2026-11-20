_This project has been created as part of the 42 curriculum by vduryee._

# Libft

## Description

Libft is the first project of the 42 common core. The goal is to build a personal C library (`libft.a`) that reimplements a set of standard libc functions and adds extra utility functions

The library is split into four groups:

**Part 1 - libc functions**

|Category|Functions|
|---|---|
|Character checks|`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`|
|Character conversion|`ft_toupper`, `ft_tolower`|
|Strings|`ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`|
|Memory|`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`|
|Conversion|`ft_atoi`|

**Part 2 - additional functions**

|Category|Functions|
|---|---|
|Strings|`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`|
|Conversion|`ft_itoa`|
|Output|`ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`|

**Part 3 - linked lists**

Built on the `t_list` structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

|Category|Functions|
|---|---|
|Creation|`ft_lstnew`|
|Adding|`ft_lstadd_front`, `ft_lstadd_back`|
|Inspecting|`ft_lstsize`, `ft_lstlast`|
|Removing|`ft_lstdelone`, `ft_lstclear`|
|Iterating|`ft_lstiter`, `ft_lstmap`|

## Instructions

### Compilation

All files are compiled with `cc -Wall -Wextra -Werror`.

```
make          # builds libft.a
make clean    # removes the object files
make fclean   # removes the object files and libft.a
make re       # fclean, then all
```

### Usage

Include the header in your code:

```c
#include "libft.h"
```

Then compile your program and link it against the library:

```
cc -Wall -Wextra -Werror main.c -lft -o my_program
```

### Example

```c
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = ft_itoa(-42);
	printf("%s\n", str);
	free(str);
	return (0);
}
```

## Resources

- `man` pages for each reimplemented libc function (`man 3 strlen`, `man 3 calloc`, ...)
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language), Kernighan and Ritchie
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The 42 Norm, checked with `norminette`
- [W3Schools - C Tutorial](https://www.w3schools.com/c/)
- [GeeksforGeeks - C Programming Language](https://www.geeksforgeeks.org/c/c-programming-language/)
- [C For Dummies](https://c-for-dummies.com/)
- [Stack Overflow - questions tagged C](https://stackoverflow.com/questions/tagged/c)

### Use of AI

AI was used as a learning and review aid during this project: to explain concepts such as linked lists and pointer behavior, to point out bugs and edge cases in my own code (for example the `INT_MIN` and zero cases in `ft_itoa`, and the empty-list case in `ft_lstadd_back`), and to help format the Makefile and the Readme to meet the Norm. All code was written, reviewed and tested by me.