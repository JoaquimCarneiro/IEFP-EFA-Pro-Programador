#ifndef INC_21_REVISOES_C_SOMARNUMMAISBAIXO_H
#define INC_21_REVISOES_C_SOMARNUMMAISBAIXO_H

#endif //INC_21_REVISOES_C_SOMARNUMMAISBAIXO_H

/* Desenvolva um programa que solicite quatro números e imprima a soma dos três menores. Use um ciclo IF */
void somarMaisBaixo(){
    int num1, num2, num3, num4, soma;
    printf("Introduza o primeiro numero: ");
    scanf("%i", &num1);
    printf("Introduza o segundo numero: ");
    scanf("%i", &num2);
    printf("Introduza o terceiro numero: ");
    scanf("%i", &num3);
    printf("Introduza o quarto numero: ");
    scanf("%i", &num4);
    if(num1 > num2 && num1 > num3 && num1 > num4){
        soma = num2 + num3 + num4;
    }else if(num2 > num1 && num2 > num3 && num2 > num4){
        soma = num1 + num3 + num4;
    }else if(num3 > num1 && num3 > num2 && num3 > num4){
        soma = num1 + num2 + num4;
    }else {
        soma = num1 + num2 + num3;
    }
    printf("A soma é %i", soma);
}