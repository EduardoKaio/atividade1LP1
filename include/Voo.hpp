#ifndef VOO_HPP
#define VOO_HPP
#include <vector> // Inclua isso para usar std::vector
#include "Astronauta.hpp"
using namespace std;
class Astronauta;

class Voo {
    private:
        int codigo;
        int estado;
        vector<Astronauta> passageiros;
        // 1 - planejamento
        // 2 - em curso
        // 3 - finalziado com sucesso
        // 4 - finalizado sem sucesso
    
    public:
        Voo();
        Voo(int codigo);
        
        void setCodigo(int codigo);

        int getCodigo();

        int getEstado();

        void setEstado(int novo_estado);

        void adicionarAstronauta(Astronauta astronauta);

        // Função para remover astronauta
        void removerAstronauta(Astronauta astronauta);

        // Função para obter lista de passageiros
        vector<Astronauta> getPassageiros();
        
    //cadastrar voo
    // adicionar astronauta no voo (codigo do voo e cpf do astronauta)
    // remover astronauta do voo (codigo do voo e cpf do astronauta)
};
#endif