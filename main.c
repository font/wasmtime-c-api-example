#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "handler.h"

extern struct custom_handler_s handler_wasmtime;

void usage(char *prog_name) {
    printf("Usage: %s [WASM_MODULE]\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: expected 1 argument\n");
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    void *handler;
    if (handler_wasmtime.load(&handler)) {
        printf("Could not load libwasmtime.so: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    if (handler_wasmtime.exec_func(handler, argv[1], argv+2)) {
        printf("Could not exec wasm module %s", argv[1]);
        return EXIT_FAILURE;
    }

    if (handler_wasmtime.unload(&handler)) {
        printf("Could not unload libwasmtime.so: %s\n", dlerror());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
