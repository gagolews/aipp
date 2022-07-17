#include <iostream>
using namespace std;


// wersja rekurencyjna (por. rozdz. 5)
int binsrch(int* t, int n, int v, int a, int b)
{
//    cout << "binsrch(t, n, " << v << ", " << a << ", " << b << ")" << endl;

   if (a > b)
      return -1;
   else
   {
      int c = (a+b)/2;
//       cout << "c == " << c << endl;

           if (v == t[c]) return c;
      else if (v >  t[c]) return binsrch(t, n, v, c+1, b);
      else                return binsrch(t, n, v, a, c-1);
   }
}

int main()
{
   // tworz n-elementowa tablice (dla przykladu)
   // o elementach parzystych
   int n = 10;
   int* t = new int[n];
   for (int i=0; i<n; ++i)
      t[i] = 2*(i+1);


   // wyszukuj rozne wartosci:
   for (int i=0; i<2*n+1; ++i)
      cout << binsrch(t, n, i, 0, n-1) << endl;

//    cout << binsrch(t, n, 8, 0, n-1) << endl;
//    cout << binsrch(t, n, 9, 0, n-1) << endl;

   delete [] t;

   return 0;
}
