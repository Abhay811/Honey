workspace "Honey"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Honey"
	location "Honey"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HONEY_PLATFORM_WINDOWS",
			"HONEY_BUILD_DLL"

		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HONEY_BUILD"
		symbols "On"

	filter "configurations:Release"
		defines "HONEY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HONEY_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Honey/vendor/spdlog/include",
		"Honey/src"
	}

	links 
	{
		"Honey"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HONEY_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "HONEY_BUILD"
		symbols "On"

	filter "configurations:Release"
		defines "HONEY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HONEY_DIST"
		optimize "On"
