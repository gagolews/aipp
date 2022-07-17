#include <iostream>
#include <cassert>
using namespace std;

// -------------- kolejka.h ------------------------

bool empty(int* s, int t, int b, int n);
int dequeue(int* s, int t, int& b, int n);
void enqueue(int x, int*& s, int& t, int& b, int& n);


// -------------- main.cpp ----------------------


int main()
{
   int  n = 2;
   int* s = new int[n];
   int  t = 0; // pierwsze wolne miejsce
   int  b = 0; // pierwsze zajête miejsce

   for (int i=0; i<10; ++i)
      enqueue(i, s, t, b, n);

   while (!empty(s, t, b, n))
      cout << dequeue(s, t, b, n);

   return 0;
}


// ------------ kolejka.cpp -------------------------

bool empty(int* s, int t, int b, int n)
{
   return (t == b); // true, je¶li pusta
}


int dequeue(int* s, int t, int& b, int n)
{
   assert(t != b); // zak³adamy, ¿e mamy co zdejmowaæ
   int x = s[b];
   b = (b+1)%n;
   return x;
}


void enqueue(int x, int*& s, int& t, int& b, int& n)
{
   if ((t+1)%n == b) // konieczno¶æ powiêkszenia s
   {
      int* starys = s;  // zapamiêtaj star±
      s = new int[n+1]; // stwórz now±

      for (int i=0; i<n-1; ++i)
         s[i] = starys[(b+i)%n]; // przepisanie z przeindeksowaniem

      delete [] starys;      // skasuj star±
      b = 0;
      t = n-1;
      ++n;
   }
   
   s[t] = x;
   t = (t+1)%n;
}
