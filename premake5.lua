workspace "Arcnum"
    architecture "x64"
   configurations { "Debug", "Release" }

project "Arcnum"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   dependson { "ArcnumCoreLib" }

   files { "src/**.cpp", "src/**.hpp" }

   includedirs { "ArcnumCore", "ArcnumCore/include/**" } -- Adjusted include directory
   libdirs { "ArcnumCore/lib/**" }
   links { "ArcnumCoreLib", "glfw3", "glew32", "opengl32.lib" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      optimize "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "Full"

project "ArcnumCoreLib"
   kind "StaticLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "ArcnumCore/core/**.cpp", "ArcnumCore/core/**.hpp" }

   includedirs { "ArcnumCore/include/**" } -- Adjusted include directory
   libdirs { "ArcnumCore/lib/**" }
   links { "glfw3", "glew32", "opengl32.lib"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      optimize "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "Full"