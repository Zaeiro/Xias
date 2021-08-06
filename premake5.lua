include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Xias"
	architecture "x86_64"
	startproject "Xias"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
group ""

include "Xias"
