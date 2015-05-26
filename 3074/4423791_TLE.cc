#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VI SIZE;
VI FIRST;

inline int ComputeSize (int x){ int i = 0; while (x){ x = (x & (x-1)); ++i; } return i; }
inline int ComputeFirst (int x){ int i = 0; while (x && !(x & 1)){ x = x/2; ++i; } return i; }

bool Erase (VI &puzzle, int i, int j, int val, VI &propagate){
  if (puzzle[i*9+j] & (1 << val)){
    puzzle[i*9+j] -= (1 << val);
    int size = SIZE[puzzle[i*9+j]];
    if (size == 1) propagate.push_back (i*9+j);
    else if (size == 0) return false;
  }
  return true;
}

bool Do (VI &puzzle, int i, int j, int val){
  puzzle[i*9+j] = (1 << val);

  VI propagate (1, i*9+j);
  while (!propagate.empty()){
    i = propagate.back() / 9;
    j = propagate.back() % 9;
    val = FIRST[puzzle[i*9+j]];
    propagate.pop_back();

    for (int k = 0; k < 9; k++){
      if (k != i) if (!Erase (puzzle, k, j, val, propagate)) return false;
      if (k != j) if (!Erase (puzzle, i, k, val, propagate)) return false;
    }
    
    for (int ki = (i/3)*3; ki < (i/3)*3+3; ki++) if (ki != i){
      for (int kj = (j/3)*3; kj < (j/3)*3+3; kj++) if (kj != j){
	if (!Erase (puzzle, ki, kj, val, propagate)) return false;
      }
    }
  }
  return true;
}

void Print (const VI &puzzle){
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      cout << FIRST[puzzle[i*9+j]];
  cout << endl;
}

void ReadPuzzle (VI &puzzle){
  string s;
  getline (cin, s);
  if (s == "end") exit(0);

  for (int i = 0; i < s.length(); i++)
    if (s[i] != '.') Do (puzzle, i/9, i%9, (int)(s[i] - '0'));
}

bool SolvePuzzle (const VI &puzzle){
  int min_left = 10, bi = -1, bj = -1;

  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      int size = SIZE[puzzle[i*9+j]];
      if (size == 1) continue;
      if (min_left > size){
	min_left = size;
	bi = i;
	bj = j;
      }
    }
  }

  if (min_left == 10){
    Print (puzzle);
    return true;
  }  

  for (int k = 1; k <= 9; k++) if (puzzle[bi*9+bj] & (1 << k)){
    VI temp (puzzle);
    if (Do (temp, bi, bj, k)){
      if (SolvePuzzle (temp)) return true;
    }
  }

  return false;
}

int main (){

  for (int i = 0; i < 1024; i++){
    SIZE.push_back (ComputeSize (i));
    FIRST.push_back (ComputeFirst (i));
  }

  while (true){
    VI puzzle = VI (81, (1<<10)-2);
    ReadPuzzle (puzzle);
    SolvePuzzle (puzzle);
  }

  return 0;
}
