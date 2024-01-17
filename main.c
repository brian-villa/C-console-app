#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//informacao dos estudantes
struct Estudantes {
    char nome[100];
    int idade;
    int ano; // ano em que está a cursar ativo // formado ou ainda estudante
};

//funcao que adiciona dados ao arquivo
void adicionar() {

    struct Estudantes studen; // cria um ocorencia do objt em RAM

    FILE *Open;
    Open = fopen("file.dat", "rb+");

    if(!Open) { //se o ficheiro não existir
        Open = fopen("file.dat", "wb");
        fclose(Open);
        Open = fopen("file.dat", "rb+");
    };

    //Preencher informacoes
    printf("Digite o nome do estudante:");
    gets(studen.nome);

    printf("Digite a idade deste estudante:");
    scanf("%d", &studen.idade);
    fgetc(stdin);

    printf("Digite o ano de ingresso do estudante:");
    scanf("%d", &studen.ano);
    fgetc(stdin);

    //fim do ficheiro
    fseek(Open, 0, SEEK_END);

    //RAM para ficheiro
    fwrite(&studen, sizeof(struct Estudantes), 1, Open);
    fclose(Open);
};

//funcao que lista os dados em console
void  listar() {
    struct Estudantes studen;
    FILE *Open;
    Open = fopen("file.dat", "rb");

    if(Open) {

        //se o ficheiro existe, listar

        fseek(Open, 0, SEEK_SET);

        int naoSei = 0; //enquanto existem registros

        printf("Nome \tIdade\tAno\n");

        while(!naoSei) {
            
            fread(&studen, sizeof(struct Estudantes), 1, Open);

            if(feof(Open)) naoSei=1;

            else {
                printf("%s\t%d\t%d\n",
                studen.nome,
                studen.idade,
                studen.ano);
            }
        }

        fclose(Open);
    } else {
        printf("Ficheiro não existe...");
    }
};

//funcao que apaga registros
void apagar() {

};


int main() {
    setlocale(LC_ALL, "Portuguese");

    //menu console

    int menu = 0;

    do {
        //opcoes do menu
        printf("\n1-Adicionar Estudante\n2-Listar Estudantes\n3-Sair\n");

        //ler acao do usuario
        scanf("%d", &menu);
        fgetc(stdin);

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