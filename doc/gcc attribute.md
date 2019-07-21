# gcc attribute

### hidden attribute

the hidden attribute makes the symbol available across all source code files that compose the shared library, but prevents it from being visible outside the library.
Whereas the static keyword limits the visibility of a symbol to a single source code file, 

```c

void
__attribute__((visibility("hidden")))
func(void) {
  /*code*/
}
```

### constructor and destructor attribute

```c
void
__attribute__((constructor)) function_name(void)
{
  // initialization code
}

void __attribute__((destructor)) some_name_unload(void)
{
  // finalization code
}
```