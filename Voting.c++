// -----------
// includes
// -----------

#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <map>

#include "Voting.h"

//----------------
//Global_Variables
//----------------

using namespace std;
/*array of names, (index + 1) represents the interger representation of the name on the voting ballot*/
string name[20];
/*array that holds the count of votes per person, (index + 1) is integer representation of the name*/
int votes [20];
/*Map's remainder of voting card to a name */
//cache
multimap<int, string> ballot_list;

//-------------------------
// voting_read_args
// ------------------------

/*
  @param input stream
  @param a reference to an int for future use by the caller
  sets the int reference to equal what should be the number of elections as described by the input
*/

void voting_read_args (istream& r, int& i){
}

//-------------------------
// voting_read_cand
// ------------------------

/*
  @param input stream
  @param a reference to an int  for future use by the caller
  sets the int reference to equal what should be the number of candidates for this election
  sets data for the candidate array
*/

void voting_read_cand (istream& r, int& i){
}

//---------------------------
// voting_read_ballot
// --------------------------

/*
  @param input stream
  reads the ballots into a multimap as a pair of int and a string
  the int representing the lead person the ballot is for
  the string representing the rest of the ballot
*/

bool voting_read_ballot (istream& r){
  return true;}

//-----------------
// voting_eval
// ----------------

/*
  @param a int reference for the totalVotes that we have
  @param a int reference for the number of candidates
  Calculates the winner of a given election
*/

string voting_eval (int& numVotes, int& cand){
  return "";}

//------------------
// voting_solve
// ------------------

/*
  @param a reference to an input stream
  @param s reference to an output stream
*/

void voting_solve(istream& r, ostream& w){
}