#pragma once

typedef enum status
{
    success = 0,
    stk_ary_ptr_is_null = -1,
    insufficient_heap_mem = -2,
    stk_ary_full = -3,
    stk_ary_empty = -4
} status_t;