#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

// Global variables
int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

// My function prototypes
bool creates_cycle(int los, int win);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();

    sort_pairs();

    lock_pairs();

    print_winner();

    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Checks if candidate is legitimate
    for (int i = 0; i < candidate_count; i++)
    {
        // Updates the candidate's rank count if legitimate
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Iterates through the ranks[] array
    for (int i = 0; i < candidate_count; i++)
    {
        /**
         * For this voter, add 1 in prefs[] array element
         *
         * preferrence[preferred-choise][less-preferred]
         *
         * to show one voter prefered ranks[i] over ranks[j]
         */
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            a = preferences[i][j];
            b = preferences[j][i];

            if (a > b)
            {
                pairs[c].winner = i;
                pairs[c].loser = j;
                c++;
                pair_count++;
            }

            else if (b > a)
            {
                pairs[c].winner = j;
                pairs[c].loser = i;
                c++;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int counter = -1;

    do
    {
        counter = 0;

        for (int i = 0, j = 1; i < pair_count - 1; i++, j++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                pair temp;
                temp.winner = pairs[j].winner;
                temp.loser = pairs[j].loser;

                pairs[j].winner = pairs[i].winner;
                pairs[j].loser = pairs[i].loser;

                pairs[i].winner = temp.winner;
                pairs[i].loser = temp.loser;
                counter++;
            }
        }
    }

    while (counter != 0);

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        // Locks pair
        locked[pairs[i].winner][pairs[i].loser] = true;

        // Checks if locking the pair creates a cycle
        if (creates_cycle(pairs[i].loser, pairs[i].winner))
        {
            // Unlocks pair if it does
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // Tracks canditate's false count in locked[][] array
    int false_counter = 0;

    // Iterates over each candidates colume from top to bottom, while k tracks candidate's index
    for (int i = 0, k = 0; k < candidate_count; k++, i = 0)
    {
        // j, keeps focus on candidate's colume while i goes down array's rows
        for (int j = k; i < candidate_count; i++)
        {
            // Increates counter if a value of false is detected in the candidate's colume
            if (locked[i][j] == false)
            {
                false_counter++;
            }
        }

        // Prints out the candidate with the highest false_counter count
        if (false_counter == candidate_count)
        {
            printf("%s\n", candidates[k]);
        }

        // Resets counter for each candidate
        false_counter = 0;
    }
    return;
}

// Detects if a cycle exits
bool creates_cycle(int los, int win)
{
    /**
     * Base case: If the winner is identical to the loser
     * it indicates a cycle, so the function returns true
     */
    if (los == win)
    {
        return true;
    }

    // Loops through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Does the loser win in any locked pairs?
        if (locked[los][i])
        {
            // If yes, check for cycle
            if (creates_cycle(i, win))
            {
                return true;
            }
        }
    }

    return false;
}