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

   for (int i=0; i<n-1; ++i)
   {
      // znajdz indeks najmn. el. sposrod t[i], ..., t[n-1];
      int j = i;
      for (int k=i+1; k<n; ++k)
         if (t[k] < t[j])        // porownanie elementow
            j = k;

      zamien(t[i], t[j]);        // zamiana elementow
   }

   for (int i=0; i<n; ++i) cout << t[i];

   delete [] t;
   return 0;
}

