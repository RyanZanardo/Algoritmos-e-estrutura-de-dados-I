#include <stdio.h>
#include <stdlib.h>

void cadastrar_produto(float matriz[][6], int *linha_atual);
void listar_produtos(float matriz[][6], int linha_atual);
void buscar_codigo(float matriz[][6], int linha_atual);
void buscar_material(float matriz[][6], int linha_atual);
void imprimir_relatorio(float matriz[][6], int linha_atual);

int main()
{
    float matriz[30][6];
    int linha_atual = 0;
    int opcao;

    printf("Digite a opcao que deseja:\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Buscar o codigo e mostrar o preco do produto, cor e material\n");
    printf("3 - Buscar material\n");
    printf("4 - Relatorio de compras\n");
    printf("5 - Listar produtos ordenados\n");
    printf("0 - Sair\n");

    do
    {
        printf("\n");
        printf("Digite a opcao que deseja:\n");
        scanf("%d%*c", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            cadastrar_produto(matriz, &linha_atual);
            break;

        case 2:
            buscar_codigo(matriz,linha_atual);
            break;

        case 3:
            buscar_material(matriz,linha_atual);
            break;

        case 4:
            imprimir_relatorio(matriz,linha_atual);
            break;

        case 5:
            listar_produtos(matriz, linha_atual);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    while (opcao != 0);
}

void cadastrar_produto(float matriz[][6], int *linha_atual)
{
    printf("Digite o codigo do produto: ");
    scanf("%f", &matriz[*linha_atual][0]);

    printf("Digite o tipo do produto: ");
    scanf("%f", &matriz[*linha_atual][1]);

    printf("Digite o material do produto: ");
    scanf("%f", &matriz[*linha_atual][2]);

    printf("Digite o estoque do produto: ");
    scanf("%f", &matriz[*linha_atual][3]);

    printf("Digite a cor do produto: ");
    scanf("%f", &matriz[*linha_atual][4]);

    printf("Digite o preco do produto: ");
    scanf("%f", &matriz[*linha_atual][5]);

    (*linha_atual)++; // incrementa o valor do ponteiro para a próxima linha
}

void listar_produtos(float matriz[][6], int linha_atual)
{
    printf("Matriz de produtos:\n");
    for (int i = 0; i < linha_atual; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void buscar_codigo(float matriz[][6], int linha_atual)
{
    int codigo;
    printf("Digite o codigo que quer buscar: ");
    scanf("%d",&codigo);

    for (int i = 0; i < linha_atual; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (codigo == matriz[i][0])
            {
                printf("O codigo : %d | O preco do produto : %.2f | A cor : %.f | O material: %.f",codigo,matriz[i][5],matriz[i][4],matriz[i][2]);
                return;
            }
        }
    }


}

void buscar_material(float matriz[][6], int linha_atual) {
    printf("Os materias cadastrados sao:\n ");
    for (int i = 0; i < linha_atual; i++)
    {
            printf("| %.f | ",matriz[i][2]);

    }
}

void imprimir_relatorio(float matriz[][6], int linha_atual) {

    int encontrou = 0; // variável para verificar se encontrou algum produto com estoque mínimo

    printf("Produtos sem estoque minimo:\n");
    for (int i = 0; i < linha_atual; i++)
    {
        if (matriz[i][3] < 2) // se estoque for menor que 2
        {
            encontrou = 1; // atualiza a variável para indicar que encontrou algum produto
            printf("Codigo: %.f | Tipo: %.f | Material: %.f | | Cor: %.f | Preco: %.2f\n", matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][4],matriz[i][5]);
        }
    }

    if (!encontrou) // se não encontrou nenhum produto com estoque mínimo
    {
        printf("Nenhum produto com estoque mínimo encontrado.\n");
    }
}
