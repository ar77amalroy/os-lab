echo "Enter range"
read n
x=0
y=1
echo "Fibonacci series:"
echo $x
echo $y
for ((i=2; i<n; i++))
do
    z=$(($x + $y))
    echo $z
    x=$y
    y=$z
done
