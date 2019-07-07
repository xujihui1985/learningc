#ifndef MYSTRING_H
#define MYSTRING_H

/**
 Best way to declare and define global variables
 The clean, reliable way to declare and define global variables is to use a header file to contain an extern declaration of the variable.
 */
extern const void *String;

struct String {
  const void *class; // must be first
  char *text;
};

void *clone(const void *self);
int differ(const void *self, const void *b);
size_t sizeOf(const void *self);

#endif
