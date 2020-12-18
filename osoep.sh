for((i=0;i<10;i++))
do
flags[i]=0
alloc[i]=-1
done 
echo -e "enter no of blocks :\c"
read bno
echo "enter each size of block:"
for((i=0;i<$bno;i++))
do
read bsize[i]
done
echo -e "enter no of processes :\c"
read pno
echo "enter size of each process :"
for((i=0;i<$pno;i++))
do
read psize[i]
done
for((i=0;i<$pno;i++))
do
for((j=0;j<$bno;j++))
do
if [ ${flags[$j]} -eq 0 -a ${bsize[$j]} -ge ${psize[$i]} ]
then
alloc[j]=$i 
flags[j]=1
break 
fi
done
done
echo -e "Block no. \t size \t\t process no. \t\t size"
for((i=0;i<$bno;i++))
do
echo -e "`expr $i + 1` \t\t ${bsize[$i]} \t\t \c"
if [ ${flags[$i]} -eq 1 ]
then 
a=`expr ${alloc[$i]} + 1`
echo -e "$a \t\t\t ${psize[${alloc[$i]}]}"
else
echo "Not allocated"
fi
done
