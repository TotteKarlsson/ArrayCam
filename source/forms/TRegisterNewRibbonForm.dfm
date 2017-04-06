object RegisterNewRibbonForm: TRegisterNewRibbonForm
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Register New Ribbon'
  ClientHeight = 546
  ClientWidth = 893
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCloseQuery = FormCloseQuery
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 16
    Top = 24
    Width = 401
    Height = 241
    Caption = 'Origin'
    TabOrder = 0
    object mBlocksForRibbonsGrid: TDBGrid
      Left = 22
      Top = 24
      Width = 291
      Height = 201
      DataSource = atdbDM.blocksDataSource
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'label'
          Width = 50
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'process_id'
          Width = 50
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Lprocess_id'
          Width = 50
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'serial'
          Width = 50
          Visible = True
        end>
    end
  end
  object GroupBox2: TGroupBox
    Left = 463
    Top = 24
    Width = 402
    Height = 241
    Caption = 'Coverslip'
    TabOrder = 1
  end
  object Panel1: TPanel
    Left = 0
    Top = 464
    Width = 893
    Height = 82
    Align = alBottom
    TabOrder = 2
    DesignSize = (
      893
      82)
    object mCloseBtn: TArrayBotButton
      Left = 773
      Top = 16
      Width = 110
      Height = 57
      Anchors = [akTop, akRight]
      Caption = 'Close'
      TabOrder = 0
      SoundID = 'BUTTON_CLICK_4'
    end
  end
end
