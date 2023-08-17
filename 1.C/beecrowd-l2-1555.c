#include <stdio.h>

int funcaoRafael(int x,int y);
int funcaoBeto(int x,int y);  
int funcaoCarlos(int x,int y);  

int main(){
    int n, x, y;
    int i; 
    int resulRafael, resulBeto, resulCarlos;

    scanf("%d", &n);

    for (i=0; i<n; i++){
        scanf("%d %d", &x, &y);    

        resulRafael = funcaoRafael(x,y);
        resulBeto = funcaoBeto(x,y);
        resulCarlos = funcaoCarlos(x,y);

        if (resulRafael > resulBeto && resulRafael > resulCarlos){
            printf("Rafael ganhou\n");       
            
        }else if (resulBeto > resulRafael && resulBeto > resulCarlos)
        {
            printf("Beto ganhou\n");
        }else{
            printf("Carlos ganhou\n");
        }
    }
}

int funcaoRafael(int x,int y){
    return (9* x* x) + (y*y);
}
int funcaoBeto(int x,int y){
    return (2*x*x) + (25 *y*y);
} 
int funcaoCarlos(int x,int y){
    return (-100)*x + y*y*y;

}