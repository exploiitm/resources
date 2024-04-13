#include <stdio.h>

int f4() {
  return 5 + 4;
}

int f3() {
  return f4();  
}

int f2(){
  return f3();
}

int f1(){
  return f2();
}

int main(){
    printf("%d\n", f1());  
}
