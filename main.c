#include <stdio.h>
#include <windows.h>

int VerificarGanhador(int matrizJogo[3][3], int xouo) {

  int aux = 0;

  for(int cont_1 = 0; cont_1 < 3; cont_1++) {

    for (int cont_2 = 0, cont_3 = 0; cont_2 < 3; cont_2++) {

      if (matrizJogo[cont_1][cont_2] == xouo) {

        cont_3++;

        if(cont_3 == 3){

          aux = 1;

        } 
      }
    }
  }

  for(int cont_1 = 0; cont_1 < 3; cont_1++) {

    for (int cont_2 = 0, cont_3 = 0; cont_2 < 3; cont_2++) {

      if (matrizJogo[cont_2][cont_1] == xouo) {

        cont_3++;

        if(cont_3 == 3){

          aux = 1;

        } 
      }
    }
  }

  for(int cont_1 = 0, cont_2 = 0, cont_3 = 0; cont_1 < 3; cont_1 ++, cont_2 ++){

     if (matrizJogo[cont_1][cont_2] == xouo) {

        cont_3++;

        if(cont_3 == 3){

          aux = 1;

        } 
      }

  }

  for(int cont_1 = 0, cont_2 = 2, cont_3 = 0; cont_1 < 3; cont_1 ++, cont_2 --){

     if (matrizJogo[cont_1][cont_2] == xouo) {

        cont_3++;

        if(cont_3 == 3){

          aux = 1;

        } 
      }

  }

  return aux;
}

int NumerosJogados(int vetorNumerosJogados[9], int numeroEscolhido){

  int aux = 0;

  for (int cont_1 = 0; cont_1 < 9; cont_1++){

    if(vetorNumerosJogados[cont_1] == numeroEscolhido){

       aux = 1; 

    }
  }

  return aux;
}

void ImprimeMatrizJogo(int matriz[3][3]) {

  system("cls");

  printf("\n\t  Jogo da Velha Player X Player\n");

  int matrizTabuleiro[5][5];

  for (int cont_1 = 0, cont_3 = 0; cont_1 < 5; cont_1 += 2, cont_3++) {

    for (int cont_2 = 0, cont_4 = 0; cont_2 < 5; cont_2 += 2, cont_4++) {

      matrizTabuleiro[cont_1][cont_2] = matriz[cont_3][cont_4];
    }
  }

  for (int cont_1 = 0; cont_1 < 5; cont_1 += 2) {

    for (int cont_2 = 1; cont_2 < 5; cont_2 += 2) {

      matrizTabuleiro[cont_1][cont_2] = 179;
    }
  }

  for (int cont_1 = 1; cont_1 < 5; cont_1 += 2) {

    for (int cont_2 = 0; cont_2 < 5; cont_2 += 2) {

      matrizTabuleiro[cont_1][cont_2] = 196;
    }
  }

  for (int cont_1 = 1; cont_1 < 5; cont_1 += 2) {

    for (int cont_2 = 1; cont_2 < 5; cont_2 += 2) {

      matrizTabuleiro[cont_1][cont_2] = 197;
    }
  }

  printf("\n\n");

  for (int cont_1 = 0; cont_1 < 5; cont_1++) {

    printf("\t\t      ");

    for (int cont_2 = 0; cont_2 < 5; cont_2++) {

      printf("%c", matrizTabuleiro[cont_1][cont_2]);
    }

    printf("\n");
  }

  printf("\n\n\n");
}

/*
            1 │ 2 │ 3

            ─ ┼ ─ ┼ ─

            4 │ 5 │ 6

            ─ ┼ ─ ┼ ─

            7 │ 8 │ 9
*/

int main(void) {

  //Define o título da janela do console.
  SetConsoleTitle("Jogo da Velha");

  //Pegando o identificador do buffer do console.
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 

  //Define as coordenadas dos cantos superior esquerdo e inferior direito do console.
  SMALL_RECT tamanhoConsole = {0, 0, 49, 34};

  //Define o tamanho e a posição do console.
  SetConsoleWindowInfo(hConsole, TRUE, &tamanhoConsole);

  COORD coordenada = {50, 35};

  //Altera o tamanho do buffer do console.
  SetConsoleScreenBufferSize(hConsole, coordenada);
    
  int placarPlayer1X = 0;
  int placarPlayer2O = 0;

  while(1) {

    int matrizJogo[3][3];
    int vetorNumerosJogados[9];
    int jogadasRealizadas = 0;
    int ganhador = 0;

    for(int cont_1 = 0, cont_3 = 49; cont_1 < 3; cont_1++) {

      for (int cont_2 = 0; cont_2 < 3; cont_2++) {

        matrizJogo[cont_1][cont_2] = cont_3;

        cont_3++;
      }
    }

    for(int cont_1 = 0; cont_1 < 9; cont_1 ++){

        vetorNumerosJogados[cont_1] = 0;
    } 

    for(int cont_1 = 0; cont_1 < 9 && ganhador != 1;) {

      ImprimeMatrizJogo(matrizJogo);

      int numeroEscolhido = 0;

      if (cont_1 % 2 == 0) {

        printf("\t         Vez do Player 1 X\n\n\n\t\t        ");
        scanf("%d", &numeroEscolhido);

        numeroEscolhido = numeroEscolhido + 48;

        if (numeroEscolhido >= 49 && numeroEscolhido <= 57 && NumerosJogados(vetorNumerosJogados, numeroEscolhido) != 1) {

          for (int cont_1 = 0; cont_1 < 3; cont_1++) {

            for (int cont_2 = 0; cont_2 < 3; cont_2++) {

              if (matrizJogo[cont_1][cont_2] == numeroEscolhido) {

                matrizJogo[cont_1][cont_2] = 'X';
              }
            }
          }

          vetorNumerosJogados[cont_1] = numeroEscolhido;

          if(cont_1 > 3){

            ganhador = VerificarGanhador(matrizJogo, 'X');

          }    

          cont_1++;

        } else {

          printf("\n\n\t      ! Numeral Inadequado !");

          Sleep(450);
        }

      } else {

        printf("\t         Vez do Player 2 O\n\n\n\t\t        ");

        scanf("%d", &numeroEscolhido);

        numeroEscolhido = numeroEscolhido + 48;

        if (numeroEscolhido >= 49 && numeroEscolhido <= 57 &&
            NumerosJogados(vetorNumerosJogados, numeroEscolhido) != 1) {

          for (int cont_1 = 0; cont_1 < 3; cont_1++) {

            for (int cont_2 = 0; cont_2 < 3; cont_2++) {

              if (matrizJogo[cont_1][cont_2] == numeroEscolhido) {

                matrizJogo[cont_1][cont_2] = 'O';
              }
            }
          }

          vetorNumerosJogados[cont_1] = numeroEscolhido;

          if(cont_1 > 3){

            ganhador = VerificarGanhador(matrizJogo, 'O');

          }

          cont_1++;

        } else {

          printf("\n\n\t      ! Numeral Inadequado !");
          Sleep(450);
        }
      }

      jogadasRealizadas++;

    }

    if(jogadasRealizadas % 2 != 0 && ganhador == 1) {

      printf("\n\n\t      -----------------------\n");
      printf("\t      | Player 1 X Ganhou ! |\n");
      printf("\t      -----------------------\n");

      placarPlayer1X++;
    }

    if(jogadasRealizadas % 2 == 0 && ganhador == 1) {

      printf("\n\n\t      -----------------------\n");
      printf("\t      | Player 2 O Ganhou ! |\n");
      printf("\t      -----------------------\n");

      placarPlayer2O++;
    }

    if(jogadasRealizadas == 9 && ganhador == 0){

      printf("\n\n\t       --------------------\n");
      printf("\t       | O Jogo Empatou ! |\n");
      printf("\t       --------------------\n");

    }

    printf("\n\n       ------------------------------------\n");
    printf("       |\t      Placar\t\t  |\n");
    printf("       |\t\t\t\t  |\n");
    printf("       | Player 1 X (%d)    Player 2 O (%d) |\n", placarPlayer1X, placarPlayer2O);
    printf("       ------------------------------------\n\n\n");

    for(int cont_1 = 0; cont_1 == 0;){

      int aux = 0;

      printf("\tPressione 1 para uma nova partida.\n\n\tPressione 2 para sair do programa.\n\n\t\t        ");
      scanf("%d", &aux);

      if(aux == 1){

        cont_1 = 1;

      }

      if(aux == 2){

        exit(0);

      }

    }

  }

  return 0;
}

// system("cls");
