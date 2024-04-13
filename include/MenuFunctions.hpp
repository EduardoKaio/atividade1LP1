#ifndef MENU_FUNCTIONS_HPP
#define MENU_FUNCTIONS_HPP

#include <vector>
#include "Astronauta.hpp"
#include "Voo.hpp"

using namespace std;

void cadastrarAstronauta(vector<Astronauta> &astronautas);
void cadastrarVoo(vector<Voo> &voos);
void listarAstronautasMortos(vector<Astronauta> &astronautas);
void adicionaAstronautaEmVoo(vector<Astronauta> &astronautas, vector<Voo> &voos);
void removeAstronautaDoVoo(vector<Astronauta> &astronautas, vector<Voo> &voos);
void listarVoos(vector<Astronauta> &astronautas, vector<Voo> &voos);
void lancarVoo(vector<Astronauta> &astronautas, vector<Voo> &voos);
void explodirVoo(vector<Astronauta> &astronautas, vector<Voo> &voos);
void finalizarVoo(vector<Astronauta> &astronautas, vector<Voo> &voos);

#endif 