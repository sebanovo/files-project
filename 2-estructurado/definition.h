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
//    Word código;
//    char nombre[21];
//    char dirección[21];
//    Fecha fechaNac;
//};

struct Fecha // 4 bytes
{
    byte día;
    byte mes;
    Word año;
};

struct RegAlumno // 72 bytes
{
    byte marca; // activo = 0; borrado = 1;
    Word código;
    char nombre[31];
    char dirección[26];
    Fecha fecha;
    Cardinal teléfono;
};

struct RegIdxCod // 8 bytes
{
    Word código;
    Cardinal pos;
};

struct RegIdxNom // 37 bytes
{
    char nombre[31];
    Cardinal pos;
};

struct RegIdxFecha // 8 bytes
{
    byte día;
    byte mes;
    Word año;
    Cardinal pos;
};

struct RegIdxTelefono // 8 bytes
{
    Cardinal teléfono;
    Cardinal pos;
};

#endif

