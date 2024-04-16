#include <iostream>
#include "../include/MenuFunctions.hpp"
#include <cstdlib> 
#include <unistd.h> 
using namespace std;

void cadastrarAstronauta(vector<Astronauta> &astronautas) {
    system("clear");
    string nome;
    string cpf;
    int idade;
    int choice;
    cout << "Digite o nome do astronauta: ";
    cin >> nome;
    cout << "" << endl;
    
    cout << "Digite o CPF do astronauta: ";
    cin >> cpf;
    cout << "" << endl;
    
    cout << "Digite a idade do astronauta: ";
    cin >> idade; 
    cout << "" << endl;
    
    astronautas.push_back(Astronauta(nome, cpf, idade));
    cout << "Astronauta cadastrado com sucesso!" << endl;
    
    cout << "Deseja retornar ao Menu?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;
    if(choice == 1){
            sleep(2);
            cout << "Voltando ao Menu Principal..." << endl;
            system("clear");
            return;
        } else if (choice == 2){
            system("clear");
            cadastrarAstronauta(astronautas);
        } else {
            cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
            sleep(2);
            system("clear");
            return;
        }
}

void cadastrarVoo(vector<Voo> &voos) {
    system("clear");
    int codigo;
    int choice;
    cout << "Digite o código do voo: ";
    cin >> codigo;
    cout << "" << endl;
    voos.push_back(Voo(codigo));
    cout << "Voo cadastrado com sucesso!" << endl;
    cout << "Deseja retornar ao Menu?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;
    if(choice == 1){
            system("clear");
            cout << "Voltando ao Menu Principal... << endl";
            sleep(2);
            system("clear");
            return;
        } else if (choice == 2){
            system("clear");
            cadastrarVoo(voos);
        } else {
            cout << "Valor inválido.\nVoltando ao Menu Principal..." << endl;
            sleep(2);
            system("clear");
            return;
        }
}

void listarAstronautasMortos(vector<Astronauta> &astronautas) {
    system("clear");
    int choice;
    for (int i = 0; i < astronautas.size(); i++){
        if(astronautas[i].getVivo()==false){
            cout << "Nome: " << astronautas[i].getNome() << ", CPF: " << astronautas[i].getCpf() 
            << ", Idade: " << astronautas[i].getIdade() << ", Voos: ";
            
            vector<int> historicoDeVoos = astronautas[i].getHistoricoDeVoos();

            for (int j = 0; j < historicoDeVoos.size(); j++){
                if(j==historicoDeVoos.size()-1){
                    cout << historicoDeVoos[j] << "";
                } else {
                    cout << historicoDeVoos[j] << ", ";
                }
            }
            cout << "" << endl;
        }
    }
    cout << "Deseja retornar ao Menu?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;
    if(choice == 1){
            system("clear");
            cout << "Voltando ao Menu Principal... << endl";
            sleep(2);
            system("clear");
            return;
        } else if (choice == 2){
            system("clear");
            listarAstronautasMortos(astronautas);
        } else {
            cout << "Valor inválido.\nVoltando ao Menu Principal..." << endl;
            sleep(2);
            system("clear");
            return;
        }
}

void adicionaAstronautaEmVoo(vector<Astronauta> &astronautas, vector<Voo> &voos) {
    system("clear");
    int codigo;
    string cpf;
    bool verificacao=false;
    int posicao_voo;
    int choice;
    
    cout << "Digite o código do voo: ";
    cin >> codigo;
    cout << "" << endl;
    for (int i=0; i < voos.size(); i++){
        if(codigo==voos[i].getCodigo()){
            verificacao=true;
            posicao_voo=i;
        }
    }
    
    if(verificacao==false){
        cout << "Voo inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    } else {
        verificacao=false;
    }
    cout << "Digite o CPF do astronauta:" << endl;
    cin >> cpf;
    
    for (int j=0; j < astronautas.size(); j++){
        if(cpf==astronautas[j].getCpf()){
            verificacao=true;
            if(voos[posicao_voo].getEstado()==1){
                astronautas[j].setCodigoVoo(codigo);
                cout << "O astronauta " << astronautas[j].getNome() 
                << " foi adicionado ao voo " << voos[posicao_voo].getCodigo() 
                << " com sucesso!" << endl;
            } else {
                cout << "O voo não está em planejamento!" << endl;
            }
        }
    }
    if(verificacao==false){
        cout << "CPF inexistente!" << endl;
        sleep(2);
        system("clear");
        return;
    }
    cout << "Deseja retornar ao Menu?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;
    if(choice == 1){
            system("clear");
            cout << "Voltando ao Menu Principal... << endl";
            sleep(2);
            system("clear");
            return;
        } else if (choice == 2){
            system("clear");
            adicionaAstronautaEmVoo(astronautas, voos);
        } else {
            cout << "Valor inválido.\nVoltando ao Menu Principal..." << endl;
            sleep(2);
            system("clear");
            return;
        }
}

void removeAstronautaDoVoo(vector<Astronauta> &astronautas, vector<Voo> &voos) {
    system("clear");
    int codigo;
    string cpf;
    int posicao_voo;
    bool verificacao=false;
    cout << "Digite o código do voo: ";
    cin >> codigo;
    cout << "" << endl;
    for (int i=0; i < voos.size(); i++){
        if(codigo==voos[i].getCodigo()){
            verificacao=true;
            posicao_voo=i;
        }
    }
    
    if(verificacao==false){
        cout << "Voo inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    } else {
        verificacao=false;
    }

    cout << "Digite o CPF do astronauta: ";
    cin >> cpf;
    cout << "" << endl;
    
    for (int j=0; j < astronautas.size(); j++){
        if(cpf==astronautas[j].getCpf()){
            verificacao=true;
            if(voos[posicao_voo].getEstado()==1){
                astronautas[j].setCodigoVoo(0);
                cout << "O astronauta " << astronautas[j].getNome() 
                << " foi removido do voo " << voos[posicao_voo].getCodigo() 
                << " com sucesso!" << endl;
            } else {
                cout << "O voo não está em planejamento" << endl;
            }
        }
    }
    if(verificacao==false){
        cout << "CPF inexistente!" << endl;
        sleep(2);
        system("clear");
        return;
    }
    sleep(2);
    system("clear");
}

void listarVoos(vector<Astronauta> &astronautas, vector<Voo> &voos) {
    system("clear");
    cout << "Planejamento: " << endl;
    for (int i = 0; i < voos.size(); i++){
        
        if(voos[i].getEstado()==1){
            cout << "   Voo: " << voos[i].getCodigo()<< endl;
            cout << "   Passageiros: " << endl;
            
            for (int j = 0; j < astronautas.size(); j++){
                if(astronautas[j].getCodigoVoo() == voos[i].getCodigo()){
                    cout << "       " << astronautas[j].getNome() << ", " << astronautas[j].getCpf() << ", " << astronautas[j].getIdade() << endl;
                }        
            }
        }
    }
    cout << " " << endl;
    cout << "Em Curso: " << endl;
    for (int i = 0; i < voos.size(); i++){
        
        if(voos[i].getEstado()==2){
            cout << "   Voo: " << voos[i].getCodigo()<< endl;
            cout << "   Passageiros: " << endl;
            
            for (int j = 0; j < astronautas.size(); j++){
                if(astronautas[j].getCodigoVoo() == voos[i].getCodigo()){
                    cout << "       " << astronautas[j].getNome() << ", " << astronautas[j].getCpf() << ", " << astronautas[j].getIdade() << endl;
                }        
            } 
        }
    }
    cout << " " << endl;
    cout << "Finalizados com sucesso: " << endl;
    for (int i = 0; i < voos.size(); i++){
        
        if(voos[i].getEstado()==3){
            cout << "   Voo: " << voos[i].getCodigo()<< endl;
            cout << "   Passageiros: " << endl;
            
            for (int j = 0; j < astronautas.size(); j++){
                if(astronautas[j].getCodigoVoo() == voos[i].getCodigo()){
                    cout << "       " << astronautas[j].getNome() << ", " << astronautas[j].getCpf() << ", " << astronautas[j].getIdade() << endl;
                }        
            }
        }
    }
    cout << " " << endl;

    cout << "Finalizados sem sucesso: " << endl;
    for (int i = 0; i < voos.size(); i++){
        
        if(voos[i].getEstado()==4){
            cout << "   Voo: " << voos[i].getCodigo()<< endl;
            cout << "   Passageiros: " << endl;
            
            for (int j = 0; j < astronautas.size(); j++){
                if(astronautas[j].getCodigoVoo() == voos[i].getCodigo()){
                    cout << "       " << astronautas[j].getNome() << ", " << astronautas[j].getCpf() << ", " << astronautas[j].getIdade() << endl;
                }        
            }
        }
    }

}

void lancarVoo(vector<Astronauta> &astronautas, vector<Voo> &voos) {
    system("clear");
    int codigoVooLancado;
    int posicaoVoo;
    int qtdPassageiros=0;
    bool disponibilidadePassageiros=true;
    bool verificacao=false;

    cout << "Digite o código do Voo: ";
    cin >> codigoVooLancado;
    cout << " " << endl;

    for (int i = 0; i < voos.size(); i++){
        if(voos[i].getCodigo() == codigoVooLancado){
            verificacao=true;
            posicaoVoo=i;
        }
    }
    if (verificacao == false){
        cout << "Código de Voo inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    } else if(voos[posicaoVoo].getEstado() != 1){
        cout << "Voo não está disponível para lançamento" << endl;
        sleep(2);
        system("clear");
        return;
    } else {
        for (int j = 0; j < astronautas.size(); j++){
            if (astronautas[j].getCodigoVoo() == codigoVooLancado){
                qtdPassageiros++;
                if(astronautas[j].getDisponibilidade()==false){
                    disponibilidadePassageiros=false;
                }
            }    
        }
        
    } 
    
    if (qtdPassageiros >=1 && disponibilidadePassageiros==true){
        voos[posicaoVoo].setEstado(2);
        cout << "Voo lançado com sucesso!" << endl;
        for (int j = 0; j < astronautas.size(); j++){
            if (astronautas[j].getCodigoVoo() == codigoVooLancado){
                astronautas[j].setDisponibilidade(false);
                astronautas[j].addVooAoHistorio(codigoVooLancado);
            }    
        }
        sleep(2);
        system("clear");
    } else {
        cout << "Não é possível lançar este Voo" << endl;
        sleep(2);
        system("clear");
    }
}

void explodirVoo(vector<Astronauta> &astronautas, vector<Voo> &voos) {
    system("clear");
    int codigoVooLancado;
    int posicaoVoo;
    bool verificacao=false;

    cout << "Digite o código do Voo: ";
    cin >> codigoVooLancado;
    cout << "" << endl;

    for (int i = 0; i < voos.size(); i++){
        if(voos[i].getCodigo() == codigoVooLancado){
            verificacao=true;
            voos[i].setEstado(4);
            posicaoVoo=i;
        }
    }
    if (verificacao == false){
        cout << "Código de Voo inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    } else {
        cout << "Voo " << voos[posicaoVoo].getCodigo() << " explodido com sucesso!" << endl;
        for (int j = 0; j < astronautas.size(); j++){
            if (astronautas[j].getCodigoVoo() == codigoVooLancado){
                astronautas[j].setVivo(false);

            }    
        }
        sleep(2);
        system("clear");
    } 
}

void finalizarVoo(vector<Astronauta> &astronautas, vector<Voo> &voos) {
    system("clear");
    int codigoVooLancado;
    int posicaoVoo;
    bool verificacao=false;

    cout << "Digite o código do Voo: ";
    cin >> codigoVooLancado;
    cout << "" << endl;

    for (int i = 0; i < voos.size(); i++){
        if(voos[i].getCodigo() == codigoVooLancado){
            verificacao=true;
            posicaoVoo=i;
        }
    }
    if (verificacao == false){
        cout << "Código de Voo inexistente" << endl;
        sleep(2);
        system("clear");
        return;
    } else {
        cout << "Voo " << voos[posicaoVoo].getCodigo() << " finalizado com sucesso!" << endl;
        for (int j = 0; j < astronautas.size(); j++){
            if (astronautas[j].getCodigoVoo() == codigoVooLancado){
                astronautas[j].setDisponibilidade(true);
            }    
        }
        sleep(2);
        system("clear");
    } 
}