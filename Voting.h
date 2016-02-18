#ifndef Voting_h
#define Voting_h

// -----------
// includes
// -----------

#include <iostream>
#include <string>

//-------------------------
// voting_read_args
// ------------------------

/*
	@param input stream
	@param a reference to an int for future use by the caller
	sets the int reference to equal what should be the number of elections as described by the input
*/

void voting_read_args (std::istream&, int&);

//-------------------------
// voting_read_cand
// ------------------------

/*
	@param input stream
	@param a reference to an int  for future use by the caller
	sets the int reference to equal what should be the number of candidates for this election
	sets data for the candidate array
*/

void voting_read_cand (std::istream&, int&);

//---------------------------
// voting_read_ballot
// --------------------------

/*
	@param input stream
	reads the ballots into a multimap as a pair of int and a string
	the int representing the lead person the ballot is for
	the string representing the rest of the ballot
*/

bool voting_read_ballot (std::istream&);

//-----------------
// voting_eval
// ----------------

/*
	@param a int reference for the totalVotes that we have
	@param a int reference for the number of candidates
	Calculates the winner of a given election
*/

std::string voting_eval (int&, int&);

//------------------
// voting_solve
// ------------------

/*
	@param a reference to an input stream
	@param s reference to an output stream
*/

void voting_solve(std::istream&, std::ostream&);

#endif