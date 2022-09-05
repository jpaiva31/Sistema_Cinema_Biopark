/*Código de controle de sistema de um cinema, pedido pelo professor Leonardo.
O código deve permitir que o usuario compre, reserve ou cancele a reserva de poltronas de uma sala de cinema.
Código iniciado em 05/09
*/
#include <stdio.h>
#include <string.h>
struct Pessoa
{
    char nome[100];
    int CPF;
};

struct Cinema
{
    int cadeiras[5][10];
    struct Pessoa pessoas[5][10];
};

struct Cinema inicializa()
{
    struct Cinema cine;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<10; j++)
        {
            cine.cadeiras[i][j]=0;
        }
    }
    return cine;
}

int scanea()
{
    int n;
    printf("Escolha uma opcao:\n1- Comprar ingresso\n2- Reservar ingresso\n3- Cancelar reserva\n4- Mostrar as opcoes de poltronas\n5- Buscar poltrona pela pessoa\n6- Sair\n");
    scanf("%d", &n);
    return n;
}

struct Cinema compra(struct Cinema cine)
{
    printf("Qual poltrona deseja comprar?\n");
    int n;
    scanf("%d", &n);
    int i=n,j=0;
    while(n>10)
    {
        n-=10;
        i=n;
        j++;
    }
    cine.cadeiras[j][i-1]=1;
    printf("NOME: ");
    fflush(stdin);
    gets(cine.pessoas[j][i-1].nome);
    printf("CPF: ");
    scanf("%d", &cine.pessoas[j][i-1].CPF);
    return cine;
}
struct Cinema reserva(struct Cinema cine)
{
    printf("Qual poltrona deseja reservar?\n");
    int n;
    scanf("%d", &n);
    int i=n,j=0;
    while(n>10)
    {
        n-=10;
        i=n;
        j++;
    }
    cine.cadeiras[j][i-1]=2;
    return cine;
}

struct Cinema cancelaReserva(struct Cinema cine)
{
    printf("Qual poltrona deseja cancelar a reserva?\n");
    int n;
    scanf("%d", &n);
    int i=n,j=0;
    while(n>10)
    {
        n-=10;
        i=n;
        j++;
    }
    if(cine.cadeiras[j][i-1]==2)
    {
        cine.cadeiras[j][i-1]=0;
    }
    else printf("Essa poltrona nao estava reservada!!\n");
    return cine;
}
void busca(struct Cinema cine, int *p1,int *p2)
{
    int n;
    printf("Digite o CPF da pessoa que voce quer saber a poltrona: ");
    scanf("%d",&n);
    if(n!=0)
    {
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(n==cine.pessoas[i][j].CPF)
                {
                    *p1 = i;
                    *p2 = j;
                    return;
                }
            }
        }
    }
    *p1=-1;
    *p2=-1;
}

void mostra(struct Cinema cine)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(cine.cadeiras[i][j]==0) printf("[ ]");
            else if(cine.cadeiras[i][j]==1) printf("[X]");
            else if(cine.cadeiras[i][j]==2) printf("[#]");
        }
        printf("\n");
    }
    printf("[ ] = Poltronas vazias\n[X] = Poltronas ja compradas\n[#] = Poltronas ja reservadas\n");
}

int main()
{
    struct Cinema cine=inicializa();
    int n=0;
    while(n!=6)
    {
        n = scanea();

        if(n == 1)
        {
            mostra(cine);
            cine = compra(cine);
        }
        if(n == 2)
        {
            mostra(cine);
            cine = reserva(cine);
        }
        if(n == 4)
        {
            mostra(cine);
        }
        if(n == 3)
        {
            mostra(cine);
            cine = cancelaReserva(cine);
        }
        if(n == 5)
        {
            int aux1,aux2;
            busca(cine,&aux1,&aux2);
            if(aux1==-1&&aux2==-1) printf("CPF nao cadastrado!\n");
            else printf("A poltrona de %s eh a poltrona %d\n", cine.pessoas[aux1][aux2].nome,(aux1*10)+aux2+1);
        }
    }

    return 0;
}
