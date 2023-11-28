#include "color.hpp"

namespace arcnum_core
{
	color::color(float r, float g, float b)
	{
		this->_r = r;
		this->_g = g;
		this->_b = b;
	}

	color::color(float r, float g, float b, float a)
	{
		this->_r = r;
		this->_g = g;
		this->_b = b;
		this->_a = a;
	}

	color::color(color_type type)
	{
		switch (type)
		{
		case color_type::RED:
			_r = 1.0f;
			_g = 0.0f;
			_b = 0.0f;
			break;
		case color_type::GREEN:
			_r = 0.0f;
			_g = 1.0f;
			_b = 0.0f;
			break;
		case color_type::BLUE:
			_r = 0.0f;
			_g = 0.0f;
			_b = 1.0f;
			break;
		case color_type::WHITE:
			_r = 1.0f;
			_g = 1.0f;
			_b = 1.0f;
			break;
		case color_type::BLACK:
			_r = 0.0f;
			_g = 0.0f;
			_b = 0.0f;
			break;
		}
	}
}