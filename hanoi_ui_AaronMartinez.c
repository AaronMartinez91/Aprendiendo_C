#include <stdio.h>
#include <stdlib.h>

/*
	Autor: Willoom //Modificado por Aaron Martinez (estudiante)
	Fecha: 9 de diciembre de 2024
	Descripción:

		Al jugador se le imprime por pantalla una representación ASCII
		de los ejes tal como
  #     |     |
 ###    |     |
#####   |     |

		En el juego, el jugador ha de pasar un disco por turno a otro eje.

		Existen restricciones: 

			- no podemos poner un disco de diámetro superior sobre otro de 
			diámetro inferior, 

			- no podemos mover un disco desde un eje sin discos,

			- sólo podemos mover un disco a la primera posición inferior libre
			del eje destino. 
 
*/


/*

FUNCIÓN: hanoi_ui_3discos

PARÁMETROS: int * posicion_discos
			Este puntero al primer entero de un array de tres registra las posiciones de los discos
			en cada eje.

			Por tanto sus valores válidos serán:
			-> 1 eje izquierdo
			-> 2 eje central
			-> 3 eje derecho

			Si los valores del array son 3, 2, 1 el resultado esperado a visualizar por pantalla sería:

  |     |     |
  |     |     |
#####  ###    #	 

*/

void hanoi_ui_3discos(int* posiciones) {
	//en primer lugar creo un array multidimensional donde guardare los discos como valores numericos, hago el mismo uso de mi ejercicio completo de hanoi (3=disco grande, 2= mediano, 3 = pequenyo)
	int registro_estado[3][3] = {
		{0,0,0},
		{0,0,0},
		{0,0,0}
	};

	int valor_disco = 3; //como cada vez que itere colocare "un disco distinto" y siempre son 3 y de mayor a menor, con esta variable me aseguro de que la primera vez que "guardo" uno es el grande, y va bajando de medida conforme los "coloco en la array"
	for(int i = 2; i >= 0; i--){
		if(posiciones[i] == 1){
			if(registro_estado[2][0] == 0){ //en este caso la iteracion es simple, si el valor de posiciones es 1, corresponde a la primera torre, por lo que en mi matriz es la primera columna. Por eso en este if solo controlo los valores de esta. Sigo la misma logica que en mi ejercicio (si es 0 esta vacio y puedo colocar, en caso contrario paso al siguiente hueco potencialmente vacio)
				registro_estado[2][0] = valor_disco;
				valor_disco--;
			}
			else if(registro_estado[1][0] == 0){
				registro_estado[1][0] = valor_disco;
				valor_disco--;
			}
			else{
				registro_estado[0][0] = valor_disco;
				valor_disco--;
			}
		}
		if(posiciones[i] == 2){ //lo mismo pero con la segunda torre
			if(registro_estado[2][1] == 0){
				registro_estado[2][1] = valor_disco;
				valor_disco--;
			}
			else if(registro_estado[1][1] == 0){
				registro_estado[1][1] = valor_disco;
				valor_disco--;
			}
			else{
				registro_estado[0][1] = valor_disco;
				valor_disco--;
			}
		}
		if(posiciones[i] == 3){ //y despues con la tercera
			if(registro_estado[2][2] == 0){
				registro_estado[2][2] = valor_disco;
				valor_disco--;
			}
			else if(registro_estado[1][2] == 0){
				registro_estado[1][2] = valor_disco;
				valor_disco--;
			}
			else{
				registro_estado[0][2] = valor_disco;
				valor_disco--;
			}
		}
	}
	//ahora que ya tengo los valores guardados, uso el mismo codigo que en mi ejercicio completo para mostrarlo en pantalla, en este caso voy mostrando las "filas" desde arriba y en funcion del valor registrado, imprimo un disco u otro
	for(int i=0; i < 3; i++){
		if(registro_estado[0][i] == 0){
			printf("  |  ");	
		}
		if(registro_estado[0][i] == 1){
			printf("  #  ");	
		}
		if(registro_estado[0][i] == 2){
			printf(" ### ");	
		}
		if(registro_estado[0][i] == 3){
			printf("#####");	
		}
		printf("    "); 
	}
	printf("\n");

	for(int i=0; i < 3; i++){
		if(registro_estado[1][i] == 0){
			printf("  |  ");	
		}
		if(registro_estado[1][i] == 1){
			printf("  #  ");	
		}
		if(registro_estado[1][i] == 2){
			printf(" ### ");	
		}
		if(registro_estado[1][i] == 3){
			printf("#####");	
		}
		printf("    ");
	}
	printf("\n");
	
	for(int i=0; i < 3; i++){
		if(registro_estado[2][i] == 0){
			printf("  |  ");	
		}
		if(registro_estado[2][i] == 1){
			printf("  #  ");	
		}
		if(registro_estado[2][i] == 2){
			printf(" ### ");	
		}
		if(registro_estado[2][i] == 3){
			printf("#####");	
		}
		printf("    ");
	}
	printf("\n");

			
}

/*

FUNCIÓN: hanoi_ui_ndiscos

PARÁMETROS: int * posicion_discos
			Este puntero al primer entero de un array de n discos y registra las posiciones de estos discos
			en cada eje.

			Por tanto sus valores válidos serán:
			-> 1 eje izquierdo
			-> 2 eje central
			-> 3 eje derecho

			Si num_discos es cuatro y los valores del array son 3, 2, 1, 1 
			el resultado esperado a visualizar por pantalla sería:

   |       |       |
 #####     |       |
#######   ###      #    


*/
//primero creo una funcion que reserva memoria y preparo codigo que imprima los discos en funcion de la cantidad de ellos
char* string_ndiscos(int num_discos, int tamanyo){
	
	//en funcion de la cantidad de discos, debo calcular el tamanyo maximo necesario de la subcadena
	int size_disco = num_discos * 2;
	
	//ahora reservo el espacio necesario en memoria pra poder imprimir los discos
	char* impresion_discos = (char*) malloc(sizeof(char)*size_disco);
	
	//debo buscar el punto medio de la subcadena donde empezar a poner los #
	int inicio_impresion = num_discos - tamanyo;
	
	//no considero necesario crear la variable eje_posicion para determinar el centro desde donde imprimira los caracteres a derecha e izq ya que con la variable num_discos que ya tengo creada tengo el mismo valor
	//int eje_posicion = num_discos;
	
	//genero un bucle que escriba por delante y detras del eje
	for (int i=0; i < num_discos; i++) {
		if (i < inicio_impresion) {
			impresion_discos[i] = ' ';
			impresion_discos[(size_disco - 2) - i] = ' ';
		} 
		else {
			impresion_discos[i] = '#';
			impresion_discos[(size_disco - 2) - i] = '#';
		}
	}
	
	//quito el valor final \0 de la string
	impresion_discos[size_disco - 1] = '\0';
	
	return impresion_discos;
}
//intentaba registrar directamente en los arrays las cadenas de caracteres devueltas por la funcion string_ndiscos, pero no funciona asi en C, y solo encontraba soluciones usando la libreria string.h, sin embargo, encontre una funcion que hace el trabajo de esa libreria y me permite usar la logica que estaba buscando
void copiar_cadena(char* destino, char* origen){
	int i = 0;
	while (origen[i] != '\0'){
		destino[i] = origen[i];
		i++;
	}
	destino[i] = '\0';
}

void hanoi_ui_ndiscos(int num_discos, int* n_posiciones) {
	//mi intencion inicial era la de hacer algo similar a la parte anterior, crear un array multidimensional de columnas fijas pero filas variables, la fila variable sera siempre el num_discos, almacenar en esta array directamente CON LA FUNCION ANTERIOR LOS # y printear el array, pero no he sido capaz de hacerlo de esta forma
	//al final en lugar de eso he creado 3 arrays simples de tipo char que me guardaran directamente los ### que devuelve la funcion anterior en funcion de los valores de los discos a guardar y de la cantidad de los mismos
	//el numero de estas 3 corresponde a la "torre" donde guardo estos ### ya definidos por la funcion anterior
	char registro_nestado1[num_discos][100];
	char registro_nestado2[num_discos][100];
	char registro_nestado3[num_discos][100];
	//para poder registrar mas tarde en el bucle en distintas posiciones del array y empezando por 0, necesito una variable por array que cambie cada vez que registre un numero, es importante que haga uno por array para que se rellenen los huecos de forma ordenada y correcta
	int registrador_nestado1 = 0;
	int registrador_nestado2 = 0;
	int registrador_nestado3 = 0;
	
	//para poder llamar a la funcion de los # y controlar el tamanyo de los discos que me imprime, necesito una variable que se vaya modificando conforme los guarde
	int tamanyo = num_discos; //esta siempre tiene el valor inicial de la cantidad de discos, es decir, el disco mas grande segun hemos definido en la otra funcion y bajara conforme se guarden estos discos y pasemos al siguiente directamente mas pequenyo
	//los guardo ya de mas grande a mas pequenro para tener el orden al imprimir ya hecho y no tener que darle la vuelta despues
	for(int j=(num_discos-1); j >= 0; j--){
		char* disco = string_ndiscos(num_discos, tamanyo); //esta variable me guarda los ## en cada vuelta 
		
		if(n_posiciones[j] == 1){
			//registro_nestado1[registrador_nestado1] = string_ndiscos(num_discos, tamanyo); entiendo que esto no funcionaba porque le intentaba dar a un hueco de un solo caracter el valor de una cadena de caracteres
			copiar_cadena(registro_nestado1[registrador_nestado1], disco);
			registrador_nestado1++;	
		}
		else if(n_posiciones[j] == 2){
			//registro_nestado2[registrador_nestado2] = string_ndiscos(num_discos, tamanyo);
			copiar_cadena(registro_nestado2[registrador_nestado2], disco);
			registrador_nestado2++;
		}
		else if(n_posiciones[j] == 3){
			//registro_nestado3[registrador_nestado3] = string_ndiscos(num_discos, tamanyo);
			copiar_cadena(registro_nestado3[registrador_nestado3], disco);
			registrador_nestado3++;		
		}
		tamanyo--; //cada vez que registra un valor, el siguiente disco a registrar es mas pequenyo
		free(disco); //debo liberar este espacio de memoria despues de usarlo
	}
	//creo un bucle for para que me muestre las torres tal y como me pide el ejercicio
	//para centrar el "palo" uso un bucle for, busco el punto medio y de forma manual cutrera le pongo espacios antes y despues de ese punto medio, poniendo un palo en el propio punto
	for(int i = num_discos - 1; i >= 0; i--){
        //torre 1
        if(i < registrador_nestado1){
            printf("%s", registro_nestado1[i]);
        } 
		else{
            for (int k = 0; k < num_discos -1; k++){
            	printf(" ");	
			}
			printf("|");
			for (int k = 0; k < num_discos -1; k++){
            	printf(" ");	
			}      
        }

		printf("     ");
		
        //torre 2
        if(i < registrador_nestado2){
            printf("%s", registro_nestado2[i]);
        } 
		else{
            for (int k = 0; k < num_discos -1; k++){
            	printf(" ");	
			}
			printf("|");
			for (int k = 0; k < num_discos -1; k++){
            	printf(" ");	
			}      
        }
		
		printf("     ");
        //torre 3
        if(i < registrador_nestado3){
            printf("%s", registro_nestado3[i]);
        } 
		else{
            for (int k = 0; k < num_discos -1; k++){
            	printf(" ");	
			}
			printf("|");
			for (int k = 0; k < num_discos -1; k++){
            	printf(" ");	
			}      
        }
        printf("\n");
    }
}


int main(int argc, char *argv[]) {

	// Durante la evaluación podré cambiar estos valores.

	printf("Ejemplo de hanoi_ui_3discos\n");
	int posiciones[] = {1,1,1}; 
				
	hanoi_ui_3discos(posiciones);


	printf("\nEjemplo de hanoi_ui_ndiscos\n");
	int n_posiciones[] = {3,2,3,3,3};
	hanoi_ui_ndiscos(5, n_posiciones);
	

	//compruebo que realmente funcione la funcion string_ndiscos:
	/*char *c1, *c2, *c3, *c4, *c5;
	
	c1 = string_ndiscos(5,1);
	c2 = string_ndiscos(5,2);
	c3 = string_ndiscos(5,3);
	c4 = string_ndiscos(5,4);
	c5 = string_ndiscos(5,5);
	
	printf("%s \n", c1);
	printf("%s \n", c2);
	printf("%s \n", c3);
	printf("%s \n", c4);
	printf("%s \n", c5);*/
	
	return 0;

}


/*primero_libre_eje_izquierdo = 2;
  primero_libre_eje_central = 2;
  primero_libre_eje_derecho = 2;
  
  array bidimensional [num_ejes][num_discos]
  array(3,2,1,1) empiezo a leer desde la derecha porque es el disco mas grande
  relleno matriz con los valores
  para printear: como en mi ejercicio*/
