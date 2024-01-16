#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//informacao dos estudantes
struct Students {
    char nome[100];
    int idade;
    char morada [100];
};

void adicionar () {

};

void listar() {

};

int main() {
    setlocale(LC_ALL, "Portuguese");

    //menu console

    int menu = 0;

    do {
        //opcoes do menu
        printf("\n1-Adicionar Estudante\n2-Listar Estudantes\n3-Sair");

        //ler acao do usuario
        scanf("%d", &menu);

        //validar acao do usuário
        if(menu == 1) {
            adicionar();
        }
        if(menu == 2) {
            listar();
        }
    } while(menu != 3);
    printf("Programa encerrado!");
    

    return 0;
}