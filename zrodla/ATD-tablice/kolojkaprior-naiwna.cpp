#include <iostream>
#include <cassert>
using namespace std;


struct Data
{
   int dzien;
   int miesiac;
};


void wypiszData(Data d)
{
   cout << d.dzien << "." << d.miesiac << endl;
}


Data tworzData(int dzien, int miesiac)
{
   Data nowa;
   nowa.dzien = dzien;
   nowa.miesiac = miesiac;
   return nowa;
}


bool czyMniejszeRowne(Data d1, Data d2)
{
   if (d1.miesiac < d2.miesiac) return true;
   else if (d1.miesiac == d2.miesiac)
   {
      if (d1.dzien <= d2.dzien) return true;
      else return false;
   }
   else return false;
}



// IMPLEMENENTACJA PIERWSZA (NAJGORSZA)

struct KolejkaPriorytetowa {
   Data* elem;
   int n;
};

KolejkaPriorytetowa* tworzKolejkePriorytowa()
{
   KolejkaPriorytetowa* kolejka = new KolejkaPriorytetowa;

   //(*kolejka).n = 0;
   kolejka->n = 0;
   kolejka->elem = NULL;

   return kolejka;
}

void kasujKolejkePriorytetowa(KolejkaPriorytetowa* kolejka)
{
   if (kolejka->elem != NULL)
      delete [] kolejka->elem;
   delete kolejka;
}


bool empty(KolejkaPriorytetowa* kolejka)
{
   //return (kolejka->n == 0);
   return (kolejka->elem == NULL);
}


void insert(KolejkaPriorytetowa* kolejka, Data m)
{
   if (empty(kolejka))
   {
      kolejka->elem = new Data[1];
      kolejka->elem[0] = m;
      kolejka->n = 1;
   }
   else
   {
      Data* tab = new Data[kolejka->n + 1];

      // kopiowanie
      int i=0;
      for (; i<kolejka->n; ++i)
      {
         if (czyMniejszeRowne(kolejka->elem[i], m))
            tab[i] = kolejka->elem[i];
         else {
            tab[i] = m;
            break;
         }
      }
      for (; i<kolejka->n; ++i)
      {
         tab[i+1] = kolejka->elem[i];
      }

      if (czyMniejszeRowne(kolejka->elem[kolejka->n-1], m))
         tab[kolejka->n] = m;

      kolejka->n++;
      delete [] kolejka->elem;
      kolejka->elem = tab;
   }
}

Data pull(KolejkaPriorytetowa* kolejka)
{
   assert(!empty(kolejka));
   Data w = kolejka->elem[0];
   if (kolejka->n == 1)
   {
      kolejka->n = 0;
      delete [] kolejka->elem;
      kolejka->elem = NULL;
   }
   else
   {
      Data* tab = new Data[kolejka->n - 1];

      // kopiowanie
      for (int i=0; i<kolejka->n - 1; i++)
         tab[i] = kolejka->elem[i+1];

      kolejka->n--;
      delete [] kolejka->elem;
      kolejka->elem = tab;
   }
   return w;
}



int main()
{
   KolejkaPriorytetowa* k = tworzKolejkePriorytowa();

   insert(k, tworzData(1,1));
   insert(k, tworzData(31,12));
   insert(k, tworzData(4,10));
   insert(k, tworzData(6,10));

   while (!empty(k))
      wypiszData(pull(k));

   kasujKolejkePriorytetowa(k);

   return 0;
}

