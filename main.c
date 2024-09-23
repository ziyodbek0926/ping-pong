#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void line(int rack_1, int rack_2, int chap_01r, int ong_01r, int ball_y,
          int ball_x, int score_1, int score_2);

#define Y 25
#define X 80
#define chap_rack 3
#define ong_rack 3

int main() {
  system("clear");  // consolni tozalash uchun

  int rack_1 = 12;
  int rack_2 = 12;
  int chap_01r = 0;
  int ong_01r = 0;
  int ball_y = 13;
  int ball_x = 40;
  int j_2 = 1;
  int j_1 = -1;
  int score_1=0;
  int score_2=0;
  char c;

  while (1) {

    if (ball_x==1)
    {
      score_1++;
      ball_x=40;
      ball_y=13;
    } else if (ball_x==X-2)
    {
      score_2++;
      ball_x=40;
      ball_y=13;
    }
    
    
    if (((ball_y >= rack_1 && ball_y <= rack_1+2 )&& ball_x == 2) || (ball_y >= rack_2 && ball_y <= rack_2+2 ) && ball_x==77) j_1 = (-1) * j_1;

    if (ball_y == 23 || ball_y == 1) j_2 = (-1) * j_2;
    ball_x += j_1;
    ball_y += j_2;
    c = getchar();
    if ((c == 'z' || c == 'Z') && rack_1 < 21) {
      rack_1++;
    } else if ((c == 'a' || c == 'A') && rack_1 > 1) {
      rack_1--;
    } else if ((c == 'k' || c == 'K') && rack_2 > 1) {
      rack_2--;
    } else if ((c == 'm' || c == 'M') && rack_2 < 21) {
      rack_2++;
    }else if (c == 'q')
    {
      break;
    }
    
    line(rack_1, rack_2, chap_01r, ong_01r, ball_y, ball_x, score_1, score_2);  // fon funksiyasi
    usleep(1000);                                             //
  }
  return 0;
}

void line(int rack_1, int rack_2, int chap_01r, int ong_01r, int ball_y,
          int ball_x, int score_1, int score_2) {  // fon funksiyasi
  system("clear");       // consolni tozalash uchun

  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      if (i == 0) {
        printf(",");

      } else if (i == Y - 1) {
        printf("`");
      } else if (j == 0 || j == X - 1) {
        putchar(124);

      } else if (j == 1 && chap_01r < chap_rack && rack_1 == i &&
                 rack_1 != 24 && rack_1 != 0) {
        putchar(124);
        chap_01r++;
        rack_1++;
      } else if (i == ball_y && j == ball_x) {
        printf("o");
      } else if (j == X - 2 && ong_01r < ong_rack && rack_2 == i &&
                 rack_2 != 0 && rack_2 != 24) {
        putchar(124);
        ong_01r++;
        rack_2++;
      } else if (j == 39) {
        putchar(124);
        // printf("A");
      } else {
        putchar(32);
      }
    }
    putchar(10);
  }
  printf("%d \n%d\n", score_1, score_2);
}
