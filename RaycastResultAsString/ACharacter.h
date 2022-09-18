#pragma once
// MUST be placed inside main project's Character.h file 
class ACharacter
{
public:
	FHitResult* DoRaycast();

	FHitResult RaycastHit;

	UFUNCTION(BlueprintCallable, Category = "Raycast")
	FString GetRaycastResult();
};
