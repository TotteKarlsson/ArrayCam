object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Compressor'
  ClientHeight = 652
  ClientWidth = 1208
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
  PixelsPerInch = 96
  TextHeight = 13
  object IntLabel1: TIntLabel
    Left = 224
    Top = 280
    Width = 10
    Height = 13
    Caption = '-1'
    Value = -1
    TheFont.Charset = DEFAULT_CHARSET
    TheFont.Color = clWindowText
    TheFont.Height = -11
    TheFont.Name = 'Tahoma'
    TheFont.Style = []
  end
  object InputFileE: TSTDStringLabeledEdit
    Left = 32
    Top = 64
    Width = 513
    Height = 21
    EditLabel.Width = 45
    EditLabel.Height = 13
    EditLabel.Caption = 'Input File'
    TabOrder = 0
    Text = 
      'P:\\videoCompressor\\Movies\\0_bf55f096-8ced-11e7-82b5-d8cb8abce' +
      '51b.avi'
    Value = 
      'P:\\videoCompressor\\Movies\\0_bf55f096-8ced-11e7-82b5-d8cb8abce' +
      '51b.avi'
  end
  inline TFFMPEGFrame1: TFFMPEGFrame
    Left = 632
    Top = 32
    Width = 438
    Height = 265
    AutoSize = True
    TabOrder = 1
    ExplicitLeft = 632
    ExplicitTop = 32
    inherited GroupBox1: TGroupBox
      inherited FFMPEGLocationE: TSTDStringLabeledEdit
        Text = 'ffmpeg.exe'
        Value = 'ffmpeg.exe'
      end
    end
  end
  object CompressBtn: TArrayBotButton
    Left = 40
    Top = 152
    Width = 137
    Height = 81
    Caption = 'CompressBtn'
    TabOrder = 2
    OnClick = CompressBtnClick
    SoundID = 'BUTTON_CLICK_4'
  end
  object infoMemo: TMemo
    Left = 0
    Top = 384
    Width = 1208
    Height = 268
    Align = alBottom
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 3
    WordWrap = False
  end
  object ProgressBar1: TProgressBar
    Left = 40
    Top = 304
    Width = 393
    Height = 25
    TabOrder = 4
  end
  object ShutDownTimer: TTimer
    Enabled = False
    Interval = 50
    OnTimer = ShutDownTimerTimer
    Left = 256
    Top = 136
  end
end
