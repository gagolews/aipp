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

   for (int i=1; i<n; ++i)
   {
      // znajdz najwieksze j ze zbioru {0,...,i} takie, ze
      // j == 0 lub t[i] > t[j-1];
      int j;
      for (j=i; j>0; j--)
         if (t[j-1] <= t[i])          // porownanie
            break;

      // wstaw t[i] przed t[j];
      for (int k = i-1; k>=j; k--)
         zamien(t[k], t[k+1]);         // zamiana
   }

   for (int i=0; i<n; ++i) cout << t[i];

   delete [] t;
   return 0;
}

