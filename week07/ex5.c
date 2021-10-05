#include <stdio.h>
#include <stdlib.h>

int main() {
char **s = (char **)malloc(sizeof(char*)*512); // for (char **) we need to explicitly allocate memory via malloc/calloc
char foo[] = "Hello World";
*s = foo;
printf("s is %p\n",s); // s has a pointer type, so printf should receive %p as parameter
s[0] = foo;
printf("s[0] is %s\n",s[0]); return(0);
free(*s); // after all work have been done, it is better to free memory
}