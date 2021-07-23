// Exercicio 01.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int nif, anonascimento, anodescontos, anoatual = 2021;
    bool valido;
    char continuar = 'a';

    printf("\n\tSeja Benvindo/a!\n\n\t Vamos começar.\n\n");

Inicio:

    do
    {
        valido = true;
        printf("\n\tInsira o Número de Identificação Fiscal:   ");
        if (scanf_s("%d", &nif) == 0 || nif < 100000000 || nif > 999999999) {      //Validação de que o NIF é válido, sendo que o NIF tém 9 números.
            printf("\n\tInsira um Número de Identificação Fiscal Válido.\n\n");
            valido = false;
        }
        getchar();
    } while (valido == false);

    do
    {
        valido = true;
        printf("\n\tInsira o Ano de Nascimento do Contribuinte:   ");
        if (scanf_s("%d", &anonascimento) == 0 || anonascimento < 1921 || anoatual - anonascimento < 16) {    //Considerei o ano de Nascimento mínimo de 1920, considerando que a pessoa pdia ter até 100 anos, Considerei também que a pessoa não podia ter menos de 16 anos, que é a idade mínima para começar a trabalhar com a autoriação dos pais.
            printf("\n\tInsira um Ano Válido.\n\n");
            valido = false;
        }
        getchar();
    } while (valido == false);

    do
    {
        valido = true;
        printf("\n\tInsira o Ano de Início dos Descontos do Contribuinte:   ");
        if (scanf_s("%d", &anodescontos) == 0 || anodescontos - anonascimento < 16 || anodescontos > anoatual) {
            printf("\n\tInsira um Ano Válido.\n\n");
            valido = false;
        }
        getchar();
    } while (valido == false);

    printf("\n\tO Contribuinte com o NiF %d tem %d anos de idade e %d anos de descontos.", nif, anoatual - anonascimento, anoatual - anodescontos);

    if (anoatual - anonascimento >= 65) {
        printf("\n\tO Contribuinte reúne a idade mínima para requerer a reforma.\n\n");
    }

    else if (anoatual - anodescontos >= 30) {
        printf("\n\tO Contribuinte reúne os anos de descontos necessários para requerer a reforma.\n\n");
    }

    else if (anoatual - anonascimento >= 60 && anoatual - anodescontos >= 25) {
        printf("\n\tO Contribuinte reúne a idade e os anos de descontos necessários para requerer a reforma.\n\n");
    }

    else {
        printf("\n\tO Contribuinte não reúne as condições necessárias para requerer a reforma.\n\n");
    }

    do
    {
        valido = true;
        printf("\n\tDeseja continuar a Inserir Dados?\n\tS - Sim\n\tN - Não\n\t");
        continuar = _getwch();
        continuar = toupper(continuar);   //Converter para Maiúsculas 

        switch (continuar)
        {
        case'S': goto Inicio; break;
        case'N': printf("\n\tFim\n\n"); break;
        default: printf("\n\tValor Inválido\n\n"); valido = false;; break;
        }
    } while (valido == false);

}
