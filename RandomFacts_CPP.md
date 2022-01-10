
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
- `name hiding` or `shadowing` : the same variable name is used within multiple nested scopes.  
when a variable declared within a certain scope (decision block, method, or inner class) has the same name as a variable declared in an outer scope
	- `gcc -Wshadow`: warns you about name hiding
- `__PRETTY_FUCNTION__` is available in GCC and CLang. It gives us the name of the function in a pretty pretty format, including the template parameters, which we especially want.
- `What is move semantics?` Move semantics in contrast to copy semantics is a programming technique in which the members of an object are initialized by 'taking over' instead of copying another object's members. Such 'take over' makes only sense with pointers and resource handles, which can be cheaply transferred by copying the pointer or integer handle rather than the underlying data.
 - `What kind of classes and objects support move semantics?` It is up to you as a developer to implement move semantics in your own classes if these would benefit from transferring their members instead of copying them. Once you implement move semantics, you will directly benefit from work from many library programmers who have added support for handling classes with move semantics efficiently.
 - `Why can't the compiler figure it out on its own?` The compiler cannot just call another overload of a function unless you say so. You must help the compiler choose whether the regular or move version of the function should be called.
- `In which situations would I want to tell the compiler that it should treat a variable as an rvalue?` This will most likely happen in template or library functions, where you know that an intermediate result could be salvaged.

### Advantage of using `std::allocator`

 - allocator is the memory allocator for the STL containers. This container can separate the memory allocation and de-allocation from the initialization and destruction of their elements. Therefore, a call of vec.reserve(n) of a vector vec allocates only memory for at least n elements. The constructor for each element will not be executed.
 - allocator can be adjusted according to the container of your need, for example, vector where you only want to allocate occasionally.
 - On the contrary, new doesn’t allow to have control over which constructors are called and simply construct all objects at the same time. That’s an advantage of std:: allocator over new


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
