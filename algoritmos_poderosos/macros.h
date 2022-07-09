#ifndef __MACROS__
#define __MACROS__

typedef int Item;

#define key(A) (A)

#define less(A,B) (key(A) < key(B))

#define lesseq(A,B) (key(A) <= key(B))

#define exch(A,B) { Item t; t=A;A=B;B=t; }

#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

#endif
