#!/bin/sh

run_test () {
    printf "\e[32m $ ./convert \"$1\" \e[0m\n"
    ./convert "$1"
    echo
}

printf '\e[34m \t############## \e[0m \n'
printf '\e[34m \t#   SPACES   # \e[0m \n'
printf '\e[34m \t############## \e[0m \n'
run_test ''
run_test '    '
run_test '   1'
run_test '1   	'
run_test ' 1 
 '
run_test '- 1'

printf '\e[34m \t############ \e[0m \n'
printf '\e[34m \t#   CHAR   # \e[0m \n'
printf '\e[34m \t############ \e[0m \n'
run_test "'*'"
run_test "'a'"
run_test "'A'"
run_test "' '"
run_test "'~'"
run_test "'.'"
run_test "'"
run_test "''"
run_test "'''"

printf '\e[34m \t########### \e[0m \n'
printf '\e[34m \t#   INT   # \e[0m \n'
printf '\e[34m \t########### \e[0m \n'
run_test 0
run_test 5
run_test 70
run_test -1
run_test -0
run_test -70
run_test +70
run_test  2147483647
run_test -2147483648
run_test  2147483648
run_test -2147483649

printf '\e[34m \t############# \e[0m \n'
printf '\e[34m \t#   FLOAT   # \e[0m \n'
printf '\e[34m \t############# \e[0m \n'
run_test '0.0f'
run_test '1.0f'
run_test '0.1f'
run_test '3333.1f'
run_test '1.3333f'
run_test '.f'
run_test '.1f'
run_test '1.f'
run_test '1..1f'
run_test 'f'
run_test '0f'
run_test '1f'
run_test '33f'
run_test '-33f'
run_test '-33.45f'
run_test '+33f'
run_test '+33.45f'
run_test 'inff'
run_test '+inff'
run_test '-inff'
run_test '+infff'
run_test '-infff'
run_test 'nanf'
run_test '-nanf'
run_test '3.5e+30f'
run_test '3.5e+40f'

printf '\e[34m \t############## \e[0m \n'
printf '\e[34m \t#   DOUBLE   # \e[0m \n'
printf '\e[34m \t############## \e[0m \n'
run_test '0.0'
run_test '1.0'
run_test '0.1'
run_test '3333.1'
run_test '1.3333'
run_test '.'
run_test '.1'
run_test '1.'
run_test '1..1'
run_test '0'
run_test '1'
run_test '33'
run_test '-33'
run_test '-33.45'
run_test '+33'
run_test '+33.45'
run_test 'inf'
run_test '+inf'
run_test '-inf'
run_test 'nan'
run_test '-nan'
run_test '+nan'
