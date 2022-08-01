#! /bin/bash
read -p "Enter a number :" num
temp=$num
r=0
n=0
while [ $num -gt 0 ]
do 
r=$((num%10))
n=$((n + $((r * r * r)) ))
num=$((num/10))
done
if [ $n -eq $temp ]
then 
echo "Armstrong"
else
echo "Not Armstrong"
fi