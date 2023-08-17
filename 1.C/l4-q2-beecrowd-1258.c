#include <stdio.h>
#include <string.h>

struct Camisa {
    char nome[60];
    char size[60];
    char cor[60];
};

int main (){
    int n, i, j, k, l; 
    int compCor = 0, compSize = 0, compNome = 0;
    char letra;
    struct Camisa camisaTemp;
    scanf("%d", &n);

    while(n !=0){
        getchar();
        struct Camisa camisa[n];
        for(i=0; i<n;i++){
            letra = getchar();
            j=0;
            while (letra != '\n')
            {
                camisa[i].nome[j] = letra;
                j++;
                letra = getchar();
            }
            camisa[i].nome[j] = '\0';
            
            scanf("%s %s", &camisa[i].cor, camisa[i].size);
            letra = getchar();
        }

        for(k=0; k<n; k++){
            for (l=k+1; l<n; l++){
                compCor = strcmp(camisa[k].cor, camisa[l].cor);
                if (compCor >0){
                    camisaTemp = camisa[k];
                    camisa[k] = camisa[l];
                    camisa[l] = camisaTemp;

               }
            }
        }

        for(k=0; k<n; k++){
            for (l=k+1; l<n; l++){
                compCor = strcmp(camisa[k].cor, camisa[l].cor);
                compSize = strcmp(camisa[k].size, camisa[l].size);
                if (compSize<0 && compCor == 0){
                    camisaTemp = camisa[k];
                    camisa[k] = camisa[l];
                    camisa[l] = camisaTemp;
               }
            }
        }

        for(k=0; k<n; k++){
            for (l=k+1; l<n; l++){
                compCor = strcmp(camisa[k].cor, camisa[l].cor);
                compSize = strcmp(camisa[k].size, camisa[l].size);
                compNome = strcmp(camisa[k].nome, camisa[l].nome);
                if (compNome >0 && compSize==0 && compCor == 0){
                    camisaTemp = camisa[k];
                    camisa[k] = camisa[l];
                    camisa[l] = camisaTemp;
               }
            }
        }

        for(k=0; k<n; k++){
        printf("%s %s %s\n", camisa[k].cor, camisa[k].size, camisa[k].nome);
        }
    
        scanf("%d", &n);
        if(n == 0){
        break;
        }
        printf("\n");
    }
    
        return 0;
}
