#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;


/* Ktore dzialanie szybsze? pow(x,0.5), czy sqrt(x)?
 * Zeby czym¶ zajac komputer, bedziemy sumowac pierwiastki z roznych
 * wartosci. Zwrocmy uwage, ze wynik bedzie zalezny od szybkosci komputera,
 * mozesz uzyskaæ inne wyniki niz Twoj kolega/kolezanka.
 * Co wiecej, aby pomiar by³ wiarygodny, nalezy uruchomic program kilkakrotnie
 * i usrednic uzyskane wyniki (np. z 3 badz 5 prob).
 */

int main()
{
   int n = 100000000; // duzo razy liczymy
   double x = 0.1;
   double s;


   s = 0.0;
   int t0pow = clock(); // czas start!
   for (int i=0; i<n; ++i)
      s += pow(x+s, 0.5);
   int t1pow = clock(); // czas stop!

   cout << "pow(,0.5) - " << double(t1pow-t0pow)/CLOCKS_PER_SEC;
   cout << " s." << endl;


   s = 0.0;
   int t0sqrt = clock(); // czas start!
   for (int i=0; i<n; ++i)
      s += sqrt(x+s);
   int t1sqrt = clock(); // czas stop!

   cout << "sqrt()    - " << double(t1sqrt-t0sqrt)/CLOCKS_PER_SEC;
   cout << " s." << endl;

   return 0;
}


// Przykladowy wynik:
// pow(,0.5) - 8.93 s.
// sqrt()    - 1.78 s.

