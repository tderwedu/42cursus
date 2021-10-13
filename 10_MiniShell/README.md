# ```MiniShell```
*a 19 Coding School project*

The objective of this project is to create a simple bash-like shell.

# Brief Summary

There is a main loop which wait for commands, parse it into token, check the grammar and syntax, get the here-documents if any and either produce an error or an output the resulting command.

```c
// Initialize minishell
while (1)
{
	msh.line = readline("msh>");
	if (!msh.line)
		break ;
	else if (*msh.line)
	{
		add_history(msh.line);
		lexer(&msh);
		parser(&msh);
		word_expansion(&msh);
		get_heredoc(&msh);
		launcher(&msh);
		g_sig = 0;
	}
	g_sig = 0;
	clean_msh(&msh);
}
// quit properly
```

## The Lexical Analyzer

The lexical analysis simply break the input string from the user to a series of tokens. Each tokens can either be a character or a series of characters. It also groups characters that are inside a single or double quotations.


## The Syntax Tree Parser

The implementation is based on a recursive parsing technique. After getting the tokens from the lexer, the parser build a binary tree data structure that holds tokens and operations in order of the execution. This is called an [Abstract Syntax Tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree).

The implemented shell language grammar is defined as follows in [Backus–Naur form](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form):

```c
<pipe seq>	::	<command>  '|'  <pipe seq>
			|	<command>

<command>	::=	   WORD		<cmd lst>
			|	<io redir>	<cmd lst>

<cmd lst>	::=	   WORD		<cmd lst>
		 	|	<io redir>	<cmd lst>

<io redir>	::=	 IO_NBR		<io file>
		 	|	 IO_NBR		<io here>
			|	<io file>
		 	|	<io here>

<io file>	::=	   '<' 		WORD
		 	|	   '>' 		WORD
		 	|	   '>>'		WORD

<io here>	::=	   '<<' 	WORD
```

For each production, there is one function which validates its corresponding rule. The purpose is to recursively check if the order of tokens belongs to a particular grammar. This reduces down to check for terminal symbols and non-terminals.

## Execution

After we build our syntax tree, it is quite easy to traverse through out the abstract syntax tree in order and make executions if necessary.

# Acknowledgements

 - Stanford's course [CS143](https://web.stanford.edu/class/archive/cs/cs143/cs143.1128/)
 - Swoorup Joshi's [mysh](https://github.com/Swoorup/mysh)
 - Stéphane Chazelas' answer [Symbolic link recursion](https://unix.stackexchange.com/questions/79571/symbolic-link-recursion-what-makes-it-reset/79621#79621)
 - Stackoverflow's question [Difference between LL and LR parsing](https://stackoverflow.com/questions/5975741/what-is-the-difference-between-ll-and-lr-parsing/6824545#6824545)
  - Stackoverflow's question [Difference between an LL and Recursive Descent parser](https://stackoverflow.com/questions/1044600/difference-between-an-ll-and-recursive-descent-parser/1044678#1044678)


# License

Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).


