#include <iostream>
#include <iomanip>
using namespace std;

struct wezel
{
   double elem;
   wezel* lewy;
   wezel* prawy;
};


void wstaw (wezel*&d, double x)
{
   if(d==NULL)
   {
      d=new wezel;
      d->elem=x;
      d->lewy=NULL;
      d->prawy=NULL;
   }
   else if(x>d->elem)
      wstaw(d->prawy,x);
   else
      wstaw(d->lewy,x);
}


void kasujwszystko(wezel*&d)
{
   if(d==NULL)
      return;

   kasujwszystko(d->lewy);
   kasujwszystko(d->prawy);
   delete d;
   d=NULL;
}

void wypisz (wezel*d)
{
   if(d!=NULL)
   {
      wypisz(d->lewy);
      cout<<d->elem<<endl;
      wypisz(d->prawy);
   }
}

void wypisz2(wezel*d, int w=0)
{
   if(d!=NULL)
   {
      wypisz2(d->prawy, w+1); // najpierw prawy - rysunek obrocony
      for(int i=0; i<w; ++i)
         cout<<"  |";
      cout << setw(3) << d->elem << endl;
      wypisz2(d->lewy, w+1);
   }
}

int wysokosc(wezel*d)
{
   if(d==NULL)
      return 0;
   else
   {
      int hl=wysokosc(d->lewy);
      int hp=wysokosc(d->prawy);
      if(hl>hp)
            return (hl+1);
      else
            return (hp+1);
   }
}

int wypiszco2(wezel*w, int i=0)
{
   if(w==NULL)
      return i;
   else
   {
      i=wypiszco2(w->lewy, i);
      if(i%2==1)
         cout<<w->elem<<" ";
      ++i;
      return wypiszco2(w->prawy,i);
   }

}
bool kasujmax(wezel*&d, double x)
{
   if(d==NULL)
      return false;
   else if (d->prawy!=NULL)
      return kasujmax(d->prawy,x);
   else
   {
      if(d->elem!=x)
         return false;
      else {
         wezel*t=d;
         d=d->lewy;
         delete t;
         return true;
      }
   }


}
void usunpowt(wezel*&d)
{
   if(d==NULL) return;
   usunpowt(d->lewy);
   usunpowt(d->prawy);
   while(kasujmax(d->lewy,d->elem))
      ;

}


int main()
{
   wezel*korzen=NULL;
   wstaw(korzen, 14 );
   wstaw(korzen, 10 );
   wstaw(korzen, 17 );
   wstaw(korzen, 10 );
   wstaw(korzen, 10 );
   wstaw(korzen,  1 );
   wstaw(korzen, 20 );
   wstaw(korzen, 10 );
   wstaw(korzen, 11 );
   wstaw(korzen, 18 );

   cout << "Postac drzewa:" << endl;
   wypisz2(korzen);

   cout << endl;

   cout<<"Wysokosc: "<<wysokosc(korzen)<<endl;

   cout << endl;

   cout << "Wypisz_co_2:" << endl;
   cout<<wypiszco2(korzen,0)<<endl;

   cout << endl;

   cout << "Usuwam powtarzajace sie elementy:" << endl;
   usunpowt(korzen);
   wypisz(korzen);

   kasujwszystko(korzen);
   return 0;
}