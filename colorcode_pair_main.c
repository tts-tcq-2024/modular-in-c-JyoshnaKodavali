#include "paircolorcode_main.h"

void PrintColorReferenceManual(void) {
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    for (int i = 1; i <= numberOfMajorColors * numberOfMinorColors; i++) {
        ColorPair colorPair = GetColorFromPairNumber(i);
        ColorPairToString(&colorPair, colorPairNames);
        printf("%d: %s\n", i, colorPairNames);
    }
}

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    PrintColorReferenceManual();
    return 0;
}
