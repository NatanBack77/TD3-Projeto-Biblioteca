#include <stdio.h>
#include <string.h>

#define VALOR_MULTA 5.0 // Valor da multa por dia de atraso
#define SENHA  "admin123" // Senha para acessar o sistema

// Livro 1
char titulo1[50] = "";
char locador1[50] = "";
int diasRestantes1 = 0;
int locado1 = 0;
char nomemultado1[50] = "";
float valormulta1 = 0;

// Livro 2
char titulo2[50] = "";
char locador2[50] = "";
int diasRestantes2 = 0;
int locado2 = 0;
char nomemultado2[50] = "";
float valormulta2 = 0;

// Livro 3
char titulo3[50] = "";
char locador3[50] = "";
int diasRestantes3 = 0;
int locado3 = 0;
char nomemultado3[50] = "";
float valormulta3 = 0;

// Livro 4
char titulo4[50] = "";
char locador4[50] = "";
int diasRestantes4 = 0;
int locado4 = 0;
char nomemultado4[50] = "";
float valormulta4 = 0;

// Livro 5
char titulo5[50] = "";
char locador5[50] = "";
int diasRestantes5 = 0;
int locado5 = 0;
char nomemultado5[50] = "";
float valormulta5 = 0;



int temNumero(const char texto[]) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= '0' && texto[i] <= '9') {
            return 1; // Tem número
        }
    }
    return 0; // Não tem número
}

// Função auxiliar para checar se o nome está multado em qualquer livro
int estaMultado(const char nome[50]) {
    return ((strcmp(nome, nomemultado1) == 0 && valormulta1 > 0) ||
            (strcmp(nome, nomemultado2) == 0 && valormulta2 > 0) ||
            (strcmp(nome, nomemultado3) == 0 && valormulta3 > 0) ||
            (strcmp(nome, nomemultado4) == 0 && valormulta4 > 0) ||
            (strcmp(nome, nomemultado5) == 0 && valormulta5 > 0));
}

int estaAdicionado(const char titulo[50]) {
    return (strcmp(titulo, titulo1) == 0 || strcmp(titulo, titulo2) == 0 ||
            strcmp(titulo, titulo3) == 0 || strcmp(titulo, titulo4) == 0 ||
            strcmp(titulo, titulo5) == 0);
}

void adicionarLivro() {
    char senha[20];
    char titulo[50];
    int diasDevolucao;

    printf("Digite a senha para adicionar um livro: ");
    scanf("%s", senha);
    if(strcmp(senha, SENHA) != 0) {
        printf("Senha incorreta! Acesso negado.\n");
        return;
    }
    printf("Senha correta! Você tem acesso ao sistema.\n");
    printf("Digite o título do livro:  \n");
    getchar();
    fgets(titulo, 50, stdin);
    size_t len = strlen(titulo);
    if (len > 0 && titulo[len-1] == '\n') titulo[len-1] = '\0';

    if (estaAdicionado(titulo)) {
        printf("O livro %s já foi adicionado!\n", titulo);
        return;
    }

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
                printf("Esse livro já está alugado por %s durante %d dia(s)\n\n", locador1, diasRestantes1);
                printf("Você pode renovar o aluguel ou devolver o livro.\n");
                getchar();
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
                // Lógica de consulta: se o livro está locado, mostra nome e dias restantes
                if(locado1 == 1) {
                    printf("Livro '%s' está locado por '%s'. Dias restantes: %d\n", titulo1, locador1, diasRestantes1);
                }
                if(estaMultado(nomeLocador)) {
                    printf("Você possui uma multa pendente em algum livro e não pode alugar até pagar!\n");
                    return;
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
                printf("Esse livro já está alugado por %s durante %d dia(s)\n\n", locador2, diasRestantes2);
                printf("Você pode renovar o aluguel ou devolver o livro.\n");
                getchar();
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
                if(locado2 == 1) {
                    printf("Livro '%s' está locado por '%s'. Dias restantes: %d\n", titulo2, locador2, diasRestantes2);
                }
                if(estaMultado(nomeLocador)) {
                    printf("Você possui uma multa pendente em algum livro e não pode alugar até pagar!\n");
                    return;
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
                printf("Esse livro já está alugado por %s durante %d dia(s)\n\n", locador3, diasRestantes3);
                printf("Você pode renovar o aluguel ou devolver o livro.\n");
                getchar();
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
                if(locado3 == 1) {
                    printf("Livro '%s' está locado por '%s'. Dias restantes: %d\n", titulo3, locador3, diasRestantes3);
                }
                if(estaMultado(nomeLocador)) {
                    printf("Você possui uma multa pendente em algum livro e não pode alugar até pagar!\n");
                    return;
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
                printf("Esse livro já está alugado por %s durante %d dia(s)\n\n", locador4, diasRestantes4);
                printf("Você pode renovar o aluguel ou devolver o livro.\n");
                getchar();
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
                if(locado4 == 1) {
                    printf("Livro '%s' está locado por '%s'. Dias restantes: %d\n", titulo4, locador4, diasRestantes4);
                }
                if(estaMultado(nomeLocador)) {
                    printf("Você possui uma multa pendente em algum livro e não pode alugar até pagar!\n");
                    return;
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
                printf("Esse livro já está alugado por %s durante %d dia(s)\n\n", locador5, diasRestantes5);
                printf("Você pode renovar o aluguel ou devolver o livro.\n");
                getchar();
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
                if(locado5 == 1) {
                    printf("Livro '%s' está locado por '%s'. Dias restantes: %d\n", titulo5, locador5, diasRestantes5);
                }
                if(estaMultado(nomeLocador)) {
                    printf("Você possui uma multa pendente em algum livro e não pode alugar até pagar!\n");
                    return;
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
    getchar();
}

void devolverLivro() {
    int escolha;
    int diasUsados;
    float valorMulta = 0;
    listar_livros();
    printf("Escolha o número do livro que deseja devolver: ");
    scanf("%d", &escolha);
    switch (escolha) {
        case 1:
            if(strlen(titulo1) == 0 || locado1 == 0) {   
                printf("Livro não alugado!\n");
                break;
            }
            printf("Quantos dias você usou o livro '%s'? ", titulo1);
            scanf("%d", &diasUsados);
            if(diasUsados > diasRestantes1) {
                printf("Você usou o livro por mais dias do que o permitido! Você deve pagar uma multa.\n");
                valorMulta = (diasUsados - diasRestantes1) * VALOR_MULTA;
                printf("Valor da multa: R$ %.2f\n", valorMulta);
                strcpy(nomemultado1, locador1);
                valormulta1 = valorMulta;
                break;
            }
            locado1 = 0;
            printf("Livro '%s' devolvido com sucesso!\n", titulo1);
            titulo1[0] = '\0';
            break;
        case 2:
            if(strlen(titulo2) == 0 || locado2 == 0) {
                printf("Livro não alugado!\n");
                break;
            }
            printf("Quantos dias você usou o livro '%s'? ", titulo2);
            scanf("%d", &diasUsados);
            if(diasUsados > diasRestantes2) {
                printf("Você usou o livro por mais dias do que o permitido! Você deve pagar uma multa.\n");
                valorMulta = (diasUsados - diasRestantes2) * VALOR_MULTA;
                printf("Valor da multa: R$ %.2f\n", valorMulta);
                strcpy(nomemultado2, locador2);
                valormulta2 = valorMulta;
                break;
            }
            locado2 = 0;
            printf("Livro '%s' devolvido com sucesso!\n", titulo2);
            titulo2[0] = '\0';
            break;
        case 3:
            if(strlen(titulo3) == 0 || locado3 == 0) {
                printf("Livro não alugado!\n");
                break;
            }
            printf("Quantos dias você usou o livro '%s'? ", titulo3);
            scanf("%d", &diasUsados);
            if(diasUsados > diasRestantes3) {
                printf("Você usou o livro por mais dias do que o permitido! Você deve pagar uma multa.\n");
                valorMulta = (diasUsados - diasRestantes3) * VALOR_MULTA;
                printf("Valor da multa: R$ %.2f\n", valorMulta);
                strcpy(nomemultado3, locador3);
                valormulta3 = valorMulta;
                break;
            }
            locado3 = 0;
            printf("Livro '%s' devolvido com sucesso!\n", titulo3);
            titulo3[0] = '\0';
            break;
        case 4:
            if(strlen(titulo4) == 0 || locado4 == 0) {
                printf("Livro não alugado!\n");
                break;
            }
            printf("Quantos dias você usou o livro '%s'? ", titulo4);
            scanf("%d", &diasUsados);
            if(diasUsados > diasRestantes4) {
                printf("Você usou o livro por mais dias do que o permitido! Você deve pagar uma multa.\n");
                valorMulta = (diasUsados - diasRestantes4) * VALOR_MULTA;
                printf("Valor da multa: R$ %.2f\n", valorMulta);
                strcpy(nomemultado4, locador4);
                valormulta4 = valorMulta;
                break;
            }
            locado4 = 0;
            printf("Livro '%s' devolvido com sucesso!\n", titulo4);
            titulo4[0] = '\0';
            break;
        case 5:
            if(strlen(titulo5) == 0 || locado5 == 0) {
                printf("Livro não alugado!\n");
                break;
            }
            printf("Quantos dias você usou o livro '%s'? ", titulo5);
            scanf("%d", &diasUsados);
            if(diasUsados > diasRestantes5) {
                printf("Você usou o livro por mais dias do que o permitido! Você deve pagar uma multa.\n");
                valorMulta = (diasUsados - diasRestantes5) * VALOR_MULTA;
                printf("Valor da multa: R$ %.2f\n", valorMulta);
                strcpy(nomemultado5, locador5);
                valormulta5 = valorMulta;
                break;
            }
            locado5 = 0;
            printf("Livro '%s' devolvido com sucesso!\n", titulo5);
            titulo5[0] = '\0';
            break;
        default:
            printf("Opção inválida!\n");
    }

    printf("\nPRESSIONE ENTER PARA VOLTAR AO MENU PRINCIPAL...");
    getchar();
    getchar();
}


void pagarmulta() {
    int encontrou = 0;
    if(strlen(nomemultado1) > 0) {
        printf("Locador multado: %s\n", nomemultado1);
        printf("Valor da multa: R$ %.2f\n", valormulta1);
        printf("Multa paga com sucesso!\n");
        nomemultado1[0] = '\0';
        valormulta1 = 0;
        encontrou = 1;
    }
    if(strlen(nomemultado2) > 0) {
        printf("Locador multado: %s\n", nomemultado2);
        printf("Valor da multa: R$ %.2f\n", valormulta2);
        printf("Multa paga com sucesso!\n");
        nomemultado2[0] = '\0';
        valormulta2 = 0;
        encontrou = 1;
    }
    if(strlen(nomemultado3) > 0) {
        printf("Locador multado: %s\n", nomemultado3);
        printf("Valor da multa: R$ %.2f\n", valormulta3);
        printf("Multa paga com sucesso!\n");
        nomemultado3[0] = '\0';
        valormulta3 = 0;
        encontrou = 1;
    }
    if(strlen(nomemultado4) > 0) {
        printf("Locador multado: %s\n", nomemultado4);
        printf("Valor da multa: R$ %.2f\n", valormulta4);
        printf("Multa paga com sucesso!\n");
        nomemultado4[0] = '\0';
        valormulta4 = 0;
        encontrou = 1;
    }
    if(strlen(nomemultado5) > 0) {
        printf("Locador multado: %s\n", nomemultado5);
        printf("Valor da multa: R$ %.2f\n", valormulta5);
        printf("Multa paga com sucesso!\n");
        nomemultado5[0] = '\0';
        valormulta5 = 0;
        encontrou = 1;
    }
    if(!encontrou) {
        printf("Nenhum locador multado.\n");
    }
}

void renovarLivro() {
    int escolha;
    listar_livros();
    printf("Escolha o número do livro que deseja renovar: ");
    scanf("%d", &escolha);
    switch (escolha) {
        case 1:
            if(strlen(titulo1) == 0 || locado1 == 0) {
                printf("Livro não alugado!\n");
                break;
            }
            printf("Renovando livro '%s' por mais %d dias.\n", titulo1, diasRestantes1);
            diasRestantes1 += 7; // Renovação de 7 dias
            printf("Novo prazo: %d dias.\n", diasRestantes1);
            break;
        case 2:
            if(strlen(titulo2) == 0 || locado2 == 0) {
                printf("Livro não alugado!\n");
                break;
            }
            printf("Renovando livro '%s' por mais %d dias.\n", titulo2, diasRestantes2);
            diasRestantes2 += 7; // Renovação de 7 dias
            printf("Novo prazo: %d dias.\n", diasRestantes2);
            break;
        case 3:
            if(strlen(titulo3) == 0 || locado3 == 0) {
                printf("Livro não alugado!\n");
                break;
            }
            printf("Renovando livro '%s' por mais %d dias.\n", titulo3, diasRestantes3);
            diasRestantes3 += 7; // Renovação de 7 dias
            printf("Novo prazo: %d dias.\n", diasRestantes3);
            break;
        case 4:
            if(strlen(titulo4) == 0 || locado4 == 0) {
                printf("Livro não alugado!\n");
                break;
            }
            printf("Renovando livro '%s' por mais %d dias.\n", titulo4, diasRestantes4);
            diasRestantes4 += 7; // Renovação de 7 dias
            printf("Novo prazo: %d dias.\n", diasRestantes4);
            break;
        case 5:
            if(strlen(titulo5) == 0 || locado5 == 0) {
                printf("Livro não alugado!\n");
                break;
            }
            printf("Renovando livro '%s' por mais %d dias.\n", titulo5, diasRestantes5);
            diasRestantes5 += 7; // Renovação de 7 dias
            printf("Novo prazo: %d dias.\n", diasRestantes5);
            break;
        default:
            printf("Opção inválida!\n");
    }
    printf("\nPRESSIONE ENTER PARA VOLTAR AO MENU PRINCIPAL...");
    getchar();
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
        printf("6. Pagar multa\n");
        printf("7. Sair\n");
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
        devolverLivro();
        break;
    case 5:
       renovarLivro();
        break;
    case 6:
        pagarmulta();
        break;
    case 7:
    printf("Saindo do sistema...\n");
        break;   
    default:
        printf("Opção inválida!\n");
    }
    } while (opcao != 6);

   return 0;  
}