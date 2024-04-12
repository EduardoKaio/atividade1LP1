#include "Voo.hpp"
#include <iostream>

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

//cadastrar voo
// adicionar astronauta no voo (codigo do voo e cpf do astronauta)
// remover astronauta do voo (codigo do voo e cpf do astronauta)
