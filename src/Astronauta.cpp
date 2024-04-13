#include "../include/Astronauta.hpp"
using namespace std;

Astronauta::Astronauta(string nome, string cpf, int idade){
    this->nome = nome;
    this->cpf = cpf;
    this->idade = idade;
}

int Astronauta::getCodigoVoo(){
    return codigoVoo;
}

void Astronauta::setCodigoVoo(int codigoVoo){
    this->codigoVoo = codigoVoo;
}

string Astronauta::getNome(){
    return nome;
}

string Astronauta::getCpf(){
    return cpf;
}

int Astronauta::getIdade(){
    return idade;
}

// Métodos setters
void Astronauta::setNome(string nome) {
    this->nome = nome;
}

void Astronauta::setCpf(string cpf) {
    this->cpf = cpf;
}

void Astronauta::setIdade(int idade) {
    this->idade = idade;
}

bool Astronauta::getDisponibilidade(){
    return disponibilidade;
}

void Astronauta::setDisponibilidade(bool disponibilidade){
    this->disponibilidade=disponibilidade;
}

bool Astronauta::getVivo(){
    return vivo;
}

void Astronauta::setVivo(bool vivo){
    this->vivo=vivo;
}
vector<int> Astronauta::getHistoricoDeVoos(){
    return voos;
};

void Astronauta::addVooAoHistorio(int codigoVoo){
    this->voos.push_back(codigoVoo);
}
