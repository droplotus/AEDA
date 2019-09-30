#include "veiculo.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a) {
    this->marca = mc;
    this->mes = m;
    this->ano = a;
}

string Veiculo::getMarca() const {
    return this->marca;
}

int Veiculo::getAno() const {
    return this->ano;
}

int Veiculo::info() const {
    cout << marca << endl << mes << endl << ano << endl;
    return 3;
}

Motorizado::Motorizado(string mc, int m, int a, string c, int cil) :Veiculo(mc, m, a){
    this->combustivel = c;
    this->cilindrada = cil;
}

int Motorizado::info() const {
    return 5;
}

int Automovel::info() const {
    Motorizado::info();
}

string Motorizado::getCombustivel() const {
    return this->combustivel;
}

Automovel::Automovel(string mc, int m, int a, string c, int cil) :Motorizado(mc, m, a, c, cil) {}

Camiao::Camiao(string mc, int m, int a, string c, int cil, int cm) :Motorizado(mc, m, a, c, cil){
    this->carga_maxima = cm;
}

int Camiao::info() const {
    return 6;
}

Bicicleta::Bicicleta(string mc, int m, int a, string t):Veiculo(mc, m, a) {
    this->tipo = t;
}

int Bicicleta::info() const {
    return 4;
}