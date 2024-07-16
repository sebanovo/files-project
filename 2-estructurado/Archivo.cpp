//---------------------------------------------------------------------------

#pragma hdrstop

#include <fstream>
#include "Archivo.h"
//---------------------------------------------------------------------------
void Archivo::Grabar(const AnsiString fileName, RegAlumno registroAlumno)
{
    // espera
}

bool Archivo::esCodigoRepetido(AnsiString fileName, RegAlumno reg)
{
    ifstream fi(fileName.c_str());
    RegAlumno registroAux;
    bool hallado = false;
    while (!hallado && fi.read((char*)&registroAux, sizeof(registroAux))) {
        hallado = reg.código == registroAux.código && reg.marca == 0;
    }

    return hallado;
}

void Archivo::esRegistroValido(RegAlumno reg)
{
    if (reg.código < 0)
        throw Exception("El Código tiene que ser mayor a 0 y menor a 256");
    if (reg.nombre == "")
        throw Exception("El campo nombre esta vacio");
    if (reg.dirección == "")
        throw Exception("El campo dirección esta vacio");
    if (reg.fechaNac.día <= 0 || reg.fechaNac.día > 30)
        throw Exception("El día tiene que estar entre 1 y 30");
    if (reg.fechaNac.mes <= 0 || reg.fechaNac.mes > 12)
        throw Exception("El mes tiene que estar entre 1 y 12");
    if (reg.fechaNac.año < 0)
        throw Exception("No hay años negativos");
    if (reg.teléfono < 0)
        throw Exception("No hay telefonos negativos");
}

#pragma package(smart_init)

