object MainForm: TMainForm
  Left = 0
  Top = 0
  ActiveControl = BlocksAndRibbonsPC
  Caption = 'Array Cam 0.5'
  ClientHeight = 963
  ClientWidth = 1817
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
    Left = 965
    Top = 84
    Height = 857
    Align = alRight
    ExplicitLeft = 1015
    ExplicitTop = 52
    ExplicitHeight = 814
  end
  object MainContentPanel: TPanel
    Left = 968
    Top = 84
    Width = 818
    Height = 857
    Align = alRight
    Caption = 'MainContentPanel'
    Constraints.MinWidth = 786
    TabOrder = 0
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 816
      Height = 855
      Align = alClient
      Caption = 'Panel1'
      TabOrder = 0
      DesignSize = (
        816
        855)
      object PageControl1: TPageControl
        Left = 1
        Top = 1
        Width = 814
        Height = 853
        ActivePage = TabSheet7
        Align = alClient
        MultiLine = True
        TabOrder = 0
        OnChange = PageControlChange
        object Main: TTabSheet
          Caption = 'Main'
          ImageIndex = 5
          object ScrollBox1: TScrollBox
            Left = 0
            Top = 0
            Width = 806
            Height = 819
            Align = alClient
            TabOrder = 0
            object Panel9: TPanel
              Left = 0
              Top = 0
              Width = 802
              Height = 815
              Align = alClient
              TabOrder = 0
              object RibbonRegistrationGB: TGroupBox
                Left = 1
                Top = 606
                Width = 800
                Height = 138
                Align = alBottom
                Caption = 'Ribbon  Registration'
                TabOrder = 0
                DesignSize = (
                  800
                  138)
                object mBCLabel: TLabel
                  AlignWithMargins = True
                  Left = 654
                  Top = 56
                  Width = 131
                  Height = 39
                  Alignment = taRightJustify
                  Anchors = [akTop, akRight]
                  Caption = 'Barcode'
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clRed
                  Font.Height = -32
                  Font.Name = 'Tahoma'
                  Font.Style = [fsBold]
                  ParentFont = False
                  Layout = tlCenter
                end
                object DecodeSessionBtn: TButton
                  Left = 25
                  Top = 37
                  Width = 143
                  Height = 85
                  Caption = 'Scan Barcode'
                  TabOrder = 0
                  OnClick = DecodeBarcodeClick
                end
                object RegisterRibbonBtn: TArrayBotButton
                  Left = 201
                  Top = 39
                  Width = 143
                  Height = 85
                  Caption = 'Register Ribbon'
                  ParentDoubleBuffered = True
                  TabOrder = 1
                  OnClick = RegisterRibbonBtnClick
                  SoundID = 'BUTTON_CLICK_4'
                end
                object GroupBox5: TGroupBox
                  Left = 368
                  Top = 16
                  Width = 225
                  Height = 105
                  Caption = 'Block Face'
                  TabOrder = 2
                  object BlockFaceHeight: TFloatLabeledEdit
                    Left = 16
                    Top = 56
                    Width = 81
                    Height = 27
                    EditLabel.Width = 169
                    EditLabel.Height = 19
                    EditLabel.Caption = 'Block Face Height (mm)'
                    TabOrder = 0
                    Text = '1.0000'
                    Value = 1.000000000000000000
                  end
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
                  Width = 89
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
                  Visible = False
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
                Top = 266
                Width = 800
                Height = 340
                Align = alClient
                Caption = 'Operation'
                Constraints.MinHeight = 101
                TabOrder = 2
                object GroupBox11: TGroupBox
                  Left = 2
                  Top = 21
                  Width = 183
                  Height = 317
                  Align = alLeft
                  Caption = 'Cutter'
                  TabOrder = 0
                  object StartStopBtn: TArrayBotButton
                    Left = 16
                    Top = 31
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
                  object StopOptionsRG: TRadioGroup
                    Left = 2
                    Top = 176
                    Width = 179
                    Height = 139
                    Align = alBottom
                    Caption = 'Stop options'
                    ItemIndex = 0
                    Items.Strings = (
                      'Immediately'
                      'Before Cutting'
                      'After Cutting'
                      'Before Retracting')
                    TabOrder = 1
                  end
                end
                object GroupBox12: TGroupBox
                  AlignWithMargins = True
                  Left = 565
                  Top = 24
                  Width = 230
                  Height = 311
                  Margins.Left = 10
                  Align = alClient
                  Caption = 'Knife Stage'
                  TabOrder = 1
                  DesignSize = (
                    230
                    311)
                  object mMoveNorthBtn: TArrayBotButton
                    Left = 97
                    Top = 24
                    Width = 130
                    Height = 60
                    Anchors = [akTop, akRight]
                    Caption = 'Knife Forward'
                    Enabled = False
                    ParentDoubleBuffered = True
                    TabOrder = 0
                    OnClick = CreateUC7Message
                    SoundID = 'BUTTON_CLICK_4'
                  end
                  object mMoveSouthBtn: TArrayBotButton
                    Left = 97
                    Top = 90
                    Width = 130
                    Height = 60
                    Anchors = [akTop, akRight]
                    Caption = 'Knife Reverse'
                    Enabled = False
                    ParentDoubleBuffered = True
                    TabOrder = 1
                    OnClick = CreateUC7Message
                    SoundID = 'BUTTON_CLICK_4'
                  end
                end
                object GroupBox7: TGroupBox
                  Left = 185
                  Top = 21
                  Width = 185
                  Height = 317
                  Align = alLeft
                  Caption = 'Options'
                  TabOrder = 2
                  object SyncWhiskerCB: TPropertyCheckBox
                    Left = 16
                    Top = 40
                    Width = 145
                    Height = 49
                    BiDiMode = bdLeftToRight
                    Caption = 'Sync Whisker with Cutter'
                    ParentBiDiMode = False
                    TabOrder = 0
                    WordWrap = True
                    OnClick = SyncWhiskerCBClick
                  end
                end
                object GroupBox9: TGroupBox
                  Left = 370
                  Top = 21
                  Width = 185
                  Height = 317
                  Align = alLeft
                  Caption = 'Return Speed'
                  TabOrder = 3
                  object PresetReturnSpeedBtn: TArrayBotButton
                    Left = 22
                    Top = 40
                    Width = 133
                    Height = 81
                    Caption = 'Preset'
                    TabOrder = 0
                    WordWrap = True
                    OnClick = CreateUC7Message
                    SoundID = 'BUTTON_CLICK_4'
                  end
                  object SlowReturnSpeedBtn: TArrayBotButton
                    Left = 22
                    Top = 127
                    Width = 133
                    Height = 81
                    Caption = 'Slow'
                    TabOrder = 1
                    WordWrap = True
                    OnClick = CreateUC7Message
                    SoundID = 'BUTTON_CLICK_4'
                  end
                  object UltraSlowReturnSpeedBtn: TArrayBotButton
                    Left = 22
                    Top = 214
                    Width = 133
                    Height = 81
                    Caption = 'Ultra Slow'
                    TabOrder = 2
                    WordWrap = True
                    OnClick = CreateUC7Message
                    SoundID = 'BUTTON_CLICK_4'
                  end
                end
              end
              object KnifeStageGB: TGroupBox
                Left = 1
                Top = 154
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
              object BlockInfoGB: TGroupBox
                Left = 1
                Top = 744
                Width = 800
                Height = 70
                Align = alBottom
                Caption = 'Current Block Info (Change block on the Blocks and Ribbons tab)'
                TabOrder = 4
                object DBText7: TDBText
                  Left = 87
                  Top = 38
                  Width = 73
                  Height = 17
                  DataField = 'id'
                  DataSource = pgDM.blocksDataSource
                end
                object Label11: TLabel
                  Left = 13
                  Top = 37
                  Width = 65
                  Height = 19
                  Caption = 'Block ID:'
                end
              end
              object CutterStatusPanel: TPanel
                Left = 1
                Top = 113
                Width = 800
                Height = 41
                Align = alTop
                TabOrder = 5
                object UC7Shape: TShape
                  Left = 432
                  Top = 24
                  Width = 93
                  Height = 11
                  Brush.Color = clLime
                end
                object Label4: TLabel
                  Left = 32
                  Top = 6
                  Width = 101
                  Height = 19
                  Caption = 'Before Cutting'
                end
                object Label16: TLabel
                  Left = 264
                  Top = 6
                  Width = 51
                  Height = 19
                  Caption = 'Cutting'
                end
                object Label17: TLabel
                  Left = 432
                  Top = 6
                  Width = 91
                  Height = 19
                  Caption = 'After Cutting'
                end
                object Label18: TLabel
                  Left = 624
                  Top = 6
                  Width = 71
                  Height = 19
                  Caption = 'Retracting'
                end
              end
            end
          end
        end
        object TabSheet7: TTabSheet
          Caption = 'Blocks and Ribbons'
          ImageIndex = 6
          object BlocksAndRibbonsPC: TPageControl
            Left = 0
            Top = 0
            Width = 806
            Height = 819
            ActivePage = TabSheet2
            Align = alClient
            TabOrder = 0
            object TabSheet2: TTabSheet
              Caption = 'Select Block'
              object BlockNotesGB: TGroupBox
                Left = 0
                Top = 121
                Width = 798
                Height = 216
                Align = alTop
                Caption = 'Block Notes'
                Padding.Left = 5
                Padding.Top = 5
                Padding.Right = 5
                Padding.Bottom = 5
                TabOrder = 0
                ExplicitTop = 209
                object Panel4: TPanel
                  Left = 206
                  Top = 26
                  Width = 585
                  Height = 183
                  Align = alClient
                  TabOrder = 0
                  object mBlockNoteMemo: TDBMemo
                    Left = 1
                    Top = 1
                    Width = 583
                    Height = 156
                    Align = alClient
                    DataField = 'note'
                    DataSource = pgDM.blockNotesDSource
                    TabOrder = 0
                  end
                  object DBNavigator2: TDBNavigator
                    Left = 1
                    Top = 157
                    Width = 583
                    Height = 25
                    DataSource = pgDM.blockNotesDSource
                    VisibleButtons = [nbPost, nbCancel]
                    Align = alBottom
                    TabOrder = 1
                  end
                end
                object Panel5: TPanel
                  Left = 7
                  Top = 26
                  Width = 199
                  Height = 183
                  Align = alLeft
                  BevelOuter = bvNone
                  TabOrder = 1
                  object mBlockNoteNavigator: TDBNavigator
                    Left = 0
                    Top = 158
                    Width = 199
                    Height = 25
                    DataSource = pgDM.blockNotesDSource
                    VisibleButtons = [nbInsert, nbDelete, nbRefresh, nbApplyUpdates]
                    Align = alBottom
                    ConfirmDelete = False
                    TabOrder = 0
                    OnClick = mBlockNoteNavigatorClick
                  end
                  object mBlockNotesGrid: TDBGrid
                    Left = 0
                    Top = 0
                    Width = 199
                    Height = 158
                    Align = alClient
                    DataSource = pgDM.blockNotesDSource
                    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
                    TabOrder = 1
                    TitleFont.Charset = DEFAULT_CHARSET
                    TitleFont.Color = clWindowText
                    TitleFont.Height = -16
                    TitleFont.Name = 'Tahoma'
                    TitleFont.Style = []
                    Columns = <
                      item
                        Expanded = False
                        FieldName = 'created_on'
                        Title.Caption = 'Date'
                        Width = 161
                        Visible = True
                      end>
                  end
                end
              end
              object Panel11: TPanel
                Left = 0
                Top = 0
                Width = 798
                Height = 121
                Align = alTop
                TabOrder = 1
                object BlockSelectionGB: TGroupBox
                  Left = 1
                  Top = 1
                  Width = 796
                  Height = 119
                  Align = alClient
                  Caption = 'DB/Block Selection'
                  TabOrder = 0
                  ExplicitHeight = 207
                  object Panel2: TPanel
                    Left = 2
                    Top = 21
                    Width = 575
                    Height = 96
                    Align = alLeft
                    BevelOuter = bvNone
                    TabOrder = 0
                    ExplicitLeft = 3
                    ExplicitTop = 18
                    ExplicitHeight = 184
                    object Label3: TLabel
                      Left = 141
                      Top = 16
                      Width = 65
                      Height = 19
                      Caption = 'Block ID:'
                    end
                    object BlockIDCB: TDBLookupComboBox
                      Left = 212
                      Top = 16
                      Width = 135
                      Height = 27
                      KeyField = 'id'
                      ListField = 'id'
                      ListSource = pgDM.allBlocksDataSource
                      TabOrder = 0
                      OnCloseUp = DB_CBCloseUp
                    end
                    object mUsersCB: TDBLookupComboBox
                      Left = 12
                      Top = 13
                      Width = 109
                      Height = 27
                      KeyField = 'id'
                      ListField = 'user_name'
                      ListSource = pgDM.usersDataSource
                      TabOrder = 1
                      OnCloseUp = mUsersCBCloseUp
                    end
                  end
                end
              end
              object RibbonsDataGB: TGroupBox
                Left = 0
                Top = 337
                Width = 798
                Height = 448
                Align = alClient
                Caption = 'Ribbons'
                TabOrder = 2
                ExplicitTop = 425
                ExplicitHeight = 360
                object DBGrid1: TDBGrid
                  Left = 2
                  Top = 21
                  Width = 794
                  Height = 259
                  Align = alClient
                  DataSource = pgDM.ribbonsDSource
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
                      FieldName = 'statusL'
                      Width = 123
                      Visible = True
                    end
                    item
                      Expanded = False
                      FieldName = 'cutting_order'
                      Width = 104
                      Visible = True
                    end
                    item
                      Expanded = False
                      FieldName = 'nr_of_sections'
                      Width = 113
                      Visible = True
                    end
                    item
                      Expanded = False
                      FieldName = 'coverslip_id'
                      Width = 120
                      Visible = True
                    end>
                end
                object GroupBox3: TGroupBox
                  Left = 2
                  Top = 280
                  Width = 794
                  Height = 166
                  Align = alBottom
                  Caption = 'Ribbon Notes'
                  TabOrder = 1
                  ExplicitTop = 192
                  object Panel6: TPanel
                    Left = 2
                    Top = 21
                    Width = 185
                    Height = 143
                    Align = alLeft
                    TabOrder = 0
                    object mRibbonNotesGrid: TDBGrid
                      Left = 1
                      Top = 1
                      Width = 183
                      Height = 116
                      Align = alClient
                      DataSource = pgDM.ribbonNotesDSource
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
                          FieldName = 'created_on'
                          Title.Caption = 'Date'
                          Width = 143
                          Visible = True
                        end>
                    end
                    object mRibbonNotesNavigator: TDBNavigator
                      Left = 1
                      Top = 117
                      Width = 183
                      Height = 25
                      DataSource = pgDM.ribbonNotesDSource
                      VisibleButtons = [nbInsert, nbDelete, nbRefresh, nbApplyUpdates]
                      Align = alBottom
                      ConfirmDelete = False
                      TabOrder = 1
                      OnClick = mRibbonNotesNavigatorClick
                    end
                  end
                  object Panel7: TPanel
                    Left = 187
                    Top = 21
                    Width = 605
                    Height = 143
                    Align = alClient
                    TabOrder = 1
                    object mRibbonNoteMemo: TDBMemo
                      Left = 1
                      Top = 1
                      Width = 603
                      Height = 116
                      Align = alClient
                      DataField = 'note'
                      DataSource = pgDM.ribbonNotesDSource
                      TabOrder = 0
                    end
                    object mRibbonNoteNavigator: TDBNavigator
                      Left = 1
                      Top = 117
                      Width = 603
                      Height = 25
                      DataSource = pgDM.ribbonNotesDSource
                      VisibleButtons = [nbPost, nbCancel]
                      Align = alBottom
                      TabOrder = 1
                    end
                  end
                end
              end
            end
            object TabSheet16: TTabSheet
              Caption = 'DB Connections'
              ImageIndex = 2
              inline TPGConnectionFrame1: TPGConnectionFrame
                Left = 0
                Top = 0
                Width = 798
                Height = 201
                Align = alTop
                AutoSize = True
                TabOrder = 0
                ExplicitWidth = 798
                inherited GBox1: TGroupBox
                  Width = 798
                  Align = alClient
                  ExplicitWidth = 798
                  inherited mServerIPE: TSTDStringLabeledEdit
                    Top = 47
                    Width = 473
                    Height = 27
                    EditLabel.Width = 107
                    EditLabel.Height = 19
                    EditLabel.ExplicitLeft = 16
                    EditLabel.ExplicitTop = 25
                    EditLabel.ExplicitWidth = 107
                    EditLabel.ExplicitHeight = 19
                    ExplicitTop = 47
                    ExplicitWidth = 473
                    ExplicitHeight = 27
                  end
                  inherited mDBUserE: TSTDStringLabeledEdit
                    Left = 192
                    Top = 103
                    Height = 27
                    EditLabel.Width = 32
                    EditLabel.Height = 19
                    EditLabel.ExplicitLeft = 192
                    EditLabel.ExplicitTop = 81
                    EditLabel.ExplicitWidth = 32
                    EditLabel.ExplicitHeight = 19
                    ExplicitLeft = 192
                    ExplicitTop = 103
                    ExplicitHeight = 27
                  end
                  inherited mPasswordE: TSTDStringLabeledEdit
                    Left = 370
                    Top = 103
                    Height = 27
                    EditLabel.Width = 67
                    EditLabel.Height = 19
                    EditLabel.ExplicitLeft = 370
                    EditLabel.ExplicitTop = 81
                    EditLabel.ExplicitWidth = 67
                    EditLabel.ExplicitHeight = 19
                    ExplicitLeft = 370
                    ExplicitTop = 103
                    ExplicitHeight = 27
                  end
                  inherited mDatabaseE: TSTDStringLabeledEdit
                    Left = 18
                    Top = 103
                    Height = 27
                    EditLabel.Width = 64
                    EditLabel.Height = 19
                    EditLabel.ExplicitLeft = 18
                    EditLabel.ExplicitTop = 81
                    EditLabel.ExplicitWidth = 64
                    EditLabel.ExplicitHeight = 19
                    ExplicitLeft = 18
                    ExplicitTop = 103
                    ExplicitHeight = 27
                  end
                  inherited ArrayBotButton1: TArrayBotButton
                    Left = 512
                    Top = 47
                    Width = 265
                    Height = 81
                    ExplicitLeft = 512
                    ExplicitTop = 47
                    ExplicitWidth = 265
                    ExplicitHeight = 81
                  end
                end
              end
            end
          end
        end
        object TabSheet12: TTabSheet
          Caption = 'Videos && Images'
          ImageIndex = 8
          object GroupBox6: TGroupBox
            Left = 0
            Top = 0
            Width = 806
            Height = 86
            Align = alTop
            BiDiMode = bdLeftToRight
            Caption = 'Media'
            ParentBiDiMode = False
            TabOrder = 0
            object BrowseForMediaFolderBtn: TButton
              Left = 339
              Top = 47
              Width = 27
              Height = 25
              Caption = '...'
              TabOrder = 0
              OnClick = BrowseForFolderClick
            end
            object MediaFolderE: TSTDStringLabeledEdit
              Left = 16
              Top = 46
              Width = 317
              Height = 27
              EditLabel.Width = 128
              EditLabel.Height = 19
              EditLabel.Caption = 'Media Root Folder'
              TabOrder = 1
            end
          end
          object MediaPageControl: TPageControl
            Left = 65
            Top = 86
            Width = 741
            Height = 733
            ActivePage = TabSheet13
            Align = alClient
            TabOrder = 1
            OnChange = MediaPageControlChange
            object TabSheet13: TTabSheet
              Caption = 'Movies'
              ImageIndex = 2
              inline TMoviesFrame1: TMoviesFrame
                Left = 0
                Top = 0
                Width = 733
                Height = 699
                Align = alClient
                TabOrder = 0
                ExplicitWidth = 733
                ExplicitHeight = 699
                inherited Panel22: TPanel
                  Top = 644
                  Width = 733
                  ExplicitTop = 644
                  ExplicitWidth = 733
                  inherited Label4: TLabel
                    Width = 143
                    Height = 19
                    ExplicitWidth = 143
                    ExplicitHeight = 19
                  end
                end
                inherited ScrollBox2: TScrollBox
                  Width = 733
                  Height = 644
                  ExplicitWidth = 733
                  ExplicitHeight = 644
                  inherited FlowPanel1: TFlowPanel
                    Width = 729
                    ExplicitWidth = 729
                  end
                end
              end
            end
            object TabSheet15: TTabSheet
              Caption = 'Images'
              ImageIndex = 1
              inline TImagesFrame1: TImagesFrame
                Left = 0
                Top = 0
                Width = 733
                Height = 699
                Align = alClient
                TabOrder = 0
                ExplicitWidth = 733
                ExplicitHeight = 699
                inherited Panel22: TPanel
                  Top = 644
                  Width = 733
                  ExplicitTop = 644
                  ExplicitWidth = 733
                  inherited Label4: TLabel
                    Width = 143
                    Height = 19
                    ExplicitWidth = 143
                    ExplicitHeight = 19
                  end
                end
                inherited ScrollBox2: TScrollBox
                  Width = 733
                  Height = 644
                  ExplicitWidth = 733
                  ExplicitHeight = 644
                  inherited FlowPanel1: TFlowPanel
                    Width = 729
                    ExplicitWidth = 729
                  end
                end
              end
            end
          end
          object GroupBox16: TGroupBox
            Left = 0
            Top = 86
            Width = 65
            Height = 733
            Align = alLeft
            Caption = 'Block IDs'
            Color = clBtnFace
            ParentColor = False
            TabOrder = 2
            object BlockIDSLLB: TDBLookupListBox
              Left = 2
              Top = 21
              Width = 61
              Height = 707
              Align = alClient
              BiDiMode = bdRightToLeft
              KeyField = 'id'
              ListField = 'id'
              ListSource = pgDM.blockIDsDataSource
              ParentBiDiMode = False
              TabOrder = 0
              OnKeyUp = BlockIDSLLBKeyUp
              OnMouseUp = BlockIDSLLBMouseUp
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
            Height = 819
            Align = alClient
            Caption = 'UC7'
            TabOrder = 0
            object GroupBox4: TGroupBox
              Left = 2
              Top = 62
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
            object KnifeGB: TGroupBox
              Left = 2
              Top = 156
              Width = 802
              Height = 120
              Align = alTop
              Caption = 'Knife position'
              TabOrder = 2
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
            object GroupBox8: TGroupBox
              Left = 2
              Top = 276
              Width = 802
              Height = 237
              Align = alTop
              Caption = 'Return speeds (mm/s)'
              TabOrder = 3
              object PresetReturnSpeedE: TFloatLabeledEdit
                Left = 24
                Top = 56
                Width = 121
                Height = 27
                EditLabel.Width = 43
                EditLabel.Height = 19
                EditLabel.Caption = 'Preset'
                TabOrder = 0
                Text = '0.00'
              end
              object SlowReturnSpeedE: TFloatLabeledEdit
                Left = 24
                Top = 112
                Width = 121
                Height = 27
                EditLabel.Width = 34
                EditLabel.Height = 19
                EditLabel.Caption = 'Slow'
                TabOrder = 1
                Text = '0.00'
              end
              object UltraSlowReturnSpeedE: TFloatLabeledEdit
                Left = 24
                Top = 176
                Width = 121
                Height = 27
                EditLabel.Width = 73
                EditLabel.Height = 19
                EditLabel.Caption = 'Ultra Slow'
                TabOrder = 2
                Text = '0.00'
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
                OnClick = DecodeBarcodeClick
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
            Height = 819
            Align = alLeft
            Caption = 'Misc.'
            Color = clBtnFace
            ParentColor = False
            TabOrder = 0
            object NavitarControllerConnectBtn: TButton
              Left = 20
              Top = 24
              Width = 153
              Height = 57
              Caption = 'Connect'
              TabOrder = 0
              OnClick = NavitarControllerConnectBtnClick
            end
            object ControllerInfoGB: TGroupBox
              Left = 2
              Top = 702
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
            Height = 819
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
          end
        end
        object TabSheet1: TTabSheet
          Caption = 'Miscellaneous'
          ImageIndex = 6
          object MiscPageControl: TPageControl
            Left = 0
            Top = 0
            Width = 806
            Height = 819
            ActivePage = TabSheet5
            Align = alClient
            TabOrder = 0
            OnChange = PageControlChange
            OnExit = PageControlExit
            object TabSheet5: TTabSheet
              Caption = 'ArrayCam Server'
              ImageIndex = 2
              object GroupBox1: TGroupBox
                Left = 0
                Top = 0
                Width = 798
                Height = 193
                Align = alTop
                Caption = 'Server'
                TabOrder = 0
                object NrOfArrayCamServerClients: TIntLabel
                  Left = 166
                  Top = 120
                  Width = 15
                  Height = 19
                  Caption = '-1'
                  Value = -1
                  TheFont.Charset = DEFAULT_CHARSET
                  TheFont.Color = clWindowText
                  TheFont.Height = -16
                  TheFont.Name = 'Tahoma'
                  TheFont.Style = []
                end
                object Label2: TLabel
                  Left = 16
                  Top = 120
                  Width = 134
                  Height = 19
                  Caption = 'Number of Clients:'
                end
                object ArrayCamServerPortE: TIntegerLabeledEdit
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
            end
            object TabSheet3: TTabSheet
              Caption = 'Arduino Client'
              ImageIndex = 2
              object GroupBox2: TGroupBox
                Left = 0
                Top = 0
                Width = 798
                Height = 169
                Align = alTop
                Caption = 'Arduino Client'
                TabOrder = 0
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
                object ArduinoServerStartStopButton: TButton
                  Left = 143
                  Top = 25
                  Width = 104
                  Height = 97
                  Caption = 'Start'
                  TabOrder = 1
                  OnClick = ArduinoServerStartStopButtonClick
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
                  Value = True
                end
              end
            end
            object TabSheet4: TTabSheet
              Caption = 'Sounds'
              ImageIndex = 1
              inline TSoundsFrame1: TSoundsFrame
                Left = 0
                Top = 482
                Width = 798
                Height = 303
                Align = alClient
                AutoSize = True
                TabOrder = 0
                ExplicitTop = 482
                ExplicitWidth = 798
                ExplicitHeight = 303
                inherited GroupBox1: TGroupBox
                  Width = 798
                  Height = 303
                  Align = alClient
                  ExplicitWidth = 798
                  ExplicitHeight = 303
                  inherited SoundsLB: TListBox
                    Top = 21
                    Width = 215
                    Height = 280
                    ItemHeight = 19
                    ExplicitTop = 21
                    ExplicitWidth = 215
                    ExplicitHeight = 280
                  end
                end
              end
              inline TApplicationSoundsFrame1: TApplicationSoundsFrame
                Left = 0
                Top = 0
                Width = 798
                Height = 482
                Align = alTop
                AutoSize = True
                TabOrder = 1
                object GBS: TGroupBox
                  Left = 0
                  Top = 0
                  Width = 798
                  Height = 241
                  Align = alTop
                  Caption = 'Application Sounds'
                  TabOrder = 1
                  object ApplicationSoundsLB: TListBox
                    Left = 2
                    Top = 21
                    Width = 247
                    Height = 218
                    Align = alLeft
                    ItemHeight = 19
                    TabOrder = 0
                  end
                  object SoundPropsGB: TGroupBox
                    Left = 249
                    Top = 21
                    Width = 547
                    Height = 218
                    Align = alClient
                    Caption = 'Sound Properties'
                    TabOrder = 1
                    object EnabledCB: TCheckBox
                      Left = 24
                      Top = 143
                      Width = 97
                      Height = 17
                      Caption = 'Enabled'
                      TabOrder = 0
                    end
                    object PlayBtn: TButton
                      Left = 144
                      Top = 105
                      Width = 105
                      Height = 32
                      Caption = 'Play'
                      TabOrder = 1
                    end
                    object RepeatCB: TCheckBox
                      Left = 24
                      Top = 120
                      Width = 97
                      Height = 17
                      Caption = 'Repeat'
                      TabOrder = 2
                      Visible = False
                    end
                    object SoundCB: TComboBox
                      Left = 24
                      Top = 32
                      Width = 233
                      Height = 27
                      TabOrder = 3
                      Text = 'SoundCB'
                    end
                    object VolumeTB: TTrackBar
                      Left = 24
                      Top = 73
                      Width = 233
                      Height = 26
                      Max = 0
                      Min = -10000
                      TabOrder = 4
                      TickStyle = tsNone
                    end
                  end
                end
              end
            end
            object TabSheet11: TTabSheet
              Caption = 'Video Compression'
              ImageIndex = 3
              inline TFFMPEGFrame1: TFFMPEGFrame
                Left = 0
                Top = 0
                Width = 798
                Height = 241
                Align = alTop
                AutoSize = True
                TabOrder = 0
                ExplicitWidth = 798
                inherited GroupBox1: TGroupBox
                  Width = 798
                  Align = alTop
                  ExplicitWidth = 798
                  inherited Label1: TLabel
                    Width = 91
                    Height = 19
                    ExplicitWidth = 91
                    ExplicitHeight = 19
                  end
                  inherited FFMPEGThreads: TIntegerLabeledEdit
                    Height = 27
                    EditLabel.Width = 245
                    EditLabel.Height = 19
                    EditLabel.ExplicitLeft = 17
                    EditLabel.ExplicitTop = 73
                    EditLabel.ExplicitWidth = 245
                    EditLabel.ExplicitHeight = 19
                    ExplicitHeight = 27
                  end
                  inherited CRFValue: TIntegerLabeledEdit
                    Height = 27
                    EditLabel.Width = 122
                    EditLabel.Height = 19
                    EditLabel.ExplicitLeft = 17
                    EditLabel.ExplicitTop = 25
                    EditLabel.ExplicitWidth = 122
                    EditLabel.ExplicitHeight = 19
                    ExplicitHeight = 27
                  end
                  inherited PresetCB: TComboBox
                    Height = 27
                    ExplicitHeight = 27
                  end
                  inherited DeleteSourceFileCB: TPropertyCheckBox
                    Width = 192
                    ExplicitWidth = 192
                  end
                end
              end
            end
            object RibbonSeparatorSheet: TTabSheet
              Caption = 'Ribbon Separator'
              ImageIndex = 4
              object GroupBox10: TGroupBox
                Left = 0
                Top = 73
                Width = 798
                Height = 128
                Align = alTop
                Caption = 'Window Mouse Clicker'
                TabOrder = 0
                object winXLbl: TLabel
                  Left = 40
                  Top = 40
                  Width = 20
                  Height = 19
                  Caption = 'X: '
                end
                object winYLbl: TLabel
                  Left = 40
                  Top = 79
                  Width = 21
                  Height = 19
                  Caption = 'Y: '
                end
                object ClickXE: TIntegerLabeledEdit
                  Left = 168
                  Top = 56
                  Width = 121
                  Height = 27
                  EditLabel.Width = 47
                  EditLabel.Height = 19
                  EditLabel.Caption = 'Click X'
                  TabOrder = 0
                  Text = '0'
                end
                object ClickYE: TIntegerLabeledEdit
                  Left = 328
                  Top = 56
                  Width = 121
                  Height = 27
                  EditLabel.Width = 48
                  EditLabel.Height = 19
                  EditLabel.Caption = 'Click Y'
                  TabOrder = 1
                  Text = '0'
                end
                object TestClickWindowBtn: TButton
                  Left = 496
                  Top = 38
                  Width = 105
                  Height = 64
                  Caption = 'Click'
                  TabOrder = 2
                  OnClick = TestClickWindowBtnClick
                end
              end
              object Panel12: TPanel
                Left = 0
                Top = 0
                Width = 798
                Height = 73
                Align = alTop
                BevelOuter = bvNone
                TabOrder = 1
                object WindowCheckLbl: TLabel
                  Left = 304
                  Top = 32
                  Width = 120
                  Height = 19
                  Caption = 'WindowCheckLbl'
                end
                object WinCaptionE: TSTDStringLabeledEdit
                  Left = 8
                  Top = 36
                  Width = 241
                  Height = 27
                  EditLabel.Width = 116
                  EditLabel.Height = 19
                  EditLabel.Caption = 'Window Caption'
                  TabOrder = 0
                  Text = 'ELLO'
                  Value = 'ELLO'
                end
              end
            end
          end
        end
        object TabSheet10: TTabSheet
          Caption = 'Lights'
          ImageIndex = 7
          object LightIntensitiesGB: TGroupBox
            Left = 3
            Top = 16
            Width = 350
            Height = 105
            Caption = 'Light Intensities'
            TabOrder = 0
            object mFrontLEDLbl: TLabel
              Left = 151
              Top = 26
              Width = 28
              Height = 19
              Caption = 'LED'
            end
            object Panel10: TPanel
              Left = 2
              Top = 21
              Width = 143
              Height = 82
              Align = alLeft
              BevelOuter = bvNone
              TabOrder = 0
              object FrontLEDTB: TTrackBar
                Left = 0
                Top = 0
                Width = 143
                Height = 40
                Align = alTop
                Max = 255
                TabOrder = 0
                ThumbLength = 30
                TickStyle = tsNone
                OnChange = FrontLEDTBChange
              end
            end
          end
        end
      end
      object Button1: TButton
        Left = 783
        Top = 1
        Width = 25
        Height = 25
        Action = ToggleMainContentPanelA
        Anchors = [akTop, akRight]
        Caption = 'x'
        TabOrder = 1
      end
    end
  end
  object LeftPanel: TPanel
    Left = 0
    Top = 84
    Width = 965
    Height = 857
    Align = alClient
    BevelEdges = []
    TabOrder = 1
    object mMainPhotoPanel: TPanel
      Left = 1
      Top = 1
      Width = 963
      Height = 855
      Margins.Left = 0
      Margins.Right = 0
      Align = alClient
      BevelEdges = []
      BevelOuter = bvNone
      TabOrder = 0
      OnResize = mMainPhotoPanelResize
      object mCamera1BackPanel: TPanel
        Left = 1
        Top = 0
        Width = 850
        Height = 673
        Margins.Left = 0
        Margins.Right = 0
        BevelOuter = bvNone
        Caption = 'No Camera...'
        TabOrder = 0
        object mPB: TPaintBox
          Left = 0
          Top = 30
          Width = 850
          Height = 643
          Margins.Left = 0
          Margins.Top = 0
          Margins.Right = 0
          Margins.Bottom = 0
          Align = alClient
          Color = clActiveCaption
          ParentColor = False
          PopupMenu = CameraPopup
          OnMouseDown = mPBMouseDown
          OnMouseMove = mPBMouseMove
          OnMouseUp = mPBMouseUp
          ExplicitTop = 33
        end
        object CameraHC: THeaderControl
          Left = 0
          Top = 0
          Width = 850
          Height = 30
          BiDiMode = bdLeftToRight
          Sections = <
            item
              Alignment = taCenter
              BiDiMode = bdLeftToRight
              ImageIndex = -1
              ParentBiDiMode = False
              Text = 'Camera Settings'
              Width = 130
            end
            item
              Alignment = taCenter
              ImageIndex = -1
              Text = 'Reticle Settings'
              Width = 150
            end
            item
              Alignment = taCenter
              ImageIndex = -1
              Text = 'Show Reticle'
              Width = 110
            end
            item
              Alignment = taCenter
              ImageIndex = -1
              Text = 'Reset Reticle'
              Width = 110
            end
            item
              Alignment = taCenter
              ImageIndex = -1
              Text = 'Maximize Camera View'
              Width = 180
            end
            item
              ImageIndex = -1
              Text = 'Show Image Center'
              Width = 160
            end>
          OnSectionClick = CameraHCSectionClick
          ParentBiDiMode = False
          PopupMenu = CameraPopup
          StyleElements = [seFont, seClient]
        end
      end
      object MPEGPanel: TFlowPanel
        Left = 0
        Top = 0
        Width = 963
        Height = 100
        Align = alTop
        AutoSize = True
        TabOrder = 1
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 941
    Width = 1817
    Height = 22
    Hint = 'Test'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    Panels = <>
    UseSystemFont = False
    OnHint = StatusBar1Hint
  end
  object ControlBar1: TControlBar
    Left = 0
    Top = 0
    Width = 1817
    Height = 84
    Align = alTop
    AutoDock = False
    DockSite = False
    DragMode = dmAutomatic
    DrawingStyle = dsGradient
    TabOrder = 3
    OnStartDrag = ControlBar1StartDrag
    object ToolBar1: TToolBar
      Left = 1330
      Top = 2
      Width = 327
      Height = 75
      AutoSize = True
      ButtonHeight = 75
      Caption = 'ToolBar1'
      TabOrder = 0
      object ArrayBotButton1: TArrayBotButton
        Left = 0
        Top = 0
        Width = 145
        Height = 75
        Action = OpenHandWheelPositionFormA
        Caption = 'Open Handwheel Position Form'
        TabOrder = 1
        WordWrap = True
        SoundID = 'BUTTON_CLICK_4'
      end
      object ArrayBotButton2: TArrayBotButton
        Left = 145
        Top = 0
        Width = 168
        Height = 75
        Hint = 'Open Handwheel position Form'
        Caption = 'Open Logger Form'
        TabOrder = 0
        WordWrap = True
        OnClick = OpenLoggerForm1Click
        SoundID = 'BUTTON_CLICK_4'
      end
    end
    object CounterGB: TGroupBox
      Left = 11
      Top = 2
      Width = 614
      Height = 74
      Align = alTop
      TabOrder = 1
      object SectionCounterLabel: TIntLabel
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
        OnClick = CountLabelClick
        Value = 1
        TheFont.Charset = DEFAULT_CHARSET
        TheFont.Color = clWindowText
        TheFont.Height = -29
        TheFont.Name = 'Tahoma'
        TheFont.Style = []
      end
      object RibbonOrderCountLabel: TIntLabel
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
        OnClick = CountLabelClick
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
      object RibbonLengthLbl: mtkFloatLabel
        Left = 448
        Top = 39
        Width = 38
        Height = 19
        Caption = '-1.00'
        ValueString = '-1.00'
        Value = -1.000000000000000000
        TheFont.Charset = DEFAULT_CHARSET
        TheFont.Color = clWindowText
        TheFont.Height = -16
        TheFont.Name = 'Tahoma'
        TheFont.Style = []
      end
      object Label19: TLabel
        Left = 448
        Top = 14
        Width = 148
        Height = 19
        Caption = 'Ribbon Length (mm)'
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
    end
    object ToolBar2: TToolBar
      Left = 805
      Top = 2
      Width = 363
      Height = 100
      ButtonHeight = 75
      Caption = 'ToolBar2'
      TabOrder = 2
      object RecordVideoBtn: TArrayBotButton
        Left = 0
        Top = 0
        Width = 180
        Height = 75
        Align = alLeft
        Caption = 'Record Video'
        TabOrder = 0
        OnClick = RecordVideoBtnClick
        SoundID = 'BUTTON_CLICK_4'
      end
      object TakeSnapShotBtn: TArrayBotButton
        Left = 180
        Top = 0
        Width = 161
        Height = 75
        Align = alLeft
        Caption = 'Take SnapShot'
        TabOrder = 1
        OnClick = TakeSnapShotBtnClick
        SoundID = 'BUTTON_CLICK_4'
      end
    end
  end
  object ToggleMainContentBtn: TButton
    Left = 1786
    Top = 84
    Width = 31
    Height = 857
    Action = ToggleMainContentPanelA
    Align = alRight
    Caption = '<'
    TabOrder = 4
    Visible = False
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    UseAppManager = True
    Left = 148
    Top = 165
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
    Left = 672
    Top = 432
  end
  object mMediaPopup: TPopupMenu
    Left = 304
    Top = 264
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
  object CheckArduinoServerConnectionTimer: TTimer
    Enabled = False
    Interval = 3000
    OnTimer = CheckArduinoServerConnectionTimerTimer
    Left = 368
    Top = 216
  end
  object CameraPopup: TPopupMenu
    Left = 120
    Top = 304
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
    object N7: TMenuItem
      Caption = '-'
    end
    object oggleControlBar1: TMenuItem
      Action = ToggleControlBar
      AutoCheck = True
    end
  end
  object ReticlePopup: TPopupMenu
    Left = 256
    Top = 128
    object Reset1: TMenuItem
      Caption = 'Reset'
    end
  end
  object MainMenu1: TMainMenu
    Left = 192
    Top = 168
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
      object ShowHideMainContentPanel1: TMenuItem
        Action = ToggleMainContentPanelA
        AutoCheck = True
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object UC7StatusChart1: TMenuItem
        Action = OpenHandWheelPositionFormA
      end
      object OpenLoggerForm1: TMenuItem
        Caption = 'Open Logger Form'
        OnClick = OpenLoggerForm1Click
      end
      object Actions1: TMenuItem
        Action = OpenCloseShortcutForm
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object Hide1: TMenuItem
        Action = ToggleControlBar
        AutoCheck = True
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
    Left = 96
    Top = 144
    object FileExit1: TFileExit
      Category = 'File'
      Caption = 'E&xit'
      Hint = 'Exit|Quits the application'
      ImageIndex = 43
    end
    object OpenHandWheelPositionFormA: TAction
      Category = 'File'
      Caption = 'Open Handwheel Position Form'
      Hint = 'Open Handwheel position Form'
      OnExecute = OpenHandWheelPositionFormAExecute
    end
    object ToggleMainContentPanelA: TAction
      Category = 'File'
      AutoCheck = True
      Caption = 'Show/Hide Main Content Panel'
      OnExecute = ToggleMainContentPanelAExecute
    end
    object OpenCloseShortcutForm: TAction
      Category = 'File'
      Caption = 'Open Actions'
      OnExecute = OpenCloseShortcutFormExecute
      OnUpdate = OpenCloseShortcutFormUpdate
    end
    object ToggleControlBar: TAction
      Category = 'Misc'
      AutoCheck = True
      Caption = 'Toggle ControlBar'
      OnExecute = ToggleControlBarExecute
      OnUpdate = ToggleControlBarUpdate
    end
    object BrowseForFolder1: TBrowseForFolder
      Category = 'File'
      Caption = '...'
      DialogCaption = 'BrowseForFolder1'
      BrowseOptions = [bifEditBox, bifNewDialogStyle, bifUseNewUI]
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
      Caption = 'More Settings'
      Hint = 'Open Camera settings form'
      OnExecute = OpenCameraSettingsAExecute
    end
  end
  object BindingsList2: TBindingsList
    Methods = <>
    OutputConverters = <>
    UseAppManager = True
    Left = 672
    Top = 16
  end
  object VideoRecTimer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = VideoRecTimerTimer
    Left = 664
    Top = 504
  end
  object CleanupTimer: TTimer
    Enabled = False
    Interval = 300
    OnTimer = CleanupTimerTimer
    Left = 648
    Top = 264
  end
  object MouseClickTimer: TTimer
    Enabled = False
    Interval = 50
    OnTimer = MouseClickTimerTimer
    Left = 1056
    Top = 568
  end
end
