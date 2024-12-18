![image](https://github.com/RafaelVVolkmer/c-advanced-topics/blob/main/struct_padding/images/packed.png)

```c
typedef struct paddingStruct 
{
    int  element_0;
    char element_1;
    int  element_2;
} padding_t;

```

```c
typedef struct __attribute__((packed)) packedStruct 
{
    int  element_0;
    char element_1;
    int  element_2;
} packed_t;

```

```c
#pragma pack(push, 1u)

typedef struct pragmaStruct 
{
    int  element_0;
    char element_1;
    int  element_2;
} pragma_t;

#pragma pack(pop)
```
