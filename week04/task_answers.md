# Week 04 task answers:

## Task 1

The output is different because we always create a new processes with a unique pid, also we have many other proccesses in the system that can create new proccesses, so the numbers of pid can go not one after another:
 - example of an output: 
```Hello from parent node PID - 51180
Hello from child node PID - 51181
Hello from parent node PID - 51185
Hello from child node PID - 51186
Hello from parent node PID - 51188
Hello from child node PID - 51189
Hello from parent node PID - 51191
Hello from child node PID - 51192
Hello from parent node PID - 51194
Hello from child node PID - 51195
Hello from parent node PID - 51197
Hello from child node PID - 51198
Hello from parent node PID - 51200
Hello from child node PID - 51201
Hello from parent node PID - 51203
Hello from child node PID - 51204
Hello from parent node PID - 51206
Hello from child node PID - 51207
Hello from parent node PID - 51209
Hello from child node PID - 51210
```

Also, it is good to add that after the rebooting of the system, the numeration of processes will be refreshed, and begins from 2, as 0 pid is unused and 1st one is reserved for init process.


## Task 2

Every process creates a child one and continues as long as i will be equal to 5, at every i every process doubles itself, so the number of processes will be always equal to 2 in a power of i.
 - example of output
```
ex2─┬─ex2─┬─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2───ex2
    │     └─ex2
    ├─ex2───ex2
    └─ex2
```
