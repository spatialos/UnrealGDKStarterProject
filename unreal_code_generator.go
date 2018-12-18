package main;

import (
  "flag"
  "fmt"
  "log"
  "path"
  "os"
  "text/template"
)

var fOutputDir = flag.String("output_dir", ".", "directory to write output to")

const actorClassHeaderTemplate = `
#pragma once

#include "CoreMinimal.h"
#include "{{.ClassName}}.generated.h"

UCLASS()
class A{{.ClassName}} : public AActor
{
  GENERATED_BODY()

public:
  A{{.ClassName}}();

protected:
  virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
  UPROPERTY(VisibleAnywhere)
  class USceneComponent* MyRoot;

public:
  {{range .ReplicatedProperties}}
  UPROPERTY(Replicated)
  {{.Type}} {{.Name}};
  {{end}}

  {{range .Components}}
  UPROPERTY(VisibleAnywhere)
  class U{{.Type}}* {{.Name}};
  {{end}}
};
`

const actorClassImplTemplate = `
#include "{{.ClassName}}.h"

{{range .Components}}
#include "{{.Type}}.h"
{{end}}

#include "Net/UnrealNetwork.h"

A{{.ClassName}}::A{{.ClassName}}()
{
  SetReplicates(true);

  // Set up a root component so this can be placed in the world at a location.
  MyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
  SetRootComponent(MyRoot);

  {{range .Components}}
  {{.Name}} = CreateDefaultSubobject<U{{.Type}}>(TEXT("{{.Name}}"));
  {{end}}
}

void A{{.ClassName}}::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
  Super::GetLifetimeReplicatedProps(OutLifetimeProps);

  {{range .ReplicatedProperties}}
  DOREPLIFETIME(A{{$.ClassName}}, {{.Name}});
  {{end}}
}
`

const componentClassHeaderTemplate = `
#pragma once

#include "CoreMinimal.h"
#include "{{.ClassName}}.generated.h"

UCLASS()
class U{{.ClassName}} : public UActorComponent
{
  GENERATED_BODY()

public:
  U{{.ClassName}}();

protected:
  virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
  {{range .ReplicatedProperties}}
  UPROPERTY(Replicated)
  {{.Type}} {{.Name}};
  {{end}}
};
`

const componentClassImplTemplate = `
#include "{{.ClassName}}.h"

#include "Net/UnrealNetwork.h"

U{{.ClassName}}::U{{.ClassName}}()
{
  SetIsReplicated(true);
}

void U{{.ClassName}}::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
  Super::GetLifetimeReplicatedProps(OutLifetimeProps);

  {{range .ReplicatedProperties}}
  DOREPLIFETIME(U{{$.ClassName}}, {{.Name}});
  {{end}}
}
`

type Property struct {
  Type string
  Name string
}
type ActorData struct {
  ClassName string
  ReplicatedProperties []Property
  Components []Property
}

func WriteTemplateToFile(filename string, templ string, data interface{}) error {
  t := template.Must(template.New("actor").Parse(templ))

  f, err := os.Create(filename)
  if err != nil {
    return err
  }
  defer f.Close()
  return t.Execute(f, data)
}

func GenerateData(data *ActorData) {
  for _, cat := range []struct{
    Prefix string
    Type string
    Count int
  }{
    {
      Prefix: "bBool",
      Type: "bool",
      Count: 50,
    },
    {
      Prefix: "Int",
      Type: "int32",
      Count: 50,
    },
    {
      Prefix: "String",
      Type: "FString",
      Count: 50,
    },
    {
      Prefix: "Vector",
      Type: "FVector",
      Count: 50,
    },
  } {
    arr := &data.ReplicatedProperties
    for i := 0; i < cat.Count; i++ {
      *arr = append(*arr, Property{
        Type: cat.Type,
        Name: fmt.Sprintf("%sProp%d", cat.Prefix, i),
      })
    }
  }
}

func main() {
  flag.Parse()

  data := ActorData{
    ClassName: "DummyActor",
    ReplicatedProperties: nil,
    Components: nil,
  }

  GenerateData(&data)

  for i := 0; i < 10; i++ {
    componentData := ActorData{
      ClassName: fmt.Sprintf("DummyComponent%d", i),
      ReplicatedProperties: nil,
    }

    data.Components = append(data.Components, Property{
      Type: componentData.ClassName,
      Name: "My" + componentData.ClassName,
    })

    GenerateData(&componentData)

    err := WriteTemplateToFile(path.Join(*fOutputDir, componentData.ClassName + ".h"), componentClassHeaderTemplate, componentData)
    if err != nil {
      log.Println(err)
    }
    err = WriteTemplateToFile(path.Join(*fOutputDir, componentData.ClassName + ".cpp"), componentClassImplTemplate, componentData)
    if err != nil {
      log.Println(err)
    }
  }

  // TODO: UStruct with custom NetSerialize

  err := WriteTemplateToFile(path.Join(*fOutputDir, data.ClassName + ".h"), actorClassHeaderTemplate, data)
  if err != nil {
    log.Println(err)
  }
  err = WriteTemplateToFile(path.Join(*fOutputDir, data.ClassName + ".cpp"), actorClassImplTemplate, data)
  if err != nil {
    log.Println(err)
  }
}
