#ifndef CORE_ENTITY_TYPE
#define CORE_ENTITY_TYPE

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

	enum class entity_type
	{
		test_brick     = "wall"_hash,
		test_container = "container"_hash,
	};
}

#endif