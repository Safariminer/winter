// USE AS "../common/WinterCommon.h

#pragma once

struct WinterObjectCandidate {
	const char* actorType;
	float x, y, z;
	void* structure;
};

struct WinterConfirmation {
	bool success;
	size_t id;
};

struct WinterActorType {
	void(*Create)(void*);
	void(*Update)(void*);
	void(*Delete)(void*);
};

// what the engine sends to the game dll
struct WinterEngineHandle {
	int(*ProofOfCalling)();
	bool(*PushActorType)(WinterActorType,const char*);
	WinterConfirmation(*PushObjectCandidate)(WinterObjectCandidate*);
};

// what the game dll sends to the engine
struct WinterGameHandle {
	int(*ProofOfCalling)();
};

// the function exchange function is ALWAYS NAMED exchangeFunctions
using FuncExchange = WinterGameHandle(*)(WinterEngineHandle);