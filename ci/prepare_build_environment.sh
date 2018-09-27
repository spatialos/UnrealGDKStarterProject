#!/usr/bin/env bash

source ci/pinned-tools.sh

if ! isTeamCity ; then
  echo "This script should only be run on the CI agents."
  exit 0
fi

if ! isWindows ; then
  echo "Starter project can only be built on Windows."
  exit 0
fi

if [ -z "${UNREAL_GDK_BRANCH+x}" ]; then
  echo "The UNREAL_GDK_BRANCH variable was not set, using master as default."
  UNREAL_GDK_BRANCH="master"
fi

UNREAL_GDK_INSTALL_DIRECTORY="Game/Plugins"

markStartOfBlock "Clean gdk build directory"
  rm -rf ${UNREAL_GDK_INSTALL_DIRECTORY}
  mkdir -p ${UNREAL_GDK_INSTALL_DIRECTORY}
markEndOfBlock "Clean gdk build directory"

markStartOfBlock "Clone the GDK from github"
  pushd "${UNREAL_GDK_INSTALL_DIRECTORY}"
    git clone git@github.com:improbable/UnrealGDK.git -b ${UNREAL_GDK_BRANCH} --single-branch
  popd
markEndOfBlock "Clone the GDK from github"

markStartOfBlock "Run the GDK setup script"
  pushd "${UNREAL_GDK_INSTALL_DIRECTORY}/UnrealGDK"
    ./Setup.bat

    # The current version of Unreal.
    if [ -z "${UNREAL_HOME+x}" ]; then
      UNREAL_VERSION="$(cat SpatialGDK/Extras/unreal-engine.version)"
      export UNREAL_HOME="C:/Unreal/UnrealEngine-${UNREAL_VERSION}"
    fi

    # LINUX_MULTIARCH_ROOT is used by Unreal when cross compiling Linux workers
    # as Unreal only builds on Windows otherwise. The Linux cross compiling tools
    # should be automatically installed by puppet as part of the Unreal Engine
    # installation.
    if [ -z "${LINUX_MULTIARCH_ROOT+x}" ]; then
      export LINUX_MULTIARCH_ROOT="${UNREAL_HOME}/ClangToolchain"
    fi
  popd

markEndOfBlock "Run the GDK setup script"
