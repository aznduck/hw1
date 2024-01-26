#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <string>
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val)
{
  if(!head_ && !tail_)
  {
    Item* node = new Item();
    head_ = node;
    tail_ = node;
    node -> val[0] = val;
    node -> last = 1;
  }
  else if(tail_ -> last == ARRSIZE)
  {
    Item* node = new Item();
    tail_ -> next = node; //
    node -> prev = tail_;
    tail_ = node;
    node -> val[0] = val;
    node -> last = 1;
  }
  else
  {
    tail_ -> val[tail_ -> last] = val;
    tail_ -> last++;
  }
  size_++;
}

void ULListStr::pop_back()
{
  if(tail_)
  {
    if(tail_ -> last == 1)
    {
      Item* temp = tail_;
      tail_ = tail_ -> prev;
      if(tail_)
        tail_ -> next = NULL;
      else 
        head_ = NULL;
      delete temp;
    }
    else
    {
      tail_ -> val[tail_ -> last - 1] = "";
      tail_ -> last--;
    }
    size_--;
  }
}

void ULListStr::pop_front()
{
  if(head_)
  {
    if(head_ -> first == ARRSIZE - 1)
    {
      Item* temp = head_;
      head_ = head_ -> next;
      if(head_)
        head_ -> prev = NULL;
      else 
        tail_ = NULL;
      delete temp;
    }
    else
    {
      head_ -> val[head_ -> first] = "";
      head_ -> first++;
    }
    size_--;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if(!head_ && !tail_)
  {
    Item* node = new Item();
    head_ = node;
    tail_ = node;
    node -> val[ARRSIZE - 1] = val;
    node -> last = ARRSIZE;
    node -> first = ARRSIZE - 1;
  }
  else if(head_ -> first == 0)
  {
    Item* node = new Item();
    head_ -> prev = node; //
    node -> next = head_;
    head_ = node;
    node -> val[ARRSIZE - 1] = val;
    node -> first = ARRSIZE - 1;
    node -> last = ARRSIZE;
  }
  else
  {
    head_ -> first--;
    head_ -> val[head_ -> first] = val;
  }
  size_++;
}


std::string const & ULListStr::back() const
{
  return tail_ -> val[(tail_ -> last) - 1];
}

std::string const & ULListStr::front() const
{
  return head_ -> val[head_ -> first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  Item* temp = head_;
  size_t itemCounter = 0;
  while(temp != NULL)
  {
    size_t valCounter = temp -> first; 
    while(valCounter < temp -> last)
    {
      if(itemCounter == loc)
      {
        return &(temp -> val[valCounter]);
      }
      valCounter++;
      itemCounter++;
    }
    temp = temp -> next;
  }
  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
