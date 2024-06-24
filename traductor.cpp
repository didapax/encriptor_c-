#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

enum alfabeto {a=1,b=2,c=3,d=5,e=8,f=13,g=21,h=34,i=55,j=89,k=144,l=233,m=377,n=610,o=987,p=1597,q=2584,r=4181,s=6765,t=10946,u=17711,v=28657,w=46368,x=75025,y=121393,z=196418,zero=317811,uno=514229,dos=832040,tres=1346269,cuatro=2178309,cinco=3524578,seis=5702887,siete=9227465,ocho=14930352,nueve=24157817,espacio=39088169,intro=63245986};
char *encriptar(char valor);
char dencriptar(int valor);
int main (int argc, char *argv[]){
	FILE *archivo;
	char letra;
	char nvalor[34];
	int cont=0;
	char t;
	unsigned int i=0;
	if( strcmp(argv[1],"-c")==0){
		for(i=0;i<strlen(argv[2]);i++)
			printf("%s",encriptar(argv[2][i]));
	}
	else if (strcmp(argv[1],"-d")==0){
		for(i=0;i<strlen(argv[2]);i++){
			t=argv[2][i];
			if(t=='+'){
				for(cont=0;cont<34;cont++){
					nvalor[cont]= argv[2][i+1];
					i++;
					if(argv[2][i]=='-'){
						printf("%c",dencriptar(atoi(nvalor)));
						strcpy(nvalor,"");
						break;						
					}
				}
			}
		}
	}
	else if (strcmp(argv[1],"-cf")==0){
		archivo = fopen(argv[2],"r");
		while(feof(archivo)==0){
			letra=fgetc(archivo);			
			printf("%s",encriptar(letra));
		};
		fclose(archivo);
	}
	else if (strcmp(argv[1],"-df")==0){
		i=0;
		archivo = fopen(argv[2],"r");
		while(feof(archivo)==0){
			letra=fgetc(archivo);
			if(letra=='+'){
				i=0;
			}
			nvalor[i]= letra;
			i++;
			if(letra=='-'){
						nvalor[i]='\0';
						printf("%c",dencriptar(atoi(nvalor)));
						strcpy(nvalor,"");						
			}
		};
		fclose(archivo);
	}	
	return 0;	
}

char *encriptar(char valor){
	alfabeto alfa;
	char *cadena=(char*)malloc(sizeof(char*));
	switch (valor){
		case 'a': alfa = a;
		break;
		case 'b': alfa = b;
		break;		
		case 'c': alfa = c;
		break;
		case 'd': alfa = d;
		break;
		case 'e': alfa = e;
		break;		
		case 'f': alfa = f;
		break;
		case 'g': alfa = g;
		break;
		case 'h': alfa = h;
		break;
		case 'i': alfa = i;
		break;
		case 'j': alfa = j;
		break;
		case 'k': alfa = k;
		break;	
		case 'l': alfa = l;
		break;
		case 'm': alfa = m;
		break;
		case 'n': alfa = n;
		break;
		case 'o': alfa = o;
		break;		
		case 'p': alfa = p;
		break;
		case 'q': alfa = q;
		break;
		case 'r': alfa = r;
		break;
		case 's': alfa = s;
		break;	
		case 't': alfa = t;
		break;
		case 'u': alfa = u;
		break;
		case 'v': alfa = v;
		break;
		case 'w': alfa = w;		
		break;		
		case 'x': alfa = x;
		break;
		case 'y': alfa = y;
		break;
		case 'z': alfa = z;		
		break;	
		case '0': alfa = zero;
		break;
		case '1': alfa = uno;
		break;
		case '2': alfa = dos;				
		break;					
		case '3': alfa = tres;
		break;
		case '4': alfa = cuatro;
		break;
		case '5': alfa = cinco;				
		break;		
		case '6': alfa = seis;
		break;
		case '7': alfa = siete;
		break;
		case '8': alfa = ocho;				
		break;		
		case '9': alfa = nueve;				
		break;
		case ' ': alfa = espacio;						
		break;						
		case '\n': alfa = intro;	
	}
	sprintf(cadena,"+%i-",alfa);
	return cadena;
}

char dencriptar(int valor){
	char cadena;
	switch (valor){
		case 1: cadena= 'a';
		break;
		case 2: cadena= 'b';
		break;		
		case 3: cadena= 'c';
		break;
		case 5: cadena= 'd';
		break;
		case 8: cadena= 'e';
		break;
		case 13: cadena= 'f';
		break;
		case 21: cadena= 'g';
		break;
		case 34: cadena= 'h';
		break;
		case 55: cadena= 'i';
		break;
		case 89: cadena= 'j';
		break;
		case 144: cadena= 'k';
		break;
		case 233: cadena= 'l';
		break;
		case 377: cadena= 'm';
		break;
		case 610: cadena= 'n';
		break;
		case 987: cadena= 'o';
		break;
		case 1597: cadena= 'p';
		break;
		case 2584: cadena= 'q';
		break;
		case 4181: cadena= 'r';
		break;
		case 6765: cadena= 's';
		break;
		case 10946: cadena= 't';
		break;
		case 17711: cadena= 'u';
		break;
		case 28657: cadena = 'v';
		break;
		case 46368: cadena= 'w';
		break;
		case 75025: cadena= 'x';
		break;
		case 121393: cadena= 'y';
		break;
		case 196418: cadena= 'z';
		break;
		case 317811: cadena= '0';
		break;
		case 514229: cadena= '1';
		break;
		case 832040: cadena= '2';
		break;
		case 1346269: cadena= '3';
		break;
		case 2178309: cadena= '4';
		break;
		case 3524578: cadena= '5';
		break;
		case 5702887: cadena= '6';
		break;
		case 9227465: cadena= '7';
		break;
		case 14930352: cadena= '8';
		break;
		case 24157817: cadena= '9';
		break;
		case 39088169: cadena= ' ';
		break;
		case 63245986: cadena= '\n';
	}
	return cadena;
}
