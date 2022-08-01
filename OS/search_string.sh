#! /bin/bash
str1="Hi this is Linux"
str2="this"
if [[ $str1 == *"$str2"* ]]
then
echo "$str2 is present in $str1"
else
echo "$str2 is not in present in $str1"
fi