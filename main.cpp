#include <iostream>
#include <stdexcept>
#include "circular_queue.h"
 

using namespace std;


// Tail: è l'indice della prossima cella in cui si va a scrivere, quindi deve essere già stata letta.
//       Per calcolarne la posizione usiamo l'operatore modulo "%" con head e size  
// Head: Si posiziona sulla cella da leggere, successivamente libera la cella
// Capacity: grandezza della queuq
// Size: elementi ancora da leggere, deve essere sempre <= di capacità


int main() {
 
   cout << "Starting" << endl;

   my::CircularQueue q(7);   // capacity = 7
 
   cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
   q.enqueue('a');
   cout << "top of the queue: " << q.top() << endl;
   cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
   q.enqueue('b');
   cout << "top of the queue: " << q.top() << endl;
   q.enqueue('c');
   q.enqueue('d');
   q.enqueue('e');
   char x = q.dequeue();  // a
   cout << x << endl;   // a
   q.dequeue();   // b
   q.enqueue('f');
   q.enqueue('g');
   q.enqueue('h');
   q.enqueue('i');
   // coda piena
   try {     //Destroys the instance, deleting any dynamic attribute  
       q.enqueue('z');
   } catch (std::runtime_error& ex) {
       cout << "something bad happened!" << ex.what() << endl;
       cout << "I caught the exception, will continue" << endl;
   };

   q.dequeue();  // c
   q.dequeue();  // d
   q.dequeue();  // e
   q.dequeue();  // f
   q.dequeue();  // g
   q.dequeue();  // h
   cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
   q.dequeue();  // i
 
   cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
   try {
       q.dequeue();
   } catch (std::runtime_error& ex) {
       cout << "something bad happened!" << ex.what() << endl;
       cout << "I caught the exception, will continue" << endl;
   };
 
   cout << "end of the program!" << endl;


{
    my::CircularQueue q2(9);  // Nuova coda di dimensione 9
    cout << "Ciao" << endl;
}

    cout << "dopo blocco" << endl;

    cout << "end of the program!" << endl;


   return 0;
}
