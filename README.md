# Laboratorio Estructura de Datos y Análisis de Algoritmos: "SpotMusic"
Este proyecto de laboratorio, corresponde a la realización de un programa en *lenguaje de programación C* denominado "Spotmusic", que consiste en organizar un archivo de música según la popularidad de la canción, luego por orden alfabético de los artistas y por último, la duración que tiene la canción, y además, crear una playlist con las canciones más populares según generos musicales de preferencia y una duración estimada.

## Funcionalidades del programa 📋

- ***Formato archivos entrada:***  
  Se tienen cuatro archivos de entrada, cuyos nombres son "artistas.in", "generos.in", "canciones.in" y "preferencias.in".
  - **artistas.in**:
  
    <img src="https://user-images.githubusercontent.com/66185308/142038222-67f1a808-5b84-408a-91e7-7326e2b0b857.png" width="300">


  - **generos.in**:
  
      <img src="https://user-images.githubusercontent.com/66185308/142038186-0d2085ce-5d94-4d39-af22-81a3b7aeb9f2.png" width="200">


  - **canciones.in**:

    <img src="https://user-images.githubusercontent.com/66185308/142037941-13fb8910-81b4-4e1d-beec-49b24013f665.png" width="400">
  
  - **preferencias.in**:
  
     <img src="https://user-images.githubusercontent.com/66185308/142038259-ca19ec0a-5f8e-4d69-b66a-bdcb5baf3613.png" width="50">



- ***Archivos de salida:*** 

  Se generan dos archivos de salida, cuyos nombres son "salida.out" y "playlist.out".
  
  - **salida.out**: lista todas las canciones sin repetir, indicando puntos de popularidad, nombre de la canción, duración, artista y género, separados por punto y coma (;). Si existen dos o más canciones con mismo valor de popularidad se ordenan alfabéticamente por nombre de artista. Si dos o más canciones tienen misma popularidad y pertenecen al mismo artista, se ordenan según duración de manera ascendente.

    
      <img src="https://user-images.githubusercontent.com/66185308/142036559-ceb19573-b4b4-4694-b8ff-582f7d63fa31.png" width="500">

  
  - **playlist.out**: consiste en la creación de una playlist tomando en cuenta las preferencias (preferencias.in). 
 
      
      <img src="https://user-images.githubusercontent.com/66185308/142036733-c3970452-953f-4f50-8bad-756e4089a40d.png" width="500">

 

> Considera las siguientes restricciones:
>  
>  1. La playlist solamente debe contener canciones cuyo código del género esté especificado en el archivo de preferencias. Por ejemplo, si el archivo “preferencias.in” contiene en la segunda línea los géneros con identificador 3 y 2, la playlist solamente podrá incorporar una combinación entre las canciones “safaera”, “dakiti” y “dynamite”.
> 
> 2. Las canciones de preferencia deben ser agregadas a la playlist de forma alternada de acuerdo a su género, siguiendo el orden designado en el archivo de entrada “preferencias.in”. Considerando el ejemplo anterior, la primera canción debe ser trap, la segunda k-pop, luego trap, y así. Además, para canciones de un mismo género, estas deben ingresar en orden descendente según su popularidad. Por ejemplo, para el género trap, primero debe ingresar “safaera” antes que “dakiti”.
> 3. En primera instancia, se debe tratar de agregar todas las canciones que cumplan con el o los géneros, siempre y cuando no superen el tiempo deseado. De acuerdo a esto se consideran los siguientes casos:
>     1. Si existe un solo género de preferencia, en ese caso lo que se alterna son las canciones considerando su nombre. Por ejemplo, si el archivo “preferencias.in” solo indica preferencias al género trap, la playlist debe alternar las canciones “safaera” y “dakiti”.
>     2. Para los archivos de entrada siempre se considerarán dos o más canciones que cumplan las preferencias solicitadas.
>     3. En caso de que no se puedan incluir todas las canciones del género solicitado debido a que superan el tiempo deseado, se debe cortar la playlist justo en la canción que provoca que exceda este tiempo (la debe incluir). La duración de la última canción será cortada lo justo y necesario para cumplir con el tiempo solicitado. Finalmente, se debe indicar en la última línea del archivo de salida “playlist.out” el tiempo sobrante de la última canción con el formato ​MINUTOS:SEGUNDOS​. Cabe mencionar que la duración original de la canción es la misma y esa es la que se debe mostrar en la duración de la canción en la línea que le corresponde.
>     4. En caso de que se agreguen todas las canciones y sobra tiempo para agregar alguna más, se debe repetir las canciones en el mismo orden que fueron agregadas anteriormente, siguiendo el mismo criterio del punto anterior (iii.) para lograr completar el tiempo solicitado.
>     5. Para las canciones repetidas no hay restricción de género ni de nombre, solo se considera el orden anterior.

  
  

  


## Compilación y ejecución ⚙️
### En linux/macOS:
- Requisito: tener instalado GCC
- Escribir en terminal: 
`gcc main.c -o main -lm` , y luego
`./main`

### En windows:
- Requisito: tener instalado MinGW
- Escribir en terminal: 
`gcc main.c -o main` , y luego
`main`


## Autor ✒️
- Victoria Bórquez
