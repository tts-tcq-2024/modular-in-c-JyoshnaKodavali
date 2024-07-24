#include <stdio.h>
#include <assert.h> 
#include "colorPairDataStructures.h"
#include "convertColorPairToNumber.h"
#include "convertNumberToColorPair.h"


void testNumberToColorPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorPairFromGivenNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    PrintColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testColorPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetNumberFromGivenColorPair(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberToColorPair(4, WHITE, BROWN);
    testNumberToColorPair(5, WHITE, SLATE);

    testColorPairToNumber(BLACK, ORANGE, 12);
    testColorPairToNumber(VIOLET, SLATE, 25);

    return 0;
}
