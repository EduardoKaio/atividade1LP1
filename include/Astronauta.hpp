#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
#include <vector>
#include "Voo.hpp"
using namespace std;


class Astronauta {
    private:
        string nome;
        string cpf;
        int idade;
        bool vivo=true;
        int codigoVoo;
        bool disponibilidade=true;
        vector<int> voos;

    public:
        Astronauta(string nome, string cpf, int idade);

        int getCodigoVoo();

        void setCodigoVoo(int codigoVoo);

        string getNome();

        string getCpf();
        vector<int> getHistoricoDeVoos();
        
        void addVooAoHistorio(int codigoVoo);
        
        bool getDisponibilidade();

        bool getVivo();

        int getIdade();

        void setNome(string nome);

        void setCpf(string cpf);

        void setIdade(int idade);
        void setDisponibilidade(bool disponivilidade);
        void setVivo(bool vivo);
};
#endif
