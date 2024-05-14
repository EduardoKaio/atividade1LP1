#ifndef GESTAO_HPP
#define GESTAO_HPP

#include <vector>
#include <map> 
#include "Astronauta.hpp"
#include "Voo.hpp"
using namespace std;

class Gestao {
private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;
    map<string, Astronauta> mapaAstronautasCPF;
    map<int, Voo> mapaVoos;
    

public:

    Gestao();
    void cabeçalho(const string& titulo);
    // Métodos para astronautas
    Astronauta& obterAstronautaPorCPF(const string& cpf);
    bool astronautaExiste(string cpf); 
    void cadastrarAstronauta();
    void listarAstronautasMortos();
    void adicionaAstronautaEmVoo();
    void removeAstronautaDoVoo();
    void listarAstronautas();

    // Métodos para voos
    void cadastrarVoo();
    void listarVoos();
    void lancarVoo();
    void explodirVoo();
    void finalizarVoo();
    bool vooExiste(int codigoVoo);
    Voo& obterVooPorCodigo(int codigoVoo);

};

#endif // GESTAO_HPP