#ifndef INC_21_REVISOES_C_PESQUISA_H
#define INC_21_REVISOES_C_PESQUISA_H
#endif //INC_21_REVISOES_C_PESQUISA_H


/* Foi feita uma pesquisa entre os habitantes de uma região. Foram coletados os dados de idade, sexo (M/F) e salário.
 * Faça um programa que calcule e mostre:
 *      a. A média dos salários do grupo;
 *      b. A maior e a menor idade do grupo;
 *      c. A quantidade de mulheres na região;
 *      d. A idade e o sexo da pessoa que possui o menor salário;
 *      e. Finalize a entrada de dados ao ser digitada uma idade negativa.
 * */
void pesquisa(){
    /* por não se estar a usar arrays ou vetores isto é uma festa de variaveis */
    int habitantes = 0, idade, idadeMin, idadeMax, mulheres = 0, idadeMenorSalario;
    float salario = 0, totalSalarios = 0, mediaSalarios, menorSalario;
    char sexo, sexoMenorSalario;
    while(true){ // loop infinito até se digitar -1 na idade
        printf("-== Introduza os dados do habitante =-\n");
        /* perguntar por idade, sexo e salário (as perguntas deveriam ser tranformadas em funções)
         * as perguntas não estão a verificar tipos de dados, isto pode provocar erros */
        // IDADE
        do {
            printf("Digite a idade do habitante: ");
            scanf("%i", &idade);
        } while (idade < -1);
        // se a idade for -1 sair do loop
        if(idade == -1){
            printf("a sair...\n");
            break;
        }

        //Genero
        do {
            printf("Digite o genero do habitante(m/f): ");
            scanf(" %c", &sexo); //quirk: " %c" tem que ser usado
            fflush(stdin);
        } while (sexo != 'm' && sexo != 'f' &&
                 sexo != 'M' && sexo != 'F');

        //salário
        do {
            printf("Digite o salário do habitante: ");
            scanf("%f", &salario);
        } while (salario < 0);

        //calcular média de salário
        totalSalarios += salario;
        mediaSalarios = totalSalarios / ((float)habitantes + 1);


        //calcular menor e maior idade
        //calcular idade e sexo do menor salario
        //no primeiro caso atribuir a idade a idadeMax e idadeMin
        // + menorSalario + sexoMenorSalario + idadeMenorSalario
        if(habitantes == 0){
            idadeMax = idade;
            idadeMin = idade;
            menorSalario = salario;
            sexoMenorSalario = sexo;
            idadeMenorSalario = idade;
        }else{
            if(idadeMax < idade){
                idadeMax = idade;
            }
            if(idadeMin > idade){
                idadeMin = idade;
            }
            if(menorSalario > salario){
                menorSalario = salario;
                sexoMenorSalario = sexo;
                idadeMenorSalario = idade;
            }
        }

        //calcular quantidade de mulheres na região
        if(sexo == 'f' || sexo == 'F'){
            mulheres ++;
        }

        //calcular quantidade de habitantes
        habitantes ++;

        printf("\n-========== Subtotais ==========-\n");
        printf("Total de habitantes: %i\n", habitantes);
        printf("Total de salarios: %.2f\n"
               "Média de salarios: %.2f\n", totalSalarios, mediaSalarios);
        printf("Idade máxima: %i\n", idadeMax);
        printf("Idade minima: %i\n", idadeMin);
        printf("Totalidade de mulheres: %i\n", mulheres);
        printf("O habitante com menor salário é do sexo ");
        if(sexoMenorSalario == 'f'){
            printf("feminino, ");
        } else{
            printf("masculino, ");
        }
        printf("tem %i anos de idade e um vencimento de %.2f €.\n", idadeMenorSalario, menorSalario);
        printf("-==================================-\n\n");
    }
    // output
    printf("-======= Resultados finais! =======-\n");
    printf("Total de habitantes: %i\n", habitantes);
    printf("Total de salarios: %.2f\n"
           "Média de salarios: %.2f\n", totalSalarios, mediaSalarios);
    printf("Idade máxima: %i\n", idadeMax);
    printf("Idade minima: %i\n", idadeMin);
    printf("Totalidade de mulheres: %i\n", mulheres);
    printf("O habitante com menor salário é do sexo ");
    if(sexoMenorSalario == 'f'){
        printf("feminino, ");
    } else{
        printf("masculino, ");
    }
    printf("tem %i anos de idade e um vencimento de %.2f €.\n", idadeMenorSalario, menorSalario);
    printf("-==================================-\n");
}
