╔═══════════════════════════════════════════════════════════════╗
║		TRABAJO FINAL PROGRAMACIÓN IMPERATIVA		║
║								║
║	Integrantes:						║
║		*Lucía Torrusio		Legajo: 59489		║
║		*Tamara Puig		Legajo: 59820		║
║		*Nicolás Comerci	Legajo: 59520		║
╚═══════════════════════════════════════════════════════════════╝

>> Generar ejecutable:

1- Una vez posicionado en el directorio en el que se encuentran los archivos fuente y de encabezado entregados utilizar el siguiente comando para generar el ejecutable "TPFinalGrupo4":

   $> make


>> Ejecutar el programa:

1- Ejecutar el siguiente comando en consola:

   $> ./TPFinalGrupo4 *file1* *file2*

Donde *file1* y *file2* representan el PATH de los archivos .csv de los cuales serán extraídos los datos.

Ejemplo de ejecución asumiendo que los archivos se llaman "aeropuertos.csv", "movimientos.csv" y ambos están ubicados en el home:
	
   $> ./TPFinalGrupo4 $HOME/aeropuertos.csv $HOME/movimientos.csv


>> Errores:

1- "ERROR: Two arguments expected.": la cantidad de argumentos al momento de ejecutar el programa es incorrecta.

2- "ERROR: No such file or directory.": algún PATH ingresado como argumento es incorrecto.

3- "ERROR: Wrong file.": alguno de los archivos ingresados como argumentos no cumple con el formato esperado.

4- "ERROR: Out of memory.": la memoria disponible para ejecutar el programa es insuficiente.


>> Modo de uso:

1- Una vez ejecutado correctamente el programa aparecerán 5 opciones en pantalla:

	1) Movimientos por aeropuerto: esta opción crea un archivo "movimientos_aeropuerto.csv" donde cada línea contiene separados por ";" el código OACI, la denominación y la cantidad de movimientos del aeropuerto.

	2) Movimientos por día de la semana: esta opción crea un archivo "dia_semana.csv" donde cada línea contiene separados por ";" el día de la semana, la cantidad de movimientos de cabotaje para ese día, la cantidad de movimientos internacionales para ese día y la suma de ambos movimientos.

	3) Composición de Movimientos: esta opción crea un archivo "composicion.csv" donde cada línea de la salida contiene separados por ";" el total de movimientos por Clasificación de Vuelo y por Clase de Vuelo.

	4) Realizar todo lo anterior: como lo indica el nombre, esta opción genera los tres archivos mencionados arriba y finaliza la ejecución del programa.

	5) Salir: finaliza la ejecución del programa.

Para seleccionarlas simplemente tiene que ingresar el número de la opción que quiera utilizar. 
Todos los archivos .csv creados estarán localizados en el mismo directorio del ejecutable.
    
