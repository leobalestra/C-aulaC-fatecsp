#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    //Declarar variáveis
    char entrada[200], saida[200], senha[25], escolha[1];
    FILE *entra, *sai;
    int i, ch, tam_senha, cs;
    int tem = 0;

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
		printf("\nEscolha uma opção:\n [i] - Invert\n [c] - Cript\n [u] - Dos to Unix\n [d] - Unix to dos -->: ");
		gets(escolha);
	}

	//Dá o nome para o arquivo de saída
    strcpy(saida, entrada);

	//opção [i]
    //if(strcmp(argv[2], "i") == 0)
    if(strcmp(escolha, "i") == 0) //tirar
	{
		//Colocar a extensão no arquivo de sáida
		i = strlen(saida) - 1;
        if(saida[i] == 'v' && saida[i-1] == 'n' && saida[i-2] == 'i' && saida[i-3] == '.'){
            strcat(saida, ".dnv");
        }
        else{
           strcat(saida, ".inv");
		}

		//carregar arquivos
        sai = fopen(saida, "wb");

        if(!entra||!sai)
        {
            printf("\nFalha nos arquivos");
        }

		// Inverter byte a byte
        ch = fgetc(entra);
        while(ch != EOF)
		{
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
		i = strlen(saida) - 1;
        if(saida[i] == 'p' && saida[i-1] == 'r' && saida[i-2] == 'c' && saida[i-3] == '.'){
            strcat(saida, ".drp");
        }
        else
           strcat(saida, ".crp");

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

        while(ch != EOF)
		{
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

        while(ch != EOF)
		{
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
