#include "tm.h"
#include "stdio.h"

typedef struct player_board_resources {
    int credits;
    int steel;
    int titanium;
    int plants;
    int energy;
    int heat;
}
Player_board_resources;

void
print_board_resources(Player_board_resources board_resources)
{
    printf("Credits %2.2d ",board_resources.credits);
    printf("Steel %2.2d ",board_resources.steel);
    printf("Titanium %2.2d ",board_resources.titanium);
    printf("Plants %2.2d ",board_resources.plants);
    printf("Energy %2.2d ",board_resources.energy);
    printf("Heat %2.2d\n",board_resources.heat);
}

typedef struct player_board_production {
    int credits;
    int steel;
    int titanium;
    int plants;
    int energy;
    int heat;
}
Player_board_production;

typedef struct player_board
{
    Player_board_resources resources;
    Player_board_production production;
} Player_board;


void update_player_board(int NT,Player_board* board)
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
    Player_board board;
} Player;

void
print_player(Player player)
{
    printf("NT: %2.2d\n",player.NT);
    print_board_resources(player.board.resources);
}

void
player_produce(Player *player)
{
    update_player_board(player->NT, &player->board);
}

int main(int argc, char *argv[]) {
    Player_board_resources board_resources = {};
    Player_board_production board_production = {};
    Player_board player_board = {};
    player_board.production = board_production;
    player_board.resources = board_resources;
    Player player = {};
    player.board = player_board;
    player.NT = 20;

    player.board.production.credits=1;

    print_player(player);
    player_produce(&player);
    print_player(player);
    return 0;
}
