//---------------------------------------------------------------------------

#pragma hdrstop

#include "Archivo.h"
#include <vcl.h>
#include <fstream>
#include <cctype>
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

// el eof => 2bytes cr = 13 lf = 10; en realidad el enter son dos bytes
// clase Archivo
Cardinal contar_caracteres(AnsiString name)
{
    Cardinal c;
    char x;
    c = 0;
    ifstream f(name.c_str());
    if (f.fail())
        return c;

    while (!f.eof()) {
        x = f.get();

        if (f.eof() || x == 10) // sin es EOL
            continue;

        c++;
    }

    f.close();

    return c;
}

// ejercicio 1
// hacer una funcion que devuelva la cantidad de palabras que hay en un archivo
// palabra secuencia de letras
// "Hola23" => 1
// "Hola_que_tal" => 3
bool esLetra(char letra)
{
    AnsiString letras =
        "qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNMáéíóúÁÉÍÓÚäëïöüÄËÏÖÜ";
    return letras.Pos(letra) > 0;
}

Cardinal contar_palabras(AnsiString name)
{
    Cardinal c;
    char x;
    bool b;
    b = false;
    c = 0;
    ifstream f(name.c_str());
    if (!f.fail()) {
        while (!f.eof()) {
            x = f.get();
            if (!f.eof()) {
                if (esLetra(x)) {
                    if (!b) {
                        b = true;
                        c++;
                    }
                } else {
                    b = false;
                }
            }
        }
        f.close();
    }
    return c;
}

Cardinal contar_digitos(AnsiString name)
{
    Cardinal c;
    char x;
    c = 0;
    fstream f(name.c_str());
    if (!f.fail()) {
        while (!f.eof()) {
            x = f.get();
            if (!f.eof()) {
                if (isdigit(x)) {
                    c++;
                }
            }
        }
        f.close();
    }
    return c;
}

Cardinal contar_numeros(AnsiString name)
{
    Cardinal c;
    char x;
    bool b;
    b = false;
    c = 0;
    ifstream f(name.c_str());
    if (!f.fail()) {
        while (!f.eof()) {
            x = f.get();
            if (!f.eof()) {
                if (isdigit(x)) {
                    if (!b) {
                        b = true;
                        c++;
                    }
                } else {
                    b = false;
                }
            }
        }
        f.close();
    }
    return c;
}

// tarea:
// hacer una funcion que devuelva la cantidad de palabras que tengan al menos 3 vocales
bool esVocal(char v)
{
    AnsiString vocales = "aeiouAEIOUáéíóúÁÉÍÓÚ";
    return vocales.Pos(v) > 0;
}

Cardinal contar_vocales(AnsiString palabra)
{
    Cardinal c;
    c = 0;
    for (int i = 1; i <= palabra.Length(); i++) {
        if (esVocal(palabra[i])) {
            c++;
        }
    }
    return c;
}

Cardinal ejemplo1(AnsiString name)
{
    char x;
    bool b = false;
    Cardinal c = 0;
    AnsiString palabra = "";

    ifstream f(name.c_str());

    if (f.fail()) {
        return c;
    }

    while (f.get(x)) {
        if (esLetra(x)) {
            palabra = palabra + x;
            b = true;
        } else {
            if (contar_vocales(palabra) >= 3) {
                c++;
            }
            palabra = "";
            b = false;
        }
    }

    // revision final
    if (contar_vocales(palabra) >= 3) {
        c++;
    }

    f.close();

    return c;
}

// ejemplo 2
// leer de un archivo la cantidad de números de una linea y
// cargar en otro archivo la cantidad de números de cada linea
Cardinal cantidad_de_numeros(AnsiString linea)
{
    Cardinal c = 0;
    bool b = false;

    for (int i = 1; i <= linea.Length(); i++) {
        if (isdigit(linea[i])) {
            if (!b) {
                c++;
                b = true;
            }
        } else {
            b = false;
        }
    }
    return c;
}

void ejemplo2(AnsiString fileName, AnsiString newFileName)
{
    fstream fi(fileName.c_str());
    fstream fo(newFileName.c_str(), ios::trunc | ios::out);
    char x;
    Cardinal c;
    AnsiString linea;

    if (fi.fail() || !fo.is_open()) {
        fi.close();
        fo.close();
        return;
    }

    while (fi.get(x)) {
        linea = "";
        while (!fi.eof() && x != 10) {
            linea = linea + x;
            x = fi.get();
        }
        c = cantidad_de_numeros(linea);
        fo << c;
        fo << '\n';
    }

    fi.close();
    fo.close();
}

// Hacer un algorítmo para copiar a un archivo todas las primeras palabras de
// cada línea, siendo la primer letra mayúsculas y separadas por comas (,)

// hola a todos => Hola
AnsiString primer_palabra(AnsiString linea)
{
    AnsiString primerPalabra = "";
    bool encontradoPrimerLetra = false;
    int c = 1;

    for (int i = 1; i <= linea.Length(); i++) {
        if (esLetra(linea[i])) {
            primerPalabra += c == 1 ? UpperCase(linea[i]) : linea[i];
            c++;
            encontradoPrimerLetra = true;
        } else {
            if (encontradoPrimerLetra) {
                // nos salimos del bucle
                break;
            }
        }
    }

    return primerPalabra;
}

void ejemplo3(AnsiString fileName, AnsiString newFileName)
{
    char x;
    AnsiString c;
    AnsiString linea;
    bool es_primer_palabra = true;
    fstream fi(fileName.c_str());
    fstream fo(newFileName.c_str(), ios::trunc | ios::out);

    if (fi.fail() || fo.fail()) {
        fi.close();
        fo.close();
        return;
    }

    while (fi.get(x)) {
        linea = "";
        while (!fi.eof() && x != 10) {
            linea = linea + x;
            x = fi.get();
        }
        if (!es_primer_palabra) {
            fo << ',';
        }
        c = primer_palabra(linea);
        fo << c;
        es_primer_palabra = false;
    }
    fi.close();
    fo.close();
}

// eliminar no alfanumerico
bool esPuntuacion(char simbolo)
{
    AnsiString simbolos_de_puntuacion = ".,;:¿?¡! "; // incluyo el espacio
    return simbolos_de_puntuacion.Pos(simbolo) > 0;
}

void ejemplo4(AnsiString name)
{
    char x;
    AnsiString temporaryFileName = "temporal.exe";
    ifstream fi(name.c_str());
    ofstream fo(temporaryFileName.c_str());
    if (fi.fail()) {
        fi.close();
        fo.close();
        return;
    }

    while (fi.get(x)) {
        if (esLetra(x) || esPuntuacion(x) || x == 10) { // x == 10 los enter
            fo.put(x);
        }
    }

    fi.close();
    fo.close();
    remove(name.c_str());
    rename(temporaryFileName.c_str(), name.c_str());
}

// Justificar a las izquierda (alinear a la izquierda)
void ejemplo5(AnsiString name)
{
    char x;
    bool b = false;
    AnsiString temporaryFileName = "temporal.tmp";
    ifstream fi(name.c_str());
    ofstream fo(temporaryFileName.c_str());
    if (fi.fail()) {
        fi.close();
        fo.close();
        return;
    }

    while (fi.get(x)) {
        if (x != ' ' || b) // si !(p y !q) => !p o q
            fo.put(x);
        if (x != ' ')
            b = true;
        if (x == 10)
            b = false;
    }

    fi.close();
    fo.close();
    remove(name.c_str());
    rename(temporaryFileName.c_str(), name.c_str());
}

// Hacer un algoritmo para eliminar todos los caracteres no númericos de un
// archivo de texto.   separados por un espacio (' ')
AnsiString obtener_numeros(AnsiString linea)
{
    AnsiString numeros = "";
    bool b = false;
    linea = linea + ' ';
    for (int i = 1; i <= linea.Length(); i++) {
        if (isdigit(linea[i])) {
            numeros = numeros + linea[i];
        } else {
            numeros = numeros.Trim() + ' ';
        }
    }
    return numeros.Trim();
}

void ejemplo6(AnsiString name)
{
    char x;
    AnsiString linea;

    AnsiString temporaryFileName = "temporal.tmp";
    ifstream fi(name.c_str());
    ofstream fo(temporaryFileName.c_str());

    if (fi.fail() || fi.fail()) {
        fi.close();
        fo.close();
        return;
    }

    while (fi.get(x)) {
        linea = "";
        while (!fi.eof() && x != 10) {
            linea = linea + x;
            x = fi.get();
        }
        AnsiString temporal = obtener_numeros(linea);
        if (!temporal.IsEmpty()) {
            fo << obtener_numeros(linea);
            fo << '\n';
        }
    }

    fi.close();
    fo.close();
    remove(name.c_str());
    rename(temporaryFileName.c_str(), name.c_str());
}

//  Hacer un algoritmo para alinear a la derecha un archivo de texto
Cardinal obtener_longitud_de_la_mayor_linea(AnsiString name)
{
    char x;
    Cardinal mayor = 0;
    Cardinal actual;
    AnsiString linea;

    ifstream fi(name.c_str());

    if (fi.fail()) {
        fi.close();
        return mayor;
    }

    while (fi.get(x)) {
        linea = "";
        while (!fi.eof() && x != 10) {
            linea = linea + x;
            x = fi.get();
        }
        actual = linea.TrimRight().Length(); // ver
        if (mayor < actual) {
            mayor = actual;
        }
    }
    fi.close();

    return mayor;
}

AnsiString ajustar_linea(AnsiString linea, Cardinal longitud_mayor_linea)
{
    AnsiString espacios = "";
    Cardinal diferencia = longitud_mayor_linea - linea.Length();

    for (int i = 0; i < diferencia; i++) {
        espacios = espacios + " ";
    }

    return espacios + linea;
}

void ejemplo7(AnsiString name)
{
    char x;
    AnsiString linea;
    Cardinal longitud_mayor_linea = obtener_longitud_de_la_mayor_linea(name);

    AnsiString temporaryFileName = "temporal.tmp";
    ifstream fi(name.c_str());
    ofstream fo(temporaryFileName.c_str());

    if (fi.fail() || fi.fail()) {
        fi.close();
        fo.close();
        return;
    }

    while (fi.get(x)) {
        linea = "";
        while (!fi.eof() && x != 10) {
            linea = linea + x;
            x = fi.get();
        }
        fo << ajustar_linea(linea.TrimRight(), longitud_mayor_linea);
        fo << '\n';
    }

    fi.close();
    fo.close();
    remove(name.c_str());
    rename(temporaryFileName.c_str(), name.c_str());
}

// Modelos Proyecto 1
// Escribir un algoritmo para dado un archivo de texto conteniendo un mapa de BITs como el desarrollado en el proyecto 1(nivel1.txt) genere otro archivo con los caracteres modificados de la siguiente forma:

// "#" por "M"
// "h" por "@"
// "p" por "#"
// " " por "c"

void tarea1(AnsiString fileName, AnsiString newFileName)
{
    char x;
    ifstream fi(fileName.c_str());
    ofstream fo(newFileName.c_str());

    if (fi.fail() || fo.fail()) {
        fi.close();
        fo.close();
        return;
    }

    while (fi.get(x)) {
        switch (x) {
            case '#':
                fo << 'M';
                break;
            case 'h':
                fo << '@';
                break;
            case 'p':
                fo << '#';
                break;
            case ' ':
                fo << 'c';
                break;
            default:
                fo << '\n';
        }
    }
    fi.close();
    fo.close();
}

// tarea2 verificar que esten somalemente los caracteres del mapa de BITs
bool esBITs(char x)
{
    AnsiString mapaBITs = "#hp M@#c";
    return mapaBITs.Pos(x) > 0;
}

bool tarea2(AnsiString fileName)
{
    char x;
    ifstream f(fileName.c_str());

    if (f.fail())
        throw Exception("fallo al abrir");

    while (f.get(x)) {
        if (!esBITs(x) && x != '\n') {
            return false;
        }
    }
    f.close();
    return true;
}

// Search and Replace
// reemplazar un texto por otro
AnsiString reemplazar(const AnsiString original, const AnsiString textAcambiar,
    const AnsiString textNuevo)
{
    AnsiString resultado;
    int i = 1;

    while (i <= original.Length()) {
        int j = 1;
        while (j < textAcambiar.Length() && i + j - 1 < original.Length() &&
               original[i + j - 1] == textAcambiar[j])
        {
            ++j;
        }

        if (j == textAcambiar.Length()) {
            resultado += textNuevo;
            i += textAcambiar.Length();
        } else {
            resultado += original[i];
            ++i;
        }
    }

    return resultado;
}

void tarea3(AnsiString fileName, AnsiString wordToReplace, AnsiString word)
{
    char x;
    AnsiString temporaryFileName = "temporal.tmp";
    AnsiString linea;
    ifstream fi(fileName.c_str());
    ofstream fo(temporaryFileName.c_str());

    if (fi.fail() || fi.fail()) {
        fi.close();
        fo.close();
        return;
    }

    while (fi.get(x)) {
        linea = "";
        while (!fi.eof() && x != '\n') {
            linea = linea + x;
            x = fi.get();
        }
        fo << reemplazar(linea, wordToReplace, word);
        fo << '\n';
    }

    fi.close();
    fo.close();
    remove(fileName.c_str());
    rename(temporaryFileName.c_str(), fileName.c_str());
}
// tarea 4 Convertir a Mayúsculas la primer letra de cada palabra

void convertirPrimeriLetraDeCadaPalabraEnMayuscula(AnsiString &linea)
{
    bool b = false;
    if (linea.Length() == 1) {
        linea = UpperCase(linea);
        return;
    }

    for (int i = 1; i <= linea.Length(); i++) {
        if (esLetra(linea[i])) {
            if (!b) {
                b = true;
                linea[i] = UpperCase(linea[i])[1];
            }
        } else {
            b = false;
        }
    }
}
void tarea4(AnsiString fileName)
{
    char x;
    AnsiString temporaryFileName = "temporal.tmp";
    AnsiString linea;
    ifstream fi(fileName.c_str());
    ofstream fo(temporaryFileName.c_str());

    if (fi.fail() || fo.fail()) {
        fi.close();
        fo.close();
        return;
    }

    while (fi.get(x)) {
        linea = "";
        while (!fi.eof() && x != '\n') {
            linea += x;
            x = fi.get();
        }
        convertirPrimeriLetraDeCadaPalabraEnMayuscula(linea);
        fo << linea;
        fo << '\n';
    }

    fi.close();
    fo.close();
    remove(fileName.c_str());
    rename(temporaryFileName.c_str(), fileName.c_str());
}

