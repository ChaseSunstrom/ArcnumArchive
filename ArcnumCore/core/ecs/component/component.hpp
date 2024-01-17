#ifndef CORE_COMPONENT_H
#define CORE_COMPONENT_H

#include "../entity/entity_type.hpp"

#include "shader.hpp"

namespace ac
{
	__A_CORE_API__ class component_array_base
	{
	public:
		virtual ~component_array_base() = default;
		virtual void entity_destroyed(entity entity) = 0;
	};

	template <typename T>
	__A_CORE_API__ class component_array : public component_array_base
	{
	public:
		void insert(entity entity, T component);
		void remove(entity entity);
		void entity_destroyed(entity entity);
		std::vector<T>& get_array();
		T& operator[](entity entity);
	private:
		std::vector<T> m_component_array = std::vector<T>();
	};

	__A_CORE_API__ class component_manager
	{
	public:
		template <typename T>
		void register_component();

		template <typename... components>
		void register_components();

		template <typename T>
		void add_component(entity entity, T component);

		template <typename T>
		void remove_component(entity entity);

		template <typename T>
		T& operator[](entity entity);

		void destroy_component_array(entity entity);

		template <typename T>
		component_array<T>& get_component_array();

		template <typename T>
		bool has_component(entity entity);
	private:
		std::unordered_map<std::type_index, std::unique_ptr<component_array_base>> m_components;
	};

	__A_CORE_API__ struct vertex
	{
		vertex() = default;
		vertex(const glm::vec3& position, const glm::vec3& normal, const glm::vec2& texcoord) : m_position(position), m_normal(normal), m_texcoords(texcoord) {}
		~vertex() = default;

		glm::vec3 m_position = glm::vec3(0);
		glm::vec3 m_normal   = glm::vec3(0);
		glm::vec2 m_texcoords = glm::vec2(0);
	};

	__A_CORE_API__ struct mesh
	{
		mesh();
		mesh(const std::vector<vertex>& vertices, const std::vector<GLuint>& indices);
		~mesh();
		void bind();
		void unbind();
		void update_vertices(const std::vector<vertex>& vertices);
		void update_indices(const std::vector<GLuint>& indices);
		void create_mesh();

		GLuint m_vao = 0;
		GLuint m_vbo = 0;
		GLuint m_ibo = 0;
		std::vector<vertex> m_vertices = std::vector<vertex>();
		std::vector<GLuint> m_indices = std::vector<GLuint>();
		GLsizei m_index_count = 0;
	};

	__A_CORE_API__ struct mesh_component
	{
		mesh_component() = default;
		mesh_component(std::shared_ptr<mesh>& mesh) : m_mesh(std::move(mesh)) {}
		~mesh_component() = default;

		std::shared_ptr<mesh> m_mesh = nullptr;
	};

	__A_CORE_API__ struct material_component
	{
		material_component() = default;
		material_component(const glm::vec4& color, const GLint& texture) : m_color(color) { m_textures.emplace_back(texture); }
		~material_component() = default;

		glm::vec4 m_color = glm::vec4(1);
		std::vector<GLuint> m_textures = std::vector<GLuint>();
	};

	__A_CORE_API__ struct transform_component
	{
		transform_component() = default;
		transform_component(const glm::vec3& position, const glm::dquat& rotation, const glm::vec3& scale) : m_position(position), m_rotation(rotation), m_scale(scale) {}
		~transform_component() = default;

		glm::vec3 m_position  = glm::vec3(0);
		glm::dquat m_rotation = glm::dquat(1.0f, 0.0f, 0.0f, 0.0f);
		glm::vec3 m_scale     = glm::vec3(1);
	};

	__A_CORE_API__ struct render_component
	{

	};

	__A_CORE_API__ class material_manager
	{
	public:
		material_manager() = default;
		void create_material(const std::string& name, const std::shared_ptr<material_component>& material);
		std::shared_ptr<material_component> get_material(const std::string& name);
		void destroy_material(const std::string& name);
	private:
		std::unordered_map<std::string, std::shared_ptr<material_component>> m_materials = std::unordered_map<std::string, std::shared_ptr<material_component>>();
		std::shared_ptr<shader_manager> m_shader_manager = nullptr;
	};
}


#endif // CORE_COMPONENT_H 