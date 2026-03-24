
// Declare (but do not define) the pair struct.
// This allows us to use the name of this struct later even though we haven't defined it yet.
struct pair;

// Store values of different types in this tagged union
struct value {
  enum {CHAR, INT, FLOAT, STRING, PAIR, NIL} tag;
  union {
    char c;
    int i;
    float f;
    char* s;
    struct pair* p;
  };
};

// Hold a pair of values together
struct pair {
  struct value car;
  struct value cdr;
};

int main() {
  
  return 0;
}
