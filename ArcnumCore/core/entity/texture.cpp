#include <map>
#include <filesystem>
#include <string>

#include <glew.h>
#include <glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "texture.hpp"
#include "entity.hpp"

namespace arcnum_core
{
	texture::texture(std::filesystem::path path)
	{
		this->_texture_path = path;
		this->bind_texture();
		this->load_texture();
	}

	texture::~texture()
	{
		stbi_image_free(this->_image_data);
	}

	void texture::load_texture()
	{
		this->_image_data = stbi_load(this->_texture_path.string().c_str(), &this->_width, &this->_height, &this->_nrChannels, 0);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->_width, this->_height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->_image_data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE3);
	}

	void texture::bind_texture()
	{
		glGenTextures(1, &this->_texture);
		glBindTexture(GL_TEXTURE_2D, this->_texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	void texture_manager::insert(texture_type key, texture* value)
	{
		this->_textures[key] = std::unique_ptr<texture>(value);
	}

	texture_manager::texture_manager()
	{
		for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::absolute("assets/sprites")))
		{
			std::string file_string = entry.path().filename().string();
			std::string file_without_extension = file_string.erase(file_string.find_last_of("."), std::string::npos);

			texture_type type = get_texture_type(file_without_extension);

			this->insert(type, new texture(entry.path()));
		}
	}

	texture* texture_manager::texture_find(texture_type key)
	{
		return &*this->_textures[key];
	}
}