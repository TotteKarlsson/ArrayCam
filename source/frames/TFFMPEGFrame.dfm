object FFMPEGFrame: TFFMPEGFrame
  Left = 0
  Top = 0
  Width = 438
  Height = 265
  AutoSize = True
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 438
    Height = 265
    Caption = 'FFMPEG Settings'
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 216
      Width = 63
      Height = 13
      Caption = 'H.264 Preset'
    end
    object FFMPEGLocationE: TSTDStringLabeledEdit
      Left = 24
      Top = 72
      Width = 393
      Height = 21
      EditLabel.Width = 82
      EditLabel.Height = 13
      EditLabel.Caption = 'FFMPEG Location'
      TabOrder = 0
      Text = 'C:\\Program Files (x86)\\ImageMagick-7.0.3-Q8\\ffmpeg.exe'
      Value = 'C:\\Program Files (x86)\\ImageMagick-7.0.3-Q8\\ffmpeg.exe'
    end
    object FFMPEGThreads: TIntegerLabeledEdit
      Left = 24
      Top = 176
      Width = 121
      Height = 21
      EditLabel.Width = 161
      EditLabel.Height = 13
      EditLabel.Caption = 'Threads Employed (0 => optimal)'
      TabOrder = 1
      Text = '0'
    end
    object CRFValue: TIntegerLabeledEdit
      Left = 24
      Top = 128
      Width = 121
      Height = 21
      EditLabel.Width = 82
      EditLabel.Height = 13
      EditLabel.Caption = 'CRF Value (0-51)'
      TabOrder = 2
      Text = '20'
      Value = 20
    end
    object PresetCB: TComboBox
      Left = 24
      Top = 235
      Width = 145
      Height = 21
      ItemIndex = 3
      TabOrder = 3
      Text = 'medium'
      Items.Strings = (
        'ultrafast'
        'veryfast'
        'fast'
        'medium'
        'slower'
        'veryslow')
    end
  end
end
