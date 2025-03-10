echo "Enter num1"
read n1
echo "Enter num2"
read n2
echo "Enter option"
read op
case $op in
1)n3=$(($n1+$n2))
echo "Result="$n3;;
2)n3=$(($n1-$n2))
echo "Result="$n3;;
3)n3=$(($n1*$n2))
echo "Result="$n3;;
4)n3=$(($n2/$n1))
echo "Result="$n3;;
*)echo "Wrong choice";;
esac
