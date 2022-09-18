#include "ACharacter.h"
// MUST be placed inside main project's Character.cpp file

FHitResult* ACharacter::DoRaycast()
{
	// FHitResult will hold all data returned by our line collision query
	FVector Serega;
	Serega = {0, 0 , 60.0};
	// We set up a line trace from our current location to a point 1000cm ahead of us
	FVector TraceStart = GetActorLocation() + Serega;
	FVector TraceEnd = TraceStart + GetActorForwardVector() * 300.0f;

	// You can use FCollisionQueryParams to further configure the query
	// Here we add ourselves to the ignored list so we won't block the trace
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	// To run the query, you need a pointer to the current level, which you can get from an Actor with GetWorld()
	// UWorld()->LineTraceSingleByChannel runs a line trace and returns the first actor hit over the provided collision channel.
	GetWorld()->LineTraceSingleByChannel(RaycastHit, TraceStart, TraceEnd, TraceChannelProperty, QueryParams);

	// You can use DrawDebug helpers and the log to help visualize and debug your trace queries.
	//DrawDebugLine(GetWorld(), TraceStart, TraceEnd, Hit.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 0, 10.0f);
	UE_LOG(LogTemp, Log, TEXT("Tracing line: %s to %s"), *TraceStart.ToCompactString(), *TraceEnd.ToCompactString());

	// If the trace hit something, bBlockingHit will be true,
	// and its fields will be filled with detailed info about what was hit
	if (RaycastHit.bBlockingHit && IsValid(RaycastHit.GetActor()))
	{
		UE_LOG(LogTemp, Log, TEXT("Trace hit actor: %s"), *RaycastHit.GetActor()->GetName());
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("No Actors were hit"));
	}
	return &RaycastHit;
}

FString ARelictaCharacter::GetRaycastResult()
{
	DoRaycast();
	return *RaycastHit.GetActor()->GetName();
}