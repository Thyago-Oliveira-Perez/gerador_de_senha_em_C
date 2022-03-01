#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>

int main(void)
{
   int seta = 1, enter = 0, escolha;
   printf("---- Gerador de Senhas ----\n");

   menu(seta, enter, &escolha);

   switch(escolha){
    case 6:
        gerarSenhaDoZero();
        break;
    case 7:
        criptoGrafarSenha();
        printf("\n\nIn progress");
        break;

    case 8:
        printf("Encerrando");
        for(int i = 0; i < 3; i++){
           Sleep(500);
           printf(".");
        }
        exit(0);
        break;
   }
   return 0;
}

void menu(int seta, int enter, int *escolha){
       while(1){
       opcoes(&seta);
       movimentoSeta(&seta, &enter);
       if(enter != 0 && seta != 0){
            *escolha = seta + enter;
            break;
       }
   }
}

void criptoGrafarSenha(){
    srand(time(NULL));
    int i = 0, tamanhoSenha, posicaoSenha, posicaoPalavra, posicaoCaracteres;
    char palavra[i], caractere;
    char* senha [tamanhoSenha];
    char* caracteres[63] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                           "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "W", "Y","Z",
                           "#", "@", "!", "$", "%", "&", "^", "?", "~", "+", "=",
                           "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
                           "n", "o", "p", "q", "r", "s", "t", "u", "v", "x", "w", "y", "z"};

    printf("Digite uma palavra para criptografar:");
    while(1){
        caractere = getch();
        printf("%c", caractere);
        if(caractere == 13){
            break;
        }
        palavra[i] = caractere;
        i += 1;
    }

    int tamanhoPalavra = strlen(palavra);

    system("cls");

    printf("Digite o tamanho da senha que deseja: ");
    scanf("%d", &tamanhoSenha);

    if(tamanhoSenha <= tamanhoPalavra){
        printf("O tamanho da senha deve ser maior que o da palavra digitada.\n");
        Sleep(800);
        system("cls");
        criptoGrafarSenha();
    }

   /* for(int i = 0; i < tamanhoSenha; i++){
        posicaoSenha = rand() % tamanhoSenha;
        posicaoPalavra = rand() % tamanhoPalavra;
        posicaoCaracteres = rand() % 63;
        if(posicaoSenha != posicaoPalavra && posicaoSenha != posicaoCaracteres && posicaoPalavra != posicaoCaracteres){
            senha[posicaoSenha] = palavra[posicaoPalavra];
            senha[posicaoPalavra] = caracteres[posicaoCaracteres];
        }
    } */

    for(int i = 0; i < tamanhoSenha; i++){

        posicaoSenha = rand() % tamanhoSenha;
        int temp = palavra[i];
        palavra[i] = palavra[posicaoSenha];
        palavra[posicaoSenha] = temp;

        posicaoPalavra = rand() % tamanhoSenha;
        senha[posicaoPalavra] = palavra[posicaoSenha];

    }



    for(int i = 0; i < tamanhoSenha; i++){
        printf("%c", senha[i]);
    }

}

void gerarSenhaDoZero(){

  int a, tamanhoSenha;
  system("cls");
  printf("Digite o tamanho da senha que deseja:");
  scanf("%d", &tamanhoSenha);

  srand(time(NULL));

  char* caracteres[63] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                           "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "W", "Y","Z",
                           "#", "@", "!", "$", "%", "&", "^", "?", "~", "+", "=",
                           "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
                           "n", "o", "p", "q", "r", "s", "t", "u", "v", "x", "w", "y", "z"};
  char* palavra[tamanhoSenha];

  for(int y = 0; y < tamanhoSenha; y++){
    a = rand() % 63;
    palavra[y] = caracteres[a];
  }

  for (int i=0; i < tamanhoSenha; i++)
  {
    printf("%s", palavra[i]);
  }

}

void movimentoSeta(int *seta, int *enter){
    char getcH = getch();
    if(getcH == 80){
        *seta += 1;
        if(*seta > 3){
            *seta = 1;
        }
    }else if(getcH == 72){
            *seta -= 1;
        if(*seta < 1){
            *seta = 3;
        }
    }else if(getcH == 13){
        *enter = 5;
    }
}

void opcoes(int *seta){
    if(*seta == 1){
        system("cls");
        printf("---- Gerador de Senhas ----\n");
        printf("> Gerar senha automatico\n");
        printf("Criptografar senha\n");
        printf("Sair\n");
    }else if(*seta == 2){
        system("cls");
        printf("---- Gerador de Senhas ----\n");
        printf("Gerar senha automatico\n");
        printf("> Criptografar senha\n");
        printf("Sair\n");
    }else if(*seta == 3){
        system("cls");
        printf("---- Gerador de Senhas ----\n");
        printf("Gerar senha automatico\n");
        printf("Criptografar senha\n");
        printf("> Sair\n");
    }
}
