#include<stdio.h>  //es una libreria que sirve para imprimir cosas por pantalla y para que el usuario pueda cargar datos.
#include<stdlib.h> //es una libreria que sirve para que pueda manipular archivos.
//#include<conio.h> //cuando ponia la opcion getchar() no me funcionaba el codigo asi que agregue esta libreria para que a ustedes les funcione el getch()
int main(){
	
	// Empiezo cargando el primer archivo (subtes) //
	
	FILE*arch1;
	arch1=fopen("subte_ene-jun.dat","rb");
	if(arch1==NULL){
		perror("Error al abrir el archivo arch1");
		return(-1);
	}
	
	int i,c,c1;    					//declaro un contador y variables para usar en los archivos
	long numero1;					//declaro una variable donde se van a cargar los datos leidos del archivo
	long subte[182];				//declaro el vector donde se van a guardar los datos
	
//	printf("Los datos leidos del archivo subte_ene-jun son: \n\n");
	
	for (i=0;i<182;i++){ 			//utilizo un ciclo for para leer uno a uno los datos del archivo y cargarlos en el vector
		subte[i]=numero1;
		c=fread(&numero1,sizeof(long),1,arch1);
		if(c!=1){
			perror("Error al leer el archivo arch1");
			return(-2);
		}
//		printf(" %li ",numero1);	//lo utilizo para ver en pantalla los datos del archivo
	}
	
	c1=fclose(arch1);
	if(c1!=0){
		perror("Error al cerrar el archivo arch1");
		return (-3);
	}
	
	//Cargo el segundo archivo (trenes) //
	
	FILE*arch2;
	arch2=fopen("tren_ene-jun.dat","rb");
	if(arch2==NULL){
		perror("Error al abrir el archivo arch2");
		return(-4);
	}
	
	int	j,c2,c3; 					//declaro un contador y variables para usar en los archivos
	long numero2;					//declaro una variable donde se van a cargar los datos leidos del archivo
	long tren[182]; 				//declaro el vector donde se van a guardar los datos
	
//	printf("\n\nLos datos leidos del archivo tren_ene-jun son: \n\n");
	
	for(j=0;j<182;j++){				//utilizo un ciclo for para leer uno a uno los datos del archivo y cargarlos en el vector
		tren[j]=numero2;
		c2=fread(&numero2,sizeof(long),1,arch2);
		if(c2!=1){
			perror("Error al leer el archivo arch2");
			return (-5);
		}
//		printf(" %li ",numero2);
	}
	
	c3=fclose(arch2);
	if(c3!=0){
		perror("Error al cerrar el archivo arch2");
		return (-6);
	}
	
//	printf("\n\nLos archivos se leyeron correctamente\n\n");

	/* CALCULO Y GUARDO LOS PROMEDIOS EN UN NUEVO ARCHIVO */
	
	/* PROMEDIO DE VIAJES EN SUBTE */
	
	FILE*arch3;
	arch3=fopen("cambioscovidsubte.dat","wb");
	if(arch3==NULL){
		perror("Error al abrir el archivo arch3");
		return (-7);
	}
	
	int n=2;		//Declaro una valiable que va a indicar la cantidad de datos que va a contener mi vector donde voy a guardar ambos promedios
	
	/* PROMEDIO DE VIAJES EN SUBTE PRE PANDEMIA */
	
	long suma1_pre=0, cant1_pre=0;  //defino dos contadores, uno donde se va a guardar la suma de los numeros leidos y otro donde se va a guardar la cantidad de nros leidos
	long promedio1_pre;
	long datos[n];
		
	for(i=69;i<79;i++){				//Utilizo un ciclo for para sumar los valores leidos y la cantidad de datos leidos
		suma1_pre+=subte[i];
		cant1_pre++;
//		printf(" %li ",subte[i]);
	}
	
	promedio1_pre= (suma1_pre/cant1_pre);
	datos[1]=promedio1_pre;
	
//	printf ("\n\nLa suma de los numeros es: %li ",suma1_pre);
//	printf("\n\nLa cantidad de numeros leidos es: %li ",cant1_pre);
//	printf("\n\nEl promedio de viajes en pre pandemia es de %li \n\n",datos[1]);	
	
	/* PROMEDIO DE VIAJES EN SUBTE POST PANDEMIA */
	
	long suma1_post=0, cant1_post=0;
	long promedio1_post;
	
	for(i=79;i<89;i++){				//Utilizo un ciclo for para sumar los valores leidos y la cantidad de datos leidos
		
		suma1_post+=subte[i];
		cant1_post++;
//		printf (" %li ",subte[i]);
	}
	
	promedio1_post=(suma1_post/cant1_post);
	datos[2]=promedio1_post;
	
//	printf ("\n\nLa suma de los numeros es: %li ",suma1_post);
//	printf("\n\nLa cantidad de numeros leidos es: %li ",cant1_post);
//	printf("\n\nEl promedio de viajes en post pandemia es de %li \n\n",datos[2]);
	
	int c4,c5,c6;
	long valor[n];				//Cree un nuevo vector para guardar los datos de los promedios
		
	valor[1]=datos[1];
	c4=fwrite(&datos[1],sizeof(long),1,arch3);				//Escribi el dato del promedio pre pandemia
		if(c4!=1){
		perror("Error al escribir el archivo arch3");
		return (-8);
	}	
	
	valor[2]=datos[2];
	c5=fwrite(&datos[2],sizeof(long),1,arch3);				//Escribi el dato del promedio pos pandemia
		if(c5!=1){
			perror("Error al escribir el archivo arch3");
			return(-9);
		}
	
	c6=fclose(arch3);
	if(c6!=0){
		perror("Error al cerrar el archivo arch3");
		return (-10);
	}
	
	/* PROMEDIO DE VIAJES EN TREN */
	
	FILE*arch4;
	arch4=fopen("cambioscovidtren.dat","wb");
	if(arch4==NULL){
		perror("Error al abrir el archivo arch4");
		return(-11);
	}	

	/* PROMEDIO DE VIAJES EN TREN PRE PANDEMIA */
	
	long suma2_pre=0, cant2_pre=0;
	long promedio2_pre;
	long datos2[n];
	
	for(j=69;j<79;j++){
		suma2_pre+=tren[j];
		cant2_pre++;
//		printf(" %li ",tren[j]);
	}
	
	promedio2_pre= (suma2_pre/cant2_pre);
	datos2[1]=promedio2_pre;
	
//	printf ("\n\nLa suma de los numeros es: %li ",suma2_pre);
//	printf("\n\nLa cantidad de numeros leidos es: %li ",cant2_pre);
//	printf("\n\nEl promedio de viajes en pre pandemia es de %li \n\n",datos2[1]);	
	
	/* PROMEDIO DE VIAJES EN TREN POST PANDEMIA */
	
	long suma2_post=0, cant2_post=0;
	long promedio2_post;
	
	for(j=79;j<89;j++){
		suma2_post+=tren[j];
		cant2_post++;
//		printf(" %li ",tren[j]);
	}
	
	promedio2_post=(suma2_post/cant2_post);
	datos2[2]=promedio2_post;
	
//	printf ("\n\nLa suma de los numeros es: %li ",suma2_post);
//	printf("\n\nLa cantidad de numeros leidos es: %li ",cant2_post);
//	printf("\n\nEl promedio de viajes en post pandemia es de %li \n\n",datos2[2]);
	
	int c7,c8,c9;
	long valor2[n];
	
	valor2[1]=datos2[1];
	c7=fwrite(&datos2[1],sizeof(long),1,arch3);				//Escribi el dato del promedio pre pandemia
		if(c7!=1){
		perror("Error al escribir el archivo arch4");
		return (-12);
	}	
	
	valor2[2]=datos2[2];
	c8=fwrite(&datos2[2],sizeof(long),1,arch3);				//Escribi el dato del promedio pos pandemia
		if(c8!=1){
			perror("Error al escribir el archivo arch4");
			return(-13);
		}
	
	c9=fclose(arch4);
	if(c9!=0){
		perror("Error al cerrar el archivo arch3");
		return (-14);
	}
	
	
	/*CALCULO EL PORCENTAJE DIARIO SUBTE-TREN */
	
	/* Porcentaje diario de SUBTE*/
	
	long suma_total_s;
	
	for(i=0;i<182;i++){
		suma_total_s+=subte[i];
	}
	
	long mes1_s[29], mes2_s[29], mes3_s[29], mes4_s[29], mes5_s[29],mes6_s[29];
	
	for(i=0;i<30;i++){
		mes1_s[i]=subte[i];
	}
	
	for(i=31;i<60;i++){
		mes2_s[i-30]=subte[i];
	}
	
	for(i=60;i<89;i++){
		mes3_s[i-59]=subte[i];
	}
	
	for(i=91;i<120;i++){
		mes4_s[i-90]=subte[i];
	}
	
	for(i=121;i<150;i++){
		mes5_s[i-120]=subte[i];
	}

	for(i=152;i<181;i++){
		mes6_s[i-151]=subte[i];
	}
	
	/* Porcentaje diario de TRENES */
	
	long suma_total_t;
	
	for(j=0;j<182;j++){
		suma_total_s+=tren[j];
	}
	
	long mes1_t[29], mes2_t[29], mes3_t[29], mes4_t[29], mes5_t[29],mes6_t[29];
	
	for(j=0;j<30;j++){
		mes1_t[j]=tren[j];
	}
	
	for(j=31;j<60;j++){
		mes2_t[j-30]=tren[j];
	}
	
	for(j=60;j<89;j++){
		mes3_t[j-59]=tren[j];
	}
	
	for(j=91;j<120;j++){
		mes4_t[j-90]=tren[j];
	}
	
	for(j=121;j<150;j++){
		mes5_t[j-120]=tren[j];
	}

	for(j=152;j<181;j++){
		mes6_t[j-151]=tren[j];
	}
	
	/* DIAS DE ALTA OCUPACION DE TREN*/
	
	int cant_dias_t=0, cant_prepand_t=0, cant_postpand_t=0;		//declaro los contadores que voy a utilizar para guardar la cantidad de dias
	int porcentaje_cantpre, porcentaje_cantpost;

	for(j=0;j<182;j++){							//Arme un ciclo for para que recorra uno a uno los datos
		
		if(tren[j]>promedio2_pre){				//dentro del ciclo for arme un condicional if para comparar los datos almacenados en el vector
			cant_dias_t++;						//con el valor del promedio calculado mas arriba
			if(j<80){
				cant_prepand_t++;				//si el valor se encuentra entre los dias anteriores al dia 80 se suma un dia
			}									//en la cantidad de dias pre pandemia lo que aumenta el contador
			else{								//caso contrario si el valor se encuentra entre los dias posteriores al dia 80
				cant_postpand_t++;				//se suma en la cantidad de dias y aumenta el contador
			}
		}
		else{
			cant_dias_t=cant_dias_t;			//caso contrario, donde el numero comparado sea menor al promedio el contador permanecera 
		}										//con la misma cantidad de datos cargados que tenia hasta el ultimo valor mayor al promedio leido
	}
	
//	printf("\n\ncantidad de dias con mas viajes en prepandemia: %i ",cant_prepand_t);   //Los use para ver si funcionaba.
//	printf("\ncantidad de dias con mas viajes en pandemia: %i ",cant_postpand_t);
	
	porcentaje_cantpre=((cant_prepand_t*100)/cant_dias_t);
	porcentaje_cantpost=((cant_postpand_t*100)/cant_dias_t);
	
//	printf("\n porcentaje pre pandemia: %i %% ",porcentaje_cantpre);					//Los use para ver si funcionaban
//	printf("\n porcentaje post pandemia: %i %% ",porcentaje_cantpost);


 	/* MINIMA CANTIDAD DE PASAJEROS */  
	 
	/* Cantidad minima en Subte */ 
	
	int dia_minimo_s; 
	long cant_minima_s;
	
	cant_minima_s=subte[0];
	
	for(i=0;i<182;i++){						//armo un ciclo for para que compare uno a uno los numeros
		
		if(subte[i]<cant_minima_s){			//si el numero que lee es menor al numero guardado anteriormente 
			cant_minima_s=subte[i];
			dia_minimo_s=i;	
		}
		else{
			cant_minima_s=cant_minima_s;
		}
	} 
	
//	printf(" %li ",cant_minima_s);
//	printf(" %i ",dia_minimo_s);			//Lo use para ver si funcionaba el ciclo for
 
	/* Cantidad minima en Tren */

	int dia_minimo_t;
	long cant_minima_t;
	
	cant_minima_t=tren[1];
	
	for(j=1;j<=182;j++){
		
		if(tren[j]<cant_minima_t){
			cant_minima_t=tren[j];
			dia_minimo_t=j;
		}
		else{
			cant_minima_t=cant_minima_t;
		}
	}
	
//	printf(" %li ",cant_minima_t); 			//Lo use para ver si funcionaba el ciclo for
//	printf(" %i ",dia_minimo_t);	
	
	/*-------------------------------------------------------------------------*/


	/* Para armar el menu */	
	
	int opc,opc_case1,opc_case2,meses,opc_case4; 		//declaro la variables donde se va a guardar la opcion que el usuario decida ver en pantalla
	do{
		
		system("cls");										// para limpiar la pantalla antes de entrar al menu por si quedan cosas impresas
		printf("\n\n MENU DE OPCIONES\n\n");
		printf("1. Promedio de viajes en subte o tren\n");
		printf("2. Porcentaje diario subte-tren\n");
		printf("3. Dias de alta ocupacion en trenes\n");
		printf("4. Minima cantidad de pasajeros en tren o subte\n");
		printf("5. Salir\n\n");
		
		printf("Opcion a escoger:  ");
		scanf("%i",&opc);					// guardo la opcion dentro de la variable
		
		switch(opc){						// utilizo un switch para armar el menu 
			case 1:							// ya que me va a dar la posibilidad de volver al menu una vez ingresada e impresa una opcion hasta que ingrese 
				system("cls");				// la opcion que me permita salir del bucle (menu)
				do{
					system("cls");
					printf("\n\n MENU DE OPCIONES\n\n");
					printf("1. Promedio de viajes en subtes\n");
					printf("2. Promedio de viajes en trenes\n");
					printf("3. Salir\n");
					printf("Opcion a escoger:  ");
					scanf("%i",&opc_case1);
					
					switch(opc_case1){
						
						case 1: 
							system("cls");
							printf("El promedio de viajes prepandemia fue: %li \n",promedio1_pre); 
							printf("El promedio de viajes pospandemia fue: %li \n",promedio1_post);
							getch();
							break;
						
						case 2: 
							system("cls");
							printf("El promedio de viajes prepandemia fue: %li \n",promedio2_pre);
							printf("El promedio de viajes pospandemia fue: %li \n",promedio2_post);
							getch();
							break;
	
						case 3:
							break;
						
						default:
						printf("La opcion ingresada es incorrecta");
					}
				}while(opc_case1!=3);
				getch();
				break;
			// terminado
			case 2:
				system("cls");
				do{
					system("cls");
					printf("\n\n MENU DE OPCIONES\n\n");
					printf("1. Ingresar el dia y seleccionar el mes\n");
					printf("2. Salir\n");
					printf("Opcion a escoger:  ");
					scanf("%i",&opc_case2);
					
					switch (opc_case2){
						
						case 1:
							system("cls");
							int dia;
							printf("Ingrese el dia del que quiere saber el porcentaje de viajes:  ");
							scanf("%i", &dia);
	
							do{
								system("cls");
								printf("\n\n MENU DE OPCIONES\n\n");
								printf("\n\nElija el mes:  ");
								printf("\n1. Enero");
								printf("\n2. Febrero");
								printf("\n3. Marzo");
								printf("\n4. Abril");
								printf("\n5. Mayo");
								printf("\n6. Junio");
								printf("\n7. Salir");
								
								printf("\n\nOpcion a elegir:  ");
								scanf("%i",&meses);
								
								switch(meses){
									
									case 1: 
										printf("\nEl porcentaje de viajes del dia %i de ENERO fue:  ",dia);
										printf("\n %li %% en Subte",((mes1_s[dia]*100)/(mes1_s[dia]+mes1_t[dia])));
										printf("\n %li %% en Tren",((mes1_t[dia]*100)/(mes1_s[dia]+mes1_t[dia])));
										getch();
										break;
										
									case 2:
										
										printf("\nEl porcentaje de viajes del dia %i de FEBRERO fue:  ",dia);
										printf("\n %li %% en Subte",((mes2_s[dia]*100)/(mes2_s[dia]+mes2_t[dia])));
										printf("\n %li %% en Tren",((mes2_t[dia]*100)/(mes2_s[dia]+mes2_t[dia])));
										getch();
										break;
										
									case 3:
										
										printf("\nEl porcentaje de viajes del dia %i de MARZO fue:  ",dia);
										printf("\n %li %% en Subte",((mes3_s[dia]*100)/(mes3_s[dia]+mes3_t[dia])));
										printf("\n %li %% en Tren",((mes3_t[dia]*100)/(mes3_s[dia]+mes3_t[dia])));
										getch();
										break;
									
									case 4:
										
										printf("\nEl porcentaje de viajes del dia %i de ABRIL fue:  ",dia);
										printf("\n %li %% en Subte",((mes4_s[dia]*100)/(mes4_s[dia]+mes4_t[dia])));
										printf("\n %li %% en Tren",((mes4_t[dia]*100)/(mes4_s[dia]+mes4_t[dia])));
										getch();
										break;
									
									case 5:
										
										printf("\nEl porcentaje de viajes del dia %i de MAYO fue:  ",dia);
										printf("\n %li %% en Subte",((mes5_s[dia]*100)/(mes5_s[dia]+mes5_t[dia])));
										printf("\n %li %% en Tren",((mes5_t[dia]*100)/(mes5_s[dia]+mes5_t[dia])));
										getch();
										break;
										
									case 6:
										
										printf("\nEl porcentaje de viajes del dia %i de JUNIO fue:  ",dia);
										printf("\n %li %% en Subte",((mes6_s[dia]*100)/(mes6_s[dia]+mes6_t[dia])));
										printf("\n %li %% en Tren",((mes6_t[dia]*100)/(mes6_s[dia]+mes6_t[dia])));
										getch();
										break;
										
									case 7:
										break;
										
									default:
										printf("No ingreso una opcion valida");
								}
							}while(meses!=7);
							getch();
							break;
							
						case 2:
							break;	
					}
		
				}while(opc_case2!=2);
				getch();
				break;
			//terminado	
			case 3:
				system("cls");
				
				printf("La cantidad de dias donde el numero de pasajeros supera el promedio en pre-pandemia es:  %i ",cant_dias_t);
				printf("\n\nEl porcentaje de dias que son de pre-pandemia es: %i %%",porcentaje_cantpre);
				printf("\n\nEl porcentaje de dias que son de post-pandemia es: %i %%",porcentaje_cantpost);	
				
				getch();
				break;
			//terminado
			case 4:
				system("cls");
				
				do{
					system("cls");										// para limpiar la pantalla antes de entrar al menu por si quedan cosas impresas
					printf("\n\n MENU DE OPCIONES\n\n");
					printf("1. Minima cantidad de pasajeros en Subte\n");
					printf("2. Minima cantidad de pasajeros en Tren\n");
					printf("3. Salir\n\n");
		
					printf("Opcion a escoger:  ");
					scanf("%i",&opc_case4);				
					
					switch(opc_case4){
						
						case 1:
							system("cls");
							printf("La cantidad minima de pasajeros en Subte fue: %li \n\n",cant_minima_s);
							printf("El dia con la cantidad minima de pasajeros fue el dia %i ",dia_minimo_s-60);
							
							if(dia_minimo_s>0 && dia_minimo_s<30){
								printf("del mes de Enero");
							}
							if(dia_minimo_s>31 && dia_minimo_s<60){
								printf("del mes de Febrero");
							}
							if(dia_minimo_s>60 && dia_minimo_s<90){
								printf("del mes de Marzo");
							}
							if(dia_minimo_s>91 && dia_minimo_s<120){
								printf("del mes de Abril");
							}
							if(dia_minimo_s>121 && dia_minimo_s<150){
								printf("del mes de Mayo");
							}
							if(dia_minimo_s>152 && dia_minimo_s<180){
								printf("del mes de Enero");
							}
							getch();
							break;
							
						case 2:
							system("cls");
							printf("La cantidad minima de pasajeros en Tren fue: %li \n\n",cant_minima_t);
							printf("El dia con la cantidad minima de pasajeros fue el dia %i ",dia_minimo_t-60);
							
							if(dia_minimo_t>0 && dia_minimo_t<30){
								printf("del mes de Enero");
							}
							if(dia_minimo_t>31 && dia_minimo_t<60){
								printf("del mes de Febrero");
							}
							if(dia_minimo_t>60 && dia_minimo_t<90){
								printf("del mes de Marzo");
							}
							if(dia_minimo_t>91 && dia_minimo_t<120){
								printf("del mes de Abril");
							}
							if(dia_minimo_t>121 && dia_minimo_t<150){
								printf("del mes de Mayo");
							}
							if(dia_minimo_t>152 && dia_minimo_t<180){
								printf("del mes de Enero");
							}
							getch();
							break;					
					}
				}while(opc_case4!=3);
				getch();
				break;
			case 5:
				break;
			
			default:
				printf("La opcion ingresada es incorrecta");
				
		}
	}while(opc!=5);

	return 0;
}
