//---------------------------------------------------------------------------

#ifndef ArchivoH
#define ArchivoH

Cardinal contar_caracteres(AnsiString name);
Cardinal contar_palabras(AnsiString name);
Cardinal contar_digitos(AnsiString name);
Cardinal contar_numeros(AnsiString name);
Cardinal ejemplo1(AnsiString name);
void ejemplo2(AnsiString FileName, AnsiString newFileName);
void ejemplo3(AnsiString fileName, AnsiString newFileName);
void ejemplo4(AnsiString name);
void ejemplo5(AnsiString name);
void ejemplo6(AnsiString name);
void ejemplo7(AnsiString name);

// Tareas completadas:
// 1. Hacer corrrer el algoritmo eliminar no letras ni caracteres de puntuacion
// 2. Hacer correr el algoritmo AlinearaLaIzquierda
// 3. Hacer un algoritmo para eliminar todos los caracteres no númericos de un
// archivo de texto.
// 4. Hacer un algoritmo para alinear a la derecha un archivo de texto

void tarea1(AnsiString fileName, AnsiString newFileName);
bool tarea2(AnsiString fileName);
void tarea3(AnsiString fileName, AnsiString wordToReplace, AnsiString word);
void tarea4(AnsiString fileName);
//---------------------------------------------------------------------------
#endif

