#include <stdio.h>
#include <assert.h> 

// Define enums for major and minor colors
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

// Arrays to store color names corresponding to MajorColor enums
const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

// Calculate number of elements in MajorColorNames
int numberOfMajorColors =
    sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

// Arrays to store color names corresponding to MinorColor enums
const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

// Maximum characters for color pair name
const int MAX_COLORPAIR_NAME_CHARS = 16;

// Calculate number of elements in MinorColorNames arrays
int numberOfMinorColors =
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

// Struct to represent a color pair
typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

// Function to convert ColorPair to string representation
void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

// Function to get ColorPair from pair number
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

// Function to get pair number from ColorPair
int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

// Function to test GetColorFromPairNumber function
void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

// Function to test GetPairNumberFromColor function
void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

// Main function to run tests
int main() {
    // Test cases for converting pair number to ColorPair
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

     // Test cases for converting ColorPair to pair number
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    return 0;
}
