#include "btree.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <iterator>
using namespace std;
void foo( const_btree_iterator<int> iter){

}
int main(){
  srand(0);
  btree<int> b(4);
  vector<int> vec(100,1);
  cout << "size" << vec.size();
  int nr;
  for( int i=0; i<100;++i){
//    nr = rand()%100;
 //   vec[nr] = 0;
    auto p = b.insert(i);
  }
  for(int i=0; i<101; ++i){
    auto it = b.find(i); 
    bool isEnd = b.find(i) == b.end();
    if(isEnd){
      cout << i << " find not working"<<endl;
    }
  }
  cout << b << endl;

  auto it = b.begin();
  auto it3 = b.begin();
  const_btree_iterator<int> it2 = it;
  foo(it);
  if( it2++ == it3){
    cout << "iterator working" <<endl;
  }else{
    cout << "iterator Failed" <<endl;
  }
  auto it4 = b.crbegin();
  auto it5 = b.crbegin();
  if( it4++ == it5){
    cout << "Rev iterator working" <<endl;
  }else{
    cout << "Rev iterator Failed" <<endl;
  }


  /*
    if(p.second){
      if(*p.first != nr){
        cout << "ERROR"<<endl;
      }
    }else{
      cout << "second case"<<endl;
      if(p.first != b.end()){
        cout << "ERROR 2 "<< *p.first << " " <<nr<<endl;
      }else{
        cout << "NO ERROR 2" <<endl;
      }
    }

  }
  */

/*
  btree<int> c(move(b));
  cout <<"bfs: "<< c << endl;
  cout << "increasing: ";
  auto end = c.end();
  nr = 0;
  for(auto it=c.begin(); it!= c.end(); ++it){
    cout << *it<<" ";
    --it;
    ++it;
    cout << *it<<" "<<endl;
  }
  for( int i=0; i<100; ++i){
    if( vec[i] == 1){
      auto it = c.find(i);
      if( it != c.end() ){
        cout << "it isnt equal to end" <<endl;
      }

    }

  }
  cout << "END" << endl;
 */ 
  
  /*
  auto it1 = c.end();
  auto it2 = c.cbegin();

  reverse_iterator<btree_iterator<int>> it3(c.begin());
  */
  /*
  auto it= c.begin();
  auto it2= c.end();
  while(true){
    cout << "test.cpp: " <<*it << endl;
    ++it;
    if( it == it2){
      break;
    }
  }
  */
  return 0;
}
