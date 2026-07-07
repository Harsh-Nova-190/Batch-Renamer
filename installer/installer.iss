;------------------------------------------------------------
; NovaBytes Batch Renamer Installer
; Company : NovaBytes
;------------------------------------------------------------

#define MyAppName "NovaBytes Batch Renamer"
#define MyAppVersion "1.0.0"
#define MyAppPublisher "NovaBytes"
#define MyAppURL "https://github.com/Harsh-Nova-190/Batch-Renamer"
#define MyAppExeName "NovaBytesBatchRenamer.exe"

[Setup]
AppId={{8C0A4A1E-0D62-4B92-8F6A-8F82D3D9C001}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}

DefaultDirName={autopf}\NovaBytes\Batch Renamer
DefaultGroupName=NovaBytes

DisableProgramGroupPage=yes

LicenseFile=..\LICENSE

OutputDir=Output
OutputBaseFilename=NovaBytesBatchRenamerSetup-1.0.0-Setup

Compression=lzma2
SolidCompression=yes

WizardStyle=modern

SetupIconFile=..\resources\branding\NovaBytes.ico

PrivilegesRequired=lowest

ArchitecturesAllowed=x64compatible
ArchitecturesInstallIn64BitMode=x64compatible

UninstallDisplayIcon={app}\NovaBytesBatchRenamer.exe

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "Create a desktop shortcut"; Flags: unchecked

[Files]
Source: "..\dist\NovaBytesBatchRenamer\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{autoprograms}\NovaBytes\NovaBytes Batch Renamer"; Filename: "{app}\NovaBytesBatchRenamer.exe"

Name: "{autodesktop}\NovaBytes Batch Renamer"; Filename: "{app}\NovaBytesBatchRenamer.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\NovaBytesBatchRenamer.exe"; Description: "Launch NovaBytes Batch Renamer"; Flags: nowait postinstall skipifsilent