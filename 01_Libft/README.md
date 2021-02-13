# ```libft```
*a 19 Coding School project*

The aim of this project is to code a C library regrouping essential functions used in C.  
This library will be used in other projects and will therefore be regularly updated.

## How to use it

In order to create the library, simply execute:
```bash
make
```

To remove the ```.o``` files, execute:
```bash
make clean
``` 

To remove the ```.o``` files, execute:
```bash
make clean
```

To use library with a ```main.c``` file, simply execute:
```bash
gcc main.c -L . -lft
```

## What I learned

This project allows to get familiar with some of the most foundational functions in C.

## Content of the Libft
*v1.00 - Last updated with libft project*

### ctype
- ft_isalnum
- ft_isalpha
- ft_isascii
- ft_isdigit
- ft_isprint
- ft_tolower
- ft_toupper

### String
- ft_atol
- ft_ltoa
- ft_split
- ft_strchr
- ft_strdup
- ft_strjoin
- ft_strlcat
- ft_strlcpy
- ft_strlen
- ft_strmapi
- ft_strncmp
- ft_strnstr
- ft_strrchr
- ft_strtrim
- ft_substr

### Stdio
- ft_putendl_fd
- ft_putchar_fd
- ft_putnbr_fd
- ft_putstr_fd
### Memory
- ft_bzero
- ft_memccpy
- ft_memchr
- ft_memcmp
- ft_memcpy
- ft_memset
- ft_calloc
### Linked List
- ft_lstadd_back
- ft_lstadd_front
- ft_lstclear
- ft_lstdelone
- ft_lstiter
- ft_lstlast
- ft_lstmap
- ft_lstnew
- ft_lstsize

## Acknowledgements

[Ooming](https://github.com/oomsveta)  
[Matthew Dreemurr](https://github.com/Matthew-Dreemurr)

## License
Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
