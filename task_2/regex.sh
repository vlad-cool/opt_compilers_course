#!/bin/sh
SUB_EXPRESSION="2(([0-4][0-9])|(5[0-5]))|([1][0-9][0-9])|([1-9]?[0-9])"
EXPRESSION="^($SUB_EXPRESSION)\.($SUB_EXPRESSION)\.($SUB_EXPRESSION)\.($SUB_EXPRESSION)$"

echo $EXPRESSION

cat $1 | grep -E --color $EXPRESSION
