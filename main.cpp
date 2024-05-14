#include <iostream>
#include <vector>
#include <string>
#include "include/Astronauta.hpp"
#include "include/Voo.hpp"
#include "include/Gestao.hpp" 

using namespace std;

int main(){
    Gestao gestao;
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
        cout << "10. Listar todos os astronauta" << endl;

        cout << "0. Sair" << endl;

        printf("Escolha uma opcao: ");
        cin >> choice;

        switch (choice) {
            case 1:
                gestao.cadastrarAstronauta();
                break;
            case 2:
                gestao.cadastrarVoo();
                break;
            case 3:
                gestao.adicionaAstronautaEmVoo();
                break;
            case 4:
                gestao.removeAstronautaDoVoo();
                break;
            case 5:
                gestao.lancarVoo();
                break;
            case 6:
                gestao.explodirVoo();
                break;
            case 7:
                gestao.finalizarVoo();
                break;
            case 8:
                gestao.listarVoos();
                break;
            case 9:
                gestao.listarAstronautasMortos();
                break;
            case 10:
                gestao.listarAstronautas();
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