#ifndef INC_21_REVISOES_C_FUNCOES_H
#define INC_21_REVISOES_C_FUNCOES_H
#endif //INC_21_REVISOES_C_FUNCOES_H

/* faz uma pergunta e devolve uma "string"
 * limitaçãoes:
 *      - não admite espaços (limitação/funcionamento do scanf)
 * pergunta - pregunta a fazer ao utilizador
 * resposta - variável pointer que vai conter a resposta
 * */
const char * perguntar_string(const char * pergunta, char * resposta, int tamanhoResposta){
    /* Cria o formato a ser utilizado no scanf
     * ------ tem problemas ao ser utilizado dentro de uma função
     * ------ scanf tem o formato "hardcoded"
     * ------ int tamanhoResposta era um argumento */

    // os tamanhos destas strings estão hardcoded!!!
    char tamanhoToString[99]; //strings tem limite de 6 digitos (1 000 000 de caracteres... lol)
    char formato[120];
    strcpy(formato,"%");
    //Converte o número inteiro tamanhoResposta para uma "string" (vá se lá saber pq é que limita a 4 caracteres em vez de 6)
    sprintf(tamanhoToString, "%i", tamanhoResposta);

    //sucessão de concatenações para finalizar o formato
    strcat(formato, tamanhoToString);
    strcat(formato, "s%*[^\n]");
    printf("%s", formato);

    printf("%s", pergunta);
    //resposta já é um apontador não precisa da referência(&)
    scanf(formato, resposta);
    return resposta;
}

/* Fazer uma pregunta simples do tipo boleano:
 *  devolve um boleano
 *  aceita uma "string" (pergunta)
 *  aceita dois caracteres como resposta (s/n, v/f, ...)*/
bool perguntar_bool(const char *pergunta, char verdadeiro, char falso){
    char continuar;
    int valor = 0;
    printf("\n%s ",pergunta);
    do {
        if(valor > 0){
            printf("Valor inválido, escolher entre %c e %c\n", verdadeiro, falso);
        }
        scanf(" %c%*[^\n]", &continuar); // lovely quirk

        valor ++;
    } while (continuar != verdadeiro && continuar != falso);
    if (continuar == falso) {
        return false;
    } else{
        return true;
    }
}

/* função para sair*/
int sair(){
    for (int i = 10; i >= 0; i--) {
        printf("\rT-minus %i",i);
        fflush(stdout);
        usleep(300000); //sleep() nao estava a funcionar como pretendido
    }
    printf("\naté à próxima");
    return 1;
}