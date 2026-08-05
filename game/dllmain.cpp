// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "../common/WinterCommon.h"

#include <print>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


int proofOfCalling() {
    std::println("Proof that the engine can call the game.");
    return 0x05060708;
}








extern "C"{
    __declspec(dllexport)
    WinterGameHandle __cdecl exchangeFunctions(
        WinterEngineHandle engineHandle
    ){
        if (engineHandle.ProofOfCalling() == 0x01020304) {
            std::println("Game called engine successfully.");
        }
    
        WinterGameHandle hnd = {
            .ProofOfCalling = proofOfCalling
        };
    
        return hnd;
    }
}