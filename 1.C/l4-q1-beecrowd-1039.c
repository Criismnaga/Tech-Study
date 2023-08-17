#include <stdio.h>
#include <math.h>

struct Pontos {
    int coordX;
    int coordY;
};

struct FireFlower {
    int raioFlor;
    struct Pontos posicao;
};

struct Hunter {
    int raioCacador;
    struct Pontos posicao;
};

double DistCentros(struct Pontos p1, struct Pontos p2){
    double x = p2.coordX - p1.coordX;
    double y = p2.coordY - p1.coordY;
    double elevadox = pow(x, 2);
    double elevadoy = pow(y, 2);
    double quadrado = elevadox + elevadoy;
    double DistCentros = sqrt(quadrado);
    return DistCentros;
}

int main(){
    struct Hunter cacador;
    struct FireFlower flor;
    while(scanf("%d %d %d %d %d %d", &cacador.raioCacador, &cacador.posicao.coordX, &cacador.posicao.coordY, &flor.raioFlor, &flor.posicao.coordX, &flor.posicao.coordY) != EOF){
        double dist = DistCentros(cacador.posicao, flor.posicao);
        if( abs(flor.raioFlor) + dist <= abs(cacador.raioCacador)) printf("RICO\n");
        else printf("MORTO\n");
    }
    return 0;
}