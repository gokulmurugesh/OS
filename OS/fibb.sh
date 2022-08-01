#! /bin/bash
read -p "Enter a number :" num;
a=-1
b=1
for i in $( eval echo {1..$num} )
do
c=$((a+b))
echo $c
a=$b
b=$c
done