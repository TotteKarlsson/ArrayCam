object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 652
  ClientWidth = 1208
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
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
        EditLabel.ExplicitLeft = 0
        EditLabel.ExplicitTop = -16
        EditLabel.ExplicitWidth = 85
      end
    end
  end
  object Compress: TArrayBotButton
    Left = 40
    Top = 152
    Width = 137
    Height = 81
    Caption = 'Compress'
    TabOrder = 2
    SoundID = 'BUTTON_CLICK_4'
  end
  object Memo1: TMemo
    Left = 0
    Top = 384
    Width = 1208
    Height = 268
    Align = alBottom
    TabOrder = 3
  end
  object ProgressBar1: TProgressBar
    Left = 40
    Top = 304
    Width = 393
    Height = 25
    TabOrder = 4
  end
end
