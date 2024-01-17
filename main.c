#include <stdio.h>
#include <stdlib.h>
#include <string.h> //não foi ensinado na aula mas estava enfrentando um problema de erro e a solução que encontrei foi importar essa lib
#include <locale.h>

//informacao dos estudantes
struct Estudantes {
    char nome[100];
    int idade;
    int ano; // ano em que está a cursar ativo // formado ou ainda estudante
    char status[20]; // ativo ou formado
};

//funcao que adiciona dados ao arquivo
void adicionar() {

    struct Estudantes studen; // cria um ocorencia do obj em RAM

    FILE *Open;
    Open = fopen("file.dat", "rb+");

    if(!Open) { //se o ficheiro não existir
        Open = fopen("file.dat", "wb");
        fclose(Open);
        Open = fopen("file.dat", "rb+");
    };

    //Preencher informacoes
    printf("Digite o nome do estudante: ");
    gets(studen.nome);

    printf("Digite a idade deste estudante: ");
    scanf("%d", &studen.idade);
    fgetc(stdin);

    printf("Digite o ano de ingresso do estudante: ");
    scanf("%d", &studen.ano);
    fgetc(stdin);


    //validar ano de ingresso
    if(studen.ano < 2021) { // ano menor que 2021 licenciatura concluída

        strcpy(studen.status, "Inativo/Concluido"); //copiar uma string de origem para um local de memória do obj Estudantes chamado status 

    } else if (studen.ano >= 2021 && studen.ano <= 2024) { //ano de ingresso entre 2021 e 2024 curso em andamento
        
        strcpy(studen.status, "Ativo/Cursando");

    } else {
        printf("Ano de ingresso invalido");
        fclose(Open);
    }

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

        int maisRegistros = 0; //enquanto existem registros

        printf("Nome \tIdade\tAno\tStatus de Matricula\n");

        while(!maisRegistros) {
            
            fread(&studen, sizeof(struct Estudantes), 1, Open);

            if(feof(Open)) maisRegistros = 1;

            else {
                printf("%s\t%d\t%d\t%s\n",
                studen.nome,
                studen.idade,
                studen.ano,
                studen.status);
            }
        }

        fclose(Open);
    } else {
        printf("Ficheiro não existe...\n");
    }
};

//funcao de editar os registros
void editar() {

}

//funcao que apaga registros
void apagar() {

};


int main() {
    setlocale(LC_ALL, "Portuguese");

    //menu console

    int menu = 0;

    do {
        //opcoes do menu
        printf("\n1-Adicionar Estudante\n2-Listar Estudantes\n3-Editar\n4-Apagar\n5-Sair\n");

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
        if(menu == 3) {
            editar();
        }
        if(menu == 4) {
            apagar();
        }
    } while(menu != 5);
    printf("Programa encerrado!");
    

    return 0;
}