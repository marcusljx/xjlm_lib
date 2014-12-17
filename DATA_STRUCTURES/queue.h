#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <vector>

using namespace std;

class Queue {
	private:
		vector<int> 		queue_int;
		vector<void*> 	queue_pointer;
		vector<string>	queue_string;
	
	public:
		Queue();
		~Queue();
	
		void enqueue(int);
		void enqueue(void*);
		void enqueue(string);
		
		int 		dequeue();
		void*		dequeue();
		string	dequeue();
};

#endif