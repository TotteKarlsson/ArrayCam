object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Compressor'
  ClientHeight = 861
  ClientWidth = 1503
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object DBText1: TDBText
    Left = 168
    Top = 192
    Width = 65
    Height = 17
    DataField = 'id'
    DataSource = atdbDM.blockIDsDataSource
  end
  object infoMemo: TMemo
    Left = 0
    Top = 705
    Width = 1503
    Height = 156
    Align = alBottom
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 0
    WordWrap = False
  end
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 1503
    Height = 129
    Align = alTop
    TabOrder = 1
    object GroupBox1: TGroupBox
      Left = 1
      Top = 1
      Width = 505
      Height = 127
      Align = alLeft
      Caption = 'Data Folder Selection'
      TabOrder = 0
      object Panel1: TPanel
        Left = 2
        Top = 15
        Width = 501
        Height = 41
        Align = alTop
        TabOrder = 0
        object MovieFolder: TSTDStringEdit
          Left = 9
          Top = 11
          Width = 440
          Height = 21
          TabOrder = 0
          Text = 'P:\videoCompressor\Movies'
          Value = 'P:\videoCompressor\Movies'
        end
        object Button1: TButton
          Left = 455
          Top = 10
          Width = 34
          Height = 25
          Action = BrowseForFolder1
          TabOrder = 1
        end
      end
    end
    inline TATDBConnectionFrame1: TATDBConnectionFrame
      Left = 1029
      Top = 1
      Width = 473
      Height = 127
      Align = alRight
      AutoSize = True
      TabOrder = 1
      ExplicitLeft = 1029
      ExplicitTop = 1
      ExplicitWidth = 473
      ExplicitHeight = 127
      inherited GBox1: TGroupBox
        Width = 473
        ExplicitWidth = 473
        inherited mServerIPE: TSTDStringLabeledEdit
          Text = 'atdb'
          Value = 'atdb'
        end
        inherited mDBUserE: TSTDStringLabeledEdit
          Text = 'atdb'
          Value = 'atdb'
        end
        inherited mATDBServerBtnConnect: TArrayBotButton
          Left = 311
          Top = 46
          ExplicitLeft = 311
          ExplicitTop = 46
        end
        inherited mDatabaseE: TSTDStringLabeledEdit
          Text = 'atdb-live'
          Value = 'atdb-live'
        end
      end
    end
  end
  object Panel2: TGroupBox
    Left = 0
    Top = 129
    Width = 113
    Height = 576
    Align = alLeft
    Caption = 'Block IDs'
    Color = clBtnFace
    ParentColor = False
    TabOrder = 2
    object DBLookupListBox1: TDBLookupListBox
      Left = 2
      Top = 15
      Width = 109
      Height = 550
      Align = alClient
      KeyField = 'id'
      ListField = 'id'
      ListSource = atdbDM.blockIDsDataSource
      TabOrder = 0
    end
  end
  object ShutDownTimer: TTimer
    Enabled = False
    Interval = 50
    OnTimer = ShutDownTimerTimer
    Left = 256
    Top = 136
  end
  object ActionList1: TActionList
    Left = 360
    Top = 120
    object BrowseForFolder1: TBrowseForFolder
      Category = 'File'
      Caption = '...'
      DialogCaption = '...'
      BrowseOptions = [bifBrowseForComputer, bifEditBox, bifNewDialogStyle]
      OnAccept = BrowseForFolder1Accept
    end
  end
end
