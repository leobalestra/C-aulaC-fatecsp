#include <stdio.h>
#include <stdlib.h>

/* Exercicio 2
int main()
{
    int num;
    int nd;
    
	printf ("Digite o núumero de lados de um poligono: ");
	scanf ("%d",&num);
	
	
	while (num < 3)
	{
        printf ("Um poligono possui mais de 2 lados\n");
        printf ("Digite o numero de lados de um poligono: ");
        scanf ("%d",&num);
    }
    
    nd = (num*(num-3))/2;

    printf("\n%d\n\n", nd);
  
  system("PAUSE");	
  return 0;
}*/

/* Exercício 3
int main()
{
    float num;
    float num_f;
    
	printf ("Informe o salario do funcionario: ");
	scanf ("%f",&num);
	
	num_f = num_f + num;
	
	if (num_f < 750.00)
	{
        num_f = num_f + 100.00;
    }
    
    num_f = num_f * 1.05;
    
    printf("\n\nO salario inicial e: %.2f\n\n", num);
    printf("O salario final e: %.2f\n\n", num_f);
    
  system("PAUSE");	
  return 0;
}*/

/* Exercicio 4
int main()
{
    float num_1;
    float num_2;
    
	printf ("Informe o primeiro numero: ");
	scanf ("%f",&num_1);
	
	printf ("\n\nInforme o segundo numero: ");
	scanf ("%f",&num_2);
	
    if (num_1 > num_2)
    {
        printf("\n\nA ordem crescente e: %.2f - %.2f\n\n", num_2, num_1);
    }
    else
    {
        printf("\n\nA ordem crescente e: %.2f - %.2f\n\n", num_1, num_2);
    }
    
  system("PAUSE");	
  return 0;
}*/

/*Exercicio 5
int main()
{
    float num_1;
    float num_2;
    float num_3;
    
	printf ("Informe o primeiro numero: ");
	scanf  ("%f",&num_1);
	printf ("\n\nInforme o segundo numero: ");
	scanf  ("%f",&num_2);
	printf ("\n\nInforme o segundo numero: ");
	scanf  ("%f",&num_3);
	
    if ((num_1 >= num_2) && (num_1 >= num_3))
    {
        printf("\n\nO maior numero e: %.2f\n\n", num_1);
    }
    else if ((num_2 >= num_1) && (num_2 >= num_3))
    {
        printf("\n\nO maior numero e: %.2f\n\n", num_2);
    }
    else --((num_3 >= num_1) && (num_3 >= num_2))
    {
        printf("\n\nO maior numero e: %.2f\n\n", num_3);
    }
    
  system("PAUSE");	
  return 0;
}*/

/* Exercicio 6*/

int main()
{
    float a,b,c;
    
    printf("Digite o primeiro numero: ");
    scanf("%f", &a);
    
    printf("Digite o segundo numero: ");
    scanf("%f", &b);
    
    printf("Digite o terceiro numero: ");
    scanf("%f", &c);
    
    if ((a<b) && (b<c))
        printf("\n A ordem crescente e o %.2f %.2f %.2f ", a,b,c);
    else
        if ((a<c) && (c<b))
            printf("\n A ordem crescente e o %.2f %.2f %.2f ", a,c,b);
        else
            if ((b<c) && (b<a))
                printf("\n A ordem crescente e o %.2f %.2f %.2f ", b,c,a);
            else
                if ((b<a) && (b<c))
                    printf("\n A ordem crescente e o %.2f %.2f %.2f ", b,a,c);
                else
                    if ((c<a) && (c<b))
                        printf("\n A ordem crescente e o %.2f %.2f %.2f ", c,a,b);
                    else
                        printf("\n A ordem crescente e o %.2f %.2f %.2f ", c,b,a);
    
  system("PAUSE");	
  return 0;
}/**/

/* Exercicio 7
int main()
{

  float num_1;
  float num_2;
   
  printf("Digite o primeiro numero: ");
  scanf("%f",&num_1);
   
  printf("Digite o segundo numero: ");
  scanf("%f",&num_2);
  
  num_1 >= num_2 ? printf("\n\nO maior numero e: %.2f\n\n",num_1) : printf("\n\nO maior numero e: %.2f\n\n",num_2);

  system("PAUSE");	
  return 0;
  
}*/



















































