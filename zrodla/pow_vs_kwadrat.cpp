#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;


/* Ktore dzialanie szybsze? pow(x,2), czy x*x?
 * Zeby czym¶ zajac komputer, bedziemy sumowac kwadraty z roznych
 * wartosci. Zwrocmy uwage, ze wynik bedzie zalezny od szybkosci komputera,
 * mozesz uzyskaæ inne wyniki niz Twoj kolega/kolezanka.
 * Co wiecej, aby pomiar by³ wiarygodny, nalezy uruchomic program kilkakrotnie
 * i usrednic uzyskane wyniki (np. z 3 badz 5 prob).
 */

double kwadrat(double x)
{
   return x*x;
}



int main()
{
   int n = 100000000; // duzo razy liczymy
   double x = -0.9;
   double s;


   s = 0.0;
   int t0pow = clock(); // czas start!
   for (int i=0; i<n; ++i)
      s += pow(x+s, 2);
   int t1pow = clock(); // czas stop!

   cout << "pow(,2)   - " << double(t1pow-t0pow)/CLOCKS_PER_SEC;
   cout << " s." << endl;

   s = 0.0;
   int t0sqrt = clock(); // czas start!
   for (int i=0; i<n; ++i)
      s += kwadrat(x+s);
   int t1sqrt = clock(); // czas stop!

   cout << "kwadrat() - " << double(t1sqrt-t0sqrt)/CLOCKS_PER_SEC;
   cout << " s." << endl;

   return 0;
}


// Przykladowy wynik:
// pow(,2)   - 1.7 s.
// kwadrat() - 1.5 s.

