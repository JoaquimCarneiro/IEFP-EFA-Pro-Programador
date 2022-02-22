#ifndef INC_21_REVISOES_C_PERIODOESTUDO_H
#define INC_21_REVISOES_C_PERIODOESTUDO_H
#endif //INC_21_REVISOES_C_PERIODOESTUDO_H

/* Desenvolva um programa que pergunte em que turno estuda. Peça para digitar:
 *      M – Matutino
 *      V- Vespertino
 *      N – Noturno
 * Imprima a mensagem “Bom dia”, “Boa tarde” ou “Boa noite” Conforme o caso
 * */
void turnoEstudo(){
    char turno;
    int controle = 0;
    printf("Qual é o seu periodo de Estudo?\n"
           "\tM – Matutino\n"
           "\tV - Vespertino\n"
           "\tN – Noturno\n");
    do {
        if(controle > 0){
            printf("Valor inválido, escolha entre M, V ou N.");
        }
        printf("$: ");
        scanf("%s", &turno);
        controle ++;
    } while (turno != 'm' && turno != 'v' && turno != 'n' &&
             turno != 'M' && turno != 'V' && turno != 'N');

    if(turno == 'm' || turno == 'M'){
        printf("Bom dia, alegria!");
    }else if(turno == 'v' || turno == 'V'){
        printf("Boa tarde, o dia já arde!");
    }else{
        printf("Bom noite, a cama afoite!");
    }
}