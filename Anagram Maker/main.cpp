#include <fstream>
#include <string>
#include "StopWatch.h"
#include "AnagramMaker.h"

int main (int argc, char* argv[]) {
  vector<int> vec;
  unsigned int count=0;
  double time, total=0;
  CStopWatch s;	//acts like a stop watch:  start, stop, and read the elapsed time
  bool print=false;
  if (argc <4) {
	printf ("Error, not enough parameters.  They can be entered by:\n  Project, properties, configuration properties, debugging, command arguments.\nParameters are dictionary file, yes or no for printing, and the phrases to test.\n");
	return 1;
  }

  if	  (strcmp(argv[2],"yes") == 0) print=true;
  else if (strcmp(argv[2],"no") == 0) print=false;
  else {
	printf("error in 2nd parameter which must be yes or no, got %s\n",argv[2]);
	return 2;
  }
  ifstream inTest;	//test that dictionary can be opened 
  inTest.open(argv[1]);
  if (!inTest.is_open()) {
	printf ("File %s could not be opened\n", argv[1]);
	return 3;
  }
  inTest.close();

  //time the preprocessing stage, ie the constructor
  s.startTimer();
  AnagramMaker anagrams(argv[1]);
  s.stopTimer();
  printf("%s took %4.4f seconds preprocessing\n", argv[1], s.getElapsedTime());

  for (int i=3; i<argc; ++i) {//run and time each findAnagrams call
	printf ("\tInput phrase %s\n",argv[i]);
	s.startTimer();
	count=anagrams.findAnagrams(argv[i],print);
    s.stopTimer();
    time=s.getElapsedTime();
	total+=time;
	printf("  for a total of %d anagrams in %4.4f seconds\n\n", count, time);
  }
  printf("Average time was %4.4f\n",total/(argc-3));//-program name, dictionary file, print arguments
  return 0;
}
