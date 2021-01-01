#include "queue.h"
#include <iostream>
#include <indicators/progress_bar.hpp>
#include <thread>
#include <chrono>


using namespace std;

int nextnumber(int i, int* trio) {
    int candidate = i-1==0? 1000000 : i-1;
    while (candidate == trio[0] || candidate==trio[1] || candidate==trio[2]){
        candidate = candidate-1==0? 1000000 : candidate-1;
    }
    return candidate;
}

int main() {
    
	Queue<int> q;
	
	int start [1000000] = {1, 5, 7, 6, 2, 3, 9, 8, 4};

	for (int i=10; i<=1000000; i++) {
		start[i-1] = i;
	}

	q.insert(start, 1000000);

  indicators::ProgressBar bar{
    indicators::option::BarWidth{50},
    indicators::option::Start{"["},
    indicators::option::Fill{"="},
    indicators::option::Lead{">"},
    indicators::option::Remainder{"."},
    indicators::option::End{"]"},
    indicators::option::PostfixText{"Steps"},
    indicators::option::ForegroundColor{indicators::Color::green},
    indicators::option::FontStyles{std::vector<indicators::FontStyle>{indicators::FontStyle::bold}}
  };

  
    int cur;
    Node<int>* prev = q.getroot()->prev; 
    Node<int>* curn = q.getroot()->prev; 
    int trio [3];
    Node<int>* trion [3];
    int tar;
    Node<int>* tarn;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100000; j++) {
            prev = curn;
            curn = prev->next;
            cur = curn->value;
            trion[0] = curn->next;
            for (int l=1; l<3; l++)
                trion[l] = trion[l-1]->next;
            for (int l=0; l<3; l++)
                trio[l] = trion[l]->value;
            q.remove(curn);
            q.remove(trion[0]);
            q.remove(trion[1]);
            q.remove(trion[2]);
    
            tar = nextnumber(cur, trio);

            tarn = q.find(tar);

            q.insert(trio, 3, tarn);
            q.insert(cur, prev);
        }
        bar.tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return 0;

}
