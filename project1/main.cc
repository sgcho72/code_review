#include <iostream>
#include <cstdlib>
#include "priority_queue.h"
#include "custom_enum.h"

using namespace std;

template <typename T>
void pushQueue(templatePriorityQueue<T>* Que, int data){
	cout << "[+] Integer "<< data <<" pushed in the Priority Queue." << endl;
	Que->push(data);
}

template<typename T>
void popQueue(templatePriorityQueue<T>* Que){
	cout << "[+] Integer "<< Que->top() << " will be poped from the Priority Queue." << endl;
	Que->pop();
}

int main(int argc, char* argv[]){
	templatePriorityQueue<int> priQueue;
	int customNumber = 0;


	// push
	pushQueue(&priQueue,BAD_CUSTOMER );
	pushQueue(&priQueue,SUPER_CUSTOMER);
	pushQueue(&priQueue,GOOD_CUSTOMER );

	if( argc > 1 ){
		customNumber = atoi(argv[1]);
		if( customNumber > MIN_VAL_CUSTOMER && customNumber < MAX_VAL_CUSTOMER ){
			pushQueue(&priQueue,customNumber);
		}
		else{
			pushQueue(&priQueue, UNKNOWN_CUSTOMER);
		}
	}
	else{
		pushQueue(&priQueue,UNKNOWN_CUSTOMER);
	}

	//empty & size
	if(priQueue.empty()){
		cout << "[-] Priority Queue is empty. - Push method did not work!" << endl;
		return -1;
	}
	else{
		cout << "[+] Priority Queue has data. - Queue Size : " << priQueue.size() <<endl;
	}

	// pop twice
	popQueue(&priQueue);
	popQueue(&priQueue);

	cout << "[+] Now, Top element of Priority Queue is " << priQueue.top() << endl;
	
	return 0;
}
