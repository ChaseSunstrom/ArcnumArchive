#ifndef CORE_COLOR_HPP
#define CORE_COLOR_HPP

namespace arcnum_core
{
	enum class color_type
	{
		RED,
		GREEN,
		BLUE,
		WHITE,
		BLACK,
		NONE
	};

	struct color
	{
		color() = default;
		color(color_type type);
		color(float r, float g, float b);
		color(float r, float g, float b, float a);
		~color() = default;

		float _r = 0.0f;
		float _g = 0.0f;
		float _b = 0.0f;
		float _a = 1.0f;
	};
}

#endif