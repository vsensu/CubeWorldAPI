// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeWorldAPIFunctionLibrary.h"

#include "Engine/World.h"
//#include "Runtime/PakFile/Public/IPlatformFilePak.h"
//#include "HAL/PlatformFilemanager.h"

//#include "ModActor.h"
//#include "ModGameInstance.h"
#include "ForUE.h"
#include "CppCubeWorldAPIModActor.h"

BlockInfo UCubeWorldAPIFunctionLibrary::GetBlockInfoFromArray(const TArray<FString>& args)
{
    BlockInfo info;
    if (args.Num() == 0)
        return info;

    int i = 0;
    for (; i < args.Num(); ++i)
    {
        std::string key = TCHAR_TO_UTF8(*args[i]);
        if (key == "" && i != 0)
        {
            info.uv_indices[i] = info.uv_indices[i - 1];
        }
        else
        {
            auto result = UCubeWorldAPIFunctionLibrary::GlobalDataActor->img_index_map.find(key);
            if (result != UCubeWorldAPIFunctionLibrary::GlobalDataActor->img_index_map.end())
            {
                info.uv_indices[i] = result->second;
            }
            else
            {
                info.uv_indices[i] = 0;
                UE_LOG(LogTemp, Warning, TEXT("img_index_map has no such key: %s"), *args[i]);
            }
        }
        if (i >= args.Num())
        {
            break;
        }
    }

    for (; i < 6; ++i)
    {
        info.uv_indices[i] = info.uv_indices[i - 1];
    }

    return info;
}

//void UModAPI::RegisterMod(TSubclassOf<AModActor> type)
//{
//    auto *mod_game_instance = (UModGameInstance*)GWorld->GetGameInstance();
//	if(mod_game_instance != nullptr)
//	{
//		mod_game_instance->AddModType(type);
//	}
//}
//
//
//TSet<TSubclassOf<AModActor>> UModAPI::ModTypes()
//{
//	return UModGameInstance::ModTypes;
//}
//
//
//FString UModAPI::GetMountPoint(const FString &PakFilename, bool bSigned)
//{
//	FPakPlatformFile *PakPlatformFile;
//    FString PlatformFileName = FPlatformFileManager::Get().GetPlatformFile().GetName();
//    UE_LOG(LogTemp, Warning, TEXT("Platform File: %s"), *PlatformFileName);
//    if (PlatformFileName.Equals(FString(TEXT("PakFile"))))
//    {
//        PakPlatformFile = static_cast<FPakPlatformFile*>(&FPlatformFileManager::Get().GetPlatformFile());
//    }
//    else
//    {
//        PakPlatformFile = new FPakPlatformFile;
//        if (!PakPlatformFile->Initialize(&FPlatformFileManager::Get().GetPlatformFile(), TEXT("")))
//        {
//            UE_LOG(LogTemp, Error, TEXT("FPakPlatformFile failed to initialize"));
//            return "";
//        }
//        FPlatformFileManager::Get().SetPlatformFile(*PakPlatformFile);
//    }
//
//	FPakFile PakFile(PakPlatformFile, *PakFilename, bSigned);
//    return PakFile.GetMountPoint();
//}


//void UModAPI::RegisterModAPI(FString modKey, AActor *actor)
//{
//    if(ModManagerActor != nullptr)
//        return ModManagerActor->RegisterModAPI(modKey, actor);
//}
//
//
//void UModAPI::CallUserModAPI(FString modKey, FString funcName)
//{
//    if(ModManagerActor != nullptr)
//    {
//        ModManagerActor->CallUserModAPI(modKey, funcName);
//    }
//}
//
//AActor* UModAPI::GetUserModAPIActor(FString modKey)
//{
//    if(ModManagerActor != nullptr)
//        return ModManagerActor->GetUserModAPIActor(modKey);
//    return nullptr;
//}
//
//void UModAPI::AddModActor(AModActor *modActor)
//{
//    if(ModManagerActor != nullptr)
//    {
//        ModManagerActor->AddModActor(modActor);
//    }
//}
//
//void UModAPI::SetupModsInitOrders()
//{
//    if(ModManagerActor != nullptr)
//    {
//        ModManagerActor->SetupModsInitOrders();
//    }
//}
//
//bool UModAPI::InitBefore(FString modKey, FString modKeyBefore)
//{
//    return true;
//}
//
//
//bool UModAPI::InitAfter(FString modKey, FString modKeyAfter)
//{
//    return true;
//}
//
//void UModAPI::InitMods()
//{
//    if(ModManagerActor != nullptr)
//    {
//        ModManagerActor->InitMods();
//    }
//}

//void UCubeWorldAPIFunctionLibrary::InitModAPI(AActor *modActor)
//{
//    if(modActor)
//    {
//        FActorSpawnParameters spawnParams;
//        spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
//        GlobalDataActor = modActor->GetWorld()->SpawnActor<ACppCubeWorldAPIModActor>(ACppCubeWorldAPIModActor::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, spawnParams);
//    }
//}

void UCubeWorldAPIFunctionLibrary::RegisterBlockType(std::string key, const BlockInfo &blockInfo)
{
    if(GlobalDataActor != nullptr)
    {
        GlobalDataActor->block_type_manager[key] = blockInfo;
    }
}

int UCubeWorldAPIFunctionLibrary::RegisterTexture(FString key)
{
    return RegisterTexture(vsensu::ForUE::FStringToStdString(key));
}

int UCubeWorldAPIFunctionLibrary::RegisterTexture(std::string key)
{
    if(nullptr == GlobalDataActor)
        return 0;
    
    int index = GlobalDataActor->img_index_map.size();
    GlobalDataActor->img_index_map[key] = index;
    return index;
}