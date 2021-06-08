#!/bin/bash
if [[ $# -ne 1 ]]
then
    echo "Usage:\n$0 [number of elements]"
    exit 1
fi

if [ ! -f "./push_swap" ]; then
	echo "Compiling ..."
    make
fi

LIST=$(perl -e "use List::Util 'shuffle'; my @out = (shuffle 0..$1)[0..$1]; print \"@out\"")
echo "LIST=\""${LIST[@]}"\""

./push_swap ${LIST[@]} 

if [ -f "./checker" ]; then
	echo "Checker:"
	printf "\033[32m"
	./push_swap ${LIST[@]} | ./checker ${LIST[@]}
	printf "\033[0m"
fi

echo "Number of instructions:"
printf "\033[96m"
./push_swap ${LIST[@]} | wc -l
