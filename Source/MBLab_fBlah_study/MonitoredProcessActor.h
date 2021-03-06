// © Ajit D'Monte 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Misc/MonitoredProcess.h"

#include "MonitoredProcessActor.generated.h"

UCLASS()
class MBLAB_FBLAH_STUDY_API AMonitoredProcessActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonitoredProcessActor();

	~AMonitoredProcessActor();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "fBlah's Blueprints", meta = (DisplayName = "Create Process", Keywords = "Create Process"))
		bool CreateProcess(const FString& InURL, const FString& InParams, bool InHidden, bool InCreatePipes);

	void OnProcessCompleted(int32 code);

	void OnProcessOutput(const FString Message);

	UFUNCTION(BlueprintImplementableEvent, category = "fBlah's Blueprints")
		void ProcessCompleted(int32 code);

	UFUNCTION(BlueprintImplementableEvent, category = "fBlah's Blueprints")
		void ProcessOutput(const FString &Message);

private:
	FMonitoredProcess * Process = nullptr;
};
