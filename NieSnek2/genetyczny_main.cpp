#include "genetyczny_main.h"

#include <iostream>
#include "genetyczny_result.h"
#include <conio.h>

#include <algorithm>    // std::sort
//#include <stdlib.h> //qsort


using namespace std;

bool myfunction (genetyczny_result* i,genetyczny_result* j) { return (i->Ocena > j->Ocena); }

genetyczny_main::genetyczny_main(){

}

vector<int> genetyczny_main::execute()
{


    cout << "Hello World!" << endl;
    vector<genetyczny_result*> a;
    vector<Uprawa> NowaUprawa;

    //a.push_back(new Result(Uprawa::Zyto, Uprawa::Pszenica, Uprawa::Kukurydza, Uprawa::Slonecznik));
    a.push_back(new genetyczny_result(Uprawa::Zyto, Uprawa::Zyto, Uprawa::Zyto, Uprawa::Zyto));
    a.push_back(new genetyczny_result(Uprawa::Pszenica, Uprawa::Pszenica, Uprawa::Pszenica, Uprawa::Pszenica));
    //a.push_back(new Result(Uprawa::Kukurydza, Uprawa::Kukurydza, Uprawa::Kukurydza, Uprawa::Kukurydza));
    a.push_back(new genetyczny_result(Uprawa::Slonecznik, Uprawa::Slonecznik, Uprawa::Slonecznik, Uprawa::Slonecznik));

    cout << "Uprawy\tPraca\tKoszt\tPrzychod\tOcena" << endl;

    sort(a.begin(), a.end(), myfunction );


    for(int i=0; i< a.size();i++){
        genetyczny_result* x = a[i];
        for(int j=0; j< x->lista.size(); j++){
            cout << x->lista[j];
        }
        cout << "\t" << x->Praca;
        cout << "\t" << x->Koszt;
        cout << "\t" << x->Przychod;
        cout << "\t\t" << x->Ocena;
        cout << endl;
    }




    for(int c=0; c <= 4; c++){
        cout << "\t\t-----------------------------------" << endl;

        for(int i=0; i<=5; i++){
            int x = rand()% a.size();
            int y = rand()% a.size();
            genetyczny_result* Rx = a[x];
            genetyczny_result* Ry = a[y];
            int punkt_krzyzowania = rand()%3; //0 oznacza przecięcie Ż|PKS, 1 oznacza przecięcie ŻP|KS, 2 oznacza przecięcie ŻPK|S.

            for(int a=0; a<=punkt_krzyzowania;a++){
                NowaUprawa.push_back(Rx->lista[a]);
            }
            for (int a=punkt_krzyzowania; a<=3;a++){
                NowaUprawa.push_back(Ry->lista[a]);
            }

            punkt_krzyzowania = rand()%100;
            while(punkt_krzyzowania<=5){
                int pozycja = rand()%4;
                int nowy = rand()%4;
                NowaUprawa[pozycja]=(Uprawa)nowy;
                punkt_krzyzowania = rand()%100;
            }
            a.push_back(new genetyczny_result(NowaUprawa));
            NowaUprawa.clear();
        }

        sort(a.begin(), a.end(), myfunction );

        for(int i=0; i< a.size();i++){
            genetyczny_result* x = a[i];
            for(int j=0; j< x->lista.size(); j++){
                cout << x->lista[j];
            }
            cout << "\t" << x->Praca;
            cout << "\t" << x->Koszt;
            cout << "\t" << x->Przychod;
            cout << "\t\t" << x->Ocena;
            cout << endl;
        }

        if(a.size()>=30) //max 21 elementów w liście najlepszych
            a.erase(a.begin()+30, a.end());
    }

    genetyczny_result* z = a[0];
    return vector<int> {(int)z->lista[0], (int)z->lista[1], (int)z->lista[2], (int)z->lista[3]};
}
