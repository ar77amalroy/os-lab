echo "Enter number to find factorial"
read n
fact=1
for((i=1;i<=$n;i++))
do
((fact=$fact*i))
done
echo $fact

