#include <iostream>
using namespace std;


void zamien(int& x, int& y)
{
   int t = x;
   x = y;
   y = t;
}

int main()
{
   // ...
   int n = 5;
   int* t[n] = new int[n];
   t[0] = 5;
   t[1] = 3;
   t[2] = 2;
   t[3] = 1;
   t[4] = 4;
   // ...

   for (int i=n-1; i>0; --i)
   {
      for (int j=0; j<i; ++j)
      {
         // porownuj elementy parami
         if (t[j] > t[j+1])           // porownanie
            zamien(t[j], t[j+1]);     // zamiana
      }
   }

   for (int i=0; i<n; ++i) cout << t[i];

   delete [] t;
   return 0;
}

