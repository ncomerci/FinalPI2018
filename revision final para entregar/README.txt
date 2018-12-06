	TRABAJO FINAL PROGRAMACI�N IMPERATIVA

Integrantes:
		Luc�a Torrusio	Legajo: 59489
		Tamara Puig	Legajo: 59820
		Nicol�s Comerci	Legajo: 59520

Generar ejecutable:

1- Una vez posicionado en el directorio en el que se encuentran los archivos  fuente y de encabezado entregados utilizar el siguiente comando para generar el ejecutable "censo":

   $> gcc main.c getnum.c TAD.c -o censo -pedantic -std=c99 -Wall -fsanitize=address

Modo de uso:

1- Para invocar el programa:
	$> censo (path del archivo de aeropuertos) (path del archivo de movimientos)
 donde los dos �ltimos archivos son los utilizados por el progrma para hacer el censo.


2-Aparecer�n 5 opciones en pantalla:

	1) Movimientos por aeropuerto: esta opci�n crea un archivo "movimientos_aeropuerto.csv" donde cada l�nea contiene separados por ; el c�digo OACI, la denominaci�n y la cantidad de movimientos del aeropuerto.

	2) Movimientos por d�a de la semana: esta opci�n crea un archivo "dia_semana.csv" donde cada l�nea contiene separados por ";" el d�a de la semana, la cantidad de movimientos de cabotaje para ese d�a, la cantidad de movimientos internacionales para ese d�a y la suma de ambos movimientos.

	3) Composici�n de Movimientos: esta opci�n crea un archivo "composicion.csv" donde cada l�nea de la salida contenga separados por ";" el total de movimientos por Clasificaci�n de Vuelo y por Clase de Vuelo.

	4) Realizar todo lo anterior: como lo indica el nombre, esta opci�n genera tres archivos "movimientos_aeropuerto.csv", "dia_semana.csv" y "composicion.csv" con lo anterior dicho.

	5) Salir: Una vez terminado el uso del programa esta opci�n termina la ejecuci�n del mismo.

    Para seleccionarlas simplemente tiene que ingresar el n�mero de la opci�n que quiera utilizar. Todos los archivos .csv creados estar�n localizados en el mmismo directorio que el del ejecutable. 
    
