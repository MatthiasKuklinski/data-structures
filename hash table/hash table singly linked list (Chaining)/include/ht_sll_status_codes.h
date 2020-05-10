#pragma once

typedef enum status_code
{
    success = 0,
    ht_sll_ptr_is_null = -1,
    insufficient_heap_mem = -2,
} status_code_t;