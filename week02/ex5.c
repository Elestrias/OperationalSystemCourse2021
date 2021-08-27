#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void first(int height) {
  for (int i = 1; i <= height; i++) {
    for (int j = 0; j < height - i; ++j) {
      printf(" ");
    }
    for (int j = 0; j < 2 * i - 1; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void second(int height) {
  for (int i = 1; i <= height; i++) {
    for (int j = 0; j < i; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void third(int height) {
  int after_middle = 0;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < i + 1 - after_middle; ++j) {
      printf("*");
    }
    if (i >= height / 2) {
      after_middle += 2;
    }
    printf("\n");
  }
  if ((height % 2) == 0) {
    printf("*\n");
  }
}

void fourth(int height) {
  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= height; j++) {
      printf("*");
    }
    printf("\n");
  }
}

int main() {
  int a, b;
  printf("enter figure number: 1 - pyramid, 2 - semi-pyramid\\n 3 - rotated "
         "pyramyd 4 - square:\n");
  scanf("%d %d", &a, &b);
  if (a == 1) {
    first(b);
  } else if (a == 2) {
    second(b);
  } else if (a == 4) {
    fourth(b);
  } else if (a == 3){
      third(b);
  }
}
