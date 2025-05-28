#include <stdio.h>
#include <string.h>


int errosTentativasAlugar = 0;

char titulo1[50] = "";
char locador1[50] = "";
int diasRestantes1 = 0;
int locado1 = 0;

// Livro 2
char titulo2[50] = "";
char locador2[50] = "";
int diasRestantes2 = 0;
int locado2 = 0;

// Livro 3
char titulo3[50] = "";
char locador3[50] = "";
int diasRestantes3 = 0;
int locado3 = 0;

// Livro 4
char titulo4[50] = "";
char locador4[50] = "";
int diasRestantes4 = 0;
int locado4 = 0;

// Livro 5
char titulo5[50] = "";
char locador5[50] = "";
int diasRestantes5 = 0;
int locado5 = 0;

void adicionarLivro() {
    char titulo[50];
    int diasDevolucao;
    printf("Digite o título do livro:  \n");
    getchar();
    fgets(titulo, 50, stdin);
    size_t len = strlen(titulo);
    if (len > 0 && titulo[len-1] == '\n') titulo[len-1] = '\0';
    printf("Digite o número de dias para devolução:  \n");
    scanf("%d", &diasDevolucao);

    if(strlen(titulo1) == 0) {
        strcpy(titulo1, titulo);
        diasRestantes1 = diasDevolucao;
        printf("Livro 1 adicionado com sucesso!\n");
    }
    else if(strlen(titulo2) == 0) {
        strcpy(titulo2, titulo);
        diasRestantes2 = diasDevolucao;
        printf("Livro 2 adicionado com sucesso!\n");
    }
    else if(strlen(titulo3) == 0) {
        strcpy(titulo3, titulo);
        diasRestantes3 = diasDevolucao;
        printf("Livro 3 adicionado com sucesso!\n");
    }
    else if(strlen(titulo4) == 0) {
        strcpy(titulo4, titulo);
        diasRestantes4 = diasDevolucao;
        printf("Livro 4 adicionado com sucesso!\n");
    }
    else if(strlen(titulo5) == 0) {
        strcpy(titulo5, titulo);
        diasRestantes5 = diasDevolucao;
        printf("Livro 5 adicionado com sucesso!\n");
    }
    else {
        printf("Limite de livros atingido!\n");
    }
}
   
void alugarLivro(char titulo[], char locador[], int *diasRestantes, int *locado) {
    if (strlen(titulo) == 0) {
        printf("Erro: Nenhum livro cadastrado ainda. Por favor, adicione um livro primeiro.\n");
        return;
    }

    if (*locado == 1) {
        printf("Erro: O livro \"%s\" já está alugado por %s. Faltam %d dias.\n", titulo, locador, *diasRestantes);
        errosTentativasAlugar++;
        printf("Tentativas mal-sucedidas: %d\n", errosTentativasAlugar);
        return;
    }

    getchar(); // limpar buffer
    printf("Digite seu nome: ");
    fgets(locador, 50, stdin);
    size_t len = strlen(locador);
    if (len > 0 && locador[len - 1] == '\n') locador[len - 1] = '\0';

    printf("Digite a quantidade de dias para devolução: ");
    scanf("%d", diasRestantes);

    *locado = 1;

    printf("Livro \"%s\" alugado com sucesso por %s por %d dias!\n", titulo, locador, *diasRestantes);
} 

void listar_livros() {
    printf("\n--------------LIVROS--------------\n");
    printf("1- %s\n", titulo1);
    printf("2- %s\n", titulo2);
    printf("3- %s\n", titulo3);
    printf("4- %s\n", titulo4);
    printf("5- %s\n", titulo5);
    printf("----------------------------------\n");
    getchar();
    printf("PRESSIONE ENTER PARA VOLTAR AO MENU: ");
    getchar();
}

void alugarLivro () {} 

int main(){
    int opcao;
    do {

        printf("\n---------------MENU---------------\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("3. Alugar livro\n");
        printf("4. Devolver livro\n");
        printf("5. Renovar livro\n");
        printf("6. Sair\n");
        printf("----------------------------------\n");
        printf("Escolha uma opÃ§Ã£o: ");
        scanf("%d", &opcao);


        switch (opcao) {
            case 1:
                adicionarLivro();
                break;
            case 2:
                listar_livros();
                break;
            case 3:
                alugarLivro(titulo2, locador2, &diasRestantes2, &locado2);
                break;
            case 4:
                alugarLivro(titulo3, locador3, &diasRestantes3, &locado3);
                break;
            case 5:
                alugarLivro(titulo4, locador4, &diasRestantes4, &locado4);
                break;
            case 6:
                alugarLivro(titulo5, locador5, &diasRestantes5, &locado5);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    return 0;
    
}