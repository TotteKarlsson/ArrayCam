; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName       "ArrayCam"
#define MyAppVersion    "0.6.2"
#define MyAppPublisher  "Smith Lab"
#define MyAppURL        "http://www.example.com/"
#define MyAppExeName    "ArrayCam.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId                       = {{F30EB32C-5FDB-4CDA-913D-E3DFC186AB6F}}
AppName                     = {#MyAppName}
AppVersion                  = {#MyAppVersion}
AppVerName                  = {#MyAppName}_{#MyAppVersion}
AppPublisher                = {#MyAppPublisher}
AppPublisherURL             = {#MyAppURL}
AppSupportURL               = {#MyAppURL}
AppUpdatesURL               = {#MyAppURL}
DefaultDirName              = {pf}\{#MyAppName}
DisableProgramGroupPage     = yes
OutputBaseFilename          = {#MyAppName}-{#MyAppVersion}
OutputDir                   = x:\atSoftwareReleases
Compression                 = lzma
SolidCompression            = yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "P:\AppReleases\ArrayCam\ArrayCam.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "P:\ArrayBot\db\atDB.db";               DestDir: "{localappdata}\ArrayBot"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "P:\AppReleases\ArrayCam\*";            DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{commonprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

