#include "frota.h"
#include <string>
using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1) {
    this->veiculos.push_back(v1);
}

int Frota::numVeiculos() const {
    return this->veiculos.size();
}

int Frota::menorAno() const {
    int menor = 10000000;
    vector<Veiculo *>::const_iterator veic;
    if(numVeiculos() == 0)
        menor = 0;
    else
        //for(int i=0; i<veiculos.size(); i++)
        //    if(veiculos.at(i)->getAno() < menor)
        //        menor = veiculos.at(i)->getAno();
        for(veic = veiculos.begin(); veic < veiculos.end(); veic++){
            Veiculo* veiculo = *veic;
            if(veiculo->getAno() < menor)
                menor = veiculo->getAno();

        }
    return menor;
}