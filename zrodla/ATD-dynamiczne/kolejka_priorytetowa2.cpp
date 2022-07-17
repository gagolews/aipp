#include <iostream>
#include <cassert>
using namespace std;

// -------------- kolejka_prior.h ------------------------

struct wezel
{
   int elem;     // element przechowywany w wê¼le
   wezel* lewy;  // wska¼nik na lewego potomka
   wezel* prawy; // wska¼nik na prawego potomka
};

void insert(int i, wezel*& pocz);
int  pull(wezel*& pocz);
bool empty(wezel* pocz);


// -------------- main.cpp ----------------------


int main()
{
   wezel* pocz = NULL; // puste drzewo (na pocz±tek)

   for (int i=0; i<20; ++i)
      insert((i*7+9)%17, pocz); // jakie¶ ró¿ne warto¶ci

   while (!empty(pocz))
      cout << pull(pocz) << ' ';

   return 0;
}


// ------------ kolejka_prior.cpp -------------------------

bool empty(wezel* pocz)
{
   return (pocz == NULL); // true, je¶li drzewo puste
}


void insert(int i, wezel*& pocz)
{
   // wstawianie na odpowiednie miejsce w drzewie
   // wersja rekurencyjna (o wiele prostsza ni¿ iteracyjna)

   if (pocz == NULL)        // gdy poddrzewo puste...
   {
      pocz = new wezel;     // stwórz li¶æ
      pocz->elem = i;
      pocz->lewy = NULL;
      pocz->prawy = NULL;
   }
   else if (i <= pocz->elem)
      insert(i, pocz->lewy);  // wstaw do lewego poddrzewa, bêdzie FIFO, gdy ==
   else
      insert(i, pocz->prawy); // wstaw do prawego poddrzewa

   // pesymistyczny koszt operacji: O(n), ¶redni: O(log n)
}


int pull(wezel*& pocz)
{
   assert(pocz != NULL); // na wszelki wypadek...

   // usuwanie "skrajnie prawego" li¶cia


   // wersja rekurencyjna:

   if (pocz->prawy == NULL) // wtedy to, co w pocz >= od wszystkiego, co w ca³ym poddrzewie
   {
      int i = pocz->elem;
      wezel* stary = pocz;
      pocz = pocz->lewy; // mo¿e byæ NULL
      delete stary;
      return i;
   }
   else
   {
      return pull(pocz->prawy);
   }

   // pesymistyczny koszt operacji: O(n), ¶redni: O(log n)




   // alternatywnie - wersja iteracyjna (dla porównania):

//    if (pocz->prawy == NULL) // wtedy to, co w pocz >= od wszystkiego, co w ca³ym poddrzewie
//    {
//       int i = pocz->elem;
//       wezel* stary = pocz;
//       pocz = pocz->lewy; // mo¿e byæ NULL
//       delete stary;
//       return i;
//    }
//    else
//    {
//       wezel* wsk = pocz;
//       while (wsk->prawy->prawy != NULL)
//          wsk = wsk->prawy;
//
//       // teraz wsk->prawy to najwiêkszy element w ca³ym drzewie
//
//       int i = wsk->prawy->elem;
//       wezel* stary = wsk->prawy;
//       wsk->prawy = wsk->prawy->lewy; // mo¿e byæ NULL
//       delete stary;
//       return i;
//    }
}
