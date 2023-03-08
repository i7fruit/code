#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define NOTES_SIZE 12

// Notes in an octave
const string NOTES[] = {"C", "C#", "D", "D#", "E", "F",
                        "F#", "G", "G#", "A", "A#", "B"
                       };

string adjust(char arr[], short i);
short find_position(string s);
int get_frequency(short oct, short k);

int main(void)
{
    string note = get_string("Enter string: ");

    short octave = 0, n = strlen(note);
    short i;
    int f = 0;

    /**
     * A character array to store the non-digit
     * parts of the note.
     */

    char c[n - 1];

    //Changes the entry to uppercase if user typed lowercase
    for (i = 0; i < n - 1; i++)
        c[i] = toupper(note[i]);

    //Adjusts for flats and sharps
    string col = adjust(c, i);

    for (int j = 0; j < strlen(c); j++)
        c[j] = col[j];

    //Separates note from octave
    if (n == 2 || n == 3)
        octave = atoi(&note[n - 1]);

    printf("%s\n%i\n", c, octave);

    //Finds the position of the note in the NOTES array
    short k = find_position(c);

    printf("Found at position %hi\n", k);

    f = get_frequency(octave, k);

    printf("Frequency = %i\n", f);

    return 0;
}

string adjust(char arr[], short i)
{
    //Adjusts for flats
    if (arr[i - 1] == 'B')
    {
        if (arr[i - 2] == 'F')
        {
            arr[i - 2] = 'E';
            arr[i - 1] = '\0';
        }

        else if (arr[i - 2] == 'A')
        {
            arr[i - 2] = 'G';
            arr[i - 1] = '#';
        }

        else
        {
            arr[i - 2] = arr[i - 2] - 1;
            arr[i - 1] = '#';
        }
    }

    else if (arr[i - 1] == '#' && arr[i - 2] == 'E')
    {
        arr[i - 2] = 'F';
        arr[i - 1] = '\0';
    }

    return arr;
}

//Finds position in NOTES array
short find_position(string s)
{
    short k = 0;

    for (; k < NOTES_SIZE; k++)
        if (strcmp(s, NOTES[k]) == 0)
            break;

    return k;
}

//Computes the frequency
int get_frequency(short oct, short p)
{
    //Finds number of notes from note A4
    int freq = 0, b = 0;

    //For notes before the 4th octave
    if (oct < 4)
        for (; p < NOTES_SIZE; p++)
        {
            if (strcmp("A", NOTES[p]) == 0 && oct == 4)
                break;

            else
                b--;

            if (p == 11)
            {
                p = -1;
                oct++;
            }
        }

    //For notes after the 4th octave
    else if (oct > 4)
    {
        for (; p > -1; p--)
        {
            if (strcmp("A", NOTES[p]) == 0 && oct == 4)
                break;

            else
                b++;

            if (p == 0)
            {
                p = 12;
                oct--;
            }
        }
    }

    //For notes within the 4th octave
    else if (oct == 4)
    {
        if (p < 10)
        {
            for (; p < NOTES_SIZE; p++)
            {
                if (strcmp("A", NOTES[p]) == 0 && oct == 4)
                break;

                else
                    b--;
            }
        }

        else if (p > 8)
        {
            for (; p > -1; p--)
            {
                if (strcmp("A", NOTES[p]) == 0 && oct == 4)
                break;

                else
                    b++;
            }
        }

    }

    //Computes the frequency
    float z = pow(2, (float)b / 12);
    return freq = round(440 * z);
}