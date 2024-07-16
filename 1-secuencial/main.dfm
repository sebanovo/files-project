object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 386
  ClientWidth = 736
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  TextHeight = 15
  object Edit1: TEdit
    Left = 192
    Top = 96
    Width = 481
    Height = 39
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 192
    Top = 152
    Width = 481
    Height = 39
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 480
    Top = 296
  end
  object MainMenu1: TMainMenu
    Left = 592
    Top = 296
    object Practica1: TMenuItem
      Caption = 'Practica'
      object ContarCaracteres1: TMenuItem
        Caption = 'Contar Caracteres'
        OnClick = ContarCaracteres1Click
      end
      object ContarPalabras1: TMenuItem
        Caption = 'Contar Palabras'
        OnClick = ContarPalabras1Click
      end
      object ContarDigitos1: TMenuItem
        Caption = 'Contar Digitos'
        OnClick = ContarDigitos1Click
      end
      object ContarNumeros1: TMenuItem
        Caption = 'Contar Numeros'
        OnClick = ContarNumeros1Click
      end
      object E11: TMenuItem
        Caption = 'E1'
        OnClick = E11Click
      end
      object E21: TMenuItem
        Caption = 'E2'
        OnClick = E21Click
      end
      object E31: TMenuItem
        Caption = 'E3'
        OnClick = E31Click
      end
      object E41: TMenuItem
        Caption = 'E4'
        OnClick = E41Click
      end
      object E51: TMenuItem
        Caption = 'E5'
        OnClick = E51Click
      end
      object E61: TMenuItem
        Caption = 'E6'
        OnClick = E61Click
      end
      object E71: TMenuItem
        Caption = 'E7'
        OnClick = E71Click
      end
    end
    object Modelos1: TMenuItem
      Caption = 'Modelos'
      object T11: TMenuItem
        Caption = 'T1'
        OnClick = T11Click
      end
      object T21: TMenuItem
        Caption = 'T2'
        OnClick = T21Click
      end
      object T31: TMenuItem
        Caption = 'T3'
        OnClick = T31Click
      end
      object T41: TMenuItem
        Caption = 'T4'
        OnClick = T41Click
      end
    end
  end
end
