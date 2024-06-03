object Form1: TForm1
  Left = 0
  Top = 0
  ActiveControl = MainStringTree
  Caption = #1053#1080#1082#1080#1090#1080#1085' '#1056#1048'-591220'
  ClientHeight = 348
  ClientWidth = 541
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object SearchTimeResultLabel: TLabel
    Left = 463
    Top = 328
    Width = 6
    Height = 15
    Caption = '0'
  end
  object CountResultLabel: TLabel
    Left = 463
    Top = 307
    Width = 6
    Height = 15
    Caption = '0'
  end
  object FileFormatLabel: TLabel
    Left = 382
    Top = 8
    Width = 123
    Height = 15
    Caption = #1048#1089#1082#1086#1084#1086#1077' '#1088#1072#1089#1096#1080#1088#1077#1085#1080#1077
  end
  object SearchTimeLabel: TLabel
    Left = 343
    Top = 328
    Width = 100
    Height = 15
    Caption = #1042#1088#1077#1084#1103' '#1087#1086#1080#1089#1082#1072' ('#1089'): '
  end
  object CountLabel: TLabel
    Left = 343
    Top = 307
    Width = 96
    Height = 15
    Caption = #1053#1072#1081#1076#1077#1085#1086' '#1092#1072#1081#1083#1086#1074':'
  end
  object DetectLabel: TLabel
    Left = 343
    Top = 291
    Width = 23
    Height = 15
    Caption = #1060'C: '
  end
  object DetectResultLabel: TLabel
    Left = 463
    Top = 291
    Width = 83
    Height = 15
    Caption = #1053#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1072
  end
  object DiskNameLabel: TLabel
    Left = 374
    Top = 124
    Width = 58
    Height = 15
    Caption = #1048#1084#1103' '#1076#1080#1089#1082#1072
  end
  object SqlLabel: TLabel
    Left = 374
    Top = 153
    Width = 53
    Height = 15
    Caption = #1055#1091#1090#1100' '#1082' '#1041#1044
  end
  object Panel1: TPanel
    Left = 374
    Top = 29
    Width = 139
    Height = 89
    TabOrder = 7
  end
  object Button3: TButton
    Left = 374
    Top = 215
    Width = 139
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1082' '#1087#1086#1080#1089#1082#1072' '#1092#1072#1081#1083#1086#1074
    TabOrder = 0
    OnClick = Button3Click
  end
  object MainStringTree: TVirtualStringTree
    Left = 16
    Top = 8
    Width = 321
    Height = 335
    ClipboardFormats.Strings = (
      'Plain text'
      'Unicode text')
    DefaultNodeHeight = 19
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    ScrollBarOptions.AlwaysVisible = True
    TabOrder = 1
    OnGetText = MainStringTreeGetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Options = [coAllowClick, coDraggable, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible, coSmartResize, coAllowFocus, coEditable, coStyleColor]
        Position = 0
        Text = #8470' '#1082#1083#1072#1089#1090#1077#1088#1072
        Width = 84
      end
      item
        Options = [coAllowClick, coDraggable, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible, coSmartResize, coAllowFocus, coEditable, coStyleColor]
        Position = 1
        Text = #1055#1077#1088#1074#1099#1077' 10 '#1073#1072#1081#1090
        Width = 216
      end>
  end
  object JpegButton: TRadioButton
    Left = 386
    Top = 89
    Width = 50
    Height = 17
    Caption = 'jpeg'
    TabOrder = 2
  end
  object PdfButton: TRadioButton
    Left = 386
    Top = 43
    Width = 46
    Height = 17
    Caption = 'pdf'
    TabOrder = 3
  end
  object ExeButton: TRadioButton
    Left = 386
    Top = 66
    Width = 46
    Height = 17
    Caption = 'exe'
    TabOrder = 4
  end
  object PngButton: TRadioButton
    Left = 456
    Top = 89
    Width = 57
    Height = 17
    Caption = 'png'
    Checked = True
    TabOrder = 5
    TabStop = True
    WordWrap = True
  end
  object StopButton: TButton
    Left = 375
    Top = 260
    Width = 138
    Height = 25
    Caption = #1054#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1087#1086#1080#1089#1082
    TabOrder = 6
    OnClick = StopButtonClick
  end
  object Edit1: TEdit
    Left = 471
    Top = 124
    Width = 34
    Height = 23
    TabOrder = 8
    Text = '\\.\G:'
  end
  object Edit2: TEdit
    Left = 374
    Top = 174
    Width = 139
    Height = 23
    TabOrder = 9
    Text = '../../FilesFoundDB.sqlite3'
  end
  object DocxButton: TRadioButton
    Left = 456
    Top = 43
    Width = 57
    Height = 17
    Caption = 'docx'
    TabOrder = 10
    WordWrap = True
  end
  object DocButton: TRadioButton
    Left = 456
    Top = 66
    Width = 49
    Height = 17
    Caption = 'doc'
    TabOrder = 11
    WordWrap = True
  end
end
