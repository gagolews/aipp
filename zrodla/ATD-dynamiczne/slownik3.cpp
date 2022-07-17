#include <iostream>
#include <cassert>
using namespace std;

/* Implementacja ATD typu slownik - lista jednokierunkowa
 * Wszystkie operacje O(n) (i nie da siê lepiej - lista nie zapewnia
 * bezpo¶redniego dostêpu do elementu o zadanym indeksie, tak jak tablica)
 * Jak zwykle zakladamy, ze w ATD przechowujemy pojedyncza zmienna typu int.
 */


// ---------- slownik.h ------------------------------------------

struct wezel
{
   int elem; // przechowywany element
   wezel* nast; // nastepnik
};

bool search(int x, wezel* w);   // O(n)
void insert(int x, wezel*& w);  // O(n)
void remove(int x, wezel*& w);  // O(n)

void print(wezel* w);
void removeAll(wezel*& w);


// ---------- main.cpp ------------------------------------------

int main()
{
   wezel* glowa = NULL; // pusty slownik
   
   for (int i=0; i<10; ++i)
      insert((5*i+17)%13, glowa); // wstaw jakies wartosci

   print(glowa);      

   for (int i=0; i<5; ++i)
      cout << i << ": " << search(i, glowa) << endl; // wyszukaj jakies wartosci

   for (int i=5; i<10; ++i)
      remove(i, glowa); // usun jakies wartosci

   print(glowa);

   removeAll(glowa);
   
   return 0;
}


// ---------- slownik.cpp ------------------------------------------

bool search(int x, wezel* w)
{
   if (w == NULL) return false;
   else if (w->elem == x) return true;
   else return search(x, w->nast);
}



void insert(int x, wezel*& w)
{
   // gdyby w slowniku nie mogly wystepowac duplikaty,
   // bylaby to operacja O(1) - wstawianie na poczatek.
   // Niestety musimy isc na koniec listy...

   if (w == NULL)
   {
      // wstaw tu
      w = new wezel;
      w->nast = NULL;
      w->elem = x;
   }
   else if (w->elem == x)
      return; // element juz jest - nic nie rob
   else
      insert(x, w->nast); // wstaw dalej
}



void remove(int x, wezel*& w)
{
   if (w == NULL) return; // nic nie rob
   else if (w->elem == x)
   {
      // to skasuj
      wezel* wstary = w;
      w = w->nast;
      delete wstary;
      // koniec
   }
   else remove(x, w->nast); // szukaj dalej
}




void print(wezel* w)
{
   cout << "{ ";
   while (w != NULL)
   {
      cout << w->elem << " ";
      w = w->nast;
   }
   cout << "}" << endl;
}



void removeAll(wezel*& w)
{
   if (w == NULL) return; // nie ma czego usuwac

   removeAll(w->nast); // usun najpierw wszystkie nastepniki
   
   delete w; // usun sie
   w = NULL;
}



