#!/bin/sh

make all

replace_test () {
    echo "\e[36m From ORIGIN to REPLACED \e[0m"
    echo "> ./replace $1 \"$2\" \"$3\""
    ./replace "$1" "$2" "$3"
    echo "\e[36m From REPLACED back to ORIGIN \e[0m"
	echo "> ./replace $1.replace \"$3\" \"$2\""
    ./replace "$1.replace" "$3" "$2"
	echo "\e[36m Checking differences \e[0m"
    echo "> diff $1 $1.replace.replace"
    diff $1 "$1.replace.replace"
}

replace_error() {
    echo "$ ./replace $1 $2 $3"
    ./replace "$1" "$2" "$3"
}

echo "\e[31m ========> FAIL test \e[0m"
replace_test open.txt "open" "close"

echo '\e[32m ========> TEST: Simple \e[0m'
replace_test open.txt "open()" "close()"
echo '\e[32m ========> TEST: Whole Sentence \e[0m'
replace_test open.txt "open()" "A call to open() creates a new open file description,"
echo '\e[32m ========> TEST: Newlinesest  \e[0m'
replace_test open.txt "open()" '\nclose()\n'
echo '\e[32m ========> TEST: No match \e[0m'
replace_test open.txt "RIEN" "NOTHING"


echo '\e[31m ========>ERROR: nbr args [0] \e[0m'
./replace
echo '\e[31m ========>ERROR: nbr args [1] \e[0m'
./replace open.txt
echo '\e[31m ========>ERROR: nbr args [2] \e[0m'
./replace open.txt "open()"
echo '\e[31m ========>ERROR: nbr args [4] \e[0m'
./replace open.txt "open()" "close()" "read()"
echo '\e[31m ========>ERROR: s1 NULL \e[0m'
./replace open.txt "" "close()"
echo '\e[31m ========>ERROR: s2 NULL \e[0m'
./replace open.txt "open()" ""
echo '\e[31m ========>ERROR: filename NULL \e[0m'
./replace "" "open()" "close()"
echo '\e[31m ========>ERROR: filename do not exist \e[0m'
./replace cLoSe.tXt "open()" "close()"
