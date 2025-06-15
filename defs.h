#ifndef DEFS_H
#define DEFS_H

#include <stdlib.h>

#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
    if (!(n)) { \
        printf("Assertion failed: %s\n", #n); \
        printf("On %s", __DATE__); \
        printf("At %s", __TIME__); \
        printf("In file %s", __FILE__); \
        printf("At line %d\n", __LINE__); \
        exit(1);}
#endif

typedef unsigned long long U64;

#define NAME "FishStock 1.0"
#define boardSquareNumber 120

#define maxGameMoves 2048


// ENUMS
enum { empty, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };
enum { fileA, fileB, fileC, fileD, fileE, fileF, fileG, fileH, fileNone };
enum { rank1, rank2, rank3, rank4, rank5, rank6, rank7, rank8, rankNone };

enum { white, black, both };

enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, noSquare
};

enum { false, true };

enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 };


// STRUCTS
typedef struct {
    int move;
    int castlePermission;
    int enPassant;
    int fiftyMove;
    U64 posKey;
} Undo;

typedef struct {
    int pieces[boardSquareNumber];
    U64 pawns[3];

    int kingSquare[2];

    int side;
    int enPassant;
    int fiftyMove;

    int ply;
    int hisPly;

    int castlePermission;

    U64 posKey;

    int pieceNumber[13];
    int bigPiece[3];
    int majorPiece[3];
    int minorPiece[3];

    Undo history[maxGameMoves];

    int pieceList[13][10];


} Board;

/* MACROS */
#define FR2SQ(f, r) ((21 + (f)) + ((r) * 10))
#define SQ64(sq120) (Sq120ToSq64[(sq120)])
#define POP(b) PopBit(b)
#define CLEAR(bb, sq) ((bb) &= ClearMask[(sq)])
#define SET(bb, sq) ((bb) |= SetMask[(sq)])

/* GLOBALS */
extern int Sq120ToSq64[boardSquareNumber];
extern int Sq64ToSq120[64];
extern U64 SetMask[64];
extern U64 ClearMask[64];

/* FUNCTIONS */

// init.c
extern void AllInit();

// bitboards.c
extern void PrintBitboard(U64 bb);
extern int PopBit(U64 *bb);
extern int CountBits(U64 b);

#endif // DEFS_H