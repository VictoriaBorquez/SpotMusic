/*Victoria Bórquez */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*Lista Enlazada simple Artistas
Contiene:
- IDArtista (tipo int)
- nombreArtista (tipo char*)
- puntero a otra estructura*/
typedef struct Artistas{
  int IDArtista;
  char * nombreArtista;
  struct Artistas *sig;
} artistas;

/*Lista Enlazada simple Generos
Contiene:
- IDGenero (tipo int)
- genero (tipo char*)
- puntero a otra estructura*/
typedef struct Generos{
  int IDGenero;
  char * genero;
  struct Generos *sig;
} generos;

/*Lista Enlazada simple Canciones
Contiene:
- nombreCancion (tipo char*)
- duracionMM (tipo int)
- duracionSS (tipo int)
- IDArtista (tipo int)
- IDGenero (tipo int)
- popularidad (tipo int)
- nombreArtista (tipo char*)
- nombreGenero (tipo char*)
- puntero a otra estructura*/
typedef struct Canciones{
  char * nombreCancion;
  int duracionMM;
  int duracionSS;
  int IDArtista;
  int IDGenero;
  int popularidad;
  char * nombreArtista;
  char * nombreGenero;
  struct Canciones *sig;
} canciones;

/*Función crearNodoArtista
Crea un nodo con informacion de los artistas (ID y nombre)
Entrada: -
Salida: nodo */
artistas *crearNodoArtista(){
  artistas *aux;
  aux = (artistas *)malloc(sizeof(artistas)); //asigna memoria al nodo
  aux -> sig = NULL; //apunta el siguiente a nulo
  return aux;
}

/*Función crearNodoGeneros
Crea un nodo con informacion de los generos (ID y nombre)
Entrada: -
Salida: nodo */
generos *crearNodoGeneros(){
  generos *aux;
  aux = (generos *)malloc(sizeof(generos)); //asigna memoria al nodo
  aux -> sig = NULL; //apunta el siguiente a nulo
  return aux;
}

/*Función crearNodoCanciones
Crea un nodo con informacion de las canciones (nombre, duracion, IDArtista,
IDGenero, popularidad, nombreArtista y nombreGenero)
Entrada: -
Salida: nodo */
canciones *crearNodoCanciones(){
  canciones *aux;
  aux = (canciones *)malloc(sizeof(canciones)); //asigna memoria al nodo
  aux -> sig = NULL; //apunta el siguiente a nulo
  return aux;
}

/*Función agregarInicioArtista
agrega un nodo al inicio de la lista enlazada simple
Entrada: lista de artistas, ID artista y nombre del artista
Salida: nueva lista */
artistas *agregarInicioArtista(artistas *L,  int IDArtista,char * nombreArtista){
  artistas *nuevo;
  nuevo = crearNodoArtista();
  nuevo->IDArtista = IDArtista;
  nuevo->nombreArtista = nombreArtista;
  nuevo->sig = L;
  return nuevo;
}

/*Función agregarInicioGenero
agrega un nodo al inicio de la lista enlazada simple
Entrada: lista de genero, ID genero y nombre del genero
Salida: nueva lista */
generos *agregarInicioGenero(generos *L,  int IDGenero,char * genero){
  generos *nuevo;
  nuevo = crearNodoGeneros();
  nuevo->IDGenero = IDGenero;
  nuevo->genero = genero;
  nuevo->sig = L;
  return nuevo;
}

/*Función agregarInicioCanciones
agrega un nodo al inicio de la lista enlazada simple
Entrada: lista de canciones, nombre de Cancion, duracion en minutos y en segundos,
Id artista, Id genero, popularidad, nombre artista y nombre genero
Salida: nueva lista */
canciones *agregarInicioCanciones(canciones *L,  char * nombreCancion, int duracionMM,int duracionSS,int IDArtista,int IDGenero,int popularidad, char * nombreArtista,char * nombreGenero){
  canciones *nuevo;
  nuevo = crearNodoCanciones();
  nuevo->nombreCancion = nombreCancion;
  nuevo->duracionMM = duracionMM;
  nuevo->duracionSS = duracionSS;
  nuevo->IDArtista = IDArtista;
  nuevo->IDGenero = IDGenero;
  nuevo->popularidad = popularidad;
  nuevo->nombreArtista = nombreArtista;
  nuevo->nombreGenero = nombreGenero;
  nuevo->sig = L;
  return nuevo;
}

/*Función agregarFinal
agrega un nodo al final de la lista enlazada simple
Entrada: lista de canciones, nombre de Cancion, duracion en minutos y en segundos,
Id artista, Id genero, popularidad, nombre artista y nombre genero
Salida: nueva lista */
canciones *agregarFinal(canciones *L, char * nombreCancion, int duracionMM, int duracionSS, int IDArtista, int IDGenero, int popularidad, char * nombreArtista, char * nombreGenero){
  canciones *aux;
  aux = L;
  canciones *nuevo;
  nuevo = crearNodoCanciones();
  nuevo->nombreCancion = nombreCancion;
  nuevo->duracionMM = duracionMM;
  nuevo->duracionSS = duracionSS;
  nuevo->IDArtista = IDArtista;
  nuevo->IDGenero = IDGenero;
  nuevo->popularidad = popularidad;
  nuevo->nombreArtista = nombreArtista;
  nuevo->nombreGenero = nombreGenero;
  if(L==NULL){
    L = nuevo;
  }
  else{
    while(aux->sig != NULL){
      aux = aux->sig;
    }
    aux->sig = nuevo;
  }
  return L;
}

/*Función escribirListaCanciones
escribe la solución en el archivo de salida
Entrada: lista de canciones, archivo de salida
Salida: no aplica (void)*/
void escribirListaCanciones(canciones *L, FILE * f){
  canciones *aux;
  aux = L; //variable auxiliar para recorrer la list
  while(aux != NULL){ //hasta el final de la lista
    fprintf(f, "%d;%s;%d:%02d;%s;%s\n",aux->popularidad,aux->nombreCancion, aux->duracionMM,aux->duracionSS,aux->nombreArtista,aux->nombreGenero);
    aux = aux->sig; //avanza al siguiente elemento
  }
}

/*Función agregarDatosGeneros
agrega datos del genero, especificamente el nombre de genero, de acuerdo a su id
Entrada: lista de canciones, lista de generos, cantidad de canciones y cantidad
de generos
Salida: lista*/
canciones *agregarDatosGeneros(canciones *L1,generos *L2,int cantidadCanciones, int cantidadGeneros){
  canciones *aux1 = L1;
  int i,j;
  for(i=0;i<cantidadCanciones;i++){
    generos *aux2 = L2;
    for(j=0;j<cantidadGeneros;j++){
      if(aux1->IDGenero == aux2->IDGenero){
        aux1->nombreGenero = aux2->genero;
      }
      aux2 = aux2->sig;
    }
    aux1 = aux1->sig;
  }
  return L1;
}

/*Función agregarDatosArtistas
agrega datos del artista, especificamente el nombre de artista, de acuerdo a su id
Entrada: lista de canciones, lista de artistas, cantidad de canciones y cantidad
de artistas
Salida: lista*/
canciones *agregarDatosArtistas(canciones *L1,artistas *L3,int cantidadCanciones, int cantidadArtistas){
  canciones *aux1 = L1;
  int i,j;
  for(i=0;i<cantidadCanciones;i++){
    artistas *aux3 = L3;
    for(j=0;j<cantidadArtistas;j++){
      if(aux1->IDArtista == aux3->IDArtista){
        aux1->nombreArtista = aux3->nombreArtista;
      }
      aux3 = aux3->sig;
    }
    aux1 = aux1->sig;
  }
  return L1;
}

/*Función duracionTotal
Calcula la duracion total en segundos
Entrada: tiempo en minutos y tiempo en segundos
Salida: tiempo en segundos*/
int duracionTotal(int min, int seg){
  return min*60 + seg;
}

/*Función calcularDuracionMM
Calcula la duracion total en minutos
Entrada: tiempo en segundos
Salida: tiempo en minutos*/
int calcularDuracionMM(int duracionSS){
  return duracionSS/60;
}

/*Función calcularDuracionSS
Calcula la duracion en segundos
Entrada: tiempo en segundos
Salida: tiempo en segundos*/
int calcularDuracionSS(int duracionSS){
  return duracionSS%60;
}

/*Función swap
Intercambia dos nodos de la lista simple enlazada
Entrada: nodos a intercambiar
Salida: nodo intercambiado*/
canciones* swap(canciones* a,canciones* b){
  canciones* temp;
  temp = b->sig;
  b->sig = a;
  a->sig = temp;
  return b;
}

/* Algoritmo de ordenamiento - Método burbuja
Ordena los elementos de mayor a menor, en base a la popularidad, nombre artista
y/o duracion
Entrada: lista de canciones y cantidad de canciones
Salida: void*/
void burbuja(canciones** L, int cantidadCanciones){
  canciones** aux;
  int i, j, flag;
  for (i = 0; i <= cantidadCanciones; i++){
    aux = L;
    flag = 0;
    for (j = 0; j < cantidadCanciones - i - 1; j++){
      canciones* p1 = *aux;
      canciones* p2 = p1->sig;
      if (p1->popularidad < p2->popularidad){
        *aux = swap(p1, p2);
        flag = 1;
      }
      if (p1->popularidad == p2->popularidad){
        if(strcmp(p1->nombreArtista,p2->nombreArtista)>0){
          *aux = swap(p1,p2);
          flag = 1;
        }
        if(strcmp(p1->nombreArtista,p2->nombreArtista)==0){
          if(duracionTotal(p1->duracionMM,p1->duracionSS) > duracionTotal(p2->duracionMM,p2->duracionSS)){
            *aux = swap(p1,p2);
            flag = 1;
          }
        }
      }
      aux = &(*aux)->sig;
    }
    if (flag == 0){
      break;
    }
  }
}

/* Función crearPlaylist
Crea la playlist inicial con las canciones de acuerdo al genero de preferencia
Entrada: lista de canciones, preferencias, cantidad de preferencias y cantidad
de canciones en la playlist
Salida: lista playlist*/
canciones * crearPlaylist(canciones *L, int preferencias[],int cantidadPreferencias, int * cantCancionesPlaylist){
  canciones *aux;
  aux = L; //variable auxiliar para recorrer la list
  int i;
  canciones *ListaPlaylist = NULL;
  while(aux != NULL){ //hasta el final de la lista
    for(i = 0;i<cantidadPreferencias;i++){
      if(aux->IDGenero==preferencias[i]){
        ListaPlaylist = agregarInicioCanciones(ListaPlaylist, aux->nombreCancion, aux->duracionMM, aux->duracionSS, aux->IDArtista, aux->IDGenero, aux->popularidad, aux->nombreArtista, aux->nombreGenero);
        *cantCancionesPlaylist = *cantCancionesPlaylist + 1;
      }
    }
    aux = aux->sig; //avanza al siguiente elemento
  }
  return ListaPlaylist;
}


/* Función crearPlaylistAlternada
En base a la playlist inicial, alterna las canciones segun genero
Entrada: lista de canciones, preferencias, cantidad de preferencias y cantidad
de canciones en la playlist
Salida: lista playlist alternada*/
canciones * crearPlaylistAlternada(canciones * L, int preferencias[], int cantidadPreferencias, int cantCancionesPlaylist){
  canciones * aux;
  canciones * PlayListaAlternada = NULL;
  int idx = 0; // para array de preferencias
  int idx2 = 0; // para posicion en arrayAux
  int marcadas = 0; // para cortar la revision de canciones
  int auxMarcadas = 0;
  int arrayAux[cantCancionesPlaylist];
  for(int i = 0; i < cantCancionesPlaylist; i++){
    arrayAux[i] = 0;
  }
  while(marcadas < cantCancionesPlaylist){
    aux = L;
    auxMarcadas = 0;
    idx2 = 0;
    for(int j = 0; j < cantCancionesPlaylist; j++){
      // si el genero es el mismo y la posicion no se ha usado antes
      if(aux->IDGenero == preferencias[idx] && arrayAux[idx2] != 1){
        arrayAux[idx2] = 1;
        PlayListaAlternada = agregarFinal(PlayListaAlternada, aux->nombreCancion, aux->duracionMM, aux->duracionSS, aux->IDArtista, aux->IDGenero, aux->popularidad, aux->nombreArtista, aux->nombreGenero);
        idx++;
        if(idx == cantidadPreferencias){
          idx = 0;
        }
        auxMarcadas = 1;
        break;
      }
      idx2++;
      if(j != cantCancionesPlaylist-1){
        aux = aux->sig;
      }
    }
    if(auxMarcadas==1){
      marcadas++;
    }
    else{
      idx++;
    }
  }
  return PlayListaAlternada;
}

/* Función crearPlaylistFinal
Crea la playlist final con las restricciones de duracion deseada
Entrada: lista de canciones, duracion deseada en minutos y segundos, cantidad de
generos de archivo, cantidad de canciones en la playlist, duracion sobrante en
minutos y en segundos.
Salida: lista playlist final*/
canciones * crearPlaylistFinal(canciones * L, int duracionDeseadaMM, int duracionDeseadaSS, int CantGenerosArchivo, int cantCancionesPlaylist, int * duracionSobranteMM, int * duracionSobranteSS){
  int duracionTotalSeg = duracionTotal(duracionDeseadaMM, duracionDeseadaSS);
  int tiempoPlaylist = 0;
  int tiempoSobrante = 0;
  int cancionesAgregadas = 0;
  canciones * playlistFinal = NULL;
  canciones * aux = L;
  while(tiempoPlaylist < duracionTotalSeg){
    playlistFinal =  agregarFinal(playlistFinal, aux->nombreCancion, aux->duracionMM, aux->duracionSS, aux->IDArtista, aux->IDGenero, aux->popularidad, aux->nombreArtista, aux->nombreGenero);
    cancionesAgregadas++;
    tiempoPlaylist = tiempoPlaylist + duracionTotal(aux->duracionMM, aux->duracionSS);
    // este if es para cuando tenemos todas las canciones y sobra tiempo aun
    if(cancionesAgregadas % cantCancionesPlaylist == 0){
      aux = L;
    }
    else{
      aux = aux->sig;
    }
  }
  tiempoSobrante = tiempoPlaylist-duracionTotalSeg;
  if(tiempoSobrante>0){
    *duracionSobranteMM = calcularDuracionMM(tiempoSobrante);
    *duracionSobranteSS = calcularDuracionSS(tiempoSobrante);
  }
  return playlistFinal;
}



/*********************************************************************************************************/
int main(){
  FILE*archivoEntrada;
  FILE*archivoSalida;
  int cantidadArtistas;
  int cantidadGeneros;
  int cantidadCanciones;
  int duracionDeseadaMM;
  int duracionDeseadaSS;
  int CantGenerosArchivo = 0;
  int duracionSobranteMM = 0;
  int duracionSobranteSS = 0;
  int gen = 0;
  int pos = 0;
  int i,j,k,l;
  int listaPreferencias[cantidadGeneros];
  artistas *ListaArtistas = NULL;
  generos *ListaGeneros = NULL;
  canciones *ListaCanciones = NULL;
  canciones *ListaPlaylist = NULL;
  canciones *ListaPlaylistFinal = NULL;
  clock_t inicio1, termino1, inicio2, termino2;
  inicio1 = clock();


  //Lectura archivo artistas.in
  archivoEntrada = fopen("artistas.in","r");
  fscanf(archivoEntrada,"%i",&cantidadArtistas);
  for(i = 0; i<cantidadArtistas; i++){
    char * artista = (char *)malloc(sizeof(char)*100);
    int IDArtista;
    fscanf(archivoEntrada, "%i", &IDArtista);
    fscanf(archivoEntrada, "%s", artista);
    ListaArtistas = agregarInicioArtista(ListaArtistas,IDArtista,artista);
  }
  fclose(archivoEntrada);

  //Lectura archivo generos.in
  archivoEntrada = fopen("generos.in","r");
  fscanf(archivoEntrada,"%i",&cantidadGeneros);
  for(j = 0; j<cantidadGeneros; j++){
    char * generoMusical = (char *)malloc(sizeof(char)*100);
    int IDGenero;
    fscanf(archivoEntrada, "%i", &IDGenero);
    fscanf(archivoEntrada, "%s", generoMusical);
    ListaGeneros = agregarInicioGenero(ListaGeneros,IDGenero,generoMusical);
  }
  fclose(archivoEntrada);

  //Lectura archivo canciones.in
  archivoEntrada = fopen("canciones.in","r");
  fscanf(archivoEntrada,"%i",&cantidadCanciones);
  canciones * cancionesFinal = (canciones *)malloc(sizeof(canciones)*cantidadCanciones);
  for(k = 0; k<cantidadCanciones; k++){
    char * canciones = (char *)malloc(sizeof(char)*100);
    int duracionMM;
    int duracionSS;
    int IDArtista;
    int IDGenero;
    int popularidad;
    char * generos = (char *)malloc(sizeof(char)*100);
    char * artistas = (char *)malloc(sizeof(char)*100);
    fscanf(archivoEntrada, "%s", canciones);
    fscanf(archivoEntrada, "%i:%02i", &duracionMM,&duracionSS);
    fscanf(archivoEntrada, "%i", &IDArtista);
    fscanf(archivoEntrada, "%i", &IDGenero);
    fscanf(archivoEntrada, "%i", &popularidad);
    ListaCanciones = agregarInicioCanciones(ListaCanciones,canciones,duracionMM,duracionSS,IDArtista,IDGenero,popularidad,generos,artistas);
  }
  fclose(archivoEntrada);

  //organizacion de canciones
  ListaCanciones = agregarDatosGeneros(ListaCanciones,ListaGeneros,cantidadCanciones,cantidadGeneros);
  ListaCanciones = agregarDatosArtistas(ListaCanciones,ListaArtistas,cantidadCanciones,cantidadArtistas);
  burbuja(&ListaCanciones, cantidadCanciones);

  /*****************************archivosalida******************************/
  //Generación archivo de salida canciones ordenadas
  archivoSalida = fopen("salida.out","w");
  escribirListaCanciones(ListaCanciones, archivoSalida);
  printf("Se ha creado archivo de salida salida.out\n");
  fclose(archivoSalida);

  termino1 = clock();
  printf("Tiempo transcurrido: %f\n",(double)(termino1 - inicio1)/ CLOCKS_PER_SEC);
  /************************************************************************/

  /*****************************PLAYLIST******************************/
  inicio2 = clock();
  //Lectura archivo preferencias.in
  archivoEntrada = fopen("preferencias.in","r");
  fscanf(archivoEntrada,"%i:%02i",&duracionDeseadaMM,&duracionDeseadaSS);
  fscanf (archivoEntrada, "%d", &gen);
  while (!feof(archivoEntrada)){
    fscanf(archivoEntrada, "%d", &gen);
    CantGenerosArchivo++;
  }
  rewind(archivoEntrada);
  fscanf(archivoEntrada,"%i:%02i",&duracionDeseadaMM,&duracionDeseadaSS);

  int generosPlaylist[CantGenerosArchivo];
  while (!feof(archivoEntrada)){
    fscanf(archivoEntrada, "%d", &generosPlaylist[pos]);
    pos++;
  }
  fclose(archivoEntrada);

  //Creacion de playlists segun restricciones
  int cantCancionesPlaylist = 0;
  ListaPlaylist = crearPlaylist(ListaCanciones, generosPlaylist,CantGenerosArchivo, &cantCancionesPlaylist);
  burbuja(&ListaPlaylist, cantCancionesPlaylist);
  ListaPlaylist = crearPlaylistAlternada(ListaPlaylist, generosPlaylist, CantGenerosArchivo, cantCancionesPlaylist);
  ListaPlaylistFinal = crearPlaylistFinal(ListaPlaylist, duracionDeseadaMM, duracionDeseadaSS, CantGenerosArchivo, cantCancionesPlaylist, &duracionSobranteMM, &duracionSobranteSS);

  /*****************************archivosalida******************************/
  //Generación archivo de salida playlist
  archivoSalida = fopen("playlist.out","w");
  escribirListaCanciones(ListaPlaylistFinal, archivoSalida);
  fprintf(archivoSalida, "%d:%02d\n",duracionSobranteMM,duracionSobranteSS);
  printf("Se ha creado archivo de salida playlist.out\n");
  fclose(archivoSalida);

  /************************************************************************/
  termino2 = clock();
  printf("Tiempo transcurrido: %f\n",(double)(termino2 - inicio2)/ CLOCKS_PER_SEC);

  return 0;
}
