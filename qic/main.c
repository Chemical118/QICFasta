#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fseU16.h"

int main() {
    int n = 10000, max = 4095;
    uint16_t *ip = malloc(sizeof(uint16_t) * n);
    uint8_t *op = malloc(sizeof(uint8_t) * n * 2);

    for (int i=0; i<n; i++){
        ip[i] = i % (1 << 12);
    }

    size_t compress = FSE_compressU16(op, 2 * n, ip, n, max, 0);
    printf("Code : %zd\n", compress);

    free(ip);
    free(op);
}