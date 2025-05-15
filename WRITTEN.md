# Spring 2025 System Programming — Final Project

## Written Portion

### 1. Describe what happens to memory released by the OS with regard to virtual memory

When memory is released by a process, the operating system makes a note that the virtual memory region is free, which will make it available for future allocations.

---

### 2. In a C program, why does `argv[argc]` return `NULL`?

In C, argv[argc] is guaranteed to be NULL by the language specification.

---

### 3. When a system call is made the CPU changes from user mode to kernel mode. Why?

The CPU switches from user mode to kernel mode during a system call to ensure the operating system can safely and securely access hardware resources or manage important functions like file I/O, memory, or process control. 

---

### 4. Explain the relationship between the return value of a system call and the global variable `errno`

System calls return a value that either say success or failure. On success, the return value is  non-negative. On failure, the return value is  -1, and the global variable errno is set to reference the specific error code. 
---

### 5. Consider the following C program. The variables and functions get allocated to which memory segments? Write your answers in comments to the right of each item

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 128

char my_string[MAX];
char class_name[] = "System Programming";
int global_integer = 3;

void print_global() {
  printf("%d\n", global_integer);
}

int square(int x) {
  int result = x * x;

  return result;
}

int main (int argc, char *argv[]) {
  char *dynamic_memory;// local pointer variable
  dynamic_memory = malloc(MAX);//memory allocated dynamically
  free(dynamic_memory);//memory is freed
  dynamic_memory = NULL;//pointer still local to stack

  return 0;
}
```

---

### 6. Explain the difference between `malloc`, `calloc`, `realloc`

The difference between malloc, calloc, and realloc is how they allocate and manage memory. malloc allocates a single block of memory of a specified size but does not initialize the contents, meaning it may contain garbage values. In contrast, calloc not only allocates memory but also initializes all bytes to zero.realloc is used to resize an existing memory block that was previously allocated with malloc or calloc. It preserves the original content up to the minimum of the old and new sizes and may move the memory block to a new location if necessary.

---

### 7. Explain the difference between `brk` and `sbrk`. Why is `malloc` a better option of `brk`, and `sbrk`?

REPLACE THIS CONTENT WITH YOUR ANSWER

---

### 8. Explain why a shadow password file is needed

REPLACE THIS CONTENT WITH YOUR ANSWER

---

### 9. What is the numeric equivalent of the `README.md` file’s permission bits below, and what is the command to give the file full access, across the board?

```sh
-rw-r--r-- 1  johnnythunders  staff  3476 May  1 11:57 README.md
```

REPLACE THIS CONTENT WITH YOUR ANSWER

---

### 10. What does `kill -9 1` do? Explain in detail

REPLACE THIS CONTENT WITH YOUR ANSWER
