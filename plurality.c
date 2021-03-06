#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{

    int b = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            b++;
        }
        else
        {
            continue;
        }
    }
    if (b != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    string winner;
    int w = 0;
    if (candidate_count == 1)
    {
        winner = candidates[0].name;
        printf("%s\n", winner);
        return;
    }
    for (int i = 0; i < candidate_count - 1; i++)
    {
        if (candidates[w].votes > candidates[i + 1].votes)
        {
            winner = candidates[w].name;
            //w = i;
        }
        else if (candidates[w].votes < candidates[i + 1].votes)
        {
            winner = candidates[i + 1].name;
            w = i + 1;
        }
        else
        {
            winner = candidates[0].name;
            w = 0;
        }
    }

    printf("%s\n", winner);
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == candidates[w].votes && i != w)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

