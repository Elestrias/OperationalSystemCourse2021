while true
do
x=$(tail -n1 input.txt)
x=$((x+=1))
echo $x>>input.txt
done