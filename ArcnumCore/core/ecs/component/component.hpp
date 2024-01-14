#ifndef CORE_COMPONENT_H
#define CORE_COMPONENT_H

#include "../entity/entity_type.hpp"

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
		void entity_destroyed(entity entity);
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
		T& operator[](entity entity);

		void destroy_component_array(entity entity);
	private:
		template <typename T>
		component_array<T>& get_component_array();
	private:
		std::unordered_map<std::type_index, std::unique_ptr<component_array_base>> m_components;
	};
}

/*
__A_CORE_API__ CORE_COMPONENT_FACTORY(component);
__A_CORE_API__ CORE_COMPONENT_FACTORY(mesh_component, vector(float64_t) values; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(transform_component, vec3 position; vec3 rotation; vec3 scale;);
__A_CORE_API__ CORE_COMPONENT_FACTORY(shader_component, GLuint VAO; GLuint VBO; GLuint vertex_shader; GLuint fragment_shader; GLuint shader_program; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(render_component, mesh_component mesh; shader_component shader; transform_component transform; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(texture_component, ubyte* image_data; GLuint texture; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(color_component, color color; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(normal_component);
*/

#endif // CORE_COMPONENT_H 