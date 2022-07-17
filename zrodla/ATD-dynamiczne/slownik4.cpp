#include <iostream>
#include <cassert>
using namespace std;

/* Implementacja ATD typu slownik - drzewo binarne
 * Jak zwykle zakladamy, ze w ATD przechowujemy pojedyncza zmienna typu int.
 */


// ---------- slownik.h ------------------------------------------

struct wezel
{
   int elem;     // przechowywany element
   wezel* lewy;  // lewy potomek
   wezel* prawy; // prawy potomek
};

bool search(int x, wezel* w);   // O(n) pesymistycznie, ale srednio O(log n)
void insert(int x, wezel*& w);  // O(n) pesymistycznie, ale srednio O(log n)
void remove(int x, wezel*& w);  // O(n) pesymistycznie, ale srednio O(log n)

void print(wezel* w);
void removeAll(wezel*& w);


// ---------- main.cpp ------------------------------------------

int main()
{
   wezel* korzen = NULL; // pusty slownik
   
   for (int i=0; i<10; ++i)
      insert((5*i+17)%13, korzen); // wstaw jakies wartosci

   print(korzen);

   for (int i=0; i<5; ++i)
      cout << i << ": " << search(i, korzen) << endl; // wyszukaj jakies wartosci

   for (int i=5; i<10; ++i)
      remove(i, korzen); // usun jakies wartosci

   print(korzen);

   removeAll(korzen);
   
   return 0;
}


// ---------- slownik.cpp ------------------------------------------

bool search(int x, wezel* w)
{
   if (w == NULL)         return false;
   else if (w->elem == x) return true;
   else if (w->elem < x)  return search(x, w->prawy);
   else                   return search(x, w->lewy);
}



void insert(int x, wezel*& w)
{
   if (w == NULL)
   {
      // wstaw tu
      w = new wezel;
      w->lewy = NULL;
      w->prawy = NULL;
      w->elem = x;
   }
   else if (w->elem == x)
      return; // element juz jest - nic nie rob
   else if (w->elem <  x)
      insert(x, w->prawy);
   else
      insert(x, w->lewy);
}



void remove(int x, wezel*& w)
{
   if (w == NULL)
      return; // nic nie rob
   else if (w->elem == x)
   {
      // to skasuj
      wezel* wstary = w;

      if (w->lewy != NULL) // ma lewego potomka
      {
         w = w->lewy; // zastap lewym

         // a co z ewentualnym prawym potomkiem i jego dziecmi?
         // musimy go doczepic jako "skrajnie" prawy lisc
         wezel* wsk = w;
         while (wsk->prawy != NULL)
            wsk = wsk->prawy;
         wsk->prawy = wstary->prawy;
      }
      else if (w->prawy != NULL) // ma prawego potomka, ale nie ma lewego
         w = w->prawy; // zastap prawym
      else // jest lisciem
         w = NULL;
      
      delete wstary;
   }
   else if (w->elem < x)
      remove(x, w->prawy);
   else
      remove(x, w->lewy);
}




void print_pomocnicza(wezel* w) // funkcja pomocnicza (dla ladniejszego formatowania)
{
   if (w == NULL) return;
   print_pomocnicza(w->lewy);
   cout << w->elem << " ";
   print_pomocnicza(w->prawy);
}


void print(wezel* w)
{
   cout << "{ ";
   print_pomocnicza(w);
   cout << "}" << endl;
}



void removeAll(wezel*& w)
{
   if (w == NULL) return; // nie ma czego usuwac

   // usun najpierw wszystkich potomkow
   removeAll(w->lewy); 
   removeAll(w->prawy);

   // usun sie
   delete w; 
   w = NULL;
}



