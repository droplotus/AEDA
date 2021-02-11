#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot), numMaximoClientes(nMaxCli) {
    vagas = lotacao;
}

unsigned int ParqueEstacionamento::getNumLugares() const {
    return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const {
    return numMaximoClientes;
}

bool ParqueEstacionamento::adicionaCliente(const string &nome) {
    if(clientes.size() == numMaximoClientes) return false;
    InfoCartao cliente = InfoCartao();
    cliente.nome = nome;
    cliente.presente = false;
    clientes.push_back(cliente);
    return true;
}

int ParqueEstacionamento::posicaoCliente(const string &nome) const {
    for(size_t i=0; i<clientes.size(); i++)
            if(clientes.at(i).nome == nome) return i;

    return -1;
}

bool ParqueEstacionamento::entrar(const string &nome) {
    for(size_t i=0; i<clientes.size(); i++)
        if(clientes.at(i).nome == nome && clientes.at(i).presente == false && vagas != 0){
            vagas--;
            clientes.at(i).presente = true;
            return true;
        }
    return false;
}

bool ParqueEstacionamento::retiraCliente(const string &nome) {
    for(size_t i=0; i<clientes.size(); i++)
        if(clientes.at(i).nome == nome && clientes.at(i).presente == false){
            clientes.erase(clientes.begin() + i);
            return true;
        }
    return false;
}

bool ParqueEstacionamento::sair(const string &nome) {
    for(size_t i=0; i<clientes.size(); i++)
        if(clientes.at(i).nome == nome && clientes.at(i).presente == true){
            vagas++;
            clientes.at(i).presente = false;
            return true;
        }
    return false;
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
    return clientes.size();
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
    return lotacao-vagas;
}