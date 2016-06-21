#ifndef GENETYCZNY_RESULT_H
#define GENETYCZNY_RESULT_H

#include <vector>

enum Uprawa
{
    Zyto=0, Pszenica=1, Kukurydza=2, Slonecznik=3
};


class genetyczny_result
{
public:
    genetyczny_result(Uprawa A, Uprawa B, Uprawa C, Uprawa D);
    genetyczny_result(std::vector<Uprawa> list);

    std::vector<Uprawa> lista;
    int Praca=0;
    int Koszt=0;
    int Przychod=0;
    int Ocena=0;

    //bool operator > (const Result& r) const
    //{
    //    return (Ocena < r.Ocena);
    //}
};





#endif // GENETYCZNY_RESULT_H
