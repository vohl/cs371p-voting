#include <iostream>
#include <sstream>
#include <string>
#include <utility>

#include "gtest/gtest.h"

#include "Voting.h"

// ---
// read_args
// ---

TEST(Voting, read_args_1){
  std::istringstream r("1\n\n2\nChad\nAndrew Vohl\n1 2\n2 1\n2 1");
  int v;
  voting_read_args(r, v);
  ASSERT_EQ(1, v);}

TEST(Voting, read_args_2){
  std::istringstream r("2\nIt dont matter what my name is");
  int v;
  voting_read_args(r, v);
  ASSERT_EQ(2, v);}

TEST(Voting, read_args_3){
  std::istringstream r("50000000\nI guess Im testing for nothing read");
  int v;
  voting_read_args(r, v);
  ASSERT_EQ(50000000, v);}

// ---
// read_cand
// ---

TEST(Voting, read_cand_1){
  std::istringstream r("3\nChad\nAndrew\nGabe");
  int v;
  voting_read_cand(r, v);
  ASSERT_EQ(3, v);}

TEST(Voting, read_cand_2){
  std::istringstream r("6\nWhat\nYou\nWant\nGi\nnga\n?");
  int v;
  voting_read_cand(r, v);
  ASSERT_EQ(6, v);}

TEST(Voting, read_cand_3){
  std::istringstream r("1\nOnly one my bro");
  int v;
  voting_read_cand(r, v);
  ASSERT_EQ(1, v);}

// ---
// read_ballot
// ---

TEST(Voting, read_ballot_1){
  std::istringstream r("1 2 3\n2 1 3\n2 3 1");
  bool v = voting_read_ballot(r);
  ASSERT_EQ(1, v);}

TEST(Voting, read_ballot_2){
  std::istringstream r("1");
  bool v = voting_read_ballot(r);
  ASSERT_EQ(1, v);}

TEST(Voting, read_ballot_3){
  std::istringstream r("");
  bool v = voting_read_ballot(r);
  ASSERT_EQ(0, v);}

// ---
// eval
// ---

TEST(Voting, eval_1){
  std::istringstream r("1\n\n2\nChad\nAndrew");
  int v;
  int j;
  int votes = 0;
  voting_read_args(r, v);
  voting_read_cand(r, j);
  while(voting_read_ballot(r)){
    ++votes;}
  std::string s = voting_eval(votes, j);
  ASSERT_EQ("Chad\nAndrew\n", s);}

TEST(Voting, eval_2){
  std::istringstream r("1\n\n1\nAndrew");
  int v;
  int j;
  int votes = 0;
  voting_read_args(r, v);
  voting_read_cand(r, j);
  while(voting_read_ballot(r)){
    ++votes;}
  std::string s = voting_eval(votes, j);
  ASSERT_EQ("Andrew\n", s);}

TEST(Voting, eval_3){
  std::istringstream r("1\n\n3\nA\nB\nC\n1 2 3\n2 1 3\n3 2 1");
  int v;
  int j;
  int votes = 0;
  voting_read_args(r, v);
  voting_read_cand(r, j);
  while(voting_read_ballot(r)){
    ++votes;}
  std::string s = voting_eval(votes, j);
  ASSERT_EQ("A\n", s);}

// ---
// solve
// ---

TEST(Voting, solve_1){
  std::istringstream r("1\n\n2\nAndrew\nChad");
  std::ostringstream w;
  voting_solve(r, w);
  ASSERT_EQ("Andrew\nChad", w.str());}

TEST(Voting, solve_2){
  std::istringstream r("1\n\n3\nA\nB\nC\n1 2 3\n2 1 3\n3 2 1");
  std::ostringstream w;
  voting_solve(r, w);
  ASSERT_EQ("A\nB\nC", w.str());}

TEST(Voting, solve_3){
  std::istringstream r("1\n\n2\nAndrew\nChad\n1 2\n1 2\n1 2\n2 1");
  std::ostringstream w;
  voting_solve(r, w);
  ASSERT_EQ("Andrew", w.str());}