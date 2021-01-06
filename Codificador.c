#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define H 26 // DEFININDO H COMO 26
/**
TRABALHO DE MATEMATICA DISCRETA
ALUNO: MARCOS GABRIEL PEREIRA ARAUJO
2017/2  - NºMATRICULA: 2017111024

CODIFICADOR DA CIFRA DE HILL
**/

int main()
{
    char Nome[1000]; //VETOR QUE RECEBE A FRASE DELIMITADO COM ATE 1000 LETRAS
    //MODULARIZAÇÃO NO 26 POIS CONTA COM O ESPAÇO COMO UM CARACTER INCLUINDO AS LETRAS NORMAIS MAISCULAS
    char Vet[H]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};//VETOR PARA IDENTIFICAR AS LETRAS
    int Vetor[H]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};//VETOR PARA IDENTIFICAR OS NUMEROS
    int Vetc[1000];//VETOR QUE IRA RECEBER O NUMERO REFERENTE A CADA LETRA
    int e,i,j,k;
//LE O QUE FOI DIGITADO E GRAVA NO VETOR
    printf("Digite a palavra\n");
    scanf(" %[^\n]s", Nome);
    int x = strlen(Nome);
//TRANSFOMAÇÃO LEMBRANDO SO DA PRA FAZER COM CAIXA ALTA
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<H; j++)
        {
            if(Nome[i]==Vet[j])
            {
                Vetc[i]=Vetor[j];//VETOR RECEBE OS NUMEROS REFERENTE A CADA LETRA
                break;
            }
        }
    }
//ATRIBUI A VARIAVEL "e" O UM NUMERO NO QUAL AS MATRIZES VAO RECEBER E ALOCAR A QUANTIDADE MEMORIA CORRETA
    if(x%2!=0)
    {
        e = 1+x/2;
    }
    else
    {
        e = x/2;
    }

    int N[e][2];//MATRIZ QUE IRA RECEBER CADA VALOR
    int C[2][e];//MATRIZ QUE IRA RECEBER OS CALCULOS
    int M[2][2];//MATRIZ CHAVE
    int h=0;
    //ZERANDO A MATRIZ QUE IRA RECEBER OS CALCULOR
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<e; j++)
        {
            C[i][j]=0;
        }
    }
    //MATRIZ N IRA RECEBER OS VALORES DO VETOR VETC IR ATRIBUIR A CADA POSIÇÃO CORRETA
    for(i=0; i<e; i++)
    {
        for(j=0; j<2; j++)
        {
            N[i][j] = Vetc[h];
            //SE O NUMERO DE CARACTERES DE VETC FOR IMPAR O ULTIMO VALOR A SER ATRIBUIDO 26 QUE E A MESMAS COISA QUE ESPAÇO.
            if(x%2!=0&&i==e-1&&j==1)
            {
                N[i][j]= 1; //SE A PALAVRA FOR IMPAR OU TIVER ESPAÇO SERA ESCRITO B, POIS NAO IRA MUDAR O SENTIDO DA FRASE
            }
            h++;
        }
    }
    //MATRIZ M IRA RECEBER A CHAVE 2X2
    printf("Digite os numeros da matriz chave\n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }
    //MATRIZ C IRA RECEBER OS VALORES DO CALCULO DA CIFRA DE HILL
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<e; j++)
        {
            for(int k=0; k<2; k++)
            {
                C[i][j] =C[i][j]+ (M[i][k] * N[j][k]); //Utilizamos a regra da multiplicação de matrizes.
                C[i][j] = C[i][j]%H; //Aqui usamos o modulo de 27 para obter o valor.
            }
        }
    }
    //IMPRIMIMOS NA TELA OS VALOR EM FORMA DE CARACTERE APLICADOS NO MODULO 27
    for(int i=0; i<e; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("%c", Vet[C[j][i]]);//LEMBRANDO QUE MUITAS VEZES O ESPAÇO PODERA SER IMPRESSO COMO B POIS ESSA E A LETRA SUBSTITUTA}
    }
}
    //POIS O DECODIFICADOR SO ACEITARA ENTRADAS PARES VINDO DO CODIFICADOR
    return 0;
}
