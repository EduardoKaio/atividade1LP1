#include "../include/Gestao.hpp"
#include <cstdlib> 
#include <unistd.h> 
#include <iostream>
#include <map> 

using namespace std;

Gestao::Gestao() {}

bool Gestao::vooExiste(int codigoVoo) {
    return mapaVoos.find(codigoVoo) != mapaVoos.end();
}

bool Gestao::astronautaExiste(string cpf) {
    return mapaAstronautasCPF.find(cpf) != mapaAstronautasCPF.end();
}
void Gestao::cabeçalho(const string& titulo) {
    system("clear");
    cout << "===============================" << endl;
    cout << titulo << endl;
    cout << "===============================" << endl << endl;
}

int retornarAoMenu() {
    int choice;
    cout << "Deseja retornar ao Menu?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;
    
    if(choice == 1){
        cout << "Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return 1;
    } else if (choice == 2){
        system("clear");
        return 2;
    } else {
        cout << "Valor inválido.\nVoltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return 0;
    }
}


Astronauta& Gestao::obterAstronautaPorCPF(const string& cpf) {
    return mapaAstronautasCPF[cpf];
}

Voo& Gestao::obterVooPorCodigo(int codigoVoo) {
    return mapaVoos[codigoVoo];
}


void Gestao::cadastrarAstronauta() {
    system("clear");
    cabeçalho("Cadastro de Astronauta");
    string nome;
    string cpf;
    int idade;
    int choice;

    cout << "Digite o nome do astronauta: ";
    getline(cin >> ws, nome); 
    cout << "" << endl;

    cout << "Digite o CPF do astronauta: ";
    cin >> cpf;
    cin.ignore();
    cout << "" << endl;
    
    if (astronautaExiste(cpf)) {
        cout << "Já existe um astronauta cadastrado com o CPF fornecido." << endl;
        sleep(2);
        system("clear");
        return;
    }

    cout << "Digite a idade do astronauta: ";
    cin >> idade; 
    cout << "" << endl;
    
    Astronauta novoAstronauta(nome, cpf, idade); 

    astronautas.push_back(novoAstronauta); 
    mapaAstronautasCPF[cpf] = novoAstronauta; 

    cout << "Astronauta cadastrado com sucesso!" << endl;
    
    choice = retornarAoMenu();
    if(choice == 1){
        return;
    } else if (choice == 2){
        cadastrarAstronauta(); 
    } else {
        return;
    }
}


void Gestao::cadastrarVoo() {
    system("clear");
    cabeçalho("Cadastro de Voo");
    int codigo;
    int choice;
    cout << "Digite o código do voo: ";
    cin >> codigo;
    cout << "" << endl;
    
    if (vooExiste(codigo)) {
        cout << "Este código de voo já está em uso." << endl;
        return;
    } else {
        Voo voonovo(codigo); 
        voos.push_back(voonovo);
        mapaVoos[codigo] = Voo(codigo);
        cout << "Voo cadastrado com sucesso!" << endl;
    }
    
    choice = retornarAoMenu();
    if(choice == 1){
        return;
    } else if (choice == 2){
        Gestao::cadastrarVoo();
    } else {
        return;
    }
}

void Gestao::listarAstronautasMortos() {
    system("clear");
    cabeçalho("Lista de Astronautas Mortos");
    int choice;
    for (auto& astronauta : astronautas) {
        if (!astronauta.getVivo()) {
            cout << "Nome: " << astronauta.getNome() << ", CPF: " << astronauta.getCpf() 
                 << ", Idade: " << astronauta.getIdade() << ", Voos: ";
            
            vector<int> historicoDeVoos = astronauta.getHistoricoDeVoos();

            for (int j = 0; j < historicoDeVoos.size(); j++) {
                if (j == historicoDeVoos.size() - 1) {
                    cout << historicoDeVoos[j] << "";
                } else {
                    cout << historicoDeVoos[j] << ", ";
                }
            }
            cout << "" << endl;
        }
    }
}

void Gestao::adicionaAstronautaEmVoo() {
    system("clear");
    cabeçalho("Adicionar Astronauta em Voo");
    int codigo;
    string cpf;
    int choice;
    
    cout << "Digite o código do voo: ";
    cin >> codigo;
    cout << "" << endl;

    if (!vooExiste(codigo)) {
        cout << "Voo inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    }
    Voo& voo = obterVooPorCodigo(codigo);

    if (voo.getEstado() != 1) {
        cout << "Não é possível adicionar astronauta neste voo, pois ele não está em planejamento!" << endl;
        sleep(2);
        system("clear");
        return;
    }

    cout << "Digite o CPF do astronauta: ";
    cin >> cpf;
    cout << "" << endl;

    if (!astronautaExiste(cpf)) {
        cout << "CPF de astronauta inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    }

    Astronauta& astronauta = obterAstronautaPorCPF(cpf);
    
    if (!astronauta.getVivo()) {
        cout << "Não é possível adicionar esse astronauta em voo, pois ele está morto" << endl;
        sleep(2);
        system("clear");
        return;
    }

    astronauta.setCodigoVoo(codigo);

    voo.adicionarAstronauta(astronauta);
    cout << "O astronauta " << astronauta.getNome() 
        << " foi adicionado ao voo " << voo.getCodigo() 
        << " com sucesso!" << endl;
    choice = retornarAoMenu();
    if(choice == 1){
        return;
    } else if (choice == 2){
        adicionaAstronautaEmVoo();
    } else {
        return;
    }
}


void Gestao::removeAstronautaDoVoo() {
    system("clear");
    cabeçalho("Remove Astronauta em Voo");
    int codigo;
    string cpf;
    int posicao_voo;
    int choice;

    cout << "Digite o código do voo: ";
    cin >> codigo;
    cout << "" << endl;
    
    if (!vooExiste(codigo)) {
        cout << "Voo inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    }
    Voo& voo = obterVooPorCodigo(codigo);

    if (voo.getEstado() != 1) {
        cout << "Não é possível remover astronauta desse voo, pois ele não está em planejamento!" << endl;
        sleep(2);
        system("clear");
        return;
    }

    cout << "Digite o CPF do astronauta: ";
    cin >> cpf;
    cout << "" << endl;
        if (!astronautaExiste(cpf)) {
        cout << "CPF de astronauta inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    }
    Astronauta& astronauta = obterAstronautaPorCPF(cpf);

    
    astronauta.setCodigoVoo(codigo);
    voo.removerAstronauta(astronauta);
    cout << "O astronauta " << astronauta.getNome() 
        << " foi removido do voo " << voo.getCodigo() 
        << " com sucesso!" << endl;
    
    choice = retornarAoMenu();
    if(choice == 1){
        return;
    } else if (choice == 2){
        Gestao::removeAstronautaDoVoo();
    } else {
        return;
    }
}

void Gestao::listarVoos() {
    system("clear");

    cabeçalho("Lista de Voos");

    cout << "Planejamento: " << endl;
    for (auto& it : mapaVoos) {
        if (it.second.getEstado() == 1) {
            cout << "   Voo: " << it.first << endl;
            cout << "   Passageiros: " << endl;
            vector<Astronauta> passageiros = it.second.getPassageiros();
            for (int j = 0; j < passageiros.size(); j++) {
                cout << "       Nome: " << passageiros[j].getNome() << ", CPF: " << passageiros[j].getCpf() << ", Idade: " << passageiros[j].getIdade() << endl;
            }
        }
    }

    cout << " " << endl;
    cout << "Em Curso: " << endl;
    for (auto& it : mapaVoos) {
        if (it.second.getEstado() == 2) {
            cout << "   Voo: " << it.first << endl;
            cout << "   Passageiros: " << endl;
            vector<Astronauta> passageiros = it.second.getPassageiros();
            for (int j = 0; j < passageiros.size(); j++) {
                cout << "       Nome: " << passageiros[j].getNome() << ", CPF: " << passageiros[j].getCpf() << ", Idade: " << passageiros[j].getIdade()<< endl;;
            }
        }
    }

    cout << " " << endl;
    cout << "Finalizados com sucesso: " << endl;
    for (auto& it : mapaVoos) {
        if (it.second.getEstado() == 3) {
            cout << "   Voo: " << it.first << endl;
            cout << "   Passageiros: " << endl;
            vector<Astronauta> passageiros = it.second.getPassageiros();
            for (int j = 0; j < passageiros.size(); j++) {
                cout << "       Nome: " << passageiros[j].getNome() << ", CPF: " << passageiros[j].getCpf() << ", Idade: " << passageiros[j].getIdade()<< endl;;
            }
        }
    }

    cout << " " << endl;
    cout << "Finalizados sem sucesso: " << endl;
    for (auto& it : mapaVoos) {
        if (it.second.getEstado() == 4) {
            cout << "   Voo: " << it.first << endl;
            cout << "   Passageiros: " << endl;
            vector<Astronauta> passageiros = it.second.getPassageiros();
            for (int j = 0; j < passageiros.size(); j++) {
                cout << "       Nome: " << passageiros[j].getNome() << ", CPF: " << passageiros[j].getCpf() << ", Idade: " << passageiros[j].getIdade()<< endl;;
            }
        }
    }
}

void Gestao::lancarVoo() {
    system("clear");

    cabeçalho("Lançar Voo");

    int codigoVooLancado;
    int posicaoVoo;
    int choice;

    cout << "Digite o código do Voo: ";
    cin >> codigoVooLancado;
    cout << "" << endl;

    if (!vooExiste(codigoVooLancado)) {
        cout << "Voo inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    }

    Voo& voo = obterVooPorCodigo(codigoVooLancado);
    if (voo.getEstado() != 1) {
        cout << "Não é possível lançar este voo, pois ele não está em planejamento!" << endl;
        sleep(2);
        system("clear");
        return;
    }

    // Verifica a disponibilidade dos astronautas no voo
    bool todosDisponiveis = true;
    for (auto& astronauta : astronautas) {
        for (auto& passageiro : voo.getPassageiros()) {
            if (astronauta.getCpf() == passageiro.getCpf()){
                if (!astronauta.getDisponibilidade() || !astronauta.getVivo()) {
                    todosDisponiveis = false;
                    break; // Não há necessidade de verificar mais astronautas se um já estiver indisponível
                }
            }
        }
    }
    if (todosDisponiveis) {
        if (voo.getEstado() == 1 && voo.getPassageiros().size() >= 1) {
            voo.setEstado(2); // Altera o estado do voo para em curso
            cout << "Voo lançado com sucesso!" << endl;

            // Agora atualiza a disponibilidade dos astronautas na lista principal
            for (auto& astronauta : astronautas) {
                for (auto& passageiro : voo.getPassageiros()) {
                    if (astronauta.getCpf() == passageiro.getCpf()) {
                        astronauta.setDisponibilidade(false);
                        astronauta.addVooAoHistorio(voo.getCodigo());
                    }
                }
            }
        } else {
            cout << "Não é possível lançar este voo, pois ele não está em planejamento ou não possui a quantidade mínima de um passageiro." << endl;
        }
    } else {
        cout << "Não é possível lançar este voo, pois nele existem passageiros indisponíveis." << endl;
    }
}

void Gestao::explodirVoo() {
    system("clear");
    cabeçalho("Explodir Voo");
    int codigoVooLancado;

    cout << "Digite o código do Voo: ";
    cin >> codigoVooLancado;
    cout << "" << endl;

    if (!vooExiste(codigoVooLancado)) {
        cout << "Voo inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    }
    Voo& voo = obterVooPorCodigo(codigoVooLancado);

    if (voo.getEstado() != 2) {
        cout << "Não é possível explodir o voo pois ele não está em curso." << endl;
        sleep(2);
        system("clear");
        return;
    }
    cout << "****** Voo " << voo.getCodigo() << " explodido com sucesso! ******" << endl;
    voo.setEstado(4);

    for (auto& astronauta : astronautas) {
        for (auto& passageiro : voo.getPassageiros()) {
            if (astronauta.getCpf() == passageiro.getCpf()) {
                astronauta.setVivo(false);
            }
        }
    }
}


void Gestao::finalizarVoo() {
    
    system("clear");
    cabeçalho("Finalizar Voo");
    int codigoVooLancado;

    cout << "Digite o código do Voo: ";
    cin >> codigoVooLancado;
    cout << "" << endl;

    if (!vooExiste(codigoVooLancado)) {
        cout << "Voo inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    }
    Voo& voo = obterVooPorCodigo(codigoVooLancado);

    if (voo.getEstado() != 2) {
        cout << "Não é possível finalizar o voo pois ele não está em curso." << endl;
        sleep(2);
        system("clear");
        return;
    }
    cout << "Voo " << voo.getCodigo() << " finalizado com sucesso!" << endl;
    voo.setEstado(3);
    for (auto& astronauta : astronautas) {
        for (auto& passageiro : voo.getPassageiros()) {
            if (astronauta.getCpf() == passageiro.getCpf()) {
                astronauta.setDisponibilidade(true);
            }
        }
    }
    sleep(2);
    system("clear");       
}

void Gestao::listarAstronautas() {
    cabeçalho("Lista de Astronautas");

    cout << "Astronautas Vivos:" << endl;
    for (auto& astronauta : astronautas) {
        if (astronauta.getVivo()) {
            cout << "Nome: " << astronauta.getNome() << ", CPF: " << astronauta.getCpf() << ", Idade: " << astronauta.getIdade();
            if (astronauta.getDisponibilidade()) {
                cout << ", Disponibilidade: Disponível" << endl;
            } else {
                cout << ", Disponibilidade: Indisponível" << endl;
            }
        }
    }
    cout << endl << "Astronautas Mortos:" << endl;
    for (auto& astronauta : astronautas) {
        if (!astronauta.getVivo()) {
            cout << "Nome: " << astronauta.getNome() << ", CPF: " << astronauta.getCpf() << ", Idade: " << astronauta.getIdade() << ", Estado: Morto" << endl;
        }
    }
}