# 42cursus
*19 Coding School's projects [@19network42](https://github.com/19network42)*

This repository contains all the code I have written so far for school 19's projects.  
19 is a computer programming school based in Belgium and part of the 42 network.

Learn more about 19 [here](https://s19.be).  
Learn more about 42 [here](https://www.42.fr/42-network/).

![tderwedu's 42 stats](https://badge42.herokuapp.com/api/stats/tderwedu?privacyEmail=true)

## Projects

| #  | Name | Topics |
| -- | ---- | ------ |
| 1  | [Libft](https://github.com/tderwedu/42cursus/tree/main/01_Libft) | `C` |
| 2  | [Get Next Line](https://github.com/tderwedu/42cursus/tree/main/02_getNextLine) | `C` |
| 3  | [ft_printf](https://github.com/tderwedu/42cursus/tree/main/03_Printf) | `C` Floating Points IEEE-754 Std |
| 4  | [Netwhat](https://github.com/tderwedu/42cursus/tree/main/04_netwhat) | Networks, TCP/IP, IP addresses, OSI MOdel, ...  |
| 5  | [cub3D](https://github.com/tderwedu/42cursus/tree/main/05_Cub3D) | `C` Raycasting |
| 6  | [ft_server](https://github.com/tderwedu/42cursus/tree/main/06_ft_server) | Docker, NGINX, WordPress, MySQL |
| 7  | [Push Swap](https://github.com/tderwedu/42cursus/tree/main/07_Push_Swap) | `C` Sorting algorithms, Big O notation
| 8  | [Pipex](https://github.com/tderwedu/42cursus/tree/main/08_Pipex) | `C` |
| 9  | [Philosophers](https://github.com/tderwedu/42cursus/tree/main/09_Philosophers) | `C` Multi-threads, multi-processes, Dining philosophers problem |
| 10 | [MiniShell](https://github.com/tderwedu/42cursus/tree/main/10_MiniShell) | `C` Shell, IEEE-1003.1 Std, parsing (Lexer, Parser, AST) |
| 11 | [C++](https://github.com/tderwedu/42cursus/tree/main/11_CPP) | `C++` from OOP to templates |
| 12 | [Inception](https://github.com/tderwedu/42cursus/tree/main/12_Inception) | Docker, Docker Compose, NGINX, MySQL, WordPress, Redis |
| 13 | [ft_containers](https://github.com/tderwedu/42cursus/tree/main/13_ft_containers) | `C++` STL, vector, stack, map, Red Black Trees |
| 14 | [Webserv](https://github.com/tderwedu/42cursus/tree/main/14_Webserv) | `C++` HTTP - RFC7230 to RFC7234 |

## How to use it
> Note:  
> Everything has been developped on `Ubuntu 20.04 (Focal Fossa)` on `WSL 2` and may not work properly in other environments.

Since most project come with a `makefile`, clone this repository and go into the projetc's folder:
```
make
```
or (if any)
```
make bonus
```
to get try the full version.

## The Norm

The norm is a programming standard defining a set of rules to follow when writing C code.  
Most notably:
 - ```For```, ```do ... while``` and ```case``` are forbidden,
 - Each function must have a maximum of _25_ lines,
 - Each Lines mustmust be at most _80_ cloumns wide,
 - No more than _5_ variables per bloc can be declared.

## License

If not specified otherwise, everything in this repository is released under the [Unlicense](https://github.com/tderwedu/42cursus/blob/main/LICENSE).
