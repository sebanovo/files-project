//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
#include <fstream>
#include <filesystem>
#include <vector>
#include "definition.h"
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
  __published: // IDE-managed Components
    TEdit* Edit1;
    TEdit* Edit2;
    TEdit* Edit3;
    TEdit* Edit4;
    TEdit* Edit5;
    TEdit* Edit6;
    TEdit* Edit7;
    TLabel* Label1;
    TButton* Button1;
    TButton* Button2;
    TButton* Button3;
    TButton* Button6;
    TButton* Button7;
    TButton* Button8;
    TButton* Button9;
    TButton* Button11;
    TMainMenu* MainMenu1;
    TMenuItem* Archivo1;
    TMenuItem* IndexarPorCodigo1;
    TMenuItem* IndexarPorNombre1;
    TMenuItem* Ordenamiento1;
    TMenuItem* PorCodigo1;
    TMenuItem* PorNombre1;
    TComboBox* ComboBox1;
    TMenuItem* IndexarPorFecha1;
    TMenuItem* IndexarPorTelefono1;
    TMenuItem* PorFecha1;
    TMenuItem* PorTelefono1;
    TMenuItem* Modelos1;
    TMenuItem* Pregunta1;
    TStringGrid* StringGrid1;
    void __fastcall Edit1Exit(TObject* Sender);
    void __fastcall FormCreate(TObject* Sender);
    void __fastcall Button1Click(TObject* Sender);
    void __fastcall Button2Click(TObject* Sender);
    void __fastcall Button3Click(TObject* Sender);
    void __fastcall Button5Click(TObject* Sender);
    void __fastcall Button6Click(TObject* Sender);
    void __fastcall Button8Click(TObject* Sender);
    void __fastcall Button7Click(TObject* Sender);
    void __fastcall Button9Click(TObject* Sender);
    void __fastcall Button10Click(TObject* Sender);
    void __fastcall Button11Click(TObject* Sender);
    void __fastcall IndexarPorCodigo1Click(TObject* Sender);
    void __fastcall PorCodigo1Click(TObject* Sender);
    void __fastcall IndexarPorNombre1Click(TObject* Sender);
    void __fastcall PorNombre1Click(TObject* Sender);
    void __fastcall IndexarPorFecha1Click(TObject* Sender);
    void __fastcall IndexarPorTelefono1Click(TObject* Sender);
    void __fastcall PorFecha1Click(TObject* Sender);
    void __fastcall PorTelefono1Click(TObject* Sender);
    void __fastcall Pregunta1Click(TObject* Sender);
  private: // User declarations
    AnsiString nomArch, nomArchIdxCod, nomArchIdxNom, nomArchIdxFecha,
        nomArchIdxTelefono;
    fstream *pf, *pfIdx;
    AnsiString filesDirectoryStr;
    std::vector<AnsiString> formFields = { "Marca", "Código", "Nombre",
        "Dirección", "Fecha", "Teléfono" };
  public: // User declarations
    __fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();
};

// Valores
/*
  byte = 1 byte
  char = 1 byte
  Word = 2 byte
  Cardinal = 4 byte
  char[value] = value byte
*/

//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif

