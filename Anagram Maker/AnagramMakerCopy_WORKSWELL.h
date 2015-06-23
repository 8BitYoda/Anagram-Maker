#ifndef ANAGRAMMAKER_H
#define ANAGRAMMAKER_H
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

class AnagramMaker{
public:
  AnagramMaker(const string &dictFile);
  unsigned int findAnagrams(const string &input, const bool &print) const;
private:
  struct data{
	
	data(){};
	//data(int c, string &w){
	  //letLeft=c;
	data(const string &w){
	  word=w;
	  for(int i=0; i<26; i++)
		letters[i]=0;
	  //for(int i=letLeft-1; i>-1; i--){
	  for(int i=word.length()-1; i>-1; i--){
		char temp=word[i];
		temp=temp-'a';
		letters[temp]+=1;
		//int index=temp-'a';
		//letters[index]=+1;
	  }

	  /*int i=0;
	  while(letters[i]==0)
		++i;
	  s=letters[i];*/ //makes slower dont use!
	}
	//int letLeft;
	//char s;
	string word;
	char letters[26];
	
	//array<char, 26> letters;
  };
  vector<data> origDict;
  bool tempTest(const char orig[]);
  //int findAnagrams(const string &soFar, const data &input, const bool &print, const vector<data>::const_iterator &it) const;
  int findAnagrams(const string &soFar, const char input[], const bool &print, const vector<data>::const_iterator &myIt,const vector<data> &tempD) const;
  //int findAnagrams(const string &soFar, const char input[], const bool &print, const vector<data> &tempD) const; NO
  //bool testWord(const data &input, const data &it)const;
  bool testWord(const char input[], const char it[])const;
  bool empty(const char e[])const;
};
#endif