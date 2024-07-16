//---------------------------------------------------------------------------

#ifndef ArchivoH
#define ArchivoH

#include <System.Classes.hpp>
#include "definition.h"
//---------------------------------------------------------------------------
class Archivo
{
  private:
    // pending
  public:
    void Grabar(const AnsiString fileName, RegAlumno registroAlumno);
    bool esCodigoRepetido(AnsiString fileName, byte codigo);
    bool esCodigoRepetido(AnsiString fileName, RegAlumno reg);
    void esRegistroValido(RegAlumno reg);
};
#endif

