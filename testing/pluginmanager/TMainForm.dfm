object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 689
  ClientWidth = 1070
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object TopGB: TGroupBox
    Left = 0
    Top = 282
    Width = 1070
    Height = 224
    Align = alTop
    Caption = 'Plugin Info'
    TabOrder = 0
    object PluginsLB: TListBox
      Left = 2
      Top = 15
      Width = 121
      Height = 207
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
      OnClick = PluginsLBClick
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 506
    Width = 1070
    Height = 183
    Align = alClient
    Caption = 'Panel1'
    TabOrder = 1
    object Memo1: TMemo
      Left = 1
      Top = 1
      Width = 1068
      Height = 181
      Align = alClient
      Lines.Strings = (
        'Memo1')
      ReadOnly = True
      ScrollBars = ssBoth
      TabOrder = 0
    end
  end
  object ControlBar1: TControlBar
    Left = 0
    Top = 0
    Width = 1070
    Height = 56
    Align = alTop
    AutoSize = True
    TabOrder = 2
    object Panel2: TPanel
      Left = 26
      Top = 2
      Width = 255
      Height = 48
      Align = alClient
      TabOrder = 0
      object LoadPluginsBtn: TButton
        Left = 1
        Top = 1
        Width = 113
        Height = 46
        Align = alLeft
        Caption = 'Load Plugins'
        TabOrder = 0
        OnClick = LoadPluginsBtnClick
      end
      object GetPluginsInfoBtn: TButton
        Left = 114
        Top = 1
        Width = 113
        Height = 46
        Align = alLeft
        Caption = 'Get Plugin Info'
        TabOrder = 1
        OnClick = LoadPluginsBtnClick
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 241
    Width = 1070
    Height = 41
    Align = alTop
    TabOrder = 3
    object ExecuteBtn: TButton
      Left = 16
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Execute'
      Enabled = False
      TabOrder = 0
      OnClick = ExecuteBtnClick
    end
  end
  object PythonGB: TGroupBox
    Left = 0
    Top = 56
    Width = 1070
    Height = 185
    Align = alTop
    Caption = 'Plugin Info'
    TabOrder = 4
    object PythonPluginsLB: TListBox
      Left = 2
      Top = 15
      Width = 121
      Height = 168
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
      OnClick = PythonPluginsLBClick
    end
  end
  object LogFileReader1: TLogFileReader
    ReadFromStart = True
    LogFileMemo = Memo1
    Left = 248
    Top = 104
  end
  object ShutDownTimer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = ShutDownTimerTimer
    Left = 584
    Top = 104
  end
  object PluginManager1: TPluginManager
    Left = 248
    Top = 184
  end
end
