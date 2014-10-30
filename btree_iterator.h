#ifndef BTREE_ITERATOR_H
#define BTREE_ITERATOR_H
#include <iterator>

using namespace std;

template <typename T> class btree;
template <typename T> class const_btree_iterator;
template <typename T> class btree_iterator;

template <class T> 
  bool operator==(const_btree_iterator<T> lhs, const_btree_iterator<T> rhs);
template <class T> 
  bool operator!=(const_btree_iterator<T>& lhs, const_btree_iterator<T>& rhs);

//§template <class T> 
//  bool operator==(const_btree_iterator<T> lhs, btree_iterator<T> rhs);
//template <class T> 
//  bool operator!=(const_btree_iterator<T> lhs, btree_iterator<T> rhs);


template <typename T>
class btree_iterator{
  public:
  friend const_btree_iterator<T>;
  friend bool operator==<T>(const_btree_iterator<T> lhs, const_btree_iterator<T> rhs);
  friend bool operator!=<T>(const_btree_iterator<T>& lhs, const_btree_iterator<T>& rhs);
  typedef ptrdiff_t difference_type;
  typedef bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  reference operator*() const;
  pointer operator->() const;
  btree_iterator& operator++();
  btree_iterator& operator--();
//  bool operator==(const btree_iterator& other);
//  bool operator!=(const btree_iterator& other);
  // begin();
  btree_iterator( btree<T>* root);
  // find();
  btree_iterator( btree<T>* pTree, size_t index);

  private:
  bool goLeft();
  bool goRight();
  btree<T>* _pTree;
  btree<T>* _root;
  size_t _index;

};
/**
  *
  * Const iterator
  *
  */
template <typename T>
class const_btree_iterator{
  public:
  typedef ptrdiff_t difference_type;
  typedef bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef const T* pointer;
  typedef const T& reference;

  friend bool operator==<T>(const_btree_iterator<T> lhs, const_btree_iterator<T> rhs);
  friend bool operator!=<T>(const_btree_iterator<T>& lhs, const_btree_iterator<T>& rhs);

//  friend bool operator==<T>(const_btree_iterator<T> lhs, btree_iterator<T> rhs);
//  friend bool operator!=<T>(const_btree_iterator<T> lhs, btree_iterator<T> rhs);

  reference operator*() const;
  pointer operator->() const;
  const_btree_iterator& operator++();
  const_btree_iterator& operator--();
  //bool operator==(const const_btree_iterator& other);
  //bool operator!=(const const_btree_iterator& other);
  // begin();
  const_btree_iterator( const btree<T>* root);
  // find();
  const_btree_iterator( const btree<T>* pTree, size_t index);
  const_btree_iterator( const btree_iterator<T>& it );
//  const_btree_iterator( const btree_iterator<T> it );

  private:
  bool goLeft();
  bool goRight();
  const btree<T>* _pTree;
  const btree<T>* _root;
  size_t _index;

};
/**
 * You MUST implement the btree iterators as (an) external class(es) in this file.
 * Failure to do so will result in a total mark of 0 for this deliverable.
 **/

// iterator related interface stuff here; would be nice if you called your
// iterator class btree_iterator (and possibly const_btree_iterator)

#include "btree_iterator.tem"

#endif
