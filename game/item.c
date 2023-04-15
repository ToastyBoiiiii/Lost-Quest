#include <stdlib.h>
#include <string.h>

#include "item.h"

item itemList[ITEM_COUNT];

void initItems()
{
    // Basic Weapons
    strncpy(itemList[0].name, "Violin of Death", 20);
    itemList[0].item_type = MELEE_WEAPON;
    itemList[0].item_data[0] = 35;
    itemList[0].item_data[1] = 65;
    itemList[0].item_rarity = 1;
    itemList[0].min_item_loot_count = 1;
    itemList[0].max_item_loot_count = 1;
    itemList[0].item_cost = 50;

    strncpy(itemList[1].name, "Excalibur", 20);
    itemList[1].item_type = MELEE_WEAPON;
    itemList[1].item_data[0] = 30;
    itemList[1].item_data[1] = 70;
    itemList[1].item_rarity = 3;
    itemList[1].min_item_loot_count = 1;
    itemList[1].max_item_loot_count = 1;
    itemList[1].item_cost = 30;

    strncpy(itemList[2].name, "Sniper Rifle", 20);
    itemList[2].item_type = RANGED_WEAPON;
    itemList[2].item_data[0] = 20;
    itemList[2].item_data[1] = 40;
    itemList[2].item_data[2] = 40;
    itemList[2].item_rarity = 5;
    itemList[2].min_item_loot_count = 1;
    itemList[2].max_item_loot_count = 1;
    itemList[2].item_cost = 25;

    strncpy(itemList[3].name, "Steel Crossfire Bow", 20);
    itemList[3].item_type = RANGED_WEAPON;
    itemList[3].item_data[0] = 35;
    itemList[3].item_data[1] = 65;
    itemList[3].item_data[2] = 10;
    itemList[3].item_rarity = 1;
    itemList[3].min_item_loot_count = 1;
    itemList[3].max_item_loot_count = 1;
    itemList[3].item_cost = 40;

    // Mana Weapons
    strncpy(itemList[4].name, "Holy Blaze", 20);
    itemList[4].item_type = MANA_WEAPON;
    itemList[4].item_data[0] = 20;
    itemList[4].item_data[1] = 80;
    itemList[4].item_data[2] = 10;
    itemList[4].item_rarity = 3;
    itemList[4].min_item_loot_count = 1;
    itemList[4].max_item_loot_count = 1;
    itemList[4].item_cost = 25;

    strncpy(itemList[5].name, "Blessing of Death", 20);
    itemList[5].item_type = MANA_WEAPON;
    itemList[5].item_data[0] = 50;
    itemList[5].item_data[1] = 70;
    itemList[5].item_data[2] = 40;
    itemList[5].item_rarity = 1;
    itemList[5].min_item_loot_count = 1;
    itemList[5].max_item_loot_count = 1;
    itemList[5].item_cost = 80;

    strncpy(itemList[6].name, "Ice Explosion", 20);
    itemList[6].item_type = MANA_WEAPON;
    itemList[6].item_data[0] = 35;
    itemList[6].item_data[1] = 75;
    itemList[6].item_data[2] = 15;
    itemList[6].item_rarity = 3;
    itemList[6].min_item_loot_count = 1;
    itemList[6].max_item_loot_count = 1;
    itemList[6].item_cost = 45;

    // Consumables
    strncpy(itemList[7].name, "Apple", 20);
    itemList[7].item_type = CONSUMALBE;
    itemList[7].item_data[0] = 20;
    itemList[7].item_data[1] = 5;
    itemList[7].item_rarity = 7;
    itemList[7].min_item_loot_count = 8;
    itemList[7].max_item_loot_count = 15;
    itemList[7].item_cost = 5;

    strncpy(itemList[8].name, "Mana Potion", 20);
    itemList[8].item_type = CONSUMALBE;
    itemList[8].item_data[0] = 5;
    itemList[8].item_data[1] = 50;
    itemList[8].item_rarity = 6;
    itemList[8].min_item_loot_count = 3;
    itemList[8].max_item_loot_count = 5;
    itemList[8].item_cost = 8;

    strncpy(itemList[9].name, "God Banana", 20);
    itemList[9].item_type = CONSUMALBE;
    itemList[9].item_data[0] = 50;
    itemList[9].item_data[1] = 50;
    itemList[9].item_rarity = 1;
    itemList[9].min_item_loot_count = 1;
    itemList[9].max_item_loot_count = 5;
    itemList[9].item_cost = 20;

    // Misc
    strncpy(itemList[10].name, "Arrows", 20);
    itemList[10].item_type = MISC;
    itemList[10].item_data[0] = 5;
    itemList[10].item_rarity = 10;
    itemList[10].min_item_loot_count = 3;
    itemList[10].max_item_loot_count = 8;
    itemList[10].item_cost = 1;

    strncpy(itemList[11].name, "Bullets", 20);
    itemList[11].item_type = MISC;
    itemList[11].item_data[0] = 5;
    itemList[11].item_rarity = 8;
    itemList[11].min_item_loot_count = 3;
    itemList[11].max_item_loot_count = 5;
    itemList[11].item_cost = 1;
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