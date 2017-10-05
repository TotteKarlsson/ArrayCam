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
  end
end
