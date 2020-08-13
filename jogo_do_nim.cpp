#include <bits/stdc++.h>

using namespace std;

void aviso_pecas(int q, bool flag){
    if(q > 1){
        printf("Agora restam %i peças no tabuleiro.\n\n", q);
    }
    else if(q == 0 && !flag) {
        puts("Fim do jogo! O computador ganhou!\n");
    }
    else if(q == 0 && flag) {
        puts("Fim do jogo! Você ganhou!\n");
    }
    else {
        puts("Agora resta apenas uma peça no tabuleiro!\n");
    }
}


bool decisao(int n, int m) {
    if(n%(m+1) == 0) {
        return true;
    }
    else {
        return false;
    }
}

int computador_escolhe_jogada(int n, int m) {
    int r;
    bool flag = false;
    
    for(int i=m; i>0; i--) {
        if((n - i) % (m+1) == 0) {
            r=i;
            break;
        }
        else {
            r=m;
        }
    }
    
    if(n-r<0) {
        r = r - (r - n);
    }
    if(r>1) {
        printf("O computador tirou %i peças.\n", r);
    }
    else {
        puts("O computador tirou uma peça.\n");
    }
    
    aviso_pecas(n-r, flag);
    
    return r;
}


int usuario_escolhe_jogada(int n, int m) {
    bool flag_two = false;
    bool flag_one = true;
    int r;
    
    while(!flag_two) {
        puts("Quantas peças você vai tirar?");
        printf("> ");
        scanf("%i", &r);
        
        if(r > m || r <= 0) {
            puts("\nOops! Jogada inválida! Tente novamente.\n");
        }
        else {
            flag_two = true;
        }
    }
    
    if(r>1) {
        printf("Você tirou %i peças.\n", r);
    }
    else {
        puts("Você tirou uma peça\n");
    }
    
    aviso_pecas(n-r,flag_one);
    
    return r;
}


bool partida() {
    int n, m, r;
    puts("Número de peças");
    printf("> ");
    scanf("%i", &n);
    puts("");
    puts("Limite de peças por jogada");
    printf("> ");
    scanf("%i", &m);
    puts("");
    
    bool flag = false;
    
    if(decisao(n,m)) {
        puts("\nVocê começa!\n");
        r = usuario_escolhe_jogada(n,m);
        n-=r;
        flag = true;
    }
    else {
        puts("\nComputador começa!\n");
        r = computador_escolhe_jogada(n,m);
        n-=r;
        flag = false;
    }
    
    while(n>0) {
        if(flag) {
            r = computador_escolhe_jogada(n,m);
            n-=r;
            flag = false;
        }
        else {
            r = usuario_escolhe_jogada(n,m);
            n-=r;
            flag = true;
        }
    }
    
    if(flag) {
        return true;
    }
    else {
        return false;
    }
}


void campeonato() {
    int placar_user = 0, placar_pc = 0;
    
    for(int i=1;  i<4;  i++) {
        printf("**** Rodada %d ****\n", i);
        int valor = partida();
        if(valor) {
            placar_user++;
        }
        else {
            placar_pc++;
        }
    }
    
    puts("**** Final do campeonato! ****");
    
    printf("Placar: Você %d X %d Computador\n", placar_user, placar_pc);
}


void controle_partida(int n) {
    switch(n) {
        case 1:
        puts("Você escolheu uma partida isolada!\n");
        partida();
        break;
        
        case 2:
        puts("Você escolheu um campeonato!\n");
        campeonato();
        break;
        
    }
}


int main() {
    puts("\nBem-vindo ao jogo do NIM! Escolha:\n");
    puts("1 - para jogar uma partida isolada");
    puts("2 - para jogar um campeonato\n");
    int x=0;
    
    while(x>2 || x<1) {
        printf("> ");
        scanf("%i", &x);
        if(x> 2 || x<1) {
            puts("Opção inválida");
        }
    }
    puts("");
    controle_partida(x);
    
    return 0;
}