gcc ex1.c -o ex2
sleep 1
./ex2 &
top -i 1 | grep ex2
