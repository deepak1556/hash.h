#ifndef __HOOK_H__
#define __HOOK_H__

#include <stdlib.h>
#include <uv.h>
#include "async.h"

#define HOOK_MAX_LISTENERS 50
#define HOOK_EVENT_MAX_CALLBACKS 50

typedef void (hook_event_cb)(void *data);

struct hook;

typedef struct {
  long id;
  hook_event_cb *cb;
  int once;
}hook_event_cb_t;

typedef struct hook_event {
  async_env_t *env;
  struct hook *hook;
  char *name;
  void *data;
  int cb_count;
  hook_event_cb_t *cbs[HOOK_EVENT_MAX_CALLBACKS];
}hook_event_t;

typedef struct hook {
  uv_loop_t *loop;
  int event_count;
  hook_event_t *events[HOOK_MAX_EVENTS];
}hook_t;

hook_t*
hook_new(uv_loop_t *loop);

hook_event_cb_t**
hook_listeners(hook_t *hook, char *name);

void
hook_free(hook_t *hook, char *name, void *data);

int
hook_publish(hook_t *hook, char *name, void *data);

#endif
