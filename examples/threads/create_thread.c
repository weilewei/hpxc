//  Copyright (c) 2012-2013 Alexander Duchene
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpxc/threads.h>
#include <stdio.h>
#include <stdlib.h>
#if !defined(_MSC_VER)
#include <unistd.h>
#endif

void* hello_thread(void* p)
{
    int* n = (int*) p;
    int* r;
    printf("hello world=%d\n", *n);
    r = (int*) malloc(sizeof(int));
    *r = 2 * (*n);
    free(p);
    hpxc_thread_exit(r);
    return r;
}

int main(int argc, char* argv[])
{
    hpxc_thread_t thread;
    int* n = (int*) malloc(sizeof(int));
    int* r = NULL;
    *n = 120;
    hpxc_thread_create(&thread, NULL, hello_thread, n);
    hpxc_thread_join(thread, (void**) &r);
    printf("r=%d\n", *r);
    free(n);

    return 0;
}
