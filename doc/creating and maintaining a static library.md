# creating and maintaining a static library

```bash

cc -g -c libhello.c 
ar r libhello.a libhello.o
rm libhello.o
```

```bash

ar tv libhello.a  

display content in the lib.a archive
```

```bash
ar d libhello.a test.o # delete a named module from archive
```

#### linking

we can link a program against a static library in two ways, the first is to name the static library
```bash
cc -g -c prog.c

cc -g -o prog prog.o libhello.a
```

or we can link by linker

```bash
cc -g -o prog prog.o -lhello
# the linker will search libhello.a from libaray path, we can specify the library path by -L

cc -g -o prog prog.o -Lmylibdir -lhello
```


#### shared library

Shared libraries must be compiled to use position-independent code which has a performance overhead on most architectures because it requires the use of an extra register


creating shared library

```bash
gcc -g -c -fPIC -Wall mod1.c mod2.c mod3.c
gcc -g -shared -o libfoo.so mod1.o mod2.o mod3.o
```

the `cc -fPIC` option specifies that the compiler should generate `position-independent code`. this changes the way that the compiler generates code for operations such as accessing global, static, and external variables;


nm - list symbols from object files

In order to determine whether an existing object file has been compiled with the –fPIC option, we can check for the presence of the name _GLOBAL_OFFSET_TABLE_ in the object file’s symbol table

```bash
nm mod1.o | grep _GLOBAL_OFFSET_TABLE_
readelf -s mod1.o | grep _GLOBAL_OFFSET_TABLE_
```


Conversely, if either of the following equivalent commands yields any output, then the specified shared library includes at least one object module that was not compiled with –fPIC:

```
objdump —all-headers libfoo.so | grep TEXTREL
readelf -d libfoo.so | grep TEXTREL
```


#### soname

```bash
$ gcc -g -c -fPIC -Wall mod1.c mod2.c mod3.c
$ gcc -g -shared -Wl,-soname,libbar.so -o libfoo.so mod1.o mod2.o mod3.o
```

The `–Wl,–soname,libbar.so` option is an instruction to the linker to mark the shared library libfoo.so with the soname libbar.so.

```bash
objdump -p libfoo.so | grep SONAME
readelf -d libfoo.so | greo SONAME
```

When using a soname, one further step is required: we must create a symbolic link from the soname to the real name of the library. This symbolic link must be created in one of the directories searched by the dynamic linker. Thus, we could run our program as follows:


#### proc/pid/maps

To find out which shared libraries a process is currently using, we can list the contents of the corresponding Linux-specific _proc_PID/maps file


#### ldd

list dynamic dependencies

For most ELF executables, ldd will list entries for at least ld-linux.so.2, the dynamic linker, and libc.so.6, the standard C library.

#### objdump readelf


#### nm

The nm command lists the set of symbols defined within an object library or executable program. One use of this command is to find out which of several libraries defines a symbol. For example, to find out which library defines the crypt() function, we could do the following:

```bash
nm -A /usr/lib/lib*.so 2> /dev/null | grep ' crypt$'
```


#### names

The real name employs the format convention `libname.so.major-id.minor-id.`

The soname of the shared library includes the same major version identifier as its corresponding real library name, but excludes the minor version identifier. Thus, the soname has the form libname.so.major-id.

Usually, the soname is created as a relative symbolic link in the directory that contains the real name.

libdemo.so.1        -> libdemo.so.1.0.2
libdemo.so.2        -> libdemo.so.2.0.0


####  the linker name

is used when linking an executable against the shared library.

ry. The linker name is a symbolic link containing just the library name without the major or minor version identifiers,
and thus has the form libname.so. The linker name allows us to construct version-independent link commands that automatically operate with the correct (i.e., most up-to-date) version of the shared library.

 ldconfig program automates the task of keeping sonames up to date, and thus implicitly maintains linker names if we use the convention just described.)

If we want to link a program against an older major version of a shared library, we can’t use the linker name. Instead, as part of the link command, we would need to indicate the required (major) version by specifying a particular real name or soname.


realname   libname.so.maj.min
sonar          libname.so.maj
linker name   libname.so


```bash
gcc -g -c -fPIC -Wall mod1.c mod2.c mod3.c
gcc -g -shared -Wl,-soname,libdemo.so.1 -o libdemo.so.1.0.1 mod1.o mod2.o mod3.o
ln -s libdemo.so.1.0.1 libdemo.so.1
ln -s libdemo.so.1 libdemo.so
```

Then we can build our executable using the linker name 

```bash
gcc -g -Wall -o prog prog.c -L. -ldemo
```

#### install shared library

 More usually, a shared library and its associated symbolic links are installed in one of a number of standard library directories, in particular, one of the following:

```
/usr/lib, the directory in which most standard libraries are installed;
/lib
/usr/local/lib
one of the directories listed in /etc/ld.so.conf
```


#### ldconfig

The ldconfig program solves these problems by performing two tasks:
ldconfig –p displays the current contents of _etc_ld.so.cache.

in order to correctly perform these actions, ldconfig expects libraries to be named according to the conventions described earlier

We should run ldconfig whenever a new library is installed, an existing library is updated or removed, or the list of directories in _etc_ld.so.conf is changed.

install two different major versions of a library. we would do this as follows

```bash

mv libdemo.so.1.0.1 libdemo.so.2.0.0 /usr/lib
ldconfig -v | grep libdemo

cd /usr/lib

ls -l libdemo* | awk '{print $1, $9, $10, $11}'

#We must still create the symbolic link for the linker name, as shown in the next command:
ln -s libdemo.so.2 libdemo.so
```


we can have ldconfig create the soname symbolic link for us by using the –n option.

```bash

gcc -g -c -fPIC -Wall mod1.c mod2.c mod3.c
gcc -g -shared -Wl,-soname,libdemo.so.1 -o libdemo.so.1.0.1 mod1.o mod2.o mod3.o
/sbin/ldconfig -nv .
```

#### upgrading shared libraries

```
gcc -g -c -fPIC -Wall mod1.c mod2.c mod3.c

gcc -g -shared -Wl,-soname,libdemo.so.1 -o libdemo.so.1.0.2 \
	mod1.o mod2.o mod3.o
mv libdemo.so.1.0.2 /usr/lib
ldconfig -v | grep libdemo
```

As can be seen in the above output, ldconfig automatically creates a soname symbolic link for the new major version. However, as the last command shows, we must manually update the linker name symbolic link.


#### There is a third way: during the static editing phase

we can insert into the executable a list of directories that should be searched at run time for shared libraries.
This is useful if we have libraries that reside in fixed locations that are not among the standard locations searched by the dynamic linker. To do this, we employ the `–rpath` linker option when creating an executable:

```bash
gcc -g -Wall -Wl,-rpath,/home/mtk/pdir -o prog prog.c libdemo.so
```

The above command copies the string _home_mtk/pdir into the run-time library path (rpath) list of the executable prog, so, that when the program is run, the dynamic linker will also search this directory when resolving shared library references.

 the –rpath option can be specified multiple times; all of the directories are concatenated into a single ordered rpath list placed in the executable file. Alternatively, multiple directories can be specified as a colon-separated list within a single –rpath option.  


```bash

gcc -g -c -Wall -fPIC modx1.c
gcc -g -shared -o libx1.so modx1.o -Wl,-rpath,/home/mtk/pdir/d2 \
-L/home/mtk/pdir/d2 -lx2
```

Finally, we build the main program, in the pdir directory. Since the main program makes use of libx1.so, and this library resides in a nonstandard directory, we again employ the –rpath linker option:

```bash
gcc -g -Wall -o prog prog.c -Wl,-rpath,/home/mtk/pdir/d1 \
-L/home/mtk/pdir/d1 -lx1
```

Note that we did not need to mention libx2.so when linking the main program. Since the linker is capable of analyzing the rpath list in libx1.so, it can find libx2.so, and thus is able to satisfy the requirement that all symbols can be resolved at static link time.

```bash
objdump -p prog | grep PATH
objdump -p d1/libx1.so | grep PATH
```


#### ELF DT_RPATH and DT_RUNPATH

the difference between DT_RPATH and DT_RUNPATH, DT_RPATH has higher precedence while DT_RUNPATH has lower precendence.

be default, the linker creates the rpath list as a `DT_RPATH` tag, to have the linker instead create the rpath list as a `DT_RUNPATH` entry,  we must use `--enable-new-dtags` linker option

> -Wl,option  

Pass option as an option to the linker. If option contains commas, it is split into multiple options at the commas. You can use this syntax to pass an argument to the option. For example, -Wl,-Map,output.map passes  -Map output.map to the linker. When using the GNU linker, you can also get the same effect with `-Wl,-Map=output.map'.

```bash
gcc -g -Wall -o prog prog.c -Wl,--enable-new-dtags \
-Wl,rpath,/home/mtk/pdir/d1 -L/home/mkt/pdir/d1 -lx1
```

#### Using `$ORIGIN` in rpath

当我们希望将应用打包成zip或者tgz分分发给用户的时候，我们希望用户解压后直接能执行，但是这样没有办法指定so的路径，除非让用户自己指定`LD_LIBRARY_PATH` , 要解决这个问题，就需要用特殊符号 `$ORIGIN`  这个代表了二进制包所在的路径，所以可以这样link

```bash

gcc -Wl,rpath,'$ORIGIN'/lib ....
```


#### search shared library

if `LD_LIBRARY_PATH` is defined, then its value is searched in turn, if executable is a `set-uid` or `sed-gid` ， LD_LIBRARY_PATH is ignored, this is a security measure
if any directories listed in DT_RUNPATH, then these directories are searched

DT_RPATH > LD_LIRBARY_PATH > DT_RUNPATH > _etc_ld.so.cache > _lib && /usr_lib


#### Bsymbolic

加入在我们的so和executatle中有相同的函数，那么默认情况下 executable 中的函数会覆盖so中的，如果我们希望确保so中的函数被调用掉，那就需要用 `-Bsymbolic`

```bash
gcc -g -c -fPIC -Wall foo.c
gcc -g -shared -Wl,-Bsymbolic -o libfoo.so foo.o
gcc -g -o prog prog.c libfoo.so
LD_LIBRARY_PATH=. ./prog
```


#### 静态链接

当我们的lib目录中同时存在 libdemo.so 和 libdemo.a 时, 加入我们希望强制静态编译，有2个手段

1. -l的时候指定.a 文件
2. 用-static 或者 dynamic来选择静态或者动态编译

```bash
-Wl,-Bstatic
-Wl,-Bdynamic
```


#### hidden attribute

the hidden attribute makes the symbol available across all source code files that compose the shared library, but prevents it from being visible outside the library.
Whereas the static keyword limits the visibility of a symbol to a single source code file, 

```c

void
__attribute__((visibility("hidden")))
func(void) {
  /*code*/
}
```