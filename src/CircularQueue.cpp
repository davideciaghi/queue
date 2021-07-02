
#include "circular_queue.h"
#include <cmath>
#include "iostream"
 

  
        /** A circular queue of chars: i_Tail = head + size with a fixed capacity
        */


        /* Inizializzo la queue, riservando lo spazio per un numero di elementi oari alla capacità assegnata.

            - Allocare dinamincamente un array di caratteri
            - Se la capacità è <=0 lanciare un std::invalid_argument
            - Complessità : 0(capacity)

        */ 

        
        my::CircularQueue::CircularQueue(int capacity) {  // Costruttore
            if (capacity <= 0) {
                throw std::invalid_argument(std::string("Expected positive capacity, found instead: ") + std::to_string(capacity));
            }
            this->capacity = capacity;
            this->head = 0;
            this->size = 0;
            this->arr = new char[capacity]; // Crea un'array di caratteri di lunghezza capacity
        }


        /* Distruttore che distrugge ogni allocazione dinamica
        
           Viene chiamato al termine della circularQueue
        */
        my::CircularQueue::~CircularQueue() {
            std::cout << "DEBUG: chiamata distuttore CircularQueue" << std::endl;
            delete this->arr;
        }


        /* Return the capacity of the queue, that is, the maximum number of allowed elements in the queue.
                  
                   - Complexity: O(1)
        */   
        int my::CircularQueue::get_capacity() {
            return this->capacity;
        }


        /* Ritorna true se la queue è vuota, false altrimenti.
              
               - Complexity: O(1)
        */ 
        bool my::CircularQueue::isEmpty() {
            return this->size == 0; // Se size=0 la coda è vuota e ritorna TRUE
        }


        /* Ritorna l'elemento in head alla queue senza rimuoverlo
              
            - se la queue è vuota lancia std::runtime_error
            - Complexity: O(1)
                
        */
        char my::CircularQueue::top() {
            
            if (isEmpty()) {
                throw std::runtime_error("The queue is empty!");
            } else {
                return this->arr[this->head];
            }
        }

        
        /* Ritorna la size della queue.
              
            - Complexity: O(1)
        */ 
        int my::CircularQueue::get_size() {
            return this->size;
        }



        /* Inserisce il carattere dato nella cella con indice calculated_tail
              
            - Se la coda è piena lancia std::runtime_error
            - Complexity: O(1)
        */  
        void my::CircularQueue::enqueue(char c) {
            std::cout << "DEBUG: enqueueing char: " << c << std::endl;
            
            if (this->size == this->capacity) {
                throw std::runtime_error(std::string("Queue is full!"));
            } else {
                int calculated_tail = (this->head + this->size) % this->capacity;
                this-> arr[calculated_tail] = c;
                this->size += 1; 
            }
        }

        

        /* Rimuove l'elemento in head e lo ritorna
                      
               - Se la queue è vuota, lancia un std::runtime_error
               - Complexity: O(1)
        */
        char my::CircularQueue::dequeue() {
            std::cout << "DEBUG: dequeueing" << std::endl;

            if (isEmpty()) {
                throw std::runtime_error(std::string("Queue is empty!"));
            } else {
                char ret = this->arr[this->head];
                this->head = (this->head + 1) % this->capacity;
                this->size -= 1;
                return ret;
            }
        }
      
