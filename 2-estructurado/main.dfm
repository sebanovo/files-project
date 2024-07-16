object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 534
  ClientWidth = 875
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 152
    Top = 3
    Width = 120
    Height = 16
    Caption = 'ABM Alumnos.dat'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 152
    Top = 25
    Width = 186
    Height = 24
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TextHint = 'C'#243'digo'
    OnExit = Edit1Exit
  end
  object Edit2: TEdit
    Left = 152
    Top = 55
    Width = 186
    Height = 24
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    MaxLength = 30
    ParentFont = False
    TabOrder = 1
    TextHint = 'Nombre'
  end
  object Edit3: TEdit
    Left = 152
    Top = 85
    Width = 186
    Height = 24
    Hint = 'asdfasdfasd'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    MaxLength = 25
    ParentFont = False
    TabOrder = 2
    TextHint = 'Direcci'#243'n'
  end
  object Edit4: TEdit
    Left = 152
    Top = 115
    Width = 58
    Height = 24
    Hint = 'D'#237'a'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    TextHint = 'D'#237'a'
  end
  object Edit5: TEdit
    Left = 216
    Top = 115
    Width = 49
    Height = 24
    Hint = 'Mes'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
    TextHint = 'Mes'
  end
  object Edit6: TEdit
    Left = 271
    Top = 115
    Width = 67
    Height = 24
    Hint = 'A'#241'o'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
    TextHint = 'A'#241'o'
  end
  object Button1: TButton
    Left = 152
    Top = 183
    Width = 81
    Height = 27
    Cursor = crHandPoint
    Caption = 'Grabar'
    DoubleBuffered = False
    DragCursor = crDefault
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 7
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 239
    Top = 183
    Width = 81
    Height = 27
    Cursor = crHandPoint
    Caption = 'Eliminar'
    DoubleBuffered = False
    DragCursor = crDefault
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 8
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 326
    Top = 183
    Width = 81
    Height = 27
    Cursor = crHandPoint
    Caption = 'Limpiar'
    DoubleBuffered = False
    DragCursor = crDefault
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 9
    OnClick = Button3Click
  end
  object Edit7: TEdit
    Left = 152
    Top = 145
    Width = 186
    Height = 24
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    MaxLength = 25
    ParentFont = False
    TabOrder = 6
    TextHint = '+591 '
  end
  object Button6: TButton
    Left = 395
    Top = 55
    Width = 99
    Height = 25
    Cursor = crHandPoint
    Caption = 'Navegar Idx'
    DragCursor = crHandPoint
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 395
    Top = 86
    Width = 43
    Height = 25
    Cursor = crHandPoint
    Caption = '<<'
    DragCursor = crHandPoint
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 444
    Top = 86
    Width = 50
    Height = 25
    Cursor = crHandPoint
    Caption = '>>'
    DragCursor = crHandPoint
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 395
    Top = 117
    Width = 99
    Height = 25
    Cursor = crHandPoint
    Caption = 'Fin'
    DragCursor = crHandPoint
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = Button9Click
  end
  object ComboBox1: TComboBox
    Left = 395
    Top = 26
    Width = 99
    Height = 23
    Style = csDropDownList
    DragCursor = crDefault
    ItemIndex = 0
    TabOrder = 14
    Text = 'C'#243'digo'
    Items.Strings = (
      'C'#243'digo'
      'Nombre'
      'Fecha'
      'Telef'#243'no')
  end
  object Button11: TButton
    Left = 413
    Top = 183
    Width = 81
    Height = 27
    Caption = 'Mostrar'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cascadia Code'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = Button11Click
  end
  object StringGrid1: TStringGrid
    Left = 152
    Top = 230
    Width = 609
    Height = 262
    ColCount = 6
    DefaultColWidth = 100
    DrawingStyle = gdsClassic
    FixedCols = 0
    RowCount = 2
    GradientEndColor = clTeal
    ScrollBars = ssVertical
    TabOrder = 16
  end
  object MainMenu1: TMainMenu
    Left = 32
    Top = 24
    object Archivo1: TMenuItem
      Caption = 'Archivo'
      object IndexarPorCodigo1: TMenuItem
        Caption = 'Indexar Por C'#243'digo'
        OnClick = IndexarPorCodigo1Click
      end
      object IndexarPorNombre1: TMenuItem
        Caption = 'Indexar Por Nombre'
        OnClick = IndexarPorNombre1Click
      end
      object IndexarPorFecha1: TMenuItem
        Caption = 'Indexar Por Fecha'
        OnClick = IndexarPorFecha1Click
      end
      object IndexarPorTelefono1: TMenuItem
        Caption = 'Indexar Por Telef'#243'no'
        OnClick = IndexarPorTelefono1Click
      end
    end
    object Ordenamiento1: TMenuItem
      Caption = 'Ordenamiento'
      object PorCodigo1: TMenuItem
        Caption = 'Por Codigo'
        OnClick = PorCodigo1Click
      end
      object PorNombre1: TMenuItem
        Caption = 'Por Nombre'
        OnClick = PorNombre1Click
      end
      object PorFecha1: TMenuItem
        Caption = 'Por Fecha'
        OnClick = PorFecha1Click
      end
      object PorTelefono1: TMenuItem
        Caption = 'Por Telefono'
        OnClick = PorTelefono1Click
      end
    end
    object Modelos1: TMenuItem
      Caption = 'Modelos'
      object Pregunta1: TMenuItem
        Caption = 'Pregunta1'
        OnClick = Pregunta1Click
      end
    end
  end
end
