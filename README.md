# System V IPC Library

This library is used to make the functions used in the System V IPCs libraries more accessible while coding. System V IPC is the name given to three interprocess communication mechanisms that are widely available on UNIX systems: message queues, semaphore, and shared memory.

In folder "lib", you'll find three ".h" and three ".c" files, each for one IPC of the System V IPCs, each of them implements fucntions like "open_queue" for opening message queue that is created before or create a new one, "attach_shmem" for attaching the zero index of the shared memory with a void pointer, "acquire_sem" for acquiring a semaphore at specified index and many other functions you might find useful. There's also one function in the "fork_lib" library which forks and executes a new process with a given executabe name.

To compile the library, you can use the "Makefile" file in the repositary. The Makefile has targets "all" and "clean" to compile and link all libraries together. Below is a summerization:

Compile with "make"
> $make

Run with "./main"
> $./main

Clean with "make clean"
> $make clean

The library is tested in the "test.c" file, you can clone the repositary and test it in the same file with no need to change the Makefile configurations.
