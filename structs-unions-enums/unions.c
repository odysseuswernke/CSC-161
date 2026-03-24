#include <stdio.h>
#include <string.h>

// Store values of different types in this tagged union
struct value {
  enum {CHAR, INT, FLOAT, STRING} tag;
  union {
    char c;
    int i;
    float f;
    char* s;
  };
};

//print struct type and its value
void print_value(struct value val){
  switch(val.tag){
    case CHAR:
      printf("%c\n", val.c);
      break;
    case INT:
      printf("%d\n", val.i);
      break;
    case FLOAT:
      printf("%f\n", val.f);
      break;
    case STRING:
      printf("%s\n", val.s);
      break;
  }
}


int main() {
  //Store values of different types with tagged union
  struct value w = {
    .tag = STRING,
    .s = "Hello world!"
  };

  struct value x = {
    .tag = FLOAT,
    .f = 3.14159
  };

  struct value y = {
    .tag = INT,
    .i = 3819
  };

  struct value z = {
    .tag = STRING,
    .s = "CSC 161 is fun"
  };

  print_value(w);
  print_value(x);
  print_value(x);
  print_value(z);
  return 0;
}
