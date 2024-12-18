![image](https://github.com/RafaelVVolkmer/c-advanced-topics/blob/main/struct_padding/images/packed.png)

```c
typedef struct paddingStruct 
{
    int  element_0;
    char element_1;
    int  element_2;
} padding_t;

padding_t struct_0 =
{
  .element_0 = 0xAABBCCDD,
  .element_1 = 'A',
  .element_2 = 0xDDCCBBAA
};
```

```c

```
