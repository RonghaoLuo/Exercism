#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// TODO: Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.

int vote_count(ElectionResult& election_result) {
    return election_result.votes;
}

// TODO: Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.

void increment_vote_count(ElectionResult& election_result, int votes) {
    election_result.votes += votes;
}

// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.

// Assume all votes are positive
ElectionResult& determine_result(std::vector<ElectionResult>& candidates) {
    unsigned winner = 0; // first assume the first candidate is the winner
    for (unsigned i = 1; i < candidates.size(); ++i) { // comparison to find the candidate with most votes
                                                       // start the comparison with the second candidate
        if (candidates.at(winner).votes < candidates.at(i).votes) {
            winner = i;
        }
    }

    candidates.at(winner).name = "President " + candidates.at(winner).name; // changes the variable "name" of the winner
    return candidates.at(winner); // returns the winner by reference, since the return type has "&" included
}

}  // namespace election