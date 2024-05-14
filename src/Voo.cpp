#include "../include/Voo.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Voo::Voo() {}

Voo::Voo(int codigo){
    this->codigo=codigo;
    this->estado=1;
}

void Voo::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Voo::getCodigo() {
    return codigo;
}
int Voo::getEstado() {
    return estado;
}

void Voo::setEstado(int novo_estado) {
    if(novo_estado == 1 || novo_estado == 2 || novo_estado == 3 || novo_estado == 4){
        estado = novo_estado;
    } else {
        std::cout << "Estado de Voo não cadastrado" << std::endl;
    }
}

void Voo::adicionarAstronauta(Astronauta astronauta) {
    passageiros.push_back(astronauta); // Adiciona o endereço do astronauta à lista
}

    // Método para remover um astronauta da lista de passageiros
void Voo::removerAstronauta(Astronauta astronauta) {
    passageiros.erase(std::remove_if(passageiros.begin(), passageiros.end(), 
        [&](const Astronauta& a) { return a.getCpf() == astronauta.getCpf(); }),
        passageiros.end());
}

vector<Astronauta> Voo::getPassageiros() {
    return passageiros;
}
