
# Canonical Form

In C++, there are 3 things every object is expected to be able to do:
 - An object should be able to initialize itself to a default state,
 - It should be able to initialize itself from another instance of the same class,
 - It should be able to assume the semantic state of another instance of the same class. 

In C++, these operations are expressed with the default constructor, the copy constructor, and the assignment operator.
These three functions are special in C++: If you don't provide them yourself, C++ provides them for you. And automatically makes them public.

	You can declare the function private and not define it. The declaration will suppress the compiler-generated version of the function.
	The default constructor is only defined by the compiler when you don’t create any other constructors.
	For copying and assignment the automatically-generated code will do a SHALLOW memberwise COPY.

# Random Facts

- The delete operator in C++ automatically performs this null check for you, so it's okay to delete a null pointer. 
- Access control in C++ is done on an class by class basis, not on an instance-by-instance basis.
- `++iter` returns the value after being incremented!  
`iter++` returns the previous value and then increments it. (wastes
just a bit of time)
- Top-level cv-qualifier are ignored in function’s signature. NON-top-level cv-qualifiers are not ignored.  
`T const *volatile q;`  
	 - volatile = top-level
	 - const = second-level
- `explicit`:  Specifies that a constructor is explicit, that is, it cannot be used for implicit conversions and copy-initialization.

# Memory Alignement


struct Data
{
	char	c;
	int		i;
	long	l;	
} __attribute__((packed, aligned(4)));

 - "packed"    : use the smallest possible space - i.e.no  padding for momory alignement
 - "aligned(4)": the struct should be aligned to an address that is divisible by 4

 /!\ These are GCC extensions, not part of any C standard.
