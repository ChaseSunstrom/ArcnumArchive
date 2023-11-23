#include <vector>
#include <filesystem>

#include <glew.h>
#include <glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "texture.hpp"

namespace arcnum_core
{
	texture::texture(std::filesystem::path path)
	{
		this->_texture_path = path;
		this->bind_texture();
		this->load_texture();
	}

	void texture::load_texture()
	{
		unsigned char* image_data = stbi_load(this->_texture_path.string().c_str(), &this->_width, &this->_height, &this->_nrChannels, 0);
	
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->_width, this->_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(image_data);
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
}