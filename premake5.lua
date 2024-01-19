workspace "Arcnum"
    architecture "x64"
   configurations { "Debug", "Release" }

project "Arcnum"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   dependson { "Spark" }

   files { "src/**.cpp", "src/**.hpp" }

   includedirs { "Spark", "Spark/include/**" } -- Adjusted include directory
   libdirs { "Spark/lib/**" }
   links { "Spark", "glfw3", "glew32", "opengl32.lib" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      optimize "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "Full"

project "Spark"
   kind "StaticLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "Spark/core/**.cpp", "Spark/core/**.hpp" }

   includedirs { "Spark/include/**" } -- Adjusted include directory
   libdirs { "Spark/lib/**" }
   links { "glfw3", "glew32", "opengl32.lib"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      optimize "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "Full"