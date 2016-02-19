// -----------
// includes
// -----------

#include <cassert>
#include <iostream>
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
  string s;

  // Stripping off the first line in the input
  // How many elections are we having???
  getline(r, s);
  stringstream ss(s);
  ss >> i;
  getline(r, s);
  assert(i > 0);}

//-------------------------
// voting_read_cand
// ------------------------

/*
  @param input stream
  @param a reference to an int  for future use by the caller
  sets the int reference to equal what should be the number of candidates for this election
  sets data for the candidate array
*/

void voting_read_cand (istream& r, int& j){
  int i = 0;
  string s;

  // Reading the number of candidates for an election
  getline(r, s);
  stringstream ss(s);
  ss >> j;

  // array of strings that represents the name of the candidates
  while(i < j){
    getline(r, s);
    name[i] = s;
    ++i;}
  assert(j > 0);
  assert(j < 21);}

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
  int i;
  string s;

  // Reading ballots
  getline(r, s);
  stringstream ss(s);

  if(s == ""){
    return false;}
  else{
    ss >> i;
    getline (ss, s);
    // inserting pairs of ballots and who the ballot counts to in a list.
    // using an int to represent the index of a candidates name in the array, and determining if
    // that ballot goes to them or not
    ballot_list.insert(pair<int, string>(i, s));
    ++votes[i-1];
    return true;}}

//-----------------
// voting_eval
// ----------------

/*
  @param a int reference for the totalVotes that we have
  @param a int reference for the number of candidates
  Calculates the winner of a given election
*/

string voting_eval (int& numV, int& cand){
  int min = 1001;
  int max = 0;
  int count = 0;
  string s = "";
  int i;

  // if there are no ballots to for the candidate
  if(numV == 0){
    for(int i = 0; i < cand; ++i){
      if(count > 0){
        s += "\n" + name[i];}
      else{
        s += name[i];}
      ++count;}
    return s;}

  while(1){
    // finding the min and max in an array
    for(int elem = 0; elem < cand; ++elem){
      // auto win if this case is seen, candidate with more then half the votes
      if(votes[elem] > (numV/2)){
        return name[elem];}
      // counting votes
      else{
        if(votes[elem] < min && votes[elem] > 0){
          min = votes[elem];}
        if(votes[elem] > max){
          max = votes[elem];}}}

    if(max == min){
      // We have a tie for winner; multimap contains keys of corresponding to winners
      // very bad solution
      s = "";
      for(int win = 0; win < cand; ++win){
        if(votes[win] > 0){
          if(count > 0){
            s += "\n" + name[win];}
          else{
            s += name[win];}
          ++count;}}
      return s;}


    //Fucking Brilliant code *Please pronounce this is a british accent*
    for(int elem = 0; elem < cand; ++elem){
      if(min == votes[elem]){
        multimap<int, string>::iterator it;
        for(it = ballot_list.equal_range(elem + 1).first; it != ballot_list.equal_range(elem + 1).second; ++it){
          s = (*it).second;
          stringstream ss(s);
          ss >> i;
          while(votes[i - 1] <= min){
            ss >> i;}
          getline(ss, s);
          ballot_list.insert(pair<int, string>(i, s));
          ++votes[i - 1];}
        ballot_list.erase(elem + 1);
        votes[elem] = 0;}}
  min = 1001;}}

//------------------
// voting_solve
// ------------------

/*
  @param a reference to an input stream
  @param s reference to an output stream
*/

void voting_solve(istream& r, ostream& w){
  // Number of different elections in input
  int cases;
  // Number of Candidates in an election
  int numCand;
  // Number of voter cards/ballots
  int totalVotes;

  voting_read_args(r, cases);

  // while we still haves cases left in stdin compute the winner in tthe next upcoming election
  while(cases > 0){
    voting_read_cand(r, numCand);
    totalVotes = 0;
    // For this election read all the ballots into my multimap
    while(voting_read_ballot(r)){
      ++totalVotes;}
    // TODO: Compute the winner in here
    if(cases == 1){
      w << voting_eval(totalVotes, numCand) << endl;}
    else{
      w << voting_eval(totalVotes, numCand) << endl << endl;}

    // reset my data structures for the next election
    for(int i = 0; i < 20; ++i){
      votes[i] = 0;
      name[i] = "";}

    ballot_list.clear();

    // one less case left
    --cases;

    // Can't have more than 1000 voter cards
    assert(totalVotes < 1001);}}