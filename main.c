#include <stdio.h>
#include <stdlib.h>
FILE *nomes;
FILE *provas;
FILE *trabalhos;

void inicializaArquivos(){
    // nomes dos arquivos: nomes.txt, provas.txt, trabalhos.txt

    nomes = fopen("nomes.txt", "r+");
    provas = fopen("provas.txt", "r+");
    trabalhos = fopen("trabalhos.txt", "r+");
    if(nomes == NULL){
        nomes = fopen("nomes.txt", "w+");
        printf("nao existia, criei");
    }
    if(provas == NULL){
        provas = fopen("provas.txt", "w+");
    }
    if(trabalhos == NULL){
        trabalhos = fopen("trabalhos.txt", "w+");
    }
    if(nomes == NULL || trabalhos==NULL || provas == NULL){
        printf("Um ou mais arquivos nao puderam ser criados. O programa sera fechado");
        exit(1);
    }
    fclose(nomes);
    fclose(provas);
    fclose(trabalhos);
    return;
}

int entraValor(){
    int entrada = 0;
    while(1){
        scanf("%d", &entrada);
        fflush(stdin);
        if(entrada == 1 || entrada == 2 || entrada == 3){
            return entrada;
        }
        else{
            printf("Entrada invalida, digite novamente: \n");
        }
    }
    return 0;
}

// FUNCOES PARA INCLUIRAÇUNO()

const char * pegaNUSP(){
    char NUSP[9];
    int flag = 0;
    scanf("%s", &NUSP);
    fflush(stdin);
    while(flag == 0){
        if(sizeof(NUSP) != 9){
            printf("Numero de caracteres incorreto, digite novamente: \n");
            scanf("%s", &NUSP);
            fflush(stdin);
        }
        else if((NUSP[0]<'0' || NUSP[1]<'0' ||  NUSP[2]<'0' ||  NUSP[3]<'0' ||  NUSP[4]<'0' ||  NUSP[5]<'0' || NUSP[6]<'0' || NUSP[7]<'0') ||
                (NUSP[0]>'9' || NUSP[1]>'9' ||  NUSP[2]>'9' ||  NUSP[3]>'9' ||  NUSP[4]>'9' ||  NUSP[5]>'9' || NUSP[6]>'9' || NUSP[7]>'9')
                ){
                  printf("Erro na formatacao do NUSP, digite novamente: \n");
                  scanf("%s", &NUSP);
                  fflush(stdin);
                }
        else{
            flag = 1;
        }
    }
    printf("%s", NUSP);
    return NUSP;
}

void incluirAluno(){

    printf("Para inserir o aluno desejado, digite numero USP: \n");
    char NUSP[9] = pegaNUSP();
    printf("%s", NUSP);
}


// FIM DAS FUNCOES PARA INCLUIR ALUNO()
int main()
{
    inicializaArquivos();
    printf("Bem vindo!\n\n");
    char mainFlag = 's';
    while(mainFlag == 's' || mainFlag == 'S'){
        printf("Selecione uma acao (1-Incluir / 2-Remover / 3-Consultar): \n");
        int primeiroValor = entraValor();
        printf("Selecione uma acao (1-Alunos / 2-Provas / 3-Trabalhos): \n");
        int segundoValor = entraValor();
        if(primeiroValor == 1 && segundoValor == 1){
                incluirAluno();
        }

        if(primeiroValor == 1 && segundoValor == 2){
                //incluirProva();
                printf("Incluir prova");
                fprintf(nomes, "TESTANDO MANO");
        }

        if(primeiroValor == 1 && segundoValor == 3){
                //incluirTrabalho();
        }

        if(primeiroValor == 2 && segundoValor == 1){
                //removerAluno();
        }

        if(primeiroValor == 2 && segundoValor == 2){
                //removerProva();
        }

        if(primeiroValor == 2 && segundoValor == 3){
                //removerTrabalho();
        }

        if(primeiroValor == 3 && segundoValor == 1){
                //consultarAluno();
        }

        if(primeiroValor == 3 && segundoValor == 2){
                //consultarProva();
        }

        if(primeiroValor == 3 && segundoValor == 3){
                //consultarTrabalho();
        }
        printf("Deseja realizar mais alguma acao? (s/n)");
        scanf("%c", &mainFlag);
        fflush(stdin);
        while(mainFlag != 's' && mainFlag != 'n' && mainFlag != 'S' && mainFlag != 'N'){
            printf("Comando nao reconhecido, digite novamente: \n");
            scanf("%c", &mainFlag);
            fflush(stdin);
        }
    }
    fclose(nomes);
    fclose(provas);
    fclose(trabalhos);
    return 0;
}
