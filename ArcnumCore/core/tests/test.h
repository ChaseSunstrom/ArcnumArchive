#ifndef CORE_TEST_H
#define CORE_TEST_H

#include "../core.h"
#include "../ecs/component/component.h"
#include "../ecs/entity/entity.h"
#include "../ecs/entity/uuid.h"

__A_CORE_TEST__ bool core_unit_test_main(void);

__A_CORE_TEST__ bool test_read_file(void);

__A_CORE_TEST__ bool test_vector_push(void);
__A_CORE_TEST__ bool test_vector_insert(void);
__A_CORE_TEST__ bool test_vector_pop(void);
__A_CORE_TEST__ bool test_vector_remove(void);
__A_CORE_TEST__ bool test_vector_clear(void);
__A_CORE_TEST__ bool test_vector_reverse(void);
__A_CORE_TEST__ bool test_vector_add_capacity(void);
__A_CORE_TEST__ bool test_vector_add_vector(void);
__A_CORE_TEST__ bool test__vector_add_array(void);
__A_CORE_TEST__ bool test_vector_remove_slice(void);
__A_CORE_TEST__ bool test_vector_move_data(void);
__A_CORE_TEST__ bool test_vector_change_data(void);

__A_CORE_TEST__ bool test_map_insert(void);
__A_CORE_TEST__ bool test_map_remove(void);
__A_CORE_TEST__ bool test_map_get(void);

__A_CORE_TEST__ bool test_iterator_next(void);
__A_CORE_TEST__ bool test_iterator_prev(void);
__A_CORE_TEST__ bool test_iterator_iterate(void);
__A_CORE_TEST__ bool test_iterator_b_iterate(void);
__A_CORE_TEST__ bool test_iterator_begin(void);
__A_CORE_TEST__ bool test_iterator_end(void);
__A_CORE_TEST__ bool test_iterator_get_prev(void);
__A_CORE_TEST__ bool test_iterator_get_next(void);
__A_CORE_TEST__ bool test_iterator_get_current_data(void);
__A_CORE_TEST__ bool test_iterator_has_next(void);
__A_CORE_TEST__ bool test_iterator_has_prev(void);
__A_CORE_TEST__ bool test_iterator_reset(void);
__A_CORE_TEST__ bool test_iterator_update(void);

__A_CORE_TEST__ bool test_str_concat(void);
__A_CORE_TEST__ bool test_str_cconcat(void);
__A_CORE_TEST__ bool test_str_replace_c_strs(void);
__A_CORE_TEST__ bool test_str_find_char(void);
__A_CORE_TEST__ bool test_str_find_chars(void);
__A_CORE_TEST__ bool test_str_find_str(void);
__A_CORE_TEST__ bool test_str_find_strs(void);
__A_CORE_TEST__ bool test_str_find_c_str(void);
__A_CORE_TEST__ bool test_str_find_c_strs(void);
__A_CORE_TEST__ bool test_str_remove_char(void);
__A_CORE_TEST__ bool test_str_remove_chars(void);
__A_CORE_TEST__ bool test__str_remove_char(svoid);
__A_CORE_TEST__ bool test__str_remove_chars(void);

__A_CORE_TEST__ bool test_batcher_bind(void);
__A_CORE_TEST__ bool test_batcher_add_entity(void);
__A_CORE_TEST__ bool test_batcher_add_entities(void);

__A_CORE_TEST__ bool test_uuid(void);

__A_CORE_TEST__ bool test_ecs_add_entity(void);
__A_CORE_TEST__ bool test_ecs_remove_entity(void);

__A_CORE_TEST__ bool test_entity_change_vertices(void);
__A_CORE_TEST__ bool test_entity_add_component(void);
__A_CORE_TEST__ bool test_entity_get_component(void);
__A_CORE_TEST__ bool test_entity_has_component(void);
__A_CORE_TEST__ bool test_entity_remove_component(void);

__A_CORE_TEST__ bool test_bump_allocator_alloc(void);
__A_CORE_TEST__ bool test_bump_allocator_free(void);
__A_CORE_TEST__ bool test_bump_allocator_reset(void);

#endif // CORE_TEST_H