#include <string.h>

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

// Added as extern definition as the definition will be in the c file 
extern const char* MajorColorNames[];
extern const char* MinorColorNames[];
extern int numberOfMajorColors;
extern int numberOfMinorColors;

/* Interface to Color pair to string */
void ColorPairToString(const ColorPair* colorPair, char* buffer);

/* Interface to Get color from pair number */
ColorPair GetColorFromPairNumber(int pairNumber);

/* Interface to Get Pair number from color */
int GetPairNumberFromColor(const ColorPair* colorPair);

/* Interface to Print reference Manual */
void PrintReferenceManual();
