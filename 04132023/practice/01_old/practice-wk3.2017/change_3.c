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

int main(void)
{
    string note = get_string("Enter string: ");

    short oct = 0, n = strlen(note);
    short i;

    /**
     * A character array to store the non-digit
     * parts of the note.
     */

    char c[n - 1];

    //Changes the entry to uppercase if user typed lowercase
    for (i = 0; i < n - 1; i++)
        c[i] = toupper(note[i]);

    //Adjusts for flats
    if (c[i - 1] == 'B')
    {
        if (c[i - 2] == 'F')
        {
            c[i - 2] = 'E';
            c[i - 1] = '\0';
        }

        else if (c[i - 2] == 'A')
        {
            c[i - 2] = 'G';
            c[i - 1] = '#';
        }

        else
        {
            c[i - 2] = c[i - 2] - 1;
            c[i - 1] = '#';
        }
    }

    else if (c[i - 1] == '#' && c[i - 2] == 'E')
    {
        c[i - 2] = 'F';
        c[i - 1] = '\0';
    }

    //Separates note from octave
    if (n == 2 || n == 3)
        oct = atoi(&note[n - 1]);

    printf("%s\n%i\n", c, oct);

    //Finds the position of the note in the NOTES array
    int k;
    for (k = 0; k < NOTES_SIZE; k++)
        if (strcmp(c, NOTES[k]) == 0)
            break;

    printf("Found at position %i\n", k);

    //Finds number of notes from note A4
    int freq = 0, b = 0;

    //For notes before the 4th octave
    if (oct < 4)
        for (; k < NOTES_SIZE; k++)
        {
            if (strcmp("A", NOTES[k]) == 0 && oct == 4)
                break;

            else
                b--;

            if (k == 11)
            {
                k = -1;
                oct++;
            }
        }

    //For notes after the 4th octave
    else if (oct > 4)
    {
        for (; k > -1; k--)
        {
            if (strcmp("A", NOTES[k]) == 0 && oct == 4)
                break;

            else
                b++;

            if (k == 0)
            {
                k = 12;
                oct--;
            }
        }
    }

    //For notes within the 4th octave
    else if (oct == 4)
    {
        if (k < 10)
        {
            for (; k < NOTES_SIZE; k++)
            {
                if (strcmp("A", NOTES[k]) == 0 && oct == 4)
                break;

                else
                    b--;
            }
        }

        else if (k > 8)
        {
            for (; k > -1; k--)
            {
                if (strcmp("A", NOTES[k]) == 0 && oct == 4)
                break;

                else
                    b++;
            }
        }

    }

    //Computes the frequency
    float z = pow(2, (float)b / 12);
    freq = round(440 * z);

    printf("Frequency = %i\n", freq);

    return 0;
}