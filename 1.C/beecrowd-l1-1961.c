#include <stdio.h>

int main(){
    int p, n;
    
    scanf("%d %d", &p, &n);

    int puloAlturaLista[n];
       
    for(int i=0; i<n; i++){
        scanf("%d", &puloAlturaLista[i]);
    }
    int canoDif; 

    for(int i=0; i<n-1; i++){
        canoDif = puloAlturaLista[i+1] - puloAlturaLista[i];
        printf("diferença é: %d\n", canoDif);
        if(canoDif > p || canoDif < -p){
            printf("GAME OVER\n");
            return 0;   
        }
    }
    printf("YOU WIN\n");
    return 0;
}