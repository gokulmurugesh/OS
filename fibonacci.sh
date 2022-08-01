read count
n1=-1
n2=1
for(( i=0;i<$count;i++ ))
do
    n=$((n1+n2))
    echo $n
    n1=$n2
    n2=$n
done
