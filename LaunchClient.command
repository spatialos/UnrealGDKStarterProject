#!/bin/sh

source "`dirname "$0"`"/ProjectPaths.sh
$UNREAL_HOME/Engine/Binaries/Mac/UE4Editor.app/Contents/MacOS/UE4Editor "`dirname "$0"`/$PROJECT_PATH/$GAME_NAME.uproject" 127.0.0.1 -game -log -workerType UnrealClient -stdout -nowrite -unattended -nologtimes -nopause -noin -messaging -NoVerifyGC -windowed -ResX=800 -ResY=600
