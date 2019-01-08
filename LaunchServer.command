#!/bin/sh

source "`dirname "$0"`"/ProjectPaths.sh
$UNREAL_HOME/Engine/Binaries/Mac/UE4Editor.app/Contents/MacOS/UE4Editor "`dirname "$0"`/$PROJECT_PATH/$GAME_NAME.uproject" ThirdPersonExampleMap -server -log -workerType UnrealWorker -stdout -nowrite -unattended -nologtimes -nopause -noin -messaging -SaveToUserDir -NoVerifyGC -windowed -resX=400 -resY=300
