#ifndef VOO_HPP
#define VOO_HPP

class Voo {
    private:
        int codigo;
        int estado;
        // 1 - planejamento
        // 2 - em curso
        // 3 - finalziado com sucesso
        // 4 - finalizado sem sucesso
    
    public:
        Voo(int codigo);
        
        void setCodigo(int codigo);

        int getCodigo();

        int getEstado();

        void setEstado(int novo_estado);
        
    //cadastrar voo
    // adicionar astronauta no voo (codigo do voo e cpf do astronauta)
    // remover astronauta do voo (codigo do voo e cpf do astronauta)
};
#endif