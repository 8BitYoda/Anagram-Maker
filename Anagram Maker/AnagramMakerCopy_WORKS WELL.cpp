#include <iostream>
#include <string>
#include <fstream>
#include "AnagramMaker.h"
using namespace std;

AnagramMaker::AnagramMaker(const string &dictFile){
  string line;
  ifstream myfile (dictFile);
  if (myfile.is_open()){
	while (!myfile.eof()){
	  getline(myfile, line);
	  //data newWord(line.length(),line);
	  data newWord(line);
	  origDict.push_back(newWord);
    }
   myfile.close();
  }
}

unsigned int AnagramMaker::findAnagrams(const string &input, const bool &print)const{
  string in=input;
  //data origWord(in.length(),in);
  data origWord(in);
  vector<data> tempDict;
  for(unsigned int i=0; i<origDict.size(); i++){
	if(origDict[i].word.length()<=origWord.word.length()){
	  //if(origDict[i].s<=origWord.s){
		if(testWord(origWord.letters,origDict[i].letters)){
		  data tempWord(origDict[i].word);
		  tempDict.push_back(tempWord);
		}
	  //}
	}
  }
  //return findAnagrams("",origWord,print,origDict.begin());
  //return findAnagrams("",origWord.letters,print,origDict.begin());
  return findAnagrams("",origWord.letters,print,tempDict.begin(),tempDict);//,tempDict.begin());
}

//int AnagramMaker::findAnagrams(const string &soFar, const data &input, const bool &print, const vector<data>::const_iterator &myIt) const{
//  int anaCount=0;
//  vector<data>:: const_iterator it = myIt;
//  data finds;
//  while(it!=origDict.end()){
//	if(testWord(input, *it)){
//	  for(int i=0; i<26; i++){
//		finds.letters[i]=input.letters[i]-it->letters[i];
//		finds.letLeft=input.letLeft-(it->letLeft);
//	  }
//	  if(finds.letLeft==0){
//		anaCount++;
//		if(print==1)
//		  cout<<soFar + " " + it->word<<endl;
//	  }
//	  else
//		anaCount += findAnagrams(soFar+" "+it->word,finds, print, it);
//	}
//	it++;
//  }
//  return anaCount;
//}
int AnagramMaker::findAnagrams(const string &soFar, const char input[], const bool &print, const vector<data>::const_iterator &myIt, const vector<data> &tempD) const{
//int AnagramMaker::findAnagrams(const string &soFar, const char input[], const bool &print, const vector<data> &tempD) const{
  int anaCount=0;
  vector<data>:: const_iterator it = myIt;
  char result[26];
  while(it!=tempD.end()){
  	if(testWord(input, it->letters)){
	  for(int i=0; i<26; i++){
		result[i]=input[i]-it->letters[i];
	  }
	  if(empty(result)){
		anaCount++;
		if(print==1)
		  cout<<soFar + " " + it->word<<endl;
	  }
	  else
		anaCount += findAnagrams(soFar+" "+it->word,result, print, it, tempD);
	}
	it++;
  }
  return anaCount;
}
//bool AnagramMaker::testWord(const data &input, const data &it)const{
//  for(unsigned int i=0; i<it.word.length(); i++){
//	char index = it.word[i];
//	index=index-'a';
//	if(input.letters[index]<it.letters[index]) return false;
//	//int index = letter-'a';
//	//if(input.letters[index]<it.letters[index]) return false;
//  }
//  return true;
//}

bool AnagramMaker::testWord(const char input[], const char it[])const{
  for(int i=0; i<26; i++){
	if(input[i]<it[i]) return false;
  }
  return true;
}
 
bool AnagramMaker::empty(const char e[])const{
  for(int i=0; i<26; i++){
	if(e[i]!=0) return false;
  }
  return true;
}
