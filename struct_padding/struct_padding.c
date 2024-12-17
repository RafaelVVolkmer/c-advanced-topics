#include <stdio.h>
#include <stdint.h>
#include <errno.h>

typedef struct paddingStruct 
{
    int  element_0;  // 4-bytes
    char element_1;  // 1-byte (var) + 3-bytes (padding)
    int  element_2;  // 4-bytes
} padding_t;

typedef struct __attribute__((packed)) packedStruct
{
    int  element_0;  // 4-bytes
    char element_1;  // 1-byte
    int  element_2;  // 4-bytes
} packed_t;

static int memDumpStruct(const void *data, size_t size);

int main(void) 
{
    padding_t struct_0;
    packed_t  struct_1;

    struct_0.element_0 = 0x11223344;
    struct_0.element_1 = 0x55;
    struct_0.element_2 = 0xAABBCCDD;

    struct_1.element_0 = 0x11223344;
    struct_1.element_1 = 0x55;
    struct_1.element_2 = 0xAABBCCDD;

    printf("=== Padding Struct ===\n");
    printf("struct_0.element_0 = 0x%08X\n", struct_0.element_0);
    printf("struct_0.element_1 = 0x%02X\n", (unsigned char)struct_0.element_1);
    printf("struct_0.element_2 = 0x%08X\n", struct_0.element_2);
    printf("\n");
    
    memDumpStruct(&struct_0, sizeof(struct_0));

    printf("\n=== Packed Struct ===\n");
    printf("struct_1.element_0 = 0x%08X\n", struct_1.element_0);
    printf("struct_1.element_1 = 0x%02X\n", (unsigned char)struct_1.element_1);
    printf("struct_1.element_2 = 0x%08X\n", struct_1.element_2);
    printf("\n");
    
    memDumpStruct(&struct_1, sizeof(struct_1));

    return 0;
}

static int memDumpStruct(const void *data, size_t size)
{
    int ret = 0u;
    
    const unsigned char *bytes = NULL;
    size_t iterator = 0u;
    
    if (data == NULL)
    {
       ret = -ENOMEM;
       goto end_of_function;
    }
    
    bytes = (const unsigned char *)data;

    printf("Memory dump ---\n size = %zu-bytes\nBytes ---------\n", size);
    
    for (iterator = 0u; iterator < size; iterator++) 
    {
        printf("byte[%zu] = 0x%02X\n", iterator, bytes[iterator]);
    }

end_of_function:
    return ret;
}
