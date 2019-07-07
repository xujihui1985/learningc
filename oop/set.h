#ifndef SET_H
#define SET_H

extern const void * Set;

struct Set {
  unsigned count;
};

struct Object {
  unsigned count;
  struct Set *in;
};

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

const void *Set = &_Set;
const void *Object = &_Object;

void *add(void *set, const void *element);
void *find(const void *set, const void *element);
void *drop(void *set, const void *element);
int contains(const void *set, const void *element);

#endif // SET_H
