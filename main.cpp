#include <iostream>
#include <fstream>

using namespace std;

ifstream in("suma.in");
ofstream out("suma.out");

int main()
{
    int monede[100], nr_monede, i,sortat, schimb,suma;

//citim ]n fisier numarul de monede si suma
    in>>nr_monede>>suma;

// citim valoarea monedelor cu care se va restitui suma ce trebuie returnata
    for(i=1; i<=nr_monede; i++)
        in>>monede[i];

//utilizand o metoda se sortare se sorteaza monedele in ordine descrescatoare
    do
    {
        sortat = 0;
        for(i = 1; i<nr_monede; i++ )
            if(monede[i]<monede[i+1])
            {
            schimb = monede[i];
            monede[i] = monede[i+1];
            monede[i+1] = schimb;
        sortat = 1;
    }
    }

    while (sortat == 1);
    i = 1;

//utilizam metoda Greedy pentru calcularea numarului de monezi restituite
    while(suma!=0)
    {
        if (suma/monede[i])
        {
            out<<"-------------------------"<<endl;
            out<<monede[i]<<'x'<<suma/monede[i]<<'='<<monede[i]*(suma/monede[i])<<'\n';
            suma = suma % monede[i];
        }
        i++;
    }
    in.close();
    out.close();

    return 0;
}
