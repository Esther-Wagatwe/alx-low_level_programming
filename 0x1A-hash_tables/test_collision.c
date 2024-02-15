#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"

void test_collision_scenarios(void)
{
    hash_table_t *ht;
    unsigned long int index;

    ht = hash_table_create(1024);  /* Choose an appropriate size for your hash table */

    /* Test collisions */
    index = key_index((unsigned char *)"hetairas", ht->size);
    printf("Index for 'hetairas': %lu\n", index);

    index = key_index((unsigned char *)"mentioner", ht->size);
    printf("Index for 'mentioner': %lu\n", index);

    index = key_index((unsigned char *)"heliotropes", ht->size);
    printf("heliotropes: %lu\n", index);

    index = key_index((unsigned char *)"neurospora", ht->size);
    printf("neurospora: %lu\n", index);

    index = key_index((unsigned char *)"depravement", ht->size);
    printf("depravement: %lu\n", index);

    index = key_index((unsigned char *)"serafins", ht->size);
    printf("serafins: %lu\n", index);

    index = key_index((unsigned char *)"stylist", ht->size);
    printf("stylist: %lu\n", index);

    index = key_index((unsigned char *)"subgenera", ht->size);
    printf("subgenera: %lu\n", index);

    index = key_index((unsigned char *)"joyful", ht->size);
    printf("joyful: %lu\n", index);

    index = key_index((unsigned char *)"synaphea", ht->size);
    printf("synaphea: %lu\n", index);

    index = key_index((unsigned char *)"redescribed", ht->size);
    printf("redescribed: %lu\n", index);

    index = key_index((unsigned char *)"urites", ht->size);
    printf("urites: %lu\n", index);

    index = key_index((unsigned char *)"dram", ht->size);
    printf("dram: %lu\n", index);

    index = key_index((unsigned char *)"vivency", ht->size);
    printf("vivency: %lu\n", index);

}

int main(void)
{
    test_collision_scenarios();

    return 0;
}
