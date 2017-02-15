object SettingsForm: TSettingsForm
  Left = 0
  Top = 0
  Caption = 'ArrayCam Settings'
  ClientHeight = 814
  ClientWidth = 625
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnHide = FormHide
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 625
    Height = 759
    ActivePage = TabSheet4
    Align = alClient
    TabOrder = 0
    ExplicitHeight = 486
    object TabSheet1: TTabSheet
      Caption = 'Camera'
      ExplicitHeight = 458
      object GroupBox2: TGroupBox
        Left = 9
        Top = 152
        Width = 192
        Height = 64
        Caption = 'Mirror planes'
        TabOrder = 0
        object mVerticalMirrorCB: TPropertyCheckBox
          Left = 10
          Top = 18
          Width = 65
          Height = 17
          Caption = 'Vertical'
          TabOrder = 0
          OnClick = mVerticalMirrorCBClick
        end
        object mHorizontalMirrorCB: TPropertyCheckBox
          Left = 98
          Top = 18
          Width = 65
          Height = 17
          Caption = 'Horizontal'
          TabOrder = 1
          OnClick = mHorizontalMirrorCBClick
        end
      end
      object GroupBox3: TGroupBox
        Left = 9
        Top = 19
        Width = 411
        Height = 118
        Caption = 'Camera Settings'
        TabOrder = 1
        object Label1: TLabel
          Left = 19
          Top = 40
          Width = 94
          Height = 13
          Caption = 'Exposure Time (ms)'
        end
        object mExposureTimeLbl: mtkFloatLabel
          Left = 248
          Top = 64
          Width = 88
          Height = 13
          Caption = 'mExposureTimeLbl'
          Value = -1.000000000000000000
          TheFont.Charset = DEFAULT_CHARSET
          TheFont.Color = clWindowText
          TheFont.Height = -11
          TheFont.Name = 'Tahoma'
          TheFont.Style = []
        end
        object mAutoExposureCB: TPropertyCheckBox
          Left = 19
          Top = 64
          Width = 109
          Height = 17
          Caption = 'Auto'
          TabOrder = 0
          OnClick = AutoParaCBClick
        end
        object mExposureTimeTB: TTrackBar
          Left = 148
          Top = 30
          Width = 260
          Height = 35
          Max = 300
          Min = 10
          Position = 10
          ShowSelRange = False
          TabOrder = 1
          ThumbLength = 35
          TickStyle = tsNone
          OnChange = mExposureTimeTBChange
        end
      end
      object GroupBox6: TGroupBox
        Left = 9
        Top = 232
        Width = 521
        Height = 86
        Caption = 'Folders (raw files)'
        TabOrder = 2
        object mBrowseForImagesFolderBtn: TButton
          Left = 228
          Top = 40
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 0
          OnClick = BrowseForFolder
        end
        object mBrowseForMoviesFolderBtn: TButton
          Left = 483
          Top = 40
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 1
          OnClick = BrowseForFolder
        end
        object mMoviesFolderE: TSTDStringLabeledEdit
          Left = 261
          Top = 44
          Width = 219
          Height = 21
          EditLabel.Width = 66
          EditLabel.Height = 13
          EditLabel.Caption = 'Movies Folder'
          TabOrder = 2
        end
        object mPhotoOutputBaseFolder: TSTDStringLabeledEdit
          Left = 6
          Top = 44
          Width = 219
          Height = 21
          EditLabel.AlignWithMargins = True
          EditLabel.Width = 61
          EditLabel.Height = 13
          EditLabel.Caption = 'Photo Folder'
          TabOrder = 3
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Image'
      ImageIndex = 1
      ExplicitHeight = 458
      object GroupBox4: TGroupBox
        Left = 19
        Top = 19
        Width = 390
        Height = 214
        Caption = 'Master Gain'
        TabOrder = 0
        object mGainLbl: TLabel
          Left = 18
          Top = 46
          Width = 6
          Height = 13
          Caption = '1'
        end
        object Label2: TLabel
          Left = 18
          Top = 27
          Width = 21
          Height = 13
          Caption = 'Gain'
        end
        object Label3: TLabel
          Left = 18
          Top = 147
          Width = 52
          Height = 13
          Caption = 'Black Level'
        end
        object mBlackLevelLbl: TIntLabel
          Left = 126
          Top = 184
          Width = 70
          Height = 13
          Caption = 'mBlackLevelLbl'
          ValueString = '12'
          Value = -1
          TheFont.Charset = DEFAULT_CHARSET
          TheFont.Color = clWindowText
          TheFont.Height = -11
          TheFont.Name = 'Tahoma'
          TheFont.Style = []
        end
        object mAutoGainCB: TPropertyCheckBox
          Left = 18
          Top = 79
          Width = 109
          Height = 17
          Caption = 'Auto'
          TabOrder = 0
          OnClick = AutoParaCBClick
        end
        object mGainTB: TTrackBar
          Left = 117
          Top = 34
          Width = 258
          Height = 47
          Enabled = False
          Max = 100
          ShowSelRange = False
          TabOrder = 1
          ThumbLength = 35
          TickStyle = tsNone
          OnChange = mGainTBChange
        end
        object mBlackLevelTB: TTrackBar
          Left = 117
          Top = 138
          Width = 258
          Height = 47
          Enabled = False
          Max = 100
          ShowSelRange = False
          TabOrder = 2
          ThumbLength = 35
          TickStyle = tsNone
          OnChange = mBlackLevelTBChange
        end
        object mAutoBlackLevelCB: TPropertyCheckBox
          Left = 18
          Top = 166
          Width = 109
          Height = 17
          Caption = 'Auto'
          TabOrder = 3
          OnClick = AutoParaCBClick
        end
        object mGainBoostCB: TCheckBox
          Left = 18
          Top = 102
          Width = 87
          Height = 17
          Caption = 'Gain Boost'
          TabOrder = 4
          OnClick = mGainBoostCBClick
        end
      end
      object Gamma: TGroupBox
        Left = 19
        Top = 608
        Width = 390
        Height = 81
        Caption = 'Gamma'
        TabOrder = 1
        object Label4: TLabel
          Left = 18
          Top = 28
          Width = 82
          Height = 13
          Caption = 'Software Gamma'
        end
        object mSoftwareGammaLbl: mtkFloatLabel
          Left = 18
          Top = 47
          Width = 22
          Height = 13
          Caption = '1.00'
          ValueString = '1.00'
          Value = 1.000000000000000000
          TheFont.Charset = DEFAULT_CHARSET
          TheFont.Color = clWindowText
          TheFont.Height = -11
          TheFont.Name = 'Tahoma'
          TheFont.Style = []
        end
        object mGammaSB: TTrackBar
          Left = 117
          Top = 30
          Width = 260
          Height = 35
          Max = 300
          Min = 10
          Position = 10
          ShowSelRange = False
          TabOrder = 0
          ThumbLength = 35
          TickStyle = tsNone
          OnChange = mGammaSBChange
        end
      end
      object GroupBox5: TGroupBox
        Left = 19
        Top = 239
        Width = 390
        Height = 105
        Caption = 'Color Gain'
        TabOrder = 2
        object mAutoWhiteBalanceCB: TPropertyCheckBox
          Left = 18
          Top = 32
          Width = 109
          Height = 17
          Caption = 'Auto White Balance'
          TabOrder = 0
          OnClick = AutoParaCBClick
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Peripherals'
      ImageIndex = 2
      ExplicitHeight = 458
      object LightIntensitiesGB: TGroupBox
        Left = 3
        Top = 16
        Width = 350
        Height = 137
        Caption = 'Light Intensities'
        TabOrder = 0
        object mCoaxLbl: TLabel
          Left = 151
          Top = 103
          Width = 54
          Height = 13
          Caption = 'Coax (122)'
        end
        object mBackLEDLbl: TLabel
          Left = 151
          Top = 65
          Width = 72
          Height = 13
          Caption = 'Back LED (122)'
        end
        object mFrontLEDLbl: TLabel
          Left = 151
          Top = 26
          Width = 76
          Height = 13
          Caption = 'Front LED (122)'
        end
        object Panel2: TPanel
          Left = 2
          Top = 15
          Width = 143
          Height = 120
          Align = alLeft
          BevelOuter = bvNone
          TabOrder = 0
          object mBackLEDTB: TTrackBar
            Left = 0
            Top = 40
            Width = 143
            Height = 40
            Align = alTop
            Max = 255
            TabOrder = 0
            ThumbLength = 30
            TickStyle = tsNone
            OnChange = SettingsChange
          end
          object mCoaxTB: TTrackBar
            Left = 0
            Top = 80
            Width = 143
            Height = 40
            Align = alTop
            Max = 255
            TabOrder = 1
            ThumbLength = 30
            TickStyle = tsNone
            OnChange = SettingsChange
          end
          object mFrontLEDTB: TTrackBar
            Left = 0
            Top = 0
            Width = 143
            Height = 40
            Align = alTop
            Max = 255
            TabOrder = 2
            ThumbLength = 30
            TickStyle = tsNone
            OnChange = SettingsChange
          end
        end
        object mPairLEDsCB: TPropertyCheckBox
          Left = 248
          Top = 25
          Width = 97
          Height = 17
          Caption = 'Pair F/B LEDs'
          TabOrder = 1
          OnClick = mPairLEDsCBClick
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Connections'
      ImageIndex = 1
      ExplicitHeight = 458
      object GroupBox1: TGroupBox
        Left = 3
        Top = 16
        Width = 273
        Height = 161
        Caption = 'Arduino Client'
        TabOrder = 0
        object mArduinoServerPortE: TIntegerLabeledEdit
          Left = 16
          Top = 56
          Width = 121
          Height = 21
          EditLabel.Width = 63
          EditLabel.Height = 13
          EditLabel.Caption = 'Network Port'
          TabOrder = 0
          Text = '50000'
          Value = 50000
        end
        object mASStartBtn: TButton
          Left = 143
          Top = 40
          Width = 104
          Height = 97
          Caption = 'Start'
          TabOrder = 1
          OnClick = mASStartBtnClick
        end
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 759
    Width = 625
    Height = 55
    Align = alBottom
    TabOrder = 1
    ExplicitTop = 486
    object Button1: TButton
      Left = 512
      Top = 2
      Width = 99
      Height = 45
      Caption = 'Close'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object mUIUpdateTimer: TTimer
    Enabled = False
    Interval = 200
    OnTimer = mUIUpdateTimerTimer
    Left = 368
    Top = 312
  end
end
