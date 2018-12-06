	TRABAJO FINAL PROGRAMACIÓN IMPERATIVA

Integrantes:
		Lucía Torrusio	Legajo: 59489
		Tamara Puig	Legajo: 59820
		Nicolás Comerci	Legajo: 59520

Generar ejecutable:

1- Una vez posicionado en el directorio en el que se encuentran los archivos  fuente y de encabezado entregados utilizar el siguiente comando para generar el ejecutable "censo":

   $> gcc main.c getnum.c TAD.c -o censo -pedantic -std=c99 -Wall -fsanitize=address

Modo de uso:

1- Para invocar el programa:
	$> censo (path del archivo de aeropuertos) (path del archivo de movimientos)
 donde los dos últimos archivos son los utilizados por el progrma para hacer el censo.


2-Aparecerán 5 opciones en pantalla:

	1) Movimientos por aeropuerto: esta opción crea un archivo "movimientos_aeropuerto.csv" donde cada línea contiene separados por ; el código OACI, la denominación y la cantidad de movimientos del aeropuerto.

	2) Movimientos por día de la semana: esta opción crea un archivo "dia_semana.csv" donde cada línea contiene separados por ";" el día de la semana, la cantidad de movimientos de cabotaje para ese día, la cantidad de movimientos internacionales para ese día y la suma de ambos movimientos.

	3) Composición de Movimientos: esta opción crea un archivo "composicion.csv" donde cada línea de la salida contenga separados por ";" el total de movimientos por Clasificación de Vuelo y por Clase de Vuelo.

	4) Realizar todo lo anterior: como lo indica el nombre, esta opción genera tres archivos "movimientos_aeropuerto.csv", "dia_semana.csv" y "composicion.csv" con lo anterior dicho.

	5) Salir: Una vez terminado el uso del programa esta opción termina la ejecución del mismo.

    Para seleccionarlas simplemente tiene que ingresar el número de la opción que quiera utilizar. Todos los archivos .csv creados estarán localizados en el mmismo directorio que el del ejecutable. 
    
