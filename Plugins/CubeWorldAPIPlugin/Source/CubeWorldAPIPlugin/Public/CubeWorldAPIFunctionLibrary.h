// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include <string>

//#include "ModManagerActor.h"
#include "BlockInfo.h"

#include "CubeWorldAPIFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class CUBEWORLDAPIPLUGIN_API UCubeWorldAPIFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    static BlockInfo GetBlockInfoFromArray(const TArray<FString>& args);

    //UFUNCTION(BlueprintCallable, Category = "CubeWorldAPI")
    //static void InitModAPI(AActor *modActor);

    ///**
    // * @brief 注册Mod
    // * @param type 要注册的Mod类
    // */
    //UFUNCTION(BlueprintCallable, Category = "Mod API")
    //static void RegisterMod(TSubclassOf<class AModActor> type);

    //UFUNCTION(BlueprintCallable, Category = "Mod API")
    //static TSet<TSubclassOf<AModActor>> ModTypes();

    //UFUNCTION(BlueprintCallable, Category = "Mod API")
    //static FString GetMountPoint(const FString &PakFilename, bool bSigned);

    /**
     * @brief 注册方块类型
     * @param key 方块唯一标识，建议使用 命名空间:类名 的格式，以避免key冲突
     * @param blockInfo 方块类型信息
     */
    static void RegisterBlockType(std::string key, const BlockInfo &blockInfo);
    
    /**
     * @brief 注册纹理
     * @param key 纹理路径，Textures目录下的相对路径
     * @return 
     */
    UFUNCTION(BlueprintCallable, Category = "CubeWorldAPI")
    static int RegisterTexture(FString key);
 
    /**
     * @brief 注册纹理
     * @param key 纹理路径，Textures目录下的相对路径
     * @return 
     */
    static int RegisterTexture(std::string key);

    ///**
    // * @brief 注册自定义的Mod API，暴露给其他Mod使用
    // * @param modKey mod的key，建议为 作者:mod模块名 的格式，以避免冲突
    // * @param actor mod actor
    // */
    //UFUNCTION(BlueprintCallable, Category="Mod API")
    //static void RegisterModAPI(FString modKey, AActor *actor);

    ///**
    // * @brief 调用自定义Mod API 中的接口
    // * @param modKey mod的key
    // * @param funcName 函数名
    // */
    //UFUNCTION(BlueprintCallable, Category="Mod API")
    //static void CallUserModAPI(FString modKey, FString funcName);

    ///**
    // * @brief 获取指定的Mod API actor
    // * @param modKey mod的key
    // * @return Mod API actor
    // */
    //UFUNCTION(BlueprintCallable, Category="Mod API")
    //static AActor* GetUserModAPIActor(FString modKey);

    ///**
    // * @brief 将Mod actor添加到Mod Manager
    // * @param modActor 要添加的Mod
    // */
    //UFUNCTION(BlueprintCallable, Category="Mod API")
    //static void AddModActor(AModActor *modActor);

    ///**
    // * @brief 处理Mod依赖，建立Mod初始化顺序
    // */
    //UFUNCTION(BlueprintCallable, Category="Mod API")
    //static void SetupModsInitOrders();

    ///**
    // * @brief 指定Mod在另一个Mod之前初始化
    // * @param modKey 指定的Mod
    // * @param modKeyBefore 在其之前的Mod
    // * @return 是否成功
    // */
    //UFUNCTION(BlueprintCallable, Category="Mod API")
    //static bool InitBefore(FString modKey, FString modKeyBefore);

    ///**
    // * @brief 指定Mod在另一个Mod之后初始化
    // * @param modKey 指定的Mod
    // * @param modKeyAfter 在其之后的Mod
    // * @return 
    // */
    //UFUNCTION(BlueprintCallable, Category="Mod API")
    //static bool InitAfter(FString modKey, FString modKeyAfter);

    ///**
    // * @brief 初始化所有Mod
    // */
    //UFUNCTION(BlueprintCallable, Category="Mod API")
    //static void InitMods();

    //static inline AModManagerActor *ModManagerActor{nullptr};
    static inline class ACppCubeWorldAPIModActor *GlobalDataActor{nullptr};

};
