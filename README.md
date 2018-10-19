# SpatialOS Unreal GDK Starter Project

## Introduction

You can use the SpatialOS Unreal GDK Starter Project as the basis for developing a game using the SpatialOS Unreal GDK. To use the Starter Project, you need to follow the [setup guide](https://github.com/improbable/UnrealGDK/blob/master/docs/setup-and-installing.md) for the SpatialOS Unreal GDK. We've enabled use of the `ThirdPersonExampleMap` and a controllable character `AStarterGameCharacter` that derives from the Unreal class `ACharacter`.

> Note that the SpatialOS Unreal GDK is currently in **pre-alpha**, and we do not recommend using it for games in the production phase yet.

For more information, see the [SpatialOS Unreal GDK repository](https://github.com/improbable/UnrealGDK) and its [documentation](https://github.com/improbable/UnrealGDK/blob/master/docs/readme.md).

## Helper scripts

This repository contains a set of helper scripts to get you started.

| Helper script | Description |
| --- | --- |
| LaunchSpatial.bat | Starts a local Spatial deployment with the default launch configuration |
| LaunchServer.bat | Starts an Unreal server worker, and connects it to the local deployment |
| LaunchClient.bat | Starts an Unreal client worker, and connects it to the local deployment |