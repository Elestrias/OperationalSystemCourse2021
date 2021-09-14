gcc ex2.c
./a.out &
ex2_pid=$!
for((i=1;i<5;i++))
do
pstree $ex2_pid
sleep 2
done

