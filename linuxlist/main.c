#include "list.h"
#include "stdlib.h"

struct component {
    int id;
    struct list_head list_node;
};

struct player {
    int x;
    int y;

    struct list_head list_node;
    struct list_head components;
};

LIST_HEAD(players);


int
main() 
{
    int i;
    struct list_head *pos;
    int count = 0;

    for (i = 0; i < 10; i++) {
        struct player *new_player = (struct player *)malloc(sizeof(struct player));
        new_player->x = i;
        new_player->y = i;
        list_add_tail(&new_player->list_node, &players);
    }

    list_for_each(pos, &players) {
        struct player *p = NULL;

        p = list_entry(pos, struct player, list_node);

        printf("Player %d {%d %d}\n", count, p->x, p->y);
        count++;
    }



}

