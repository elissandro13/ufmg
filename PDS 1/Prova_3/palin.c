#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Aluno {
    char *nome;
    int id;
    float rsg;
}Aluno;

int checkPalindromo(char* str, int inicio, int final){

    if (inicio >= strlen(str)/2)
        return 1;
    if (str[inicio] != str[final-1])
    {
        //printf("%d, %d \n", start, final);
        return 0;
    }
        

    return checkPalindromo(str, inicio+1, final-1);
}

int ePalindromo(int num){
    
    //Questao 1
    int length = snprintf(NULL, 0, "%d", num);
    char str[length + 1];
    snprintf(str, length + 1, "%d", num);

    //printf("%d %s", length, str);
    return checkPalindromo(str, 0, length);

}

void stringMinuscula(char *str){

    if(str[0] == '\0'){
        //printf("\n%s", str);
        return;
    }
    str[0] = tolower(str[0]);
    stringMinuscula(str+1);
}

int funcElfo(char *str, char c) {
    
    if(str[0] == '\0'){
        return 0;
    }
    else if(str[0] == c)
        return 1;

    return funcElfo(str+1, c);
}



int ehElfica(char *str) {

    stringMinuscula(str);

    if (funcElfo(str, 'e') == 0 || funcElfo(str, 'l') == 0 || funcElfo(str, 'f') == 0)
    {
        return 0;
    }
    


    return 1;
}

char buscaMaior(char *str, char maior){

    if(str[0] == '\0'){
        return maior;
    }

    if(maior < str[0]) {
        maior = str[0];
        
    }

    

    return buscaMaior(str+1, maior);
}

void transformaStr(char *str) {

    if(str[0] == '\0'){
        printf("\n acabou\n");
        return;
    }

    str[0] = buscaMaior(str+1, str[0]);

    return transformaStr(str+1);
}

Aluno* buscaRSG(char nome_arquivo[]) {
    FILE *arq = fopen("students_x.csv", "r");
    char linha[1000];
    char *token;
    int linhas = 1;

    Aluno *alunos;
    int maior_rsg_pos = 0;
    //Aluno *maior_rsg = (Aluno*)malloc(sizeof(Aluno));

    while(fgets(linha,1024,arq))
        linhas++;

   alunos = (Aluno*)malloc((linhas+1)*sizeof(Aluno));
   int count = 0;
   
   rewind(arq);

    while(!feof(arq)){
        fgets(linha, 100, arq);
        token = strtok(linha, ",");
        alunos[count].id = atoi(token);
        token = strtok(NULL, ",");
        //printf("COnt %d %s\n",count,  token);
        alunos[count].nome = (char *)malloc((strlen(token)+1)*sizeof(char));
        strcpy(alunos[count].nome,token);
        //alunos[count].nome = token;
        token = strtok(NULL, ",");
    
        alunos[count].rsg = atof(token);

        if(count == 0){
            maior_rsg_pos = 0;
        } else if (alunos[maior_rsg_pos].rsg < alunos[count].rsg)
        {
            maior_rsg_pos = count;
        }
        
    
        

        //printf("%s %d %lf\n", alunos[count].nome, alunos[count].id, alunos[count].rsg);
        //printf("Maior %s %d %lf\n", maior_rsg.nome, maior_rsg.id, maior_rsg.rsg);


        count++;
    }
      fclose(arq);
    //printf("Maior %s %d %lf\n", alunos[maior_rsg_pos].nome, alunos[maior_rsg_pos].id, alunos[maior_rsg_pos].rsg);
    //for (int i = 0; i < count; i++)
    //{
    //    printf("%d %s %lf\n", alunos[i].id, alunos[i].nome, alunos[i].rsg);
    //}

    Aluno *melhor_aluno = &alunos[maior_rsg_pos];
    melhor_aluno->nome = alunos[maior_rsg_pos].nome;
   // melhor_aluno->id = alunos[maior_rsg_pos].id;
    //melhor_aluno->nome = alunos[maior_rsg_pos].nome;
    //melhor_aluno->rsg = alunos[maior_rsg_pos].rsg;


    
    //Aluno* melhor_aluno = malloc(sizeof(Aluno));
    //melhor_aluno->nome = (char *)malloc((strlen(alunos[maior_rsg_pos].nome)+1)*sizeof(char));
    //melhor_aluno->id = alunos[maior_rsg_pos].id;
    //strcpy(melhor_aluno->nome,alunos[maior_rsg_pos].nome);
    //melhor_aluno->rsg = alunos[maior_rsg_pos].rsg;
    
    int j = 0;
    while (j < count)
    {
        free(alunos[j].nome);
        j++;;
    }
    
    free(alunos);

    return melhor_aluno;
}

int somaVet(int v[], int n) {
    if(n == 1) {
        return v[0];
    }
    return v[n-1] + somaVet(v, n-1);
}

void freeMatriz(int **M, int n){

    if(n == 0) {
        free(M);
        return;
    }
    free(M[n-1]);
    freeMatriz(M, n-1);
}

int ** geraListaAdjacencias(int **M, int n) {
    int i, j, n_cols, count;
    int **ME = (int**)malloc(n*sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        n_cols = somaVet(M[i], n) + 1;
        //printf("Colunas %d\n", n_cols);
        ME[i] = (int*)malloc((n_cols+1) * sizeof(int));
        ME[i][n_cols] = -1;
        count = 0;
        for (j = 0; j < n; j++)
        {
            if(M[i][j] == 1){
                ME[i][count] = j;
                count++;
            }
        }
    }
    freeMatriz(M, n);
    
    return ME;
}


void buscaRisco(char* nome_arquivo) {
    
    FILE *arq = fopen(nome_arquivo, "r");
    char linha[1000];
    char *token;
    int linhas = 1;

    int ID = 0;
    int UR = 0;
    int PR = 0;
    float TMED = 0;

    while(!feof(arq)){
        fgets(linha, 1000, arq);
        token = strtok(linha, " ");
        ID = atoi(token);
        token = strtok(NULL, " ");
        UR = atoi(token);
        token = strtok(NULL, " ");
        PR = atoi(token);
        token = strtok(NULL, " ");
        TMED = atof(token);

        if((TMED/UR) - PR > 1) {
            FILE *saida = fopen("risks.txt", "a");
            float risco = (TMED/UR) - PR;
            fprintf(saida, "%d %0.2f\n", ID, risco);
            fclose(saida);
        }

        printf("%d %d %d %.2f \n", ID, UR, PR, TMED);

    }

    fclose(arq);
    
}

int main(){

    buscaRisco("monitoring_x.txt");
    //printf("\n%d", ePalindromo(123521));
    //char el[] = "zavab";
    //printf("%s", el);
    //transformaStr(el);
    //printf("%s", el);
    //printf("Come\n");
    //Aluno *a = buscaRSG("students_x.csv");
    //printf("Resultado final %d %s %lf\n", a->id, a->nome, a->rsg);
    /* int **m = (int**)malloc(4 * sizeof(int*));
    for (int index=0;index<4;++index)
    {
        m[index] = (int*)malloc(4 * sizeof(int));
    }
    
    printf("Ler matriz:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &m[i][j]);
        }
        
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    

    int **v = geraListaAdjacencias(m, 4); */

    //printf("Oba\n");
    //for (int i = 0; i != -1; i++)
    //{
    //    for (int j = 0;j != -1; j++)
    //    {
    //        printf("%d ", v[i][j]);
    //    }
    //    printf("\n");
    //}

    //printf("sadasd\n");
    return 0;
}