#ifndef LOSTQUEST_ITEM_H
#define LOSTQUEST_ITEM_H

#define EMPTY -1
#define MELEE_WEAPON 0 // data1: Damage, data2: accuracy
#define RANGED_WEAPON 1 // data1: Damage, data2: accuracy, data3: projectile number
#define MANA_WEAPON 2 // data1: Damage, data2: accuracy, data3: mana cost
#define CONSUMALBE 3 // data1: regenerated health, data2: regenerated mana
#define MISC 4

#define MELEE_WEAPON_STACK_SIZE 1
#define RANGED_WEAPON_STACK_SIZE 1
#define MANA_WEAPON_STACK_SIZE 1
#define CONSUMALBE_STACK_SIZE 50
#define MISC_STACK_SIZE 50

#define ITEM_COUNT 12

typedef struct
{
    char name[20];

    int item_type;
    int item_data[3];
    int item_count;
    int item_rarity;
    int item_cost;

    int min_item_loot_count;
    int max_item_loot_count;
} item;

extern item itemList[ITEM_COUNT];

void initItems();
item generateRandomItem();

#endif //LOSTQUEST_ITEM_H