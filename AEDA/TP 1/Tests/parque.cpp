#include "parque.h"
#include <vector>

using namespace std;


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli): numMaximoClientes(nMaxCli), lotacao(lot) {
    vagas = lot;
}

unsigned int ParqueEstacionamento::getNumLugares() const { return lotacao; }
unsigned int ParqueEstacionamento::getNumMaximoClientes() const { return numMaximoClientes; }

int ParqueEstacionamento::posicaoCliente(const string &nome) const {
    int index = -1;
    for(int i=0; i<clientes.size(); i++)
        if (clientes.at(i).nome == nome)
            index = i;
    return index;
}

bool ParqueEstacionamento::adicionaCliente(const string &nome) {
    if(posicaoCliente(nome) != -1) return false;
    if(clientes.size() == numMaximoClientes) return false;
    InfoCartao clis = InfoCartao();
    clis.nome = nome;
    clis.presente = false;
    clientes.push_back(clis);
    return true;
}

bool ParqueEstacionamento::entrar(const string &nome) {
    if(posicaoCliente(nome) == -1) return false;
    if(clientes.at(posicaoCliente(nome)).presente) return false;
    if(vagas == 0) return false;
    vagas--;
    clientes.at(posicaoCliente(nome)).presente = true;
    return true;
}

bool ParqueEstacionamento::retiraCliente(const string &nome) {
    for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++){

        if((*it).nome == nome)
            if ((*it).presente == false){
                clientes.erase(it);
                return true;
            }
    }
    return false;
}

bool ParqueEstacionamento::sair(const string &nome) {
    if(posicaoCliente(nome) == -1) return false;
    if(!clientes.at(posicaoCliente(nome)).presente) return false;
    clientes.at(posicaoCliente(nome)).presente = false;
    vagas++;
    retiraCliente(nome);
    return true;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const { return lotacao - vagas; }
unsigned int ParqueEstacionamento::getNumClientesAtuais() const { return clientes.size(); }