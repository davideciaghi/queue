#ifndef MY_CIRCULAR_QUEUE_H
#define MY_CIRCULAR_QUEUE_H
  
#include <stdexcept>
#include <string>
#include <iostream>
 
 
namespace my {
  
 
   /* A circular queue of chars with a fixed capacity
   */
   class CircularQueue {
      
       private:

       int head;
       int capacity;
       int size;
       char *arr[];

 
       public:


        /* Initializes the queue, reserving space for a number of elements equal to provided capacity.                   
 
               - dynamically allocates a char array inside            
               - If capacity is <= 0, throws std::invalid_argument
               - Complexity: O(capacity)
        */ 
        CircularQueue(int capacity); // Costruttore



        /**  Distruttore
        */
        ~CircularQueue();


        /** Return the capacity of the queue, that is, the maximum number of allowed elements in the queue.
                  
                   - Complexity: O(1)
           */   
        int get_capacity();


        /**
               Return true if the queue is empty, false otherwise.
              
               - Complexity: O(1)
           */ 
        bool isEmpty();


        /**
                Return the element at the head of the queue, without removing it.
              
                   - If the queue is empty, raises std::runtime_error
                   - Complexity: O(1)
                  
           */
        char top();

        
        /**  Return the size of the queue.
              
                   - Complexity: O(1)
           */ 
        int get_size();



        /** Enqueues provided element v at the end of the queue.
              
                   - If the queue is full, raises std::runtime_error
                   - Complexity: O(1)
           */  
        void enqueue(char c);

        

        /** Removes head element and returns it.
                      
               - If the queue is empty, raises a std::runtime_error
               - Complexity: O(1)
           */
        char dequeue();



        int get_arr();
      
   };
  
};
 
 
 
#endif // MY_CIRCULAR_QUEUE_H