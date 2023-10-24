#include <stdio.h>
#include <stdlib.h>

int exitKex(int displayType);
int typeOfWindows();
int reconnectKex(int displayType);

int main() {
    int opcao = 0;
    int displayType = 0;
    do {
        printf("\n");
        printf("O que você deseja fazer?\n");
        printf("1 - iniciar o Kex\n");
        printf("2 - reconectar ao Kex (utilizar se o kex está rodando em background)\n");
        printf("3 - fechar o Kex\n");
        printf("0 - sair do programa\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
		            displayType = typeOfWindows();
                break;
            case 2:
                if(reconnectKex(displayType) > 0){
                  printf("Kex reconectado com sucesso\n");
                }
                break;
            case 3:
                if(exitKex(displayType) > 0){
                  printf("Kex fechado com sucesso\n");
                }
                break;
            default:
                if(opcao != 0) {
                    printf("opção inválida\n");
                }
                break;
        }
    } while(opcao != 0);

    printf("saindo do Kex_Controller\n");

    return 0;
}

  int typeOfWindows() {
    int opcaoTypeofWindows = 0;
    printf("======================================================\n");
    printf("qual tipo de janela você deseja utilizar?\n");
    printf("1 - Enhanced Session Mode\n");
    printf("2 - Seamless Mode\n");
    printf("3 - Windows Mode\n");
    scanf("%d", &opcaoTypeofWindows);
    switch(opcaoTypeofWindows) {
      case 1:
        printf("Iniciando o Kex em Enhanced Session Mode\n");
        system("kex --esm --sound");
        return 1;
      case 2:
        printf("Iniciando o Kex em Seamless Mode\n");
        system("kex --sl --sound");
        return 2;
      case 3:
        printf("Iniciando o Kex em Windows Mode\n");
        system("kex --win --sound");
        return 3;
      default:
        printf("Opção inválida!\n");
        return 0;
  }

}

int exitKex(int displayType) {
	switch(displayType){
      case 0:
        printf("nenhuma instancia do Kex foi iniciada\n");
      case 1:
        system("kex --esm --stop");
      case 2:
        system("kex --sl --stop");
      case 3:
        system("kex --win --stop");
  }
  return 0;
}

int reconnectKex(int displayType) {
  switch(displayType){
      case 0:
        printf("nenhuma instancia do Kex foi iniciada\n");
        return 0;
      case 1:
        system("kex --esm --start-client");
        return 0;
      case 2:
        system("kex --sl --start-client");
        return 0;
      case 3:
        system("kex --win --start-client");
        return 0;
  }
}
