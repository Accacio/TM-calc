#ifndef TM_H_
#define TM_H_

#include "stdio.h"

typedef struct board_resources {
    int credits;
    int steel;
    int titanium;
    int plants;
    int energy;
    int heat;
} Board_resources;

void
print_board_resources(Board_resources board_resources)
{
    printf("Credits\t%2.2d\t",board_resources.credits);
    printf("Steel%2.2d\t",board_resources.steel);
    printf("Titanium %2.2d\t",board_resources.titanium);
    printf("Plants\t%2.2d\t",board_resources.plants);
    printf("Energy\t%2.2d\t",board_resources.energy);
    printf("Heat\t%2.2d\n",board_resources.heat);
}

typedef struct Board_production {
    int credits;
    int steel;
    int titanium;
    int plants;
    int energy;
    int heat;
} Board_production;

void
print_board_production(Board_production board_production)
{
    printf("\t%2.2d\t",board_production.credits);
    printf("\t%2.2d\t",board_production.steel);
    printf("\t%2.2d\t",board_production.titanium);
    printf("\t%2.2d\t",board_production.plants);
    printf("\t%2.2d\t",board_production.energy);
    printf("\t%2.2d\n",board_production.heat);
}

typedef struct board
{
    Board_resources resources;
    Board_production production;
} Board;


void update_player_board(int NT,Board* board)
{
    board->resources.heat     += board->resources.energy      ;
    board->resources.energy    = 0                            ;
    board->resources.credits  += NT+board->production.credits ;
    board->resources.titanium += board->production.titanium   ;
    board->resources.plants   += board->production.plants     ;
    board->resources.energy   += board->production.energy     ;
    board->resources.heat     += board->production.heat       ;
}

typedef struct player {
    int NT;
    Board board;
} Player;

void
print_player(Player player)
{
    Board b = player.board;
    printf("NT:\t%2.2d\n",player.NT);
    printf("Credits: %2.2d +(%2.2d) ",b.resources.credits,b.production.credits);
    printf("| Steel:  %2.2d +(%2.2d) ",b.resources.steel,b.production.steel);
    printf("| Titanium: %2.2d +(%2.2d) |\n",b.resources.titanium,b.production.titanium);
    printf("Plants:  %2.2d +(%2.2d) ",b.resources.plants,b.production.plants);
    printf("| Energy: %2.2d +(%2.2d) ",b.resources.energy,b.production.energy);
    printf("| Heat:     %2.2d +(%2.2d) |\n\n",b.resources.heat,b.production.heat);
}

void
player_produce(Player *player)
{
    update_player_board(player->NT, &player->board);
}


#endif // TM_H_
