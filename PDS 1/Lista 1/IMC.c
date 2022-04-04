#include <stdio.h>
#include <locale.h>

typedef struct 
{
    float peso;   
    float altura;    
    float imc;
    char *nome; 

} Pessoa;

int main() {

    setlocale(LC_ALL, "Portuguese_Brasil");
    Pessoa pessoa[2];

    // [0] = Brutos

    pessoa[0].altura = 1.84;
    pessoa[0].peso = 122;
    pessoa[0].nome = "Brutos";
    pessoa[0].imc = 0;

    // [1] Olivia

    pessoa[1].altura = 1.76;
    pessoa[1].peso = 45;
    pessoa[1].nome = "Olivia";
    pessoa[1].imc = 0;
    
    float peso_ideal = 0;

    for (int i = 0; i < 2; i++)
    {
        peso_ideal = 0;
         pessoa[i].imc = ((pessoa[i].peso) / (pessoa[i].altura * pessoa[i].altura));

        if (pessoa[i].imc > 25)
        {
            peso_ideal = 24.9 * (pessoa[i].altura * pessoa[i].altura);
            peso_ideal = pessoa[i].peso - peso_ideal;
            printf ("O IMC de %s e: %.2f. Para ter um peso saudavel, essa pessoa precisa perder, no minimo, %.2f kg. \n\n", pessoa[i].nome, pessoa[i].imc, peso_ideal);
        }
        else 
        {
            if (pessoa[i].imc >= 18.5)
            {
                printf ("O IMC de %s e: %.2f. Isso quer dizer que essa pessoa esta com um peso saudavel!\n\n", pessoa[i].nome ,pessoa[i].imc);
            }
            else
            {
                peso_ideal = 18.5 * (pessoa[i].altura * pessoa[i].altura);
                peso_ideal -= pessoa[i].peso;
                printf ("O IMC de %s e: %.2f. Para ter um peso saudavel, essa pessoa precisa ganhar, no minimo, %.2f kg. \n\n", pessoa[i].nome, pessoa[i].imc, peso_ideal);
            }
        }
    }

    return 0;
}