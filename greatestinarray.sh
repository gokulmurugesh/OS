echo "Enter array size"
read count
echo "Enter the numbers"
read n;
large=$n
for(( i=1;i<$count;i++ ))
do
    read n
    if [ $n -gt $large ]
    then
        large=$n
    fi
done
echo "largest is "$large
