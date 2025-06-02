#include <stdio.h>
#include <string.h>

// Livro 1
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

int temNumero(const char texto[]) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= '0' && texto[i] <= '9') {
            return 1; // Tem número
        }
    }
    return 0; // Não tem número
}

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

void listar_livros() {
    printf("\n--------------LIVROS--------------\n");
    printf("1- %s\n", titulo1);
    printf("2- %s\n", titulo2);
    printf("3- %s\n", titulo3);
    printf("4- %s\n", titulo4);
    printf("5- %s\n", titulo5);
    printf("----------------------------------\n");
    getchar();
}

void alugarLivro() {
    int escolha;
    listar_livros();

    printf("Escolha o número do livro que deseja alugar: ");
    scanf("%d", &escolha);

    char nomeLocador[50];

    switch (escolha) {
        case 1:
            if(strlen(titulo1) == 0) {
                printf("Livro não cadastrado!\n");
                break;
            }
            if(locado1 == 1) {
                printf("Esse livro já está alugado!\n");
                break;
            }
            getchar();
            do {
                printf("Digite seu nome: ");
                fgets(nomeLocador, 50, stdin);
                size_t len1 = strlen(nomeLocador);
                if (len1 > 0 && nomeLocador[len1-1] == '\n') nomeLocador[len1-1] = '\0';
                if (temNumero(nomeLocador)) {
                    printf("Nome inválido! Não pode conter números.\n");
                }
            } while (temNumero(nomeLocador));
            strcpy(locador1, nomeLocador);
            locado1 = 1;
            printf("Livro '%s' alugado por '%s'. Prazo de %d dias.\n", titulo1, locador1, diasRestantes1);
            break;

        case 2:
            if(strlen(titulo2) == 0) {
                printf("Livro não cadastrado!\n");
                break;
            }
            if(locado2 == 1) {
                printf("Esse livro já está alugado!\n");
                break;
            }
            getchar();
            do {
                printf("Digite seu nome: ");
                fgets(nomeLocador, 50, stdin);
                size_t len2 = strlen(nomeLocador);
                if (len2 > 0 && nomeLocador[len2-1] == '\n') nomeLocador[len2-1] = '\0';
                if (temNumero(nomeLocador)) {
                    printf("Nome inválido! Não pode conter números.\n");
                }
            } while (temNumero(nomeLocador));
            strcpy(locador2, nomeLocador);
            locado2 = 1;
            printf("Livro '%s' alugado por '%s'. Prazo de %d dias.\n", titulo2, locador2, diasRestantes2);
            break;

        case 3:
            if(strlen(titulo3) == 0) {
                printf("Livro não cadastrado!\n");
                break;
            }
            if(locado3 == 1) {
                printf("Esse livro já está alugado!\n");
                break;
            }
            getchar();
            do {
                printf("Digite seu nome: ");
                fgets(nomeLocador, 50, stdin);
                size_t len3 = strlen(nomeLocador);
                if (len3 > 0 && nomeLocador[len3-1] == '\n') nomeLocador[len3-1] = '\0';
                if (temNumero(nomeLocador)) {
                    printf("Nome inválido! Não pode conter números.\n");
                }
            } while (temNumero(nomeLocador));
            strcpy(locador3, nomeLocador);
            locado3 = 1;
            printf("Livro '%s' alugado por '%s'. Prazo de %d dias.\n", titulo3, locador3, diasRestantes3);
            break;

        case 4:
            if(strlen(titulo4) == 0) {
                printf("Livro não cadastrado!\n");
                break;
            }
            if(locado4 == 1) {
                printf("Esse livro já está alugado!\n");
                break;
            }
            getchar();
            do {
                printf("Digite seu nome: ");
                fgets(nomeLocador, 50, stdin);
                size_t len4 = strlen(nomeLocador);
                if (len4 > 0 && nomeLocador[len4-1] == '\n') nomeLocador[len4-1] = '\0';
                if (temNumero(nomeLocador)) {
                    printf("Nome inválido! Não pode conter números.\n");
                }
            } while (temNumero(nomeLocador));
            strcpy(locador4, nomeLocador);
            locado4 = 1;
            printf("Livro '%s' alugado por '%s'. Prazo de %d dias.\n", titulo4, locador4, diasRestantes4);
            break;

        case 5:
            if(strlen(titulo5) == 0) {
                printf("Livro não cadastrado!\n");
                break;
            }
            if(locado5 == 1) {
                printf("Esse livro já está alugado!\n");
                break;
            }
            getchar();
            do {
                printf("Digite seu nome: ");
                fgets(nomeLocador, 50, stdin);
                size_t len5 = strlen(nomeLocador);
                if (len5 > 0 && nomeLocador[len5-1] == '\n') nomeLocador[len5-1] = '\0';
                if (temNumero(nomeLocador)) {
                    printf("Nome inválido! Não pode conter números.\n");
                }
            } while (temNumero(nomeLocador));
            strcpy(locador5, nomeLocador);
            locado5 = 1;
            printf("Livro '%s' alugado por '%s'. Prazo de %d dias.\n", titulo5, locador5, diasRestantes5);
            break;

        default:
            printf("Opção inválida!\n");
    }

    printf("\nPRESSIONE ENTER PARA VOLTAR AO MENU PRINCIPAL...");
    getchar(); 
}


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
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);


    switch (opcao) {
    case 1:
        adicionarLivro();
        break;
    case 2:
        listar_livros();
        break;
    case 3:
        alugarLivro();
        break;
    case 4:
        printf("Não tem a função de devolver livro (galego/natan)");
        break;
    case 5:
        printf("Não tem função de renovar livro (galego/natan)");
        break;
    case 6:
        printf("Saindo...\n");
        break;
    default:
        printf("Opção inválida!\n");
    }

    } while (opcao != 6);

    return 0;
    
}