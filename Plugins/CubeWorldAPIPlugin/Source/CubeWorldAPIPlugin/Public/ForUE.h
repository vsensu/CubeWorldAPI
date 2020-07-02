#pragma once

#include "CoreMinimal.h"
#include <string>

namespace vsensu
{
	template <typename T>
	constexpr T pi = static_cast<T>(3.1415926535897932384626433832795);

	class ForUE final
	{
	public:
		static FVector scale(const FVector& origin, float scale)
		{
			return origin * scale;
		}

		static FVector MeterToUEUnit(const FVector& origin)
		{
			return scale(origin, 100.f);
		}

		inline static TCHAR* StdStringToTCharString(std::string str) 
		{
			return UTF8_TO_TCHAR(str.c_str());
		}

		inline static std::string TCharStringToStdString(TCHAR *tcharStr)
		{
			return TCHAR_TO_UTF8(tcharStr);
		}

		inline static FString StdStringToFString(std::string str)
		{
			return UTF8_TO_TCHAR(str.c_str());
		}

		inline static std::string FStringToStdString(FString str)
		{
			return TCHAR_TO_UTF8(*str);
		}
	};
}
