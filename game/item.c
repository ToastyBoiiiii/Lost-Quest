#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"

item itemList[ITEM_COUNT];

void initItems()
{
    FILE *itemFp = fopen("data/itemList.data", "rb");

    if(itemFp == NULL)
    {
        fprintf(stderr, "[ERROR] Couldn't read item file");
        exit(1);
    }

    fread(itemList, sizeof(item), ITEM_COUNT, itemFp);

    fclose(itemFp);
}

item generateRandomItem()
{
    item randomItem;

    int raritySum = 0;

    for(int i = 0; i < ITEM_COUNT; i++)
    {
        raritySum += itemList[i].item_rarity;
    }

    int randomItemIndex = rand()%raritySum;

    for(int i = 0; i < ITEM_COUNT; i++)
    {
        randomItemIndex -= itemList[i].item_rarity;

        if(randomItemIndex <= 0)
        {
            randomItemIndex = i;
            break;
        }
    }

    strncpy(randomItem.name, itemList[randomItemIndex].name, 20);
    randomItem.item_type = itemList[randomItemIndex].item_type;
    randomItem.item_data[0] = itemList[randomItemIndex].item_data[0];
    randomItem.item_data[1] = itemList[randomItemIndex].item_data[1];
    randomItem.item_data[2] = itemList[randomItemIndex].item_data[2];
    randomItem.item_count = rand()%(itemList[randomItemIndex].max_item_loot_count - itemList[randomItemIndex].min_item_loot_count + 1) + itemList[randomItemIndex].min_item_loot_count;

    return randomItem;
}