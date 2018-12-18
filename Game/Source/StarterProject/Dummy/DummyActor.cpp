
#include "DummyActor.h"


#include "DummyComponent0.h"

#include "DummyComponent1.h"

#include "DummyComponent2.h"

#include "DummyComponent3.h"

#include "DummyComponent4.h"

#include "DummyComponent5.h"

#include "DummyComponent6.h"

#include "DummyComponent7.h"

#include "DummyComponent8.h"

#include "DummyComponent9.h"


#include "Net/UnrealNetwork.h"

ADummyActor::ADummyActor()
{
  SetReplicates(true);

  // Set up a root component so this can be placed in the world at a location.
  MyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
  SetRootComponent(MyRoot);

  
  MyDummyComponent0 = CreateDefaultSubobject<UDummyComponent0>(TEXT("MyDummyComponent0"));
  
  MyDummyComponent1 = CreateDefaultSubobject<UDummyComponent1>(TEXT("MyDummyComponent1"));
  
  MyDummyComponent2 = CreateDefaultSubobject<UDummyComponent2>(TEXT("MyDummyComponent2"));
  
  MyDummyComponent3 = CreateDefaultSubobject<UDummyComponent3>(TEXT("MyDummyComponent3"));
  
  MyDummyComponent4 = CreateDefaultSubobject<UDummyComponent4>(TEXT("MyDummyComponent4"));
  
  MyDummyComponent5 = CreateDefaultSubobject<UDummyComponent5>(TEXT("MyDummyComponent5"));
  
  MyDummyComponent6 = CreateDefaultSubobject<UDummyComponent6>(TEXT("MyDummyComponent6"));
  
  MyDummyComponent7 = CreateDefaultSubobject<UDummyComponent7>(TEXT("MyDummyComponent7"));
  
  MyDummyComponent8 = CreateDefaultSubobject<UDummyComponent8>(TEXT("MyDummyComponent8"));
  
  MyDummyComponent9 = CreateDefaultSubobject<UDummyComponent9>(TEXT("MyDummyComponent9"));
  
}

void ADummyActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
  Super::GetLifetimeReplicatedProps(OutLifetimeProps);

  
  DOREPLIFETIME(ADummyActor, bBoolProp0);
  
  DOREPLIFETIME(ADummyActor, bBoolProp1);
  
  DOREPLIFETIME(ADummyActor, bBoolProp2);
  
  DOREPLIFETIME(ADummyActor, bBoolProp3);
  
  DOREPLIFETIME(ADummyActor, bBoolProp4);
  
  DOREPLIFETIME(ADummyActor, bBoolProp5);
  
  DOREPLIFETIME(ADummyActor, bBoolProp6);
  
  DOREPLIFETIME(ADummyActor, bBoolProp7);
  
  DOREPLIFETIME(ADummyActor, bBoolProp8);
  
  DOREPLIFETIME(ADummyActor, bBoolProp9);
  
  DOREPLIFETIME(ADummyActor, bBoolProp10);
  
  DOREPLIFETIME(ADummyActor, bBoolProp11);
  
  DOREPLIFETIME(ADummyActor, bBoolProp12);
  
  DOREPLIFETIME(ADummyActor, bBoolProp13);
  
  DOREPLIFETIME(ADummyActor, bBoolProp14);
  
  DOREPLIFETIME(ADummyActor, bBoolProp15);
  
  DOREPLIFETIME(ADummyActor, bBoolProp16);
  
  DOREPLIFETIME(ADummyActor, bBoolProp17);
  
  DOREPLIFETIME(ADummyActor, bBoolProp18);
  
  DOREPLIFETIME(ADummyActor, bBoolProp19);
  
  DOREPLIFETIME(ADummyActor, bBoolProp20);
  
  DOREPLIFETIME(ADummyActor, bBoolProp21);
  
  DOREPLIFETIME(ADummyActor, bBoolProp22);
  
  DOREPLIFETIME(ADummyActor, bBoolProp23);
  
  DOREPLIFETIME(ADummyActor, bBoolProp24);
  
  DOREPLIFETIME(ADummyActor, bBoolProp25);
  
  DOREPLIFETIME(ADummyActor, bBoolProp26);
  
  DOREPLIFETIME(ADummyActor, bBoolProp27);
  
  DOREPLIFETIME(ADummyActor, bBoolProp28);
  
  DOREPLIFETIME(ADummyActor, bBoolProp29);
  
  DOREPLIFETIME(ADummyActor, bBoolProp30);
  
  DOREPLIFETIME(ADummyActor, bBoolProp31);
  
  DOREPLIFETIME(ADummyActor, bBoolProp32);
  
  DOREPLIFETIME(ADummyActor, bBoolProp33);
  
  DOREPLIFETIME(ADummyActor, bBoolProp34);
  
  DOREPLIFETIME(ADummyActor, bBoolProp35);
  
  DOREPLIFETIME(ADummyActor, bBoolProp36);
  
  DOREPLIFETIME(ADummyActor, bBoolProp37);
  
  DOREPLIFETIME(ADummyActor, bBoolProp38);
  
  DOREPLIFETIME(ADummyActor, bBoolProp39);
  
  DOREPLIFETIME(ADummyActor, bBoolProp40);
  
  DOREPLIFETIME(ADummyActor, bBoolProp41);
  
  DOREPLIFETIME(ADummyActor, bBoolProp42);
  
  DOREPLIFETIME(ADummyActor, bBoolProp43);
  
  DOREPLIFETIME(ADummyActor, bBoolProp44);
  
  DOREPLIFETIME(ADummyActor, bBoolProp45);
  
  DOREPLIFETIME(ADummyActor, bBoolProp46);
  
  DOREPLIFETIME(ADummyActor, bBoolProp47);
  
  DOREPLIFETIME(ADummyActor, bBoolProp48);
  
  DOREPLIFETIME(ADummyActor, bBoolProp49);
  
  DOREPLIFETIME(ADummyActor, IntProp0);
  
  DOREPLIFETIME(ADummyActor, IntProp1);
  
  DOREPLIFETIME(ADummyActor, IntProp2);
  
  DOREPLIFETIME(ADummyActor, IntProp3);
  
  DOREPLIFETIME(ADummyActor, IntProp4);
  
  DOREPLIFETIME(ADummyActor, IntProp5);
  
  DOREPLIFETIME(ADummyActor, IntProp6);
  
  DOREPLIFETIME(ADummyActor, IntProp7);
  
  DOREPLIFETIME(ADummyActor, IntProp8);
  
  DOREPLIFETIME(ADummyActor, IntProp9);
  
  DOREPLIFETIME(ADummyActor, IntProp10);
  
  DOREPLIFETIME(ADummyActor, IntProp11);
  
  DOREPLIFETIME(ADummyActor, IntProp12);
  
  DOREPLIFETIME(ADummyActor, IntProp13);
  
  DOREPLIFETIME(ADummyActor, IntProp14);
  
  DOREPLIFETIME(ADummyActor, IntProp15);
  
  DOREPLIFETIME(ADummyActor, IntProp16);
  
  DOREPLIFETIME(ADummyActor, IntProp17);
  
  DOREPLIFETIME(ADummyActor, IntProp18);
  
  DOREPLIFETIME(ADummyActor, IntProp19);
  
  DOREPLIFETIME(ADummyActor, IntProp20);
  
  DOREPLIFETIME(ADummyActor, IntProp21);
  
  DOREPLIFETIME(ADummyActor, IntProp22);
  
  DOREPLIFETIME(ADummyActor, IntProp23);
  
  DOREPLIFETIME(ADummyActor, IntProp24);
  
  DOREPLIFETIME(ADummyActor, IntProp25);
  
  DOREPLIFETIME(ADummyActor, IntProp26);
  
  DOREPLIFETIME(ADummyActor, IntProp27);
  
  DOREPLIFETIME(ADummyActor, IntProp28);
  
  DOREPLIFETIME(ADummyActor, IntProp29);
  
  DOREPLIFETIME(ADummyActor, IntProp30);
  
  DOREPLIFETIME(ADummyActor, IntProp31);
  
  DOREPLIFETIME(ADummyActor, IntProp32);
  
  DOREPLIFETIME(ADummyActor, IntProp33);
  
  DOREPLIFETIME(ADummyActor, IntProp34);
  
  DOREPLIFETIME(ADummyActor, IntProp35);
  
  DOREPLIFETIME(ADummyActor, IntProp36);
  
  DOREPLIFETIME(ADummyActor, IntProp37);
  
  DOREPLIFETIME(ADummyActor, IntProp38);
  
  DOREPLIFETIME(ADummyActor, IntProp39);
  
  DOREPLIFETIME(ADummyActor, IntProp40);
  
  DOREPLIFETIME(ADummyActor, IntProp41);
  
  DOREPLIFETIME(ADummyActor, IntProp42);
  
  DOREPLIFETIME(ADummyActor, IntProp43);
  
  DOREPLIFETIME(ADummyActor, IntProp44);
  
  DOREPLIFETIME(ADummyActor, IntProp45);
  
  DOREPLIFETIME(ADummyActor, IntProp46);
  
  DOREPLIFETIME(ADummyActor, IntProp47);
  
  DOREPLIFETIME(ADummyActor, IntProp48);
  
  DOREPLIFETIME(ADummyActor, IntProp49);
  
  DOREPLIFETIME(ADummyActor, StringProp0);
  
  DOREPLIFETIME(ADummyActor, StringProp1);
  
  DOREPLIFETIME(ADummyActor, StringProp2);
  
  DOREPLIFETIME(ADummyActor, StringProp3);
  
  DOREPLIFETIME(ADummyActor, StringProp4);
  
  DOREPLIFETIME(ADummyActor, StringProp5);
  
  DOREPLIFETIME(ADummyActor, StringProp6);
  
  DOREPLIFETIME(ADummyActor, StringProp7);
  
  DOREPLIFETIME(ADummyActor, StringProp8);
  
  DOREPLIFETIME(ADummyActor, StringProp9);
  
  DOREPLIFETIME(ADummyActor, StringProp10);
  
  DOREPLIFETIME(ADummyActor, StringProp11);
  
  DOREPLIFETIME(ADummyActor, StringProp12);
  
  DOREPLIFETIME(ADummyActor, StringProp13);
  
  DOREPLIFETIME(ADummyActor, StringProp14);
  
  DOREPLIFETIME(ADummyActor, StringProp15);
  
  DOREPLIFETIME(ADummyActor, StringProp16);
  
  DOREPLIFETIME(ADummyActor, StringProp17);
  
  DOREPLIFETIME(ADummyActor, StringProp18);
  
  DOREPLIFETIME(ADummyActor, StringProp19);
  
  DOREPLIFETIME(ADummyActor, StringProp20);
  
  DOREPLIFETIME(ADummyActor, StringProp21);
  
  DOREPLIFETIME(ADummyActor, StringProp22);
  
  DOREPLIFETIME(ADummyActor, StringProp23);
  
  DOREPLIFETIME(ADummyActor, StringProp24);
  
  DOREPLIFETIME(ADummyActor, StringProp25);
  
  DOREPLIFETIME(ADummyActor, StringProp26);
  
  DOREPLIFETIME(ADummyActor, StringProp27);
  
  DOREPLIFETIME(ADummyActor, StringProp28);
  
  DOREPLIFETIME(ADummyActor, StringProp29);
  
  DOREPLIFETIME(ADummyActor, StringProp30);
  
  DOREPLIFETIME(ADummyActor, StringProp31);
  
  DOREPLIFETIME(ADummyActor, StringProp32);
  
  DOREPLIFETIME(ADummyActor, StringProp33);
  
  DOREPLIFETIME(ADummyActor, StringProp34);
  
  DOREPLIFETIME(ADummyActor, StringProp35);
  
  DOREPLIFETIME(ADummyActor, StringProp36);
  
  DOREPLIFETIME(ADummyActor, StringProp37);
  
  DOREPLIFETIME(ADummyActor, StringProp38);
  
  DOREPLIFETIME(ADummyActor, StringProp39);
  
  DOREPLIFETIME(ADummyActor, StringProp40);
  
  DOREPLIFETIME(ADummyActor, StringProp41);
  
  DOREPLIFETIME(ADummyActor, StringProp42);
  
  DOREPLIFETIME(ADummyActor, StringProp43);
  
  DOREPLIFETIME(ADummyActor, StringProp44);
  
  DOREPLIFETIME(ADummyActor, StringProp45);
  
  DOREPLIFETIME(ADummyActor, StringProp46);
  
  DOREPLIFETIME(ADummyActor, StringProp47);
  
  DOREPLIFETIME(ADummyActor, StringProp48);
  
  DOREPLIFETIME(ADummyActor, StringProp49);
  
  DOREPLIFETIME(ADummyActor, VectorProp0);
  
  DOREPLIFETIME(ADummyActor, VectorProp1);
  
  DOREPLIFETIME(ADummyActor, VectorProp2);
  
  DOREPLIFETIME(ADummyActor, VectorProp3);
  
  DOREPLIFETIME(ADummyActor, VectorProp4);
  
  DOREPLIFETIME(ADummyActor, VectorProp5);
  
  DOREPLIFETIME(ADummyActor, VectorProp6);
  
  DOREPLIFETIME(ADummyActor, VectorProp7);
  
  DOREPLIFETIME(ADummyActor, VectorProp8);
  
  DOREPLIFETIME(ADummyActor, VectorProp9);
  
  DOREPLIFETIME(ADummyActor, VectorProp10);
  
  DOREPLIFETIME(ADummyActor, VectorProp11);
  
  DOREPLIFETIME(ADummyActor, VectorProp12);
  
  DOREPLIFETIME(ADummyActor, VectorProp13);
  
  DOREPLIFETIME(ADummyActor, VectorProp14);
  
  DOREPLIFETIME(ADummyActor, VectorProp15);
  
  DOREPLIFETIME(ADummyActor, VectorProp16);
  
  DOREPLIFETIME(ADummyActor, VectorProp17);
  
  DOREPLIFETIME(ADummyActor, VectorProp18);
  
  DOREPLIFETIME(ADummyActor, VectorProp19);
  
  DOREPLIFETIME(ADummyActor, VectorProp20);
  
  DOREPLIFETIME(ADummyActor, VectorProp21);
  
  DOREPLIFETIME(ADummyActor, VectorProp22);
  
  DOREPLIFETIME(ADummyActor, VectorProp23);
  
  DOREPLIFETIME(ADummyActor, VectorProp24);
  
  DOREPLIFETIME(ADummyActor, VectorProp25);
  
  DOREPLIFETIME(ADummyActor, VectorProp26);
  
  DOREPLIFETIME(ADummyActor, VectorProp27);
  
  DOREPLIFETIME(ADummyActor, VectorProp28);
  
  DOREPLIFETIME(ADummyActor, VectorProp29);
  
  DOREPLIFETIME(ADummyActor, VectorProp30);
  
  DOREPLIFETIME(ADummyActor, VectorProp31);
  
  DOREPLIFETIME(ADummyActor, VectorProp32);
  
  DOREPLIFETIME(ADummyActor, VectorProp33);
  
  DOREPLIFETIME(ADummyActor, VectorProp34);
  
  DOREPLIFETIME(ADummyActor, VectorProp35);
  
  DOREPLIFETIME(ADummyActor, VectorProp36);
  
  DOREPLIFETIME(ADummyActor, VectorProp37);
  
  DOREPLIFETIME(ADummyActor, VectorProp38);
  
  DOREPLIFETIME(ADummyActor, VectorProp39);
  
  DOREPLIFETIME(ADummyActor, VectorProp40);
  
  DOREPLIFETIME(ADummyActor, VectorProp41);
  
  DOREPLIFETIME(ADummyActor, VectorProp42);
  
  DOREPLIFETIME(ADummyActor, VectorProp43);
  
  DOREPLIFETIME(ADummyActor, VectorProp44);
  
  DOREPLIFETIME(ADummyActor, VectorProp45);
  
  DOREPLIFETIME(ADummyActor, VectorProp46);
  
  DOREPLIFETIME(ADummyActor, VectorProp47);
  
  DOREPLIFETIME(ADummyActor, VectorProp48);
  
  DOREPLIFETIME(ADummyActor, VectorProp49);
  
}
