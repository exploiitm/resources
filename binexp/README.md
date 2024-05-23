# How to go about

`./basics` contains the basic programs to understand function execution and
how buffer overflows work in principle.

`./canary` contains an example to run canary code and a script to exploit it.

`./compilation` contains information about shared objects, GOT, and PLT.

`backtrace.c` shows you how function stackframes work. In particular, set
breakpoints at each function, each function's `leave`/`pop rbp` instructions
and each function's `ret` instructions and see how the values of `$rbp` and
`$rsp` change and how it affects program execution.

`buffer.c` is very simple in principle. Overflow the buffer to change the
variable value. This will be helpful for you in calculating offsets.

`env_vars.c` shows you how env flags are iterated through.

## Some helpful tips

`gcc -no-pie file.c -o file.out`: sets the code to NOT be position independent
executable. Use this if you want to disable PIE.

`gcc -fno-stack-protector file.c -o file.out`: removes canaries.

`gcc -z execstack file.c -o file.out`: Makes stack executable (shellcodes go
brr).

`gcc -static file.c -o file.out`: Statically link all files (no dynamic
loading).

If you want to disable ASLR, edit the file `/proc/sys/kernel/randomize_va_space`
and set the value to 0. The default is 2, accepted values are 0, 1 and 2.

If you want to attach GDB to a running process, set
`/proc/sys/kernel/yama/ptrace_scope` to 0. Set it back to 1 to enable it. Then
execute the binary and gdb using `./bin & gdb -p $(pidof bin)` where `bin` is
the binary name.
