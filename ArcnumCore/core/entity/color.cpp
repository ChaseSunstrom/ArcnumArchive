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
        case color_type::YELLOW:
            _r = 1.0f;
            _g = 1.0f;
            _b = 0.0f;
            break;
        case color_type::CYAN:
            _r = 0.0f;
            _g = 1.0f;
            _b = 1.0f;
            break;
        case color_type::MAGENTA:
            _r = 1.0f;
            _g = 0.0f;
            _b = 1.0f;
            break;
        case color_type::ORANGE:
            _r = 1.0f;
            _g = 0.5f;
            _b = 0.0f;
            break;
        case color_type::PURPLE:
            _r = 0.5f;
            _g = 0.0f;
            _b = 0.5f;
            break;
        case color_type::LIME:
            _r = 0.0f;
            _g = 1.0f;
            _b = 0.5f;
            break;
        case color_type::PINK:
            _r = 1.0f;
            _g = 0.5f;
            _b = 0.5f;
            break;
        case color_type::TEAL:
            _r = 0.0f;
            _g = 0.5f;
            _b = 0.5f;
            break;
        case color_type::BROWN:
            _r = 0.4f;
            _g = 0.2f;
            _b = 0.0f;
            break;
        case color_type::GOLD:
            _r = 1.0f;
            _g = 0.8f;
            _b = 0.0f;
            break;
        case color_type::SILVER:
            _r = 0.75f;
            _g = 0.75f;
            _b = 0.75f;
            break;
        case color_type::GRAY:
            _r = 0.5f;
            _g = 0.5f;
            _b = 0.5f;
            break;
        case color_type::SKY_BLUE:
            _r = 0.53f;
            _g = 0.81f;
            _b = 0.98f;
            break;
        case color_type::INDIGO:
            _r = 0.29f;
            _g = 0.0f;
            _b = 0.51f;
            break;
        case color_type::TURQUOISE:
            _r = 0.25f;
            _g = 0.88f;
            _b = 0.82f;
            break;
        case color_type::CORAL:
            _r = 1.0f;
            _g = 0.5f;
            _b = 0.31f;
            break;
        case color_type::SALMON:
            _r = 0.98f;
            _g = 0.5f;
            _b = 0.45f;
            break;
        case color_type::OLIVE:
            _r = 0.5f;
            _g = 0.5f;
            _b = 0.0f;
            break;
        case color_type::BEIGE:
            _r = 0.96f;
            _g = 0.96f;
            _b = 0.86f;
            break;
        case color_type::MINT_GREEN:
            _r = 0.6f;
            _g = 0.98f;
            _b = 0.6f;
            break;
		}
	}
}