// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically

#include "SpatialTypeBinding_StarterProjectCharacter_BP_C.h"

#include "GameFramework/PlayerState.h"
#include "NetworkGuid.h"

#include "SpatialOS.h"
#include "EntityBuilder.h"

#include "SpatialConstants.h"
#include "SpatialConditionMapFilter.h"
#include "SpatialUnrealObjectRef.h"
#include "SpatialActorChannel.h"
#include "SpatialPackageMapClient.h"
#include "SpatialMemoryReader.h"
#include "SpatialMemoryWriter.h"
#include "SpatialNetDriver.h"
#include "SpatialInterop.h"
#include "StarterProjectCharacter.h"

#include "StarterProjectCharacterBPCSingleClientRepDataAddComponentOp.h"
#include "StarterProjectCharacterBPCMultiClientRepDataAddComponentOp.h"
#include "StarterProjectCharacterBPCHandoverDataAddComponentOp.h"

const FRepHandlePropertyMap& USpatialTypeBinding_StarterProjectCharacter_BP_C::GetRepHandlePropertyMap() const
{
	return RepHandleToPropertyMap;
}

const FHandoverHandlePropertyMap& USpatialTypeBinding_StarterProjectCharacter_BP_C::GetHandoverHandlePropertyMap() const
{
	return HandoverHandleToPropertyMap;
}

UClass* USpatialTypeBinding_StarterProjectCharacter_BP_C::GetBoundClass() const
{
	return LoadObject<UClass>(nullptr, TEXT("/Game/EntityBlueprints/StarterProjectCharacter_BP.StarterProjectCharacter_BP_C"), nullptr, LOAD_None, nullptr);
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap)
{
	Super::Init(InInterop, InPackageMap);

	RPCToSenderMap.Emplace("TestClientRPC", &USpatialTypeBinding_StarterProjectCharacter_BP_C::TestClientRPC_SendRPC);
	RPCToSenderMap.Emplace("RootMotionDebugClientPrintOnScreen", &USpatialTypeBinding_StarterProjectCharacter_BP_C::RootMotionDebugClientPrintOnScreen_SendRPC);
	RPCToSenderMap.Emplace("ClientVeryShortAdjustPosition", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientVeryShortAdjustPosition_SendRPC);
	RPCToSenderMap.Emplace("ClientCheatWalk", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatWalk_SendRPC);
	RPCToSenderMap.Emplace("ClientCheatGhost", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatGhost_SendRPC);
	RPCToSenderMap.Emplace("ClientCheatFly", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatFly_SendRPC);
	RPCToSenderMap.Emplace("ClientAdjustRootMotionSourcePosition", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionSourcePosition_SendRPC);
	RPCToSenderMap.Emplace("ClientAdjustRootMotionPosition", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionPosition_SendRPC);
	RPCToSenderMap.Emplace("ClientAdjustPosition", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustPosition_SendRPC);
	RPCToSenderMap.Emplace("ClientAckGoodMove", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAckGoodMove_SendRPC);
	RPCToSenderMap.Emplace("SetArrOfStructs1", &USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs1_SendRPC);
	RPCToSenderMap.Emplace("SetArrOfStructs2", &USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs2_SendRPC);
	RPCToSenderMap.Emplace("RPCStructInput", &USpatialTypeBinding_StarterProjectCharacter_BP_C::RPCStructInput_SendRPC);
	RPCToSenderMap.Emplace("UpdateNestedStructCpp", &USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructCpp_SendRPC);
	RPCToSenderMap.Emplace("Update Nested Struct BP", &USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructBP_SendRPC);
	RPCToSenderMap.Emplace("TestRPC", &USpatialTypeBinding_StarterProjectCharacter_BP_C::TestRPC_SendRPC);
	RPCToSenderMap.Emplace("ServerMoveOld", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveOld_SendRPC);
	RPCToSenderMap.Emplace("ServerMoveNoBase", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveNoBase_SendRPC);
	RPCToSenderMap.Emplace("ServerMoveDualNoBase", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualNoBase_SendRPC);
	RPCToSenderMap.Emplace("ServerMoveDualHybridRootMotion", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualHybridRootMotion_SendRPC);
	RPCToSenderMap.Emplace("ServerMoveDual", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDual_SendRPC);
	RPCToSenderMap.Emplace("ServerMove", &USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMove_SendRPC);
	RPCToSenderMap.Emplace("TestMulticast", &USpatialTypeBinding_StarterProjectCharacter_BP_C::TestMulticast_SendRPC);

	UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("StarterProjectCharacter_BP_C"));

	// Populate RepHandleToPropertyMap.
	RepHandleToPropertyMap.Add(1, FRepHandleData(Class, {"bHidden"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(2, FRepHandleData(Class, {"bReplicateMovement"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(3, FRepHandleData(Class, {"bTearOff"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(4, FRepHandleData(Class, {"bCanBeDamaged"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(5, FRepHandleData(Class, {"RemoteRole"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(6, FRepHandleData(Class, {"ReplicatedMovement"}, {0}, COND_SimulatedOrPhysicsNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(7, FRepHandleData(Class, {"AttachmentReplication", "AttachParent"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(8, FRepHandleData(Class, {"AttachmentReplication", "LocationOffset"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(9, FRepHandleData(Class, {"AttachmentReplication", "RelativeScale3D"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(10, FRepHandleData(Class, {"AttachmentReplication", "RotationOffset"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(11, FRepHandleData(Class, {"AttachmentReplication", "AttachSocket"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(12, FRepHandleData(Class, {"AttachmentReplication", "AttachComponent"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(13, FRepHandleData(Class, {"Owner"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(14, FRepHandleData(Class, {"Role"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(15, FRepHandleData(Class, {"Instigator"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(16, FRepHandleData(Class, {"PlayerState"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(17, FRepHandleData(Class, {"RemoteViewPitch"}, {0}, COND_SkipOwner, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(18, FRepHandleData(Class, {"Controller"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(19, FRepHandleData(Class, {"ReplicatedBasedMovement", "MovementBase"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(20, FRepHandleData(Class, {"ReplicatedBasedMovement", "BoneName"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(21, FRepHandleData(Class, {"ReplicatedBasedMovement", "Location"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(22, FRepHandleData(Class, {"ReplicatedBasedMovement", "Rotation"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(23, FRepHandleData(Class, {"ReplicatedBasedMovement", "bServerHasBaseComponent"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(24, FRepHandleData(Class, {"ReplicatedBasedMovement", "bRelativeRotation"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(25, FRepHandleData(Class, {"ReplicatedBasedMovement", "bServerHasVelocity"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(26, FRepHandleData(Class, {"AnimRootMotionTranslationScale"}, {0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(27, FRepHandleData(Class, {"ReplicatedServerLastTransformUpdateTimeStamp"}, {0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(28, FRepHandleData(Class, {"ReplicatedMovementMode"}, {0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(29, FRepHandleData(Class, {"bIsCrouched"}, {0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(30, FRepHandleData(Class, {"JumpMaxHoldTime"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(31, FRepHandleData(Class, {"JumpMaxCount"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(32, FRepHandleData(Class, {"RepRootMotion", "bIsActive"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(33, FRepHandleData(Class, {"RepRootMotion", "AnimMontage"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(34, FRepHandleData(Class, {"RepRootMotion", "Position"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(35, FRepHandleData(Class, {"RepRootMotion", "Location"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(36, FRepHandleData(Class, {"RepRootMotion", "Rotation"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(37, FRepHandleData(Class, {"RepRootMotion", "MovementBase"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(38, FRepHandleData(Class, {"RepRootMotion", "MovementBaseBoneName"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(39, FRepHandleData(Class, {"RepRootMotion", "bRelativePosition"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(40, FRepHandleData(Class, {"RepRootMotion", "bRelativeRotation"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(41, FRepHandleData(Class, {"RepRootMotion", "AuthoritativeRootMotion"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(42, FRepHandleData(Class, {"RepRootMotion", "Acceleration"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(43, FRepHandleData(Class, {"RepRootMotion", "LinearVelocity"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(44, FRepHandleData(Class, {"MyCppStructIns", "b"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(45, FRepHandleData(Class, {"MyCppStructIns", "V"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(46, FRepHandleData(Class, {"MyNestedStructIns", "StructArr"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(47, FRepHandleData(Class, {"MyNestedStructIns", "BoolArr"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(48, FRepHandleData(Class, {"MyCppStructArr"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(49, FRepHandleData(Class, {"MyNestedStructArr"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(50, FRepHandleData(Class, {"MyBool"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(51, FRepHandleData(Class, {"MyArrofBools"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(52, FRepHandleData(Class, {"MyStructVar", "StructBool_1_76B6BADA4BA8FEA4761B938495DEA0E1"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(53, FRepHandleData(Class, {"MyStructVar", "StructVec_4_734F338F470A88C85C79289BBB7E8467"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(54, FRepHandleData(Class, {"MyArrofStructs"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(55, FRepHandleData(Class, {"MyStructNested", "MyBoolArrayNested_7_87D2B213446573EC06159DB37E89CD99"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(56, FRepHandleData(Class, {"MyStructNested", "MyStructArrayNested_6_3B3D5A594BF31A5D239E52AF9AD0D3D7"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(57, FRepHandleData(Class, {"my struct nested arr"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(58, FRepHandleData(Class, {"MyStructLv2Ins", "lv1ins_2_EFC0167049B51FFB215E2284C0988E4B", "MyBoolArrayNested_7_87D2B213446573EC06159DB37E89CD99"}, {0, 0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(59, FRepHandleData(Class, {"MyStructLv2Ins", "lv1ins_2_EFC0167049B51FFB215E2284C0988E4B", "MyStructArrayNested_6_3B3D5A594BF31A5D239E52AF9AD0D3D7"}, {0, 0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(60, FRepHandleData(Class, {"MyStructLv2Ins", "lv1arr_5_6E29525C4699B03778E671BA749C6EA7"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(61, FRepHandleData(Class, {"MyStructLv2Ins", "lv0ins_9_A4B4EC294F2B5A8EE604A78342AEC4FD", "StructBool_1_76B6BADA4BA8FEA4761B938495DEA0E1"}, {0, 0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(62, FRepHandleData(Class, {"MyStructLv2Ins", "lv0ins_9_A4B4EC294F2B5A8EE604A78342AEC4FD", "StructVec_4_734F338F470A88C85C79289BBB7E8467"}, {0, 0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(63, FRepHandleData(Class, {"MyStructlv2arr"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(64, FRepHandleData(Class, {"MyStructlv3ins", "lv2ins_3_BC6BEB9D4C9AFC99D6925F881E8DEB21", "lv1ins_2_EFC0167049B51FFB215E2284C0988E4B", "MyBoolArrayNested_7_87D2B213446573EC06159DB37E89CD99"}, {0, 0, 0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(65, FRepHandleData(Class, {"MyStructlv3ins", "lv2ins_3_BC6BEB9D4C9AFC99D6925F881E8DEB21", "lv1ins_2_EFC0167049B51FFB215E2284C0988E4B", "MyStructArrayNested_6_3B3D5A594BF31A5D239E52AF9AD0D3D7"}, {0, 0, 0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(66, FRepHandleData(Class, {"MyStructlv3ins", "lv2ins_3_BC6BEB9D4C9AFC99D6925F881E8DEB21", "lv1arr_5_6E29525C4699B03778E671BA749C6EA7"}, {0, 0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(67, FRepHandleData(Class, {"MyStructlv3ins", "lv2ins_3_BC6BEB9D4C9AFC99D6925F881E8DEB21", "lv0ins_9_A4B4EC294F2B5A8EE604A78342AEC4FD", "StructBool_1_76B6BADA4BA8FEA4761B938495DEA0E1"}, {0, 0, 0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(68, FRepHandleData(Class, {"MyStructlv3ins", "lv2ins_3_BC6BEB9D4C9AFC99D6925F881E8DEB21", "lv0ins_9_A4B4EC294F2B5A8EE604A78342AEC4FD", "StructVec_4_734F338F470A88C85C79289BBB7E8467"}, {0, 0, 0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(69, FRepHandleData(Class, {"MyStructlv3ins", "lv2arr_6_7A77E9954D2D0A825445FCAE349DE705"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(70, FRepHandleData(Class, {"MyStructlv3ins", "lv1arr_9_1EE4DD494C52603042686DBB43795940"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(71, FRepHandleData(Class, {"MyStructlv3ins", "vectorarr_13_9869B6EB4C946B8A5B8B32931EDB2413"}, {0, 0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(72, FRepHandleData(Class, {"MyStructlv3arr"}, {0}, COND_None, REPNOTIFY_OnChanged));

	// Populate HandoverHandleToPropertyMap.
	HandoverHandleToPropertyMap.Add(1, FHandoverHandleData(Class, {"CharacterMovement", "MovementMode"}));
	HandoverHandleToPropertyMap.Add(2, FHandoverHandleData(Class, {"CharacterMovement", "CustomMovementMode"}));
	HandoverHandleToPropertyMap.Add(3, FHandoverHandleData(Class, {"CharacterMovement", "GroundMovementMode"}));

	bIsSingleton = false;
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::BindToView(bool bIsClient)
{
	TSharedPtr<worker::View> View = Interop->GetSpatialOS()->GetView().Pin();
	ViewCallbacks.Init(View);

	if (Interop->GetNetDriver()->GetNetMode() == NM_Client)
	{
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_SingleClient(ActorChannel, Op.Update);
		}));
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_MultiClient(ActorChannel, Op.Update);
		}));
		if (!bIsClient)
		{
			ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData>([this](
				const worker::ComponentUpdateOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData>& Op)
			{
				// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
				if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::ComponentId))
				{
					return;
				}
				USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
				check(ActorChannel);
				ReceiveUpdate_Handover(ActorChannel, Op.Update);
			}));
		}
	}
	ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCNetMulticastRPCs>([this](
		const worker::ComponentUpdateOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCNetMulticastRPCs>& Op)
	{
		// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
		if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCNetMulticastRPCs::ComponentId))
		{
			return;
		}
		ReceiveUpdate_NetMulticastRPCs(Op.EntityId, Op.Update);
	}));

	using ClientRPCCommandTypes = improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands;
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Testclientrpc>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::TestClientRPC_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Rootmotiondebugclientprintonscreen>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::RootMotionDebugClientPrintOnScreen_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientveryshortadjustposition>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientVeryShortAdjustPosition_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientcheatwalk>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatWalk_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientcheatghost>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatGhost_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientcheatfly>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatFly_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientadjustrootmotionsourceposition>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionSourcePosition_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientadjustrootmotionposition>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionPosition_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientadjustposition>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustPosition_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientackgoodmove>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAckGoodMove_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Testclientrpc>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::TestClientRPC_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Rootmotiondebugclientprintonscreen>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::RootMotionDebugClientPrintOnScreen_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientveryshortadjustposition>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientVeryShortAdjustPosition_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientcheatwalk>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatWalk_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientcheatghost>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatGhost_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientcheatfly>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatFly_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientadjustrootmotionsourceposition>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionSourcePosition_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientadjustrootmotionposition>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionPosition_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientadjustposition>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustPosition_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientackgoodmove>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAckGoodMove_OnCommandResponse, this, std::placeholders::_1)));

	using ServerRPCCommandTypes = improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands;
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Setarrofstructs1>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs1_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Setarrofstructs2>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs2_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Rpcstructinput>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::RPCStructInput_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Updatenestedstructcpp>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructCpp_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Updatenestedstructbp>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructBP_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Testrpc>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::TestRPC_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermoveold>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveOld_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermovenobase>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveNoBase_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermovedualnobase>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualNoBase_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermovedualhybridrootmotion>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualHybridRootMotion_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermovedual>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDual_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermove>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMove_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Setarrofstructs1>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs1_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Setarrofstructs2>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs2_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Rpcstructinput>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::RPCStructInput_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Updatenestedstructcpp>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructCpp_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Updatenestedstructbp>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructBP_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Testrpc>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::TestRPC_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermoveold>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveOld_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermovenobase>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveNoBase_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermovedualnobase>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualNoBase_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermovedualhybridrootmotion>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualHybridRootMotion_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermovedual>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDual_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermove>(std::bind(&USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMove_OnCommandResponse, this, std::placeholders::_1)));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::UnbindFromView()
{
	ViewCallbacks.Reset();
}

worker::Entity USpatialTypeBinding_StarterProjectCharacter_BP_C::CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const
{
	// Validate replication list.
	const uint16 RepHandlePropertyMapCount = GetRepHandlePropertyMap().Num();
	for (auto& Rep : InitialChanges.RepChanged)
	{
		checkf(Rep <= RepHandlePropertyMapCount, TEXT("Attempting to replicate a property with a handle that the type binding is not aware of. Have additional replicated properties been added in a non generated child object?"))
	}

	// Setup initial data.

	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::Data SingleClientStarterProjectCharacter_BP_CData;
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::Update SingleClientStarterProjectCharacter_BP_CUpdate;
	bool bSingleClientStarterProjectCharacter_BP_CUpdateChanged = false;
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::Data MultiClientStarterProjectCharacter_BP_CData;
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::Update MultiClientStarterProjectCharacter_BP_CUpdate;
	bool bMultiClientStarterProjectCharacter_BP_CUpdateChanged = false;
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::Data StarterProjectCharacter_BP_CHandoverData;
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::Update StarterProjectCharacter_BP_CHandoverDataUpdate;
	bool bStarterProjectCharacter_BP_CHandoverDataUpdateChanged = false;

	BuildSpatialComponentUpdate(InitialChanges, Channel, SingleClientStarterProjectCharacter_BP_CUpdate, bSingleClientStarterProjectCharacter_BP_CUpdateChanged, MultiClientStarterProjectCharacter_BP_CUpdate, bMultiClientStarterProjectCharacter_BP_CUpdateChanged, StarterProjectCharacter_BP_CHandoverDataUpdate, bStarterProjectCharacter_BP_CHandoverDataUpdateChanged);
	SingleClientStarterProjectCharacter_BP_CUpdate.ApplyTo(SingleClientStarterProjectCharacter_BP_CData);
	MultiClientStarterProjectCharacter_BP_CUpdate.ApplyTo(MultiClientStarterProjectCharacter_BP_CData);
	StarterProjectCharacter_BP_CHandoverDataUpdate.ApplyTo(StarterProjectCharacter_BP_CHandoverData);

	// Create entity.
	std::string ClientWorkerIdString = TCHAR_TO_UTF8(*ClientWorkerId);

	improbable::WorkerAttributeSet WorkerAttribute{{worker::List<std::string>{"UnrealWorker"}}};
	improbable::WorkerAttributeSet ClientAttribute{{worker::List<std::string>{"UnrealClient"}}};
	improbable::WorkerAttributeSet OwningClientAttribute{{"workerId:" + ClientWorkerIdString}};

	improbable::WorkerRequirementSet WorkersOnly{{WorkerAttribute}};
	improbable::WorkerRequirementSet ClientsOnly{{ClientAttribute}};
	improbable::WorkerRequirementSet OwningClientOnly{{OwningClientAttribute}};
	improbable::WorkerRequirementSet AnyUnrealWorkerOrClient{{WorkerAttribute, ClientAttribute}};
	improbable::WorkerRequirementSet AnyUnrealWorkerOrOwningClient{{WorkerAttribute, OwningClientAttribute}};

	// Set up unreal metadata.
	improbable::unreal::UnrealMetadata::Data UnrealMetadata;
	if (Channel->Actor->IsFullNameStableForNetworking())
	{
		UnrealMetadata.set_static_path({std::string{TCHAR_TO_UTF8(*Channel->Actor->GetPathName(Channel->Actor->GetWorld()))}});
	}
	if (!ClientWorkerIdString.empty())
	{
		UnrealMetadata.set_owner_worker_id({ClientWorkerIdString});
	}

	uint32 CurrentOffset = 1;
	worker::Map<std::string, std::uint32_t> SubobjectNameToOffset;
	ForEachObjectWithOuter(Channel->Actor, [&UnrealMetadata, &CurrentOffset, &SubobjectNameToOffset](UObject* Object)
	{
		// Objects can only be allocated NetGUIDs if this is true.
		if (Object->IsSupportedForNetworking() && !Object->IsPendingKill() && !Object->IsEditorOnly())
		{
			SubobjectNameToOffset.emplace(TCHAR_TO_UTF8(*(Object->GetName())), CurrentOffset);
			CurrentOffset++;
		}
	});
	UnrealMetadata.set_subobject_name_to_offset(SubobjectNameToOffset);

	// Build entity.
	const improbable::Coordinates SpatialPosition = SpatialConstants::LocationToSpatialOSCoordinates(Position);
	return improbable::unreal::FEntityBuilder::Begin()
		.AddPositionComponent(improbable::Position::Data{SpatialPosition}, WorkersOnly)
		.AddMetadataComponent(improbable::Metadata::Data{TCHAR_TO_UTF8(*Metadata)})
		.SetPersistence(true)
		.SetReadAcl(AnyUnrealWorkerOrClient)
		.AddComponent<improbable::unreal::UnrealMetadata>(UnrealMetadata, WorkersOnly)
		.AddComponent<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData>(SingleClientStarterProjectCharacter_BP_CData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData>(MultiClientStarterProjectCharacter_BP_CData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData>(StarterProjectCharacter_BP_CHandoverData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs>(improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Data{}, OwningClientOnly)
		.AddComponent<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs>(improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Data{}, WorkersOnly)
		.AddComponent<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCNetMulticastRPCs>(improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCNetMulticastRPCs::Data{}, WorkersOnly)
		.Build();
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const
{
	// Build SpatialOS updates.
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::Update HandoverDataUpdate;
	bool bHandoverDataUpdateChanged = false;
	BuildSpatialComponentUpdate(Changes, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged, HandoverDataUpdate, bHandoverDataUpdateChanged);

	// Send SpatialOS updates if anything changed.
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	if (bSingleClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData>(EntityId.ToSpatialEntityId(), SingleClientUpdate);
	}
	if (bMultiClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData>(EntityId.ToSpatialEntityId(), MultiClientUpdate);
	}
	if (bHandoverDataUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData>(EntityId.ToSpatialEntityId(), HandoverDataUpdate);
	}
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters)
{
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	auto SenderFuncIterator = RPCToSenderMap.Find(Function->GetFName());
	if (SenderFuncIterator == nullptr)
	{
		UE_LOG(LogSpatialGDKInterop, Error, TEXT("Sender for %s has not been registered with RPCToSenderMap."), *Function->GetFName().ToString());
		return;
	}
	checkf(*SenderFuncIterator, TEXT("Sender for %s has been registered as null."), *Function->GetFName().ToString());
	(this->*(*SenderFuncIterator))(Connection.Get(), Parameters, TargetObject);
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const
{
	auto* SingleClientAddOp = Cast<UStarterProjectCharacterBPCSingleClientRepDataAddComponentOp>(AddComponentOp);
	if (SingleClientAddOp)
	{
		auto Update = improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::Update::FromInitialData(*SingleClientAddOp->Data.data());
		ReceiveUpdate_SingleClient(Channel, Update);
		return;
	}
	auto* MultiClientAddOp = Cast<UStarterProjectCharacterBPCMultiClientRepDataAddComponentOp>(AddComponentOp);
	if (MultiClientAddOp)
	{
		auto Update = improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::Update::FromInitialData(*MultiClientAddOp->Data.data());
		ReceiveUpdate_MultiClient(Channel, Update);
		return;
	}
	auto* HandoverDataAddOp = Cast<UStarterProjectCharacterBPCHandoverDataAddComponentOp>(AddComponentOp);
	if (HandoverDataAddOp)
	{
		auto Update = improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::Update::FromInitialData(*HandoverDataAddOp->Data.data());
		ReceiveUpdate_Handover(Channel, Update);
		return;
	}
}

worker::Map<worker::ComponentId, worker::InterestOverride> USpatialTypeBinding_StarterProjectCharacter_BP_C::GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const
{
	worker::Map<worker::ComponentId, worker::InterestOverride> Interest;
	if (bIsClient)
	{
		if (!bAutonomousProxy)
		{
			Interest.emplace(improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::ComponentId, worker::InterestOverride{false});
		}
		Interest.emplace(improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::ComponentId, worker::InterestOverride{false});
	}
	return Interest;
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::BuildSpatialComponentUpdate(
	const FPropertyChangeState& Changes,
	USpatialActorChannel* Channel,
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::Update& SingleClientUpdate,
	bool& bSingleClientUpdateChanged,
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::Update& MultiClientUpdate,
	bool& bMultiClientUpdateChanged,
	improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::Update& HandoverDataUpdate,
	bool& bHandoverDataUpdateChanged) const
{
	const FRepHandlePropertyMap& RepPropertyMap = GetRepHandlePropertyMap();
	const FHandoverHandlePropertyMap& HandoverPropertyMap = GetHandoverHandlePropertyMap();
	if (Changes.RepChanged.Num() > 0)
	{
		// Populate the replicated data component updates from the replicated property changelist.
		FChangelistIterator ChangelistIterator(Changes.RepChanged, 0);
		FRepHandleIterator HandleIterator(ChangelistIterator, Changes.RepCmds, Changes.RepBaseHandleToCmdIndex, 0, 1, 0, Changes.RepCmds.Num() - 1);
		while (HandleIterator.NextHandle())
		{
			const FRepLayoutCmd& Cmd = Changes.RepCmds[HandleIterator.CmdIndex];
			const FRepHandleData& PropertyMapData = RepPropertyMap[HandleIterator.Handle];
			const uint8* Data = PropertyMapData.GetPropertyData(Changes.SourceData) + HandleIterator.ArrayOffset;
			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*Channel->Actor->GetName(),
				Channel->GetEntityId().ToSpatialEntityId(),
				*Cmd.Property->GetName(),
				HandleIterator.Handle);
			switch (GetGroupFromCondition(PropertyMapData.Condition))
			{
			case GROUP_SingleClient:
				ServerSendUpdate_SingleClient(Data, HandleIterator.Handle, Cmd.Property, Channel, SingleClientUpdate);
				bSingleClientUpdateChanged = true;
				break;
			case GROUP_MultiClient:
				ServerSendUpdate_MultiClient(Data, HandleIterator.Handle, Cmd.Property, Channel, MultiClientUpdate);
				bMultiClientUpdateChanged = true;
				break;
			}
			if (Cmd.Type == REPCMD_DynamicArray)
			{
				if (!HandleIterator.JumpOverArray())
				{
					break;
				}
			}
		}
	}

	// Populate the handover data component update from the handover property changelist.
	for (uint16 ChangedHandle : Changes.HandoverChanged)
	{
		const FHandoverHandleData& PropertyMapData = HandoverPropertyMap[ChangedHandle];
		const uint8* Data = PropertyMapData.GetPropertyData(Changes.SourceData);
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending handover property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*Channel->Actor->GetName(),
			Channel->GetEntityId().ToSpatialEntityId(),
			*PropertyMapData.Property->GetName(),
			ChangedHandle);
		ServerSendUpdate_Handover(Data, ChangedHandle, PropertyMapData.Property, Channel, HandoverDataUpdate);
		bHandoverDataUpdateChanged = true;
	}
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::Update& OutUpdate) const
{
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_bhidden0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bhidden0(Value);
			break;
		}
		case 2: // field_breplicatemovement0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_breplicatemovement0(Value);
			break;
		}
		case 3: // field_btearoff0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_btearoff0(Value);
			break;
		}
		case 4: // field_bcanbedamaged0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bcanbedamaged0(Value);
			break;
		}
		case 5: // field_remoterole0
		{
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(Data));

			OutUpdate.set_field_remoterole0(uint32_t(Value));
			break;
		}
		case 6: // field_replicatedmovement0
		{
			const FRepMovement& Value = *(reinterpret_cast<FRepMovement const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 6);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRepMovement&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRepMovement failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_replicatedmovement0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 6);
			}
			break;
		}
		case 7: // field_attachmentreplication0_attachparent0
		{
			AActor* Value = *(reinterpret_cast<AActor* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 7);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication0_attachparent0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_attachmentreplication0_attachparent0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 8: // field_attachmentreplication0_locationoffset0
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 8);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_attachmentreplication0_locationoffset0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 8);
			}
			break;
		}
		case 9: // field_attachmentreplication0_relativescale3d0
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 9);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_attachmentreplication0_relativescale3d0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 9);
			}
			break;
		}
		case 10: // field_attachmentreplication0_rotationoffset0
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 10);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRotator&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_attachmentreplication0_rotationoffset0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 10);
			}
			break;
		}
		case 11: // field_attachmentreplication0_attachsocket0
		{
			FName Value = *(reinterpret_cast<FName const*>(Data));

			OutUpdate.set_field_attachmentreplication0_attachsocket0(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 12: // field_attachmentreplication0_attachcomponent0
		{
			USceneComponent* Value = *(reinterpret_cast<USceneComponent* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 12);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication0_attachcomponent0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_attachmentreplication0_attachcomponent0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 13: // field_owner0
		{
			AActor* Value = *(reinterpret_cast<AActor* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 13);
				}
				else
				{
					OutUpdate.set_field_owner0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_owner0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 14: // field_role0
		{
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(Data));

			OutUpdate.set_field_role0(uint32_t(Value));
			break;
		}
		case 15: // field_instigator0
		{
			APawn* Value = *(reinterpret_cast<APawn* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 15);
				}
				else
				{
					OutUpdate.set_field_instigator0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_instigator0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 16: // field_playerstate0
		{
			APlayerState* Value = *(reinterpret_cast<APlayerState* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 16);
				}
				else
				{
					OutUpdate.set_field_playerstate0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_playerstate0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 17: // field_remoteviewpitch0
		{
			uint8 Value = *(reinterpret_cast<uint8 const*>(Data));

			OutUpdate.set_field_remoteviewpitch0(uint32_t(Value));
			break;
		}
		case 18: // field_controller0
		{
			AController* Value = *(reinterpret_cast<AController* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 18);
				}
				else
				{
					OutUpdate.set_field_controller0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_controller0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 19: // field_replicatedbasedmovement0_movementbase0
		{
			UPrimitiveComponent* Value = *(reinterpret_cast<UPrimitiveComponent* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 19);
				}
				else
				{
					OutUpdate.set_field_replicatedbasedmovement0_movementbase0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_replicatedbasedmovement0_movementbase0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 20: // field_replicatedbasedmovement0_bonename0
		{
			FName Value = *(reinterpret_cast<FName const*>(Data));

			OutUpdate.set_field_replicatedbasedmovement0_bonename0(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 21: // field_replicatedbasedmovement0_location0
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 21);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_replicatedbasedmovement0_location0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 21);
			}
			break;
		}
		case 22: // field_replicatedbasedmovement0_rotation0
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 22);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRotator&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_replicatedbasedmovement0_rotation0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 22);
			}
			break;
		}
		case 23: // field_replicatedbasedmovement0_bserverhasbasecomponent0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_replicatedbasedmovement0_bserverhasbasecomponent0(Value);
			break;
		}
		case 24: // field_replicatedbasedmovement0_brelativerotation0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_replicatedbasedmovement0_brelativerotation0(Value);
			break;
		}
		case 25: // field_replicatedbasedmovement0_bserverhasvelocity0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_replicatedbasedmovement0_bserverhasvelocity0(Value);
			break;
		}
		case 26: // field_animrootmotiontranslationscale0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_animrootmotiontranslationscale0(Value);
			break;
		}
		case 27: // field_replicatedserverlasttransformupdatetimestamp0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_replicatedserverlasttransformupdatetimestamp0(Value);
			break;
		}
		case 28: // field_replicatedmovementmode0
		{
			uint8 Value = *(reinterpret_cast<uint8 const*>(Data));

			OutUpdate.set_field_replicatedmovementmode0(uint32_t(Value));
			break;
		}
		case 29: // field_biscrouched0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_biscrouched0(Value);
			break;
		}
		case 30: // field_jumpmaxholdtime0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_jumpmaxholdtime0(Value);
			break;
		}
		case 31: // field_jumpmaxcount0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_jumpmaxcount0(int32_t(Value));
			break;
		}
		case 32: // field_reprootmotion0_bisactive0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_reprootmotion0_bisactive0(Value);
			break;
		}
		case 33: // field_reprootmotion0_animmontage0
		{
			UAnimMontage* Value = *(reinterpret_cast<UAnimMontage* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 33);
				}
				else
				{
					OutUpdate.set_field_reprootmotion0_animmontage0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_reprootmotion0_animmontage0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 34: // field_reprootmotion0_position0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_reprootmotion0_position0(Value);
			break;
		}
		case 35: // field_reprootmotion0_location0
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 35);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_reprootmotion0_location0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 35);
			}
			break;
		}
		case 36: // field_reprootmotion0_rotation0
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 36);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRotator&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_reprootmotion0_rotation0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 36);
			}
			break;
		}
		case 37: // field_reprootmotion0_movementbase0
		{
			UPrimitiveComponent* Value = *(reinterpret_cast<UPrimitiveComponent* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 37);
				}
				else
				{
					OutUpdate.set_field_reprootmotion0_movementbase0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_reprootmotion0_movementbase0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 38: // field_reprootmotion0_movementbasebonename0
		{
			FName Value = *(reinterpret_cast<FName const*>(Data));

			OutUpdate.set_field_reprootmotion0_movementbasebonename0(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 39: // field_reprootmotion0_brelativeposition0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_reprootmotion0_brelativeposition0(Value);
			break;
		}
		case 40: // field_reprootmotion0_brelativerotation0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_reprootmotion0_brelativerotation0(Value);
			break;
		}
		case 41: // field_reprootmotion0_authoritativerootmotion0
		{
			const FRootMotionSourceGroup& Value = *(reinterpret_cast<FRootMotionSourceGroup const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 41);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRootMotionSourceGroup&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRootMotionSourceGroup failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_reprootmotion0_authoritativerootmotion0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 41);
			}
			break;
		}
		case 42: // field_reprootmotion0_acceleration0
		{
			const FVector_NetQuantize10& Value = *(reinterpret_cast<FVector_NetQuantize10 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 42);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_reprootmotion0_acceleration0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 42);
			}
			break;
		}
		case 43: // field_reprootmotion0_linearvelocity0
		{
			const FVector_NetQuantize10& Value = *(reinterpret_cast<FVector_NetQuantize10 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 43);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_reprootmotion0_linearvelocity0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 43);
			}
			break;
		}
		case 44: // field_mycppstructins0_b0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_mycppstructins0_b0(Value);
			break;
		}
		case 45: // field_mycppstructins0_v0
		{
			const FVector& Value = *(reinterpret_cast<FVector const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 45);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mycppstructins0_v0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 45);
			}
			break;
		}
		case 46: // field_mynestedstructins0_structarr0
		{
			const TArray<FMyCppStruct>& Value = *(reinterpret_cast<TArray<FMyCppStruct> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 46);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyCppStruct::StaticStruct()->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyCppStruct*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mynestedstructins0_structarr0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 46);
			}
			break;
		}
		case 47: // field_mynestedstructins0_boolarr0
		{
			const TArray<bool>& Value = *(reinterpret_cast<TArray<bool> const*>(Data));

			::worker::List<bool> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				List.emplace_back(Value[i]);
			}
			OutUpdate.set_field_mynestedstructins0_boolarr0(List);
			break;
		}
		case 48: // field_mycppstructarr0
		{
			const TArray<FMyCppStruct>& Value = *(reinterpret_cast<TArray<FMyCppStruct> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 48);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyCppStruct::StaticStruct()->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyCppStruct*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mycppstructarr0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 48);
			}
			break;
		}
		case 49: // field_mynestedstructarr0
		{
			const TArray<FMyCppNestedStruct>& Value = *(reinterpret_cast<TArray<FMyCppNestedStruct> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 49);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyCppNestedStruct::StaticStruct()->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyCppNestedStruct*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mynestedstructarr0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 49);
			}
			break;
		}
		case 50: // field_mybool0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_mybool0(Value);
			break;
		}
		case 51: // field_myarrofbools0
		{
			const TArray<bool>& Value = *(reinterpret_cast<TArray<bool> const*>(Data));

			::worker::List<bool> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				List.emplace_back(Value[i]);
			}
			OutUpdate.set_field_myarrofbools0(List);
			break;
		}
		case 52: // field_mystructvar0_structbool176b6bada4ba8fea4761b938495dea0e10
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_mystructvar0_structbool176b6bada4ba8fea4761b938495dea0e10(Value);
			break;
		}
		case 53: // field_mystructvar0_structvec4734f338f470a88c85c79289bbb7e84670
		{
			const FVector& Value = *(reinterpret_cast<FVector const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 53);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructvar0_structvec4734f338f470a88c85c79289bbb7e84670(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 53);
			}
			break;
		}
		case 54: // field_myarrofstructs0
		{
			UStruct* FMyStruct__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStruct.MyStruct"), NULL, LOAD_None, NULL);
			const TArray<FMyStruct__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStruct__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 54);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStruct__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStruct__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_myarrofstructs0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 54);
			}
			break;
		}
		case 55: // field_mystructnested0_myboolarraynested787d2b213446573ec06159db37e89cd990
		{
			const TArray<bool>& Value = *(reinterpret_cast<TArray<bool> const*>(Data));

			::worker::List<bool> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				List.emplace_back(Value[i]);
			}
			OutUpdate.set_field_mystructnested0_myboolarraynested787d2b213446573ec06159db37e89cd990(List);
			break;
		}
		case 56: // field_mystructnested0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70
		{
			UStruct* FMyStruct__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStruct.MyStruct"), NULL, LOAD_None, NULL);
			const TArray<FMyStruct__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStruct__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 56);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStruct__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStruct__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructnested0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 56);
			}
			break;
		}
		case 57: // field_mystructnestedarr0
		{
			UStruct* FMyStructWithArray__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/myStructWithArray.MyStructWithArray"), NULL, LOAD_None, NULL);
			const TArray<FMyStructWithArray__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStructWithArray__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 57);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStructWithArray__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStructWithArray__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructnestedarr0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 57);
			}
			break;
		}
		case 58: // field_mystructlv2ins0_lv1ins2efc0167049b51ffb215e2284c0988e4b0_myboolarraynested787d2b213446573ec06159db37e89cd990
		{
			const TArray<bool>& Value = *(reinterpret_cast<TArray<bool> const*>(Data));

			::worker::List<bool> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				List.emplace_back(Value[i]);
			}
			OutUpdate.set_field_mystructlv2ins0_lv1ins2efc0167049b51ffb215e2284c0988e4b0_myboolarraynested787d2b213446573ec06159db37e89cd990(List);
			break;
		}
		case 59: // field_mystructlv2ins0_lv1ins2efc0167049b51ffb215e2284c0988e4b0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70
		{
			UStruct* FMyStruct__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStruct.MyStruct"), NULL, LOAD_None, NULL);
			const TArray<FMyStruct__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStruct__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 59);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStruct__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStruct__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv2ins0_lv1ins2efc0167049b51ffb215e2284c0988e4b0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 59);
			}
			break;
		}
		case 60: // field_mystructlv2ins0_lv1arr56e29525c4699b03778e671ba749c6ea70
		{
			UStruct* FMyStructWithArray__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/myStructWithArray.MyStructWithArray"), NULL, LOAD_None, NULL);
			const TArray<FMyStructWithArray__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStructWithArray__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 60);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStructWithArray__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStructWithArray__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv2ins0_lv1arr56e29525c4699b03778e671ba749c6ea70(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 60);
			}
			break;
		}
		case 61: // field_mystructlv2ins0_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structbool176b6bada4ba8fea4761b938495dea0e10
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_mystructlv2ins0_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structbool176b6bada4ba8fea4761b938495dea0e10(Value);
			break;
		}
		case 62: // field_mystructlv2ins0_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structvec4734f338f470a88c85c79289bbb7e84670
		{
			const FVector& Value = *(reinterpret_cast<FVector const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 62);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv2ins0_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structvec4734f338f470a88c85c79289bbb7e84670(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 62);
			}
			break;
		}
		case 63: // field_mystructlv2arr0
		{
			UStruct* FMyStructLv2__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStructLv2.MyStructLv2"), NULL, LOAD_None, NULL);
			const TArray<FMyStructLv2__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStructLv2__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 63);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStructLv2__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStructLv2__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv2arr0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 63);
			}
			break;
		}
		case 64: // field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1ins2efc0167049b51ffb215e2284c0988e4b0_myboolarraynested787d2b213446573ec06159db37e89cd990
		{
			const TArray<bool>& Value = *(reinterpret_cast<TArray<bool> const*>(Data));

			::worker::List<bool> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				List.emplace_back(Value[i]);
			}
			OutUpdate.set_field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1ins2efc0167049b51ffb215e2284c0988e4b0_myboolarraynested787d2b213446573ec06159db37e89cd990(List);
			break;
		}
		case 65: // field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1ins2efc0167049b51ffb215e2284c0988e4b0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70
		{
			UStruct* FMyStruct__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStruct.MyStruct"), NULL, LOAD_None, NULL);
			const TArray<FMyStruct__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStruct__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 65);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStruct__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStruct__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1ins2efc0167049b51ffb215e2284c0988e4b0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 65);
			}
			break;
		}
		case 66: // field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1arr56e29525c4699b03778e671ba749c6ea70
		{
			UStruct* FMyStructWithArray__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/myStructWithArray.MyStructWithArray"), NULL, LOAD_None, NULL);
			const TArray<FMyStructWithArray__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStructWithArray__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 66);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStructWithArray__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStructWithArray__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1arr56e29525c4699b03778e671ba749c6ea70(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 66);
			}
			break;
		}
		case 67: // field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structbool176b6bada4ba8fea4761b938495dea0e10
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structbool176b6bada4ba8fea4761b938495dea0e10(Value);
			break;
		}
		case 68: // field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structvec4734f338f470a88c85c79289bbb7e84670
		{
			const FVector& Value = *(reinterpret_cast<FVector const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 68);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structvec4734f338f470a88c85c79289bbb7e84670(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 68);
			}
			break;
		}
		case 69: // field_mystructlv3ins0_lv2arr67a77e9954d2d0a825445fcae349de7050
		{
			UStruct* FMyStructLv2__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStructLv2.MyStructLv2"), NULL, LOAD_None, NULL);
			const TArray<FMyStructLv2__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStructLv2__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 69);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStructLv2__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStructLv2__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv3ins0_lv2arr67a77e9954d2d0a825445fcae349de7050(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 69);
			}
			break;
		}
		case 70: // field_mystructlv3ins0_lv1arr91ee4dd494c52603042686dbb437959400
		{
			UStruct* FMyStructWithArray__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/myStructWithArray.MyStructWithArray"), NULL, LOAD_None, NULL);
			const TArray<FMyStructWithArray__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStructWithArray__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 70);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStructWithArray__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStructWithArray__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv3ins0_lv1arr91ee4dd494c52603042686dbb437959400(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 70);
			}
			break;
		}
		case 71: // field_mystructlv3ins0_vectorarr139869b6eb4c946b8a5b8b32931edb24130
		{
			const TArray<FVector>& Value = *(reinterpret_cast<TArray<FVector> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 71);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				bool bSuccess = true;
				(const_cast<FVector&>(Value[i])).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
				checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv3ins0_vectorarr139869b6eb4c946b8a5b8b32931edb24130(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 71);
			}
			break;
		}
		case 72: // field_mystructlv3arr0
		{
			UStruct* FMyStructlv3__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStructlv3.MyStructlv3"), NULL, LOAD_None, NULL);
			const TArray<FMyStructlv3__pf3826073315>& Value = *(reinterpret_cast<TArray<FMyStructlv3__pf3826073315> const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 72);
			TSet<const UObject*> UnresolvedObjects;
			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
				FMyStructlv3__pf3826073315_Struct->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FMyStructlv3__pf3826073315*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			const ::worker::List<std::string>& Result = (List);
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_mystructlv3arr0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 72);
			}
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerSendUpdate_Handover(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_charactermovement0_movementmode0
		{
			TEnumAsByte<EMovementMode> Value = *(reinterpret_cast<TEnumAsByte<EMovementMode> const*>(Data));

			OutUpdate.set_field_charactermovement0_movementmode0(uint32_t(Value));
			break;
		}
		case 2: // field_charactermovement0_custommovementmode0
		{
			uint8 Value = *(reinterpret_cast<uint8 const*>(Data));

			OutUpdate.set_field_charactermovement0_custommovementmode0(uint32_t(Value));
			break;
		}
		case 3: // field_charactermovement0_groundmovementmode0
		{
			TEnumAsByte<EMovementMode> Value = *(reinterpret_cast<TEnumAsByte<EMovementMode> const*>(Data));

			OutUpdate.set_field_charactermovement0_groundmovementmode0(uint32_t(Value));
			break;
		}
	default:
		checkf(false, TEXT("Unknown handover property handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::Update& Update) const
{
	AActor* TargetObject = ActorChannel->Actor;
	ActorChannel->PreReceiveSpatialUpdate(TargetObject);
	TArray<UProperty*> RepNotifies;
	ActorChannel->PostReceiveSpatialUpdate(TargetObject, RepNotifies);
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::Update& Update) const
{
	AActor* TargetObject = ActorChannel->Actor;
	ActorChannel->PreReceiveSpatialUpdate(TargetObject);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::ComponentId);
	const FRepHandlePropertyMap& HandleToPropertyMap = GetRepHandlePropertyMap();
	FSpatialConditionMapFilter ConditionMap(ActorChannel, bAutonomousProxy);

	if (!Update.field_bhidden0().empty())
	{
		// field_bhidden0
		uint16 Handle = 1;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bhidden0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_breplicatemovement0().empty())
	{
		// field_breplicatemovement0
		uint16 Handle = 2;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_breplicatemovement0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_btearoff0().empty())
	{
		// field_btearoff0
		uint16 Handle = 3;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_btearoff0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bcanbedamaged0().empty())
	{
		// field_bcanbedamaged0
		uint16 Handle = 4;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bcanbedamaged0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_remoterole0().empty())
	{
		// field_remoterole0
		uint16 Handle = 5;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			// On the client, we need to swap Role/RemoteRole.
			if (!bIsServer)
			{
				Handle = 14;
				RepData = &HandleToPropertyMap[Handle];
			}

			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(PropertyData));

			Value = TEnumAsByte<ENetRole>(uint8((*Update.field_remoterole0().data())));

			// Downgrade role from AutonomousProxy to SimulatedProxy if we aren't authoritative over
			// the server RPCs component.
			if (!bIsServer && Value == ROLE_AutonomousProxy && !bAutonomousProxy)
			{
				Value = ROLE_SimulatedProxy;
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedmovement0().empty())
	{
		// field_replicatedmovement0
		uint16 Handle = 6;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRepMovement Value = *(reinterpret_cast<FRepMovement const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_replicatedmovement0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRepMovement failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_attachparent0().empty())
	{
		// field_attachmentreplication0_attachparent0
		uint16 Handle = 7;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			AActor* Value = *(reinterpret_cast<AActor* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_attachmentreplication0_attachparent0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<AActor>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<AActor>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_attachmentreplication0_locationoffset0().empty())
	{
		// field_attachmentreplication0_locationoffset0
		uint16 Handle = 8;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_attachmentreplication0_locationoffset0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_relativescale3d0().empty())
	{
		// field_attachmentreplication0_relativescale3d0
		uint16 Handle = 9;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_attachmentreplication0_relativescale3d0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_rotationoffset0().empty())
	{
		// field_attachmentreplication0_rotationoffset0
		uint16 Handle = 10;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_attachmentreplication0_rotationoffset0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_attachsocket0().empty())
	{
		// field_attachmentreplication0_attachsocket0
		uint16 Handle = 11;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FName Value = *(reinterpret_cast<FName const*>(PropertyData));

			Value = FName(((*Update.field_attachmentreplication0_attachsocket0().data())).data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_attachcomponent0().empty())
	{
		// field_attachmentreplication0_attachcomponent0
		uint16 Handle = 12;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			USceneComponent* Value = *(reinterpret_cast<USceneComponent* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_attachmentreplication0_attachcomponent0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<USceneComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<USceneComponent>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_owner0().empty())
	{
		// field_owner0
		uint16 Handle = 13;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			AActor* Value = *(reinterpret_cast<AActor* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_owner0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<AActor>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<AActor>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_role0().empty())
	{
		// field_role0
		uint16 Handle = 14;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			// On the client, we need to swap Role/RemoteRole.
			if (!bIsServer)
			{
				Handle = 5;
				RepData = &HandleToPropertyMap[Handle];
			}

			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(PropertyData));

			Value = TEnumAsByte<ENetRole>(uint8((*Update.field_role0().data())));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_instigator0().empty())
	{
		// field_instigator0
		uint16 Handle = 15;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			APawn* Value = *(reinterpret_cast<APawn* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_instigator0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<APawn>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<APawn>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_playerstate0().empty())
	{
		// field_playerstate0
		uint16 Handle = 16;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			APlayerState* Value = *(reinterpret_cast<APlayerState* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_playerstate0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<APlayerState>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<APlayerState>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_remoteviewpitch0().empty())
	{
		// field_remoteviewpitch0
		uint16 Handle = 17;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			uint8 Value = *(reinterpret_cast<uint8 const*>(PropertyData));

			Value = uint8(uint8((*Update.field_remoteviewpitch0().data())));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_controller0().empty())
	{
		// field_controller0
		uint16 Handle = 18;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			AController* Value = *(reinterpret_cast<AController* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_controller0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<AController>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<AController>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_replicatedbasedmovement0_movementbase0().empty())
	{
		// field_replicatedbasedmovement0_movementbase0
		uint16 Handle = 19;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UPrimitiveComponent* Value = *(reinterpret_cast<UPrimitiveComponent* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_replicatedbasedmovement0_movementbase0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_replicatedbasedmovement0_bonename0().empty())
	{
		// field_replicatedbasedmovement0_bonename0
		uint16 Handle = 20;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FName Value = *(reinterpret_cast<FName const*>(PropertyData));

			Value = FName(((*Update.field_replicatedbasedmovement0_bonename0().data())).data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedbasedmovement0_location0().empty())
	{
		// field_replicatedbasedmovement0_location0
		uint16 Handle = 21;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_replicatedbasedmovement0_location0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedbasedmovement0_rotation0().empty())
	{
		// field_replicatedbasedmovement0_rotation0
		uint16 Handle = 22;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_replicatedbasedmovement0_rotation0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedbasedmovement0_bserverhasbasecomponent0().empty())
	{
		// field_replicatedbasedmovement0_bserverhasbasecomponent0
		uint16 Handle = 23;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_replicatedbasedmovement0_bserverhasbasecomponent0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedbasedmovement0_brelativerotation0().empty())
	{
		// field_replicatedbasedmovement0_brelativerotation0
		uint16 Handle = 24;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_replicatedbasedmovement0_brelativerotation0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedbasedmovement0_bserverhasvelocity0().empty())
	{
		// field_replicatedbasedmovement0_bserverhasvelocity0
		uint16 Handle = 25;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_replicatedbasedmovement0_bserverhasvelocity0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_animrootmotiontranslationscale0().empty())
	{
		// field_animrootmotiontranslationscale0
		uint16 Handle = 26;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_animrootmotiontranslationscale0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedserverlasttransformupdatetimestamp0().empty())
	{
		// field_replicatedserverlasttransformupdatetimestamp0
		uint16 Handle = 27;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_replicatedserverlasttransformupdatetimestamp0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedmovementmode0().empty())
	{
		// field_replicatedmovementmode0
		uint16 Handle = 28;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			uint8 Value = *(reinterpret_cast<uint8 const*>(PropertyData));

			Value = uint8(uint8((*Update.field_replicatedmovementmode0().data())));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_biscrouched0().empty())
	{
		// field_biscrouched0
		uint16 Handle = 29;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_biscrouched0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_jumpmaxholdtime0().empty())
	{
		// field_jumpmaxholdtime0
		uint16 Handle = 30;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_jumpmaxholdtime0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_jumpmaxcount0().empty())
	{
		// field_jumpmaxcount0
		uint16 Handle = 31;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_jumpmaxcount0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_bisactive0().empty())
	{
		// field_reprootmotion0_bisactive0
		uint16 Handle = 32;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_reprootmotion0_bisactive0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_animmontage0().empty())
	{
		// field_reprootmotion0_animmontage0
		uint16 Handle = 33;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UAnimMontage* Value = *(reinterpret_cast<UAnimMontage* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_reprootmotion0_animmontage0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UAnimMontage>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<UAnimMontage>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_reprootmotion0_position0().empty())
	{
		// field_reprootmotion0_position0
		uint16 Handle = 34;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_reprootmotion0_position0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_location0().empty())
	{
		// field_reprootmotion0_location0
		uint16 Handle = 35;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_reprootmotion0_location0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_rotation0().empty())
	{
		// field_reprootmotion0_rotation0
		uint16 Handle = 36;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_reprootmotion0_rotation0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_movementbase0().empty())
	{
		// field_reprootmotion0_movementbase0
		uint16 Handle = 37;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UPrimitiveComponent* Value = *(reinterpret_cast<UPrimitiveComponent* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_reprootmotion0_movementbase0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_reprootmotion0_movementbasebonename0().empty())
	{
		// field_reprootmotion0_movementbasebonename0
		uint16 Handle = 38;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FName Value = *(reinterpret_cast<FName const*>(PropertyData));

			Value = FName(((*Update.field_reprootmotion0_movementbasebonename0().data())).data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_brelativeposition0().empty())
	{
		// field_reprootmotion0_brelativeposition0
		uint16 Handle = 39;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_reprootmotion0_brelativeposition0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_brelativerotation0().empty())
	{
		// field_reprootmotion0_brelativerotation0
		uint16 Handle = 40;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_reprootmotion0_brelativerotation0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_authoritativerootmotion0().empty())
	{
		// field_reprootmotion0_authoritativerootmotion0
		uint16 Handle = 41;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRootMotionSourceGroup Value = *(reinterpret_cast<FRootMotionSourceGroup const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_reprootmotion0_authoritativerootmotion0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRootMotionSourceGroup failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_acceleration0().empty())
	{
		// field_reprootmotion0_acceleration0
		uint16 Handle = 42;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize10 Value = *(reinterpret_cast<FVector_NetQuantize10 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_reprootmotion0_acceleration0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_linearvelocity0().empty())
	{
		// field_reprootmotion0_linearvelocity0
		uint16 Handle = 43;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize10 Value = *(reinterpret_cast<FVector_NetQuantize10 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_reprootmotion0_linearvelocity0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mycppstructins0_b0().empty())
	{
		// field_mycppstructins0_b0
		uint16 Handle = 44;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_mycppstructins0_b0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mycppstructins0_v0().empty())
	{
		// field_mycppstructins0_v0
		uint16 Handle = 45;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector Value = *(reinterpret_cast<FVector const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_mycppstructins0_v0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mynestedstructins0_structarr0().empty())
	{
		// field_mynestedstructins0_structarr0
		uint16 Handle = 46;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TArray<FMyCppStruct> Value = *(reinterpret_cast<TArray<FMyCppStruct> *>(PropertyData));

			auto& List = (*Update.field_mynestedstructins0_structarr0().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyCppStruct::StaticStruct()->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mynestedstructins0_boolarr0().empty())
	{
		// field_mynestedstructins0_boolarr0
		uint16 Handle = 47;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TArray<bool> Value = *(reinterpret_cast<TArray<bool> *>(PropertyData));

			auto& List = (*Update.field_mynestedstructins0_boolarr0().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				Value[i] = List[i];
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mycppstructarr0().empty())
	{
		// field_mycppstructarr0
		uint16 Handle = 48;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TArray<FMyCppStruct> Value = *(reinterpret_cast<TArray<FMyCppStruct> *>(PropertyData));

			auto& List = (*Update.field_mycppstructarr0().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyCppStruct::StaticStruct()->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mynestedstructarr0().empty())
	{
		// field_mynestedstructarr0
		uint16 Handle = 49;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TArray<FMyCppNestedStruct> Value = *(reinterpret_cast<TArray<FMyCppNestedStruct> *>(PropertyData));

			auto& List = (*Update.field_mynestedstructarr0().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyCppNestedStruct::StaticStruct()->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mybool0().empty())
	{
		// field_mybool0
		uint16 Handle = 50;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_mybool0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_myarrofbools0().empty())
	{
		// field_myarrofbools0
		uint16 Handle = 51;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TArray<bool> Value = *(reinterpret_cast<TArray<bool> *>(PropertyData));

			auto& List = (*Update.field_myarrofbools0().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				Value[i] = List[i];
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructvar0_structbool176b6bada4ba8fea4761b938495dea0e10().empty())
	{
		// field_mystructvar0_structbool176b6bada4ba8fea4761b938495dea0e10
		uint16 Handle = 52;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_mystructvar0_structbool176b6bada4ba8fea4761b938495dea0e10().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructvar0_structvec4734f338f470a88c85c79289bbb7e84670().empty())
	{
		// field_mystructvar0_structvec4734f338f470a88c85c79289bbb7e84670
		uint16 Handle = 53;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector Value = *(reinterpret_cast<FVector const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_mystructvar0_structvec4734f338f470a88c85c79289bbb7e84670().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_myarrofstructs0().empty())
	{
		// field_myarrofstructs0
		uint16 Handle = 54;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStruct__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStruct.MyStruct"), NULL, LOAD_None, NULL);
			TArray<FMyStruct__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStruct__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_myarrofstructs0().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStruct__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructnested0_myboolarraynested787d2b213446573ec06159db37e89cd990().empty())
	{
		// field_mystructnested0_myboolarraynested787d2b213446573ec06159db37e89cd990
		uint16 Handle = 55;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TArray<bool> Value = *(reinterpret_cast<TArray<bool> *>(PropertyData));

			auto& List = (*Update.field_mystructnested0_myboolarraynested787d2b213446573ec06159db37e89cd990().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				Value[i] = List[i];
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructnested0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70().empty())
	{
		// field_mystructnested0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70
		uint16 Handle = 56;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStruct__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStruct.MyStruct"), NULL, LOAD_None, NULL);
			TArray<FMyStruct__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStruct__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_mystructnested0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStruct__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructnestedarr0().empty())
	{
		// field_mystructnestedarr0
		uint16 Handle = 57;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStructWithArray__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/myStructWithArray.MyStructWithArray"), NULL, LOAD_None, NULL);
			TArray<FMyStructWithArray__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStructWithArray__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_mystructnestedarr0().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStructWithArray__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv2ins0_lv1ins2efc0167049b51ffb215e2284c0988e4b0_myboolarraynested787d2b213446573ec06159db37e89cd990().empty())
	{
		// field_mystructlv2ins0_lv1ins2efc0167049b51ffb215e2284c0988e4b0_myboolarraynested787d2b213446573ec06159db37e89cd990
		uint16 Handle = 58;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TArray<bool> Value = *(reinterpret_cast<TArray<bool> *>(PropertyData));

			auto& List = (*Update.field_mystructlv2ins0_lv1ins2efc0167049b51ffb215e2284c0988e4b0_myboolarraynested787d2b213446573ec06159db37e89cd990().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				Value[i] = List[i];
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv2ins0_lv1ins2efc0167049b51ffb215e2284c0988e4b0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70().empty())
	{
		// field_mystructlv2ins0_lv1ins2efc0167049b51ffb215e2284c0988e4b0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70
		uint16 Handle = 59;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStruct__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStruct.MyStruct"), NULL, LOAD_None, NULL);
			TArray<FMyStruct__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStruct__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_mystructlv2ins0_lv1ins2efc0167049b51ffb215e2284c0988e4b0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStruct__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv2ins0_lv1arr56e29525c4699b03778e671ba749c6ea70().empty())
	{
		// field_mystructlv2ins0_lv1arr56e29525c4699b03778e671ba749c6ea70
		uint16 Handle = 60;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStructWithArray__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/myStructWithArray.MyStructWithArray"), NULL, LOAD_None, NULL);
			TArray<FMyStructWithArray__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStructWithArray__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_mystructlv2ins0_lv1arr56e29525c4699b03778e671ba749c6ea70().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStructWithArray__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv2ins0_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structbool176b6bada4ba8fea4761b938495dea0e10().empty())
	{
		// field_mystructlv2ins0_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structbool176b6bada4ba8fea4761b938495dea0e10
		uint16 Handle = 61;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_mystructlv2ins0_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structbool176b6bada4ba8fea4761b938495dea0e10().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv2ins0_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structvec4734f338f470a88c85c79289bbb7e84670().empty())
	{
		// field_mystructlv2ins0_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structvec4734f338f470a88c85c79289bbb7e84670
		uint16 Handle = 62;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector Value = *(reinterpret_cast<FVector const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_mystructlv2ins0_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structvec4734f338f470a88c85c79289bbb7e84670().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv2arr0().empty())
	{
		// field_mystructlv2arr0
		uint16 Handle = 63;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStructLv2__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStructLv2.MyStructLv2"), NULL, LOAD_None, NULL);
			TArray<FMyStructLv2__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStructLv2__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_mystructlv2arr0().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStructLv2__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1ins2efc0167049b51ffb215e2284c0988e4b0_myboolarraynested787d2b213446573ec06159db37e89cd990().empty())
	{
		// field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1ins2efc0167049b51ffb215e2284c0988e4b0_myboolarraynested787d2b213446573ec06159db37e89cd990
		uint16 Handle = 64;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TArray<bool> Value = *(reinterpret_cast<TArray<bool> *>(PropertyData));

			auto& List = (*Update.field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1ins2efc0167049b51ffb215e2284c0988e4b0_myboolarraynested787d2b213446573ec06159db37e89cd990().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				Value[i] = List[i];
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1ins2efc0167049b51ffb215e2284c0988e4b0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70().empty())
	{
		// field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1ins2efc0167049b51ffb215e2284c0988e4b0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70
		uint16 Handle = 65;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStruct__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStruct.MyStruct"), NULL, LOAD_None, NULL);
			TArray<FMyStruct__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStruct__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1ins2efc0167049b51ffb215e2284c0988e4b0_mystructarraynested63b3d5a594bf31a5d239e52af9ad0d3d70().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStruct__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1arr56e29525c4699b03778e671ba749c6ea70().empty())
	{
		// field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1arr56e29525c4699b03778e671ba749c6ea70
		uint16 Handle = 66;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStructWithArray__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/myStructWithArray.MyStructWithArray"), NULL, LOAD_None, NULL);
			TArray<FMyStructWithArray__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStructWithArray__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv1arr56e29525c4699b03778e671ba749c6ea70().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStructWithArray__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structbool176b6bada4ba8fea4761b938495dea0e10().empty())
	{
		// field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structbool176b6bada4ba8fea4761b938495dea0e10
		uint16 Handle = 67;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structbool176b6bada4ba8fea4761b938495dea0e10().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structvec4734f338f470a88c85c79289bbb7e84670().empty())
	{
		// field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structvec4734f338f470a88c85c79289bbb7e84670
		uint16 Handle = 68;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector Value = *(reinterpret_cast<FVector const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_mystructlv3ins0_lv2ins3bc6beb9d4c9afc99d6925f881e8deb210_lv0ins9a4b4ec294f2b5a8ee604a78342aec4fd0_structvec4734f338f470a88c85c79289bbb7e84670().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv3ins0_lv2arr67a77e9954d2d0a825445fcae349de7050().empty())
	{
		// field_mystructlv3ins0_lv2arr67a77e9954d2d0a825445fcae349de7050
		uint16 Handle = 69;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStructLv2__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStructLv2.MyStructLv2"), NULL, LOAD_None, NULL);
			TArray<FMyStructLv2__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStructLv2__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_mystructlv3ins0_lv2arr67a77e9954d2d0a825445fcae349de7050().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStructLv2__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv3ins0_lv1arr91ee4dd494c52603042686dbb437959400().empty())
	{
		// field_mystructlv3ins0_lv1arr91ee4dd494c52603042686dbb437959400
		uint16 Handle = 70;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStructWithArray__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/myStructWithArray.MyStructWithArray"), NULL, LOAD_None, NULL);
			TArray<FMyStructWithArray__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStructWithArray__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_mystructlv3ins0_lv1arr91ee4dd494c52603042686dbb437959400().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStructWithArray__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv3ins0_vectorarr139869b6eb4c946b8a5b8b32931edb24130().empty())
	{
		// field_mystructlv3ins0_vectorarr139869b6eb4c946b8a5b8b32931edb24130
		uint16 Handle = 71;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TArray<FVector> Value = *(reinterpret_cast<TArray<FVector> *>(PropertyData));

			auto& List = (*Update.field_mystructlv3ins0_vectorarr139869b6eb4c946b8a5b8b32931edb24130().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				bool bSuccess = true;
				Value[i].NetSerialize(ValueDataReader, PackageMap, bSuccess);
				checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_mystructlv3arr0().empty())
	{
		// field_mystructlv3arr0
		uint16 Handle = 72;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UStruct* FMyStructlv3__pf3826073315_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/ThirdPersonCPP/Blueprints/MyStructlv3.MyStructlv3"), NULL, LOAD_None, NULL);
			TArray<FMyStructlv3__pf3826073315> Value = *(reinterpret_cast<TArray<FMyStructlv3__pf3826073315> *>(PropertyData));

			auto& List = (*Update.field_mystructlv3arr0().data());
			Value.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
				FMyStructlv3__pf3826073315_Struct->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	ActorChannel->PostReceiveSpatialUpdate(TargetObject, RepNotifies.Array());
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ReceiveUpdate_Handover(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::Update& Update) const
{
	const FHandoverHandlePropertyMap& HandleToPropertyMap = GetHandoverHandlePropertyMap();

	if (!Update.field_charactermovement0_movementmode0().empty())
	{
		// field_charactermovement0_movementmode0
		uint16 Handle = 1;
		const FHandoverHandleData* HandoverData = &HandleToPropertyMap[Handle];
		uint8* PropertyData = HandoverData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
		TEnumAsByte<EMovementMode> Value = *(reinterpret_cast<TEnumAsByte<EMovementMode> const*>(PropertyData));

		Value = TEnumAsByte<EMovementMode>(uint8((*Update.field_charactermovement0_movementmode0().data())));

		ApplyIncomingHandoverPropertyUpdate(*HandoverData, ActorChannel->Actor, static_cast<const void*>(&Value));

		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received handover property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ActorChannel->Actor->GetName(),
			ActorChannel->GetEntityId().ToSpatialEntityId(),
			*HandoverData->Property->GetName(),
			Handle);
	}
	if (!Update.field_charactermovement0_custommovementmode0().empty())
	{
		// field_charactermovement0_custommovementmode0
		uint16 Handle = 2;
		const FHandoverHandleData* HandoverData = &HandleToPropertyMap[Handle];
		uint8* PropertyData = HandoverData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
		uint8 Value = *(reinterpret_cast<uint8 const*>(PropertyData));

		Value = uint8(uint8((*Update.field_charactermovement0_custommovementmode0().data())));

		ApplyIncomingHandoverPropertyUpdate(*HandoverData, ActorChannel->Actor, static_cast<const void*>(&Value));

		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received handover property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ActorChannel->Actor->GetName(),
			ActorChannel->GetEntityId().ToSpatialEntityId(),
			*HandoverData->Property->GetName(),
			Handle);
	}
	if (!Update.field_charactermovement0_groundmovementmode0().empty())
	{
		// field_charactermovement0_groundmovementmode0
		uint16 Handle = 3;
		const FHandoverHandleData* HandoverData = &HandleToPropertyMap[Handle];
		uint8* PropertyData = HandoverData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
		TEnumAsByte<EMovementMode> Value = *(reinterpret_cast<TEnumAsByte<EMovementMode> const*>(PropertyData));

		Value = TEnumAsByte<EMovementMode>(uint8((*Update.field_charactermovement0_groundmovementmode0().data())));

		ApplyIncomingHandoverPropertyUpdate(*HandoverData, ActorChannel->Actor, static_cast<const void*>(&Value));

		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received handover property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ActorChannel->Actor->GetName(),
			ActorChannel->GetEntityId().ToSpatialEntityId(),
			*HandoverData->Property->GetName(),
			Handle);
	}
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCNetMulticastRPCs::Update& Update)
{
	for (auto& event : Update.testmulticast())
	{
		TestMulticast_OnRPCPayload(EntityId, event);
	}

}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::TestClientRPC_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC TestClientRPC queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::starterprojectcharacter::TestClientRPCRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: TestClientRPC, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Testclientrpc>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::RootMotionDebugClientPrintOnScreen_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventRootMotionDebugClientPrintOnScreen_Parms StructuredParams = *static_cast<Character_eventRootMotionDebugClientPrintOnScreen_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC RootMotionDebugClientPrintOnScreen queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::RootMotionDebugClientPrintOnScreenRequest RPCPayload;
		{
			RPCPayload.set_field_instring0(TCHAR_TO_UTF8(*StructuredParams.InString));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: RootMotionDebugClientPrintOnScreen, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Rootmotiondebugclientprintonscreen>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientVeryShortAdjustPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventClientVeryShortAdjustPosition_Parms StructuredParams = *static_cast<Character_eventClientVeryShortAdjustPosition_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientVeryShortAdjustPosition queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientVeryShortAdjustPositionRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.NewLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_newloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			if (StructuredParams.NewBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.NewBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.NewBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.NewBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientVeryShortAdjustPosition queued. StructuredParams.NewBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.NewBase)};
				}
				else
				{
					RPCPayload.set_field_newbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_newbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_newbasebonename0(TCHAR_TO_UTF8(*StructuredParams.NewBaseBoneName.ToString()));
		}
		{
			RPCPayload.set_field_bhasbase0(StructuredParams.bHasBase);
		}
		{
			RPCPayload.set_field_bbaserelativeposition0(StructuredParams.bBaseRelativePosition);
		}
		{
			RPCPayload.set_field_servermovementmode0(uint32_t(StructuredParams.ServerMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientVeryShortAdjustPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientveryshortadjustposition>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatWalk_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientCheatWalk queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientCheatWalkRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientCheatWalk, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatwalk>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatGhost_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientCheatGhost queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientCheatGhostRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientCheatGhost, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatghost>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatFly_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientCheatFly queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientCheatFlyRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientCheatFly, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatfly>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionSourcePosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventClientAdjustRootMotionSourcePosition_Parms StructuredParams = *static_cast<Character_eventClientAdjustRootMotionSourcePosition_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustRootMotionSourcePosition queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientAdjustRootMotionSourcePositionRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRootMotionSourceGroup&>(StructuredParams.ServerRootMotion)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRootMotionSourceGroup failed."));
			RPCPayload.set_field_serverrootmotion0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_bhasanimrootmotion0(StructuredParams.bHasAnimRootMotion);
		}
		{
			RPCPayload.set_field_servermontagetrackposition0(StructuredParams.ServerMontageTrackPosition);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.ServerLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_serverloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantizeNormal&>(StructuredParams.ServerRotation)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantizeNormal failed."));
			RPCPayload.set_field_serverrotation0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_servervelz0(StructuredParams.ServerVelZ);
		}
		{
			if (StructuredParams.ServerBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ServerBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.ServerBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.ServerBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustRootMotionSourcePosition queued. StructuredParams.ServerBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.ServerBase)};
				}
				else
				{
					RPCPayload.set_field_serverbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_serverbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_serverbonename0(TCHAR_TO_UTF8(*StructuredParams.ServerBoneName.ToString()));
		}
		{
			RPCPayload.set_field_bhasbase0(StructuredParams.bHasBase);
		}
		{
			RPCPayload.set_field_bbaserelativeposition0(StructuredParams.bBaseRelativePosition);
		}
		{
			RPCPayload.set_field_servermovementmode0(uint32_t(StructuredParams.ServerMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientAdjustRootMotionSourcePosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionsourceposition>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventClientAdjustRootMotionPosition_Parms StructuredParams = *static_cast<Character_eventClientAdjustRootMotionPosition_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustRootMotionPosition queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientAdjustRootMotionPositionRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			RPCPayload.set_field_servermontagetrackposition0(StructuredParams.ServerMontageTrackPosition);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.ServerLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_serverloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantizeNormal&>(StructuredParams.ServerRotation)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantizeNormal failed."));
			RPCPayload.set_field_serverrotation0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_servervelz0(StructuredParams.ServerVelZ);
		}
		{
			if (StructuredParams.ServerBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ServerBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.ServerBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.ServerBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustRootMotionPosition queued. StructuredParams.ServerBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.ServerBase)};
				}
				else
				{
					RPCPayload.set_field_serverbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_serverbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_serverbonename0(TCHAR_TO_UTF8(*StructuredParams.ServerBoneName.ToString()));
		}
		{
			RPCPayload.set_field_bhasbase0(StructuredParams.bHasBase);
		}
		{
			RPCPayload.set_field_bbaserelativeposition0(StructuredParams.bBaseRelativePosition);
		}
		{
			RPCPayload.set_field_servermovementmode0(uint32_t(StructuredParams.ServerMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientAdjustRootMotionPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionposition>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventClientAdjustPosition_Parms StructuredParams = *static_cast<Character_eventClientAdjustPosition_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustPosition queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientAdjustPositionRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.NewLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_newloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.NewVel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_newvel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			if (StructuredParams.NewBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.NewBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.NewBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.NewBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustPosition queued. StructuredParams.NewBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.NewBase)};
				}
				else
				{
					RPCPayload.set_field_newbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_newbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_newbasebonename0(TCHAR_TO_UTF8(*StructuredParams.NewBaseBoneName.ToString()));
		}
		{
			RPCPayload.set_field_bhasbase0(StructuredParams.bHasBase);
		}
		{
			RPCPayload.set_field_bbaserelativeposition0(StructuredParams.bBaseRelativePosition);
		}
		{
			RPCPayload.set_field_servermovementmode0(uint32_t(StructuredParams.ServerMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientAdjustPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustposition>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAckGoodMove_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventClientAckGoodMove_Parms StructuredParams = *static_cast<Character_eventClientAckGoodMove_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAckGoodMove queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientAckGoodMoveRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientAckGoodMove, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientackgoodmove>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs1_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC SetArrOfStructs1 queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::starterprojectcharacterbpc::SetArrOfStructs1Request RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: SetArrOfStructs1, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs1>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs2_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC SetArrOfStructs2 queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::starterprojectcharacterbpc::SetArrOfStructs2Request RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: SetArrOfStructs2, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs2>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::RPCStructInput_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	struct StarterProjectCharacter_BP_C_eventRPCStructInput_Parms
	{
		bool BoolIn;
		FMyStruct__pf3826073315 StructIn;
	};

	StarterProjectCharacter_BP_C_eventRPCStructInput_Parms StructuredParams = *static_cast<StarterProjectCharacter_BP_C_eventRPCStructInput_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC RPCStructInput queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::starterprojectcharacterbpc::RPCStructInputRequest RPCPayload;
		{
			RPCPayload.set_field_boolin0(StructuredParams.BoolIn);
		}
		{
			RPCPayload.set_field_structin0_structbool176b6bada4ba8fea4761b938495dea0e10(StructuredParams.StructIn.StructBool_1_76B6BADA4BA8FEA4761B938495DEA0E1);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.StructIn.StructVec_4_734F338F470A88C85C79289BBB7E8467)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_structin0_structvec4734f338f470a88c85c79289bbb7e84670(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: RPCStructInput, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Rpcstructinput>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructCpp_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC UpdateNestedStructCpp queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::starterprojectcharacterbpc::UpdateNestedStructCppRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: UpdateNestedStructCpp, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructcpp>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructBP_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC Update Nested Struct BP queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::starterprojectcharacterbpc::UpdateNestedStructBPRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: Update Nested Struct BP, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructbp>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::TestRPC_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC TestRPC queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::starterprojectcharacter::TestRPCRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: TestRPC, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Testrpc>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveOld_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMoveOld_Parms StructuredParams = *static_cast<Character_eventServerMoveOld_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveOld queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveOldRequest RPCPayload;
		{
			RPCPayload.set_field_oldtimestamp0(StructuredParams.OldTimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.OldAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_oldaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_oldmoveflags0(uint32_t(StructuredParams.OldMoveFlags));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMoveOld, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermoveold>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveNoBase_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMoveNoBase_Parms StructuredParams = *static_cast<Character_eventServerMoveNoBase_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveNoBase queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveNoBaseRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(StructuredParams.ClientLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			RPCPayload.set_field_clientloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_compressedmoveflags0(uint32_t(StructuredParams.CompressedMoveFlags));
		}
		{
			RPCPayload.set_field_clientroll0(uint32_t(StructuredParams.ClientRoll));
		}
		{
			RPCPayload.set_field_view0(uint32_t(StructuredParams.View));
		}
		{
			RPCPayload.set_field_clientmovementmode0(uint32_t(StructuredParams.ClientMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMoveNoBase, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovenobase>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualNoBase_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMoveDualNoBase_Parms StructuredParams = *static_cast<Character_eventServerMoveDualNoBase_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveDualNoBase queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveDualNoBaseRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp00(StructuredParams.TimeStamp0);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel0)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel00(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_pendingflags0(uint32_t(StructuredParams.PendingFlags));
		}
		{
			RPCPayload.set_field_view00(uint32_t(StructuredParams.View0));
		}
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(StructuredParams.ClientLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			RPCPayload.set_field_clientloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_newflags0(uint32_t(StructuredParams.NewFlags));
		}
		{
			RPCPayload.set_field_clientroll0(uint32_t(StructuredParams.ClientRoll));
		}
		{
			RPCPayload.set_field_view0(uint32_t(StructuredParams.View));
		}
		{
			RPCPayload.set_field_clientmovementmode0(uint32_t(StructuredParams.ClientMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMoveDualNoBase, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualnobase>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualHybridRootMotion_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMoveDualHybridRootMotion_Parms StructuredParams = *static_cast<Character_eventServerMoveDualHybridRootMotion_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveDualHybridRootMotion queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveDualHybridRootMotionRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp00(StructuredParams.TimeStamp0);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel0)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel00(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_pendingflags0(uint32_t(StructuredParams.PendingFlags));
		}
		{
			RPCPayload.set_field_view00(uint32_t(StructuredParams.View0));
		}
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(StructuredParams.ClientLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			RPCPayload.set_field_clientloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_newflags0(uint32_t(StructuredParams.NewFlags));
		}
		{
			RPCPayload.set_field_clientroll0(uint32_t(StructuredParams.ClientRoll));
		}
		{
			RPCPayload.set_field_view0(uint32_t(StructuredParams.View));
		}
		{
			if (StructuredParams.ClientMovementBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ClientMovementBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.ClientMovementBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.ClientMovementBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveDualHybridRootMotion queued. StructuredParams.ClientMovementBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.ClientMovementBase)};
				}
				else
				{
					RPCPayload.set_field_clientmovementbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_clientmovementbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_clientbasebonename0(TCHAR_TO_UTF8(*StructuredParams.ClientBaseBoneName.ToString()));
		}
		{
			RPCPayload.set_field_clientmovementmode0(uint32_t(StructuredParams.ClientMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMoveDualHybridRootMotion, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualhybridrootmotion>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDual_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMoveDual_Parms StructuredParams = *static_cast<Character_eventServerMoveDual_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveDual queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveDualRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp00(StructuredParams.TimeStamp0);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel0)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel00(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_pendingflags0(uint32_t(StructuredParams.PendingFlags));
		}
		{
			RPCPayload.set_field_view00(uint32_t(StructuredParams.View0));
		}
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(StructuredParams.ClientLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			RPCPayload.set_field_clientloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_newflags0(uint32_t(StructuredParams.NewFlags));
		}
		{
			RPCPayload.set_field_clientroll0(uint32_t(StructuredParams.ClientRoll));
		}
		{
			RPCPayload.set_field_view0(uint32_t(StructuredParams.View));
		}
		{
			if (StructuredParams.ClientMovementBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ClientMovementBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.ClientMovementBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.ClientMovementBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveDual queued. StructuredParams.ClientMovementBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.ClientMovementBase)};
				}
				else
				{
					RPCPayload.set_field_clientmovementbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_clientmovementbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_clientbasebonename0(TCHAR_TO_UTF8(*StructuredParams.ClientBaseBoneName.ToString()));
		}
		{
			RPCPayload.set_field_clientmovementmode0(uint32_t(StructuredParams.ClientMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMoveDual, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedual>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMove_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMove_Parms StructuredParams = *static_cast<Character_eventServerMove_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMove queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(StructuredParams.ClientLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			RPCPayload.set_field_clientloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_compressedmoveflags0(uint32_t(StructuredParams.CompressedMoveFlags));
		}
		{
			RPCPayload.set_field_clientroll0(uint32_t(StructuredParams.ClientRoll));
		}
		{
			RPCPayload.set_field_view0(uint32_t(StructuredParams.View));
		}
		{
			if (StructuredParams.ClientMovementBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ClientMovementBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.ClientMovementBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.ClientMovementBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMove queued. StructuredParams.ClientMovementBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.ClientMovementBase)};
				}
				else
				{
					RPCPayload.set_field_clientmovementbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_clientmovementbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_clientbasebonename0(TCHAR_TO_UTF8(*StructuredParams.ClientBaseBoneName.ToString()));
		}
		{
			RPCPayload.set_field_clientmovementmode0(uint32_t(StructuredParams.ClientMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMove, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermove>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::TestMulticast_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC TestMulticast queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::starterprojectcharacter::TestMulticastRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: TestMulticast, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCNetMulticastRPCs::Update Update;
			Update.add_testmulticast(RPCPayload);
			checkf(Update.testmulticast().size() == 1, TEXT("TestMulticast_SendCommand: More than one event being sent"));
			Connection->SendComponentUpdate<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCNetMulticastRPCs>(TargetObjectRef.entity(), Update);
			return {};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::TestClientRPC_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Testclientrpc>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: TestClientRPC_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: TestClientRPC_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: TestClientRPC, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("TestClientRPC"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: TestClientRPC_OnRPCPayload: Function not found. Object: %s, Function: TestClientRPC."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Testclientrpc>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::RootMotionDebugClientPrintOnScreen_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Rootmotiondebugclientprintonscreen>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RootMotionDebugClientPrintOnScreen_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: RootMotionDebugClientPrintOnScreen_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventRootMotionDebugClientPrintOnScreen_Parms Parameters;

		// Extract from request data.
		{
			Parameters.InString = FString(UTF8_TO_TCHAR(Op.Request.field_instring0().c_str()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: RootMotionDebugClientPrintOnScreen, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("RootMotionDebugClientPrintOnScreen"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: RootMotionDebugClientPrintOnScreen_OnRPCPayload: Function not found. Object: %s, Function: RootMotionDebugClientPrintOnScreen."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Rootmotiondebugclientprintonscreen>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientVeryShortAdjustPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientveryshortadjustposition>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientVeryShortAdjustPosition_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientVeryShortAdjustPosition_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventClientVeryShortAdjustPosition_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_newloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.NewLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_newbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.NewBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.NewBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientVeryShortAdjustPosition_OnRPCPayload: Parameters.NewBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.NewBaseBoneName = FName((Op.Request.field_newbasebonename0()).data());
		}
		{
			Parameters.bHasBase = Op.Request.field_bhasbase0();
		}
		{
			Parameters.bBaseRelativePosition = Op.Request.field_bbaserelativeposition0();
		}
		{
			Parameters.ServerMovementMode = uint8(uint8(Op.Request.field_servermovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientVeryShortAdjustPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientVeryShortAdjustPosition"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientVeryShortAdjustPosition_OnRPCPayload: Function not found. Object: %s, Function: ClientVeryShortAdjustPosition."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientveryshortadjustposition>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatWalk_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatwalk>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientCheatWalk_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCheatWalk_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientCheatWalk, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCheatWalk"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientCheatWalk_OnRPCPayload: Function not found. Object: %s, Function: ClientCheatWalk."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatwalk>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatGhost_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatghost>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientCheatGhost_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCheatGhost_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientCheatGhost, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCheatGhost"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientCheatGhost_OnRPCPayload: Function not found. Object: %s, Function: ClientCheatGhost."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatghost>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatFly_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatfly>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientCheatFly_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCheatFly_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientCheatFly, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCheatFly"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientCheatFly_OnRPCPayload: Function not found. Object: %s, Function: ClientCheatFly."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatfly>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionSourcePosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionsourceposition>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustRootMotionSourcePosition_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientAdjustRootMotionSourcePosition_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventClientAdjustRootMotionSourcePosition_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_serverrootmotion0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ServerRootMotion.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRootMotionSourceGroup failed."));
		}
		{
			Parameters.bHasAnimRootMotion = Op.Request.field_bhasanimrootmotion0();
		}
		{
			Parameters.ServerMontageTrackPosition = Op.Request.field_servermontagetrackposition0();
		}
		{
			auto& ValueDataStr = Op.Request.field_serverloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ServerLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_serverrotation0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ServerRotation.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantizeNormal failed."));
		}
		{
			Parameters.ServerVelZ = Op.Request.field_servervelz0();
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_serverbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ServerBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.ServerBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustRootMotionSourcePosition_OnRPCPayload: Parameters.ServerBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.ServerBoneName = FName((Op.Request.field_serverbonename0()).data());
		}
		{
			Parameters.bHasBase = Op.Request.field_bhasbase0();
		}
		{
			Parameters.bBaseRelativePosition = Op.Request.field_bbaserelativeposition0();
		}
		{
			Parameters.ServerMovementMode = uint8(uint8(Op.Request.field_servermovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientAdjustRootMotionSourcePosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientAdjustRootMotionSourcePosition"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientAdjustRootMotionSourcePosition_OnRPCPayload: Function not found. Object: %s, Function: ClientAdjustRootMotionSourcePosition."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionsourceposition>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionposition>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustRootMotionPosition_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientAdjustRootMotionPosition_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventClientAdjustRootMotionPosition_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			Parameters.ServerMontageTrackPosition = Op.Request.field_servermontagetrackposition0();
		}
		{
			auto& ValueDataStr = Op.Request.field_serverloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ServerLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_serverrotation0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ServerRotation.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantizeNormal failed."));
		}
		{
			Parameters.ServerVelZ = Op.Request.field_servervelz0();
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_serverbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ServerBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.ServerBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustRootMotionPosition_OnRPCPayload: Parameters.ServerBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.ServerBoneName = FName((Op.Request.field_serverbonename0()).data());
		}
		{
			Parameters.bHasBase = Op.Request.field_bhasbase0();
		}
		{
			Parameters.bBaseRelativePosition = Op.Request.field_bbaserelativeposition0();
		}
		{
			Parameters.ServerMovementMode = uint8(uint8(Op.Request.field_servermovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientAdjustRootMotionPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientAdjustRootMotionPosition"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientAdjustRootMotionPosition_OnRPCPayload: Function not found. Object: %s, Function: ClientAdjustRootMotionPosition."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionposition>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustposition>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustPosition_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientAdjustPosition_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventClientAdjustPosition_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_newloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.NewLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_newvel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.NewVel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_newbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.NewBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.NewBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustPosition_OnRPCPayload: Parameters.NewBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.NewBaseBoneName = FName((Op.Request.field_newbasebonename0()).data());
		}
		{
			Parameters.bHasBase = Op.Request.field_bhasbase0();
		}
		{
			Parameters.bBaseRelativePosition = Op.Request.field_bbaserelativeposition0();
		}
		{
			Parameters.ServerMovementMode = uint8(uint8(Op.Request.field_servermovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientAdjustPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientAdjustPosition"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientAdjustPosition_OnRPCPayload: Function not found. Object: %s, Function: ClientAdjustPosition."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustposition>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAckGoodMove_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientackgoodmove>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAckGoodMove_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientAckGoodMove_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventClientAckGoodMove_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientAckGoodMove, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientAckGoodMove"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientAckGoodMove_OnRPCPayload: Function not found. Object: %s, Function: ClientAckGoodMove."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientackgoodmove>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs1_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs1>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: SetArrOfStructs1_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: SetArrOfStructs1_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: SetArrOfStructs1, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("SetArrOfStructs1"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: SetArrOfStructs1_OnRPCPayload: Function not found. Object: %s, Function: SetArrOfStructs1."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs1>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs2_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs2>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: SetArrOfStructs2_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: SetArrOfStructs2_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: SetArrOfStructs2, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("SetArrOfStructs2"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: SetArrOfStructs2_OnRPCPayload: Function not found. Object: %s, Function: SetArrOfStructs2."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs2>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::RPCStructInput_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Rpcstructinput>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPCStructInput_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: RPCStructInput_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		struct StarterProjectCharacter_BP_C_eventRPCStructInput_Parms
		{
			bool BoolIn;
			FMyStruct__pf3826073315 StructIn;
		};

		StarterProjectCharacter_BP_C_eventRPCStructInput_Parms Parameters;

		// Extract from request data.
		{
			Parameters.BoolIn = Op.Request.field_boolin0();
		}
		{
			Parameters.StructIn.StructBool_1_76B6BADA4BA8FEA4761B938495DEA0E1 = Op.Request.field_structin0_structbool176b6bada4ba8fea4761b938495dea0e10();
		}
		{
			auto& ValueDataStr = Op.Request.field_structin0_structvec4734f338f470a88c85c79289bbb7e84670();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.StructIn.StructVec_4_734F338F470A88C85C79289BBB7E8467.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: RPCStructInput, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("RPCStructInput"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: RPCStructInput_OnRPCPayload: Function not found. Object: %s, Function: RPCStructInput."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Rpcstructinput>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructCpp_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructcpp>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: UpdateNestedStructCpp_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: UpdateNestedStructCpp_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: UpdateNestedStructCpp, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("UpdateNestedStructCpp"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: UpdateNestedStructCpp_OnRPCPayload: Function not found. Object: %s, Function: UpdateNestedStructCpp."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructcpp>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructBP_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructbp>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: UpdateNestedStructBP_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: Update Nested Struct BP_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: Update Nested Struct BP, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("Update Nested Struct BP"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: UpdateNestedStructBP_OnRPCPayload: Function not found. Object: %s, Function: UpdateNestedStructBP."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructbp>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::TestRPC_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Testrpc>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: TestRPC_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: TestRPC_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: TestRPC, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("TestRPC"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: TestRPC_OnRPCPayload: Function not found. Object: %s, Function: TestRPC."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Testrpc>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveOld_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermoveold>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveOld_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMoveOld_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMoveOld_Parms Parameters;

		// Extract from request data.
		{
			Parameters.OldTimeStamp = Op.Request.field_oldtimestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_oldaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.OldAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			Parameters.OldMoveFlags = uint8(uint8(Op.Request.field_oldmoveflags0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMoveOld, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMoveOld"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMoveOld_OnRPCPayload: Function not found. Object: %s, Function: ServerMoveOld."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermoveold>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveNoBase_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovenobase>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveNoBase_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMoveNoBase_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMoveNoBase_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_clientloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ClientLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
		}
		{
			Parameters.CompressedMoveFlags = uint8(uint8(Op.Request.field_compressedmoveflags0()));
		}
		{
			Parameters.ClientRoll = uint8(uint8(Op.Request.field_clientroll0()));
		}
		{
			Parameters.View = Op.Request.field_view0();
		}
		{
			Parameters.ClientMovementMode = uint8(uint8(Op.Request.field_clientmovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMoveNoBase, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMoveNoBase"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMoveNoBase_OnRPCPayload: Function not found. Object: %s, Function: ServerMoveNoBase."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovenobase>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualNoBase_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualnobase>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveDualNoBase_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMoveDualNoBase_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMoveDualNoBase_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp0 = Op.Request.field_timestamp00();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel00();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel0.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			Parameters.PendingFlags = uint8(uint8(Op.Request.field_pendingflags0()));
		}
		{
			Parameters.View0 = Op.Request.field_view00();
		}
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_clientloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ClientLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
		}
		{
			Parameters.NewFlags = uint8(uint8(Op.Request.field_newflags0()));
		}
		{
			Parameters.ClientRoll = uint8(uint8(Op.Request.field_clientroll0()));
		}
		{
			Parameters.View = Op.Request.field_view0();
		}
		{
			Parameters.ClientMovementMode = uint8(uint8(Op.Request.field_clientmovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMoveDualNoBase, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMoveDualNoBase"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMoveDualNoBase_OnRPCPayload: Function not found. Object: %s, Function: ServerMoveDualNoBase."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualnobase>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualHybridRootMotion_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualhybridrootmotion>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveDualHybridRootMotion_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMoveDualHybridRootMotion_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMoveDualHybridRootMotion_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp0 = Op.Request.field_timestamp00();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel00();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel0.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			Parameters.PendingFlags = uint8(uint8(Op.Request.field_pendingflags0()));
		}
		{
			Parameters.View0 = Op.Request.field_view00();
		}
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_clientloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ClientLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
		}
		{
			Parameters.NewFlags = uint8(uint8(Op.Request.field_newflags0()));
		}
		{
			Parameters.ClientRoll = uint8(uint8(Op.Request.field_clientroll0()));
		}
		{
			Parameters.View = Op.Request.field_view0();
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_clientmovementbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ClientMovementBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.ClientMovementBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveDualHybridRootMotion_OnRPCPayload: Parameters.ClientMovementBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.ClientBaseBoneName = FName((Op.Request.field_clientbasebonename0()).data());
		}
		{
			Parameters.ClientMovementMode = uint8(uint8(Op.Request.field_clientmovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMoveDualHybridRootMotion, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMoveDualHybridRootMotion"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMoveDualHybridRootMotion_OnRPCPayload: Function not found. Object: %s, Function: ServerMoveDualHybridRootMotion."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualhybridrootmotion>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDual_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedual>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveDual_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMoveDual_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMoveDual_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp0 = Op.Request.field_timestamp00();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel00();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel0.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			Parameters.PendingFlags = uint8(uint8(Op.Request.field_pendingflags0()));
		}
		{
			Parameters.View0 = Op.Request.field_view00();
		}
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_clientloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ClientLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
		}
		{
			Parameters.NewFlags = uint8(uint8(Op.Request.field_newflags0()));
		}
		{
			Parameters.ClientRoll = uint8(uint8(Op.Request.field_clientroll0()));
		}
		{
			Parameters.View = Op.Request.field_view0();
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_clientmovementbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ClientMovementBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.ClientMovementBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveDual_OnRPCPayload: Parameters.ClientMovementBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.ClientBaseBoneName = FName((Op.Request.field_clientbasebonename0()).data());
		}
		{
			Parameters.ClientMovementMode = uint8(uint8(Op.Request.field_clientmovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMoveDual, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMoveDual"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMoveDual_OnRPCPayload: Function not found. Object: %s, Function: ServerMoveDual."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedual>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMove_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermove>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMove_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMove_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMove_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_clientloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ClientLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
		}
		{
			Parameters.CompressedMoveFlags = uint8(uint8(Op.Request.field_compressedmoveflags0()));
		}
		{
			Parameters.ClientRoll = uint8(uint8(Op.Request.field_clientroll0()));
		}
		{
			Parameters.View = Op.Request.field_view0();
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_clientmovementbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ClientMovementBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.ClientMovementBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMove_OnRPCPayload: Parameters.ClientMovementBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.ClientBaseBoneName = FName((Op.Request.field_clientbasebonename0()).data());
		}
		{
			Parameters.ClientMovementMode = uint8(uint8(Op.Request.field_clientmovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMove, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMove"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMove_OnRPCPayload: Function not found. Object: %s, Function: ServerMove."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermove>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_StarterProjectCharacter_BP_C::TestMulticast_OnRPCPayload(const worker::EntityId EntityId, const improbable::unreal::generated::starterprojectcharacter::TestMulticastRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: TestMulticast_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: TestMulticast_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: TestMulticast, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("TestMulticast"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: TestMulticast_OnRPCPayload: Function not found. Object: %s, Function: TestMulticast."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::TestClientRPC_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Testclientrpc>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("TestClientRPC"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::RootMotionDebugClientPrintOnScreen_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Rootmotiondebugclientprintonscreen>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("RootMotionDebugClientPrintOnScreen"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientVeryShortAdjustPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientveryshortadjustposition>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientVeryShortAdjustPosition"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatWalk_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatwalk>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientCheatWalk"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatGhost_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatghost>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientCheatGhost"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientCheatFly_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatfly>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientCheatFly"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionSourcePosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionsourceposition>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientAdjustRootMotionSourcePosition"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustRootMotionPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionposition>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientAdjustRootMotionPosition"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAdjustPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustposition>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientAdjustPosition"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ClientAckGoodMove_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientackgoodmove>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientAckGoodMove"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs1_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs1>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("SetArrOfStructs1"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::SetArrOfStructs2_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs2>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("SetArrOfStructs2"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::RPCStructInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Rpcstructinput>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("RPCStructInput"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructCpp_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructcpp>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("UpdateNestedStructCpp"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::UpdateNestedStructBP_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructbp>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("Update Nested Struct BP"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::TestRPC_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Testrpc>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("TestRPC"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveOld_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermoveold>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMoveOld"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveNoBase_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovenobase>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMoveNoBase"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualNoBase_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualnobase>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMoveDualNoBase"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDualHybridRootMotion_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualhybridrootmotion>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMoveDualHybridRootMotion"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMoveDual_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedual>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMoveDual"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_StarterProjectCharacter_BP_C::ServerMove_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermove>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMove"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}
