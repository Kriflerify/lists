#include "queue.h"
#include <iostream>
#include <indicators/progress_bar.hpp>
#include <thread>
#include <chrono>


using namespace std;

int LEN = 100;

int nextnumber(int i, int* trio) {
    int candidate = i-1==0? LEN : i-1;
    while (candidate == trio[0] || candidate==trio[1] || candidate==trio[2] || candidate==i){
        candidate = candidate-1==0? LEN : candidate-1;
    }
    return candidate;
}

int main() {
    
	Queue<int> q;
	
    int start [LEN];
	for (int i=0; i<100; i++) {
		start[i] = i+1;
	}

	q.insert(start, LEN);

    cout << q << endl;

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
    Node<int>* prev; 
    Node<int>* curn = q.getroot()->prev; 
    int trio [3];
    Node<int>* trion [3];
    int tar;
    Node<int>* tarn;
    for (int i=0; i<100; i++) {
        //for (int j=0; j<100000; j++) {
            prev = curn;
            curn = prev->next;
            cur = curn->value;
            trion[0] = curn->next;
            for (int l=1; l<3; l++)
                trion[l] = trion[l-1]->next;
            for (int l=0; l<3; l++)
                trio[l] = trion[l]->value;
            //q.remove(curn);
            q.remove(trion[0]);
            q.remove(trion[1]);
            q.remove(trion[2]);
    
            tar = nextnumber(cur, trio);

            tarn = q.find(tar);

                cout << "HI" << endl;
            q.insert(trio, 3, tarn);
            //q.insert(cur, prev);
        //}
        bar.tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
            cout << q << endl;
	}

	return 0;

}
