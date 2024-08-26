#include <stdio.h>

int main() {
  int a = 1;

  printf("%p\n", &a); // print pointer address
  printf("%u\n", a); 
  printf("%c\n", 'a');
  printf("%%\n"); // print %
  //
  printf("###%5d###\n", 32); // print with width, right algin
  printf("###%-5d###\n", 32); // print with width, left algin
  printf("###%*d###\n", 10, 32); // print with width, take width 10 from argument
  printf("###%05d###\n", 32); // print with width padding with 0
  //
  printf("%.2f\n",32.233322234); // 32.23
  printf("%*.*f\n",10,2,32.233322234); // the first start is witdh, the second star is precsion
  //
  long long int l = 1123123123123123123;
  printf("###%ld###\n", 1123123123123123123); // print with width, right algin

  size_t size = 123;
  printf("###%zu###\n", size);
}
