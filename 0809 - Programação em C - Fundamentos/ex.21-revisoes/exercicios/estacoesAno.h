#ifndef INC_21_REVISOES_C_ESTACOESANO_H
#define INC_21_REVISOES_C_ESTACOESANO_H
#endif //INC_21_REVISOES_C_ESTACOESANO_H

/* Desenvolva um programa que determine a estação do ano a partir do numero do mês onde:
 *      - 1 a 3 = Inverno
 *      - 4 a 6 = Primavera
 *      - 7 a 9 = verão
 *      - 10 a 12 = outono
 * Exercicio alterado para ser mais preciso na determinação da estação:
 *      pede ano, mes, dia
 *      calcula se é bissexto
 *      determina o nome do mes por extenso e quantos dias este tem
 * */
void estacaoAno(){
    int mes, verificaImput = 0, dia, qtdDias, ano;
    char * mesExtenso;

    bool controleLoop = true, bissexto = false;

    while (controleLoop) {
        /* pedir ano */
        printf("\n\tintroduza o ano(superior a zero): ");
        do {
            if (verificaImput > 0) {
                printf("\tValor inválido, introduza um numero superior a zero: ");
            }
            scanf("%i%*[^\n]", &ano);
            verificaImput++;
        } while (ano < 0);
        verificaImput = 0; //reset á variavel, vai ser reutilizada quando se pedri por dia do mes

        /* Destermina se o ano é bissexto */
        if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0 ){
            bissexto = true;
        } else{
            bissexto = false;
        }

        /* pedir o mes do ano */
        printf("\n\tintroduza o numero do mês do ano (1-12): ");
        do {
            if (verificaImput > 0) {
                printf("\tValor inválido, introduza um numero de 1 a 12: ");
            }
            scanf("%i%*[^\n]", &mes);
            verificaImput++;
        } while (mes < 1 || mes > 12);
        verificaImput = 0;

        /* Determinar quantos dias tem o mes selcionado e qual é a sua designação por extenso */
        switch (mes) {
            case 1:
                mesExtenso = "janeiro";
                qtdDias = 31;
                break;
            case 2:
                mesExtenso = "fevereiro";
                if (bissexto){
                    qtdDias = 29;
                } else{
                    qtdDias = 28;
                }
                break;
            case 3:
                mesExtenso = "março";
                qtdDias = 31;
                break;
            case 4:
                mesExtenso = "abril";
                qtdDias = 30;
                break;
            case 5:
                mesExtenso = "maio";
                qtdDias = 31;
                break;
            case 6:
                mesExtenso = "junho";
                qtdDias = 30;
                break;
            case 7:
                mesExtenso = "julho";
                qtdDias = 31;
                break;
            case 8:
                mesExtenso = "agosto";
                qtdDias = 31;
                break;
            case 9:
                mesExtenso = "setembro";
                qtdDias = 30;
                break;
            case 10:
                mesExtenso = "outubro";
                qtdDias = 31;
                break;
            case 11:
                mesExtenso = "novembro";
                qtdDias = 30;
                break;
            default: // mes = 12
                mesExtenso = "dezembro";
                qtdDias = 31;
        }

        /* pedir o dia ao utilizador */
        printf("\tintroduza o dia do mês (1-%i): ", qtdDias);
        do {
            if (verificaImput > 0) {
                printf("\tValor inválido, introduza um numero de 1 a %i: ", qtdDias);
            }
            scanf("%i%*[^\n]", &dia);
            verificaImput++;
        } while (dia < 1 || dia > qtdDias);
        verificaImput = 0;

        printf("\nÉ %i de %s. ", dia, mesExtenso);
        if ((mes == 3 && dia >= 21) || (mes == 6 && dia <= 20) || (mes > 3 && mes < 6)) {
            printf("Está na Primavera.");
        } else if ((mes == 6 && dia >= 21) || (mes == 9 && dia <= 20) || (mes > 6 && mes < 9)) {
            printf("Está no Verão.");
        } else if ((mes == 9 && dia >= 21) || (mes == 12 && dia <= 20) || (mes > 9 && mes < 12)) {
            printf("Está no Outono.");
        } else {
            printf("Está no Inverno.");
        }
        printf("\n");

        controleLoop = perguntar_bool("Calcular outra estação do ano(s/n)?", 's', 'n');
    }
}