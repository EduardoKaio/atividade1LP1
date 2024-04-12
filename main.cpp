#include <iostream>
#include <vector>
#include <string>
#include "Astronauta.hpp"
#include "Voo.hpp"

using namespace std;

void cadastrarAstronauta(vector<Astronauta> &astronautas){
    string nome;
    string cpf;
    int idade;
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
};

void cadastrarVoo(vector<Voo> &voos){
    int codigo;
    cout << "Digite o código do voo: ";
    cin >> codigo;
    cout << "" << endl;
    voos.push_back(Voo(codigo));
    cout << "Voo cadastrado com sucesso!" << endl;

}

void listarAstronautasMortos(vector<Astronauta> &astronautas){
    for (int i = 0; i < astronautas.size(); i++){
        if(astronautas[i].getVivo()==false){
            cout << "Nome: " << astronautas[i].getNome() << ", CPF: " << astronautas[i].getCpf() 
            << ", Idade: " << astronautas[i].getIdade() << ", Voos: ";
            
            vector<int> historicoDeVoos = astronautas[i].getHistoricoDeVoos();

            for (int j = 0; j < historicoDeVoos.size(); j++){
                cout << historicoDeVoos[j] << ", ";
                if(j==historicoDeVoos.size()-1){
                    cout << historicoDeVoos[j] << "";
                } else {
                    cout << historicoDeVoos[j] << ", ";
                }
            }
            cout << "" << endl;
        }
    }
}

void adicionaAstronautaEmVoo(vector<Astronauta> &astronautas, vector<Voo> &voos){
    int codigo;
    string cpf;
    bool verificacao=false;
    int posicao_voo;

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
        return;
    }
}

void removeAstronautaDoVoo(vector<Astronauta> &astronautas, vector<Voo> &voos){
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
        return;
    }
}

void listarVoos(vector<Astronauta> &astronautas, vector<Voo> &voos){
    
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

void lancarVoo(vector<Astronauta> &astronautas, vector<Voo> &voos){
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
        return;
    } else if(voos[posicaoVoo].getEstado() != 1){
        cout << "Voo não está disponível para lançamento" << endl;
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
        
        for (int j = 0; j < astronautas.size(); j++){
            if (astronautas[j].getCodigoVoo() == codigoVooLancado){
                astronautas[j].setDisponibilidade(false);
                astronautas[j].addVooAoHistorio(codigoVooLancado);
            }    
        }
    } else {
        cout << "Não é possível lançar este Voo";
    }
}

void explodirVoo(vector<Astronauta> &astronautas, vector<Voo> &voos){
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
        return;
    } else {
        cout << "Voo " << voos[posicaoVoo].getCodigo() << " explodido com sucesso!" << endl;
        for (int j = 0; j < astronautas.size(); j++){
            if (astronautas[j].getCodigoVoo() == codigoVooLancado){
                astronautas[j].setVivo(false);

            }    
        }
    } 
}

void finalizarVoo(vector<Astronauta> &astronautas, vector<Voo> &voos){
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
        return;
    } else {
        cout << "Voo " << voos[posicaoVoo].getCodigo() << " finalizado com sucesso!" << endl;
        for (int j = 0; j < astronautas.size(); j++){
            if (astronautas[j].getCodigoVoo() == codigoVooLancado){
                astronautas[j].setDisponibilidade(true);
            }    
        }
    } 
}

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