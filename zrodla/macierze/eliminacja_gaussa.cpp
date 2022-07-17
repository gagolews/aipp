#include <iostream>
#include <iomanip>
using namespace std;
#include <cstdlib>
#include <ctime>


void schodkowa(double** A, double* b, int n)
{
   for (int i=0; i<n; ++i)
   { /* dla kazdego wiersza */
      for (int j=i+1; j<n; ++j)
      { /* odejmij od wiersza j
           A[j][i]/A[i][i]*(wiersz i) - komb. lin. */
         for (int k=i; k<n; ++k)
            A[j][k] -= A[j][i]/A[i][i]*A[i][k];

         b[j] -= A[j][i]/A[i][i]*b[i];
      }
   }
}


void eliminwst(double** A, double* b, int n, double* x)
{
   for (int i=n-1; i>=0; --i)
   {
      x[i] = b[i];
      for (int k=i+1; k<n; ++k)
      {
         x[i] -= A[i][k] * x[k];
      }
      x[i] /= A[i][i];
   }
}


void wypiszmacierz(double** A, int n)
{
   for (int i=0; i<n; ++i)
   {
      for (int j=0; j<n; ++j)
         cout << setw(9) << A[i][j] << "\t";
      cout << endl;
   }
   cout << endl;
}


void wypiszwektor(double* t, int n)
{
   for (int i=0; i<n; ++i)
      cout << t[i] << endl;
   cout << endl;
}


int main()
{
   double** A;
   double* b;
   double* x;
   int n=4;
   srand(time(NULL));

   A = new double*[n];
   b = new double[n];
   x = new double[n];

   // utworz losowa macierz A i wektor b
   for (int i=0; i<n; ++i)
   {
      A[i] = new double[n];

      for (int j=0; j<n; ++j)
      {
         A[i][j] = rand()/double(RAND_MAX)*1000.0-500.0;
      }
      b[i] = rand()/(double)RAND_MAX*1000.0-500.0;
   }
   wypiszmacierz(A,n);

   schodkowa(A,b,n);      // krok I
   eliminwst(A, b, n, x); // krok II
   wypiszwektor(x,n); // rozwiazanie


   // kasowanie
   delete [] x;
   delete [] b;

   for (int i=0; i<n; ++i) delete [] A[i];
   delete [] A;

   return 0;
}
