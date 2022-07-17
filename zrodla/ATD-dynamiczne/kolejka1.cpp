#include <iostream>
#include <cassert>
using namespace std;

// -------------- kolejka.h ------------------------

bool empty(int* s, int t, int b, int n);
int dequeue(int* s, int t, int& b, int n);
void enqueue(int x, int* s, int& t, int b, int n);


// -------------- main.cpp ----------------------


int main()
{
   int  n = 10;
   int* s = new int[n]; // n-1 element�w mo�na przechowa� (zob. ni�ej)
   int  t = 0; // pierwsze wolne miejsce
   int  b = 0; // pierwsze zaj�te miejsce

   enqueue(7, s, t, b, n);
   enqueue(5, s, t, b, n);
   enqueue(3, s, t, b, n);

   while (!empty(s, t, b, n))
      cout << dequeue(s, t, b, n);
   // wypisze na ekran 7,5,3

   return 0;
}


// ------------ kolejka.cpp -------------------------

bool empty(int* s, int t, int b, int n)
{
   return (t == b); // true, je�li pusta
}


int dequeue(int* s, int t, int& b, int n)
{
   assert(t != b); // zak�adamy, �e mamy co zdejmowa�
   int x = s[b];
   b = (b+1)%n;
   return x;
}

void enqueue(int x, int* s, int& t, int b, int n)
{
   assert((t+1)%n != b); // zak�adamy, �e mamy gdzie umie�ci� element
   s[t] = x;
   t = (t+1)%n;
}
