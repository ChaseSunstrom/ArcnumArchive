#ifndef CORE_SCENE_HPP
#define CORE_SCENE_HPP

#include "../ecs/ecs.hpp"
#include "../renderer/renderer.hpp"

#include "../core.hpp"

namespace ac
{
	class scene
	{
	public:
		scene() = default;
		scene(std::shared_ptr<ecs> ecs) : m_ecs(ecs) {}
		~scene() = default;
		std::shared_ptr<ecs> get_ecs() { return m_ecs; }
	private:
		// This is a shared pointer because multiple scenes can share the same ECS
		std::shared_ptr<ecs> m_ecs = std::make_shared<ecs>();
	};

	class scene_manager
	{
	public:
		scene_manager() = default;
		scene_manager(std::shared_ptr<renderer> renderer) : m_renderer(renderer) {}
		~scene_manager() = default;
		void add_scene(std::string name, std::unique_ptr<scene> scene);
		void remove_scene(const std::string& name);
		scene* get_scene(const std::string& name);
		scene* get_current_scene();
		void switch_scene(const std::string& name);
		void update_current_scene(float64_t time_step);
		void render_current_scene();
	private:
		std::unordered_map<std::string, std::unique_ptr<scene>> m_scenes = std::unordered_map<std::string, std::unique_ptr<scene>>();
		scene* m_current_scene = nullptr;
		// This is a shared pointer because multiple scenes can share the same renderer
		std::shared_ptr<renderer> m_renderer = std::make_shared<renderer>();
	};
}

#endif