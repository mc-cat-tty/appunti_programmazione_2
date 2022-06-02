#include <iostream>

#include "queue.h"

using namespace std;

int main() {
    queue q = new_queue();
    
    enqueue(q, new_elem(1));
    enqueue(q, new_elem(2));
    enqueue(q, new_elem(3));
    enqueue(q, new_elem(4));

    cout << "First: " << first(q) << endl;
    cout << "Empty? " << is_empty_queue(q) << endl;

    cout << dequeue(q) << endl;
    cout << dequeue(q) << endl;
    cout << dequeue(q) << endl;
    cout << dequeue(q) << endl;

    cout << "Empty? " << is_empty_queue(q) << endl;

    return 0;
}