/////////////////////////////////
// Date:       2010-05-19
// Author:     Yishi Guo
// Referrence: http://blog.myspace.cn/e/402403862.htm
/////////////////////////////////
#include <iostream>
#include <queue>

using namespace std;

struct work {
    friend bool operator<( work wk1, work wk2 ) {
        return wk1.priority < wk2.priority;
    }
    int priority;
    int value;
};

void print_work ( work wk ) {
    cout << "Priority: " << wk.priority << endl;
    cout << "Value:    " << wk.value << endl;
}

void print_queue( priority_queue<work> pq ) {
    priority_queue<work> temp = pq;
    while ( !temp.empty() ) {
        print_work( temp.top() );
        temp.pop();
    }
}

int main() {
    priority_queue<work> pq;
    for ( int i = 0; i < 10; ++i ) {
        work wk;
        wk.priority = i;
        wk.value = i*2;
        pq.push( wk );
    }
    print_queue( pq );

    return 0;
}
