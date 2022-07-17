#include <iostream>
using namespace std;

/* Implementacja ATD typu slownik - tablice (wersja podstawowa)
 * Jak zwykle zakladamy, ze w ATD przechowujemy pojedyncza zmienna typu int.
 */


// ---------- slownik.h ------------------------------------------


bool search(int x, int* t, int n);    // O(n)
void  insert(int x, int*& t, int& n); // O(n)
void remove(int x, int*& t, int& n);  // O(n)

void print(int* t, int n);
void removeAll(int*& t, int& n);


// ---------- main.cpp ------------------------------------------

int main()
{
   int* t = NULL;
   int n = 0; // pusty slownik
   
   for (int i=0; i<10; ++i)
      insert((5*i+17)%13, t, n); // wstaw jakies wartosci

   print(t, n);      

   for (int i=0; i<5; ++i)
      cout << i << ": " << search(i, t, n) << endl; // wyszukaj jakies wartosci

   for (int i=5; i<10; ++i)
      remove(i, t, n); // usun jakies wartosci

   print(t, n);

   removeAll(t, n);
   
   return 0;
}


// ---------- slownik.cpp ------------------------------------------

bool search(int x, int* t, int n) // O(n)
{
   if (n == 0) return false; // slownik pusty

   for (int i=0; i<n; ++i)
      if (t[i] == x) return true; // jest

   return false; // nie ma
}


void  insert(int x, int*& t, int& n) // O(n)
{
   if (n == 0)
   {
      n = 1;
      t = new int[n];
      t[0] = x;
   }
   else if (!search(x, t, n)) // jak jest - nie dodajemy nic
   {
      int* tstara = t;
      t = new int[n+1];
      for (int i=0; i<n; ++i)
         t[i] = tstara[i];
      t[n] = x;
      n++;
      delete [] tstara;
   }
}


void remove(int x, int*& t, int& n) // O(n)
{
   if (n == 0) return;
   else if (n == 1 && t[0] == x)
   {
      delete [] t;
      t = NULL;
      n = 0;
   }
   else
   {
      int i;
      for (i=0; i<n; ++i)
         if (t[i] == x) break; // jest

      if (i < n) // jest
      {
         n--;
         int* tstara = t;
         t = new int[n];
         for (int j=0; j<i; ++j)
            t[j] = tstara[j];

         for (int j=i+1; j<=n; ++j)
            t[j-1] = tstara[j];

         delete [] tstara;
      }
   }
}


void print(int* t, int n)
{
   cout << "{ ";
   for (int i=0; i<n; ++i)
      cout << t[i] << " ";
   cout << "}" << endl;
}


void removeAll(int*& t, int& n)
{
   if (n > 0)
   {
      delete [] t;
      t = NULL;
      n = 0;
   }
}
