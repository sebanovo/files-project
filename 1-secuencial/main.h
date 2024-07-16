//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
  __published: // IDE-managed Components
    TOpenTextFileDialog* OpenTextFileDialog1;
    TEdit* Edit1;
    TEdit* Edit2;
    TMainMenu* MainMenu1;
    TMenuItem* Practica1;
    TMenuItem* ContarCaracteres1;
    TMenuItem* ContarPalabras1;
    TMenuItem* ContarDigitos1;
    TMenuItem* ContarNumeros1;
    TMenuItem* E11;
    TMenuItem* E21;
    TMenuItem* E31;
    TMenuItem* E41;
    TMenuItem* E51;
    TMenuItem* E61;
    TMenuItem* T11;
    TMenuItem* T21;
    TMenuItem* T31;
    TMenuItem* T41;
    void __fastcall ContarCaracteres1Click(TObject* Sender);
    void __fastcall ContarPalabras1Click(TObject* Sender);
    void __fastcall ContarDigitos1Click(TObject* Sender);
    void __fastcall ContarNumeros1Click(TObject* Sender);
    void __fastcall E11Click(TObject* Sender);
    void __fastcall E21Click(TObject* Sender);
    void __fastcall E31Click(TObject* Sender);
    void __fastcall E41Click(TObject* Sender);
    void __fastcall E51Click(TObject* Sender);
    void __fastcall E61Click(TObject* Sender);
    void __fastcall E71Click(TObject* Sender);
    void __fastcall T11Click(TObject* Sender);
    void __fastcall T21Click(TObject* Sender);
    void __fastcall T31Click(TObject* Sender);
    void __fastcall T41Click(TObject* Sender);
  private: // User declarations
  public: // User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif

