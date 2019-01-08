#!/bin/sh

source "`dirname "$0"`"/ProjectPaths.sh
$UNREAL_HOME/Engine/Binaries/Mac/UE4Editor.app/Contents/MacOS/UE4Editor "`dirname "$0"`/$PROJECT_PATH/$GAME_NAME.uproject" 10.249.84.117 -receptionistHost 10.249.84.117 -game -log -workerType UnrealClient -linkProtocol Tcp -useExternalIpForBridge true -stdout -nowrite -unattended -nologtimes -nopause -noin -messaging -NoVerifyGC -windowed -ResX=800 -ResY=600
