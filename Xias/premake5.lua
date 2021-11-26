project "Xias"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Xias/src",
		"%{wks.location}/Xias/src/antlr",
		"%{wks.location}/Xias/src/antlrgen"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "X_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "X_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "X_DIST"
		runtime "Release"
		optimize "on"
