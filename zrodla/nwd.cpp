#include <iostream>
#include <cassert>
using namespace std;


// Algorytm Euklidesa - znajdywanie NWD



// wersja iteracyjna
int nwd_iter(int n, int m)
{
   assert(0 <= n && n <= m);
   int c;      // zmienna pomocnicza

   while (n != 0)
   {
      c = m%n;
      m = n;
      n = c;
   }

   return m;
}


// wersja rekurencyjna - zob. rozdz. 5
int nwd_rek(int n, int m)
{
   assert(0 <= n && n <= m);
   if (n == 0) return m;
   else return nwd_rek(m % n, n);
}


int main()
{
   int a = 532;
   int b = 774;

   cout << "nwd_iter(" << a << ", " << b << ") = " << nwd_iter(a, b) << endl;
   cout << "nwd_rek (" << a << ", " << b << ") = " << nwd_rek (a, b) << endl;

   return 0;
}
