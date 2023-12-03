#ifndef CORE_TEXTURE_TYPE_HPP
#define CORE_TEXTURE_TYPE_HPP

namespace arcnum_core
{
	constexpr size_t hash(const char* str, size_t h = 2166136261ULL)
	{
		return !str[0] ? h : hash(&str[1], (h ^ str[0]) * 16777619U);
	}

	constexpr size_t operator"" _hash(const char* str, size_t)
	{
		return hash(str);
	}

	enum class texture_type
	{
		GRASS = "grass"_hash,
		STONE = "stone"_hash,
		SAND = "sand"_hash,
		NONE = 0,

	};
}

#endif