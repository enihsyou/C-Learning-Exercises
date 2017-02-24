#include<stdio.h>

int main() {
  struct p {
    char *name;
    int scores[5];
    int score;
  };
  int i, j, k, tmp;
  struct p temp;

  struct p a[20];
  for (i = 0; i < 20; i++) {
    scanf("%s %d %d %d %d %d", a[i].name, &a[i].scores[0], &a[i].scores[1], &a[i].scores[2],
          &a[i].scores[3], &a[i].scores[4]);
  }

  for (i = 0; i < 20; i++) {
    for (j = 0; j < 5; j++) {
      for (k = j + 1; k < 5; k++) {
        if (a[i].scores[j] > a[i].scores[k]) {
          tmp = a[i].scores[j];
          a[i].scores[j] = a[i].scores[k];
          a[i].scores[k] = tmp;
        }
      }
    }
    a[i].score = a[i].scores[2];
  }
  for (i = 0; i < 20; i++) {
    for (j = 0; j < 5; j++) {
      if (a[i].score > a[j].score) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
  for (i = 0; i < 10; i++) {
    printf("第%d名 %s %d分\n", i + 1, a[i].name, a[i].score);
  }
  return 0;
}
