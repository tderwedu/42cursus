#!/bin/sh

make all

replace_test () {
	echo "\033[36m From ORIGIN to REPLACED \033[0m"
	echo "> ./replace $1 \"$2\" \"$3\""
	./replace "$1" "$2" "$3"
	echo "\033[36m From REPLACED back to ORIGIN \033[0m"
	echo "> ./replace $1.replace \"$3\" \"$2\""
	./replace "$1.replace" "$3" "$2"
	echo "\033[36m Checking differences \033[0m"
	echo "> diff $1 $1.replace.replace"
	diff $1 "$1.replace.replace"
}

replace_error() {
	echo "$ ./replace $1 $2 $3"
	./replace "$1" "$2" "$3"
}

echo "\033[31m ########  FAIL test ######## \033[0m"
replace_test open.txt "open" "close"

echo '\033[32m ########  TEST: Simple ######## \033[0m'
replace_test open.txt "open()" "close()"
echo '\033[32m ########  TEST: Empty file ######## \033[0m'
replace_test empty.txt "A" "a"
echo '\033[32m ########  TEST: Whole Sentence ########\033[0m'
replace_test open.txt "open()" "A call to open() creates a new open file description,"
echo '\033[32m ########  TEST: Newlines ######## \033[0m'
replace_test open.txt "open()" '\nclose()\n'
echo '\033[32m ########  TEST: No match \033[0m'
replace_test open.txt "RIEN" "NOTHING"


echo '\033[31m ######## ERROR: nbr args [0] ######## \033[0m'
./replace
echo '\033[31m ######## ERROR: nbr args [1] ######## \033[0m'
./replace open.txt
echo '\033[31m ######## ERROR: nbr args [2] ######## \033[0m'
./replace open.txt "open()"
echo '\033[31m ######## ERROR: nbr args [4] ######## \033[0m'
./replace open.txt "open()" "close()" "read()"
echo '\033[31m ######## ERROR: s1 = "\0" ########\033[0m'
./replace open.txt "" "close()"
echo '\033[31m ######## ERROR: s2 = "\0" ######## \033[0m'
./replace open.txt "open()" ""
echo '\033[31m ######## ERROR: filename = "\0" ######## \033[0m'
./replace "" "open()" "close()"
echo '\033[31m ######## ERROR: filename do not exist ######## \033[0m'
./replace cLoSe.tXt "open()" "close()"

chmod 000 open.txt
echo '\033[31m ######## ERROR: 0 permission ######## \033[0m'
./replace open.txt "open()" "close()"
chmod 644 open.txt