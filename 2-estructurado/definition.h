//---------------------------------------------------------------------------

#ifndef DefinitionH
#define DefinitionH
//---------------------------------------------------------------------------
/*
	 EQUIVALENCIAS
	 -------------
	 byte = 1 byte
	 char = 1 byte
	 Word = 2 byte
	 Cardinal = 4 byte
	 char[length] = length byte
 */

//struct RegAlumnoAnt // 48 bytes
//{
//    Word c�digo;
//    char nombre[21];
//    char direcci�n[21];
//    Fecha fechaNac;
//};

struct Fecha // 4 bytes
{
    byte d�a;
    byte mes;
    Word a�o;
};

struct RegAlumno // 72 bytes
{
    byte marca; // activo = 0; borrado = 1;
    Word c�digo;
    char nombre[31];
    char direcci�n[26];
    Fecha fecha;
    Cardinal tel�fono;
};

struct RegIdxCod // 8 bytes
{
    Word c�digo;
    Cardinal pos;
};

struct RegIdxNom // 37 bytes
{
    char nombre[31];
    Cardinal pos;
};

struct RegIdxFecha // 8 bytes
{
    byte d�a;
    byte mes;
    Word a�o;
    Cardinal pos;
};

struct RegIdxTelefono // 8 bytes
{
    Cardinal tel�fono;
    Cardinal pos;
};

#endif

