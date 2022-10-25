#include <cs50.h>
#include <stdio.h>
#include <string.h>



#pset2 Caesar solution of Cs50x
#adam50.com
#twitter : https://twitter.com/turabaev69/
#github : https://github.com/turabaev69/
#reddit: https://www.reddit.com/user/odom50/

// Max number of candidates
#define MAX 10

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
        return true;
    }

    // Populate array of candidates
    candidate_count = argc -1;
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
    // looping through candidates
    for (int i = 0; i < candidate_count; i++)
    {

        if (strcmp(candidates[i].name, name) == 0) //check for name
        {
            candidates[i].votes++; //if name matches, adds 1+

            return true;
        }
    }
    return false; //if it cannot find a person for voted
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //create integer variable and set it to -1
    int biggestVotes = -1;

    //check for highest  votes numbers
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= biggestVotes) //looks for candidate who is greater than biggestvotes and set them to biggestvites
        {
            biggestVotes = candidates[i].votes;
        }
    }


    for (int i = 0; i < candidate_count; i++) //cheking for candidate who got most votes
    {
        if (candidates[i].votes == biggestVotes)
        {
            printf("Bu Yilgi saylov g'olibi %s\n", candidates[i].name); //print the winner
        }
    }

    return;
}