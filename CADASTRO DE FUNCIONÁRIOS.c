#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct tFuncionario{
    char nome[30];
    int cpf;
    int cargo;
    float salario;
}Funcionario;

void cadastrar(Funcionario *f)
{
    printf("Nome......: ");
    scanf("%s", &f->nome);
    printf("CPF.......: ");
    scanf("%d", &f->cpf);
    printf("Cargo.....: ");
    scanf("%d", &f->cargo);
    printf("Salario...: ");
    scanf("%f", &f->salario);
}

void exibir(Funcionario f)
{
    printf("Nome......: %s\n", f.nome);
    printf("CPF.......: %d\n", f.cpf);
    printf("Cargo.....: %d\n", f.cargo);
    printf("Salario...: %.2f\n\n", f.salario);
}

int procurar(Funcionario vet[], int qtd, int cpf)
{
    int res = -1;
    for(int i = 0; i < qtd; i++)
        if(vet[i].cpf == cpf)
        {
            res = i;
            break;
        }
    return res;
}

void excluir(Funcionario vet[], int qtd, int pos)
{
    for(int i = pos+1; i < qtd; i++)
        vet[i-1] = vet[i];
}



int main()
{
    const limite = 200;
    int qtd_fun, op, pos, cpf;
    Funcionario vet_fun[limite];
    qtd_fun = 0;
    do
    {
        printf("<--- MENU --->\n");
        printf("1. Cadastrar\n");
        printf("2. Exibir\n");
        printf("3. Alterar\n");
        printf("4. Consultar\n");
        printf("5. Excluir\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);
        system("cls");
        switch(op)
        {
            case 1:
                printf("<--- CADASTRAR --->\n");
                cadastrar(&vet_fun[qtd_fun]);
                qtd_fun++;
                break;
            case 2:
                printf("<--- EXIBIR --->\n");
                for(int i = 0; i < qtd_fun; i++)
                    exibir(vet_fun[i]);
                system("pause");
                break;
            case 3:
                printf("<--- ALTERAR --->\n");
                printf("CPF...: ");
                scanf("%d", &cpf);
                pos = procurar(vet_fun, qtd_fun, cpf);
                if(pos == -1)
                {
                    printf("\nCPF nao encontrado!\n\n");
                    system("pause");
                }
                else
                    cadastrar(&vet_fun[pos]);
                break;
            case 4:
                printf("<--- CONSULTAR --->\n");
                printf("CPF...: ");
                scanf("%d", &cpf);
                pos = procurar(vet_fun, qtd_fun, cpf);
                if(pos == -1)
                    printf("\nCPF nao encontrado!\n\n");
                else
                    exibir(vet_fun[pos]);
                system("pause");
                break;
            case 5:
                printf("<--- EXCLUIR --->\n");
                printf("CPF...: ");
                scanf("%d", &cpf);
                pos = procurar(vet_fun, qtd_fun, cpf);
                if(pos == -1)
                    printf("\nCPF nao encontrado!\n\n");
                else
                {
                    excluir(vet_fun, qtd_fun, pos);
                    qtd_fun--;
                }
                system("pause");
                break;
        }
        system("cls");
    }while(op != 0);
    return 0;
}
