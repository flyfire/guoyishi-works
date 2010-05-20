//////////////////////////////
// Date:     2010-05-19
// Modified: 2010-05-20
// Author:   Yishi Guo
// About:    Operating System
//////////////////////////////
#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int max_pri = 0;

struct work {
    string name;
    int arr_time;
    int want_run_time;
    int run_time;
    int priority;
    bool is_fin;
    friend bool operator<( work wk1, work wk2 ) {
        return wk1.priority > wk2.priority;
    }
};

void print_line( bool bReturn = true ) {
    cout << "----------------------------"
         << ( bReturn ? "\n" : "" );
}

void print_work( work wk ) {
    print_line();
    cout << "Name:          " << wk.name << endl;
    cout << "Arrive time:   " << wk.arr_time << endl;
    cout << "Want run time: " << wk.want_run_time << endl;
    cout << "Run time:      " << wk.run_time << endl;
    cout << "Priority:      " << wk.priority << endl;
    cout << "Is finished:   " << (wk.is_fin ? "TRUE" : "FALSE") << endl;
    print_line();
}

void print_work_line( work wk, string str = "" ) {
    cout << wk.name << "\t"
         << wk.arr_time << "\t"
         << wk.want_run_time << "\t"
         << wk.run_time << "\t"
         << wk.priority << "\t"
         << ( wk.is_fin ? "TRUE " : "FALSE" )
         << ( str.empty() ? "" : " << " + str )
         << endl;
}

int get_rand_time( int max ) {
    static int addValue;
    srand( time(NULL) + addValue++ );
    return rand()%max+1;
}

template< class T>
void print_queue( priority_queue<T> pq ) {
    priority_queue<T> temp = pq;
    while ( !temp.empty() ) {
        print_work_line( temp.top() );
        temp.pop();
    }
    return;
}

void print_vector( vector<work> wks ) {
    cout << "NAME" << "\t"
         << "ARR" << "\t"
         << "WANT" << "\t"
         << "RUN" << "\t"
         << "PRI" << "\t"
         << "FIN?" << "\t"
         << endl;
    for ( int i = 0; i < wks.size(); ++i ) {
        print_work_line( wks[i] );
    }
    return;
}

void new_insert( vector<work>& vec, priority_queue<work>& pq, int time ) {
    for ( int i = 0; i < vec.size(); ++i ) {
        if ( vec[i].arr_time <= time && vec[i].run_time == -1 ) {
            vec[i].run_time = 0;
            vec[i].priority = ++max_pri;
            pq.push( vec[i] );
            print_work_line( vec[i], "ADD" );
            print_line();
        }
    }
    return;
}

bool have_next( vector<work> vec ) {
    for ( int i = 0; i < vec.size(); ++i ) {
        if ( vec[i].run_time == -1 ) {
            return true;
        }
    }
    return false;
}

int max_priority( priority_queue<work> pq ) {
    int max = 0;
    while ( !pq.empty() ) {
        if ( pq.top().priority > max ) {
            max = pq.top().priority;
        }
        pq.pop();
    }
    return max;
}

int main() {
    vector<work> vec;
    int worksCount;
    cout << "Input number of work:" << endl;
    cin >> worksCount;
    for ( int i = 0; i < worksCount; ++i ) {
        work wk;
        cout << "#" << (i+1) << ":" << endl;
        cout << "Name: ";
        cin >> wk.name;
        cout << "Arrive time: ";
        cin >> wk.arr_time;
        wk.priority = -1;
        wk.want_run_time = get_rand_time(10);
        wk.run_time = -1;
        wk.is_fin = false;
        vec.push_back( wk );
    }

    print_vector( vec );
    
    priority_queue<work> works;
    for ( int time = 0; ; ++time ) {
        cout << "++++ TIME: " << time 
             << " ++++++++++++++++++++++++++++++++" << endl;
        max_pri = max_priority( works );
        // cout << "Max Pri: " << max_pri << endl;

        new_insert( vec, works, time );
        if ( !works.empty() ) {
            work top = works.top();
            print_work_line( top, "RUN" );
            print_line();
            top.run_time++;
            top.priority += 2;
            if ( top.run_time == top.want_run_time ) {
                top.is_fin = true;
                print_work_line( top, "FINISH!" );
                print_line();
                works.pop();
            } else {
                works.pop();
                works.push( top );
            }
        }
        print_queue( works );

        if ( !have_next(vec) && works.empty() ) {
            cout << "ALL FINISHED!" << endl;
            break;
        }
    }

    return 0;
}
