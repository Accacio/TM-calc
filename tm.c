#include "tm.h"

int main(int argc, char *argv[]) {
    Player player = {};
    player.NT = 20;

    player.board.production.credits=1;
    player.board.resources.energy=2;

    print_player(player);
    player_produce(&player);
    print_player(player);
    return 0;
}
