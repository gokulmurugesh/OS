#! /bin/bash
read -p "Enter the first string :" str1
read -p "Enter the second string :" str2
if [[ $str1 == $str2 ]]
then
echo "Both the strings are Equal"
else
echo "Both the strings are different"
fi