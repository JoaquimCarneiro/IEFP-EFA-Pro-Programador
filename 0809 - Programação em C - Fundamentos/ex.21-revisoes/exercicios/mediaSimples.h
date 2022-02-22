#ifndef INC_21_REVISOES_C_EX1_H
#define INC_21_REVISOES_C_EX1_H
#endif //INC_21_REVISOES_C_EX1_H

/* ==== EX.1
 * Desenvolva um programa que permita determinar se o aluno está aprovado ou reprovado
 * tendo em conta as seguintes condições:
 *  - Média dos 3 testes >=10
 *  - Número de faltas <=3
 * */
void mediaSimples(){
    //falta verificar tipo de dados
    float nota, media = 0;
    int contador = 1, faltas = 0, maxFaltas = 3, nAlunos = 0;
    char nome[16], sobrenome[16];
    bool controleLoop = true;

    while (controleLoop){
        printf("\n -= Nome =-\n");

        perguntar_string("\tIntroduza o nome do aluno: ", nome, 16);
        perguntar_string("\tIntroduza o sobrenome do aluno: ", sobrenome, 16);

        printf("\n -= Notas =-\n");
        while (contador <= maxFaltas){
            printf("\tIntroduzir a %ia nota: ", contador);
            scanf("%f", &nota);
            media += nota;
            contador ++;
        }
        contador = 1;
        media = media / 3;

        printf("\n -= Faltas =-\n");
        printf("\tIntroduza o numero de faltas: ");
        scanf("%i", &faltas);

        //output
        printf("\n -= Avaliação =-\n");
        printf("O aluno %s %s está ", nome, sobrenome);
        if(media >= 10 && faltas <= 3){
            printf("aprovado com ");
        }else{
            printf("reprovado com ");
        }
        printf("a média de %.2f e %i faltas\n", media, faltas);

        nAlunos ++;
        controleLoop = perguntar_bool("Calcular a nota de outro aluno?", 's', 'n');
    }
}