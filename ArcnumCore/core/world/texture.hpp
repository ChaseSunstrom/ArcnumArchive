
#ifndef CORE_TEXTURE_HPP
#define CORE_TEXTURE_HPP

#include <filesystem>

#include <glew.h>
#include <glfw3.h>

namespace arcnum_core
{
	class texture
	{
	public:
		texture(std::filesystem::path path);
		void load_texture();
		void bind_texture();
	public:
		GLuint _texture = 0;
	private:
		int _width      = 0;
		int _height     = 0;
		int _nrChannels = 0;
		std::filesystem::path _texture_path;
	};
}

#endif