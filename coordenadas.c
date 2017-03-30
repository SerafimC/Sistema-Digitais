#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 70

//--------------------------Estruturas-----
FILE *out;

typedef struct coordenadas{
	int x, y;
} coordenada;

coordenada ponto;

typedef struct triangulos{
	coordenada a;
	coordenada b;
	coordenada c;
} triangulo;

triangulo trian1;

//------------------------Funções-------
int area(coordenada a, coordenada b, coordenada c);
int isInTriangle(coordenada p, triangulo t);
void createTriangulo();
void refreshPoint(int i, int j);
void writeOutput(triangulo trian1, coordenada pt);

int main(){
    int i, j;

    out = fopen("Result.txt", "w");

    //srand( time(NULL) );


    trian1.a.x = 32;
    trian1.a.y = 51;

    trian1.b.x = 23;
    trian1.b.y = 14;

    trian1.c.x = 69;
    trian1.c.y = 54;

    /*
    trian1.a.x = rand() % size + 1;
    trian1.a.y = rand() % size + 1;

    trian1.b.x = rand() % size + 1;
    trian1.b.y = rand() % size + 1;

    trian1.c.x = rand() % size + 1;
    trian1.c.y = rand() % size + 1;
    */
    for( i = 0; i < size; i++){
        for(j=0; j < size; j++){

            refreshPoint(i, j);

            if(isInTriangle(ponto, trian1) == 1){
                //printf(" X: %d Y: %d ", ponto.x, ponto.y);
                printf(" ");
            }
            else{
                printf("0");
            }

            writeOutput(trian1, ponto);
        }
        printf("\n");
	}
}

//--------------------------Funções-----

void writeOutput(triangulo trian1, coordenada pt){
	fprintf(out,"A(%d, %d),  ", trian1.a.x, trian1.a.y);

	fprintf(out,"B(%d, %d), ", trian1.b.x, trian1.b.y);

	fprintf(out,"C(%d, %d),  ", trian1.c.x, trian1.c.y);

	fprintf(out,"P(%d, %d) = ", pt.x, pt.y);

	if(isInTriangle(pt, trian1) == 1)
		fprintf(out,"1\n");
	else
		fprintf(out,"0\n");
}

int area(coordenada a, coordenada b, coordenada c){
    int result;
    result = (((a.x * b.y) - (a.y * b.x)) + ((a.y * c.x) - (a.x * c.y)) + ((b.x * c.y) - (b.y * c.x)));
    return result;
}

int isInTriangle(coordenada p, triangulo t){
    int b1, b2, b3;

	b1 = area(p, t.b, t.c);
	b2 = area(t.a, p, t.c);
	b3 = area(t.a, t.b, p);

	//printf("b1 = %d b2 = %d b3 = %d\n", b1, b2, b3);
	//printf("b1: %0.2f b2: %0.2f b3: %0.2f\n");

	if(b1 > 0 && b2 > 0 && b3 > 0){
        return 1;
    }
    else{
        return 0;
    }
}

void refreshPoint(int i, int j){
    ponto.x = j;
    ponto.y = i;
}
