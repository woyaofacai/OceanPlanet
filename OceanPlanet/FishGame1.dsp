# Microsoft Developer Studio Project File - Name="FishGame1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=FishGame1 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FishGame1.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FishGame1.mak" CFG="FishGame1 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FishGame1 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "FishGame1 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FishGame1 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "FishGame1 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib hge.lib hgehelp.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "FishGame1 - Win32 Release"
# Name "FishGame1 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AboutComponent.cpp
# End Source File
# Begin Source File

SOURCE=.\AccelerateProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ArcadeOverPanel.cpp
# End Source File
# Begin Source File

SOURCE=.\Bait.cpp
# End Source File
# Begin Source File

SOURCE=.\BaitCollection.cpp
# End Source File
# Begin Source File

SOURCE=.\Bomb.cpp
# End Source File
# Begin Source File

SOURCE=.\BombCollection.cpp
# End Source File
# Begin Source File

SOURCE=.\BombState.cpp
# End Source File
# Begin Source File

SOURCE=.\Bubble.cpp
# End Source File
# Begin Source File

SOURCE=.\ControlPanel.cpp
# End Source File
# Begin Source File

SOURCE=.\CutsceneComponent.cpp
# End Source File
# Begin Source File

SOURCE=.\DecelerateProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ExplodeBombState.cpp
# End Source File
# Begin Source File

SOURCE=.\FinalWinComponent.cpp
# End Source File
# Begin Source File

SOURCE=.\Fish.cpp
# End Source File
# Begin Source File

SOURCE=.\FishCollection.cpp
# End Source File
# Begin Source File

SOURCE=.\FishFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\Game.cpp
# End Source File
# Begin Source File

SOURCE=.\GameButton.cpp
# End Source File
# Begin Source File

SOURCE=.\GameComponent.cpp
# End Source File
# Begin Source File

SOURCE=.\GameModel.cpp
# End Source File
# Begin Source File

SOURCE=.\GameState.cpp
# End Source File
# Begin Source File

SOURCE=.\GradientSprite.cpp
# End Source File
# Begin Source File

SOURCE=.\HarvestProp.cpp
# End Source File
# Begin Source File

SOURCE=.\HarvestSpriteProduceStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\MainMenuItem.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuButton.cpp
# End Source File
# Begin Source File

SOURCE=.\Needle.cpp
# End Source File
# Begin Source File

SOURCE=.\NeedleCollection.cpp
# End Source File
# Begin Source File

SOURCE=.\NeedleFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\OpeningComponent.cpp
# End Source File
# Begin Source File

SOURCE=.\PlacedBombState.cpp
# End Source File
# Begin Source File

SOURCE=.\Prop.cpp
# End Source File
# Begin Source File

SOURCE=.\PropCollection.cpp
# End Source File
# Begin Source File

SOURCE=.\ResourceFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\RunningComponent.cpp
# End Source File
# Begin Source File

SOURCE=.\RunningSpriteProduceStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\RunningStateData.cpp
# End Source File
# Begin Source File

SOURCE=.\ScoreAnimation.cpp
# End Source File
# Begin Source File

SOURCE=.\SeaBackGround.cpp
# End Source File
# Begin Source File

SOURCE=.\Skeleten.cpp
# End Source File
# Begin Source File

SOURCE=.\Sprite.cpp
# End Source File
# Begin Source File

SOURCE=.\SpriteFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\SpriteProduceStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\StateEntity.cpp
# End Source File
# Begin Source File

SOURCE=.\TaskFailPanel.cpp
# End Source File
# Begin Source File

SOURCE=.\TaskPassPanel.cpp
# End Source File
# Begin Source File

SOURCE=.\TaskResultPanel.cpp
# End Source File
# Begin Source File

SOURCE=.\TotalScoreAnimation.cpp
# End Source File
# Begin Source File

SOURCE=.\Treasure.cpp
# End Source File
# Begin Source File

SOURCE=.\UnplacedBombState.cpp
# End Source File
# Begin Source File

SOURCE=.\WelcomeComponent.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AboutComponent.h
# End Source File
# Begin Source File

SOURCE=.\AccelerateProp.h
# End Source File
# Begin Source File

SOURCE=.\ArcadeOverPanel.h
# End Source File
# Begin Source File

SOURCE=.\Bait.h
# End Source File
# Begin Source File

SOURCE=.\BaitCollection.h
# End Source File
# Begin Source File

SOURCE=.\Bomb.h
# End Source File
# Begin Source File

SOURCE=.\BombCollection.h
# End Source File
# Begin Source File

SOURCE=.\BombState.h
# End Source File
# Begin Source File

SOURCE=.\Bubble.h
# End Source File
# Begin Source File

SOURCE=.\constants.h
# End Source File
# Begin Source File

SOURCE=.\ControlPanel.h
# End Source File
# Begin Source File

SOURCE=.\CutsceneComponent.h
# End Source File
# Begin Source File

SOURCE=.\DecelerateProp.h
# End Source File
# Begin Source File

SOURCE=.\ExplodeBombState.h
# End Source File
# Begin Source File

SOURCE=.\FinalWinComponent.h
# End Source File
# Begin Source File

SOURCE=.\Fish.h
# End Source File
# Begin Source File

SOURCE=.\FishCollection.h
# End Source File
# Begin Source File

SOURCE=.\FishFactory.h
# End Source File
# Begin Source File

SOURCE=.\Game.h
# End Source File
# Begin Source File

SOURCE=.\GameButton.h
# End Source File
# Begin Source File

SOURCE=.\GameComponent.h
# End Source File
# Begin Source File

SOURCE=.\GameModel.h
# End Source File
# Begin Source File

SOURCE=.\GameState.h
# End Source File
# Begin Source File

SOURCE=.\GradientSprite.h
# End Source File
# Begin Source File

SOURCE=.\HarvestProp.h
# End Source File
# Begin Source File

SOURCE=.\HarvestSpriteProduceStrategy.h
# End Source File
# Begin Source File

SOURCE=.\MainMenuItem.h
# End Source File
# Begin Source File

SOURCE=.\MenuButton.h
# End Source File
# Begin Source File

SOURCE=.\Needle.h
# End Source File
# Begin Source File

SOURCE=.\NeedleCollection.h
# End Source File
# Begin Source File

SOURCE=.\NeedleFactory.h
# End Source File
# Begin Source File

SOURCE=.\OpeningComponent.h
# End Source File
# Begin Source File

SOURCE=.\PlacedBombState.h
# End Source File
# Begin Source File

SOURCE=.\Prop.h
# End Source File
# Begin Source File

SOURCE=.\PropCollection.h
# End Source File
# Begin Source File

SOURCE=.\ResourceFactory.h
# End Source File
# Begin Source File

SOURCE=.\RunningComponent.h
# End Source File
# Begin Source File

SOURCE=.\RunningSpriteProduceStrategy.h
# End Source File
# Begin Source File

SOURCE=.\RunningStateData.h
# End Source File
# Begin Source File

SOURCE=.\ScoreAnimation.h
# End Source File
# Begin Source File

SOURCE=.\ScriptEngine.h
# End Source File
# Begin Source File

SOURCE=.\SeaBackGround.h
# End Source File
# Begin Source File

SOURCE=.\Skeleten.h
# End Source File
# Begin Source File

SOURCE=.\Sprite.h
# End Source File
# Begin Source File

SOURCE=.\SpriteFactory.h
# End Source File
# Begin Source File

SOURCE=.\SpriteProduceStrategy.h
# End Source File
# Begin Source File

SOURCE=.\StateEntity.h
# End Source File
# Begin Source File

SOURCE=.\TaskFailPanel.h
# End Source File
# Begin Source File

SOURCE=.\TaskPassPanel.h
# End Source File
# Begin Source File

SOURCE=.\TaskResultPanel.h
# End Source File
# Begin Source File

SOURCE=.\TotalScoreAnimation.h
# End Source File
# Begin Source File

SOURCE=.\Treasure.h
# End Source File
# Begin Source File

SOURCE=.\UnplacedBombState.h
# End Source File
# Begin Source File

SOURCE=.\util.h
# End Source File
# Begin Source File

SOURCE=.\WelcomeComponent.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
