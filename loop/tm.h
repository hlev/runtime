// Tasks
#ifndef _TASK_H
#define _TASK_H

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <stdint.h>
#include <setjmp.h>

typedef struct tm_task
{
  int (*taskfn)(void *);
  void (*taskinterrupt)(void *);
  void *taskdata;
  void *data;
  struct tm *tasknext;
} tm_task_t;

typedef volatile tm_task_t** tm_loop_t;

tm_loop_t tm_default_loop (void);
void tm_run (tm_loop_t queue);
void tm_run_forever (tm_loop_t queue);

// Threadsafe interrupt all
void tm_interruptall (tm_loop_t queue, void (*cb)(void));

void tm_lua_start (tm_loop_t queue, lua_State *L, int ref, int dounref);
void tm_luaparse_start (tm_loop_t queue, lua_State *L, uint8_t *buf, size_t size);

// Colony

typedef struct {
  uint8_t alive;
  int (*userfn)(void *);
  void *userdata;
} tm_idle_t;

typedef struct {
  uint8_t alive;
  void (*timerf)(void *);
  void *userdata;
  double time;
  double repeat;
} tm_timer_t;

typedef struct {
  size_t size;
  uint8_t *buf;
  lua_State *L;
} tm_luaparse_endpoint_t;

typedef struct {
  lua_State *L;
  int ref;
  int dounref;
  jmp_buf jmp;
} tm_lua_endpoint_t;

#endif
