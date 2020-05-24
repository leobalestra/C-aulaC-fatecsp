#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main (int argc, char *argv[])
{
    setlocale(LC_ALL,"portuguese");

    //Declarar variáveis
    char entrada[200], saida[200], senha[25], escolha[1], extensao[20], sair[1];
    FILE *entra, *sai;
    int i, ch, tam_senha, cs, ponto;
    int achou = 1;

    //Verificar se passou o arquivo no argumento
    if(argc >= 2){
        strcpy(entrada, argv[1]);
	}
    else{
        printf("\nNome do arquivo:\n");
        gets(entrada);
	}

	//carregar arquivos
    entra = fopen(entrada, "rb");
    if(!entra)
    {
        printf("\nFalha na abertura do arquivo");
        exit(0);
    }

    if(argc >= 3){
        strcpy(escolha, argv[2]);
    }
    else{
	    printf("\nEscolha uma opção:\n [i] - Invert\n [c] - Cript\n [u] - Dos to Unix\n [d] - Unix to dos\n [q] - Quit -->: ");
        gets(escolha);
    }

    if(strcmp(escolha, "q") == 0){
        exit(0);
    }

	//Dá o nome para o arquivo de saída
    strcpy(saida, entrada);

    //Verificar se tem '.' e achar o indice dele
    for(i = strlen(entrada); i > 0 && achou != 0; i--){
	    if(entrada[i] == '.'){
    		ponto = i;
		    achou = 0;
	    }
	}

    //tirar a extensao do arquivo de saida
   	if(achou == 0){
        strncpy(saida, entrada, ponto);
  	    saida[ponto] = '\0';
   	}

   	//Saber qual extensao está no arquivo atual
   	if(achou == 0){
	    strncpy(extensao, entrada + ponto, strlen(entrada) - ponto);
   		extensao[strlen(entrada) - ponto] = '\0';
   	}

    //opção [i]
    //if(strcmp(argv[2], "i") == 0)
    if(strcmp(escolha, "i") == 0) //tirar
    {
   	    //Colocar a extensão no arquivo de sáida
	    //i = strlen(saida) - 1;
        //if(saida[i] == 'v' && saida[i-1] == 'n' && saida[i-2] == 'i' && saida[i-3] == '.'){
        //    strcat(saida, ".dnv");
        //}
        //else{
        //   strcat(saida, ".inv");
        //}

	    if(strcmp(extensao, ".inv") == 0){
		    strcat(saida, ".dnv");
	    }
	    else{
    		strcat(saida, ".inv");
	    }

	    //carregar arquivos
        sai = fopen(saida, "wb");

        if(!entra||!sai){
                printf("\nFalha nos arquivos");
        }

		// Inverter byte a byte
        ch = fgetc(entra);
        while(ch != EOF){
            ch=~ch;
            fputc(ch, sai);
            ch = fgetc(entra);
        }

    }

    //opção [c]
    //else if(strcmp(argv[2], "c") == 0)
    else if(strcmp(escolha, "c") == 0) //tirar
  	{
	    //Colocar a extensão no arquivo de saída
	    //i = strlen(saida) - 1;
        //if(saida[i] == 'p' && saida[i-1] == 'r' && saida[i-2] == 'c' && saida[i-3] == '.'){
        //    strcat(saida, ".drp");
        //}
        //else{
        //   strcat(saida, ".crp");
        //}

        if(strcmp(extensao, ".crp") == 0){
    		strcat(saida, ".drp");
	    }
	    else{
    		strcat(saida, ".crp");
	    }

	    //carregar arquivos
        sai = fopen(saida, "wb");

        //Verificar senha
        //if(argc >= 3){
        //    strcpy(senha, argv[3]);
        //}
        //else{
            printf("\nNome da senha:\n");
            gets(senha);
        //}

        if(!entra||!sai)
        {
            printf("\nFalha nos arquivos");
            exit(0);
        }

        tam_senha = strlen(senha);
        ch = fgetc(entra);
        cs = senha[0];
        i = 0;

        while(ch != EOF)
	    {
   		    while(i < tam_senha && ch != EOF){
                ch=ch^cs;
                fputc(ch, sai);
                ch = fgetc(entra);
                cs = senha[i+1];
                i = i + 1;
	        }
            i = 0;
        }
    }

    //opção [u]
    //else if(strcmp(argv[2], "u") == 0)
    else if(strcmp(escolha, "u") == 0) //tirar
   	{
        strcat(saida, ".unx");

        //carregar arquivos
        sai = fopen(saida, "wb");

        if(!entra||!sai)
        {
            printf("\nFalha nos arquivos");
            exit(0);
        }

        ch = fgetc(entra);

        while(ch != EOF){

                if(ch != 13){
                    fputc(ch, sai);
                }
                ch = fgetc(entra);
        }
    }

    //opção [d]
    //else if(strcmp(argv[2], "d") == 0)
    else if(strcmp(escolha, "d") == 0) //tirar
  	{
        strcat(saida, ".dos");

        //carregar arquivos
        sai = fopen(saida, "wb");

        if(!entra||!sai)
        {
            printf("\nFalha nos arquivos");
            exit(0);
        }

        ch = fgetc(entra);

        while(ch != EOF){

            if(ch == 10){
                fputc(13, sai);
                fputc(ch, sai);
            }
            else{
                fputc(ch, sai);
            }

            ch = fgetc(entra);
        }
    }
    else{
        printf("\n\nEscolha inválida!\n\n");
        exit(0);
    }
    fclose(entra);
    fclose(sai);
}
