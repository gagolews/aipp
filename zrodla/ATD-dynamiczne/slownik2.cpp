#include <iostream>
#include <cassert>
using namespace std;

/* Implementacja ATD typu slownik - tablice (szybkie wyszukiwanie)
 * - zak³adamy, ¿e tablica jest zawsze posortowana
 * Jak zwykle zakladamy, ze w ATD przechowujemy pojedyncza zmienna typu int.
 */


// ---------- slownik.h ------------------------------------------


bool search(int x, int* t, int n);    // O(log n)
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

bool search(int x, int* t, int n) // O(log n)
{
   if (n == 0) return false; // slownik pusty

   // wyszukiwanie binarne (polowkowe)

   int l = 0;
   int p = n-1;
   while (l <= p)
   {
      int m = (p+l)/2;
      
      if (x == t[m]) return true; // jest
      else if (x > t[m]) l = m+1;
      else               p = m-1;
   }

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
   else if (!search(x, t, n)) // jak nie ma - dodajemy
   {
      int* tstara = t;
      t = new int[n+1];
  
      int i=0;
      while (i<n && tstara[i] < x) // wstaw z zachowaniem porz±dku
      {
         t[i] = tstara[i];
         i++;
      }
      
      t[i] = x;
      i++;
      n++;

      while (i<n)
      {
         t[i] = tstara[i-1];
         i++;
      }

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
   else if (search(x, t, n)) // szybko sprawdzamy, czy jest
   {
      int i;
      for (i=0; i<n; ++i)
         if (t[i] == x) break; // tu jest

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
