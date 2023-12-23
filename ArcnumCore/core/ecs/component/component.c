#include "component.h"

#include "../../util/data/vector.h"
#include "../../util/data/file.h"

__A_CORE_API__  mesh_component      mesh_component_default(void)
{
	return (mesh_component) { COMPONENT_TYPE_MESH, vector_default() };
}

__A_CORE_API__  transform_component transform_component_default(void)
{
	return (transform_component) { COMPONENT_TYPE_TRANSFORM, vec3_default(), vec3_default(), vec3_default() };
}

__A_CORE_API__  shader_component	   shader_component_default(void)
{
	return (shader_component) { COMPONENT_TYPE_SHADER, 0, 0, 0, 0, glCreateProgram() };
}

__A_CORE_API__ render_component	   render_component_default(void)
{
	return (render_component) { COMPONENT_TYPE_RENDER, mesh_component_default(), shader_component_default(), transform_component_default() };
}

__A_CORE_API__  texture_component   texture_component_default(void)
{
	return (texture_component) { COMPONENT_TYPE_TEXTURE, NULL, 0 };
}

__A_CORE_API__  color_component	   color_component_default(void)
{
	return (color_component) { COMPONENT_TYPE_COLOR, color_default() };
}

__A_CORE_API__  mesh_component mesh_component_new(f64_vec values)
{
	return (mesh_component) { COMPONENT_TYPE_MESH, values };
}

__A_CORE_API__  transform_component transform_component_new(vec3 position, vec3 rotation, vec3 scale)
{
	return (transform_component) { COMPONENT_TYPE_TRANSFORM, position, rotation, scale };
}

__A_CORE_API__  shader_component shader_component_new(string vertex_path, string fragment_path)
{
	string vertex_source = read_file(vertex_path);
	string fragment_source = read_file(fragment_path);

	shader_component shader = { COMPONENT_TYPE_SHADER, 0, 0 };

	shader.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader.vertex_shader, 1, &vertex_source, NULL);
	glCompileShader(shader.vertex_shader);
	shader.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader.fragment_shader, 1, &fragment_source, NULL);
	glCompileShader(shader.fragment_shader);

	shader.shader_program = glCreateProgram();

	glAttachShader(shader.shader_program, shader.vertex_shader);
	glAttachShader(shader.shader_program, shader.fragment_shader);

	glLinkProgram(shader.shader_program);

	return shader;
}

__A_CORE_API__  render_component render_component_new(mesh_component mesh, shader_component shader, transform_component transform)
{
	return (render_component) { COMPONENT_TYPE_RENDER, mesh, shader, transform };
}

__A_CORE_API__  texture_component texture_component_new(byte* image_data, GLuint texture)
{
	return (texture_component) { COMPONENT_TYPE_TEXTURE, image_data, texture };
}

__A_CORE_API__  color_component	color_component_new(color color)
{
	return (color_component) { COMPONENT_TYPE_COLOR, color };
}

__A_CORE_API__ void color_on_attach(stride_type stride_size)
{
	if (stride_size == 6 || stride_size == 8)
	{
		glVertexAttribPointer(1, 3, GL_DOUBLE, GL_FALSE, stride_size * sizeof(f64), 3 * sizeof(f64));
		glEnableVertexAttribArray(1);
	}

	else if (stride_size == 9 || stride_size == 11)
	{
		glVertexAttribPointer(2, 3, GL_DOUBLE, GL_FALSE, stride_size * sizeof(f64), 6 * sizeof(f64));
		glEnableVertexAttribArray(2);
	}
}

__A_CORE_API__ void texture_on_attach(stride_type stride_size)
{
	if (stride_size == 5)
	{
		glVertexAttribPointer(1, 2, GL_DOUBLE, GL_FALSE, stride_size * sizeof(f64), stride_size - 2 * sizeof(f64));
		glEnableVertexAttribArray(1);
	}
	else if (stride_size == 11)
	{
		glVertexAttribPointer(3, 2, GL_DOUBLE, GL_FALSE, stride_size * sizeof(f64), stride_size - 2 * sizeof(f64));
		glEnableVertexAttribArray(3);
	}
	else
	{
		glVertexAttribPointer(2, 2, GL_DOUBLE, GL_FALSE, stride_size * sizeof(f64), stride_size - 2 * sizeof(f64));
		glEnableVertexAttribArray(2);
	}
}

__A_CORE_API__ void normal_on_attach(stride_type stride_size)
{
	glVertexAttribPointer(1, 3, GL_DOUBLE, GL_FALSE, stride_size * sizeof(f64), 3 * sizeof(f64));
	glEnableVertexAttribArray(1);
}