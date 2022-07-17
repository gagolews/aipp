#include <iostream>
#include <cassert>
using namespace std;

// -------------- stos.h ------------------------

bool empty(int* s, int t, int n);
int pop(int* s, int& t, int n);
void push(int x, int* s, int& t, int n);


// -------------- main.cpp ----------------------


int main()
{
   int  n = 100;
   int* s = new int[n];
   int  t = -1;

   push(7, s, t, n);
   push(5, s, t, n);
   push(3, s, t, n);

   while (!empty(s, t, n))
      cout << pop(s, t, n);
   // wypisze na ekran 357

   return 0;
}


// ------------ stos.cpp -------------------------

bool empty(int* s, int t, int n)
{
   return (t < 0); // true, je¶li pusty
}


int pop(int* s, int& t, int n)
{
   assert(t >= 0); // zak³adamy, ¿e mamy co zdejmowaæ
   return s[t--];  // zwróæ s[t], a potem zmniejsz t o 1
}

void push(int x, int* s, int& t, int n)
{
   assert(t < n-1); // zak³adamy, ¿e mamy gdzie umie¶ciæ element
   s[++t] = x;      // najpierw zwiêksz t o 1, potem s[t] = x;
}
