#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Voo {
    int codigo;
    int estado;
    // 1 - planejamento
    // 2 - em curso
    // 3 - finalziado
    public:
        Voo(int codigo){
            this->codigo=codigo;
            this->estado=1;
        }
        
        void setCodigo(int codigo) {
            this->codigo = codigo;
        }

        int getCodigo() {
            return codigo;
        }
        int getEstado() {
            return estado;
        }

        void setEstado(int novo_estado) {
            estado = novo_estado;
        }
    //cadastrar voo
    // adicionar astronauta no voo (codigo do voo e cpf do astronauta)
    // remover astronauta do voo (codigo do voo e cpf do astronauta)
};

class Astronauta {

    string cpf;
    string nome;
    int idade;
    bool vivo=true;
    int codigoVoo;
    bool disponibilidade=true;
    vector<Voo> voos;

    public:
        Astronauta(string nome, string cpf, int idade){
            this->nome = nome;
            this->cpf = cpf;
            this->idade = idade;
        };

        int getCodigoVoo(){
            return codigoVoo;
        }

        void setCodigoVoo(int codigoVoo){
            this->codigoVoo = codigoVoo;
        }

        string getNome(){
            return nome;
        }

        string getCpf(){
            return cpf;
        }

        int getIdade(){
            return idade;
        }

        // Métodos setters
        void setNome(string nome) {
            this->nome = nome;
        }

        void setCpf(string cpf) {
            this->cpf = cpf;
        }

        void setIdade(int idade) {
            this->idade = idade;
        }

    
};


class missaoEspacial{
    vector<Astronauta> listaPassageiros;
    Voo voo;
    
    public:

};

void cadastrarAstronauta(vector<Astronauta> &astronautas){
    string nome;
    string cpf;
    int idade;
    cout << "Digite o nome do astronauta:" << endl;
    cin >> nome;
    cout << "Digite o CPF do astronauta:" << endl;
    cin >> cpf;
    cout << "Digite a idade do astronauta:" << endl;
    cin >> idade; 
    astronautas.push_back(Astronauta(nome, cpf, idade));

};

void cadastrarVoo(vector<Voo> &voos){
    int codigo;
    cout << "Digite o código do voo:" << endl;
    cin >> codigo;
    voos.push_back(Voo(codigo));

}

void listarAstronautas(vector<Astronauta> &astronautas){
    cout << "NOME" << "      CPF" << "      IDADE" << endl;
    for (int i = 0; i < astronautas.size(); i++){
        cout << astronautas[i].getNome() << "   " << astronautas[i].getCpf() << "   " << astronautas[i].getIdade() << endl;
    }
}

void adicionaAstronautaEmVoo(vector<Astronauta> &astronautas, vector<Voo> &voos){
    int codigo;
    string cpf;
    bool verificacao=false;
    int posicao_voo;

    cout << "Digite o código do voo:" << endl;
    cin >> codigo;
    cout << "Digite o CPF do astronauta:" << endl;
    cin >> cpf;
    
    for (int i=0; i < voos.size(); i++){
        if(codigo==voos[i].getCodigo()){
            verificacao=true;
            posicao_voo=i;
        }
    }
    
    if(verificacao==false){
        cout << "Voo inexistente" << endl;
    } else {
        verificacao=false;
    }
    
    for (int j=0; j < astronautas.size(); j++){
        if(cpf==astronautas[j].getCpf()){
            verificacao=true;
            if(voos[posicao_voo].getEstado()==1){
                astronautas[j].setCodigoVoo(codigo);
                cout << "Astronauta adicionado com sucesso!" << endl;
            } else {
                cout << "O voo não está em planejamento" << endl;
            }
        }
    }
    if(verificacao==false){
        cout << "CPF inexistente" << endl;
    }
}

void removeAstronautaDoVoo(vector<Astronauta> &astronautas, vector<Voo> &voos){
    int codigo;
    string cpf;
    int posicao_voo;
    bool verificacao=false;
    cout << "Digite o código do voo:" << endl;
    cin >> codigo;
    cout << "Digite o CPF do astronauta:" << endl;
    cin >> cpf;
    
    for (int i=0; i < voos.size(); i++){
        if(codigo==voos[i].getCodigo()){
            verificacao=true;
            posicao_voo=i;
        }
    }
    
    if(verificacao==false){
        cout << "Voo inexistente" << endl;
    } else {
        verificacao=false;
    }
    
    for (int j=0; j < astronautas.size(); j++){
        if(cpf==astronautas[j].getCpf()){
            verificacao=true;
            if(voos[posicao_voo].getEstado()==1){
                astronautas[j].setCodigoVoo(codigo);
                cout << "Astronauta removido com sucesso!" << endl;
            } else {
                cout << "O voo não está em planejamento" << endl;
            }
        }
    }
    if(verificacao==false){
        cout << "CPF inexistente" << endl;
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
                break;
            case 5:
                
                break;
            case 6:
               
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                listarAstronautas(astronautas);
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