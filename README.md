## Atividade LP I
## Command: g++ -std=c++11 -o programa main.cpp src/Astronauta.cpp src/Voo.cpp src/MenuFunctions.cpp

- Rever historico de voos dos astronatas mortos;
- Fazer verificações;
    - se o voo esta em planejameno ele não pode explodir
    - se o voo esta em curso não pode adicionar astronauta nele
    - se o voo foi finalizado sem sucesso ele nao pode ser mais acessado
    - se o voo esta finalizado com sucesso ele não pode explodir
    - se o voo está finalizado com 
- Criar class Gestao
    - Nela vai ter as lista de astronautas e voo
    - as funções sobre astronautas e voo para tirar as funções do MenuFunctions
- Implementar list ao inves de vector
- Implementear o map para mapear os astronautas pelo cpf