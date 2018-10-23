# SpatialOS Unreal GDK Starter Project

## Introduction

You can use the Starter Project as the basis for developing a game using the SpatialOS GDK for Unreal Engine. To use the Starter Project, you need to follow the [setup guide](https://github.com/improbable/UnrealGDK/blob/master/docs/setup-and-installing.md) for the GDK. We've enabled use of the `ThirdPersonExampleMap` and a controllable character `AStarterGameCharacter` on a SpatialOS deployment.

> Note that the SpatialOS GDK for Unreal Engine is currently in **alpha**, with stability and performance improvements pending.

For more information, see the [GDK repository](https://github.com/improbable/UnrealGDK) and its [documentation](https://github.com/improbable/UnrealGDK/blob/master/docs/readme.md).

## Helper scripts

| Helper script | Parameters | Description |
| --- | --- | --- |
| LaunchClient.bat | | Launches a client. Requires a SpatialOS deployment and a managed or manually launched server|
| LaunchServer.bat | | Launches an Unreal dedicated server on ThirdPersonExampleMap. Requires a SpatialOS deployment |
| LaunchSpatial.bat | | Launches a SpatialOS deployment with default launch config (found in `spatial/default_launch.json`) |