#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>
#define auto __auto_type


#define TODO(s) do{\
  assert(false && s);\
}while(0);

#define DUMP_ARRAY(arr,n) for(size_t i = 0;i < n;i++){\
  printf("%p\n",&arr[i]);\
}

typedef struct Pool Pool;

struct Pool{
  Pool* next;
  size_t size;
  size_t capacity;
  uint8_t* p;
};

// [capacity] -> [] -> [] -> [] -> null

Pool pool_init(size_t capacity){
  
  return (Pool){
    .capacity = capacity,
    .size = 0,
    .next = NULL,
    .p = (uint8_t*)malloc(sizeof(uint8_t)*capacity)
  };
}

void* pool_alloc(Pool* pool,size_t a_size){
  
  auto temp = pool;
  while(!(temp->size + a_size <= temp->capacity)){
    if(temp->next == NULL){
      Pool p = pool_init(a_size + pool->capacity);
      memcpy(temp->next,&p,sizeof(Pool));
    }
    temp = temp->next;
  }

  uint8_t* ptr = &temp->p[temp->size];
  temp->size += a_size; 
  return ptr;
}

void pool_free(Pool* pool){
  free(pool->p);
  pool->capacity = 0;
  pool->size = 0;
  auto current = pool->next;
  while(current != NULL){
    auto temp = current->next;
    free(current->p);
    free(current);
    current = temp;
  }
  pool->next = NULL;
}

void pool_reset(Pool* pool){
  auto temp = pool;

  while(temp != NULL){
    temp->size =0;
    temp = temp->next;
  }
}

void* pool_realloc(Pool* pool, size_t old_ptr,size_t new_ptr){
  
  TODO("IMPLEMENTING LATER");
}

void dump_pool(Pool* pool){
  auto temp = pool;

  while(temp != NULL){
    DUMP_ARRAY(temp->p,temp->capacity);
    temp = temp->next;
  }
}

int main(){
  auto a = pool_init(sizeof(int)*2);
  auto b = (int*)pool_alloc(&a,sizeof(int));  
  
  printf("%p\n",b);
  dump_pool(&a);
  pool_free(&a);
  return 0;
}


