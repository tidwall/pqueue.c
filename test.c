#include <assert.h>
#include <stdio.h>
#include "pqueue.h"

int compare(const void *a, const void *b, void *udata) {
    if (*(int*)a < *(int*)b) return -1;
    if (*(int*)a > *(int*)b) return 1;
    return 0;
}

int main() {
    int ints[] = { 5,3,61,7,0,16,2,3,4,6,32,5,3,98,2,27,1,94,54,11,63,20,8 };
    size_t n = sizeof(ints)/sizeof(int);
    struct pqueue *queue = pqueue_new(sizeof(int), compare, NULL);
    assert(queue);
    printf("push: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", ints[i]);
        assert(pqueue_push(queue, &ints[i]));
        assert(pqueue_count(queue) == i+1);
    }
    printf("\n");
    int last;
    printf("pop:  ");
    for (size_t i = 0; i < n; i++) {
        const void *item1 = pqueue_peek(queue);
        assert(item1);
        int x = *(int*)item1;
        const void *item2 = pqueue_pop(queue);
        assert(item1);
        int y = *(int*)item2;
        assert(x == y);
        printf("%d ", x);
        assert(pqueue_count(queue) == n-i-1);
        if (i > 0) {
            assert(i == 0 || x >= last);
        }
        last = x;
    }
    printf("\n");
    assert(pqueue_count(queue) == 0);
    printf("OK\n");
    return 0;
}