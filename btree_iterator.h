#ifndef BTREE_ITERATOR_H
#define BTREE_ITERATOR_H

#include <iterator>
using namespace std;

template <typename T> class btree;

template <typename T>
class btree_iterator{
  public:
  typedef ptrdiff_t difference_type;
  typedef bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  reference operator*() const;
  pointer operator->() const;
  btree_iterator& operator++();
  bool operator==(const btree_iterator& other);
  bool operator!=(const btree_iterator& other);
  btree_iterator( btree<T>* pointee=nullptr);
  private:
  // TODO is typename required here?
  btree<T>* _pointee;
  T holder;



};

/**
 * You MUST implement the btree iterators as (an) external class(es) in this file.
 * Failure to do so will result in a total mark of 0 for this deliverable.
 **/

// iterator related interface stuff here; would be nice if you called your
// iterator class btree_iterator (and possibly const_btree_iterator)

#include "btree_iterator.tem"

#endif