/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <cstddef>
#include <iostream>
#include "split.h"

int main(int argc, char* argv[])
{
  Node* fifth = new Node(5, nullptr);
  Node* fourth = new Node(4, fifth);
  Node* third = new Node(3, fourth);
  Node* second = new Node(2, third);
  Node* head = new Node(1, second);
  
  

  Node* curr = head;
  while(curr != nullptr)
  {
    std::cout << curr -> value << std::endl;
    curr = curr->next;
  }

  Node* odds = NULL;
  Node* evens = NULL;
  split(head, odds, evens);

  Node* odd = odds;
  while(odd != nullptr)
  {
    std::cout << "odd" << odd -> value << std::endl;
    odd = odd ->next;
  }

  Node* even = evens;
  while(even != nullptr)
  {
    std::cout << "even" << even -> value << std::endl;
    even = even->next;
  }
}