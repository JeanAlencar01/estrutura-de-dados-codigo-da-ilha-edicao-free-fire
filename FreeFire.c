#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

#define MAX_ITENS 10

typedef enum {
    NOME,
    TIPO,
    PRIORIDADE
} CriterioOrdenacao;

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade;
} Item;

Item mochila[MAX_ITENS];
int numItens = 0;
bool ordenadaPorNome = false;

void adicionarItem() {
    if (numItens < MAX_ITENS) {
        printf("Digite o nome do item: ");
        scanf("%s", mochila[numItens].nome);
        printf("Digite o tipo do item: ");
        scanf("%s", mochila[numItens].tipo);
        printf("Digite a quantidade do item: ");
        scanf("%d", &mochila[numItens].quantidade);
        printf("Digite a prioridade do item (1-5): ");
        scanf("%d", &mochila[numItens].prioridade);
        numItens++;

        printf("Item adicionado com sucesso!\n");
    } else {
        printf("Mochila cheia!\n");
    }
}

void ordenarItens(CriterioOrdenacao criterio) {
    for (int i = 1; i < numItens; i++) {
        Item chave = mochila[i];
        int j = i - 1;
        while (j >= 0) {
            if (criterio == NOME && strcmp(mochila[j].nome, chave.nome) > 0) {
                mochila[j + 1] = mochila[j];
                j--;
            } else if (criterio == TIPO && strcmp(mochila[j].tipo, chave.tipo) > 0) {
                mochila[j + 1] = mochila[j];
                j--;
            } else if (criterio == PRIORIDADE && mochila[j].prioridade < chave.prioridade) {
                mochila[j + 1] = mochila[j];
                j--;
            } else {
                break;
            }
        }
        mochila[j + 1] = chave;
    }
    if (criterio == NOME) {
        ordenadaPorNome = true;
    }
}

void removerItem() {
    char nome[50];
    printf("Digite o nome do item a remover: ");
    scanf("%s", nome);
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < numItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            numItens--;
            printf("Item removido com sucesso!\n");
            return;
        }
    }
    printf("Item não encontrado!\n");
}

void listarItens() {
    printf("Itens na mochila:\n");
    printf("Nome\tTipo\tQuantidade\tPrioridade\n");
    for (int i = 0; i < numItens; i++) {
        printf("%s\t%s\t%d\t%d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade, mochila[i].prioridade);
    }
}

void buscarItemBinaria() {
    if (!ordenadaPorNome) {
        printf("Mochila não está ordenada por nome!\n");
        return;
    }
    char nome[50];
    printf("Digite o nome do item a buscar: ");
    scanf("%s", nome);
    int inicio = 0;
    int fim = numItens - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (strcmp(mochila[meio].nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s\n", mochila[meio].nome);
            printf("Tipo: %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);
            printf("Prioridade: %d\n", mochila[meio].prioridade);
            return;
        } else if (strcmp(mochila[meio].nome, nome) < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("Item não encontrado!\n");
}

void buscarItem() {
    char nome[50];
    printf("Digite o nome do item a buscar: ");
    scanf("%s", nome);
    int encontrado = 0;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Item não encontrado!\n");
    }
}

int main() {
    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Ordenar itens\n");
        printf("5. Buscar item binária por nome\n");
        printf("6. Buscar item por nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                adicionarItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                printf("Ordenar por:\n");
                printf("1. Nome\n");
                printf("2. Tipo\n");
                printf("3. Prioridade\n");
                int criterio;
                scanf("%d", &criterio);
                ordenarItens(criterio - 1);
                break;
            case 5:
                buscarItem();
                break;
            case 6:
                buscarItemBinaria();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    return 0;
}


    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.



// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
