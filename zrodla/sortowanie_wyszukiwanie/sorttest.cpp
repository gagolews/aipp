#include <iostream>
#include <ctime>
using namespace std;



void selsort(int t[], const int n)
{
   long long q = 0;
   for (int i=0; i<n-1; ++i)
   {
      int j = i;
      for (int k=i+1; k<n; ++k)
         if (t[k] < t[j])      
            j = k;

      // zamiana
      int p = t[i];
      t[i] = t[j];
      t[j] = p;
      q++;
   }
   cout << q << " & ";
}



void bubsort(int t[], const int n)
{
   long long q = 0;
   for (int i=n-1; i>0; --i)
   {
      for (int j=0; j<i; ++j)
      {
         if (t[j] > t[j+1])           // porownanie parami
         {
            int p = t[j];             // zamiana
            t[j] = t[j+1];
            t[j+1] = p;
            q++;
         }
      }
   }
   cout << q << " & ";
}


int main()
{
   const int n = 1000000;
   int t1[n], t2[n];

   clock_t cz0;
   clock_t cz1;
   clock_t cz2;

   for (int i=0; i<n; ++i)
   {
      t1[i] = t2[i] = n-i;
   }

   cout << n << " & ";

   cz0 = clock();
   selsort(t1, n);
   cz1 = clock();
   bubsort(t2, n);
   cz2 = clock();

   cout << (cz1-cz0)/double(CLOCKS_PER_SEC) << " & " << (cz2-cz1)/double(CLOCKS_PER_SEC) << "\\\\" << endl;

   return 0;
}
