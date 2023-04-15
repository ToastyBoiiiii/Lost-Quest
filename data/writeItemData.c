#include <stdio.h>
#include <string.h>

#include "../game/item.h"

int main()
{
    FILE *itemFp = fopen("../data/itemList.data", "wb");
    
    item fileItem;

    // Basic Weapons
    strncpy(fileItem.name, "Violin of Death", 20);
    fileItem.item_type = MELEE_WEAPON;
    fileItem.item_data[0] = 35;
    fileItem.item_data[1] = 65;
    fileItem.item_rarity = 1;
    fileItem.min_item_loot_count = 1;
    fileItem.max_item_loot_count = 1;
    fileItem.item_cost = 50;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    strncpy(fileItem.name, "Excalibur", 20);
    fileItem.item_type = MELEE_WEAPON;
    fileItem.item_data[0] = 30;
    fileItem.item_data[1] = 70;
    fileItem.item_rarity = 3;
    fileItem.min_item_loot_count = 1;
    fileItem.max_item_loot_count = 1;
    fileItem.item_cost = 30;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    strncpy(fileItem.name, "Sniper Rifle", 20);
    fileItem.item_type = RANGED_WEAPON;
    fileItem.item_data[0] = 20;
    fileItem.item_data[1] = 40;
    fileItem.item_data[2] = 40;
    fileItem.item_rarity = 5;
    fileItem.min_item_loot_count = 1;
    fileItem.max_item_loot_count = 1;
    fileItem.item_cost = 25;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    strncpy(fileItem.name, "Steel Crossfire Bow", 20);
    fileItem.item_type = RANGED_WEAPON;
    fileItem.item_data[0] = 35;
    fileItem.item_data[1] = 65;
    fileItem.item_data[2] = 10;
    fileItem.item_rarity = 1;
    fileItem.min_item_loot_count = 1;
    fileItem.max_item_loot_count = 1;
    fileItem.item_cost = 40;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    // Mana Weapons
    strncpy(fileItem.name, "Holy Blaze", 20);
    fileItem.item_type = MANA_WEAPON;
    fileItem.item_data[0] = 20;
    fileItem.item_data[1] = 80;
    fileItem.item_data[2] = 10;
    fileItem.item_rarity = 3;
    fileItem.min_item_loot_count = 1;
    fileItem.max_item_loot_count = 1;
    fileItem.item_cost = 25;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    strncpy(fileItem.name, "Blessing of Death", 20);
    fileItem.item_type = MANA_WEAPON;
    fileItem.item_data[0] = 50;
    fileItem.item_data[1] = 70;
    fileItem.item_data[2] = 40;
    fileItem.item_rarity = 1;
    fileItem.min_item_loot_count = 1;
    fileItem.max_item_loot_count = 1;
    fileItem.item_cost = 80;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    strncpy(fileItem.name, "Ice Explosion", 20);
    fileItem.item_type = MANA_WEAPON;
    fileItem.item_data[0] = 35;
    fileItem.item_data[1] = 75;
    fileItem.item_data[2] = 15;
    fileItem.item_rarity = 3;
    fileItem.min_item_loot_count = 1;
    fileItem.max_item_loot_count = 1;
    fileItem.item_cost = 45;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    // Consumables
    strncpy(fileItem.name, "Apple", 20);
    fileItem.item_type = CONSUMALBE;
    fileItem.item_data[0] = 20;
    fileItem.item_data[1] = 5;
    fileItem.item_rarity = 7;
    fileItem.min_item_loot_count = 8;
    fileItem.max_item_loot_count = 15;
    fileItem.item_cost = 5;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    strncpy(fileItem.name, "Mana Potion", 20);
    fileItem.item_type = CONSUMALBE;
    fileItem.item_data[0] = 5;
    fileItem.item_data[1] = 50;
    fileItem.item_rarity = 6;
    fileItem.min_item_loot_count = 3;
    fileItem.max_item_loot_count = 5;
    fileItem.item_cost = 8;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    strncpy(fileItem.name, "God Banana", 20);
    fileItem.item_type = CONSUMALBE;
    fileItem.item_data[0] = 50;
    fileItem.item_data[1] = 50;
    fileItem.item_rarity = 1;
    fileItem.min_item_loot_count = 1;
    fileItem.max_item_loot_count = 5;
    fileItem.item_cost = 20;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    // Misc
    strncpy(fileItem.name, "Arrows", 20);
    fileItem.item_type = MISC;
    fileItem.item_data[0] = 5;
    fileItem.item_rarity = 10;
    fileItem.min_item_loot_count = 3;
    fileItem.max_item_loot_count = 8;
    fileItem.item_cost = 1;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    strncpy(fileItem.name, "Bullets", 20);
    fileItem.item_type = MISC;
    fileItem.item_data[0] = 5;
    fileItem.item_rarity = 8;
    fileItem.min_item_loot_count = 3;
    fileItem.max_item_loot_count = 5;
    fileItem.item_cost = 1;
    fwrite(&fileItem, sizeof(item), 1, itemFp);

    fclose(itemFp);
    
    return 0;
}