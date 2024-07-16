//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"

using std::filesystem::current_path;
using std::filesystem::path;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;
//---------------------------------------------------------------------------

AnsiString folderName = "Archivos";
AnsiString ArchivoAlumnos = "Alumnos.dat";
AnsiString ArchivoCodigoIdx = "codi.idx";
AnsiString ArchivoNombreIdx = "nombre.idx";
AnsiString ArchivoFechaIdx = "fecha.idx";
AnsiString ArchivoTelefonoIdx = "telefono.idx";

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}

__fastcall TForm1::~TForm1()
{
    delete pf;
}

//---------------------------------------------------------------------------
// (ON EXIT) EDIT 1
void __fastcall TForm1::Edit1Exit(TObject* Sender)
{
    RegAlumno reg;
    bool hallado = false;
    Word codi = Edit1->Text == "" ? 0 : StrToInt(Edit1->Text);
    pf = new fstream(nomArch.c_str());
    if (pf->fail()) {
        pf->close();
        delete pf;
        return;
    }

    while (!hallado && pf->read((char*)&reg, sizeof(reg))) {
        hallado = codi == reg.c�digo && reg.marca == 0;
    }

    if (!hallado)
        return Button3Click(Sender);

    Edit2->Text = reg.nombre;
    Edit3->Text = reg.direcci�n;
    Edit4->Text = reg.fecha.d�a;
    Edit5->Text = reg.fecha.mes;
    Edit6->Text = reg.fecha.a�o;
    Edit7->Text = reg.tel�fono;
    Edit2->SetFocus();

    pf->close();
    delete pf;
}
//---------------------------------------------------------------------------
// CREAR FORMULARIO
void __fastcall TForm1::FormCreate(TObject* Sender)
{
    path projectDirectory = current_path().parent_path().parent_path();
    path filesDirectory = projectDirectory / folderName.c_str();
    filesDirectoryStr = filesDirectory.string().c_str();

    std::filesystem::create_directory(
        (path)(projectDirectory / folderName.c_str()));

    nomArch = filesDirectoryStr + "\\" + ArchivoAlumnos;
    nomArchIdxCod = filesDirectoryStr + "\\" + ArchivoCodigoIdx;
    nomArchIdxNom = filesDirectoryStr + "\\" + ArchivoNombreIdx;
    nomArchIdxFecha = filesDirectoryStr + "\\" + ArchivoFechaIdx;
    nomArchIdxTelefono = filesDirectoryStr + "\\" + ArchivoTelefonoIdx;

    pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
    if (pf->fail()) {
        delete pf;
        pf = new fstream(nomArch.c_str(), ios::out | ios::binary);
    }
    pf->close();
    delete pf;

    Button7->Enabled = false;
    Button8->Enabled = false;
    Button9->Enabled = false;

    for (byte i = 0; i < formFields.size(); i++) {
        StringGrid1->Cells[i][0] = formFields[i];
    }
}
//----------------------------------------------------------------------
// LIMPIAR
void __fastcall TForm1::Button3Click(TObject* Sender)
{
    Edit2->Text = "";
    Edit3->Text = "";
    Edit4->Text = "";
    Edit5->Text = "";
    Edit6->Text = "";
    Edit7->Text = "";
}
//---------------------------------------------------------------------------
void validarFormulario(RegAlumno reg)
{
    if (reg.c�digo < 0 || reg.c�digo > 255)
        throw Exception("El c�digo tiene que estar en el dominio 0 ... 255");
    else if (reg.fecha.d�a < 0 || reg.fecha.d�a > 31)
        throw Exception("Hay 31 d�as o menos");
    else if (reg.fecha.mes < 0 || reg.fecha.mes > 12)
        throw Exception("Hay 12 meses o menos");
    else if (reg.fecha.a�o < 0 || reg.fecha.a�o > 65535)
        throw Exception("El a�o tiene que estar en el dominio de 0 ... 65535");
    else if (reg.tel�fono < 10000000 || reg.tel�fono > 10000000 * 10 - 1)
        throw Exception("El n�mero tiene que tener 8 d�gitos");
}
// GRABAR
void __fastcall TForm1::Button1Click(TObject* Sender)
{
    RegAlumno reg1, reg2;
    AnsiString cadena;

    reg1.marca = 0;
    reg1.c�digo = StrToInt(Edit1->Text);
    cadena = Edit2->Text;
    strcpy(reg1.nombre, cadena.c_str());
    cadena = Edit3->Text;
    strcpy(reg1.direcci�n, cadena.c_str());
    reg1.fecha.d�a = StrToInt(Edit4->Text);
    reg1.fecha.mes = StrToInt(Edit5->Text);
    reg1.fecha.a�o = StrToInt(Edit6->Text);
    reg1.tel�fono = StrToInt(Edit7->Text);
    bool hallado = false;

    try {
        validarFormulario(reg1);
    } catch (AnsiString e) {
        return ShowMessage(e);
    }

    pf = new fstream(nomArch.c_str(), ios::in | ios::out | ios::binary);

    if (pf->fail()) {
        pf->close();
        delete pf;
        return;
    }

    // buscar si esta repetido
    while (!hallado && pf->read((char*)&reg2, sizeof(reg2))) {
        hallado = reg1.c�digo == reg2.c�digo && reg1.marca == 0;
    }

    if (hallado) {
        pf->seekg(-sizeof(reg1), ios::cur);
        pf->write((char*)&reg1, sizeof(reg1));
    } else {
        pf->close();
        delete pf;
        pf = new fstream(nomArch.c_str(), ios::app | ios::binary);
        pf->write((char*)&reg1, sizeof(reg1));
    }

    Button3Click(Sender);
    Edit1->Text = "0";
    Edit1->SetFocus();
    delete pf;
}
//---------------------------------------------------------------------------
// ELIMINAR
void __fastcall TForm1::Button2Click(TObject* Sender)
{
    RegAlumno reg;
    bool hallado;
    Word codi;
    hallado = false;
    codi = StrToInt(Edit1->Text);
    pf = new fstream(nomArch.c_str(), ios::binary | ios::in | ios::out);

    if (pf->fail()) {
        pf->close();
        delete pf;
    }

    while (!hallado && pf->read((char*)&reg, sizeof(reg))) {
        hallado = codi == reg.c�digo && reg.marca == 0;
        if (hallado) {
            byte marca = 1;
            pf->seekg(-sizeof(reg), ios::cur);
            pf->write((char*)&marca, 1);
            Button3Click(Sender);
            Edit1->Text = "0";
            Edit1->SetFocus();
        }
    }

    pf->close();
    delete pf;
}
//---------------------------------------------------------------------------
// GENERAR INDEXAR POR CODIGO
void __fastcall TForm1::IndexarPorCodigo1Click(TObject* Sender)
{
    RegAlumno reg;
    RegIdxCod regIdx;

    pf = new fstream(nomArch.c_str(), ios::binary | ios::in);
    pfIdx = new fstream(nomArchIdxCod.c_str(), ios::binary | ios::out);

    if (pf->fail() || pfIdx->fail()) {
        pf->close();
        pfIdx->close();
        return;
    }

    regIdx.pos = pf->tellg();
    while (pf->read((char*)&reg, sizeof(reg))) {
        regIdx.c�digo = reg.c�digo;
        pfIdx->write((char*)&regIdx, sizeof(regIdx));
        regIdx.pos = pf->tellg();
    }

    pf->close();
    pfIdx->close();
}
//---------------------------------------------------------------------------
// BUSCAR POR CODIGO CON IDX
void __fastcall TForm1::Button5Click(TObject* Sender)
{
    RegAlumno reg;
    RegIdxCod regIdx;
    bool hallado = false;
    Word codi = StrToInt(Edit1->Text);
    pfIdx = new fstream(nomArchIdxCod.c_str(), ios::binary | ios::in);

    if (pfIdx->fail()) {
        pfIdx->close();
        delete pfIdx;
        return;
    }

    while (!hallado && pfIdx->read((char*)&regIdx, sizeof(regIdx))) {
        hallado = regIdx.c�digo == codi;
    }

    pfIdx->close();
    if (!hallado)
        return Button3Click(Sender);

    pf = new fstream(nomArch.c_str(), ios::binary | ios::in);
    pf->seekg(regIdx.pos, ios::beg);
    pf->read((char*)&reg, sizeof(reg));
    pf->close();
    delete (pf);
    Edit2->Text = reg.nombre;
    Edit3->Text = reg.direcci�n;
    Edit4->Text = reg.fecha.d�a;
    Edit5->Text = reg.fecha.mes;
    Edit6->Text = reg.fecha.a�o;
    Edit7->Text = reg.tel�fono;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject* Sender)
{
    RegAlumno reg;
    byte pos = ComboBox1->ItemIndex;

    if (pos == 0) {
        RegIdxCod regIdx;
        Button7->Enabled = true;
        Button8->Enabled = true;
        Button9->Enabled = true;
        pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
        pfIdx = new fstream(nomArchIdxCod.c_str(), ios::in | ios::binary);
        if (pfIdx->is_open()) {
            pfIdx->read((char*)&regIdx, sizeof(regIdx));
            if (!pfIdx->eof()) {
                pf->seekg(regIdx.pos, ios::beg);
                pf->read((char*)&reg, sizeof(reg));
                Edit1->Text = reg.c�digo;
                Edit2->Text = reg.nombre;
                Edit3->Text = reg.direcci�n;
                Edit4->Text = reg.fecha.d�a;
                Edit5->Text = reg.fecha.mes;
                Edit6->Text = reg.fecha.a�o;
                Edit7->Text = reg.tel�fono;

                ComboBox1->Enabled = false;
            }
        }
    } else if (pos == 1) {
        RegIdxNom regIdx;
        Button7->Enabled = true;
        Button8->Enabled = true;
        Button9->Enabled = true;
        pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
        pfIdx = new fstream(nomArchIdxNom.c_str(), ios::in | ios::binary);
        if (pfIdx->is_open()) {
            pfIdx->read((char*)&regIdx, sizeof(regIdx));
            if (!pfIdx->eof()) {
                pf->seekg(regIdx.pos, ios::beg);
                pf->read((char*)&reg, sizeof(reg));
                Edit1->Text = reg.c�digo;
                Edit2->Text = reg.nombre;
                Edit3->Text = reg.direcci�n;
                Edit4->Text = reg.fecha.d�a;
                Edit5->Text = reg.fecha.mes;
                Edit6->Text = reg.fecha.a�o;
                Edit7->Text = reg.tel�fono;

                ComboBox1->Enabled = false;
            }
        }
    } else if (pos == 2) {
        RegIdxFecha regIdx;
        Button7->Enabled = true;
        Button8->Enabled = true;
        Button9->Enabled = true;
        pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
        pfIdx = new fstream(nomArchIdxFecha.c_str(), ios::in | ios::binary);
        if (pfIdx->is_open()) {
            pfIdx->read((char*)&regIdx, sizeof(regIdx));
            if (!pfIdx->eof()) {
                pf->seekg(regIdx.pos, ios::beg);
                pf->read((char*)&reg, sizeof(reg));
                Edit1->Text = reg.c�digo;
                Edit2->Text = reg.nombre;
                Edit3->Text = reg.direcci�n;
                Edit4->Text = reg.fecha.d�a;
                Edit5->Text = reg.fecha.mes;
                Edit6->Text = reg.fecha.a�o;
                Edit7->Text = reg.tel�fono;

                ComboBox1->Enabled = false;
            }
        }
    } else if (pos == 3) {
        RegIdxTelefono regIdx;
        Button7->Enabled = true;
        Button8->Enabled = true;
        Button9->Enabled = true;
        pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
        pfIdx = new fstream(nomArchIdxTelefono.c_str(), ios::in | ios::binary);
        if (pfIdx->is_open()) {
            pfIdx->read((char*)&regIdx, sizeof(regIdx));
            if (!pfIdx->eof()) {
                pf->seekg(regIdx.pos, ios::beg);
                pf->read((char*)&reg, sizeof(reg));
                Edit1->Text = reg.c�digo;
                Edit2->Text = reg.nombre;
                Edit3->Text = reg.direcci�n;
                Edit4->Text = reg.fecha.d�a;
                Edit5->Text = reg.fecha.mes;
                Edit6->Text = reg.fecha.a�o;
                Edit7->Text = reg.tel�fono;

                ComboBox1->Enabled = false;
            }
        }
    } else {
        ShowMessage("Ningun Item seleccionado");
    }
}
//---------------------------------------------------------------------------
// NAVEGAR >>
void __fastcall TForm1::Button8Click(TObject* Sender)
{
    RegAlumno reg;
    byte pos = ComboBox1->ItemIndex;

    if (pos == 0) {
        RegIdxCod regIdx;

        if (!pfIdx->is_open()) {
            return;
        }

        pfIdx->read((char*)&regIdx, sizeof(regIdx));

        if (pfIdx->eof()) {
            pfIdx->close();
            delete pfIdx;
            pfIdx = new fstream(nomArchIdxCod.c_str(), ios::in | ios::binary);
            pfIdx->seekg(0, ios::end);
            Button7->Enabled = true;
            Button8->Enabled = false;
            return;
        }

        pf->seekg(regIdx.pos, ios::beg);
        pf->read((char*)&reg, sizeof(reg));
    } else if (pos == 1) {
        RegIdxNom regIdx;
        if (!pfIdx->is_open()) {
            return;
        }

        pfIdx->read((char*)&regIdx, sizeof(regIdx));

        if (pfIdx->eof()) {
            pfIdx->close();
            delete pfIdx;
            pfIdx = new fstream(nomArchIdxNom.c_str(), ios::in | ios::binary);
            pfIdx->seekg(0, ios::end);
            Button7->Enabled = true;
            Button8->Enabled = false;
            return;
        }

        pf->seekg(regIdx.pos, ios::beg);
        pf->read((char*)&reg, sizeof(reg));

    } else if (pos == 2) {
        RegIdxFecha regIdx;

        if (!pfIdx->is_open()) {
            return;
        }

        pfIdx->read((char*)&regIdx, sizeof(regIdx));

        if (pfIdx->eof()) {
            pfIdx->close();
            delete pfIdx;
            pfIdx = new fstream(nomArchIdxFecha.c_str(), ios::in | ios::binary);
            pfIdx->seekg(0, ios::end);
            Button7->Enabled = true;
            Button8->Enabled = false;
            return;
        }

        pf->seekg(regIdx.pos, ios::beg);
        pf->read((char*)&reg, sizeof(reg));
    } else if (pos == 3) {
        RegIdxTelefono regIdx;

        if (!pfIdx->is_open()) {
            return;
        }

        pfIdx->read((char*)&regIdx, sizeof(regIdx));

        if (pfIdx->eof()) {
            pfIdx->close();
            delete pfIdx;
            pfIdx =
                new fstream(nomArchIdxTelefono.c_str(), ios::in | ios::binary);
            pfIdx->seekg(0, ios::end);
            Button7->Enabled = true;
            Button8->Enabled = false;
            return;
        }

        pf->seekg(regIdx.pos, ios::beg);
        pf->read((char*)&reg, sizeof(reg));
        Button7->Enabled = true;
        Button8->Enabled = true;
    } else {
        ShowMessage("Ningun Item seleccionado");
    }

    Edit1->Text = reg.c�digo;
    Edit2->Text = reg.nombre;
    Edit3->Text = reg.direcci�n;
    Edit4->Text = reg.fecha.d�a;
    Edit5->Text = reg.fecha.mes;
    Edit6->Text = reg.fecha.a�o;
    Edit7->Text = reg.tel�fono;
    Button7->Enabled = true;
    Button8->Enabled = true;
}
//---------------------------------------------------------------------------
// NAVEGAR <<
void __fastcall TForm1::Button7Click(TObject* Sender)
{
    Cardinal p;
    RegAlumno reg;
    byte pos = ComboBox1->ItemIndex;

    if (pos == 0) {
        RegIdxCod regIdx;
        if (!pfIdx->is_open()) {
            return;
        }
        p = pfIdx->tellp();
        if (p <= sizeof(regIdx)) {
            Button7->Enabled = false;
            return;
        }

        pfIdx->seekp(-2 * sizeof(regIdx), ios::cur);
        pfIdx->read((char*)&regIdx, sizeof(regIdx));
        if (!pfIdx->eof()) {
            pf->seekg(regIdx.pos, ios::beg);
            pf->read((char*)&reg, sizeof(reg));
            Edit1->Text = reg.c�digo;
            Edit2->Text = reg.nombre;
            Edit3->Text = reg.direcci�n;
            Edit4->Text = reg.fecha.d�a;
            Edit5->Text = reg.fecha.mes;
            Edit6->Text = reg.fecha.a�o;
            Edit7->Text = reg.tel�fono;
            Button7->Enabled = true;
            Button8->Enabled = true;
        }
    } else if (pos == 1) {
        RegIdxNom regIdx;
        if (!pfIdx->is_open()) {
            return;
        }
        p = pfIdx->tellp();
        if (p <= sizeof(regIdx)) {
            Button7->Enabled = false;
            return;
        }

        pfIdx->seekp(-2 * sizeof(regIdx), ios::cur);
        pfIdx->read((char*)&regIdx, sizeof(regIdx));
        if (!pfIdx->eof()) {
            pf->seekg(regIdx.pos, ios::beg);
            pf->read((char*)&reg, sizeof(reg));
            Edit1->Text = reg.c�digo;
            Edit2->Text = reg.nombre;
            Edit3->Text = reg.direcci�n;
            Edit4->Text = reg.fecha.d�a;
            Edit5->Text = reg.fecha.mes;
            Edit6->Text = reg.fecha.a�o;
            Edit7->Text = reg.tel�fono;
            Button7->Enabled = true;
            Button8->Enabled = true;
        }
    } else if (pos == 2) {
        RegIdxFecha regIdx;
        //RegIdxNom regIdx;
        if (!pfIdx->is_open()) {
            return;
        }
        p = pfIdx->tellp();
        if (p <= sizeof(regIdx)) {
            Button7->Enabled = false;
            return;
        }

        pfIdx->seekp(-2 * sizeof(regIdx), ios::cur);
        pfIdx->read((char*)&regIdx, sizeof(regIdx));
        if (!pfIdx->eof()) {
            pf->seekg(regIdx.pos, ios::beg);
            pf->read((char*)&reg, sizeof(reg));
            Edit1->Text = reg.c�digo;
            Edit2->Text = reg.nombre;
            Edit3->Text = reg.direcci�n;
            Edit4->Text = reg.fecha.d�a;
            Edit5->Text = reg.fecha.mes;
            Edit6->Text = reg.fecha.a�o;
            Edit7->Text = reg.tel�fono;
            Button7->Enabled = true;
            Button8->Enabled = true;
        }
    } else if (pos == 3) {
        RegIdxTelefono regIdx;
        //RegIdxNom regIdx;
        if (!pfIdx->is_open()) {
            return;
        }
        p = pfIdx->tellp();
        if (p <= sizeof(regIdx)) {
            Button7->Enabled = false;
            return;
        }

        pfIdx->seekp(-2 * sizeof(regIdx), ios::cur);
        pfIdx->read((char*)&regIdx, sizeof(regIdx));
        if (!pfIdx->eof()) {
            pf->seekg(regIdx.pos, ios::beg);
            pf->read((char*)&reg, sizeof(reg));
            Edit1->Text = reg.c�digo;
            Edit2->Text = reg.nombre;
            Edit3->Text = reg.direcci�n;
            Edit4->Text = reg.fecha.d�a;
            Edit5->Text = reg.fecha.mes;
            Edit6->Text = reg.fecha.a�o;
            Edit7->Text = reg.tel�fono;
            Button7->Enabled = true;
            Button8->Enabled = true;
        }
    } else {
        ShowMessage("Ningun Item seleccionado");
    }
}
//---------------------------------------------------------------------------
// FIN NAVEGAR
void __fastcall TForm1::Button9Click(TObject* Sender)
{
    pf->close();
    pfIdx->close();
    delete pf;
    delete pfIdx;
    Button7->Enabled = false;
    Button8->Enabled = false;
    Button9->Enabled = false;

    ComboBox1->Enabled = true;
}
//---------------------------------------------------------------------------
// ORDENAR IDX POR (CODIGO)
void __fastcall TForm1::PorCodigo1Click(TObject* Sender)
{
    Cardinal p, i, pm, z;
    RegIdxCod reg, regM;
    bool fin = false;
    fstream f(nomArchIdxCod.c_str(), ios::in | ios::out | ios::binary);
    if (!f.is_open()) {
        f.close();
        return;
    }

    p = 0;
    while (!fin) {
        i = 0;
        pm = p;
        f.seekg(p);
        while (!f.eof()) {
            if (p == f.tellp()) {
                f.read((char*)&reg, sizeof(reg));
                regM = reg;
                z = f.tellp();
            } else {
                f.read((char*)&reg, sizeof(reg));
                z = f.tellp();
            }
            if (!f.eof()) {
                i++;
                if (reg.c�digo < regM.c�digo) {
                    regM = reg;
                    pm = static_cast<std::streamoff>(f.tellg()) -
                         static_cast<std::streamoff>(sizeof(reg));
                }
            }
        }
        fin = i <= 1;
        if (!fin) {
            f.close();
            f.open(nomArchIdxCod.c_str(), ios::in | ios::out | ios::binary);
            f.seekg(p);
            f.seekp(p);
            z = f.tellp();

            if (p != pm) {
                f.read((char*)&reg, sizeof(reg));
                z = f.tellp();
                f.seekp(p);
                z = f.tellp();
                f.write((char*)&regM, sizeof(reg));
                z = f.tellp();
                f.seekp(pm);
                z = f.tellp();
                f.write((char*)&reg, sizeof(reg));
                z = f.tellp();
            }
        }
        p = p + sizeof(reg);
    }

    f.flush();
    f.close();
}
//---------------------------------------------------------------------------
// INDEXAR POR NOMBRE
void __fastcall TForm1::IndexarPorNombre1Click(TObject* Sender)
{
    RegAlumno reg;
    RegIdxNom regIdx;
    pf = new fstream(nomArch.c_str(), ios::binary | ios::in);
    pfIdx = new fstream(nomArchIdxNom.c_str(), ios::binary | ios::out);
    if (pf->fail() || pfIdx->fail()) {
        pf->close();
        pfIdx->close();
        return;
    }

    regIdx.pos = pf->tellg();
    while (pf->read((char*)&reg, sizeof(reg))) {
        strcpy(regIdx.nombre, reg.nombre);
        pfIdx->write((char*)&regIdx, sizeof(regIdx));

        regIdx.pos = pf->tellg();
    }

    pf->close();
    pfIdx->close();
}
//---------------------------------------------------------------------------
// ORDENAR IDX POR (NOMBRE)
void __fastcall TForm1::PorNombre1Click(TObject* Sender)
{
    Cardinal p, i, pm, z;
    RegIdxNom reg, regM;
    bool fin = false;
    fstream f(nomArchIdxNom.c_str(), ios::in | ios::out | ios::binary);
    if (!f.is_open()) {
        f.flush();
        f.close();
    }

    p = 0;
    while (!fin) {
        i = 0;
        pm = p;
        f.seekg(p);
        while (!f.eof()) {
            if (p == f.tellp()) {
                f.read((char*)&reg, sizeof(reg));
                regM = reg;
                z = f.tellp();
            } else {
                f.read((char*)&reg, sizeof(reg));
                z = f.tellp();
            }
            if (!f.eof()) {
                i++;
                // comparar orden alfabetico
                if (std::strcmp(reg.nombre, regM.nombre) < 0) {
                    regM = reg;
                    pm = static_cast<std::streamoff>(f.tellg()) -
                         static_cast<std::streamoff>(sizeof(reg));
                }
            }
        }
        fin = i <= 1;
        if (!fin) {
            f.close();
            f.open(nomArchIdxNom.c_str(), ios::in | ios::out | ios::binary);
            f.seekg(p);
            f.seekp(p);
            z = f.tellp();

            if (p != pm) {
                f.read((char*)&reg, sizeof(reg));
                z = f.tellp();
                f.seekp(p);
                z = f.tellp();
                f.write((char*)&regM, sizeof(reg));
                z = f.tellp();
                f.seekp(pm);
                z = f.tellp();
                f.write((char*)&reg, sizeof(reg));
                z = f.tellp();
            }
        }
        p = p + sizeof(reg);
    }

    f.flush();
    f.close();
}

//---------------------------------------------------------------------------
// pregunta2:
// Hacer un algoritmo para generar un listado.txt (listado.txt) ordenado por mes en forma descendente

void __fastcall TForm1::Button10Click(TObject* Sender)
{
    AnsiString temp = "Alumnos.tmp";

    RegAlumno registroAlumno;

    // copiar archivo1 en archivo 2
    pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
    fstream file2(temp.c_str(), ios::out | ios::binary);

    if (pf->fail() || file2.fail()) {
        pf->close();
        delete pf;
        file2.close();
        return;
    }

    while (pf->read((char*)&registroAlumno, sizeof(registroAlumno))) {
        file2.write((char*)&registroAlumno, sizeof(registroAlumno));
    }
    pf->close();
    delete pf;
    file2.flush();
    file2.close();
    // ----------------------------------------------------------------
    // ORDENAR EL ARCHIVO 2 (temporal)
    Cardinal p, i, pm, z;
    RegAlumno reg1, reg2;
    bool fin = false;
    file2.open(temp.c_str(), ios::in | ios::out | ios::binary);
    if (!file2.is_open()) {
        file2.close();
        remove(temp.c_str());
        return;
    }

    p = 0;
    while (!fin) {
        i = 0;
        pm = p;
        file2.seekg(p);
        while (!file2.eof()) {
            if (p == file2.tellp()) {
                file2.read((char*)&reg1, sizeof(reg1));
                reg2 = reg1;
                z = file2.tellp();
            } else {
                file2.read((char*)&reg1, sizeof(reg1));
                z = file2.tellp();
            }
            if (!file2.eof()) {
                i++;
                if (reg1.fecha.mes > reg2.fecha.mes) {
                    reg2 = reg1;
                    pm = static_cast<std::streamoff>(file2.tellg()) -
                         static_cast<std::streamoff>(sizeof(reg1)); // a?adido
                }
            }
        }
        fin = i <= 1;
        if (!fin) {
            file2.close();
            file2.open(temp.c_str(), ios::in | ios::out | ios::binary);
            file2.seekg(p);
            file2.seekp(p);
            z = file2.tellp();

            if (p != pm) {
                file2.read((char*)&reg1, sizeof(reg1));
                z = file2.tellp();
                file2.seekp(p);
                z = file2.tellp();
                file2.write((char*)&reg2, sizeof(reg1));
                z = file2.tellp();
                file2.seekp(pm);
                z = file2.tellp();
                file2.write((char*)&reg1, sizeof(reg1));
                z = file2.tellp();
            }
        }
        p = p + sizeof(reg1);
    }

    file2.flush();
    file2.close();
    // TERMINANDO DE ORDENAR
    AnsiString listado = filesDirectoryStr + "\\" + "listado.txt";
    fstream fo(listado.c_str(), ios::out);
    file2.open(temp.c_str(), ios::in | ios::binary);
    if (fo.fail() || !file2.is_open()) {
        fo.close();
        file2.close();
        remove(temp.c_str());
    }
    while (file2.read((char*)&registroAlumno, sizeof(registroAlumno))) {
        fo << registroAlumno.c�digo << ',' << registroAlumno.nombre << ','
           << (int)registroAlumno.fecha.d�a << '/'
           << (int)registroAlumno.fecha.mes << '/'
           << (int)registroAlumno.fecha.a�o << '\n';
    }

    file2.close();
    fo.flush();
    fo.close();
    remove(temp.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject* Sender)
{
    RegAlumno reg;
    pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
    Cardinal f = 1;

    if (pf->fail()) {
        pf->close();
        return;
    }

    while (pf->read((char*)&reg, sizeof(reg))) {
        StringGrid1->Cells[0][f] = reg.marca;
        StringGrid1->Cells[1][f] = reg.c�digo;
        StringGrid1->Cells[2][f] = reg.nombre;
        StringGrid1->Cells[3][f] = reg.direcci�n;
        StringGrid1->Cells[4][f] = (AnsiString)reg.fecha.d�a + "/" +
                                   (AnsiString)reg.fecha.mes + "/" +
                                   (AnsiString)reg.fecha.a�o;
        StringGrid1->Cells[5][f] = reg.tel�fono;
        f++;
    }
    StringGrid1->RowCount = f;
    pf->close();
}
//---------------------------------------------------------------------------
// INDEXAR POR FECHA
void __fastcall TForm1::IndexarPorFecha1Click(TObject* Sender)
{
    RegAlumno reg;
    RegIdxFecha regIdx;

    pf = new fstream(nomArch.c_str(), ios::binary | ios::in);
    pfIdx = new fstream(nomArchIdxFecha.c_str(), ios::binary | ios::out);

    if (pf->fail() || pfIdx->fail()) {
        pf->close();
        pfIdx->close();
        return;
    }

    regIdx.pos = pf->tellg();
    while (pf->read((char*)&reg, sizeof(reg))) {
        regIdx.d�a = reg.fecha.d�a;
        regIdx.mes = reg.fecha.mes;
        regIdx.a�o = reg.fecha.a�o;
        pfIdx->write((char*)&regIdx, sizeof(regIdx));
        regIdx.pos = pf->tellg();
    }

    pf->close();
    pfIdx->close();
}
//---------------------------------------------------------------------------
// INDEXAR POR TELEFONO
void __fastcall TForm1::IndexarPorTelefono1Click(TObject* Sender)
{
    // indexar por telefono
    RegAlumno reg;
    RegIdxTelefono regIdx;

    pf = new fstream(nomArch.c_str(), ios::binary | ios::in);
    pfIdx = new fstream(nomArchIdxTelefono.c_str(), ios::binary | ios::out);

    if (pf->fail() || pfIdx->fail()) {
        pf->close();
        pfIdx->close();
        return;
    }

    regIdx.pos = pf->tellg();
    while (pf->read((char*)&reg, sizeof(reg))) {
        regIdx.tel�fono = reg.tel�fono;
        pfIdx->write((char*)&regIdx, sizeof(regIdx));
        regIdx.pos = pf->tellg();
    }

    pf->close();
    pfIdx->close();
}
//---------------------------------------------------------------------------
// ORDENAR IDX POR (FECHA)
void __fastcall TForm1::PorFecha1Click(TObject* Sender)
{
    Cardinal p, i, pm, z;
    RegIdxFecha reg, regM;
    bool fin = false;
    fstream f(nomArchIdxFecha.c_str(), ios::in | ios::out | ios::binary);
    if (!f.is_open()) {
        f.close();
        return;
    }

    p = 0;
    while (!fin) {
        i = 0;
        pm = p;
        f.seekg(p);
        while (!f.eof()) {
            if (p == f.tellp()) {
                f.read((char*)&reg, sizeof(reg));
                regM = reg;
                z = f.tellp();
            } else {
                f.read((char*)&reg, sizeof(reg));
                z = f.tellp();
            }
            if (!f.eof()) {
                i++;
                Cardinal totalRegistro =
                    reg.d�a / 3600 + reg.mes / 12 + reg.a�o;
                Cardinal totalRegistroM =
                    regM.d�a / 3600 + regM.mes / 12 + regM.a�o;
                if (totalRegistro < totalRegistroM) {
                    regM = reg;
                    pm = static_cast<std::streamoff>(f.tellg()) -
                         static_cast<std::streamoff>(sizeof(reg));
                }
            }
        }
        fin = i <= 1;
        if (!fin) {
            f.close();
            f.open(nomArchIdxFecha.c_str(), ios::in | ios::out | ios::binary);
            f.seekg(p);
            f.seekp(p);
            z = f.tellp();

            if (p != pm) {
                f.read((char*)&reg, sizeof(reg));
                z = f.tellp();
                f.seekp(p);
                z = f.tellp();
                f.write((char*)&regM, sizeof(reg));
                z = f.tellp();
                f.seekp(pm);
                z = f.tellp();
                f.write((char*)&reg, sizeof(reg));
                z = f.tellp();
            }
        }
        p = p + sizeof(reg);
    }

    f.flush();
    f.close();
}
//---------------------------------------------------------------------------
// ORDENAR IDX POR (TELEFONO)
void __fastcall TForm1::PorTelefono1Click(TObject* Sender)
{
    //
    Cardinal p, i, pm, z;
    RegIdxTelefono reg, regM;
    bool fin = false;
    fstream f(nomArchIdxTelefono.c_str(), ios::in | ios::out | ios::binary);
    if (!f.is_open()) {
        f.close();
        return;
    }

    p = 0;
    while (!fin) {
        i = 0;
        pm = p;
        f.seekg(p);
        while (!f.eof()) {
            if (p == f.tellp()) {
                f.read((char*)&reg, sizeof(reg));
                regM = reg;
                z = f.tellp();
            } else {
                f.read((char*)&reg, sizeof(reg));
                z = f.tellp();
            }
            if (!f.eof()) {
                i++;
                if (reg.tel�fono < regM.tel�fono) {
                    regM = reg;
                    pm = static_cast<std::streamoff>(f.tellg()) -
                         static_cast<std::streamoff>(sizeof(reg));
                }
            }
        }
        fin = i <= 1;
        if (!fin) {
            f.close();
            f.open(
                nomArchIdxTelefono.c_str(), ios::in | ios::out | ios::binary);
            f.seekg(p);
            f.seekp(p);
            z = f.tellp();

            if (p != pm) {
                f.read((char*)&reg, sizeof(reg));
                z = f.tellp();
                f.seekp(p);
                z = f.tellp();
                f.write((char*)&regM, sizeof(reg));
                z = f.tellp();
                f.seekp(pm);
                z = f.tellp();
                f.write((char*)&reg, sizeof(reg));
                z = f.tellp();
            }
        }
        p = p + sizeof(reg);
    }

    f.flush();
    f.close();
}
//---------------------------------------------------------------------------
// pregunta2:
// Hacer un algoritmo para generar un listado.txt (listado.txt) ordenado por mes en forma descendente

void __fastcall TForm1::Pregunta1Click(TObject* Sender)
{
    AnsiString temp = "Alumnos.tmp";

    RegAlumno registroAlumno;

    // copiar archivo1 en archivo 2
    pf = new fstream(nomArch.c_str(), ios::in | ios::binary);
    fstream file2(temp.c_str(), ios::out | ios::binary);

    if (pf->fail() || file2.fail()) {
        pf->close();
        delete pf;
        file2.close();
        return;
    }

    while (pf->read((char*)&registroAlumno, sizeof(registroAlumno))) {
        file2.write((char*)&registroAlumno, sizeof(registroAlumno));
    }
    pf->close();
    delete pf;
    file2.flush();
    file2.close();
    // ----------------------------------------------------------------
    // ORDENAR EL ARCHIVO 2 (temporal)
    Cardinal p, i, pm, z;
    RegAlumno reg1, reg2;
    bool fin = false;
    file2.open(temp.c_str(), ios::in | ios::out | ios::binary);
    if (!file2.is_open()) {
        file2.close();
        remove(temp.c_str());
        return;
    }

    p = 0;
    while (!fin) {
        i = 0;
        pm = p;
        file2.seekg(p);
        while (!file2.eof()) {
            if (p == file2.tellp()) {
                file2.read((char*)&reg1, sizeof(reg1));
                reg2 = reg1;
                z = file2.tellp();
            } else {
                file2.read((char*)&reg1, sizeof(reg1));
                z = file2.tellp();
            }
            if (!file2.eof()) {
                i++;
                if (reg1.fecha.mes > reg2.fecha.mes) {
                    reg2 = reg1;
                    pm = static_cast<std::streamoff>(file2.tellg()) -
                         static_cast<std::streamoff>(sizeof(reg1)); // a?adido
                }
            }
        }
        fin = i <= 1;
        if (!fin) {
            file2.close();
            file2.open(temp.c_str(), ios::in | ios::out | ios::binary);
            file2.seekg(p);
            file2.seekp(p);
            z = file2.tellp();

            if (p != pm) {
                file2.read((char*)&reg1, sizeof(reg1));
                z = file2.tellp();
                file2.seekp(p);
                z = file2.tellp();
                file2.write((char*)&reg2, sizeof(reg1));
                z = file2.tellp();
                file2.seekp(pm);
                z = file2.tellp();
                file2.write((char*)&reg1, sizeof(reg1));
                z = file2.tellp();
            }
        }
        p = p + sizeof(reg1);
    }

    file2.flush();
    file2.close();
    // TERMINANDO DE ORDENAR
    AnsiString listado = filesDirectoryStr + "\\" + "listado.txt";
    fstream fo(listado.c_str(), ios::out);
    file2.open(temp.c_str(), ios::in | ios::binary);
    if (fo.fail() || !file2.is_open()) {
        fo.close();
        file2.close();
        remove(temp.c_str());
    }
    while (file2.read((char*)&registroAlumno, sizeof(registroAlumno))) {
        fo << registroAlumno.c�digo << ',' << registroAlumno.nombre << ','
           << (int)registroAlumno.fecha.d�a << '/'
           << (int)registroAlumno.fecha.mes << '/'
           << (int)registroAlumno.fecha.a�o << '\n';
    }

    file2.close();
    fo.flush();
    fo.close();
    remove(temp.c_str());
}
//---------------------------------------------------------------------------

