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

__A_CORE_API__ shader_component shader_component_new(f64_vec vertices, c_str vertex_path, c_str fragment_path)
{
	c_str vertex_source = read_file(vertex_path);
	c_str fragment_source = read_file(fragment_path);

	shader_component shader = { COMPONENT_TYPE_SHADER, 0, 0 };

	shader.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader.vertex_shader, 1, &vertex_source, NULL);
	glCompileShader(shader.vertex_shader);
	shader.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader.fragment_shader, 1, &fragment_source, NULL);
	glCompileShader(shader.fragment_shader);

	shader.shader_program = glCreateProgram();

	glUseProgram(shader.shader_program);

	glGenVertexArrays(1, &shader.VAO);
	glBindVertexArray(shader.VAO);

	glGenBuffers(1, &shader.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, shader.VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices->size, vertices->data, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glAttachShader(shader.shader_program, shader.vertex_shader);
	glAttachShader(shader.shader_program, shader.fragment_shader);

	glLinkProgram(shader.shader_program);

	glDeleteShader(shader.vertex_shader);
	glDeleteShader(shader.fragment_shader);

	return shader;
}

__A_CORE_API__ shader_component _shader_component_new(c_str vertex_path, c_str fragment_path)
{
	c_str vertex_source = read_file(vertex_path);
	c_str fragment_source = read_file(fragment_path);

	shader_component shader = { COMPONENT_TYPE_SHADER, 0, 0 };

	shader.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader.vertex_shader, 1, &vertex_source, NULL);
	glCompileShader(shader.vertex_shader);
	shader.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader.fragment_shader, 1, &fragment_source, NULL);
	glCompileShader(shader.fragment_shader);

	shader.shader_program = glCreateProgram();

	glUseProgram(shader.shader_program);

	glGenVertexArrays(1, &shader.VAO);
	glBindVertexArray(shader.VAO);

	glGenBuffers(1, &shader.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, shader.VBO);
	glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);

	glAttachShader(shader.shader_program, shader.vertex_shader);
	glAttachShader(shader.shader_program, shader.fragment_shader);

	glLinkProgram(shader.shader_program);

	glDeleteShader(shader.vertex_shader);
	glDeleteShader(shader.fragment_shader);

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

__A_CORE_API__ void shader_component_change_shader(shader_component* sc, c_str shader_path, GLint shader_type)
{

	if (shader_type == GL_FRAGMENT_SHADER)
	{
		c_str fragment_source = read_file(shader_path);

		sc->fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(sc->fragment_shader, 1, &fragment_source, NULL);
		glCompileShader(sc->fragment_shader);

		glAttachShader(sc->shader_program, sc->fragment_shader);
		glDeleteShader(sc->fragment_shader);
	}

	else if (shader_type == GL_VERTEX_SHADER)
	{

		c_str vertex_source = read_file(shader_path);

		sc->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(sc->vertex_shader, 1, &vertex_source, NULL);
		glCompileShader(sc->vertex_shader);

		glAttachShader(sc->shader_program, sc->vertex_shader);
		glDeleteShader(sc->vertex_shader);
	}
}


__A_CORE_API__ void mesh_component_change_vertices(mesh_component* mc, f64_vec vertices)
{
	vector_move_data(mc->values, vertices);
}