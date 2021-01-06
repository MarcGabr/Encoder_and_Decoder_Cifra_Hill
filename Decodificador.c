
#include <stdio.h>
#include <stdlib.h>
#define H 26 // DEFININDO H COMO 26
/**
DECODIFICADOR DA CIFRA DE HILL
**/
  //O DECODIFICADOR SO ACEITARA ENTRADAS PARES.
int main()
{   //MODULARIZAÇÃO NO 26 POIS CONTA COM O ESPAÇO COMO UM CARACTER INCLUINDO AS LETRAS NORMAIS MAISCULAS
    char Vet[H]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};//VETOR PARA IDENTIFICAR AS LETRAS

    char Nome[100];//VETOR QUE RECEBE A FRASE DELIMITADO COM ATE 1000 LETRAS
    printf("Digite a palavra do DECODIFICADOR\n");
    scanf(" %[^\n]s", Nome);
    int x = strlen(Nome);
    int e = x;
    x = x/2;
    int b=1,c=1;
    int M[2][2];//MATRIZ CHAVE
    int N[x][2];//MATRIZ QUE IRA RECEBER CADA VALOR
    int C[2][x];//MATRIZ QUE IRA RECEBER OS CALCULOS
    int Vetc[1000];//VETOR QUE IRA RECEBER O NUMERO REFERENTE A CADA LETRA
    int Vetor[H]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};//VETOR PARA IDENTIFICAR OS NUMEROS
    int i,j,k,h=0;
    //ZERANDO A MATRIZ QUE IRA RECEBER OS CALCULOR
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<e; j++)
        {
            C[i][j]=0;
        }
    }
 //TRANSFOMAÇÃO LEMBRANDO SO DA PRA FAZER COM CAIXA ALTA
    for(int i=0; i<e; i++)
    {
        for(int j=0; j<H; j++)
        {
            if(Nome[i]==Vet[j])
            {
                Vetc[i]=Vetor[j];
                break;
            }
        }
    }
     //MATRIZ N IRA RECEBER OS VALORES DO VETOR VETC IR ATRIBUIR A CADA POSIÇÃO CORRETA
    for(i=0; i<x; i++)
    {
        for(j=0; j<2; j++)
        {
            N[i][j] = Vetc[h];
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
    //INVERSA DA MATRIZ
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(i==j)
            {
                b = b * M[i][j];
                if(i==1)
                {
                    int d = M[i][j];
                    M[i][j]=M[i-1][j-1];
                    M[i-1][j-1]=d;
                }
            }
            if(i!=j)
            {
                c=M[i][j]*c;
                M[i][j]=M[i][j]*-1;

            }
        }
    }
    //RECEBENDO O RESULTADO DA MATRIZ M
    b = b - c;
    if(b <0)
    {
        while(b<0)
        {
            b=b + H;
        }
    }
    else
    {
        b = b%26;
    }
    //MODULARIZANDO O RESULTADO DA MATRIZ M
    for(i=0; i<H; i++)
    {
        if((b*i)%H==1)
        {
            b=i;
            break;
        }
    }
    //OBTENDO A INVERSA DA MATRIZ M(CHAVE)INICIAL APLICADA NO RESULTADO DE b
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            M[i][j]=M[i][j]*b;
            if(M[i][j]<0)
            {
                while(M[i][j]<0)
                {
                    M[i][j]=M[i][j]+H;
                }
            }
            else
            {
                M[i][j]=M[i][j]%H;
            }
        }
    }
    //MATRIZ C IRA RECEBER OS VALORES DO CALCULO DA CIFRA DE HILL
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<x; j++)
        {
            for(int k=0; k<2; k++)
            {
                C[i][j] =C[i][j]+ (M[i][k] * N[j][k]); //Utilizamos a regra da multiplicação de matrizes
                C[i][j] = C[i][j]%H; //Aqui usamos o modulo de 27 para obter o valor
            }
        }
    }
//IMPRIMIMOS NA TELA OS VALOR EM FORMA DE CARACTERE APLICADOS NO MODULO 26
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("%c", Vet[C[j][i]]);
        }
    }
    return 0;
}
