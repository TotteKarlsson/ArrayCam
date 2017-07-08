object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Array Cam 0.5'
  ClientHeight = 919
  ClientWidth = 1242
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
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
    Top = 30
    Height = 870
    Align = alRight
    ExplicitLeft = 1015
    ExplicitTop = 52
    ExplicitHeight = 814
  end
  object MainContentPanel: TPanel
    Left = 424
    Top = 30
    Width = 818
    Height = 870
    Align = alRight
    Caption = 'MainContentPanel'
    Constraints.MinWidth = 786
    TabOrder = 0
    object MainTopPanel: TPanel
      Left = 1
      Top = 1
      Width = 816
      Height = 82
      Align = alTop
      AutoSize = True
      TabOrder = 0
      object CounterGB: TGroupBox
        Left = 1
        Top = 1
        Width = 814
        Height = 80
        Align = alTop
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
    object Panel1: TPanel
      Left = 1
      Top = 83
      Width = 816
      Height = 786
      Align = alClient
      Caption = 'Panel1'
      TabOrder = 1
      object PageControl1: TPageControl
        Left = 1
        Top = 1
        Width = 814
        Height = 784
        ActivePage = Main
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
            Height = 750
            Align = alClient
            TabOrder = 0
            object Panel9: TPanel
              Left = 0
              Top = 0
              Width = 802
              Height = 746
              Align = alClient
              TabOrder = 0
              object BlocksGB: TGroupBox
                Left = 1
                Top = 413
                Width = 800
                Height = 332
                Align = alBottom
                Caption = 'Ribbon  Registration'
                TabOrder = 0
                object GroupBox9: TGroupBox
                  Left = 2
                  Top = 199
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
                    DataField = 'case_id'
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
                  object DBText7: TDBText
                    Left = 133
                    Top = 68
                    Width = 170
                    Height = 17
                    DataField = 'id'
                    DataSource = atdbDM.blocksDataSource
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
                    Width = 55
                    Height = 19
                    Caption = 'Case ID'
                  end
                  object Label9: TLabel
                    Left = 220
                    Top = 68
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
                Height = 112
                Align = alTop
                Caption = 'Feed'
                TabOrder = 1
                object mSetZeroCutBtn: TArrayBotButton
                  Left = 134
                  Top = 45
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
                  Top = 48
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
                  Top = 48
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
                  Top = 48
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
                  Top = 45
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
                Top = 225
                Width = 800
                Height = 188
                Align = alClient
                Caption = 'Operation'
                Constraints.MinHeight = 101
                TabOrder = 2
                object GroupBox11: TGroupBox
                  Left = 2
                  Top = 21
                  Width = 183
                  Height = 165
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
                  Height = 159
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
                Top = 113
                Width = 800
                Height = 112
                Align = alTop
                Caption = 'Knife Stage'
                TabOrder = 3
                inline MaxStagePosFrame: TUC7StagePositionFrame
                  Left = 339
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
                  TabOrder = 0
                  ExplicitLeft = 339
                  ExplicitTop = 24
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
                  Left = 275
                  Top = 51
                  Width = 58
                  Height = 28
                  Caption = '->'
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
              end
            end
          end
        end
        object TabSheet8: TTabSheet
          Caption = 'UC7'
          ImageIndex = 5
          object UC7GB: TGroupBox
            Left = 0
            Top = 0
            Width = 806
            Height = 750
            Align = alClient
            Caption = 'UC7'
            TabOrder = 0
            object GroupBox4: TGroupBox
              Left = 2
              Top = 203
              Width = 802
              Height = 94
              Align = alTop
              Caption = 'Misc parameters'
              TabOrder = 0
              object mStageMoveDelayE: TIntegerLabeledEdit
                Left = 23
                Top = 48
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
            object KnifeGB: TGroupBox
              Left = 2
              Top = 297
              Width = 802
              Height = 120
              Align = alTop
              Caption = 'Knife position'
              TabOrder = 3
              inline BackOffStepFrame: TUC7StagePositionFrame
                Left = 10
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
                TabOrder = 0
                ExplicitLeft = 10
                ExplicitTop = 24
                inherited GroupBox1: TGroupBox
                  Caption = 'Backoff Step'
                end
              end
              inline ResumeDeltaDistanceFrame: TUC7StagePositionFrame
                Left = 280
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
                TabOrder = 1
                ExplicitLeft = 280
                ExplicitTop = 24
                inherited GroupBox1: TGroupBox
                  Caption = 'Resume Delta Distance'
                  inherited Label1: TLabel
                    Visible = False
                  end
                  inherited ValueMM: TIntegerEdit
                    Enabled = False
                    Text = '0'
                    Value = 0
                  end
                end
              end
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
            Height = 750
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
                  Width = 96
                  Height = 19
                  Caption = 'Specimen ID:'
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
                  KeyField = 'specimen_id'
                  ListField = 'specimen_id'
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
              Height = 315
              Align = alClient
              Caption = 'Ribbons'
              TabOrder = 2
              object DBGrid1: TDBGrid
                Left = 2
                Top = 21
                Width = 798
                Height = 270
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
                Top = 291
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
        object TabSheet9: TTabSheet
          Caption = 'Navitar'
          ImageIndex = 7
          object GroupBox13: TGroupBox
            Left = 0
            Top = 0
            Width = 313
            Height = 750
            Align = alLeft
            Caption = 'Misc.'
            Color = clBtnFace
            ParentColor = False
            TabOrder = 0
            object ConnectBtn: TButton
              Left = 20
              Top = 24
              Width = 153
              Height = 57
              Caption = 'Connect'
              TabOrder = 0
              OnClick = ConnectBtnClick
            end
            object ControllerInfoGB: TGroupBox
              Left = 2
              Top = 633
              Width = 309
              Height = 115
              Align = alBottom
              Caption = 'Controller Info'
              TabOrder = 1
              object Label12: TLabel
                Left = 16
                Top = 24
                Width = 82
                Height = 19
                Caption = 'Product ID:'
                Transparent = True
              end
              object Label13: TLabel
                Left = 16
                Top = 45
                Width = 132
                Height = 19
                Caption = 'Hardware Version:'
                Transparent = True
              end
              object Label14: TLabel
                Left = 16
                Top = 66
                Width = 120
                Height = 19
                Caption = 'Software Version'
                Transparent = True
              end
              object Label15: TLabel
                Left = 16
                Top = 85
                Width = 109
                Height = 19
                Caption = 'Firmware Date:'
                Transparent = True
              end
              object ProdIdLbl: TLabel
                Left = 166
                Top = 22
                Width = 28
                Height = 19
                Caption = 'N/A'
                Transparent = True
              end
              object HWVerLbl: TLabel
                Left = 166
                Top = 43
                Width = 28
                Height = 19
                Caption = 'N/A'
                Transparent = True
              end
              object SWVerLbl: TLabel
                Left = 166
                Top = 64
                Width = 28
                Height = 19
                Caption = 'N/A'
                Transparent = True
              end
              object FirmWareDateLbl: TLabel
                Left = 166
                Top = 85
                Width = 28
                Height = 19
                Caption = 'N/A'
                Transparent = True
              end
            end
          end
          object Panel8: TPanel
            Left = 313
            Top = 0
            Width = 493
            Height = 750
            Align = alClient
            TabOrder = 1
            inline TNavitarMotorFrame1: TNavitarMotorFrame
              Left = 1
              Top = 1
              Width = 491
              Height = 120
              Align = alTop
              TabOrder = 0
              ExplicitLeft = 1
              ExplicitTop = 1
              ExplicitWidth = 491
              inherited MotorGB: TGroupBox
                Width = 491
                ExplicitWidth = 491
                inherited Label1: TLabel
                  Width = 63
                  Height = 19
                  ExplicitWidth = 63
                  ExplicitHeight = 19
                end
                inherited MotorPosition: TIntegerLabeledEdit
                  EditLabel.Width = 114
                  EditLabel.Height = 19
                  EditLabel.ExplicitLeft = 135
                  EditLabel.ExplicitTop = 50
                  EditLabel.ExplicitWidth = 114
                  EditLabel.ExplicitHeight = 19
                end
              end
            end
            inline TNavitarMotorFrame2: TNavitarMotorFrame
              Left = 1
              Top = 121
              Width = 491
              Height = 120
              Align = alTop
              TabOrder = 1
              ExplicitLeft = 1
              ExplicitTop = 121
              ExplicitWidth = 491
              inherited MotorGB: TGroupBox
                Width = 491
                ExplicitWidth = 491
                inherited Label1: TLabel
                  Width = 63
                  Height = 19
                  ExplicitWidth = 63
                  ExplicitHeight = 19
                end
                inherited MotorPosition: TIntegerLabeledEdit
                  EditLabel.Width = 114
                  EditLabel.Height = 19
                  EditLabel.ExplicitLeft = 135
                  EditLabel.ExplicitTop = 50
                  EditLabel.ExplicitWidth = 114
                  EditLabel.ExplicitHeight = 19
                end
              end
            end
            object NavitarPresetGB: TGroupBox
              Left = 1
              Top = 241
              Width = 491
              Height = 508
              Align = alClient
              Caption = 'Presets'
              TabOrder = 2
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
            Height = 750
            ActivePage = TabSheet5
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
                Height = 475
                Align = alClient
                AutoSize = True
                TabOrder = 0
                ExplicitTop = 241
                ExplicitWidth = 798
                ExplicitHeight = 475
                inherited GroupBox1: TGroupBox
                  Width = 798
                  Height = 475
                  Align = alClient
                  ExplicitWidth = 798
                  ExplicitHeight = 475
                  inherited SoundsLB: TListBox
                    Top = 21
                    Width = 215
                    Height = 452
                    ItemHeight = 19
                    ExplicitTop = 21
                    ExplicitWidth = 215
                    ExplicitHeight = 452
                  end
                end
              end
              inline TApplicationSoundsFrame1: TApplicationSoundsFrame
                Left = 0
                Top = 0
                Width = 798
                Height = 241
                Align = alTop
                AutoSize = True
                TabOrder = 1
                ExplicitWidth = 798
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
                    ExplicitLeft = 330
                    ExplicitTop = 21
                    ExplicitWidth = 466
                    ExplicitHeight = 218
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
      end
    end
  end
  object LeftPanel: TPanel
    Left = 0
    Top = 30
    Width = 421
    Height = 870
    Align = alClient
    TabOrder = 1
    object mMainPhotoPanel: TPanel
      Left = 1
      Top = 1
      Width = 419
      Height = 868
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
          Left = 1
          Top = -3
          Width = 315
          Height = 460
          PopupMenu = CameraPopup
          OnMouseDown = mPBMouseDown
          OnMouseMove = mPBMouseMove
          OnMouseUp = mPBMouseUp
        end
        object CameraHC: THeaderControl
          Left = 1
          Top = 1
          Width = 387
          Height = 30
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
  object StatusBar1: TStatusBar
    Left = 0
    Top = 900
    Width = 1242
    Height = 19
    Hint = 'Test'
    Panels = <>
    OnHint = StatusBar1Hint
  end
  object ControlBar1: TControlBar
    Left = 0
    Top = 0
    Width = 1242
    Height = 30
    Align = alTop
    AutoSize = True
    TabOrder = 3
    object MainToolBar: TToolBar
      Left = 11
      Top = 2
      Width = 150
      Height = 22
      Hint = 'Main Actions'
      Caption = 'MainToolBar'
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Action = FileExit1
      end
      object ToolButton2: TToolButton
        Left = 23
        Top = 0
        Width = 8
        Caption = 'ToolButton2'
        ImageIndex = 1
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 31
        Top = 0
        Action = OpenHandWheelPositionFormA
      end
      object ToolButton8: TToolButton
        Left = 54
        Top = 0
        Action = ToggleMainContentPanelA
      end
    end
    object CameraToolbar: TToolBar
      Left = 184
      Top = 2
      Width = 150
      Height = 22
      Hint = 'Camera Actions'
      Caption = 'CameraToolbar'
      TabOrder = 1
      object ToolButton4: TToolButton
        Left = 0
        Top = 0
        Action = FitToScreenA
      end
      object ToolButton5: TToolButton
        Left = 23
        Top = 0
        Action = Zoom1To1A
      end
      object ToolButton6: TToolButton
        Left = 46
        Top = 0
        Action = Zoom1To2A
      end
      object ToolButton7: TToolButton
        Left = 69
        Top = 0
        Action = OpenCameraSettingsA
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
      Action = FitToScreenA
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object N111: TMenuItem
      Action = Zoom1To1A
    end
    object N121: TMenuItem
      Action = Zoom1To2A
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object OpenSettings1: TMenuItem
      Action = OpenCameraSettingsA
    end
  end
  object ReticlePopup: TPopupMenu
    Left = 304
    Top = 584
    object Reset1: TMenuItem
      Caption = 'Reset'
    end
  end
  object MainMenu1: TMainMenu
    Left = 160
    Top = 8
    object File1: TMenuItem
      Caption = 'File'
      object Exit1: TMenuItem
        Action = FileExit1
      end
    end
    object Camera1: TMenuItem
      Caption = 'Camera'
      object FitToScreenA1: TMenuItem
        Action = FitToScreenA
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object Zoom111: TMenuItem
        Action = Zoom1To1A
      end
      object Zoom121: TMenuItem
        Action = Zoom1To2A
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object CameraSettings1: TMenuItem
        Action = OpenCameraSettingsA
      end
    end
    object Misc1: TMenuItem
      Caption = 'Misc'
      object UC7StatusChart1: TMenuItem
        Action = OpenHandWheelPositionFormA
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object OpenLoggerForm1: TMenuItem
        Caption = 'Open Logger Form'
        OnClick = OpenLoggerForm1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object About1: TMenuItem
        Caption = 'About'
        OnClick = About1Click
      end
    end
  end
  object MenuActions: TActionList
    Left = 40
    Top = 88
    object FileExit1: TFileExit
      Category = 'File'
      Caption = 'E&xit'
      Hint = 'Exit|Quits the application'
      ImageIndex = 43
    end
    object OpenHandWheelPositionFormA: TAction
      Category = 'File'
      Caption = 'Open Handwheel Position Form'
      Hint = 'OPen Handwheel position Form'
      OnExecute = OpenHandWheelPositionFormAExecute
    end
    object ToggleMainContentPanelA: TAction
      Category = 'File'
      AutoCheck = True
      Caption = 'Show/Hide Main Content Panel'
      OnExecute = ToggleMainContentPanelAExecute
    end
  end
  object CameraActions: TActionList
    Left = 56
    Top = 192
    object FitToScreenA: TAction
      Category = 'Camera'
      Caption = 'Fit to Screen'
      Hint = 'Fit To Screen'
      OnExecute = FitToScreenAExecute
    end
    object Zoom1To1A: TAction
      Category = 'Camera'
      Caption = 'Zoom 1:1'
      Hint = 'Zoom 1:1'
      OnExecute = Zoom1To1AExecute
    end
    object Zoom1To2A: TAction
      Category = 'Camera'
      Caption = 'Zoom 1:2'
      Hint = 'Zoom 1:2'
      OnExecute = Zoom1To2AExecute
    end
    object OpenCameraSettingsA: TAction
      Category = 'Camera'
      Caption = 'Camera Settings'
      Hint = 'Open Camera settings form'
      OnExecute = OpenCameraSettingsAExecute
    end
  end
end
