#include <iostream>
#include <vector>
#include <string>
#include "include/Astronauta.hpp"
#include "include/Voo.hpp"
#include "include/MenuFunctions.hpp"

using namespace std;

int main(){
    vector<Astronauta> astronautas;
    vector<Voo> voos;
    int choice;

    do {
        cout << "=== Menu ===" << endl;
        cout << "1. Cadastrar Astronauta" << endl;
        cout << "2. Cadastrar Voo" << endl;
        cout << "3. Adicionar Astronauta em Voo" << endl;
        cout << "4. Remover Astronauta de um Voo" << endl;
        cout << "5. Lançar um voo" << endl;
        cout << "6. Explodir Voo" << endl;
        cout << "7. Finalizar um voo" << endl;
        cout << "8. Listar todos os voos" << endl;
        cout << "9. Listar todos os astronautas mortos" << endl;

        cout << "0. Sair" << endl;

        printf("Escolha uma opcao: ");
        cin >> choice;

        switch (choice) {
            case 1:
                cadastrarAstronauta(astronautas);
                break;
            case 2:
                cadastrarVoo(voos);
                break;
            case 3:
                adicionaAstronautaEmVoo(astronautas, voos);
                break;
            case 4:
                removeAstronautaDoVoo(astronautas, voos);
                break;
            case 5:
                lancarVoo(astronautas, voos);
                break;
            case 6:
                explodirVoo(astronautas, voos);
                break;
            case 7:
                finalizarVoo(astronautas, voos);
                break;
            case 8:
                listarVoos(astronautas, voos);
                break;
            case 9:
                listarAstronautasMortos(astronautas);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }

    } while (choice != 0);
    return 0;
}