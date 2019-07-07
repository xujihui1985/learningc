#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "mystring.h"
#include "class.h"


static void *String_ctor(void *_self, va_list *app)
{
  struct String *self = _self;
  const char *text = va_arg(*app, const char*);

  self->text = malloc(strlen(text) + 1);

  return self;
}

static void *String_dtor(void *_self)
{
  struct String *self = _self;
  free(self->text);
  self->text = NULL;
  return self;
}

static void *String_clone(const void *_self)
{
  const struct String *self = _self;
  return new(String, self->text);
}

static const struct Class _String = {
  .size = sizeof(struct String),
  .ctor = String_ctor,
  .dtor = String_dtor,
  .clone = String_clone,
};

const void *String = &_String;

