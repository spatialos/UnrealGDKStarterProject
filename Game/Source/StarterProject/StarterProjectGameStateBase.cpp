// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "StarterProjectGameStateBase.h"

void AStarterProjectGameStateBase::FakeServerHasBegunPlay()
{
	if (!GetWorld()) 
	{
		return;
	}
	Role = ROLE_SimulatedProxy;
	
	bReplicatedHasBegunPlay = true;
	OnRep_ReplicatedHasBegunPlay();
}
