#ifndef _KK_ARR_HH_
#define _KK_ARR_HH_

#include <stddef.h> // size_t
#include <string.h> // memset, memmove, memcpy

#ifdef KK_DEBUG
# define KK_ARR_DEBUG

# ifndef KK_ARR_ASSERT
#  ifdef KK_ASSERT
#   define KK_ARR_ASSERT(...) KK_ASSERT(__VA_ARGS__)
#  else
#   include <assert.h>
#   define KK_ARR_ASSERT(...) assert(__VA_ARGS__)
#  endif
# endif
#endif

#ifndef KK_ARR_DEBUG
# define KK_ARR_ASSERT(...) (void)(__VA_ARGS__)
#endif

#if defined(KK_ARR_ALLOC) || defined(KK_ARR_REALLOC) || defined(KK_ARR_FREE)
# if defined(KK_ARR_ALLOC) && defined(KK_ARR_REALLOC) && defined(KK_ARR_FREE)
//
# else 
#  error get me an error message
# endif
#else
# include <stdlib.h>
# define KK_ARR_ALLOC(...)   malloc(__VA_ARGS__)
# define KK_ARR_REALLOC(...) realloc(__VA_ARGS__)
# define KK_ARR_FREE(...)    free(__VA_ARGS__)
#endif

#undef _KK_CAT
#undef KK_CAT
#define _KK_CAT(A,B) A ## B
#define KK_CAT(A,B) _KK_CAT(A,B)

#undef _KK_ARR_NAME
#undef _KK_ARR_PROC
#define _KK_ARR_NAME(T)     KK_CAT(kk_Arr_,T)
#define _KK_ARR_PROC(T,SFX) KK_CAT(_KK_ARR_NAME(T),SFX)

#undef KK_CPP
#ifdef __cplusplus
#define KK_CPP(X) X 
#else
#define KK_CPP(X)
#endif

#undef  kk_Arr
#define kk_Arr(T)              _KK_ARR_NAME(T)

#undef  kk_Arr_init
#define kk_Arr_init(T)         _KK_ARR_PROC(T,_init)
#undef  kk_Arr_init_resize
#define kk_Arr_init_resize(T)  _KK_ARR_PROC(T,_init_resize)
#undef  kk_Arr_cleanup
#define kk_Arr_cleanup(T)      _KK_ARR_PROC(T,_cleanup)
/****/ 
#undef  kk_Arr_resize
#define kk_Arr_resize(T)       _KK_ARR_PROC(T,_resize)
#undef  kk_Arr_reserve
#define kk_Arr_reserve(T)      _KK_ARR_PROC(T,_reserve)
#undef  kk_Arr_size
#define kk_Arr_size(T)         _KK_ARR_PROC(T,_size)
#undef  kk_Arr_at_ptr
#define kk_Arr_at_ptr(T)       _KK_ARR_PROC(T,_at_ptr)
#undef  kk_Arr_at_val
#define kk_Arr_at_val(T)       _KK_ARR_PROC(T,_at_val)
#undef  kk_Arr_at
#define kk_Arr_at(T)           _KK_ARR_PROC(T,_at_ptr)
/****/ 
#undef  kk_Arr_push_empty
#define kk_Arr_push_empty(T)   _KK_ARR_PROC(T,_push_empty)
#undef  kk_Arr_push_ptr
#define kk_Arr_push_ptr(T)     _KK_ARR_PROC(T,_push_ptr)
#undef  kk_Arr_push_val
#define kk_Arr_push_val(T)     _KK_ARR_PROC(T,_push_val)
#undef  kk_Arr_push
#define kk_Arr_push(T)         _KK_ARR_PROC(T,_push_ptr)
/****/ 
#undef  kk_Arr_remove
#define kk_Arr_remove(T)       _KK_ARR_PROC(T,_remove)
#undef  kk_Arr_remove_span
#define kk_Arr_remove_span(T)  _KK_ARR_PROC(T,_remove_span)
#undef  kk_Arr_remove_range
#define kk_Arr_remove_range(T) _KK_ARR_PROC(T,_remove_range)
/****/ 
#undef  kk_Arr_insert_ptr
#define kk_Arr_insert_ptr(T)   _KK_ARR_PROC(T,_insert_ptr)
#undef  kk_Arr_insert_val
#define kk_Arr_insert_val(T)   _KK_ARR_PROC(T,_insert_ptr)
#undef  kk_Arr_insert
#define kk_Arr_insert(T)       _KK_ARR_PROC(T,_insert_ptr)
#undef  kk_Arr_insert_span
#define kk_Arr_insert_span(T)  _KK_ARR_PROC(T,_insert_span)
#undef  kk_Arr_insert_range
#define kk_Arr_insert_range(T) _KK_ARR_PROC(T,_insert_range)
/****/ 
#undef  kk_Arr_pop
#define kk_Arr_pop(T)          _KK_ARR_PROC(T,_pop)
#undef  kk_Arr_zero
#define kk_Arr_zero(T)         _KK_ARR_PROC(T,_zero)
/****/ 
#undef  kk_Arr__grow_cap
#define kk_Arr__grow_cap(T)    _KK_ARR_PROC(T,__grow_cap)
#undef  kk_Arr__shift_in
#define kk_Arr__shift_in(T)    _KK_ARR_PROC(T,__shift_in)
#undef  kk_Arr__shift_out
#define kk_Arr__shift_out(T)   _KK_ARR_PROC(T,__shift_out)
#undef  kk_Arr__zero_range
#define kk_Arr__zero_range(T)  _KK_ARR_PROC(T,__zero_range)

/****/ 
/****/ 

/****/ 
/****/ 

#define KK_ARR_DECL(T)\
\
typedef struct KK_CAT(_KK_ARR_NAME(T),_s) {\
  union { const size_t cnt     KK_CPP(=0);       size_t _cnt; };\
  union { const size_t cap     KK_CPP(=0);       size_t _cap; };\
  union { const T * const data KK_CPP(=nullptr); T *_data; };\
} kk_Arr(T);\
\
int    kk_Arr_init(T)         (kk_Arr(T) *arr, size_t init_cap);\
int    kk_Arr_init_resize(T)  (kk_Arr(T) *arr, size_t init_cnt);\
int    kk_Arr_cleanup(T)      (kk_Arr(T) *arr);\
/****/ \
int    kk_Arr_resize(T)       (kk_Arr(T) *arr, size_t new_cnt);\
int    kk_Arr_reserve(T)      (kk_Arr(T) *arr, size_t new_cap);\
size_t kk_Arr_size(T)         (kk_Arr(T) *arr);\
T *    kk_Arr_at_ptr(T)       (kk_Arr(T) *arr, size_t idx);\
T      kk_Arr_at_val(T)       (kk_Arr(T) *arr, size_t idx);\
/****/ \
size_t kk_Arr_push_empty(T)   (kk_Arr(T) *arr);\
size_t kk_Arr_push_ptr(T)     (kk_Arr(T) *arr, T *ptr);\
size_t kk_Arr_push_val(T)     (kk_Arr(T) *arr, T  val);\
/****/\
void   kk_Arr_remove(T)       (kk_Arr(T) *arr, size_t idx);\
void   kk_Arr_remove_span(T)  (kk_Arr(T) *arr, size_t idx, size_t n);\
void   kk_Arr_remove_range(T) (kk_Arr(T) *arr, size_t b,   size_t e);\
/****/ \
int    kk_Arr_insert_ptr(T)   (kk_Arr(T) *arr, size_t idx, const T *ptr);\
int    kk_Arr_insert_val(T)   (kk_Arr(T) *arr, size_t idx, const T  val);\
int    kk_Arr_insert_span(T)  (kk_Arr(T) *arr, size_t idx, const T * src, size_t n);\
/****/ \
void   kk_Arr_pop(T)          (kk_Arr(T) *arr);\
void   kk_Arr_zero(T)         (kk_Arr(T) *arr);\
/****/ \
size_t kk_Arr__grow_cap(T)    (kk_Arr(T) *arr);\
void   kk_Arr__shift_in(T)    (kk_Arr(T) *arr, size_t idx, size_t n);\
void   kk_Arr__shift_out(T)   (kk_Arr(T) *arr, size_t idx, size_t n);\
void   kk_Arr__zero_range(T)  (kk_Arr(T) *arr, size_t b, size_t e);\
\
KK_CPP\
(\
 template<typename> struct kk_Arr;\
\
 template<> struct kk_Arr<T> : kk_Arr(T) {\
   inline int init(size_t init_cap) {\
     return kk_Arr_init(T) (this, init_cap);\
   }\
   inline int init_resize (size_t init_cnt) {\
     return kk_Arr_init_resize(T) (this, init_cnt);\
   }\
   inline int cleanup() {\
     return kk_Arr_cleanup(T) (this); \
   } \
   /****/ \
   inline int resize (size_t new_cnt) {\
     return kk_Arr_resize(T) (this, new_cnt);\
   }\
   inline int reserve (size_t new_cap) {\
     return kk_Arr_reserve(T) (this, new_cap);\
   }\
   inline size_t size () {\
     return kk_Arr_size(T) (this);\
   }\
   inline T * at_ptr (size_t idx) {\
     return kk_Arr_at_ptr(T) (this, idx);\
   }\
   inline T   at_val (size_t idx) {\
     return kk_Arr_at_val(T) (this, idx);\
   }\
   inline T & at (size_t idx) {\
     return *kk_Arr_at_ptr(T) (this, idx);\
   }\
   /****/ \
   inline size_t push_empty () {\
     return kk_Arr_push_empty(T) (this);\
   }\
   inline size_t push_ptr (T *ptr) {\
     return kk_Arr_push_ptr(T) (this, ptr);\
   }\
   inline size_t push_val (T val) {\
     return kk_Arr_push_val(T) (this, val);\
   }\
   inline size_t push (T &ref) {\
     return kk_Arr_push_ptr(T) (this, &ref);\
   }\
   /****/\
   inline void remove (size_t idx) {\
     kk_Arr_remove(T) (this, idx);\
   }\
   inline void remove_span (size_t idx, size_t n) {\
     kk_Arr_remove_span(T) (this, idx, n);\
   }\
   inline void remove_range (size_t b, size_t e) {\
     kk_Arr_remove_range(T) (this, b, e);\
   }\
   /****/ \
   inline int insert_ptr (size_t idx, const T *ptr) {\
     return kk_Arr_insert_ptr(T) (this, idx, ptr);\
   }\
   inline int insert_val (size_t idx, const T& val) {\
     return kk_Arr_insert_val(T) (this, idx, val);\
   }\
   inline int insert (size_t idx, const T& ref) {\
     return kk_Arr_insert_ptr(T) (this, idx, &ref);\
   }\
   inline int insert_span (size_t idx, const T * src, size_t n) {\
     return kk_Arr_insert_span(T) (this, idx, src, n);\
   }\
   /****/ \
   inline void pop () {\
     kk_Arr_pop(T) (this);  \
   }\
   inline void zero () {\
     kk_Arr_zero(T) (this);\
   }\
 }\
)\

/****/
/****/

#define KK_ARR_DEF(T) \
\
int kk_Arr_init(T) (kk_Arr(T) *arr, size_t init_cap)\
{\
  size_t sz = init_cap * sizeof(T);\
\
  arr->_data = (T*)KK_ARR_ALLOC(sz);\
  if(!arr->_data) { return -1; }\
\
  memset(arr->_data, '\0', sz);/*TODO: debug only*/\
\
  arr->_cnt = 0;\
  arr->_cap = init_cap;\
\
  return 0;\
}\
\
/****/\
\
int kk_Arr_init_resize(T) (kk_Arr(T) *arr, size_t init_cnt)\
{\
  int rc = kk_Arr_init(T)(arr, init_cnt);\
  if( rc ) return rc;\
  \
  rc = kk_Arr_resize(T)(arr, init_cnt);\
  \
  return rc;\
}\
\
/****/\
\
int kk_Arr_cleanup(T) (kk_Arr(T) *arr) {\
  /*KK_ARR_ASSERT( !((bool)arr->_data ^ (bool)arr->_cap) );*/ \
  KK_ARR_FREE((void*)arr->_data);\
  return 0;\
}\
\
/****/\
\
int kk_Arr_resize(T) (kk_Arr(T) *arr, size_t new_cnt) {\
  int rc;\
  if(arr->_cnt < new_cnt) {\
    rc = kk_Arr_reserve(T) (arr, new_cnt);\
    if( rc ) return rc;\
    \
    kk_Arr__zero_range(T) (arr, arr->_cnt, new_cnt);/*TODOdebug only*/  \
    \
    arr->_cnt = new_cnt;\
    \
  } else if(arr->_cnt > new_cnt) {\
    arr->_cnt = new_cnt;\
    \
    if(new_cnt == 0)\
      KK_ARR_FREE(arr->_data);\
  }\
  return rc;\
}\
\
/****/\
\
int kk_Arr_reserve(T) (kk_Arr(T) *arr, size_t new_cap) {\
  if(arr->_cap < new_cap) {\
    size_t new_sz = new_cap * sizeof(T);\
    void *new_mem = KK_ARR_REALLOC((void*)arr->_data, new_sz);\
    if( !new_mem ) return -1;\
    \
    arr->_data = (T*)new_mem;\
    kk_Arr__zero_range(T) (arr, arr->_cap, new_cap); /*TODOdebug only*/ \
    arr->_cap = new_cap;\
  }\
  return 0;\
}\
\
/****/\
\
size_t kk_Arr_size(T) (kk_Arr(T) *arr) {\
  return arr->_cnt * sizeof(T);\
}\
\
/****/\
\
T * kk_Arr_at_ptr(T) (kk_Arr(T) *arr, size_t idx) {\
  KK_ARR_ASSERT(idx < arr->_cnt);\
  return &arr->_data[idx];\
}\
\
/****/\
\
T kk_Arr_at_val(T) (kk_Arr(T) *arr, size_t idx) {\
  KK_ARR_ASSERT(idx < arr->_cnt);\
  return arr->_data[idx];\
}\
\
/****/\
\
size_t kk_Arr_push_empty(T) (kk_Arr(T) *arr) {\
  KK_ARR_ASSERT(arr->_cnt <= arr->_cap);\
  \
  if(arr->_cnt == arr->_cap) {\
    KK_ARR_ASSERT( !kk_Arr_reserve(T)(arr, kk_Arr__grow_cap(T)(arr)) );\
  }\
  return arr->_cnt++;\
}\
\
/****/\
\
size_t kk_Arr_push_ptr(T) (kk_Arr(T) *arr, T *ptr) {\
  size_t idx = kk_Arr_push_empty(T) (arr);\
  memcpy( &arr->_data[idx], ptr, sizeof(T) );\
  return idx;\
}\
\
/****/\
\
size_t kk_Arr_push_val(T) (kk_Arr(T) *arr, T val) {\
  size_t idx = kk_Arr_push_empty(T) (arr);\
  memcpy( &arr->_data[idx], &val, sizeof(T) );\
  return idx;\
}\
\
/****/\
\
void kk_Arr_remove(T) (kk_Arr(T) *arr, size_t idx) {\
  KK_ARR_ASSERT(idx < arr->_cnt);\
\
  kk_Arr__shift_in(T) (arr, idx, 1);\
  arr->_cnt--;\
}\
\
/****/ \
\
void kk_Arr_remove_span(T) (kk_Arr(T) *arr, size_t idx, size_t n) {\
  KK_ARR_ASSERT(idx       <  arr->_cnt);\
  KK_ARR_ASSERT((idx + n) <= arr->_cnt);\
\
  kk_Arr__shift_in(T) (arr, idx, n);\
  arr->_cnt -= n;\
}\
\
/****/ \
\
void kk_Arr_remove_range(T) (kk_Arr(T) *arr, size_t b, size_t e) {\
  KK_ARR_ASSERT(b <= e);\
\
  kk_Arr_remove_span(T) (arr, b, (e - b));\
}\
\
/****/ \
\
int kk_Arr_insert_ptr(T) (kk_Arr(T) *arr, size_t idx, const T* ptr) {\
  KK_ARR_ASSERT(arr->_cnt <= arr->_cap);\
  KK_ARR_ASSERT(idx <= arr->_cnt);\
  \
  if(arr->_cnt == arr->_cap) {\
    int rc = kk_Arr_reserve(T) ( arr, kk_Arr__grow_cap(T) (arr) );\
    if( rc ) return rc;\
  }\
  \
  kk_Arr__shift_out(T) (arr, idx, 1);\
  memcpy(&arr->_data[idx], ptr, sizeof(T));\
  arr->_cnt++;\
  \
  return 0;\
}\
\
/****/\
\
int kk_Arr_insert_val(T) (kk_Arr(T) *arr, size_t idx, const T val) {\
  return kk_Arr_insert_ptr(T) (arr, idx, &val);\
}\
\
/****/\
\
int kk_Arr_insert_span(T) (kk_Arr(T) *arr, size_t idx, const T * src, size_t n) {\
  if( n == 0 ) return 0;\
  \
  KK_ARR_ASSERT(src);\
  KK_ARR_ASSERT(idx <= arr->_cnt);\
  \
  size_t new_cnt = arr->_cnt + n;\
  \
  if(new_cnt > arr->_cap) {\
    size_t new_cap = kk_Arr__grow_cap(T) (arr);\
    if(new_cap < new_cnt) new_cap = new_cnt;\
    \
    int rc = kk_Arr_reserve(T) ( arr, new_cap );\
    if( rc ) return rc;\
  }\
  \
  kk_Arr__shift_out(T) (arr, idx, n);\
  memcpy(&arr->_data[idx], src, n * sizeof(T));\
  arr->_cnt += n;\
  \
  return 0;\
}\
\
/****/\
\
void kk_Arr_pop(T) (kk_Arr(T) *arr) {\
  KK_ARR_ASSERT(arr->_cnt);\
  \
  kk_Arr_remove(T) (arr, arr->_cnt - 1);\
}\
\
/****/\
\
void kk_Arr_zero(T) (kk_Arr(T) *arr) {\
  memset(arr->_data, '\0', kk_Arr_size(T)(arr));\
}\
\
/****/\
\
size_t kk_Arr__grow_cap(T) (kk_Arr(T) * arr) {\
  return (arr->_cnt ? arr->_cnt * 2 : 1);\
}\
\
/****/\
\
void kk_Arr__shift_in(T) (kk_Arr(T) *arr, size_t idx, size_t n) {\
    KK_ARR_ASSERT((idx + n) <= arr->_cnt);\
\
    size_t sz = (arr->_cnt - (idx + n)) * sizeof(T);\
\
    memmove((void*)&arr->_data[idx], (void*)&arr->_data[idx + n], sz);\
}\
\
/****/\
\
void kk_Arr__shift_out(T) (kk_Arr(T) *arr, size_t idx, size_t n) {\
    KK_ARR_ASSERT(idx <= arr->_cnt);\
\
    size_t sz = (arr->_cnt - (idx)) * sizeof(T);\
\
    memmove((void*)&arr->_data[idx + n], (void*)&arr->_data[idx], sz);\
}\
/****/\
\
void kk_Arr__zero_range(T) (kk_Arr(T) *arr, size_t b, size_t e) {\
    memset((void*)&arr->_data[b], '\0', (e - b) * sizeof(T));\
}\

#endif /*_KK_ARR_HH_*/

#ifndef USING_KK_ARR_ALEREADY
#ifdef USING_KK_ARR
#define USING_KK_ARR_ALEREADY

# undef  Arr
# define Arr                 kk_Arr

# undef  Arr_init
# define Arr_init(T)         _KK_ARR_PROC(T,_init)
# undef  Arr_init_resize
# define Arr_init_resize(T)  _KK_ARR_PROC(T,_init_resize)
# undef  Arr_cleanup
# define Arr_cleanup(T)      _KK_ARR_PROC(T,_cleanup)
/****/ 
# undef  Arr_resize
# define Arr_resize(T)       _KK_ARR_PROC(T,_resize)
# undef  Arr_reserve
# define Arr_reserve(T)      _KK_ARR_PROC(T,_reserve)
# undef  Arr_size
# define Arr_size(T)         _KK_ARR_PROC(T,_size)
# undef  Arr_at_ptr
# define Arr_at_ptr(T)       _KK_ARR_PROC(T,_at_ptr)
# undef  Arr_at_val
# define Arr_at_val(T)       _KK_ARR_PROC(T,_at_val)
# undef  Arr_at
# define Arr_at(T)           _KK_ARR_PROC(T,_at_ptr)
/****/ 
# undef  Arr_push_empty
# define Arr_push_empty(T)   _KK_ARR_PROC(T,_push_empty)
# undef  Arr_push_ptr
# define Arr_push_ptr(T)     _KK_ARR_PROC(T,_push_ptr)
# undef  Arr_push_val
# define Arr_push_val(T)     _KK_ARR_PROC(T,_push_val)
# undef  Arr_push
# define Arr_push(T)         _KK_ARR_PROC(T,_push_ptr)
/****/ 
# undef  Arr_remove
# define Arr_remove(T)       _KK_ARR_PROC(T,_remove)
# undef  Arr_remove_span
# define Arr_remove_span(T)  _KK_ARR_PROC(T,_remove_span)
# undef  Arr_remove_range
# define Arr_remove_range(T) _KK_ARR_PROC(T,_remove_range)
/****/ 
# undef  Arr_insert_ptr
# define Arr_insert_ptr(T)   _KK_ARR_PROC(T,_insert_ptr)
# undef  Arr_insert_val
# define Arr_insert_val(T)   _KK_ARR_PROC(T,_insert_ptr)
# undef  Arr_insert
# define Arr_insert(T)       _KK_ARR_PROC(T,_insert_ptr)
# undef  Arr_insert_span
# define Arr_insert_span(T)  _KK_ARR_PROC(T,_insert_span)
# undef  Arr_insert_range
# define Arr_insert_range(T) _KK_ARR_PROC(T,_insert_range)
/****/ 
# undef  Arr_pop
# define Arr_pop(T)          _KK_ARR_PROC(T,_pop)
# undef  Arr_zero
# define Arr_zero(T)         _KK_ARR_PROC(T,_zero)
/****/ 
# undef  Arr__grow_cap
# define Arr__grow_cap(T)    _KK_ARR_PROC(T,__grow_cap)
# undef  Arr__shift_in
# define Arr__shift_in(T)    _KK_ARR_PROC(T,__shift_in)
# undef  Arr__shift_out
# define Arr__shift_out(T)   _KK_ARR_PROC(T,__shift_out)
# undef  Arr__zero_range
# define Arr__zero_range(T)  _KK_ARR_PROC(T,__zero_range)

#endif /*USING_KK_ARR*/

#endif /*USING_KK_ARR_ALEREADY*/

