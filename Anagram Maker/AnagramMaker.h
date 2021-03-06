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
  unsigned int findAnagrams(const string &input, const bool &print)const;
private:
  struct data{
	
	data(){	};
	//data(int c, string &w){
	  //letLeft=c;
	data(const string &w){
	  word=w;
	  //for(int i=0; i<26; i++)
	  for(int i=0; i<26; ++i)
		letters[i]=0;
	  //for(int i=letLeft-1; i>-1; i--){
	  for(int i=word.length()-1; i>-1; --i){
		/*char temp=word[i];
		temp=temp-'a';
		letters[temp]+=1;*/
		letters[word[i]-'a']+=1; // faster preprocessing
		//int index=temp-'a';
		//letters[index]=+1;
	  }
	  //erase spots that are zero????
	  /*int i=0;//----------------------------
	  while(letters[i]==0)
		++i;
	  s=letters[i];*/ //makes slower dont use!
	}
	//int letLeft;
	//char s;
	string word;
	char letters[26];
  };

  vector<data> origDict;

  bool tempTest(const char orig[]);
  //int findAnagrams(const string &soFar, const data &input, const bool &print, const vector<data>::const_iterator &it) const; //first
  //int findAnagrams(const string &soFar, const char input[], const bool &print, const vector<data>::const_iterator &myIt,const vector<data> &tempD) const; //pass just array
  int findAnagrams(const string &soFar, const data input, const bool &print, const vector<data>::const_iterator &myIt, const vector<data> &tempD) const;
  //bool testWord(const data &input, const data &it)const; //use with first
  bool testWord(const char input[], const char it[])const;
  bool empty(const char e[])const;
};
#endif