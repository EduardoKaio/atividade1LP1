#include "../include/Astronauta.hpp"
using namespace std;

Astronauta::Astronauta() {}

Astronauta::Astronauta(string nome, string cpf, int idade){
    this->nome = nome;
    this->cpf = cpf;
    this->idade = idade;
}

int Astronauta::getCodigoVoo() const{ 
    return codigoVoo;
}

void Astronauta::setCodigoVoo(int codigoVoo){
    this->codigoVoo = codigoVoo;
}

string Astronauta::getNome() const{
    return nome;
}

string Astronauta::getCpf() const{
    return cpf;
}

int Astronauta::getIdade() const{
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
vector<int> Astronauta::getHistoricoDeVoos() { 
    return historicoDeVoos; 
}

void Astronauta::addVooAoHistorio(int codigoVoo){
    historicoDeVoos.push_back(codigoVoo);
}
