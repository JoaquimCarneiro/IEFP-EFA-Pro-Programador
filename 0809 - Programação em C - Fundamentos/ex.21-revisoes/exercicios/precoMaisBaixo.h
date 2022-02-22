#ifndef INC_21_REVISOES_C_PRECOMAISBAIXO_H
#define INC_21_REVISOES_C_PRECOMAISBAIXO_H
#endif //INC_21_REVISOES_C_PRECOMAISBAIXO_H


/* Desenvolva um programa que pergunte o preço de três produtos e informe qual o produto que deve comprar,
 * sabendo que a decisão é sempre pelo mais barato. (use o ciclo IF)
 * */
void precoBaixo(){
    int num1, num2, num3;
    printf("Introduza o preço do primeiro produto: ");
    scanf("%i", &num1);
    printf("Introduza o preço do segundo produto: ");
    scanf("%i", &num2);
    printf("Introduza o preço do terceiro produto: ");
    scanf("%i", &num3);

    if(num1 < num2 && num1 < num3){
        printf("O primeiro produto, com o valor %i, é o mais adequado", num1);
    }else if(num2 < num1 && num2 < num3){
        printf("O segundo produto, com o valor %i, é o mais adequado", num2);
    }else{
        printf("O terceiro produto, com o valor %i, é o mais adequado", num3);
    }
}