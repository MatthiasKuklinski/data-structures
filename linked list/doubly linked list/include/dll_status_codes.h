#pragma once

typedef enum status_code
{
    success = 0,
    dll_node_ptr_is_null = -1,
    insufficient_heap_mem = -2,
    index_out_of_bounds = -3
} status_code_t;