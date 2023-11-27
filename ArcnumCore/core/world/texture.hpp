
#ifndef CORE_TEXTURE_HPP
#define CORE_TEXTURE_HPP

#include <filesystem>
#include <unordered_map>
#include <memory>

#include <glew.h>
#include <glfw3.h>

#include "texture_type.hpp"

namespace arcnum_core
{
	class texture
	{
	public:
		texture(std::filesystem::path path);
		~texture();
		void load_texture();
		void bind_texture();
	public:
		unsigned char* _image_data;
		int _width                   = 0;
		int _height                  = 0;
		int _nrChannels              = 0;
		GLuint _texture              = 0;
	private:
		std::filesystem::path _texture_path;
	};

	class texture_manager
	{
	public:
		texture_manager();
		~texture_manager() = default;
		void insert(texture_type key, texture* value);
		texture* find(texture_type key);
	private:
		std::unordered_map<texture_type, std::unique_ptr<texture>> _textures;
	};
}

#endif