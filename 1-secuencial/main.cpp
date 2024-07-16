//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "Archivo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContarCaracteres1Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        Edit2->Text = contar_caracteres(OpenTextFileDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContarPalabras1Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        Edit2->Text = contar_palabras(OpenTextFileDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContarDigitos1Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        Edit2->Text = contar_digitos(OpenTextFileDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContarNumeros1Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        Edit2->Text = contar_numeros(OpenTextFileDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E11Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        Edit2->Text = ejemplo1(OpenTextFileDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E21Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        ejemplo2(OpenTextFileDialog1->FileName, "output2.txt");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E31Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        ejemplo3(OpenTextFileDialog1->FileName, "output3.txt");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E41Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        ejemplo4(OpenTextFileDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E51Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        ejemplo5(OpenTextFileDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E61Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        ejemplo6(OpenTextFileDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E71Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        ejemplo7(OpenTextFileDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T11Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        tarea1(OpenTextFileDialog1->FileName, "nivel21.txt");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T21Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        bool b = tarea2(OpenTextFileDialog1->FileName);
        ShowMessage(b ? "Formato OK" : "Formato erróneo");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T31Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        AnsiString wordToReplace =
            InputBox("Search and Replace", "Palabra a reemplazar", "");
        AnsiString word = InputBox("Search and Replace", "palabra", "");
        tarea3(OpenTextFileDialog1->FileName, wordToReplace, word);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T41Click(TObject* Sender)
{
    if (OpenTextFileDialog1->Execute()) {
        Edit1->Text = OpenTextFileDialog1->FileName;
        tarea4(OpenTextFileDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

