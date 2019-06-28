#include <stdio.h>
#include <char.h>
#include "ranking.h"
#include "score_h"
#include "nome.h"
#include "conio.h"

int main(void){

int d;

    do{ printf("Digite 1 para INSTRUÇÕES \n 2 para JOGAR \n 3 para RANKING");
        scanf ("%d", &d);
        
        if (d < 1 && d > 3){
            printf ("Opção Inválida");
        }
            if (d = 1){
                printf("INSTRUÇÕES: \n Mexa as setas direita/esquerda para mover, pegue somente as notas acima ou igual a 6. Caso capture notas abaixo, sua pontuação irá diminuir o valor equivalente ao faltante para o valor mínimo. Desvie dos F.I, se não, GAME OVER \n A qualquer momento clique ESC para sair");
            }
      
    
            if (d = 2) {
                char nome[61];
  
                printf("Digite seu nome: ");
                scanf("%s",nome);
  
                getch();

        }
        
        
        
            if (d = 3){
                if (iaa1 >= 6)  { 
                    if (iaa2 >= 6) {
                        if (iaa1 > iaa2) {
                        printf ("RANKING:\n iaa1 \n iaa2 "%2.f %2.f);
                        }
                        else {
                        printf ("RANKING: \n iaa2 \n iaa1" %2.f %2.f);
                        }
                    }
                    else {
                    printf("Tente Novamente");
                    }
            
                else {
                printf ("Tente Novamente");
                }
                }
        
            }
    
  //  while {
        
   //    1 <= d || d <= 3;
  }
return(0);
    }
