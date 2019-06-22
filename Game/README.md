# DESVIANDO DO F.I. 

 
## Sobre
O projeto foi baseado no jogo de arcade, chamado Space Invaders, com a junção da rotina do universitário, em especial, estudantes da Universidade Federal de Santa Catarina – CTJ.  

O Game é reproduzido no próprio Terminal do Linux, onde ocorre uma queda de notas e F.I’s, o objetivo é desviar de notas abaixo de 6,0 e dos F.I’s (frequência insuficiente). O usuário será uma figura representando um estudante na parte inferior da tela, utilizando as setas direita/esquerda do teclado movimenta o personagem na horizontal.  

O jogo é dividido em 3 fases, P1, P2 e P3. Onde mudando de fase, o nível de dificuldade aumenta:  

P1 = Fácil; P2 = Médio; P3 = Difícil. 

Pegando as notas maior ou igual  à 6.0, a nota em questão é somado ao seu score, chamado I.A, obtendo um ranking após o término das fases. 

Caso pegue notas abaixo de 6.0, o Score (I.A) irá diminuir equivalente ao valor que falta para completar a nota mínima. Ex.: Se apanhar a nota 4,0, será diminuído do Score, 2,00. 

 

Se for pego F.I, será FIM DE JOGO. 

 
Clique P para PARAR o jogo. 

 

Em qualquer momento, clique ESC para voltar a tela inicial. 

 

## Requisitos para a reprodução do Jogo: 

Linux  

Pacotes: `sudo apt install sox libsox-fmt-all gawk konsole kate`  

sox - libsox-fmt-all  

gawk  

konsole  

kate  

 

## Instruções  

Compilação/execução: 

`f=GAME; gcc -o ../bin/$f *.c -Wall; ../bin/./$f` 
