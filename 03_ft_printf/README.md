# ```ft_printf```
*a 19 Coding School project*

The C ```printf()``` function recoded from scratch.

## How to use it

Clone this repository and execute the following command
```bash
make bonus
```
to generate the librairy file ```libftprintf.a```.

## What's supported

- Flags : ```#```, ```0```, ```-```, ```+```, '``` ```'
- Width : direct decimal integer or as an argument with ```*```
- Precision : direct decimal integer or as an argument with ```*```
- Size : ```hh```, ```h```, ```l```, ```ll```
- Types : ```c```, ```s```, ```u```, ```o```, ```x```, ```X```, ```p```, ```n```, ```d```, ```i```, ```a```, ```A```, ```e```, ```E```, ```f```, ```F```,```g```, ```G```.


## What I have learned

I learned mostly about floating-point numbers called ```double```.  How they are laid in memory and how to convert them back to decimal. What are the special values defined by the ```IEEE 754``` standard and what are the rounding rules.

## Acknowledgements

- Florian Loitsch's [Grisu Algorithm](https://florian.loitsch.com/publications)
- Jean-Michel Gambard's [printfTester](https://github.com/Tripouille/printfTester.git)
- Gavin Fielder's [PFT](https://github.com/gavinfielder/pft)
- Maia Chardin's [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF.git)
- Charles Cabergs's [ft_printf_test](https://github.com/cacharle/ft_printf_test)

## Bibliography

> Guy. L. Steele Jr. and J. L. White: "How to print floating-point numbers accurately". In proceedings of ACM SIGPLAN '90 Conference on Programming Language Design and Implementation, White Plains, New York, June 1990, pp. 112-126

> Robert G. Burger and R. Kent Dybvig: "Printing floating-point numbers quickly and accurately." In proceedings of ACM SIGPLAN 1996 conference on Programming Language Design and Implementation, Philadelphia, PA, USA, May 1996, pp. 108-116

> Florian Loitsch: "Printing floating-point numbers quickly and accurately with integers." In proceedings of 2010 ACM SIGPLAN Conference on Programming Language Design and Implementation, Toronto, ON, Canada, June 2010, pp. 233-243

> Ulf Adams: "Ryū: fast float-to-string conversion." ACM SIGPLAN Notices, Vol. 53, No. 4, April 2018, pp. 270-282

## License

All files, except those in the *grisu* folder, are  released under the [Unlicense](https://github.com/tderwedu/42cursus/blob/main/LICENSE).

