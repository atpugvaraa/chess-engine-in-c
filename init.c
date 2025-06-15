#include "defs.h"

int Sq120ToSq64[boardSquareNumber];
int Sq64ToSq120[64];

U64 SetMask[64];
U64 ClearMask[64];

void InitBitMasks() {
    int index = 0;

    for (index = 0; index < 64; index++) {
        SetMask[index] = 0ULL;
        ClearMask[index] = 0ULL;
    }

    for (index = 0; index < 64; index++) {
        SetMask[index] |= (1ULL << index);
        ClearMask[index] = ~SetMask[index];
    }
}

void InitSq120ToSq64() {
    int index = 0;
    int file = fileA;
    int rank = rank1;
    int sq = A1;
    int sq64 = 0;

    for (index = 0; index < boardSquareNumber; ++index) {
        Sq120ToSq64[index] = 65;
    }

    for (index = 0; index < 64; ++index) {
        Sq64ToSq120[index] = 120;
    }

    for (rank = rank1; rank <= rank8; ++rank) {
        for (file = fileA; file <= fileH; ++file) {
            sq = FR2SQ(file, rank);
            Sq64ToSq120[sq64] = sq;
            Sq120ToSq64[sq] = sq64;
            sq64++;
        }
    }
}

void AllInit() {
    InitSq120ToSq64();
    InitBitMasks();
} 