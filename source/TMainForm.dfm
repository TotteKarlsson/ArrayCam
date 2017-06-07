object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Array Cam 0.5'
  ClientHeight = 900
  ClientWidth = 1242
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDefault
  ShowHint = True
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 19
  object Splitter2: TSplitter
    Left = 421
    Top = 0
    Height = 900
    Align = alRight
    ExplicitLeft = 1015
    ExplicitTop = 52
    ExplicitHeight = 814
  end
  object MainContentPanel: TPanel
    Left = 424
    Top = 0
    Width = 818
    Height = 900
    Align = alRight
    Caption = 'MainContentPanel'
    Constraints.MinWidth = 786
    TabOrder = 0
    object MainTopPanel: TPanel
      Left = 1
      Top = 1
      Width = 816
      Height = 146
      Align = alTop
      AutoSize = True
      TabOrder = 0
      object HandwheelGB: TGroupBox
        Left = 1
        Top = 1
        Width = 669
        Height = 144
        Align = alClient
        Caption = 'UC7 Control'
        TabOrder = 0
        object mHWPosShape: TShape
          Left = 21
          Top = 43
          Width = 65
          Height = 8
          Brush.Color = clBlue
          Pen.Style = psClear
        end
        object mRetractLbl: TLabel
          Left = 21
          Top = 20
          Width = 89
          Height = 25
          Caption = 'Retracting'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Segoe UI Semibold'
          Font.Style = []
          ParentFont = False
        end
        object mCuttingLbl: TLabel
          Left = 287
          Top = 20
          Width = 64
          Height = 25
          Caption = 'Cutting'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Segoe UI Semibold'
          Font.Style = []
          ParentFont = False
        end
        object mAfterCuttingLbl: TLabel
          Left = 391
          Top = 20
          Width = 113
          Height = 25
          Caption = 'After Cutting'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Segoe UI Semibold'
          Font.Style = []
          ParentFont = False
        end
        object mBeforeCuttingLbl: TLabel
          Left = 135
          Top = 20
          Width = 125
          Height = 25
          Caption = 'Before Cutting'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Segoe UI Semibold'
          Font.Style = []
          ParentFont = False
        end
        object Panel6: TPanel
          Left = 2
          Top = 56
          Width = 665
          Height = 86
          Align = alBottom
          TabOrder = 0
          object CounterGB: TGroupBox
            Left = 1
            Top = 1
            Width = 663
            Height = 84
            Align = alClient
            TabOrder = 0
            object mSectionCounterLabel: TIntLabel
              Left = 91
              Top = 33
              Width = 16
              Height = 35
              Caption = '1'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -29
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              Value = 1
              TheFont.Charset = DEFAULT_CHARSET
              TheFont.Color = clWindowText
              TheFont.Height = -29
              TheFont.Name = 'Tahoma'
              TheFont.Style = []
            end
            object mRibbonOrderCountLabel: TIntLabel
              Left = 261
              Top = 33
              Width = 16
              Height = 35
              Caption = '1'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -29
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              OnClick = mRibbonOrderCountLabelClick
              Value = 1
              TheFont.Charset = DEFAULT_CHARSET
              TheFont.Color = clWindowText
              TheFont.Height = -29
              TheFont.Name = 'Tahoma'
              TheFont.Style = []
            end
            object Label6: TLabel
              Left = 239
              Top = 7
              Width = 96
              Height = 19
              Caption = 'Ribbon Order'
            end
            object mCountToE: TIntegerLabeledEdit
              Left = 14
              Top = 37
              Width = 65
              Height = 31
              EditLabel.Width = 66
              EditLabel.Height = 19
              EditLabel.Caption = 'Count To'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -19
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              Text = '0'
            end
            object mResetCounterBtn: TArrayBotButton
              Left = 165
              Top = 32
              Width = 68
              Height = 36
              Caption = 'Reset'
              Enabled = False
              ParentDoubleBuffered = True
              TabOrder = 1
              OnClick = mResetCounterBtnClick
              SoundID = 'BUTTON_CLICK_4'
            end
            object mResetRibbonOrderBtn: TArrayBotButton
              Left = 308
              Top = 32
              Width = 68
              Height = 36
              Caption = 'Reset'
              Enabled = False
              ParentDoubleBuffered = True
              TabOrder = 2
              OnClick = mResetCounterBtnClick
              SoundID = 'BUTTON_CLICK_4'
            end
            object mRibbonCreatorActiveCB: TPropertyCheckBox
              Left = 390
              Top = 35
              Width = 280
              Height = 26
              Caption = 'Ribbon Creator On/Off'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -21
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 3
              WordWrap = True
              OnClick = mRibbonCreatorActiveCBClick
            end
          end
        end
      end
      object Panel2: TPanel
        Left = 670
        Top = 1
        Width = 145
        Height = 144
        Align = alRight
        TabOrder = 1
        object GroupBox5: TGroupBox
          Left = 1
          Top = 71
          Width = 143
          Height = 70
          Align = alTop
          Caption = 'Temperature (C)'
          TabOrder = 0
          object mTemperatureLbl: mtkFloatLabel
            Left = 32
            Top = 23
            Width = 43
            Height = 23
            Caption = '-1.00'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            ValueString = '-1.00'
            Value = -1.000000000000000000
            TheFont.Charset = DEFAULT_CHARSET
            TheFont.Color = clWindowText
            TheFont.Height = -19
            TheFont.Name = 'Tahoma'
            TheFont.Style = []
          end
        end
        object GroupBox6: TGroupBox
          Left = 1
          Top = 1
          Width = 143
          Height = 70
          Align = alTop
          Caption = 'Rel. Humidity (%)'
          TabOrder = 1
          object mHumidityE: mtkFloatLabel
            Left = 32
            Top = 23
            Width = 43
            Height = 23
            Caption = '-1.00'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            ValueString = '-1.00'
            Value = -1.000000000000000000
            TheFont.Charset = DEFAULT_CHARSET
            TheFont.Color = clWindowText
            TheFont.Height = -19
            TheFont.Name = 'Tahoma'
            TheFont.Style = []
          end
        end
      end
    end
    object Panel1: TPanel
      Left = 1
      Top = 147
      Width = 816
      Height = 752
      Align = alClient
      Caption = 'Panel1'
      TabOrder = 1
      object PageControl1: TPageControl
        Left = 1
        Top = 1
        Width = 814
        Height = 750
        ActivePage = TabSheet1
        Align = alClient
        MultiLine = True
        TabOrder = 0
        OnChange = PageControl1Change
        object Main: TTabSheet
          Caption = 'Main'
          ImageIndex = 5
          object ScrollBox1: TScrollBox
            Left = 0
            Top = 0
            Width = 806
            Height = 716
            Align = alClient
            TabOrder = 0
            object Panel9: TPanel
              Left = 0
              Top = 0
              Width = 802
              Height = 712
              Align = alClient
              TabOrder = 0
              object BlocksGB: TGroupBox
                Left = 1
                Top = 446
                Width = 800
                Height = 265
                Align = alBottom
                Caption = 'Ribbon  Registration'
                TabOrder = 0
                object GroupBox9: TGroupBox
                  Left = 2
                  Top = 132
                  Width = 796
                  Height = 131
                  Align = alBottom
                  Caption = 'Current Block Info'
                  TabOrder = 0
                  object DBText3: TDBText
                    Left = 133
                    Top = 40
                    Width = 170
                    Height = 17
                    DataField = 'user_name'
                    DataSource = atdbDM.usersDataSource
                  end
                  object DBText4: TDBText
                    Left = 133
                    Top = 96
                    Width = 170
                    Height = 17
                    DataField = 'process_id'
                    DataSource = atdbDM.specimenDataSource
                  end
                  object DBText5: TDBText
                    Left = 341
                    Top = 69
                    Width = 170
                    Height = 17
                    DataField = 'specimen_id'
                    DataSource = atdbDM.specimenDataSource
                  end
                  object DBText6: TDBText
                    Left = 341
                    Top = 97
                    Width = 170
                    Height = 17
                    DataField = 'additional_identifier'
                    DataSource = atdbDM.specimenDataSource
                  end
                  object DBText7: TDBText
                    Left = 133
                    Top = 68
                    Width = 170
                    Height = 17
                    DataField = 'id'
                    DataSource = atdbDM.blocksDataSource
                  end
                  object Label10: TLabel
                    Left = 220
                    Top = 95
                    Width = 100
                    Height = 19
                    Caption = 'Additional ID:'
                  end
                  object Label11: TLabel
                    Left = 12
                    Top = 67
                    Width = 65
                    Height = 19
                    Caption = 'Block ID:'
                  end
                  object Label7: TLabel
                    Left = 12
                    Top = 40
                    Width = 38
                    Height = 19
                    Caption = 'User:'
                  end
                  object Label8: TLabel
                    Left = 12
                    Top = 95
                    Width = 81
                    Height = 19
                    Caption = 'Process ID:'
                  end
                  object Label9: TLabel
                    Left = 220
                    Top = 67
                    Width = 96
                    Height = 19
                    Caption = 'Specimen ID:'
                  end
                  object mBCLabel: TLabel
                    AlignWithMargins = True
                    Left = 405
                    Top = 24
                    Width = 131
                    Height = 39
                    Alignment = taCenter
                    Caption = 'Barcode'
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clRed
                    Font.Height = -32
                    Font.Name = 'Tahoma'
                    Font.Style = [fsBold]
                    ParentFont = False
                    Layout = tlCenter
                  end
                  object GroupBox10: TGroupBox
                    Left = 609
                    Top = 21
                    Width = 185
                    Height = 108
                    Align = alRight
                    Caption = 'Block Note'
                    TabOrder = 0
                    object DBMemo2: TDBMemo
                      Left = 2
                      Top = 21
                      Width = 181
                      Height = 85
                      Align = alClient
                      DataField = 'note'
                      DataSource = atdbDM.blockNotesDSource
                      ReadOnly = True
                      TabOrder = 0
                    end
                  end
                end
                object mDecodeSessionBtn: TButton
                  Left = 25
                  Top = 37
                  Width = 143
                  Height = 84
                  Caption = 'Scan Barcode'
                  TabOrder = 1
                  OnClick = mBtnClick
                end
                object mRegisterRibbonBtn: TArrayBotButton
                  Left = 336
                  Top = 37
                  Width = 143
                  Height = 82
                  Caption = 'Register Ribbon'
                  ParentDoubleBuffered = True
                  TabOrder = 2
                  OnClick = mRegisterRibbonBtnClick
                  SoundID = 'BUTTON_CLICK_4'
                end
              end
              object CuttingGB: TGroupBox
                Left = 1
                Top = 1
                Width = 800
                Height = 130
                Align = alTop
                Caption = 'Feed'
                TabOrder = 1
                object mSetZeroCutBtn: TArrayBotButton
                  Left = 134
                  Top = 58
                  Width = 104
                  Height = 50
                  Caption = 'Set zero-cut'
                  Enabled = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -16
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  OnClick = CreateUC7Message
                  SoundID = 'BUTTON_CLICK_4'
                end
                object mFeedRateE: TIntegerLabeledEdit
                  Left = 28
                  Top = 61
                  Width = 100
                  Height = 47
                  EditLabel.Width = 100
                  EditLabel.Height = 19
                  EditLabel.Caption = 'Feed (nm/cut)'
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -32
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  Text = '0'
                  OnKeyDown = uc7EditKeyDown
                end
                object mZeroCutsE: TIntegerLabeledEdit
                  Left = 616
                  Top = 61
                  Width = 169
                  Height = 47
                  EditLabel.Width = 171
                  EditLabel.Height = 19
                  EditLabel.Caption = 'Zero cuts before backoff'
                  EditLabel.Font.Charset = DEFAULT_CHARSET
                  EditLabel.Font.Color = clWindowText
                  EditLabel.Font.Height = -16
                  EditLabel.Font.Name = 'Tahoma'
                  EditLabel.Font.Style = []
                  EditLabel.ParentFont = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -32
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  Text = '0'
                  OnKeyDown = uc7EditKeyDown
                end
                object mPresetFeedRateE: TIntegerLabeledEdit
                  Left = 276
                  Top = 61
                  Width = 146
                  Height = 47
                  EditLabel.Width = 148
                  EditLabel.Height = 19
                  EditLabel.Caption = 'Preset Feed (nm/cut)'
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -32
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 3
                  Text = '0'
                  OnKeyDown = uc7EditKeyDown
                end
                object SetPresetFeedBtn: TArrayBotButton
                  Left = 428
                  Top = 58
                  Width = 120
                  Height = 50
                  Caption = 'Set Preset Feed'
                  Enabled = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -16
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 4
                  OnClick = CreateUC7Message
                  SoundID = 'BUTTON_CLICK_4'
                end
              end
              object UC7OperationGB: TGroupBox
                Left = 1
                Top = 345
                Width = 800
                Height = 101
                Align = alClient
                Caption = 'Operation'
                Constraints.MinHeight = 101
                TabOrder = 2
                object GroupBox11: TGroupBox
                  Left = 2
                  Top = 21
                  Width = 183
                  Height = 78
                  Align = alLeft
                  Caption = 'Cutter'
                  TabOrder = 0
                  object mStartStopBtn: TArrayBotButton
                    Left = 16
                    Top = 47
                    Width = 150
                    Height = 90
                    Caption = 'Start'
                    Enabled = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -21
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentDoubleBuffered = True
                    ParentFont = False
                    TabOrder = 0
                    OnClick = CreateUC7Message
                    SoundID = 'BUTTON_CLICK_4'
                  end
                end
                object GroupBox12: TGroupBox
                  AlignWithMargins = True
                  Left = 195
                  Top = 24
                  Width = 600
                  Height = 72
                  Margins.Left = 10
                  Align = alClient
                  Caption = 'Knife Stage'
                  TabOrder = 1
                  object mMoveNorthBtn: TArrayBotButton
                    Left = 475
                    Top = 24
                    Width = 100
                    Height = 60
                    Caption = 'Move North'
                    Enabled = False
                    ParentDoubleBuffered = True
                    TabOrder = 0
                    OnClick = CreateUC7Message
                    SoundID = 'BUTTON_CLICK_4'
                  end
                  object mMoveSouthBtn: TArrayBotButton
                    Left = 475
                    Top = 88
                    Width = 100
                    Height = 60
                    Caption = 'Move South'
                    Enabled = False
                    ParentDoubleBuffered = True
                    TabOrder = 1
                    OnClick = CreateUC7Message
                    SoundID = 'BUTTON_CLICK_4'
                  end
                  object StopKnifeStageMotionBtn: TArrayBotButton
                    Left = 378
                    Top = 24
                    Width = 91
                    Height = 60
                    Caption = 'Stop'
                    Enabled = False
                    ParentDoubleBuffered = True
                    TabOrder = 2
                    OnClick = CreateUC7Message
                    SoundID = 'BUTTON_CLICK_4'
                  end
                  object mRibbonStartBtn: TArrayBotButton
                    Left = 6
                    Top = 44
                    Width = 267
                    Height = 90
                    Caption = 'Resume Cutting'
                    Enabled = False
                    Font.Charset = DEFAULT_CHARSET
                    Font.Color = clWindowText
                    Font.Height = -21
                    Font.Name = 'Tahoma'
                    Font.Style = []
                    ParentDoubleBuffered = True
                    ParentFont = False
                    TabOrder = 3
                    OnClick = CreateUC7Message
                    SoundID = 'BUTTON_CLICK_4'
                  end
                end
              end
              object KnifeStageGB: TGroupBox
                Left = 1
                Top = 131
                Width = 800
                Height = 214
                Align = alTop
                Caption = 'Knife Stage'
                TabOrder = 3
                inline MaxStagePosFrame: TUC7StagePositionFrame
                  Left = 13
                  Top = 116
                  Width = 257
                  Height = 81
                  AutoSize = True
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  ExplicitLeft = 13
                  ExplicitTop = 116
                  inherited GroupBox1: TGroupBox
                    Caption = 'Max Knife Position'
                    inherited ValueMM: TIntegerEdit
                      OnKeyDown = MaxKnifePosKeyDown
                    end
                    inherited Valuenm: TIntegerEdit
                      OnKeyDown = MaxKnifePosKeyDown
                    end
                    inherited Valueum: TIntegerEdit
                      OnKeyDown = MaxKnifePosKeyDown
                    end
                  end
                end
                object PopulateMaxNorthPosBtn: TArrayBotButton
                  Left = 276
                  Top = 103
                  Width = 29
                  Height = 28
                  Caption = 'v'
                  TabOrder = 1
                  OnClick = PopulateMaxNorthPosBtnClick
                  SoundID = 'BUTTON_CLICK_4'
                end
                inline CurrentStagePosFrame: TUC7StagePositionFrame
                  Left = 13
                  Top = 24
                  Width = 257
                  Height = 81
                  AutoSize = True
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 2
                  ExplicitLeft = 13
                  ExplicitTop = 24
                  inherited GroupBox1: TGroupBox
                    Caption = 'Current Knife Position'
                    inherited ValueMM: TIntegerEdit
                      OnKeyDown = KnifePosChange
                    end
                    inherited Valuenm: TIntegerEdit
                      OnKeyDown = KnifePosChange
                    end
                    inherited Valueum: TIntegerEdit
                      OnKeyDown = KnifePosChange
                    end
                  end
                end
                inline BackOffStepFrame: TUC7StagePositionFrame
                  Left = 368
                  Top = 24
                  Width = 257
                  Height = 81
                  AutoSize = True
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 3
                  ExplicitLeft = 368
                  ExplicitTop = 24
                  inherited GroupBox1: TGroupBox
                    Caption = 'Backoff Step'
                    inherited ValueMM: TIntegerEdit
                      OnKeyDown = BackOffStepFrameKeyDown
                    end
                    inherited Valuenm: TIntegerEdit
                      OnKeyDown = BackOffStepFrameKeyDown
                    end
                    inherited Valueum: TIntegerEdit
                      OnKeyDown = BackOffStepFrameKeyDown
                    end
                  end
                end
                inline ResumeDeltaDistanceFrame: TUC7StagePositionFrame
                  Left = 368
                  Top = 116
                  Width = 257
                  Height = 81
                  AutoSize = True
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 4
                  ExplicitLeft = 368
                  ExplicitTop = 116
                  inherited GroupBox1: TGroupBox
                    Caption = 'Resume Delta Distance'
                    inherited Label1: TLabel
                      Visible = False
                    end
                    inherited ValueMM: TIntegerEdit
                      Enabled = False
                      Text = '0'
                      OnKeyDown = ResumeDeltaDistanceOnKey
                      Value = 0
                    end
                    inherited Valuenm: TIntegerEdit
                      OnKeyDown = ResumeDeltaDistanceOnKey
                    end
                    inherited Valueum: TIntegerEdit
                      OnKeyDown = ResumeDeltaDistanceOnKey
                    end
                  end
                end
              end
            end
          end
        end
        object TabSheet8: TTabSheet
          Caption = 'Leica UC7'
          ImageIndex = 5
          object UC7GB: TGroupBox
            Left = 0
            Top = 0
            Width = 806
            Height = 716
            Align = alClient
            Caption = 'UC7'
            TabOrder = 0
            object GroupBox4: TGroupBox
              Left = 2
              Top = 203
              Width = 802
              Height = 198
              Align = alTop
              Caption = 'Misc parameters'
              TabOrder = 0
              object mStageMoveDelayE: TIntegerLabeledEdit
                Left = 15
                Top = 104
                Width = 151
                Height = 27
                EditLabel.Width = 156
                EditLabel.Height = 19
                EditLabel.Caption = 'StageMove delay (ms)'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                Text = '50'
                OnKeyDown = uc7EditKeyDown
                Value = 50
              end
            end
            object mTopPanel: TPanel
              Left = 2
              Top = 21
              Width = 802
              Height = 41
              Align = alTop
              BevelOuter = bvNone
              TabOrder = 1
              object mUC7ComportCB: TComboBox
                Left = 8
                Top = 4
                Width = 145
                Height = 27
                ItemIndex = 0
                TabOrder = 0
                Text = 'COM1'
                Items.Strings = (
                  'COM1'
                  'COM2'
                  'COM3'
                  'COM4'
                  'COM5'
                  'COM6'
                  'COM7'
                  'COM8'
                  'COM9'
                  'COM10'
                  'COM11'
                  'COM12'
                  'COM13'
                  'COM14'
                  'COM15'
                  'COM16'
                  'COM17'
                  'COM18'
                  'COM19'
                  'COM20')
              end
              object mConnectUC7Btn: TButton
                Left = 159
                Top = 2
                Width = 67
                Height = 33
                Caption = 'Open'
                TabOrder = 1
                OnClick = mConnectUC7BtnClick
              end
              object mSynchUIBtn: TArrayBotButton
                Left = 232
                Top = 2
                Width = 129
                Height = 33
                Caption = 'Refresh Status'
                ParentDoubleBuffered = True
                TabOrder = 2
                OnClick = mSynchUIBtnClick
                SoundID = 'BUTTON_CLICK_4'
              end
            end
            object NorthSouthGB: TGroupBox
              Left = 2
              Top = 62
              Width = 802
              Height = 141
              Align = alTop
              Caption = 'North-South Knife Stage Position (0-100 000)'
              TabOrder = 2
            end
          end
        end
        object TabSheet2: TTabSheet
          Caption = 'ATDB'
          ImageIndex = 6
          object atdbGB: TGroupBox
            Left = 0
            Top = 0
            Width = 806
            Height = 716
            Align = alClient
            Caption = 'ATDB'
            TabOrder = 0
            inline TATDBConnectionFrame1: TATDBConnectionFrame
              Left = 2
              Top = 21
              Width = 802
              Height = 201
              Align = alTop
              AutoSize = True
              TabOrder = 0
              ExplicitLeft = 2
              ExplicitTop = 21
              ExplicitWidth = 802
              inherited GroupBox1: TGroupBox
                Left = 13
                Caption = 'Connection'
                ExplicitLeft = 13
                inherited mServerIPE: TSTDStringLabeledEdit
                  Height = 27
                  EditLabel.Width = 65
                  EditLabel.Height = 19
                  EditLabel.ExplicitLeft = 16
                  EditLabel.ExplicitTop = 18
                  EditLabel.ExplicitWidth = 65
                  EditLabel.ExplicitHeight = 19
                  ExplicitHeight = 27
                end
                inherited mDBUserE: TSTDStringLabeledEdit
                  Height = 27
                  EditLabel.Width = 32
                  EditLabel.Height = 19
                  EditLabel.ExplicitLeft = 16
                  EditLabel.ExplicitTop = 67
                  EditLabel.ExplicitWidth = 32
                  EditLabel.ExplicitHeight = 19
                  ExplicitHeight = 27
                end
                inherited mPasswordE: TSTDStringLabeledEdit
                  Height = 27
                  EditLabel.Width = 67
                  EditLabel.Height = 19
                  EditLabel.ExplicitLeft = 146
                  EditLabel.ExplicitTop = 67
                  EditLabel.ExplicitWidth = 67
                  EditLabel.ExplicitHeight = 19
                  ExplicitHeight = 27
                end
                inherited mATDBServerBtnConnect: TArrayBotButton
                  Left = 16
                  Top = 122
                  Width = 249
                  ExplicitLeft = 16
                  ExplicitTop = 122
                  ExplicitWidth = 249
                end
                inherited mDatabaseE: TSTDStringLabeledEdit
                  Height = 27
                  EditLabel.Width = 64
                  EditLabel.Height = 19
                  EditLabel.ExplicitLeft = 146
                  EditLabel.ExplicitTop = 18
                  EditLabel.ExplicitWidth = 64
                  EditLabel.ExplicitHeight = 19
                  ExplicitHeight = 27
                end
              end
            end
            object BlockSelectionGB: TGroupBox
              Left = 2
              Top = 222
              Width = 802
              Height = 211
              Align = alTop
              Caption = 'DB/Block Selection'
              TabOrder = 1
              object Panel7: TPanel
                Left = 2
                Top = 21
                Width = 335
                Height = 188
                Align = alLeft
                BevelOuter = bvNone
                TabOrder = 0
                object DBText1: TDBText
                  Left = 128
                  Top = 159
                  Width = 170
                  Height = 17
                  DataField = 'additional_identifier'
                  DataSource = atdbDM.specimenDataSource
                end
                object DBText2: TDBText
                  Left = 128
                  Top = 131
                  Width = 169
                  Height = 17
                  DataField = 'specimen_id'
                  DataSource = atdbDM.specimenDataSource
                end
                object Label1: TLabel
                  Left = 13
                  Top = 56
                  Width = 81
                  Height = 19
                  Caption = 'Process ID:'
                end
                object Label3: TLabel
                  Left = 13
                  Top = 95
                  Width = 65
                  Height = 19
                  Caption = 'Block ID:'
                end
                object Label4: TLabel
                  Left = 13
                  Top = 129
                  Width = 96
                  Height = 19
                  Caption = 'Specimen ID:'
                end
                object Label5: TLabel
                  Left = 13
                  Top = 158
                  Width = 100
                  Height = 19
                  Caption = 'Additional ID:'
                end
                object BlockIDCB: TDBLookupComboBox
                  Left = 128
                  Top = 91
                  Width = 135
                  Height = 27
                  KeyField = 'id'
                  ListField = 'id'
                  ListSource = atdbDM.blocksDataSource
                  TabOrder = 0
                  OnCloseUp = mBlockProcessIDCBCloseUp
                end
                object mBlockProcessIDCB: TDBLookupComboBox
                  Left = 128
                  Top = 52
                  Width = 134
                  Height = 27
                  KeyField = 'process_id'
                  ListField = 'process_id'
                  ListSource = atdbDM.specimenDataSource
                  TabOrder = 1
                  OnCloseUp = mBlockProcessIDCBCloseUp
                end
                object mUsersCB: TDBLookupComboBox
                  Left = 12
                  Top = 13
                  Width = 145
                  Height = 27
                  KeyField = 'id'
                  ListField = 'user_name'
                  ListSource = atdbDM.usersDataSource
                  TabOrder = 2
                  OnCloseUp = mUsersCBCloseUp
                end
              end
              object GroupBox3: TGroupBox
                Left = 337
                Top = 21
                Width = 463
                Height = 188
                Align = alClient
                Caption = 'Block Note'
                TabOrder = 1
                object DBMemo1: TDBMemo
                  Left = 2
                  Top = 48
                  Width = 459
                  Height = 138
                  Align = alClient
                  DataField = 'note'
                  DataSource = atdbDM.blockNotesDSource
                  TabOrder = 0
                end
                object DBLookupComboBox1: TDBLookupComboBox
                  Left = 2
                  Top = 21
                  Width = 459
                  Height = 27
                  Align = alTop
                  KeyField = 'id'
                  ListField = 'created_on'
                  ListSource = atdbDM.blockNotesDSource
                  TabOrder = 1
                end
              end
            end
            object RibbonsDataGB: TGroupBox
              Left = 2
              Top = 433
              Width = 802
              Height = 281
              Align = alClient
              Caption = 'Ribbons'
              TabOrder = 2
              object DBGrid1: TDBGrid
                Left = 2
                Top = 21
                Width = 798
                Height = 236
                Align = alClient
                DataSource = atdbDM.mRibbonDSource
                Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
                TabOrder = 0
                TitleFont.Charset = DEFAULT_CHARSET
                TitleFont.Color = clWindowText
                TitleFont.Height = -16
                TitleFont.Name = 'Tahoma'
                TitleFont.Style = []
                Columns = <
                  item
                    Expanded = False
                    FieldName = 'status'
                    Width = 52
                    Visible = True
                  end
                  item
                    Expanded = False
                    FieldName = 'cutting_order'
                    Width = 112
                    Visible = True
                  end
                  item
                    Expanded = False
                    FieldName = 'nr_of_sections'
                    Width = 117
                    Visible = True
                  end
                  item
                    Expanded = False
                    FieldName = 'created_by'
                    Width = 91
                    Visible = True
                  end
                  item
                    Expanded = False
                    FieldName = 'coverslip_id'
                    Width = 120
                    Visible = True
                  end>
              end
              object DBNavigator1: TDBNavigator
                Left = 2
                Top = 257
                Width = 798
                Height = 22
                DataSource = atdbDM.mRibbonDSource
                VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbRefresh]
                Align = alBottom
                TabOrder = 1
              end
            end
          end
        end
        object TabSheet6: TTabSheet
          Caption = 'Barcode Reader'
          ImageIndex = 4
          object BarCodeGB: TGroupBox
            Left = 0
            Top = 0
            Width = 806
            Height = 209
            Align = alTop
            Caption = 'Zebra'
            TabOrder = 0
            object Panel3: TPanel
              Left = 2
              Top = 21
              Width = 802
              Height = 28
              Align = alTop
              BevelOuter = bvNone
              TabOrder = 0
              object mZebraCOMPortCB: TComboBox
                Left = 0
                Top = 0
                Width = 87
                Height = 27
                Margins.Left = 10
                Align = alLeft
                TabOrder = 0
                Text = 'COM1'
                Items.Strings = (
                  'COM1'
                  'COM2'
                  'COM3'
                  'COM4'
                  'COM5'
                  'COM6'
                  'COM7'
                  'COM8'
                  'COM9'
                  'COM10'
                  'COM11'
                  'COM12'
                  'COM13'
                  'COM14'
                  'COM15'
                  'COM16'
                  'COM17'
                  'COM18'
                  'COM19'
                  'COM20')
              end
              object mConnectZebraBtn: TButton
                Left = 163
                Top = 0
                Width = 77
                Height = 28
                Align = alLeft
                Caption = 'Open'
                TabOrder = 1
                OnClick = mConnectZebraBtnClick
              end
              object mZebraBaudRateCB: TComboBox
                Left = 87
                Top = 0
                Width = 76
                Height = 27
                Margins.Left = 10
                Align = alLeft
                ItemIndex = 0
                TabOrder = 2
                Text = '9600'
                Items.Strings = (
                  '9600'
                  '14400'
                  '19200'
                  '38400'
                  '57600'
                  '115200'
                  '128000'
                  '256000')
              end
            end
            object mImagerSettingsGB: TGroupBox
              Left = 13
              Top = 76
              Width = 518
              Height = 107
              Caption = 'Check'
              TabOrder = 1
              object mScannerAimRG: TRadioGroup
                Left = 179
                Top = 22
                Width = 145
                Height = 49
                Caption = 'Aim'
                Columns = 2
                ItemIndex = 1
                Items.Strings = (
                  'On'
                  'Off')
                TabOrder = 0
                OnClick = scannerSettingsClick
              end
              object mScannerEnabledRG: TRadioGroup
                Left = 9
                Top = 23
                Width = 145
                Height = 49
                Caption = 'Enabled'
                Columns = 2
                ItemIndex = 0
                Items.Strings = (
                  'On'
                  'Off')
                TabOrder = 1
                OnClick = scannerSettingsClick
              end
              object mBeepBtn: TButton
                Left = 342
                Top = 31
                Width = 89
                Height = 37
                Caption = 'Beep'
                TabOrder = 2
                OnClick = mBtnClick
              end
            end
          end
        end
        object TabSheet1: TTabSheet
          Caption = 'Settings'
          ImageIndex = 6
          object PageControl2: TPageControl
            Left = 0
            Top = 0
            Width = 806
            Height = 716
            ActivePage = TabSheet4
            Align = alClient
            TabOrder = 0
            object TabSheet5: TTabSheet
              Caption = 'ArrayCam Connections'
              ImageIndex = 2
              object GroupBox1: TGroupBox
                Left = 0
                Top = 0
                Width = 798
                Height = 105
                Align = alTop
                Caption = 'Server'
                TabOrder = 0
                object mArrayCamServerPortE: TIntegerLabeledEdit
                  Left = 16
                  Top = 56
                  Width = 153
                  Height = 27
                  EditLabel.Width = 155
                  EditLabel.Height = 19
                  EditLabel.Caption = 'ArrayCam Server Port'
                  TabOrder = 0
                  Text = '0'
                end
                object SendServerStatusMessageBtn: TArrayBotButton
                  Left = 200
                  Top = 40
                  Width = 153
                  Height = 49
                  Caption = 'Broadcast Status'
                  TabOrder = 1
                  OnClick = SendServerStatusMessageBtnClick
                  SoundID = 'BUTTON_CLICK_4'
                end
              end
              object GroupBox7: TGroupBox
                Left = 0
                Top = 105
                Width = 798
                Height = 169
                Align = alTop
                Caption = 'Arduino Client'
                TabOrder = 1
                object mArduinoServerPortE: TIntegerLabeledEdit
                  Left = 16
                  Top = 56
                  Width = 121
                  Height = 27
                  EditLabel.Width = 93
                  EditLabel.Height = 19
                  EditLabel.Caption = 'Network Port'
                  TabOrder = 0
                  Text = '50000'
                  Value = 50000
                end
                object mASStartBtn: TButton
                  Left = 143
                  Top = 20
                  Width = 104
                  Height = 97
                  Caption = 'Start'
                  TabOrder = 1
                  OnClick = mASStartBtnClick
                end
                object mAutoCheckConnectionCB: TPropertyCheckBox
                  Left = 16
                  Top = 128
                  Width = 217
                  Height = 17
                  Caption = 'Reconnect Automatically'
                  Checked = True
                  State = cbChecked
                  TabOrder = 2
                  OnClick = mAutoCheckConnectionCBClick
                end
              end
            end
            object TabSheet4: TTabSheet
              Caption = 'Sounds'
              ImageIndex = 1
              inline TSoundsFrame1: TSoundsFrame
                Left = 0
                Top = 241
                Width = 798
                Height = 441
                Align = alClient
                AutoSize = True
                TabOrder = 0
                ExplicitTop = 241
                ExplicitWidth = 798
                ExplicitHeight = 441
                inherited GroupBox1: TGroupBox
                  Width = 798
                  Height = 441
                  Align = alClient
                  ExplicitWidth = 798
                  ExplicitHeight = 441
                  inherited SoundsLB: TListBox
                    Top = 21
                    Width = 215
                    Height = 418
                    ItemHeight = 19
                    ExplicitTop = 21
                    ExplicitWidth = 215
                    ExplicitHeight = 418
                  end
                end
              end
              inline TApplicationSounds1: TApplicationSounds
                Left = 0
                Top = 0
                Width = 798
                Height = 241
                Align = alTop
                AutoSize = True
                TabOrder = 1
                ExplicitWidth = 798
                ExplicitHeight = 241
                inherited GroupBox1: TGroupBox
                  Width = 798
                  ExplicitWidth = 798
                  inherited ApplicationSoundsLB: TListBox
                    Top = 21
                    Width = 328
                    Height = 218
                    ItemHeight = 19
                    ExplicitTop = 21
                    ExplicitWidth = 328
                    ExplicitHeight = 218
                  end
                  inherited GroupBox2: TGroupBox
                    Left = 330
                    Top = 21
                    Width = 466
                    Height = 218
                    ExplicitLeft = 249
                    ExplicitTop = 21
                    ExplicitWidth = 547
                    ExplicitHeight = 218
                    inherited EnabledCB: TCheckBox
                      Enabled = True
                    end
                    inherited SoundCB: TComboBox
                      Height = 27
                      ExplicitHeight = 27
                    end
                  end
                end
              end
            end
          end
        end
        object TabSheet3: TTabSheet
          Caption = 'Logs'
          ImageIndex = 1
          object Panel4: TPanel
            Left = 0
            Top = 0
            Width = 806
            Height = 716
            Align = alClient
            Caption = 'Panel4'
            TabOrder = 0
            object GroupBox8: TGroupBox
              Left = 1
              Top = 1
              Width = 804
              Height = 50
              Align = alTop
              Caption = 'Logs'
              TabOrder = 0
              object ToolBar1: TToolBar
                Left = 2
                Top = 21
                Width = 258
                Height = 27
                Align = alLeft
                AutoSize = True
                ButtonHeight = 21
                Caption = 'ToolBar1'
                TabOrder = 0
                object mClearLogMemoBtn: TBitBtn
                  Left = 0
                  Top = 0
                  Width = 113
                  Height = 21
                  Align = alLeft
                  Caption = 'Clear'
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 0
                  OnClick = ClearLogMemo
                end
                object LogLevelCB: TComboBox
                  Left = 113
                  Top = 0
                  Width = 145
                  Height = 21
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  TabOrder = 1
                  Text = 'INFO'
                  OnChange = LogLevelCBChange
                  Items.Strings = (
                    'INFO'
                    'DEBUG'
                    'DEBUG1'
                    'DEBUG2'
                    'DEBUG3'
                    'DEBUG4'
                    'DEBUG5')
                end
              end
            end
            object infoMemo: TMemo
              Left = 1
              Top = 51
              Width = 804
              Height = 664
              Align = alClient
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              ReadOnly = True
              ScrollBars = ssBoth
              TabOrder = 1
              WordWrap = False
            end
          end
        end
        object TabSheet7: TTabSheet
          Caption = 'About'
          ImageIndex = 8
          object GroupBox2: TGroupBox
            Left = 0
            Top = 186
            Width = 806
            Height = 530
            Align = alClient
            Caption = 'ChangeLog'
            TabOrder = 0
            object Memo1: TMemo
              Left = 2
              Top = 21
              Width = 802
              Height = 507
              Align = alClient
              Anchors = [akLeft, akRight, akBottom]
              Lines.Strings = (
                'Memo1')
              ScrollBars = ssBoth
              TabOrder = 0
              WordWrap = False
            end
          end
          object Panel5: TPanel
            Left = 0
            Top = 0
            Width = 806
            Height = 186
            Align = alTop
            TabOrder = 1
            object Image2: TImage
              Left = 620
              Top = 1
              Width = 185
              Height = 184
              Align = alRight
              Picture.Data = {
                0954506E67496D61676589504E470D0A1A0A0000000D49484452000001000000
                010008060000005C72A8660000673D4944415478DAED5D077C1CC5F99D5571EF
                1D375CC1964E27B9606CE3821B605CE9CD6003092DA12501422024813FA41012
                0804422004122009606C6C7001DBB8E1AE76926CC036AEB8F75EA49BFF7B73B7
                E7BDD3DEDDEA744DD23EFFD6B7B7DADB9D9D9D79F37D335FD1840D1B366A2CB4
                4417C0860D1B89834D00366CD460D80460C3460D864D00366CD460D80460C346
                0D864D00366CD460D80460C3460D864D0016E1CCCA6A26A4EC2D342D551D9012
                B5E7ADBE48F7A3710DFBFE66FB6EECB95C4545BB13DB6A921F36015804086028
                3EA662AB9BE8B2D8088B33D8A680003E497441921D360158040860183E6662AB
                9FE8B2D8088BD3D86E06017C9CE882243B6C02B00812809472A6A6698A00B02F
                B1AF55663F1AD7B0EF6FBA4F09C026000BB009C0226C09A04AC196002CC22600
                8B30230087C3212EECD123D1458B2AAA6283D8B46993C8CDCD351EB209C022AA
                E2FB4E08CC54800913276AA3468D8A9B08CCAFE2DC3B8BC6BEDFB178A900C1EE
                1FE9FE575F7D25FFFB9FFFB03E6D15A082B009C022CC248071E3C70B124055C6
                B93E5975B16CD932010260E7D70FD912804554FDB71F279812C0B87162649C09
                A03A74D8688304F0BFFFFED726800860B7268B305301C68F1FAF8D1839527D15
                5110C183EDC74B0588E77E345701964105F8DFFFFE67AB0011C026008B309300
                C652020001B0E1E97DD4B85FD560F60CB1D88F3628017CF0BFFFD9124004A89A
                2D3501302580B163855702883BAA2AC9C402CB49001F7C60134004B05B914598
                A900E3C68DD3868F181172A67EDBB66DDA3FDE7C539496962695085E15EE9F9A
                9A2A6E993449F6E8D123A40A00029020005B058800360158849904300612C0F0
                E1C343FE6EEB962DE295575E11656565897E842A8794941471E79D778A8CCCCC
                90E72D5FBE5C7C684B0011C126008B3023802BC78C312500A378BE0504F0572F
                01B468D9523469DC581D9761EF1802B252BF8EFCDE95BCAF551C3B764CECD9B3
                4711C01D24808C8C90E7AF20017CF8A14D0011C026008B305301200168248050
                062F2000EDD5BFFE950420870C1DAA656767ABE3D8D42CB888508C8ED26F93F2
                FEEBD7AF970BE6CF57D578C71D77C89E191921AFB762C50AF9D1871FDA2A4004
                B009C0224C25802BAF14C3C2A80094005E7BF55525010CBCE412653E1C0CB212
                236C55FB6DA8DF6DDCB8512C59BC584952B7DF71874F0208B6AA4009E0A38F3E
                B2258008601380459811C06812C0B061217FB775EB561F01F4EBD74FF4E8D9D3
                D2FD2AD329A3719D4412CA96CD9B955ECF0E3EE5F6DBC3AB002B5688A9360144
                049B002CC24C058004A05DEA2180A036F52000ED6FAFBDA654805EBD7B6B175C
                7081F17C4BA233A5DA70E744F8DB90D7F076A888447D8BBF35FD3BEA4CAE59BD
                5AF31280ECD9B367C87BAE840A3075EA545B05880036015884A904307AB4B8D4
                8204E02500E1743A4597AE5D232E4365A582684915B1C6F6EDDB457E5E9E9200
                264F99227A86919A56AE5C293E9E3AD5960022804D00166146005790002EBD34
                E4EF4800AFFFED6F8A00EAD4A9236AD7AE9DE847497A9C3973469C3C7952AD02
                90007A8471B95E4502F8F8639B0022804D001661A6028000342F01041575B741
                0578FDF5D79521500D8AC81395FB93006E9B3CD9A702043B1F12809CF6F1C7B6
                0A10016C02B0083309E0F22BAE1043870E0DF9BBDDBB772BF1D43604B28000F3
                E65410008DAD3A75EA14F267AB56AD12D36C092022D8046011A60470F9E56228
                2480443BC39881F70A57966475EEA9284800D3A74DB309200224C71BAC023053
                0120016894002A11CD2766AEB6A1CA120D15204AE58DCAF3AC820A307DFA745B
                0588003601588499047019248021438654EABAC9328A261B2A522F94003E993E
                DD96002280DDFA2CC25402B8FC726DB087002A1D1023926B44613FEE5287713F
                5AD2C5EA55ABE4279F7C624B0011C026008B3095002EBB4C0CAEA4045095912C
                D2CB9AD5AB0508C09600224072BCC12A003302184502183C38D145B38C64E9B0
                D1C69A356BC40C9B002242F56C113180990A0002D0BC049070113CD4BE77C63F
                6661B9E3FDFC81CF030940CE9831C3560122804D0016612601301EE0A0082580
                682EC325C3F25C24658CD6F35002983963862D0144009B002C22DA04501D902C
                2A452E0960E64C9B00224072BCC12A00331560E4A851DAA04183A2620A2BE220
                7657355360ABCF969B9B2B3F9D39D3560122804D00166126018C1831425C0202
                486624CB281DCB67A204F0E9A79FDA124004A87EAD23460846008CF2134D54C7
                0E1B0D84AA172606FDCC26808860B7368B305301468C1CA90D1C38507D15514C
                CE5989EB55EAFED1DC0F9CA98F862972B07BE64105F8ECB3CF6C152002D80460
                11661200E3015E1265092010A5A5A5CA3FFEC0810362EF9E3DE2F09123E2F8B1
                63C28DC69E827E51B76E5DD1A06143D1AA654B157598F106D2D3D34DAF55D959
                787A349E3D7B561C4119E8E578F0E0415596B32823C17B3742599A366B26DAB4
                6923EAD5ABA7CA124BA986D7CEA304F0D967B60410016C02B0886004E09500A2
                8EC3870F8BAFBFFE5A7CB771A38A9043120887B4B434D1B66D5BD1A54B17E1CC
                CE160DD119A3D1F9DC6EB7D8B061832A0FE3F5B16CE1C0FBB668D1429CDFA993
                B8F0C20B45C78E1D05137D440381CF9497972766D90410116C02B008331560F8
                F0E1DA8028AA00945E37A383E5AE5923376EDCA871C48D74869D9DAD478F1EF2
                E2FEFD358EC6C2DC5E3F64F9CE82748A8A8AE48A152B348EF69599F96FDEBCB9
                CCE9D54B854587D412D5550810809C3D6B96AD0244009B002CC24C02603CC068
                48006CB83B77EE144B972C5161C42966470B0C43969595A5CA59BF4103CBE521
                112D5AB850ECDAB54B4900D100FB6BE3C68D054849900882A92A15457E7EBE00
                01D8124004B009C0228211C08001032A75DD53A74EA959ECD5AB56A93878E1C0
                919DBA353FD931F99B7084C18E47119CEECB14CB439DC7390776A8AF962E1527
                4E9C08795D86EC22C1D4AA554B753E3ECBE9D3A7C33E037FC7283F8CA5D0E6BC
                F32AADA614900066CFB6092002D8046011662AC0B061C3B4FE1E02884805D8BF
                7FBF5CB870A1B661FD7A766653F1B67EFDFAB27DFBF61A230A676666CA0E1D3A
                68F5EAD7270148FC4663A7DBB963872C2929D1D8712141C863C78E99CEA0A3F3
                6B575D7DB512C7BD65F1FB3B540E8D4936962F5F2E412AE5AE818E2BA14E680C
                D2D9AB776FD9BD7B778DF30C18C9297B6BECFCFB0F1C90DF7CF38D565850C004
                1F72EFDEBD1A89CA4C7C6FD4A8911C7AE9A51AA3FEF27922A943EE141414C839
                B367DB2A4004B009C022CC24008603EB0F71B6A25022FF8E1D62EEDCB92A075E
                20D84FD04955C461C61DCCCCC8B024BE73C45E5B52A28C62BEF8E20B95632F10
                2D5BB614D75D7FBD40E72B57A6D5AB572BB13F307E2147ECAEDDBA896BAFBD56
                0C1E34489CD7B6AD3A160AECF4546748283366CC509388661399540348A2175F
                7CB19AC48C04249B3973E6D8124004B009C0224C0900222C1B6F451D60BEDFBE
                5D7552B3D9742EEB8D1B374EDC7CCB2DA273E7CE119595F72872B9C41F5F7841
                B80A0BCBE50360671E3F7EBC12DD756CFAEE3B31D524782945FC2953A68849B7
                DEAA5615220189691E08E9ADB7DE52730B81E5A13AD3BB4F1F4578DCAFE8F224
                240031D72680886013804598A900145F29015464D69A23FED48F3E92478F1E2D
                370BCEF0D73F7FFC719193931395D9F123478EC8DF3EF79C46FD3850C5183C64
                883660C00075EC0888E8BDF7DE5365325E831376BFFEF5AFE5F01123A262FF8F
                F2686FBEF9A678F7DFFF56EA8BF1EF5C148014A07983AC56E8DA900024A4295B
                058800360158849904C0788017574005A0D1CCFBEFBF2F0E1D3AE4779CED78EC
                D8B1E2D1C71E8BDADABD0EAA01BFFDED6FC5A73367FA1DE7C87EED75D78956AD
                5A2955A4A4B8D8EFEF4D9B3615CF3CF38CF2768C667928617CF9E597E2FF706D
                2E2D06D603232D67399D15BA6721A49CCFF10CB6045071D80460116604C07060
                D45DAD80B3EB3456F9F6DB6FFD8E53EFBDE9A69BC48FEFBF5F75CA58804B793F
                07B97092D0880B2EBC502D1132A066A9D79A8FA0451FC9E8EAABAF0EABEB4702
                7DBEE1D7BFFA95F8FEFBEFFDFE569BC474EDB5CAA0C92A48005F7CFEB94D0011
                C026008B305301200168FD3C041036512667AABF5CB0C028A66AE8FCF2FAEBAF
                D71E7CF04136FC58BADD2A639907EEBF5FA344A01FAF55BBB6AC5FAF5E39239F
                71E3C6C9279E7C52E37C44ACDC81592FCCE80312D0680361FC7BDB76EDE4C489
                13B5FAF5EB5B53010A0B2508C0560122804D0016612A01403CBEA85FBF72E706
                8AAFFBF7EF57E9ABA163FB9DC3A0A2BF7CEAA98827D72A02DA0AFCE98517940A
                120A5C7D78037A7AD74A2431B50A7658AE563CFD9BDFF8D50DC1380B24572B12
                08273A791D5B02A8386C02B0083302A07EDC0F04204384ADE272D8BC79F34471
                5191DF71A609FFF38B2F8AF6EDDBC7ED1968C77FC30D37843438BAF5D65BC543
                0F3F1CF1925C4541D5E38D37DE5009548DAB030D1A3410D740150865B8A4C3E5
                72A955069B002A0E9B002CC24C058004A05DE42180A02EABBB77EDD298B9169D
                CE770E0D675E78E1056DC8D0A1718DC243439FC71F7F9C4B66A6B6F8A9A9A9DA
                5494B573E7CE718D08C45588071E7C50E6E7E5F9FDBD57AF5E74B80A7B3D1080
                0401D82A4004B009C022CC24004603BAE8A28B42FE8E33ECEBD6AEF53B06FD56
                40C7F65B878F17282A3FF2B39F955B8B27FAF6ED2B5EC3489C8872712DFF0777
                DEE967D6CC3980ABAFB946192F85026D1E2865D91240C5611380459812C02597
                88BE41088083137DF89919D86891473BFE77DF7B2F2E3AB619B804396AE44853
                ABBC7BEEB947DC73EFBD09894AC4F2FC12A4488B3E23E8C4146EA9B508EAD57C
                9B0022824D001661A6020C1A3448230104134D39F3BF68E142BFE3E3274C104F
                3DF594841A9090A09CEC24575F7595FCEEBBEFFCEE4F3BFF175F7AC972B2D368
                AA00FAB1E2E262EDD64993FC8C965AB468216FBCE926CD3B2761BADA4297E505
                F3E7DB2A4004B009C022CC2400C603A4D86C063646AEAF6FDDBAD5EFF89BFFF8
                4758B521D6F8D94F7FAA54012368823B63E6CCB84E4A068246422480929212DF
                31AA235499CE0B6117C009D6050B16D8124004B009C022B21C8E611859FC0900
                E2699F200440B1FF83FFFD4F1C3F7EDC778C81393E9B352B6E33ECC1F0BBDFFD
                4EFC27603990655AFAD557CA172191F8E75B6F89975E7AC96F8E824B82C1EA99
                302300ECDF5C545C6C134018D804601124007CF8A9009000B43E7DFAA8AF2240
                34DDBA658B98356B962C2D2DF51DBFE69A6B34AEFB0B214C45E078EDBFF2F2CB
                F28D37DEF0BB3FA3F4AC58B932DEEA48B9635003C49D77DC214F9D3AE53BDEAD
                7B776DCC9831A6F5CC1DFC26D0C8EA8C4D00D6601380459849000C07E6258072
                60908AA54B97FABED3A0E5A95FFD4A5C75D55551290FE3002C5FB64CC50B6CDC
                A4091D8844870E1D2C4DE0BDF4E28BCA33CF084A00B9797996EE4DCBC1952B56
                88BD7BF7AA197A2E85D280281AE02AC015975F2EF6EDDBE73BC6A0A7B7DF7E7B
                D0DFD08F81FE05B6045071D8046011661200084049006623D9A2458BB83CE53B
                5EA74E1DF9C69B6FAAC01EA146C070FB8226B4E87CCF3DF79CDCB66D9B0AB6C1
                4BE1FA1A63073CF0C003129D31E475A00248A8007EF7A759F2B2E5CB35FA0104
                FB1D27E7A64F9FAE41822009288F3E125B83060DE4A45B6ED16E9D3CD917EFCF
                CA3305FBFB0FEEBC53AE5EBDDA77BC56AD5ADAE42953541D0A1309A0A4A4442E
                FCF24B5B0288003601588499044057E0DE41240088FF62F3A64DBEEFB46C9B36
                7DBAF2BEAB0CE8D0F3E8238F040D24C289C93FFCE10FEA7EC1F093871F16F3E7
                CFF73BC64940E6D76B17621290310C7EFBDC73A68146F8FB1B6EBC513CF4D043
                CA99A832F8CDAF7F2D683CA583D2C9F537DC209A356B667A3E2580850B17DA12
                4004B009C00439D9D9296840E761B70D7A55F3B2B23286CFC940077B1C15E673
                D92301F4EADDDBF41A5C01D8B16387EF3B23F0CCFDFC736507102928F63FF6E8
                A3AAB107033B223DF96E44670C86891326884D0672223892BFFCCA2B6AC2CD0C
                ECF418E5CBFDCE083EDB1F9E7F5E0CAE64C2D417A1A2FCD3A0A2F09918CAAC75
                EBD6A6E773D560913F019C754BF9574828F3D352530FE39DEDC57BDC5EE8721D
                0B7FF79A059B000CE8D3BB776B74F64BD190AE420372A072DA62BF493031B6FF
                8001CA5C55984C4E4D9F368D917E7DE7376EDC587EB970A1E68D7813910AF0ED
                B7DFCA7BEFB947A37E1CEA7C94497BE75FFF323D875188468E1821CF9C39532E
                39E9FD0F3CA0DD79E79D6A3FF0779C6F78F0C107E5E9D3A7439671C2C489F2E9
                A79FAE940AF0EAABAFCAD7FFF637DF7148001AAECB55145315602D5400A85C7E
                9E96866B9EC1CE1E10C02690DC7C6C1F63FB664D6E6EF4422F5761D80400F4ED
                D3A71E3AFE2DD8EE4363C94263B194C182B100824900D34000BB77EDF27DA704
                300F627765C4E355AB56891FDD775FD824210CE6B170D122D3BF2D40197EF293
                9F989A0273F47FF1A5974CC37553247FE6E9A7C386082721BEFDCE3B113F23F1
                F25FFE221839480749930654DEFC06E5B076ED5AB118CF6BF64C81C019FB5241
                02A969697F40E3FF0E4410FE47D518359E0030EA7741877A15157159456D6049
                00391E09A01C18A38EF1EF7444630E80C12FEF030198E9E0467035E0D3CF3E2B
                779C8636CF3DFBACF8E8A38F4C7F471B00A6D86A6EE2814713DD277EF10BBFC0
                2166A0F8FFCA5FFF1AF13312740F667C421D240006326DD2A489694C4006425D
                BC78B12502F08227EE02113C925EABD607AB56AFAEB1D2408D26008CFCA3CE9C
                3EFD165A52FB40D11162A2C691B459F3E6B26E9D3ADA5174BA2D9B37ABD3F473
                987587CB6FC24405605C7DAE4FEBD7C4C82F5FFFFBDF95CA10A90A00F15DDE73
                F7DD1A47BC60E7F0EBA44993B4471E7DB4DC39F8BD367EDC38FA0304BD3F7F77
                CB2DB7943BCEA01D37DD78A33C78F060D032F2EB134F3C21D1592BA5024C993C
                59E6E7E7FB8ED36C9A4149598766E7A33EE492C58B7D2A00DF5D7B9060FD7AF5
                E491A347B57D7BF7325F81D9FDCB5252535FC4757F05E9EA9CC5560D428D2500
                8CFC63CF9E3DFB77EC9E673CCEE01C3D33324406368E389C1CE346C31E8AC1C6
                1190012BBC04500E346859F6D557BEEFBC063D0019EE2A52B081330D3674ECA0
                0938DAB56B27FEF6FAEB2A1148E06FFFF39FFF88DFFFEE7721EF919999A93C02
                191034F0F7AFBCF28A9A9C0B8C1CAC837E11CF3FFF7CD0D97A2BE044E7E82BAE
                508E543AA83EDD74F3CD417FB36EDD3AB1C42001B0AE475F79A5E8D6AD9B5259
                A832511AE36A01439005480A65299AF68F5AB56BFF0C92C05151C3502309A077
                AF5E03D091DFC56E17FD18C54C26A860808F2618F903B5816D5BB79623001AC0
                042380EDDBB6297B7BE3F9B4667BF6B9E72AE56DC7C64C136306D1300617E535
                BB77EF2E7EF6C823A6710A69B473F75D77315987EF984E6EC632F2FBD3CF3CA3
                8294069693517B6803F0C9279FF8051561DDF19E8FE0DE5D2AE9E5C84CBFF44A
                34125CE72E5DC4A851A382FEE66B12C09225A6046004AFC9FC04CC556054A3F0
                AB33F8CD8BB5D2D39F5CBD664D8D52076A1C01F4CAC96951565A3A1DAD7BA057
                8F549E66970C1A249D4EA7C6093033D1944E3DD3A74DF399F6F238C842CB0EA2
                02B083F0FCE3C78FFBCE874AA1CD9A3D9BCB659532056687E58AC0FC79F3B4F5
                68D034BE01A9690C527ADE79E7953B9F23F65B6FBD25D179FD8EB76AD54A651D
                62765DE37D9854949E81B856B9FB7315201FE72F5CB4486234D59A812C070E1C
                A85644283155C61498F5F697975E526535D6274DAE2999E875AB79F22BF87E0B
                09402E5DB2C4A70230B0C9159022BA76EB66EA0D093294F35077500D7CF7C1F1
                A39016EE2959BB3674CCB46A861A4700D94EE7D378D98F635779E470F462600F
                EAE6A146E66D18D103A3E752E46592CB6060982A66C731E2D9679F15634C46D7
                5882013368A06334AFE5FD3961475D9979030E1A446E82A6B78C541C4FC72592
                266D147619564FB86A722546F316218282306DF9D2000980E1C5BB064800461C
                86F444C3A680D0E41BD36BD51A9A9B9BFBBDA821A8510480D1BF2B46C3E5D8F5
                B5268E2CC3478C08DB2149003367CC3025001924630DC56D2E4F1997CE1C5959
                E275E8E80D2C66EAAD2CA84B3302D09A356BFC8E73496D24C46A763076A0AF0C
                7E0B04A3F150151861A16EA201D61B67FEB9D4E8574E4821248050C141F5F21B
                0960D46597850DBAC2894D6615E6BC83176EFCF64F0585858FC4FC819304358A
                0030FA3F8F46F2535DF46FDAAC99F2D0D3C35F8B10A1BDE974F3E9CC997E2AC0
                45175DA4393D04602AEA320E20F3D65357371E7FF2C927E5B5D75DC7FD987ADD
                9D3D7346FEDFB3CF2AA324E37106FFB862F4688D86353C46071C482B72C78E1D
                7ED760E77BE9A597245482987B03EED9B3474E993C59F34ED2F95615060D1E2C
                2FB8E082A0EF853B2000B9ECABAFFC5400925B972E5DC225169505F9F90C4F7E
                2E088994C7D36AD5EA04B5E89CB8548D516308009DBF9E5BCAED78E0A6FCCE51
                62D8F0E1D47783FEC6385BCC7C7E5C23374A00F451A7734FA8DF73826AC58A15
                7EC7E939F797BFFC454903B102CBC919F90F3FF8A0DCAC3D49AB77EFDE7EA32A
                4561AE30041A19D1A68026C291E629B4028AFECC42C4FB1B41B19FA27CA0F154
                A0444209802B2E460960C4C8912480B0B6019C1864C2164E921AAEFF44A1CBF5
                5CCC1E3889506308C0999535011FD3F5EFEC84B42EB39A8D8723D32C1302C80A
                D389D9B819AFCEA87F13543D1898A3E3F9E747FD59998C939D7FC6279F9433DC
                A13D3DC5E3406B3F7614A6295FB66C59396B3F460962A2519265B4D50112CEDB
                6FBF2DFEF6DA6B7E44A5CFCD18C5F860F7FE860480721B09806A5D30D20A2405
                2E23FAA940522E4F4D4B1B955F5050ED6D036A0401A0F373A87B11DBFDFCAEDB
                CB5FDCBFBFE53CF43B4000B367CFF65301FAF6EDAB7947F1B0EAC3A2850BFD7E
                4B7113A3B07CEAA9A7B4CE9E912A2AF1FE68ACF4E73FFF59B9231B63EBF1B4C6
                8D1B6BEC18F44BF096D1AFAC74EF5DB37AB59A55371A3CF11A240EFA0240B40E
                E9325C917DE8DEF2DD77DFD5B8A479F2C409BFBF77E9DA5563D055BA291B9FC1
                AC9EBFF9E61BB97CD9323F1580D25DA74E9DC2AA00FCA47FC41CBCDB63C78EE9
                F73F8DBAE859B2766D70CFA76A821A410018A5E9C2FB391E76A07A68B4274E2C
                B5AB40FC3B4A0034EF358EA874050E2701101CD91820A438200127C1B57BDAE6
                D3A8A83233EE5CD7A68BEF5BFFF8879F09B20E4E3A7299309C2932E703186FE0
                BBEFBE2B375272AEE4CA3163C46DB7DEAA2497CAE40DDCB37BB79A0CA50B72A0
                51138D90BC4465E95ACCB7B83C400260AAF14E16D516BE1FFA4870A25707DACA
                4D854545FF8DF801AB086A04014002A0691A234D2A6F12CE70B3215B6D60045D
                7B49004631957AB4553D9E1D8B4B55C646A683E59978D55562D2A449AA835A25
                023678767CC6D47FFFBDF754C24D635C7D1D0D1B351203060C3075A63113ABD9
                2129097015C34C87A6B52103758E1B3F5E4504AA4879192371F9F2E52A13108D
                7202AFCF20A01CBD8339FE98613D0900D7341200A31B9FDFA993E56B30CE027D
                2D0CF5F274A1CBF52BCB17A8A2A8110490ED749E07916E9BE6F5F283FEAF66C1
                19614617754518317E2708E0F3CF3F57D975D441001280E67038C2FE56DF3F73
                FAB4465FFEDDBB77EB4943FDC4DE66CD9A69D4CF478C18A18C92D81928D91B45
                60FE8452C8D6AD5B55141C8EFA148129BEFB4E309C4FE3230609C1B5FDCAE23D
                27685941241A73EED1CE3E501DD0CF69D2A48976E9B0611C6D651FD405E30198
                9597730A748DC6B36BA843152929F0F9796E5A7ABAC694EBEDDBB7B7AC9A7167
                FDFAF572C5F2E57E2A00A59DF3CF3FDF920AC0039B376D928B172FF63D27CAFC
                0E5480E071C8AA096A04014002E88E0F5F5EEE6013613ACC463DAE19D3B0C728
                01D078281304509189314E7AD114959685A166A8D999BA413D380F23214D9389
                A3478EA848401B30321FF23760310527D0A8A6449A769CE5A30F04DD900D6BE5
                A6605D42E7561386F426E424DE69FC66EFBE7D4A9DD8E5C9001CFC792105D11D
                B92223BF0EAA00545B8C1200F33606FA438402DF2F276B0DF8507AA20A955ABE
                4815448D2000E8E917E241BFD6BF9300B84E5C11D195D6696C2066045051F01A
                18B595734A30A79ECA80FA3E3B3E3B6345F4743322D3C576DAE88723AD48C07B
                B66DDB561955D1112B9255064800E508802B08460208576EBEDF05863069387B
                2A7E741308A05AFB06D41402688F97B95517373142C991234752C4B62C6A7A1B
                889F0AD0AB776F3F1B752BD7D1F729B2631497252525CAF805627DA567D5D9F1
                3B77E922BB75EBA679438F851581C3CDB0EBFB543B5007F2EBAFBFD63881877A
                A87479B91AD1B3674F8DBA3A13A656B40E85410558B572A59F0A40B5A743870E
                417FEB556B7CC7B66FDB26972E5D6AF44B7817FF4DA64B775C1B6B9C51530880
                6172D70BAF11103B0A0840D4C7A79909AFD93E09E0CB050BFC24007A02667808
                2062B063D14680A318FDD643A5EE3603E7091A356E4C7D574DCE5935318E743D
                9F2A0CCBBB09623DC5FB13900E2A221550EAA27B2FBD0629A17002B4B2E06422
                08C04F0260C8765E3FD83B0D046D0138E761A89F3F16BA5CD5DE24B8661080C3
                41D99249FA54FC2EEAA75C660A9775D60886F7E2049E9100E809C8B801D1001B
                2575FC7DFBF72B3D9FCE39EC6CBC9FDE60D9805976EADB5CC1A0A55C4BE8DB24
                8060F319B182BE02C172EEF69697E4C5F21A0D89585E767AC6F66F81B252FD62
                A095689457EFD03460E23C85910018B0958E4E569F85D69ADB0C69DC70E51F14
                1615FD23AE959A00D414024843D3782345D3A6F03B45BC9C5EBD34889F9645CD
                DD107B172F5AE4A70278AF11F6B721F6438AA89C1F60241BFD9EE84CB276EDDA
                CA1087F6FC11DED3D2FD23D92761B1BC5C41101C715146C6F4677969D023025C
                79A3E55B000940AE5EB5CA4F05A05D8585D5049FEBF6E2C58B250858BF3619CC
                09FDFF5C92C26A8A1A410084332BEB0E7CF8189DA31197B03842E90825CA52EF
                65D009A304409BFA68490089423CDD9263858D5001680361940018AC852A9115
                700EC6A84260676D4A6AEA8082C2C223897EB65823E2B78F51B51B5ACF205CE0
                2254DC6B4566666E4984ECACACA678BDF4F356D92FD9F1FB0F18A066A083C148
                0814CB692FEE47004EA70A1F164F54870E1B6DD0608904200C04C0558550EF56
                07DF27AD08FD622508F17B54F4E3851E7B85A404FA9F036DE15E1490CCB714FD
                6F4324D7B1DC9A2846E3231B371D8D9B8EC74D196D81334E8BB18D45014E59BD
                56022BED1D94FF56DD1D98B9E72F19342864EE797D9F04B0ECABAFFC54004800
                31530102F703A3E054E29E11DD3F46FB51510136520530A412A30A40472D1040
                38432FB975EB5665F0A4AF6A303C585A6AAA23BFA0607D34DA5CAC80B64CE30E
                BA4F0EC1760C2D64031E68069E7716BEBBACDA2F842500DC289DE1B350B30FA0
                7E98F2A585E17765B8E19DB8D93B89AE102BC8C9CEEEEF76BB3FC76E43F5F068
                3FECC017867009D64177518E144609200B12403077627BA436472CEA8512004D
                977DF78004C09C8DE12400C638A4FD00BD27BD2031BCEF2A2A9A94E87AB202F4
                CDC9A84FAAB5BA1ECBF2EF439F5C828AFE0BF69715151585B46308F936A037B7
                42C77F0CD4381927964BFF8ABBADC3DF2F07016C13550020009AA532E3C4146C
                CA4286A33F8D6618FF2E54E32401D082CF8F00B2B2FCC8A3BA75FAAAF23CDF91
                000C118FC211002540DDDFE1807F28B4DD18FD47E415145489C93F1000D341CF
                C55BEA59EE1985D88F07A5C4FB7B10DA9E60D708FA867B6567772D2D2B7B1BBB
                03741B7A93208ECF63E7E745252549AB2B050224D0A5CCED9E8587B8507F1EAE
                A567E7E4C8D6AD5B6B5ECBB972E22275448C167E2A0024008D12402544F3848B
                E0C1FE1E655523A6CFFFDD77DFC9DC356B7CEF25852A8087D44D5DA619A98991
                80F04E8D41414FA7A6A53D515050F042259A575C919599A9810018E7FD91206A
                1247ABE520B529F985851BCDAE614A00BD7BF5BAF06C69E974FC31946C7C4CB8
                DD97B84A4A5C89AE888A223B3B7B8274BB997DD217C09E93820C23CD283269E9
                E9E5463F4A002A74944102A0239015F5C1ABBF97334A09677C6475BF2A229ACF
                4F5F83DC3012807789504DE63299E871FFEC4ACAF20F0470577E7E7ED2CF6519
                E1CCCC748A941426A0086A018687FB1A83DCC4DCDCDC6FCABD87C003BD72723A
                60E4FF147F707A2BCE179FCD2FC0849473B15D0302A892515320BEDF858F1734
                6FC519CD693B75EE2CD178E82DE83BEE2500E93648008EAC2CEDC20B2FF4D671
                E849BB7031F12AB32FE230025B799E8AEE47EB7A9400F27273834A00B4B66428
                F02D9B37ABF7A8B763C335664015BC232F3F7F7FA2DB65450102A88FB73315DB
                E5BEE74F49299F28550857ADF4F4B1B979797EEABA1F01403C6E78F6ECD97F61
                349CA0FF8DBF67233F74F8B0F2E8F241CAFB5DC5C5AF24BA0222055380E3E366
                348697844112D041898026ABF4A5AF0D15E1C4C9936247405619FA015CE02100
                A1D7557543557826A62CA7B392A1D0CA8BB24EDDBACA5A9121C01927C1C4CE83
                063F6FA3F33F5A153BBF0EA7C3F1633CF3CBFA77CE67D152940E678667A6FAFA
                49EDDAB56FC3B3FA3220F9BD5D8C8A0F833AB806EAB3D3A4B14B0F34F2B973E7
                32379D7EF82C2E9B5954541495A51288D20D8A8B8BE39EBB3D9B2420E560B794
                7F4245F41222FCAA88118104509D50153ABE0E1200939554006AB61C1DE2F710
                8DFF9E5F5010F79460D16CF3590E4777BC2F4E5CAA7ECBCECF60AA5F83008CFE
                0D68EB67F1621F731515FD593FE47BCBCEAC2C4E8A7D8A0B75D34507EAC34386
                0E9507F6EFD7BC117175D1C905316360A1CB5569F11FF7E5F5FE8CEDA9E29292
                84585E8108DAB84B4BEF47E5DC8CC7EBA86B3D9E3A0B2E82663A1CDA05175CA0
                BE8A044E828908D7D363A05224E4F919CCC3984C34C4337397A3D87CB4DFDF43
                FACB4567089DEF3C067064663662C4216C0FE3FE959E400701D0A36A19AEE7E4
                7342A2D198868E896D172F5AA479C3BBE9EF7C03A4DBB10585856A3E40335C84
                F9D27FA6533FBDB41835B72174E292B56B031347BC412B24104059854A6A02A7
                D3C9C0FA2BF132AE0701CC88F7CBD08197C215000EE7E3B14DC05BE98C8A60CC
                B0BA2288644033E0EE1E024808AAD2281DCBE7A104C0988B4170068DFE08AEBD
                0B9FF3F13915DB2AB4DDE80762B008B4B5F1686B1FE0812F76B95C8595BD1E54
                80545CEB35ECFE503FC6780899689FCC6ACDE8D08CE9A0E0993D7D1EC4F318BF
                AA1AC708D841BADD8BB0DB591DC48B183870A0CFCE9DB9D7A94F78C1498607C0
                2095D6FF413A29B8D96F518847DC65655F60FF5A9040C233B47AAD1E69E9D819
                ACC070628DB0DF15F57217CA5A4B3F8FF5C3A83D5651DD3A6C34108D3A6110D4
                000228453BA73FFF725C9D36BE5BB07D539400353310E8FC0DD1093F4A494D1D
                253DCBE88FA35C9596422049FF181F34FE5115CA793B86572338801B83A6029B
                20250CCDCBCFDFA64EC6287C1708E0AF7819CA26B661C386F29A6BAFD5D25253
                2967C94F67CE54DE705EBB4A894E310C0CBAB8B285A69B2EEEC9488C5D706966
                A41883CA9857D9EBC602595959C3500133515EE5C0CEBAC880D4C0A8BE9598A9
                8F89781DEF59F868AC0254E699190ABDA0A0C0786D8EFA0CE7F571A2DB4D20D0
                E647E2E3339A9FA0B0DFE1217250CE4A0F7A9002D8DBBF949E151BAD759B36CC
                F0CCFEAA5641A64E9D2A8F1E3DAAD75129D4801F6110FFBBE6FDF11C7D1981B8
                E8A28B94992B41174F108031157519CEED08D16547142A6322CA3A4DFF8EC2CF
                E6D2222AA4625131E20012002A6B26767D112CE808D4BD0212800DEBA8886440
                09C018D117389D8C0480F65E974B7678B2D1FA3194F32A94737A65AEABAE9D95
                D516D7E5129FB26463A6E6B1E3C6A980310413C4AE36984B0373A1065CA161F4
                6F8952AC135E535FFA6E5F317A34A3C8AAB36830316BD62C633EF533101FEA41
                7CA894FE0F9185F99EFE85ED7AC3E1A3DE0A991FE1656306330260C0092EB9D8
                482CF6EED913980B215909608477C06B6838FC01CA7A1BCA5AA93909B4CF54B4
                4F3A35A81ECFF88AA3D18FEB7B2344D1E49959A0CF9C8B41B90F6A4886861F5E
                2698324BCA3A141DD8F1C78D1B47315F0575387CF8B09C3B77AE468709E99940
                D85F5454643D944E108000B270B945B8A50AD3651007FF858F29C9E68A899737
                0C1F7E2A000D2ECED959544D6FBCEA707FE9819F0A809D9B5D494400D94E2755
                9EB7B17B9B5105427F3A84820FC5685C54D97BA04BEDC57337E7B51913F2F2CB
                2F57D9A0681701155FCE802ACFC84DDEFB9E4A4D49994002781005F893F08A0E
                5CD7661209DDB79ACCF1C5175F18C3427F8FC25A4FA9635E19A928C31FB0FB13
                933F6F46C71A01FDE4BBF8BD9EF070720E204002B091B4E0307733DA69F21040
                7676577442CE6F7532F9F39FA0933F9A5F505059A97A3B3E5414145AB132F47D
                336F4879920093A77C7B6E329FA9D07F4202F83308E021FD68BF7EFDFC5C5C49
                00F3E6CD8B2A01E4E4E464969595CDC67DCD82B69582C0EE8004F0EFE8557FE5
                6113409542D21100DACF6DC21391AA5C2C7A0CB5DBD2D3D24643ADAE941722EE
                C18037CA018204C0C0B7BA2A4F308B3263271AEEFBA2861F7D80FDEB749176C8
                D0A1A2A3219CF29123472424009F0A80CE791015DBBC422533A0574E4E8ADBED
                7E0597BA37C42CF0BF718FDB62FF5A2A54B95C05F8044C5ACF535A35DF2A02F7
                BD8F94E2DD87A8A5FE053E5FB512C1637A7F29A426CA19F3B883D5BF779F2B4A
                93928A001C8E7FA15CB71A9FCFD8FEA172BF96969AFAE3DCBCBC889704D146F7
                E3924D751560D4A851B251A346BE3ADDBA6D9BB6D8983456CA0F35148CEBEF5C
                9A50F6EF4CAA689CD862C044A67362F0042FCAD252521AE4151646E435D50B1D
                A94C4A3A2F34D58F31830D27710CBEF6DFA142320A0B0B1366AC6152B964D62B
                84D7DC320478CE44FD8B3B5D8AFD371E10A73B25CDA35419A4EF4E172DDF6E2E
                52CEF82537A118FD51989FB221CD07016C4AF43310599E09EF759AD7CE86FD8C
                599418C8C407290FA6A4A65E03D5F7CB48EE91ED70D441AFE64CBD72DDE724E0
                65500198D05507B31FF945B696F20BAA004B50B041FCCEE0182400866ED68D06
                18E2997E0007CFA5A272A7685A7681CB55E11880BD7AF56A5A565A3A1BBBFD84
                97E129A2F09E9CA1D463E2E3CE07708FA18511DC23D100513C8E8FE77C9555C7
                2D36FD75AB387ED17151150760FF7D23627FFF3ADFD4165DA77412A9C7538D37
                FE333AB6D9DC51D282F1FB30E02DD2BC4E67EC949CA16767340424E143AF4CAF
                55EBCADCDCDCF079DF02E0F4DC8356858A2D197A9DFE007A66280EF8B4E5E13D
                F50CD78C1CA4A1709FE38FA3741B625A0FB569D3C6EF6D2C59B244E5B8D74530
                30D81DF905056F57A480DE683C9C6CFC31C3B651046198EBC183076BCC888B82
                C93D7BF6E8A2DE29B0E12D9000924684B30AD4E7E378B4E7BCCF21655DA92902
                E87B5C1A9401CFBEFE693C16CFFD24BF7F9D6FEA90002408C0A802BC580509E0
                6A7CBC87B2AB248D68EF12831EE34CAABEE5CDFDC067A38DCD2B50057E92979F
                5FA155B06CA7730A2EF196374E82C6A428E85B7EFD78D7AE5D1AAD7A0D3E3D5F
                5005F89026B83C839D9B091A03C32973F2A0C0DFD0E21D74DE1F80042C274E44
                012783005ED5741D5A78447FE6D7E37D999E99195EBC70E3D8FD90005E4DF4CB
                AB282A2601189128692079EF5F8D2480FB348FBBAE1A8E197886ED9E9D95EDDE
                A80AE0D87110C08FF20B0BDFB17A7DF4AD3486BAC33D26EBC798B52A305E25C3
                9F2F5DBAD418FEFC2312C05FD003EFD74FEADBB7AFEA98463088829739F443BB
                D3D3D37372F3F276852B1C27FD70BB51EEB2B2F785C1EF9E22CA25975CE2CB5C
                4B5F03E352A85BCA678A8B8B9F4AD03B2B07746C2A539C0708976DF36E6C3FF5
                3D476DB7D8FEAB9DE24456D21937263D6A6FAA253A3ED65EA49EF4ABF27F62FB
                6D989FB285EF025124DCF69F8074FE3454DA5FEADF552C49AF1B3957D7BEFAEA
                2BA38A4D1C484D4BBB19BFF9C2CAA4600EBD59DD6E8ED0ADF99DAA3C25F9C0CC
                571B03622782005EE61CC0CFC0BB7FD045079AB6829DFC8C2CCE9C39A33129C6
                FEFDFB7DB396656EF7132081DF4132085A40747EAEF75F81C2FD039FADF4DFA2
                D3CB7EFDFA6928A05F5C37A34B273E5E2A2A2E7E38D12F4F070860300AF69F70
                AB0034A8C27E5DDF73409475D773736AA66ACEC227F2FEA8B694E32981AB009C
                4D3D696115E087208099B16A0F1501248017F1F180DEFE7BF7EE2D3B77EEEC7B
                7E0EB0AB56AD922003E373EE81947D2774F8392081A0F60168972950217E8E73
                9FD57FDBBC79730DE23FCD80FD56D9D8BF98835257E5B13D4A02188B3F7E88B3
                D4508C1F8BE1C387FB6EA08B0BCCC1EE72F985FFDB0BA6190B5D659559C1D0F9
                6B6314FFA174BB9FC1D726FA71CE80523C61324B23987ADA8F9D8478192FF081
                44BF3C4345DB7600550749650780B6432F3D3F299BA9CB8D710DB76CD9A2D46C
                63D469E01008E097D8DE403F335D46425FBA18D235DBA56FB867C21A6F9C0A3F
                9F8A050B16701057FBE8D5B404BC8E76004CA2CED943D549E90B4002F0A697F6
                81A20AA5802347FC62766C4687FE310A385B17557A3B9DA967CBCA86E3068FE1
                383B8D4F7EE38C240BC7251063C15811CAA5D338CF20E59F5CC5C53F1549029B
                00AA14928B001C8E17D0E07DF3161C0083F5010EB2C6E4AA422DC4B9BFC4B9BF
                AF959ABA20B7B050318452ADA51C4D9B1A61B02E64183B8EFEBA6AAD83763C24
                80D3E77C010EE19AD9240096620D2ED64B59B030AD52DFBEB27DFBF67EE2180B
                B863C70E9581850534186550B925815081E77A673FFC9105AAE38B2629945E22
                216D681D3A7450892D65407E76481872DDBA754611E8377881BF49F4CBF3BD44
                10800C70074E96A098F6FDCBED5305481E02C8CAFA158AF52BBD8C19191912AA
                B65FFB6775A05F69DBB66DE35C982C2D2D3DF73C9ECB9CC2499BF149899BBD38
                0B7FCCA6BAA9ABEF2A27E24517A980B6813E2ADBB76F9790B08D7D370FE75FA4
                FE8851F9191C7D423F99AB0034090E047F4C5580AB02324422CD40509AE0C447
                EB56ADCEE96A01282C2C546290176528E07D852ED7DF13FDF20C2FB19C044035
                86CB2D362C2250670FADC75BDE67EA76C30A12915412002350A3A45CD152CB19
                6C37D9D9D9E627E3B9986E9D13E2868C4516AA5653B3FE14FDF5B57F236802CC
                5500FD2E38FF59F4AF5FAA1ACC763A87425FFF44F384C052B9DB478C18E12746
                180D833891C01945465A0D05CE46B669D34615AA417D4FBF31A50D5C7BA9FF4C
                E809D0D975208559717C4F2161460063C78E1523468E8CD93DAB5304A1583ECB
                B265CBC407FFFB9F71504A2A0240DBB9121F1F62537A3557C0065D7289E960A8
                1F3976FCB81A6C7781DC0CAB6FA6607FE5CA1D27F08D863F3AA8BECF9F3FDFD7
                5F514B87E909585058B848F31690B3D60B85C7424F9D0336091AF09215CDAC2A
                9B366DD268C944C3028A2F3C81C63D2810136FAAFCECCD9B3553A2890C310B4C
                BD64D1A2456AB5C1F357B9173F1A008632CD6692A097584E051833668C36CC33
                616A1A914788AA350B1F6154A3A8DD3FD87EB872AD58BE5C7EF8E187C658F8C9
                A502381C5C575F815EC9BC9A6A767EE8D0A15A6D7C8A20758B1D25AEEF3F7040
                427C5799A9D0817D99A9A846D3708F96B49D3B7796E86F415DD3BD52BBF1F82A
                F4D34BF30B0A4EFA6822CBE1B89F5656C23B69C7D11F85F445140984625B6C0C
                36C8C0836417168093888D1A36549F7EE79B5F44B1206D946910616070461DEE
                05868A7BC4D6A02FD1440260E0149A31270BAAAAC450D9723363D3C753A726B3
                04C03EC5A0854EFD79690844E938D8B3071EE52079E4E851F5C9E7E4A8CF80BD
                0CDE2B3C4B7AA6D761442F0CAE466F5E376AE921A8182FFBDDC7E974B653A681
                864483142BA85794BBB8B7A283CE0298CC0FC810E770F67F877FD291E75DC5C5
                8FC6E7F558831901D0D69ADE93D242FA2AB3FD607F0F8548EE53D1FB476B3FDC
                7344EB3ED46FA74F9B96B40440400A781E05FE99FE9D69CB728CF3000175665A
                83E1C822E0EFAC0FCED7F9591A0AB10EA3FF28F4B9EFCBDD27DBE97C407A62F4
                6B5E5B7D7151DFBEB239C40B7658E9154DBC1732B86CFA5A94F74FD6CEE1DF69
                FC402B43437EF623D04F2646EA1515B31768A2028CBAEC326570212A29025732
                AA50A5EF1FE935A2A01A44E579D6AC5923677CF249D2AA00846A3F4230DF6623
                96117D8B7E37B26E9D3AFECFE3991CF5530DB4C0670E718EAF8FE24FFBA1A6AF
                5EB3C6E86BC0485F0F171616FE452F971650C856D03BA631E9877E8CEB8ABD7B
                F716F5BC6E85414579E3578BE7F019D6AD5B27B8F461386F09EE7F4581CB657D
                0A344E2F50044800C3478C50E6CCA190AC6279B296CB6AB98DED3F37375705AE
                4D660920DBE1A887D231F8EE60FD1897C47BF6ECA99EA3DCDB08314168E51CA6
                B2CBCBCBF3B3DB41DF5E969696C6C1756FD06B3246A0E699B16CA41FA3B71EBD
                0DCBCD0744D8F1751C3A7850E4A29006EB27CE02DE5D5854F4768CDE43C43023
                8061C38689010307467ED130A8AA9D34DECFC1F9A3599F7D96D40440400D9882
                CA785D78037752C2EE83C1B549535F680C4BA27F3822A0DE5F5C5CAC32211B70
                844E7F2E97EB8B90D7821A908E9A7C0A55F90B7C4DD1675BA9B3F4B8F042995E
                ABD6390A0E5C1D30EC9B9D230DFBA74E9ED418F8130C659CD55D8C4AB926BFA0
                20E912359AA900970E1BA6F5EFDFDFFF99632C024779463E6E6A8747BB8BCDFD
                0BF2F3E59C3973925A0520D0B79AA37853B10DD10DA118B413C799C8F45C5D05
                3E67C03BD70CFB81E79C3D734642EFD738A7665829610C8FE720FE3F8DBEE5B7
                766F4A38394E67833229DFC71FC71ACFA17751CF1E3DCA99195674E4E74C26BD
                FF0218EA18CA7A3D486176A25F9419CC2480C14386981A4C8543B28EECC95AAE
                7060024C46AD4A760980703A9DA3515086E16BA01FA3844DEF40E3CA59242A01
                67FAD77DFDB5F2DE358095F2695A4ACACD798585C7C25DC3879CECECD67432C0
                AFFB1A479DFAF5EB6B19D05BC05CE5D730434D02721F84C4427EFDCD3772FFFE
                FD4653504E5CFC010CF54BE827A1AD8B1204330960D0E0C11A93A88824198123
                984C4C2A3B04E37E45249D224892F3E6CD4B7A0980403B6248393AC83DAA9BF0
                F278F3E6CD25246C4D0DAE01D292E9246080A47DF8F0616DEDBA755C96F7F3E4
                C5CE9AD4F4F4715093769B952724E5F7CACE3EAFCCED66FC353F45976566DC40
                7A34D5AF6FF08D0931EA4BB75B852462A6D253A7FD1D9BDC6EF702B0DF84DCBC
                BCA4F0DF36839904C0FC897DFAF64D68B9AAEAA81DCD72171715294797AA2001
                10185C1B949696CEF03ACBF950071200337233249F6630E70D250DD00E879EB4
                3B3D227FE099CBD25253AFCD2B28D8298220EC5B4061991CF325EC32AC915F68
                164E62D07D98AA018310D6AD53C7B3D2E7FD3B3B3DED99C14E6A9D9FD985CC7C
                08706C6DAD5AB50681002A1C0B2D5E302300EAFFBD7AF78EE97D93B5832753B9
                4A4A4AC4A2850BAB0C0140E76F863EB504759811F837D66B83060D445B0CB090
                B2951F8D4E064A64C2339E8414CD20BD14F5E9DE1BE0424CF0C0C7E89F0FE687
                E8FCFA35C317383BBB09EE7C3F3AF44328A18AEAE317D218224B7A5A9A96969E
                4E3D461DA71923747DE5D5442BC130DE60B4F8FB015ED83F13FD7282C14C05B8
                F8E28BB5EC9C1CF55544269A274C04D755AF44DD3F9ACFBF6EDD3AB964F1E22A
                A102100E87E3F6144D7B53B7B7510F63D23F68ED472F5AF4298F393D803EA595
                A23F9D2D2DF5390AFA996B4B790027BF88F35F46E73F14AE2C96699C71C7701F
                AE61FE0237192298DD3442506DA07DC14E83F51F0863151E740CA4807D097A2F
                21612601F485FEEFF426514D164BBC7030DE37D6968015295745CA1D786DDA92
                7C658C7597C4124096C3D112E5FC141DD4377B4C759AEBF514E72306B36B6BDA
                626CCF815C961414165A8AD759E1B70322E0ECE5443CC45DD89CB46CB2FA9639
                C1D1F1FCF3D999944DC1F4E9D38D2E8F65D0576E87BE9254198174981140EF3E
                7D949B73BC914CE2773294892B4ACB972DAB120480D1FF3674D0B784579DA688
                3F71E244B5768FF28AAD5BB618EDF64343AA273E82BA7761FB3BB6E9052633FD
                A110F15BF366F7BD1885B80C8518890B5D40A900454AA7F4223C5E832ADB10E7
                093A76EC28D1F935E62A4B8558C3B49A2B57AEF4CBEB8E739741EC19BF2637F7
                40A4E58A15CC5400E8FF5A6666A6FA2A2A20B21AD6C4934A048FA1D79FA5FB47
                BABF7EFD7AB972C58AA4570172B2B3A9FBCF441107E82A70AF5EBD34A8920C82
                2BCBA02E1F3878902420B76EDDAA51BFF765F1F134B9B3D8A53E7D060FFFADC6
                24299AF6393E57161615459479266AB4ED74389AA050E7A3903D504886FF5673
                05DE2825CAB1889386DC52BC9F2720F27CF0C107C6B80267410E93F2F3F33F48
                F4CB2AF77C261200833AF4CCC8303DDF8A881D4F11BC32A279ACEE5F5975413F
                7FC3FAF5CA2128D9250010C08DE8D0FF12DEEC52D4F1AFBFE10625057022CF8D
                ADCCBBD181C7F84CF83C808DE1C5BFC6536F71151787D5EF2DD5612C1E149D85
                09401ED2AF4F7D9F9E737C609D04B8717693AE9C458660A378C01538EF324801
                4723BC7D4C60460059D0FF0363AF271B92515D8876B954B8EBD5AB8D87928E00
                7272721AA2837F8EDDFEFA31B61F8EFE5C2D2B33747E0E8873E6CC31A6E3230B
                301F42D46364C6A47564391C948BE762F30527EBDFBFBF3C1F2A80B7F32B6F28
                7E1E3F7E5CFBE8A38F54B003AF37E0A9B4B4B43B2005FC2716658B14662A40DD
                BA7535AF556452180255745F7A4DB5ABAA37A2BECFD5A693274F1A67C4934E05
                C0E87F7399DBFD0F8DB132A927A7A76BD75E779DAC5FAF9EE6EDF82AD807F7B7
                4005580195467F1E7CECC0335D8EE7A954F66033C44A02603290BFE0E2F7E9F7
                60E4123DC088510AE0C6C408F45B36E02B9C3712524044094863F44CE524001B
                498BA492007AE5E4D445C7A6138ECF759492233D49CB38FA9796FA467F3D8047
                40CEC0BF42957E3016017262261F663B9DBD21DA7C8AF1C5976A988633DEA8C0
                9ECE9F96A63E0F1D3A2466CF9A650C597C1252C0A4BCFCFCA47881844D00550A
                49450018FDAF81EECFD52DE5534F9BFFD1575E299A3469E2E9F85E02A0ED0C5D
                E331FA9FFBB1943B535253C7A2F3E7C5A26C312300A7D3998AC23312EA5D9EE7
                90B255AB56CA7B8E9981B83A40238714AA022084254B9648E87246316E09A480
                E19002CA2A5590683D8F1D16BC2ADD3F69540066C742E7FE92AE237A19BB76EB
                26070F1AA461F4976E88FD0CFAC9D97E06C761E767D250DF8A8CA6BD8EFEF1A3
                FC828298F48398CE102929404AE6736FEA79164D4901347C085403B8E4316FDE
                3CA31450EACD3C34379665B40A10C0007CBC21BC2C9EE4E01A3313BEF8BD5FD6
                3F23352BB3EDBA75D53E4F388B06487B0C4E3A0589404BD193515B92828C2D80
                CB4A0F8100E624BA2018FD991A8F92631ABF73F41F396A94680E95D838F1C76D
                C78E1D6A52DCB79A21E5410C90236335FA13312500A727B6000320DCAE1F6BD5
                B2A572A1AD858A301200970669CD45672103BE801430065240527A08262B9C0E
                C7CDE8EDEF198F314A73E7CE9D95EF468ABEF4663C018D8E8D90D167376FD962
                D441F5BFDFEC2A2E4EAA89D9640746FF5AA8D3CFB0EB8B1D4F679F4B060DF25B
                F2E3C6818FCB7E7EAEBC9AF64F8CFE7707FAF04713315F238214E004A32DC356
                8F628D9E7908528066580D502B0368741AE397735657F32C14BB53D3D246A102
                16C4BA9CD505E8FC9A4849791975F7235D3466A373381CAAAEA53126A331608B
                779FFF7146BAA4A44463AA2A9F78AD69AF404E7D002420232E5C0D438ED339C2
                2D2597FE54601DA8BE1AD3EE356BD64C9FF1F7CDFCEFDCB9333073CF090C8A03
                0B0A0A5C952E4808C48300681DF826766FD58F510A6082C4F4801501B6B3E5D0
                81366FDA64BCC427E9E9E937E7E6E525558CC064050880AE632FA332EFD38F31
                D8047D1602D7DE033D33F5EF6C84CC4CC30430863FBE4A8730574949D2846A4F
                6640F4AF877AA4C4345E3F46098C2AB0F44A5BBE75FF33675462DC3DFE813CDE
                419FB80B83DF995896332E5622687C7DF0D4CB8421161A038DD2EF39CD2BFE53
                1FA574C0B980850B171AAD034FE1F895C9162538990112B85D78ECCD1558B794
                0298E885465981A9A3F48ECFC6C815192692609A36A39B29CE9802527827D1CF
                565580818F93C6CC6CA50C456804C718925C0E27C1AA893FD46F2936A636CBCB
                CF37D6F76906E68DA5EEAF232E0480CAA0083415BB138457F444E7D7FAF4EEAD
                B29B7897037D222A7D04680BCDDF2A1F014D9B8A736E43259D8C4779AB3A9C59
                5974DF5E8D4EDBD568DF4FC3256FFC06158B8E196A286D52FF44C797D03F55A6
                27AA60C23FAACC7A10CA45AEA2A2239197AAE600A27F5DE976FF1BA2D2D57AFD
                D31786EEE3FCEA13FD4B4B95BB3CA31AEF3E37F3CFBA9F8EBE702D46FF984B5B
                71B31305090C465BE2ACACCA8FC651A977AF5EA205D481C015013642467831A4
                493E8AE36351218BE355DE48808E978A67648EA6EEE83007D07BB6A0D354C2C7
                3372643B1C23A567229079E3237DCFF4AED985E7B9B1B0A82821758F3AAD8FBA
                3C1FE56886BA5D8FB2EC439D26F56A447676F61065032344437EA7C4E5D5FDFD
                67FE2105ECDDB74F453536ACBE9C5061F10B0B97C4A3AC713514CFCACA9A8B1B
                5EA67F673044A6480A240082EBA1866CA6A4C50F2009DC5CE87225E5CBEF9593
                53BFCCED7E0C0DF5C7C2B3EC49265F8606FB08CABC3C1165821EDADF9B3FBE4F
                043F67BE47FAD83E50BC766DCC45513360D018804EFF47EC7209966DF5202723
                5353527E8FC12021C41A0E202C2EF7BD8FED3AFD18B36D7BA347975BFA63E70F
                088E3B17047745BCCA1B5702C00B1D8156350D3DA381774540F6E9D34725380C
                5C113878F0A0E68DF3A68B4687B03BB1A8B878513CCB6C05E8FCF5F032D9D1A6
                18033D7ACB4E6AA7345016ABF4D861F6A9F037E62474050D714E628722BF3B66
                650CFD778E040CA39D1A502E36DAB7D3D2D37F9C8C13C30E87632806AAE9D86D
                A2D72947FFA64D9BFA66FC75150092AE84F87F6EE65F886368FB57E51716CE8F
                5779E34A00991919E9A89C19E8F93E86A314C019EAB40057618A4D4CFBCCF4C8
                5E70446580D21BC1904935130DD6FF013E4800B52B7B2D1B96701AFDEAC790AC
                DE4C74418CC87238B894F55F74AA6B84B76F31012883C7BABD1E7FFAFA3F27FF
                5C2E57E0E83F1B6D7F3CA41B4BD17CA281B8FB8A66F4EC3906FA3F9747947E44
                4667BC80C68D1A95330C62E52C5FBEDCB85C7500E7D325721986B58DF949A00E
                78933DD0DA31473FC6A08EB4AC33CC61D8A8043818D0679E41650D28484D4B1B
                09113AE149647A399DA978D35DD14A07A22DBC804EA56261B06D0F1830400D72
                81863F0C94BB7ACD1A63DB3E5A5A5A7AE3DA75EB66C5B3EC7127802C4EEA48F9
                312AE7325D44224BF6E8D143051665E76774141A0571296AEFDEBDFE33D29A76
                160776820056E2E457A10F2E872818D3B5D25000015CC7200F28975AEEE1CCFA
                9021439411CDC68D1B4D0337D6005BFCA8DD9FA775EDDA55EBD4A99358BC78B1
                3C73E68C7E0EDDC66FC368F961A2DE3D2DFD18DD076AED7D20808B51B0F3A427
                22966FE5A565CB96DAF9E79FAF8C7F18054BADFB9796AAEC3D34FE313CF35C10
                DDD58571CE8999906811109526E0C6FF15DE4E43672086D76ED4B0A13879F2A4
                0AF0C0D9D14043151350477D1D9DEE0F6B727313124C14E23FBDBC26E9DFB9D6
                CE3881B4AB5FBA74A931E6A1024733125EE05ABC0DA1EA8C23A3111CF9070D1A
                A4FC17689C441B0503DE853A786B856E1225F4CEC9698111FB51B4E1BB85218F
                A619D8C75BB668A1A262D107E3089E339F3931CF4988A7D0D66F282A2E9E11EF
                E7480801A0D33045F234CE8FE8C7E820440BC16FD7AF5724500170926A06AEF5
                6B8859C7A5278D795C9042C3264D9B8B7BB7E7772E6D32E601DD3CF5048D9BFC
                AD1A5503B8EF473F529F36FC41756FFEBC797EC7683DA727A6A591127DE50D4B
                66DB314A5C5EC688B871023B33C89B52ECAF85C7CACF3293F39D5FD0BDBBB2F8
                3346C4469B9DEF1DFDE36E6791B07851D9D9D9E3D161A90AA8753FCEFCB33C86
                5CE6AA6C5C29C088A9560A5857FBF6EDD33831988C2230C39D8F1D3B56197790
                00504E999797E7F74C6C04F7DE779FC4C8562544F078DE9F51704800FA71AFC5
                A87AFF2400BA8F7FFAE9A71AC36727E3F353B26BD1A2856AC7B465E1FB877AE8
                778E77995BAD02788FB9D1C6AF2A282C9C99887E9830028014C0A5A94F500143
                4D0B86BAA5384DCFC1468D1B2B35415F26DABB678FA0D350C00C6AC2D1BE7D7B
                01FD5F8DFEDC8E41D4A37BE771831A4002B8E7DE7B132E0104FA05240318196A
                E197E72CBEEB43FC67CCBC0610FF4900DC162F5E2CB66FDF9EE8A2FA81937C23
                468C102DF1A9405B7F88F747A0CED0C3EF1BAA2D41D459F481452085092080C3
                15B865D490D056E0743AAF460D7C14580EEAC78CB99F9393E3F159A7D8C5F55F
                1CF738A669E2243AD5ECD9B393AA3150F7E7A613C019AF8B27433DEB60C7BFFB
                9E7B946E6B05F489A08B28E712584994329A356FAE3A4375C31274EE254BCE19
                C051EAEB77D145CA755C2700CE03704B1690F4478F1E2DEAE27D4A4F587215E4
                D3EDDDA7BA52505020F27273CD5685C80AD7263270496209202BAB016A603E0A
                D1CF285275EBD64D5E32689096EEE9FC9EFC499ECEEFD9F71082DCB77FBFF6E9
                CC999C3CF2FD161D443668D0C0370B2B03B2167BF67C6EB0E5FF1E98E1D8E032
                EBE73E8BAF0C68CA8EAE97FDE2FEFD45B7AE5D55FA262F094834568D168D4615
                E0EEBBEF9668302183625244646C04FA45ECDBBB575D8FC79926AA69D3A62447
                D9332343A58F0A759D30FB49959760E1C2859A37C187AA2B5AD08150253ABE52
                0198766EC3C68DDACA152B7CE7F038DFB9F13AC65978E3BE080C80CAF6642CD3
                B9937D59783543198F1D3BA6DEB9DE161A366CA88D1D374EB468DE5CA2C3FBF2
                12B068D26BDCC37D065CF96AE952B961C3067F15448855F83A026D2461497113
                2E0766391C0FA12EFEA497851D64E4C8918AFD35C3A8AF8258E89280BE31AC38
                1A03F46CDFF538D33A6AD42875AE918903D9999DDE6D382603CED3D9DA6DF85B
                E0319A711ACD953901C811411FFDF9B97EC3068117EF3B87CF77D7DD77875401
                3867400791A5180DBD1D5FE8539B9AF795514AA2B4310275555DA4812F172C50
                2A930E0C04A23B3635FA7BA5004A7C9C08D4C1FAA6A4E89D9CF3D58DDE46CC8E
                19DB8FDE9E84899469943CD95EBEF8E20BB542A5831EAD247D63FB09D6B63827
                C0885786096EBED08731FABF94C83A4F0602B80715FDAA6E42CB173A78C81009
                9D5FF3BE18B57EEA7D2152F31ED7A501CE03CC9E35CBB73E8CD15FDE3269928A
                33E836B0B1DBF38634B7CED26EB79A8421730B4FE7F69C1BB0AFB3B8DBC0E8FA
                390CE0A04F4832B6E1B04B2FE56A862A8B2E016CDEBC5963EE3AA304F0C3BBEE
                529E7922C80809C2903367CCD04E9F392D642D290F8F38AA1DEB775C686542D6
                2FA8A7355CDC50A41E4E51D7637499810307AA188B81D7B1B09F341200EB67FE
                FCF95AAEC738463D5BCF9E3D45A74E9D7C12006D2C76EEDCA97DB970210D6B7C
                136F0C309312D02E52022446EE1BCF51F5656C5B299EFA4C31B639EF35D4FA3D
                DEFF7BEFBE2B2105A8F2B22CA3AFBC52A3FE6F6C17D2D88EBC6D4E7AE6045402
                531298F7F978997B4100AF27B2FF259C009C4EE7EF51238FEADF996D87219343
                B1B57123A3722E804B443A6EBFFD76E57FED0E18F98D2C1D38EABB83480141FF
                8EEFF4E1DEBD7BB7BA276777870D1F2EDAB46EADC23B31C8C3696CDBB76D1345
                C5C5BEB2318F000820A804409DF1C30F3E50D161DDB5DCE2FB5FEE140727E8F3
                431C5D3451AFA0AEE8F8583B516B9767649C3C79326DCD13FD2A2B05D6E9DC39
                739479AC0E4A381C106AA3F3A77B5400B10BF54D4941F79D674C097A95961BB9
                03A480C07653EE5860FB32FE1E1BE762FEF9CF73C9ABB9D4AB747FBCC772ED26
                8854C981C0E59F04E70F852ED76389ACF7841240566626C9F515D4C4BDFA319A
                0577ECD831F4CB32BC3076983973E78AFDFBCED901DD78E38D6A922D280158E8
                FC7EEA83F7EF81D72B282CF4C570D35D3E3922192701B7434530BE7436E25004
                4042210190D80E5D7E586C7D7EBB301B449B7CDA5874FC453BB53F7CC408D1A7
                4F240E7FC903BE0366C3293190257D44DAB76BE737094889CBE82ADEB2654B7A
                3D96EBB081EAA3668104FCBE075C8F93B0FFFDEF7F7D65638C4566BBE22475B0
                0E1FD8AEB66EDD2A561B331849F91A8EFFB828815196124A008ECC4C8AE42FA4
                A5A63EAC8B7D7CE99D3B770E2ABA051E6747836EA5BC073D752AE58D37DDA471
                D40826BE7B34008F0A60FA77866B0E32A9E3369C0346D73822E965BF142A4087
                0E1DFC260177EED8A1E51714F8CE2101FCE0873F0C6A07C089BFE9D3A6A949C0
                ED4FEE1407AE3B207D8A3F2702BCFBA907D264E6A517AAFD9C5EBDE4A851A312
                BE0E5E99FB53A50201682400FD782FE8F6E7B56DEB370908C94863C428DFDA3B
                2400A80A3ED53025C4A4B1565E4D38F777C3BE991A4169EEBFFFF98FAFBCF4EE
                1B3972A42A9799CA68A64A6EDAB449E360A097BDB4ACECCF28D14F8B4B4A1216
                6731E12A0048E0A7A8E8E7F5B270F4A7E8178CB503999A79D5BFFCF24B5F4A65
                8AFEE3C78F57E7846364D3D1DE446A700739C6D8853BCF792B2AAF2F4E42EAA3
                3F1B0D27090B2129E82001DCF9831F049500784DA64DA788BBFD1720801B0F08
                3309206D5F9AC8187E81DAA71935D7A1AB32F86E3E8724576C9000A80E7225A0
                B66112909370F412D5711E24AE4E9D3B971BF5CD2481C0C93D61553DC0C6F2CD
                9831C317AA8EAA1C437C31C49AD5F6C5E54B4A01FACBC4DB7C04C75E4864BD27
                9C00B21C8EC1A8E085C26B52C9756E1AFFB082CBCDC606BE60ECB34170365E07
                8F356EDCD8F75D06097C19ECBB3031250EF61B767443EC42D5609DD8F415006E
                740A2A293997D28DCF75C79D770625004E6A4EFDE82325721E1A75C4A302F88C
                4DBD04808F2633A1023CE95101B812C099F0AA0CD62945FB02C3BB64EA753A01
                E9E23F49C0053235122A095F5F0539B7E227CCBF7B0E863E27C477FA2918D7F2
                B90AC0588B7E1DDF6CD0C0C6018A3621B462F48226EC974222884BE49F604806
                02A88D8AD8885A6AAB8B60184565E74E9D34AF9E6F2AD2719FB3ED1C0DF06292
                C214945E5F43870EF55301D6AF5FAFD181C5B80A30E5F6DB83AE02704E63DAC7
                1F2B51B7ACAE5B6CFDDD7679F4D2639AB26050DCA469B5B6D6129D1E6E2FEB6C
                A8A344D05B264D921049ABF42A00F7172F5AA4AD31AC02D012B47BF7EE7E2AC0
                229C432FD168AB2091EC33AE22A53E3DB662509511FB9B366F5699AFF4737019
                26FCEC5AE872F932E12402092700C2E170FC1F06B9C7BDD16BD4C44A46CF9E2A
                5E604A103B00B22EC5C5ED8675F844839207D50F4A05BA1AC08942A3B5621D12
                C0942921ED0098EF9E2B1B2483D2466562CF5D7BC5614803B2B614F557D517AD
                DE6821EAAE578E944AFCA7F97175F02EA4F7E4EA55AB7CDFD51A3F242A5DFCE7
                684F313CD0633091E024259D95749533D00E80ED74DFDEBD62EDBA75E79C98C8
                0B42FCB6A8B8F8C944973F290820DBE96C83CAFA0ABB5DF463ACD04E1851DBA1
                11782D027D1BC5636613DE1F98BD26C16023D5978648005C0EA48472D0600A4C
                15800450270401B0D13026E22A83518C19A81F4FBCEA2AE1B5068C2A0245E178
                80DE802B969F0B9FC8A54D8EB0B5BD04A02FF9EAC651C902465AEE71E1856AE5
                C928F6D30290E44F8925C00CF8BBB4D4D44BF20A0A76457ACF6821290880703A
                9D63516BF4AD6F6214B5D0B86513885AEC309C793F7AEC98C6893F29FD4D7471
                3AA3D6DE0BE63D514EAF8F61E5E1BE2CF3205D35E9D7AF9FECDCB9B35201186A
                1B8D5A63C3D59F89043079CA149525468431055E5B522256AC5C294F18CC4F79
                0D7678CE7C0FA2B9B447FFAD16A6C034AC627A38A3BA3460C000D9A44913A502
                6CDAB449428FF689D1A8FCA5F8B835AEEF3B2585CB37AFE18E43B4732CA9CACB
                09C1860D1AA8D586535CC6856A0A6930507D38848F5B21FA7F1A97425B78A6A4
                4036B3097B826A7245A022562D7CFB4B535353EFCC2F28585F81DF4505CEACAC
                9FE083655632382DC3680F4035801380345336365012C06D93275BF206E4EF38
                69B405D761C2148E228D9B34119C6BA0BAA14750AE2EA01520D5001DEC2F9C68
                E34420498F9384060F50B7E689B8FCA77897136DB53BDECD3FB03B4854AC0F1D
                800AFB2808E2ED5865FBAD2892860008546C1A46F92B318A3F0D15C019AE7CE8
                5627D008A6A2527F055D7B93C5DB441520004EBF33DF416B7EA7EAA20705A1F8
                AF5B0AEA2001DC7ADB6D0977074E46D0FFE12B030110B4F4A31AA007033188D2
                BBBDF1F30B125156B4D5CE687FBF01115CA379735D8400ED4E5CA929294FA1F3
                CF4299E316F4331C928A007464391C1D5151B76008BC1995DC4EF3845C4AF58A
                5167717C3F7A9A0BC7FF86EF9FA34213161E1AAA4B1ACA4313B16BBC8794C8DA
                A14307B176ED5A25CAAB830615E0D65B6F957542F802C4713FA9EE9F979BAB31
                2680510564A0988C8C0C8DA6D154A90CE77F84BFDD14CF08BA81C8CECEA6D27F
                190A750F9889C9171920568F095886E347B0F3BDCAD42CE5FBAEA2A2AD95BE69
                94919404A00344C08E9FC5CC30A8D3A6A0D1527CD2F46E83969ABAB6B0B03029
                C2EE6234B8142F9E3EDD61551712C0A45B6F559F56A02693A04E308B0C574128
                F6531C4EC4245DACC1387924000B38887AB81A9D7F61A2CB4CA8D4776E77065E
                4A37BCAFD618BC38281CC4FE16FCB9A8A8B8386953AA55BF56940028D545CAE7
                B0FB3311A64ED9F16F9934C91201702291D6635C16E4C427D50B4E34753CFF7C
                65275FDDD4081A742D0B4F00940EFE88BAF8452247FFEA029B00A2845E39390D
                21EEFF1144F0C300C311EE6A4615E0E65B6E09BB0AC0B0E85F7CFEB9D8B76F9F
                A9214ABD7AF5E4C851A394FBB4A8262A0008C02F2048E0337BF7DFC0E8FF3374
                FEA3897EE7D50136014411CEACAC3A68A357A64879A34C49E172E63A3458E6B5
                BB483F870470D3CD3787940038F33F67F66CEF8CB7141D3A9C8194C144239A58
                BBAE8ED8BC99098834B5364EC3A356AD5B27FAD1A302AA00CB97FBA5513C833A
                FC9276A09ADB7DC8EDC9BA33CB555C7C2AD165AD2EB0092006706666325C783A
                86B793A8E0A9D89FA8FF8D1DFFC69B6E0A4900B486E38C3883460D197C543CF9
                C4F7A279F352E53D72E0409A78EFFD16E2DFEFB6109C5FA431D015A347C7C418
                281254666E827E000104409B8EAB7045CE0C9E7595942497055035804D003186
                D3E198460230AA002000A5029889BAB4729C396386726F6EDBF68C78E79F1B65
                AB56A5DE73A8FF0A9C93229E7EA69D9C3DA789FAF9B8F1E365DBB66D13EE0BE1
                7DE48855808282026D8527159C7E3D12C0F8A2E2E2B825CBAC69B00920C6D009
                40FF4E02B8E1C61B834A004C1831C76BEE3A65F25EF1F043E6D6A20505F5C4E4
                DBBBAAFD3E7DFB322C56A21FB5D2282C285026D0069C001B8C77D9041033D804
                10639811C0F537DC109400E82F4EBF781ABCFCE6D7DBC5C409074DCF3B7A3445
                0C1A92A9F6193B6FF09021897ED44A836EBE2B6D02882B6C0288319C5959D3F0
                E153016A9300AEBF3EE82AC0F7DBB78BCF3FFF5C65177AF8A19D62F26DFBA4A6
                093F1580FBDBB6D59263C77B2202317476FF0103AAFC2A80ABB0506354605B05
                881F6C0288317402D0BFD3B30D04206A079100B8DE3FEBB3CF542A6C47E609F1
                F63FBF13E9E9FECE2EB486FDFB1BADC46B7FF3CCFE33200873E85575305C5680
                07242D3CC7BB8A8A6C0288116C028831CC08E03A1240EDDAA6E7D3F26FD1C285
                2AD211D325DE3E658FB8EFDE3D42F7FB61E75FBAB4A178E297ED411669A261A3
                4662DCB871D5C228A88804608807206C0288396C028831CAA900E8F8D75E775D
                D05500EEEFDDBB57CE9F374F25C14C4F77CBA1438F68A3461E11B5D2A55CB9AA
                BE367B4E1371E850AA0A8ACAD4D9DD2FB82029222255F6FECCA2C425505B0588
                1F6C028831CC24806BAEBD36A41D00A500A615E78458B054E9F409E89991A166
                FFAB4334208212805FD86C5B0288396C028831CC08E0EA6BAE09EB0B4012A02B
                31ADE3180B400F27C58EDFA0410391E970A8D459D5A5F313C545453601C41936
                01C418662A00084025F9141666CCF9BB7DFBF669478F1C51A9A6EAD7AFAF3129
                45BA6766B05AB9031717176B6B4000B60A103FD8041063984900575D7D75D049
                C09A0C0679655420036C0920C6B00920C630230006F2ACA90410CA57C02680F8
                C3268018C34C05983071A2651580E9A50E1F3EAC028B72E29CF9041A366CA822
                E584FBAD85FDA452014A4A4AB4BCDC5C5B0588236C028831CC24800913260435
                04D2A1E2C9EFDBA726C6380948DF00F609BA0033DE608F9E3D45DBB66DABD524
                20332891000CB0258018C3268018C34C02183F6142480980E76EDDBA55AD8963
                E4F7AC997BCFD1BCE7A4A6A54987C3A1317D16135B8A6A2001ACA504E089A26C
                4B0071824D0031869904306EFCF8907300070E1C100BBFFC52D900488CF0C72E
                BC501C4147176565A2C1FAF5A2E137DF8894B3679544D07FC00065065C1D6204
                AE5DBB562D7B1A604B003146D56F35490E3302183B6E5C48536086C6A657203B
                FF9E9123C5EE2BAF3C97D492B9015C2ED1FEFDF745EAE9D32A99EAE5575C6139
                C86832631D09C0901C54D8041073D804106398A90063C68E0DAA02A874E70B16
                C813274E68C7BA7411DFDD7FBF848CEF39C7930D87891145CB79F3E4799F7DA6
                8E0F18385076EAD4A9CAAB00EBD6ADD31815C85601E2079B00628C400980892E
                C78C19135402D8B56B9758B27831A4FD32B163C204B16FF870D3F36AEDDB277A
                3CF38CDABF102A02938456757CBD6E9D2828F0CBF3614B0031864D0031463902
                A8558B12802FA77D2076ECD8A15400AE026CBBF1467170C000D3F3524F9C1099
                8F3FAEF6BB76EB16F588408998538004A0A202196013408C6113408C11A802B0
                E35F39668CCA792F4CC4622EFD4102504925F70D1E2C765C738DF4F5465D05C0
                47836FBF955D5E7D551D776465A9EC39C6EB58DC0FFAF74478037EF3F5D71AA3
                02D92A40FC6013408C6126018CBEF2CAA02A00D7FBB902C05C78671B36149BEF
                BA4B9CECD8D1EF9CB42347448777DF55AB01EC27C3478C5029AAAB3A98F2DD05
                0230C09600620C9B00620C5302183D5ACD0504C3FAF5EB55886CE24CB3666237
                CE3FDAB3A770A7A68AFA9B378B960B16A8E540A26DBB76A27FFFFED52253F037
                20349B00E20B9B00620C3315E08AD1A383AA00DC292D2D95F97979DA962D5BCE
                89CBDE7334C3F90D1A34D0860C1DAAB204896A60080402D01813C05601E2079B
                00620C330980EBF6C1260175D0FFFFDB6FBF151B366C1067CFF8E7C3A0F9EF79
                6DDB323B6DB50805A683CF4B0230C09600620C9B00620C3302B8ECF2CBC31200
                C1393F260AE1D2E0D1A34799645E19FEB46CD54A2509AD0E62BF112400FA3E18
                6013408C6113408C61A6028CBAECB2902A401CF793EAFEEBBFFD56A34BB0AD02
                C40F3601C4186612C0C851A32C490056501D7C0074ACA704000230C09600628C
                EAD37A92145920002D800018C73F1A04509D3A3FC1D58F129B00E28AEAD58292
                103A01185580112346C85AB56B275D58EE442707DDB07EBDC69800B60A103FD8
                041063044A009CB8CBC8C8A03F7FA28B9674D8B37BB7328536C0268018C32680
                1823700E80A86EA27BB4C0558F00D8041063D82D31C600017C828FF15521334F
                12DEDF9E0388316C028821D0F9D3F1B110DBC04497A58A8269914800F3125D90
                EA0A9B006208E8FF4E7CCC41259FA71F8B96F86F222EBBB1317D503CEC003881
                E1178D3416CF85FDB3B8EE552080CFA272711BE56013400CE17038AE4ED1B40F
                B09B4AB1B64993265AD7AE5D59E99E8EE431F18FC898E6C8912372FDFAF53E91
                191F25D8FE4F2311E89D918743ED87FBBBC9BEF474FC27B165EA227BF7EEDD65
                A3468D225F05F0747A752766453E74E8904F45C0B11B8A8B8B3F4CF4BBACAEB0
                092086C87638EE404BFE87FE9DC13B9D4EA7A7D2C38C98E146549A06CF9B6790
                8CA5FC0AFF8F7415179F8AE533391D0E061F9C87025EA21F1B3972A460AE8250
                309158024F506CE072B95462545F3D4879676171F15BB17CA69A0C9B0062886C
                A793EBFF1CBDD49A1FE3F90F1F3E3C64E7B6224AF31C769235C62C3A9A361B9D
                680CC46519F6029580332B8B05A4483E5A3FC6684424B7B09D5C842602FE6DC1
                82052A168217A578D6EB0A5DAEE9B17CA69A0C9B0062088C963DD1313FC76E7B
                7D66BB77EFDECCEAABCF7297138BF589701142743E7CF8B058BA74A98414609C
                35FF053AFFEFE2F25C59593FC72D9FD30B8BD15F0E1E3C58A38352B8B27B09A0
                DC1C049F61C3860D817901B6E3E33210C0BAB8BEB81A049B0062087414BAEBBD
                896D8A7E2C2D2D8D73032AB5776054A070A3BF1B9D67CF9E3D2A7B0E7307F820
                E5F7A96969A3F20B0AE2D251B2B3B27AA28F7E8102B7D38F356BD64CF4EED347
                B46AD54AA484798E4029E0F4E9D3CAED997E007A1A74551F42BCADA5A4FCA0A0
                B0B02C1ECF55136113408C013520DBED764F45E7EEAA1F63476FDDBAB58AE6CB
                0E53A76EDD909DE6ECD9B3E208747EDACA6F86E8CF0E6340694A4ACA13B8E60B
                2080B874143C1389EDA7E8C8CF0AAF7A4390D03A4115E8DEBDBB68D4B0215398
                07BD06C9ECD4C9938AD0180968F7EEDD812B001BD35253AFC92FF40F116423BA
                B009200E802430011F6F606BC9EFBA88CB89EE468D1B6B2D5BB4102D5AB4900D
                1B35D22821A4786D648E1F3FCE915EEEDDBB57F3E6070C349671637B07BFB93F
                372FEF443C9F29273BBB3E8AF0176C93B1A518CB455767C6286CD9B2A58464A0
                3186019F159D5EE3087FF4C811B977DF3E6DDFDEBDF2C891234A2D08F027D88B
                1FFCD0E5727D92E87757DD6113401C8011936D7B0424817FE22BC5E64AD73BD7
                C831F2FF352535F5E7F9F9F9A72B7BBD480012A88D4EFD3BE976FF08CF975EF9
                2BAA3981EF5353536FC7E77C4834319DD0B46113405C91E374B6428B7E161DE6
                168C7091C5F292184885C805013C555C523227D1CF44383232AE80AEFE341A53
                1F3C5744E98AF13C274168EF4194780262FF9E443F534D814D0071064860A292
                0434AD494436F41E439F7FA542ECC7C87F3CD1CFA39E09EA009EE96514F0361A
                0A45E80B7088237F4161A1BDE41747D8041047401570A2A1D3B18541FCFDEA9E
                71023889A6C7F9636A304EFE71C2CF64EDFC2C8EFCA9A8A8E8E7897E26222B2B
                EB7778989F60D74F0D60DFE6337132D0F85C7CA63301814E8547FCDF0F296004
                48C065E9C6362A0D9B00E20474120601FC3776AFF326F881D49CA226C9DAB56B
                A7D6D2D151784C0D871851B5B3A5A54C112E77EDDAA5EDDDBB574D020A7DDD5C
                88C3B8C44097CBB536A1CFE57064E06196A1508DBD87D42460CB962D459B366D
                64DDBA75B5744E6CE259F9D04C79066253360CDF7FFFBD3C70E0803AE69506F8
                7B1A4EDDEA2A2A3A1379A96C58854D007182332BAB395AF92674026533CB1191
                CB809D3A75F28FEEEB35890DFC7EF0E04165267BECD831FD2F74FE79041DE54F
                897C2E10C04FD0719F175EE7A0060D1A2873E7A64D9B9633790EFC4E6960F3E6
                CD6A1990FBDEE73D8A733AE3B9F627F2B96A0A6C0288134000DDF0B15EFF4EB3
                E0C183072B113950C4373397E53186CD66C82C03FE84337F561463F3DF608054
                C3EEFC47E111FF15323333C505175C606AD464768CAAC092254B8CE6BF443710
                C0C6443C534D834D007182C3E168812172337A01D7CF655A5A9A86CE227BF4E8
                A17925003FB3581160424B1560D5AA5546F35F4A003F2F2A2E7E3EC1CFF5080A
                F43BCD3BFB4F55A65FBF7E4A051001A6C081710331EACBAFBFFE5AC501643624
                CD93F8F4381EAC537171F1BE443E574D814D007102240086017E0FDBB5C6E3F4
                A2A3230D2D02EBD5AF2FD24006ECFFD48B4F9D3E2D0E6364DCB66D9BD8B973A7
                3AE68394C7B494948B0A5DAEAF13FC5C3D5096D520B606FA3195B9E8BCF34487
                0E1D4463483A7520E5F018FB772944FD13C78F2B0B403A34D1AB31009C039864
                CF01C4073601C40139D9D9A9E8BCADB03B52787C03CAC504A714A02401DD4F1F
                6087A76E6CB60AA046DD94945F15141626D458C6EB1DF834B6C784C92A009F49
                4D6C7A0EA867E333F9747E7F9CC16F7E80CF79F8DC63FB00C41E36014411D94E
                273B404B34F836E8951DDD656559F8CE59F2AED2ED6E86CA6E84FD66BAE96C84
                760047F0F5B594D4D4FFCB2F28481A3B003CDF9328DEBD78EE46958809C8E580
                03A8233EE301FA03E04F6B41224538B615F7D885EF7B410C6713FDCCD5053601
                44083AC4A09136C748D6028DB3277A743F34D81C6CED70BC0D4E692A02C26645
                09B3413013D109924A44CE868A030565BA668813104550F73988BADD8567FF1E
                FB056E2957E15EEB400EFB707CBF2D2D44069B002C82A33B1A5F4334BC0E18A5
                06621B848697813F75F12EED55B82E39F8513CD6378D9BE1EF14FDE93C637491
                C5B17C7C0C2A2A2E8EABF34F38646566D6C3032DC533F5D28FD1B1899B71F69F
                FA0A939CBA0D9B95402226906AC95088EF506F6B718FA5D85F867ADC866B1EB5
                A5046BB00920047AE5E4A495B9DD1D30BA5F86CFA168707DD1D0BA086F8C3FAB
                5972F895122F8D62B83EDEB87163E5F957BF5E3D59AF5E3DAD4E9D3AB4045406
                34A99E0EA32EC325B2C3870FCB4FA64F37AA00EBB00D2D4CB2597267662625A1
                4578E09EFAF34F983851E259553624FD99CA40663468C2A69D3A754A9E387142
                3B7EE284F210C4B36AB477A0F113CF0D081E62454D2AC3EE77D85D0315691188
                E6734808DBF2F2F34B237BAAEA0F9B0002804E5F1B8DA83F5ADDE56840146719
                D9D7B228CF76C8997D76746E0C94C1357F7D36DCC205FCBFA313BCFEFAEBBE15
                00C9114F88E1AEA2A22D89AE2B23B21C8EF351F6051A2522E15909B8FBEEBB4D
                9F271CF4D50FDA0630F00949819B4A915E31698195E6425966E3BDCCC1B6322F
                419E93C90A9B0084EAF4E968590330CAD36F9F1B5D76D95B43D60F3B3BC36061
                94531DBD65AB56A245F3E6CAB8C74CA437FCD0FFAB081E478B78F7DD77392AEA
                5FBFF786C94AA80970206812AC79C29FA928419076C4A449937C7F0F1612D80F
                660650E29CCA401F827DFBF78BBD7BF628623874F83025072BA4C013D8F1397F
                F0495A6AEA277807CB4106355E4DA8D10490939D7D1E1ACF186C77A01565E250
                431162761EFAACC4E8AE71446FD5AA956CDDBAB5C6869E9E9E2E21BA870D85AD
                598DCB1F102E7CDAC71FAB38805E15603F88E54A10C0EA44D79F1120807E28DB
                67287873D61749F1AAABAFF67F3E55FCF0CF2F2D8416872A21CF9E3DAB911877
                EFDE2DF7ECD9A351628094204B4B4B83AB091EB638823A5E8B7A7C0BEADD67F9
                05053B135D7F89428D2400675616CDD46EC2C635E79EC210D6CA08B61746B361
                636ED3A60DA3F6A8EFD4D9AD26C2D0CF0B1CD52B823973E6887DFB7C2AFF515C
                731C086051A2EBD10810C050946BA6208902ACAB2BAEB822A26BF9F5788B223F
                CF3B75EA94601425D6D5AE5DBB387FA2BE87B806E70638A7F226CEF80FD4AABD
                89AEC778A3C611405656D6C5824634420C12261D9FA23B47759AB2D29A8DA27D
                BD7AF58477222FAA65B17ABD458B16294B40020DF53446ADAB4000B3135D9746
                800046E3819809594D74B0EE860E1D6AE9B711AE0284BC1EB713274E28558175
                47536A4A0B7ED694E7508A127015E1E74545452B135C9571458D220034D2DE78
                E06978D91D020D5128C6A3D36BEDDBB757B1ECA0C75738D38D57C20CB92210B0
                6FE97AAB56ADD2680EECBD9EF4C6CAFF38D1F51950B757A35C1FEAE10E6906DC
                AF5F3FDDE027A2E70FAC4383015185DE0B774E9F3EAD622B6EDFBE9D64A0D407
                1323AB6DF8C15545C5C57989AECF78A1A611C09778DF971A8F71C46FDFAE9DE8
                D8B1A31AE9C365EC217455D227DE1BF683A6D5AAC4F5D6AE5D2BB68200743010
                271AE9BF125D9F01757B1B0394EADF3B82003232327CCF6FF67C9646FE20F559
                99EB5132D8BA75ABD8FEFDF7E524025C6321EA7658A2EB335EA83104E0743A1B
                E0ED1E16B1B1CE8B2BDC52FEB8B8B8F8AF892E87110E87E347504D5E497439A2
                00865C6BEC72B98E55FE52C98F1A430018A1EA6194A0E5584A05F2D3C774BF12
                BFFB2946A984060231A95F060679211ECF1FE3FA07BFCA06A8DF93961EBC8AA3
                261180E65DA71E2EAAAE14401997A6C0B7BB8A8A922A6E1EEA371BF5CBB0E739
                A2EAB62BEA030B40009781006A4448F2AAFAA222021AE979F87850781C56D22A
                79B94460233AD9CFD1F993CA084887332B2B139DE7B7D8ED5AE98BC51F5C12E4
                CACA4BE8FC35C62EA0461100E1C8CCE433337845D5930234ED1474FFA4366575
                381C8C715627D1E588001CFD8F159794D488915F478D23001B366C9C834D0036
                6CD460D80460C3460D864D00366CD460D80460C3460D864D00366CD460D80460
                C3460D864D00366CD460FC3FD13F48506172F9FC0000000049454E44AE426082}
              Proportional = True
              Stretch = True
              Transparent = True
              ExplicitLeft = 584
              ExplicitTop = 9
              ExplicitHeight = 168
            end
            object Label2: TLabel
              Left = 34
              Top = 16
              Width = 229
              Height = 52
              Caption = 'ArrayCam  -'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -43
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object logLabel: TLabel
              Left = 34
              Top = 162
              Width = 6
              Height = 24
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -21
              Font.Name = 'Myriad Pro'
              Font.Style = []
              ParentFont = False
              StyleElements = [seClient, seBorder]
            end
            object versionLabel: TLabel
              Left = 290
              Top = 27
              Width = 104
              Height = 39
              Caption = 'Version'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -32
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
          end
        end
      end
    end
  end
  object LeftPanel: TPanel
    Left = 0
    Top = 0
    Width = 421
    Height = 900
    Align = alClient
    TabOrder = 1
    object mMainPhotoPanel: TPanel
      Left = 1
      Top = 1
      Width = 419
      Height = 898
      Align = alClient
      TabOrder = 0
      OnResize = mMainPhotoPanelResize
      object mCamera1BackPanel: TPanel
        Left = 0
        Top = 0
        Width = 393
        Height = 608
        BorderStyle = bsSingle
        Caption = 'No Camera...'
        TabOrder = 0
        object mPB: TPaintBox
          Left = 0
          Top = 0
          Width = 315
          Height = 460
          PopupMenu = CameraPopup
          OnMouseDown = mPBMouseDown
          OnMouseMove = mPBMouseMove
          OnMouseUp = mPBMouseUp
        end
        object CameraHC: THeaderControl
          Left = 1
          Top = 573
          Width = 387
          Height = 30
          Align = alBottom
          BiDiMode = bdLeftToRight
          Sections = <
            item
              Alignment = taCenter
              BiDiMode = bdLeftToRight
              ImageIndex = -1
              ParentBiDiMode = False
              Text = 'Camera'
              Width = 80
            end
            item
              Alignment = taCenter
              ImageIndex = -1
              Text = 'Reticle'
              Width = 75
            end
            item
              Alignment = taCenter
              ImageIndex = -1
              Text = 'Snapshot'
              Width = 100
            end
            item
              Alignment = taCenter
              ImageIndex = -1
              Text = 'Record Movie'
              Width = 150
            end>
          OnSectionClick = CameraHCSectionClick
          ParentBiDiMode = False
          PopupMenu = CameraPopup
        end
      end
    end
  end
  object mShutDownTimer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = mShutDownTimerTimer
    Left = 368
    Top = 152
  end
  object mCaptureVideoTimer: TTimer
    Enabled = False
    Interval = 1
    OnTimer = mCaptureVideoTimerTimer
    Left = 368
    Top = 80
  end
  object mMediaPopup: TPopupMenu
    Left = 360
    Top = 352
    object Delete1: TMenuItem
      Caption = 'Delete'
    end
    object DeleteAll1: TMenuItem
      Caption = 'Delete All'
    end
  end
  object mStartupTimer: TTimer
    Enabled = False
    Interval = 250
    OnTimer = mStartupTimerTimer
    Left = 368
    Top = 280
  end
  object mCheckSocketConnectionTimer: TTimer
    Enabled = False
    Interval = 3000
    OnTimer = mCheckSocketConnectionTimerTimer
    Left = 368
    Top = 216
  end
  object CameraPopup: TPopupMenu
    Left = 240
    Top = 576
    object FittoScreen1: TMenuItem
      Caption = 'Fit to Screen'
      OnClick = mFitToScreenButtonClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object N111: TMenuItem
      Caption = 'Zoom 1:1'
      OnClick = mOneToOneBtnClick
    end
    object N121: TMenuItem
      Caption = 'Zoom 1:2'
      OnClick = mOneToTwoBtnClick
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object OpenSettings1: TMenuItem
      Caption = 'Open Settings'
      OnClick = mSettingsBtnClick
    end
  end
  object ReticlePopup: TPopupMenu
    Left = 304
    Top = 584
    object Reset1: TMenuItem
      Caption = 'Reset'
    end
  end
end
