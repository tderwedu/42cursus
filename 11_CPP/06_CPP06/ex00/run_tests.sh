#!/bin/sh

run_test () {
    echo "$ ./convert \"$1\""
    ./convert "$1"
    echo '####################'
}

run_test ''
run_test '    '
run_test '   1'
run_test '1   '
run_test ' 1  '
run_test '- 1'

echo '=================================== CHAR  ==================='
run_test "'a'"
run_test "'A'"
run_test "' '"
run_test "'~'"
run_test "'.'"
run_test "'"
run_test "''"
run_test "'''"

echo '=================================== INT   ==================='
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

echo '=================================== FLOAT  =================='
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
run_test 'nanf'
run_test '-nanf'
run_test '3.5e+30f'
run_test '3.5e+40f'

echo '=================================== DOUBLE =================='
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
run_test '-nan'
