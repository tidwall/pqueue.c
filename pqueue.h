// Copyright 2023 Joshua J Baker. All rights reserved.
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file.

#ifndef PQUEUE_H
#define PQUEUE_H

#include <stdbool.h>
#include <stddef.h>

struct pqueue;

// pqueue_new returns a new queue or NULL of out of memory
struct pqueue *pqueue_new(size_t elsize,
    int (*compare)(const void *a, const void *b, void *udata), void *udata);

// pqueue_new_with_allocator is like pqueue_new but allows for custom allocator
struct pqueue *pqueue_new_with_allocator(size_t elsize, void *(*malloc)(size_t), 
    void *(*realloc)(void*,size_t), void (*free)(void*),
    int (*compare)(const void *a, const void *b, void *udata), void *udata);

// pqueue_free frees the queue
void pqueue_free(struct pqueue *queue);

// pqueue_clear clears the queue
void pqueue_clear(struct pqueue *queue);

// pqueue_push inserts an items into the queue. Returns false if out of memory
bool pqueue_push(struct pqueue *queue, const void *item);

// pqueue_count returns the number of items in the queue
size_t pqueue_count(const struct pqueue *queue);

// pqueue_peek returns the minimum item, but does not remove it.
const void *pqueue_peek(const struct pqueue *queue);

// pqueue_pop removes the minimum items and returns it.
const void *pqueue_pop(struct pqueue *queue);

#endif
