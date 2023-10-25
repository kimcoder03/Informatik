#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

enum _type{
    feuer,
    wasser,
    pflanzen,
    neutral,

};

typedef struct attack
{
    int8_t dmg;
    enum _type type;

};

typedef struct _Elemon{
    int8_t HP;
    uint8_t SPD;
    enum _type type;
    struct attack attack_1;
    struct attack attack_2;

}Elemon;

bool does_e1_beat_e2(Elemon e1, Elemon e2){
    return false;

};

int main (){
    Elemon Fatima_Feuer = {.HP = 81, .SPD = 83, .type = feuer, .attack_1 = {dmg = 47, .attack_1.type = feuer}, .attack_2 = {dmg = 32, .attack_2.type = neutral}};
    
};