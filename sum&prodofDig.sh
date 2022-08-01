read n;
sum=0
product=1
while [ $n -gt 0 ]
do
    let "sum+=n%10" "product*=n%10" "n/=10"
done
echo "product " $product
echo "sum " $sum
