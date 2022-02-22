#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "funcoes.h"
#include "exercicios/mediaSimples.h"
#include "exercicios/estacoesAno.h"
#include "exercicios/somarNumMaisBaixo.h"
#include "exercicios/precoMaisBaixo.h"
#include "exercicios/periodoEstudo.h"
#include "exercicios/pesquisa.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    char opcao = '0';
    int repetir_pergunta = 0;
    bool continuar = true;

    while (continuar) {//loop total (ha melhor maneiras de fazer isto)
        //menu
        printf("Escolha uma opção:\n"
               "\tA - Calcular média simples dos alunos (Ex. 1).\n"
               "\tB - Imprimir a estação do ano (Ex. 2)\n"
               "\tC - Somar numeros mais baixos (Ex. 2b)\n"
               "\tD - Selecionar preço mais baixo (Ex. 3)\n"
               "\tE - Qual é o seu periodo de estudo? (Ex. 4)\n"
               "\tF - Pesquisa de habitantes (Ex. 5)\n"
               "\tQ - Sair\n");
        //loop pergunta do menu
        do {
            if (repetir_pergunta != 0) {
                printf("Opção inválida, escolha outra vez...\n");
            }
            printf("$: ");
            /* O scanf está a pedir uma "string" (%s) para colocar num char, se for introduzido o valor de opção repetidamente,
             * por exemplo, aaaaaa, o scanf aceita o valor, assumindo somente o primeiro caractere da "string".
             * Se for usado char no scanf a repetição de caracteres na introdução de dados provoca a saida abrupta do programa.
             * Pode-se modificar a variavel para uma "string" (char opcao[1]) mas é necessário mudar o switch para uma cadeia
             * de if/else if porque o switch só aceita dados do tipo inteiro ou caractere */
            scanf(" %c%*[^\n]", &opcao);
            repetir_pergunta++;
        } while (opcao != 'a' && opcao != 'b' && opcao != 'c' && opcao != 'd' && opcao != 'e' && opcao != 'f' &&
                 opcao != 'q' &&
                 opcao != 'A' && opcao != 'B' && opcao != 'C' && opcao != 'D' && opcao != 'E' && opcao != 'F' &&
                 opcao != 'Q');
        repetir_pergunta = 0; //reset a variavel de controle
        //processamento de escolhas
        switch (opcao) {
            case 'a':
            case 'A':
                printf("\n####[ Calculadora de nota de alunos ]####\n");
                mediaSimples();
                break;
            case 'b':
            case 'B':
                printf("\n####[ Imprimir a estação do ano ]####\n");
                estacaoAno();
                break;
            case 'c':
            case 'C':
                printf("\n####[ Somar os numeros mais baixos ]####\n");
                somarMaisBaixo();
                break;
            case 'd':
            case 'D':
                printf("\n####[ Selecionar o preço mais baixo ]####\n");
                precoBaixo();
                break;
            case 'e':
            case 'E':
                printf("\n####[ periodo de estudo ]####\n");
                turnoEstudo();
                break;
            case 'f':
            case 'F':
                printf("\n####[ Pesquisa de habitantes ]####\n");
                pesquisa();
                break;
            case 'q':
            case 'Q':
                printf("\n####[ Ho no, ho no, ho no no no no noooooo ]####\n\n");
                return sair();
        }
        continuar = perguntar_bool("Deseja voltar ao menu inicial(s/n)?", 's', 'n');
    }
    return sair();
}
