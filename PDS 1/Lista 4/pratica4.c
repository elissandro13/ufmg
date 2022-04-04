#include <math.h>
#include <stdio.h>

float paraMetrosPorSegundo(float v)
{

    return v / 3.6;
}

float areaCirculo(float raio)
{
    
    return 3.141592 * (raio * raio);
}

int maior3(int n1, int n2, int n3) 
{
    int maior = n1;

    if (n1 > n2) {
        if ( n1 > n2){
            maior = n1;
        } else {
            maior = n3;
        }
    } else {
        if (n2 > n3){
            maior = n2;
        } else {
            maior = n3;
        }
    }

    return maior;

}

int ehPar(int n)
{

  return !(n & (unsigned int)1);
  
}

int ehDivisivelPor3ou5(int n)
{

    if ((n % 3 == 0) && (n % 5 == 0)) 
        return 0;
    else if ((n % 3 == 0) || (n % 5 == 0))
        return 1;
    else 
        return 0;

}

float pesoIdeal(float h, char sexo)
{
    float  pesoIdeal = 0;

    if(sexo == 'M' || sexo == 'm'){
        pesoIdeal = (72.7 * h) - 58;
    } else {
        pesoIdeal = (62.1 * h) - 44.7;
    }

    return pesoIdeal;
}

float pesoIdealEx7(float h, char sexo, float peso)
{

    float  pesoIdeal = 0;

    if(sexo == 'M' || sexo == 'm'){
        pesoIdeal = (72.7 * h) - 58;
    } else {
        pesoIdeal = (62.1 * h) - 44.7;
    }

    if (pesoIdeal > peso){
        return pesoIdeal - peso;
    } else {
        return peso - pesoIdeal;
    }
}

int somaImpares(int N)
{
    int soma = 0;
    
    for (int  i = 0; i <= N; i++){
        if(i % 2 != 0)
            soma += i;
    }
    return soma;
}

double fatorial(int N)
{
    if(N == 0){
        return 1;
    }

    return N * fatorial(N-1);
}

int somaNumerosDiv3ou5(int N) 
{
    int soma = 0;
    for (int i = 0; i <= N; i++)
    {
        if ((i % 3 == 0) && (i % 5 == 0)) 
            continue;
        else if ((i % 3 == 0) || (i % 5 == 0))
            soma += i;
       
    }
    
    return soma;
}

float calculaMedia(int x, int y, int z, int operacao)
{
    
        switch (operacao)
        {
            case 1:
                return  cbrt(x * y * z);
            break;

            case 2:
                return  (x + (2 * y) + (3  * z)) / 6;
            break;

            case 3:
                return  3 / (1 / x + 1 / y + 1);
            break;

            case 4:
                return  (x + y + z) / 3;
            break;
        }

 return 0;
}

int numeroDivisores(int N)
{
    int divisores = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            divisores++;
        }
        
    }
    

    return divisores;
}

int enesimoFibonacci(int N)
{
    
    if (N == 0)
        return 0;
    if (N == 1 || N == 2)
        return  1;

    return enesimoFibonacci(N - 1) + enesimoFibonacci(N - 2);;
 
}

int mdc(unsigned int x, unsigned int y)
{

    int mdc = 0;

    int menor = x < y ? x : y;

    for (int i = 1; i <=  menor; i++)
    {
        if(x % i == 0 && y % i == 0)
        {
            mdc = i;
        }
    }
    

    return mdc;
}

int mmc(unsigned int x, unsigned int y)
{

   return (x*y) / mdc(x,y);
    
}