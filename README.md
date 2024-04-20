# Pool Allocator in C

This is a simple pool allocator implementation in C, designed to efficiently manage memory allocations by pre-allocating memory in pools and allocating from these pools when needed.

## Overview

The pool allocator consists of the following components:

- **Pool Structure**: The `Pool` struct represents a memory pool. Each pool contains a fixed-size buffer (`p`), its capacity, the current size, and a pointer to the next pool.

- **Initialization**: The `pool_init` function initializes a pool with a given capacity.

- **Allocation**: The `pool_alloc` function allocates memory from a pool. If the current pool is full, it creates a new pool and continues allocation from there.

- **Deallocation**: The `pool_free` function frees all memory allocated by the pool allocator, including all pools and their buffers.

- **Reset**: The `pool_reset` function resets all pools to their initial state, effectively freeing all memory without deallocating the pools themselves.

- **Reallocation** (TODO): The `pool_realloc` function is a placeholder for future implementation of reallocation functionality.

## Usage

1. Include the necessary headers in your C program:

   ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include <assert.h>
   #include <stdint.h>
   #include <stdbool.h>
   #include <memory.h>
   ```

2. Define the `TODO` macro and other helper macros provided in the code.

3. Use the provided functions to manage memory allocation and deallocation:

   - `pool_init`: Initialize a new pool with a specified capacity.
   - `pool_alloc`: Allocate memory from a pool.
   - `pool_free`: Free all memory allocated by the pool allocator.
   - `pool_reset`: Reset all pools to their initial state.
   - `pool_realloc` (TODO): Reallocate memory within the pool allocator.

4. Example usage:

   ```c
   int main() {
       // Initialize a pool with capacity for two integers
       Pool a = pool_init(sizeof(int) * 2);

       // Allocate an integer from the pool
       int* b = (int*)pool_alloc(&a, sizeof(int));

       // Free all memory allocated by the pool allocator
       pool_free(&a);

       return 0;
   }
   ```