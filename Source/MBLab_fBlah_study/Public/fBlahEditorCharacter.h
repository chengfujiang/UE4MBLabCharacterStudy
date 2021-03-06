// © Ajit D'Monte 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "fBlahEditorCharacter.generated.h"

UCLASS(BlueprintType, Blueprintable)
class MBLAB_FBLAH_STUDY_API AfBlahEditorCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AfBlahEditorCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual bool ShouldTickIfViewportsOnly() const override { return true; };
	
	
	UFUNCTION(Category = "Character Editor", BlueprintImplementableEvent, meta = (CallInEditor = "true"))
		void EditorTick(float DeltaTime);
		
	UPROPERTY(Category = "Character Editor", EditAnywhere, BlueprintReadWrite)
		bool bEditorTick;

};
