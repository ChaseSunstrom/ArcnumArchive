workspace "Arcnum"
   configurations { "Debug", "Release" }

project "Arcnum"
   kind "ConsoleApp"
   language "C"
   targetdir "bin/%{cfg.buildcfg}"

   dependson { "ArcnumCoreLib" }

   files { "src/**.c", "src/**.h" }

   includedirs { "ArcnumCore/", "ArcnumCore/include/" } -- Adjusted include directory
   libdirs { "ArcnumCore/lib/" }
   links { "ArcnumCoreLib" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

project "ArcnumCoreLib"
   kind "StaticLib"
   language "C"
   targetdir "bin/%{cfg.buildcfg}"

   files { "ArcnumCore/core/**.c", "ArcnumCore/core/**.h" }

   includedirs { "ArcnumCore/include/GLEW", "ArcnumCore/include/GLFW" } -- Adjusted include directory
   libdirs { "ArcnumCore/lib/GLEW", "ArcnumCore/lib/GLFW" }
   links { "glfw3.lib", "glew32.lib"}