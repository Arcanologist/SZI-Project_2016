#include "genetyczny_result.h"



genetyczny_result::genetyczny_result(Uprawa A, Uprawa B, Uprawa C, Uprawa D)
{

lista.push_back(A);
lista.push_back(B);
lista.push_back(C);
lista.push_back(D);

for(int i=0; i<=3; i++){
    if(lista[i] == Uprawa::Zyto){
        Praca+=40;
        Przychod+=10000;
    } else if (lista[i] == Uprawa::Pszenica){
        Praca+=30;
        Przychod+=7000;
    } else if (lista[i] == Uprawa::Kukurydza){
        Praca+=20;
        Przychod+=6000;
    } else if (lista[i] == Uprawa::Slonecznik){
        Praca+=10;
        Przychod+=4000;
    }
}

Koszt = Praca * Praca;
Ocena = Przychod - Koszt;


}

genetyczny_result::genetyczny_result(std::vector<Uprawa> list)
{
    lista.push_back(list[0]);
    lista.push_back(list[1]);
    lista.push_back(list[2]);
    lista.push_back(list[3]);


    for(int i=0; i<=3; i++){
        if(lista[i] == Uprawa::Zyto){
            Praca+=40;
            Przychod+=10000;
        } else if (lista[i] == Uprawa::Pszenica){
            Praca+=30;
            Przychod+=7000;
        } else if (lista[i] == Uprawa::Kukurydza){
            Praca+=20;
            Przychod+=6000;
        } else if (lista[i] == Uprawa::Slonecznik){
            Praca+=10;
            Przychod+=3000;
        }
    }

    Koszt = Praca * Praca;
    Ocena = Przychod - Koszt;

}
