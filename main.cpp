#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

char v[21][5500];
int bin[21][20100];
char resto[2];


void input(){
	FILE * fl = fopen("Chaves_de_Cripto.txt","r");
	for(int i = 0 ; i<20; i++){
		fgets(v[i],5003,fl);
		fgets(resto,2,fl);
	}	
		fclose(fl);
}

void imprimeHex(){
	for(int i=1;i<=5000;i++){
		printf("%c",v[0][i]);
	}
}

void imprimeBin(){
	for(int j=0; j<20;j++){
			printf("\nChave %d = \n",j);
		for(int i=0;i<20000;i++){
			printf("%d",bin[j][i]);
		}
	}			
}

void converter(){
	for(int j = 0 ; j<20 ; j++){
		int flag = 0;
		
		for(int i = 1; i <= 5000 ; i++)
		{
		    if(v[j][i] == '0')
		    {
		        bin[j][flag] = 0;
		        bin[j][flag+1] = 0;
		        bin[j][flag+2] = 0;
		        bin[j][flag+3] = 0;
		    	flag = flag + 4;
		    }
		    
		    else if(v[j][i] == '1')
		    {
		        bin[j][flag] = 0;
		        bin[j][flag+1] = 0;
		        bin[j][flag+2] = 0;
		        bin[j][flag+3] = 1;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == '2')
		    {
		        bin[j][flag] = 0;
		        bin[j][flag+1] = 0;
		        bin[j][flag+2] = 1;
		        bin[j][flag+3] = 0;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == '3')
		    {
		       	bin[j][flag] = 0;
		        bin[j][flag+1] = 0;
		        bin[j][flag+2] = 1;
		        bin[j][flag+3] = 1;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == '4')
		    {
		       	bin[j][flag] = 0;
		        bin[j][flag+1] = 1;
		        bin[j][flag+2] = 0;
		        bin[j][flag+3] = 0;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == '5')
		    {
		    	bin[j][flag] = 0;
		        bin[j][flag+1] = 1;
		        bin[j][flag+2] = 0;
		        bin[j][flag+3] = 1;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == '6')
		    {
		    	bin[j][flag] = 0;
		        bin[j][flag+1] = 1;
		        bin[j][flag+2] = 1;
		        bin[j][flag+3] = 0;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == '7')
		    {
		    	bin[j][flag] = 0;
		        bin[j][flag+1] = 1;
		        bin[j][flag+2] = 1;
		        bin[j][flag+3] = 1;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == '8')
		    {
		    	bin[j][flag] = 1;
		        bin[j][flag+1] = 0;
		        bin[j][flag+2] = 0;
		        bin[j][flag+3] = 0;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == '9')
		    {
		    	bin[j][flag] = 1;
		        bin[j][flag+1] = 0;
		        bin[j][flag+2] = 0;
		        bin[j][flag+3] = 1;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == 'A')
		    {
		        bin[j][flag] = 1;
		        bin[j][flag+1] = 0;
		        bin[j][flag+2] = 1;
		        bin[j][flag+3] = 0;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == 'B')
		    {
		    	bin[j][flag] = 1;
		        bin[j][flag+1] = 0;
		        bin[j][flag+2] = 1;
		        bin[j][flag+3] = 1;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == 'C')
		    {
		    	bin[j][flag] = 1;
		        bin[j][flag+1] = 1;
		        bin[j][flag+2] = 0;
		        bin[j][flag+3] = 0;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == 'D')
		    {
		    	bin[j][flag] = 1;
		        bin[j][flag+1] = 1;
		        bin[j][flag+2] = 0;
		        bin[j][flag+3] = 1;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == 'E')
		    {
		    	bin[j][flag] = 1;
		        bin[j][flag+1] = 1;
		        bin[j][flag+2] = 1;
		        bin[j][flag+3] = 0;
		        flag = flag + 4;
		    }
		    
		    else if(v[j][i] == 'F')
		    {
		    	bin[j][flag] = 1;
		        bin[j][flag+1] = 1;
		        bin[j][flag+2] = 1;
		        bin[j][flag+3] = 1;
		        flag = flag + 4;
		    }
	  	}
	}
}

int monoBit[21];
void monobit(){
  
    printf("\n----- MONOBIT TEST -----");
    for(int j=0; j<20;j++){
        for(int i=0;i<20000;i++){
            if(bin[j][i] == 1){
                monoBit[j] = monoBit[j] + 1;
            }
        }
        printf("\n Na chave %d existem %d numeros 1 \n",j+1,monoBit[j]);
    }
}


int pokerTest[21][16];
void pokerTeste(){
  for(int i=0;i<20;i++){
    	for(int j=1; j<=5000; j++){
	    	if(v[i][j] == '0'){
	        	pokerTest[i][0] = pokerTest[i][0]+1;
	      	}  
	      	if(v[i][j] == '1'){
	        	pokerTest[i][1] = pokerTest[i][1]+1;
	      	}  
	      	if(v[i][j] == '2'){
	        	pokerTest[i][2] = pokerTest[i][2]+1;
	      	}  
	      	if(v[i][j] == '3'){
	       		pokerTest[i][3] = pokerTest[i][3]+1;
	      	}  
	      	if(v[i][j] == '4'){
	        	pokerTest[i][4] = pokerTest[i][4]+1;
	      	}  
	      	if(v[i][j] == '5'){
	        	pokerTest[i][5] = pokerTest[i][5]+1;
	      	}  
	      	if(v[i][j] == '6'){
	        	pokerTest[i][6] = pokerTest[i][6]+1;
	      	}  
	      	if(v[i][j] == '7'){
	        	pokerTest[i][7] = pokerTest[i][7]+1;
	      	}  
	      	if(v[i][j] == '8'){
	        	pokerTest[i][8] = pokerTest[i][8]+1;
	      	}  
	      	if(v[i][j] == '9'){
	        	pokerTest[i][9] = pokerTest[i][9]+1;
	      	}  
	      	if(v[i][j] == 'A'){
	        	pokerTest[i][10] = pokerTest[i][10]+1;
	      	}  
	      	if(v[i][j] == 'B'){
	        	pokerTest[i][11] = pokerTest[i][11]+1;
	      	}  
	      	if(v[i][j] == 'C'){
	        	pokerTest[i][12] = pokerTest[i][12]+1;
	      	}  
	      	if(v[i][j] == 'D'){
	        	pokerTest[i][13] = pokerTest[i][13]+1;
	      	}  
	      	if(v[i][j] == 'E'){
	        	pokerTest[i][14] = pokerTest[i][14]+1;
	      	}  
	      	if(v[i][j] == 'F'){
	        	pokerTest[i][15] = pokerTest[i][15]+1;
	      	}  
    	}
	}

    float teste [21];
    for(int i = 0; i < 20; i++){
           float soma = 0;
        for(int j = 0; j <= 15; j++){
           soma = soma + pow(pokerTest[i][j],2);
         }
     teste[i] = 16.0/5000.0 * soma;
     teste[i] = teste[i] - 5000;
    }
    
    printf("\n\n\n----- POKER TEST -----");
  	for(int i = 0 ; i<20; i++){
   		printf("\n Chave %d",i);
   		printf("\n Qtd de 0 = %d",pokerTest[i][0]);
		printf("\n Qtd de 1 = %d",pokerTest[i][1]);
		printf("\n Qtd de 2 = %d",pokerTest[i][2]);
		printf("\n Qtd de 3 = %d",pokerTest[i][3]);
		printf("\n Qtd de 4 = %d",pokerTest[i][4]);
		printf("\n Qtd de 5 = %d",pokerTest[i][5]);
		printf("\n Qtd de 6 = %d",pokerTest[i][6]);
		printf("\n Qtd de 7 = %d",pokerTest[i][7]);
		printf("\n Qtd de 8 = %d",pokerTest[i][8]);
		printf("\n Qtd de 9 = %d",pokerTest[i][9]);
		printf("\n Qtd de A = %d",pokerTest[i][10]);
		printf("\n Qtd de B = %d",pokerTest[i][11]);
		printf("\n Qtd de C = %d",pokerTest[i][12]);
		printf("\n Qtd de D = %d",pokerTest[i][13]);
		printf("\n Qtd de E = %d",pokerTest[i][14]);					
		printf("\n Qtd de F = %d",pokerTest[i][15]);	   
	    printf("\n A chave %d  resultou em: %f",i,teste[i]);
	    printf("\n");
	}
}

int runTest0[21][2];
int runTest1[21][2];
int runTest2[21][2];
int runTest3[21][2];
int runTest4[21][2];
int runTest5[21][2];
int runTest6[21][2];

void runTest()
{
  
    for (int i = 0; i < 20; i++)
    {

        int flag = 0;
        while(flag < 20000){

            int flag1=0;
            while(bin[i][flag] == 1){
                flag1++;
                flag++;
            }

            int flag0=0;
              while(bin[i][flag] == 0){
                flag0++;
                flag++;
            }

            if (flag1 == 1 )
                runTest1[i][1] = runTest1[i][1] + 1;

            if(flag1 == 2){
                runTest2[i][1] = runTest2[i][1] +1;
            }
            if(flag1 == 3){
                runTest3[i][1] = runTest3[i][1] +1;
            }
            if(flag1 == 4){
                runTest4[i][1] = runTest4[i][1] +1;
            }
            if(flag1 == 5){
                runTest5[i][1] = runTest5[i][1] +1;
            }
            if(flag1 >= 6 ){
                runTest6[i][1] = runTest6[i][1] +1;
            }

            if(flag0 == 1)
                runTest1[i][0] = runTest1[i][0] + 1;

            if(flag0 == 2){
                runTest2[i][0] = runTest2[i][0] +1;
            }
            if(flag0 == 3){
                runTest3[i][0] = runTest3[i][0] +1;
            }
            if(flag0 == 4){
                runTest4[i][0] = runTest4[i][0] +1;
            }
            if(flag0 == 5){
                runTest5[i][0] = runTest5[i][0] +1;
            }
            if(flag0 >= 6 ){
                runTest6[i][0] = runTest6[i][0] +1;
            }

        }
    }

    printf("\n\n\n----- RUN TEST -----");
    for (int i = 0; i < 20; i++)
    {
        printf("\n\n Chave %d",i+1);
        printf("\n Numero de sequencias de tamanho 1:");
        printf("\n 0 = %d",runTest1[i][0]);
        printf("\n 1 = %d",runTest1[i][1]);
        printf("\n Numero de sequencias de tamanho 2:");
        printf("\n 0 = %d",runTest2[i][0]);
        printf("\n 1 = %d",runTest2[i][1]);
        printf("\n Numero de sequencias de tamanho 3:");
        printf("\n 0 = %d",runTest3[i][0]);
        printf("\n 1 = %d",runTest3[i][1]);
        printf("\n Numero de sequencias de tamanho 4:");
        printf("\n 0 = %d",runTest4[i][0]);
        printf("\n 1 = %d",runTest4[i][1]);
        printf("\n Numero de sequencias de tamanho 5:");
        printf("\n 0 = %d",runTest5[i][0]);
        printf("\n 1 = %d",runTest5[i][1]);
        printf("\n Numero de sequencias de tamanho 6+:");
        printf("\n 0 = %d",runTest6[i][0]);
        printf("\n 1 = %d",runTest6[i][1]);
    }
}

int longRunTest[21][2];
void LongRunTest(){
    printf("\n\n\n----- LONG RUN TEST -----");
    for (int i = 0; i < 20; i++)
    {

        int flag = 0;
        while(flag < 20000){

            int flag1=0;
            while(bin[i][flag] == 1 && flag < 20000){
                flag1++;
                flag++;
            }

            int flag0=0;
              while(bin[i][flag] == 0 && flag < 20000){
                flag0++;
                flag++;
            }

            if(flag0 >= 34){
                printf(" \nValor de flag0 %d", flag0);
                longRunTest[i][0] = longRunTest[i][0] + 1;
            }
            if(flag1 >= 34){
                printf("\nValor de flag1 %d", flag1);
                longRunTest[i][1] = longRunTest[i][1] + 1;
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        printf("\n Chave %d",i+1);
        printf("\n Numero de sequencias de tamanho 34+:");
        printf("\n 0 = %d",longRunTest[i][0]);
        printf("\n 1 = %d",longRunTest[i][1]);
    }

}



int main(){
	input();
	converter();
	//imprimeHex();
	//imprimeBin();
  	monobit();
  	pokerTeste();
  	runTest();
  	LongRunTest();
}
