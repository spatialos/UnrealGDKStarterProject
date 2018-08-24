#!/usr/bin/env bash

set -e -u -x -o pipefail

cd "$(dirname "$0")/../"

source ci/profiling.sh

markStartOfBlock "$0"

source ci/prepare_build_environment.sh

markStartOfBlock "Build the StarterProject (Windows)"
  # Build each target to ensure scripts are correct, skipping code generation on all but the first to save some time.
  Game/Scripts/BuildWorker.bat "StarterProjectEditor" "Win64" "Development" "StarterProject.uproject"
  if [[ ! -f "spatial/build/assembly/worker/UnrealEditor@Windows.zip" ]]; then
    echo "Editor was not properly built."
    exit 1
  fi

  Game/Scripts/BuildWorker.bat "StarterProject" "Win64" "Development" "StarterProject.uproject" --skip-codegen
  if [[ ! -f "spatial/build/assembly/worker/UnrealClient@Windows.zip" ]]; then
     echo "Client was not properly built."
     exit 1
  fi
markEndOfBlock "Build the StarterProject (Windows)"

markEndOfBlock "$0"
