#include "tm.h"
#include "math.h"

typedef struct HEX_TYPE
{
    int q;
    int r;
} Hex;

typedef struct TILE_TYPE
{
    int type;
    int owner;
} Tile;

#define FOR_BLK "\e[0;30m"
#define FOR_RED "\e[0;31m"
#define FOR_GRN "\e[0;32m"
#define FOR_YEL "\e[0;33m"
#define FOR_BLU "\e[0;34m"
#define FOR_MAG "\e[0;35m"
#define FOR_CYN "\e[0;36m"
#define FOR_WHT "\e[0;37m"

#define FOR_GRE "\e[;90m"
#define BAC_GRE "\e[100m"
#define BAC_BLK "\e[40m"
#define BAC_RED "\e[41m"
#define BAC_GRN "\e[42m"
#define BAC_YEL "\e[43m"
#define BAC_BLU "\e[44m"
#define BAC_MAG "\e[45m"
#define BAC_CYN "\e[46m"
#define BAC_WHT "\e[47m"

#define DEFAULT FOR_WHT

#define N 5
#define board_size (2*N-1)

void
print_map(Tile board[board_size*board_size])
{
    /* for (int i = 0; i < board_size; i++) { */
    /*     if ((i>N-1)) { */
    /*         printf("%*s",i-N+1,""); */
    /*     } */
    /*     for (int j = 0; j < board_size; j++) { */
    /*         if ((i+j>=N-1) && (i+j<=(3*(N-1)))) { */
    /*         printf("(%d,%d)",j,i); */
    /*         } */
    /*         printf(" "); */
    /*     } */
    /*     printf("\n"); */
    /* } */
    printf("\n");

    for (int i = 0; i < board_size; i++) {
        if ((i>N-1)) {
            printf("%*s",i-N+1,"");
        }
        for (int j = 0; j < board_size; j++) {
            if ((i+j>=N-1) && (i+j<=(3*(N-1)))) {
                Tile cur_tile=board[i*board_size+j];
                if(cur_tile.type==0){
                    printf(BAC_RED);
                    printf(FOR_RED);
                } else if (cur_tile.type==1) {
                    printf(BAC_BLU);
                } else if (cur_tile.type==2) {
                    printf(BAC_GRN);
                } else if (cur_tile.type==3) {
                    printf(BAC_GRE);
                }


                // printf("%d",board[i*board_size+j].owner); // change foreground color

                printf("%d",cur_tile.type);
                printf(FOR_WHT);
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
};


void
set_hex_map(Tile map[board_size*board_size],Hex coord,int val,int owner)
{
    int i = coord.r+N-1;
    int j = coord.q+N-1;
    map[i*board_size+j].type=val;
    map[i*board_size+j].owner=owner;
}

int main(int argc, char *argv[]) {
    Player player = {};
    player.NT = 20;

    Hex hex = {0,0};
    player.board.production.credits=1;
    player.board.resources.energy=2;

    print_player(player);
    player_produce(&player);
    print_player(player);
    Tile map[board_size*board_size] = {};

    set_hex_map(map, (Hex) {0,0},2,1);
    set_hex_map(map, (Hex) {0,1},1,1);
    set_hex_map(map, (Hex) {1,1},1,1);
    set_hex_map(map, (Hex) {1,0},3,1);
    print_map(map);
    return 0;
}
