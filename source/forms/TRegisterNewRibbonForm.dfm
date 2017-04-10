object RegisterNewRibbonForm: TRegisterNewRibbonForm
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Register New Ribbon'
  ClientHeight = 718
  ClientWidth = 943
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 19
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 297
    Height = 638
    Align = alLeft
    Caption = 'Ribbon Origin'
    TabOrder = 0
    object Splitter1: TSplitter
      Left = 2
      Top = 21
      Height = 615
      ExplicitLeft = 160
      ExplicitTop = 192
      ExplicitHeight = 100
    end
    object GroupBox3: TGroupBox
      Left = 5
      Top = 21
      Width = 290
      Height = 615
      Align = alClient
      Caption = 'Ribbons'
      TabOrder = 0
      object mBlocksForRibbonsGrid: TDBGrid
        AlignWithMargins = True
        Left = 12
        Top = 31
        Width = 266
        Height = 531
        Margins.Left = 10
        Margins.Top = 10
        Margins.Right = 10
        Margins.Bottom = 10
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
            FieldName = 'cutting_order'
            Width = 109
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'nr_of_sections'
            Width = 124
            Visible = True
          end>
      end
      object mRibbonNavigator: TDBNavigator
        Left = 2
        Top = 572
        Width = 286
        Height = 41
        DataSource = atdbDM.mRibbonDSource
        VisibleButtons = [nbPrior, nbNext, nbInsert, nbDelete, nbPost, nbCancel, nbRefresh, nbApplyUpdates, nbCancelUpdates]
        Align = alBottom
        TabOrder = 1
        OnClick = mRibbonNavigatorClick
      end
    end
  end
  object GroupBox2: TGroupBox
    Left = 297
    Top = 0
    Width = 646
    Height = 638
    Align = alClient
    Caption = 'Coverslip and Ribbon Details'
    TabOrder = 1
    object mCSBarcode: TLabel
      Left = 144
      Top = 129
      Width = 92
      Height = 29
      Caption = 'C000123'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 24
      Top = 137
      Width = 93
      Height = 19
      Caption = 'Coverslip ID:'
    end
    object Label2: TLabel
      Left = 24
      Top = 164
      Width = 139
      Height = 19
      Caption = 'Number of Sections'
    end
    object DBText1: TDBText
      Left = 364
      Top = 21
      Width = 236
      Height = 17
      DataField = 'id'
      DataSource = atdbDM.mRibbonDSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 160
      Top = 40
      Width = 65
      Height = 17
      DataField = 'user_name'
      DataSource = atdbDM.usersDataSource
    end
    object Label3: TLabel
      Left = 24
      Top = 40
      Width = 38
      Height = 19
      Caption = 'User:'
    end
    object Label4: TLabel
      Left = 24
      Top = 244
      Width = 97
      Height = 19
      Caption = 'Cutting Order'
    end
    object Label5: TLabel
      Left = 24
      Top = 71
      Width = 123
      Height = 19
      Caption = 'Block Process ID:'
    end
    object DBText3: TDBText
      Left = 160
      Top = 71
      Width = 97
      Height = 17
      DataField = 'process_id'
      DataSource = atdbDM.blocksDataSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 318
      Top = 71
      Width = 87
      Height = 19
      Caption = 'Block Serial:'
    end
    object DBText4: TDBText
      Left = 411
      Top = 71
      Width = 97
      Height = 17
      DataField = 'serial'
      DataSource = atdbDM.blocksDataSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 24
      Top = 99
      Width = 85
      Height = 19
      Caption = 'Block Label:'
    end
    object DBText5: TDBText
      Left = 160
      Top = 99
      Width = 152
      Height = 17
      DataField = 'label'
      DataSource = atdbDM.blocksDataSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object DBText6: TDBText
      Left = 216
      Top = 202
      Width = 152
      Height = 36
      DataField = 'nr_of_sections'
      DataSource = atdbDM.mRibbonDSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object DBText7: TDBText
      Left = 216
      Top = 283
      Width = 152
      Height = 36
      DataField = 'cutting_order'
      DataSource = atdbDM.mRibbonDSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object GroupBox5: TGroupBox
      Left = 2
      Top = 344
      Width = 642
      Height = 292
      Align = alBottom
      Caption = 'Ribbon Notes'
      TabOrder = 0
      object mRibbonNotesGrid: TDBGrid
        Left = 12
        Top = 58
        Width = 156
        Height = 187
        DataSource = atdbDM.ribbonNotesDSource
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
            Width = 142
            Visible = True
          end>
      end
      object mRibbonNoteMemo: TDBMemo
        Left = 184
        Top = 24
        Width = 401
        Height = 192
        DataField = 'note'
        DataSource = atdbDM.ribbonNotesDSource
        TabOrder = 1
      end
      object mRibbonNoteNavigator: TDBNavigator
        Left = 184
        Top = 222
        Width = 400
        Height = 25
        DataSource = atdbDM.ribbonNotesDSource
        VisibleButtons = [nbPost, nbCancel]
        TabOrder = 2
      end
      object mRibbonNotesNavigator: TDBNavigator
        Left = 10
        Top = 27
        Width = 156
        Height = 25
        DataSource = atdbDM.ribbonNotesDSource
        VisibleButtons = [nbInsert, nbDelete, nbRefresh, nbApplyUpdates]
        ConfirmDelete = False
        TabOrder = 3
        OnClick = mRibbonNotesNavigatorClick
      end
    end
    object mDecrementCuttingOrderBtn: TArrayBotButton
      Left = 105
      Top = 269
      Width = 75
      Height = 50
      Caption = '-'
      TabOrder = 1
      OnClick = miscBtnClick
      SoundID = 'BUTTON_CLICK_4'
    end
    object mIncrementSectionBtn: TArrayBotButton
      Left = 24
      Top = 188
      Width = 75
      Height = 50
      Caption = '+'
      TabOrder = 2
      OnClick = miscBtnClick
      SoundID = 'BUTTON_CLICK_4'
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 638
    Width = 943
    Height = 80
    Align = alBottom
    TabOrder = 2
    DesignSize = (
      943
      80)
    object mCloseBtn: TArrayBotButton
      Left = 823
      Top = 13
      Width = 110
      Height = 57
      Anchors = [akTop, akRight]
      Caption = 'Close'
      ModalResult = 1
      TabOrder = 0
      OnClick = mCloseBtnClick
      SoundID = 'BUTTON_CLICK_4'
    end
  end
  object mDecrementSectionBtn: TArrayBotButton
    Left = 402
    Top = 188
    Width = 75
    Height = 50
    Caption = '-'
    TabOrder = 3
    OnClick = miscBtnClick
    SoundID = 'BUTTON_CLICK_4'
  end
  object mIncrementCuttingOrderBtn: TArrayBotButton
    Left = 321
    Top = 269
    Width = 75
    Height = 50
    Caption = '+'
    TabOrder = 4
    OnClick = miscBtnClick
    SoundID = 'BUTTON_CLICK_4'
  end
end
