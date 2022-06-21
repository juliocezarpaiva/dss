#define _GLIBCXX_USE_CXX11_ABI 0

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <math.h>

using namespace std;

#include "include/nlohmann/json.hpp"
using json = nlohmann::json;

#include "src/spool.cpp"
#include "src/well.cpp"
#include "src/manifold.cpp"
#include "src/model.cpp"

int main() {
	// TODO: read data from json files
	// TODO: write data to json files
  map<int, Well> my_wells;
  my_wells.insert(pair<int, Well> (1, Well(1, "P1", 5.0)));
  my_wells.insert(pair<int, Well> (2, Well(2, "P2", 5.5)));
  my_wells.insert(pair<int, Well> (3, Well(3, "P3", 6.0)));
  my_wells.insert(pair<int, Well> (4, Well(4, "P4", 5.6)));
  my_wells.insert(pair<int, Well> (5, Well(5, "P5", 5.7)));

  map<int, Spool> my_spools;
  my_spools.insert(pair<int, Spool> (1, Spool(1, "S1", 30, 5.2)));
  my_spools.insert(pair<int, Spool> (2, Spool(2, "S2", 31, 5.5)));
  my_spools.insert(pair<int, Spool> (3, Spool(3, "S3", 34, 6.3)));
  my_spools.insert(pair<int, Spool> (4, Spool(4, "S4", 32, 6.0)));
  my_spools.insert(pair<int, Spool> (5, Spool(5, "S5", 32, 6.0)));

  Manifold my_manifold1 = Manifold(1, "M1", my_wells, my_spools);

  Mgeometry1 my_mgeometry1 = Mgeometry1(1, "Mgeometry1", 3, &my_manifold1);
  Mflow1 my_mflow1 = Mflow1(2, "Mflow1", 0, &my_manifold1);

  // TODO: set diameter precision
  cout << "my_mgeometry1 diameter = " << my_mgeometry1.getDiameter() << endl;
  cout << "my_mflow1 diameter = " << my_mflow1.getDiameter() << endl;
  return 0;
}

// TODO: print a simple user interface, so the user will be capable to insert
// spools, wells and manifolds

// TODO: create a simple interface that allows users to create connections
// between spools and wells, so the connections will be not is dependent anymore