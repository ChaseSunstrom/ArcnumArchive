#include "scene.hpp"

namespace ac
{
	void scene_manager::add_scene(std::string name, std::unique_ptr<scene> scene)
	{
		m_scenes[name] = std::move(scene);
	}

	void scene_manager::remove_scene(const std::string& name)
	{
		m_scenes.erase(name);
	}

	scene* scene_manager::get_scene(const std::string& name)
	{
		return m_scenes[name].get();
	}

	void scene_manager::switch_scene(const std::string& name)
	{
		m_current_scene = m_scenes[name].get();
	}

	scene* scene_manager::get_current_scene()
	{
		return m_current_scene;
	}

	void scene_manager::update_current_scene(float64_t time_step)
	{

	}

	void scene_manager::render_current_scene()
	{
		component_array<render_component>& render_components = m_current_scene->get_ecs()->get_component_array<render_component>();

		for (auto& render_component : render_components.get_array())
		{

		}
	}
}