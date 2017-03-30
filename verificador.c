#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    char c1, c2;
    FILE *input_file1,*input_file2,*Resultado;

    input_file1 = fopen("Result.txt","r");
    input_file2 = fopen("Result_verilog.txt","r");
    Resultado = fopen("Comparacao.txt","a");

    /*for(a=0;a<20
        fscanf(LeituraC,"%i",&entradac);
        fscanf(LeituraC,"%i",&entradav);
        if(entradac != entradav){
            fprintf(Resultado,"%i\n",a);
        }
    }
    */

    while(!feof(input_file1)){

        c1 = getc(input_file1);
        c2 = getc(input_file2);

        if(c1 != c2){
            fprintf(Resultado,"%c difere de %c\n", c1, c2);
        }
        else
            fprintf(Resultado, "%c", c1);

    }

    fclose(input_file1);
    fclose(input_file2);
    fclose(Resultado);

    return(0);
}
