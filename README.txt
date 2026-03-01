Hemos creado un archivo de configuración externa que se llama "Conexion_externa.txt" donde dentro sse encuentra la siguiente linea:
dbname=helloINEP user=postgres password=21Espanyol hostaddr=127.0.0.1 port=5432



Para poder hacer la conexion  es necesario cambiar el valor de las variables dependiendo de la configuración de tu base de datos. El fichero de conexión "Conexion_externa.txt" ha de estar en el mismo directorio que el código de la aplicación.

En la variable nombre_del_archivo que se encuentra al principio del main, se tendrá que igualar al directorio donde se encuentra el archivo Conexion_externa.txt.

Por ejemplo_: 


"C:/Users/Gerard/Desktop/Proyecto INEP/Conexion_externa.txt";


***IMPORTANTE*** -> Es necesario compilar el programa des de el .sln ya que no nos deja crear el .exe