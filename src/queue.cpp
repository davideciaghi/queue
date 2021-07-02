#ifndef MY_CIRCULAR_QUEUE_H
#define MY_CIRCULAR_QUEUE_H
 
#include <stdexcept>
#include <string>
#include <iostream>
 
 
namespace my {
  
 
   /** A circular queue of chars: i_Tail = head + size with a fixed capacity
   */


   /* Inizializzo la queue, riservando lo spazio per un numero di elementi oari alla capacità assegnata.

            - Allocare dinamincamente un array di caratteri
            - Se la capacità è <=0 lanciare un std::invalid_argument
            - Complessità : 0(capacity)

   */ 
   class CircularQueue {
      
       private:

       int head;
       int capacity;
       int size;
       char * arr;

 
       public:
        
        CircularQueue(int capacity) {  // Costruttore
            if (capacity <= 0) {
                throw std::invalid_argument(std::string("Negative capacity: ") + std::to_string(capacity));
            }
            this->capacity = capacity;
            this->head = 0;
            this->size = 0;
            this->arr = new char[capacity];
        }


        /* Distruttore che distrugge ogni allocazione dinamica
        
           Viene chiamato al termine della circularQueue
        */
        ~CircularQueue() {
            cout << "DEBUG: chiamata distuttore CircularQueue" << endl;
            delete [] this->arr;
        }


        /* Return the capacity of the queue, that is, the maximum number of allowed elements in the queue.
                  
                   - Complexity: O(1)
        */   
        int get_capacity() {
            return this->capacity;
        }


        /* Ritorna true se la queue è vuota, false altrimenti.
              
               - Complexity: O(1)
        */ 
        bool isEmpty() {
            return this->size == 0; // Se size=0 la coda è vuota e ritorna TRUE
        }


        /* Ritorna l'elemento in head alla queue senza rimuoverlo
              
            - se la queue è vuota lancia std::runtime_error
            - Complexity: O(1)
                
        */
        char top() {

            if (isEmpty()) {
                throw std::runtime_error("Tried to get top from empty queue");
            }
            return this-> arr[this->head];
        }

        
        /* Ritorna la size della queue.
              
            - Complexity: O(1)
        */ 
        int get_size() {
            return this->size;
        }



        /* Inserisce il carattere dato nella cella con indice calculated_tail
              
            - Se la coda è piena lancia std::runtime_error
            - Complexity: O(1)
        */  
        void enqueue(char c) {
            cout << "DEBUG: enqueue" << endl;
            
            if (this->size == this->capacity) {
                throw std::runtime_error(std::string("Attempted to enqueue ") + c + std::string(" but queue was full."));
            }
            int calculated_tail = (this->head + this->size) % this->capacity;
            this-> arr[calculated_tail] = c;
            this->size += 1; 
        }

        

        /* Rimuove l'elemento in head e lo ritorna
                      
               - Se la queue è vuota, lancia un std::runtime_error
               - Complexity: O(1)
        */
        char dequeue() {
            cout << "DEBUG: enqueue" << endl;

            if (isEmpty()) {
                throw std::runtime_error(std::string("Attempted to enqueue but queue was full"));
            }
            char ret = this->arr[this->head];
            this->head = (this->head + 1) % this->capacity;
            this->size -= 1;
            return ret;
        }



        int get_arr() {
            return this->arr;
        }
      
   };
  
};
 
 
 
#endif // MY_CIRCULAR_QUEUE_H
