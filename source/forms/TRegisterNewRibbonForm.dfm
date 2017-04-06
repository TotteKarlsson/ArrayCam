object RegisterNewRibbonForm: TRegisterNewRibbonForm
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Register New Ribbon'
  ClientHeight = 531
  ClientWidth = 821
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
    Width = 385
    Height = 449
    Align = alLeft
    Caption = 'Ribbon Origin'
    TabOrder = 0
    object Splitter1: TSplitter
      Left = 125
      Top = 21
      Height = 426
      ExplicitLeft = 160
      ExplicitTop = 192
      ExplicitHeight = 100
    end
    object DBGrid1: TDBGrid
      AlignWithMargins = True
      Left = 12
      Top = 31
      Width = 103
      Height = 406
      Margins.Left = 10
      Margins.Top = 10
      Margins.Right = 10
      Margins.Bottom = 10
      Align = alLeft
      DataSource = atdbDM.specimenDataSource
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgMultiSelect, dgTitleClick, dgTitleHotTrack]
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -16
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      Columns = <
        item
          Alignment = taLeftJustify
          Expanded = False
          FieldName = 'process_id'
          Width = 126
          Visible = True
        end>
    end
    object Panel2: TPanel
      Left = 128
      Top = 21
      Width = 255
      Height = 426
      Align = alClient
      Caption = 'Panel2'
      TabOrder = 1
      ExplicitLeft = 108
      ExplicitTop = 15
      ExplicitWidth = 187
      ExplicitHeight = 432
      object mRibbonNavigator: TDBNavigator
        Left = 1
        Top = 400
        Width = 253
        Height = 25
        DataSource = atdbDM.blocksDataSource
        Align = alBottom
        TabOrder = 0
        OnClick = mRibbonNavigatorClick
        ExplicitTop = 406
        ExplicitWidth = 200
      end
      object mBlocksForRibbonsGrid: TDBGrid
        AlignWithMargins = True
        Left = 11
        Top = 11
        Width = 233
        Height = 379
        Margins.Left = 10
        Margins.Top = 10
        Margins.Right = 10
        Margins.Bottom = 10
        Align = alClient
        DataSource = atdbDM.blocksDataSource
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
            FieldName = 'label'
            Width = 133
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'serial'
            Width = 92
            Visible = True
          end>
      end
    end
  end
  object GroupBox2: TGroupBox
    Left = 385
    Top = 0
    Width = 436
    Height = 449
    Align = alClient
    Caption = 'Coverslip'
    TabOrder = 1
    ExplicitLeft = 388
    ExplicitWidth = 402
    ExplicitHeight = 241
    object mCSBarcode: TLabel
      Left = 144
      Top = 37
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
      Top = 45
      Width = 93
      Height = 19
      Caption = 'Coverslip ID:'
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 449
    Width = 821
    Height = 82
    Align = alBottom
    TabOrder = 2
    DesignSize = (
      821
      82)
    object mCloseBtn: TArrayBotButton
      Left = 701
      Top = 16
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
end
