read n
temp=$n
length=${#n}
result=0
while [ $temp -gt 0 ]
do
    let "r=temp%10" "result+=r**length" "temp/=10"
done
if [ $n == $result ] 
then
    echo $n "is an armstrong number"
else
    echo $n "is not an armstrong number"
fi
