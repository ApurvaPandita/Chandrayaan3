#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
    char direction;
} Spacecraft;

void move_forward(Spacecraft *craft) {
    switch (craft->direction) {
        case 'N':
            craft->y++;
            break;
        case 'S':
            craft->y--;
            break;
        case 'E':
            craft->x++;
            break;
        case 'W':
            craft->x--;
            break;
        case 'U':
            craft->z++;
            break;
        case 'D':
            craft->z--;
            break;
    }
}

void move_backward(Spacecraft *craft) {
    switch (craft->direction) {
        case 'N':
            craft->y--;
            break;
        case 'S':
            craft->y++;
            break;
        case 'E':
            craft->x--;
            break;
        case 'W':
            craft->x++;
            break;
        case 'U':
            craft->z--;
            break;
        case 'D':
            craft->z++;
            break;
    }
}

void turn_left(Spacecraft *craft) {
    switch (craft->direction) {
        case 'N':
            craft->direction = 'W';
            break;
        case 'S':
            craft->direction = 'E';
            break;
        case 'E':
            craft->direction = 'N';
            break;
        case 'W':
            craft->direction = 'S';
            break;
    }
}

void turn_right(Spacecraft *craft) {
    switch (craft->direction) {
        case 'N':
            craft->direction = 'E';
            break;
        case 'S':
            craft->direction = 'W';
            break;
        case 'E':
            craft->direction = 'S';
            break;
        case 'W':
            craft->direction = 'N';
            break;
    }
}

void turn_up(Spacecraft *craft) {
    if (craft->direction == 'N' || craft->direction == 'S') {
        craft->direction = 'U';
    }
}

void turn_down(Spacecraft *craft) {
    if (craft->direction == 'N' || craft->direction == 'S') {
        craft->direction = 'D';
    }
}

void execute_commands(Spacecraft *craft, const char *commands) {
    for (int i = 0; commands[i] != '\0'; i++) {
        switch (commands[i]) {
            case 'f':
                move_forward(craft);
                break;
            case 'b':
                move_backward(craft);
                break;
            case 'l':
                turn_left(craft);
                break;
            case 'r':
                turn_right(craft);
                break;
            case 'u':
                turn_up(craft);
                break;
            case 'd':
                turn_down(craft);
                break;
        }
    }
}

int main() {
    Spacecraft spacecraft = {0, 0, 0, 'N'};
    const char *commands = "frubl";

    execute_commands(&spacecraft, commands);

    printf("Final Position: (%d, %d, %d)\n", spacecraft.x, spacecraft.y, spacecraft.z);
    printf("Final Direction: %c\n", spacecraft.direction);

    return 0;
}
