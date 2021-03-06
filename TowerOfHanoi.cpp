#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    vector<int> t[3]; // 3 towers (A,B,C)

    int n, candidate = 1, to, from = 0, move = 0;
    cout << "Please enter a number of rings to move: ";
    cin >> n;
    cout << endl;
    
    // Intitializes the 3 towers
    for(int i = n+1; i >= 1; i--)
        t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);
    
    // The initial value of "to" depends on whether n is odd or even
    if((n%2) == 1)
        to = 1;
    else
        to = 2;
    
    while(t[1].size() < n+1) {  // while t[1] does not contain all of the rings
        // Moves the ring from the "from tower" to the "to tower"
        t[to].push_back(t[from].back()); // gets the last element from "from" and pushes it to "to" 
        t[from].pop_back(); // removes the ring from "from"
        cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from+65) << " to tower " << char(to+65) << endl;
        
        if(n%2 == 1 ) { // Odd number of rings
            // from = the index of the tower with the smallest ring that has not just been moved
            if(t[(to+1)%3].back() < t[(to+2)%3].back())
                from = (to+1)%3;
            else
                from = (to+2)%3;
            
            // to = the index of the closest tower on which the candidate can be placed
            if(t[(from)].back() < t[(from+1)%3].back())
                to = (from+1)%3;
            else
                to = (from+2)%3;
            // Gets the next candidate. Candidate = the ring on top of the "from" tower
            candidate = (t[from].back());
        }
        else { // Even number of rings
            if(t[(to+1)%3].back() < t[(to+2)%3].back())
                from = (to+1)%3;
            else
                from = (to+2)%3;

            if(t[(from)].back() < t[(from+2)%3].back())
                to = (from+2)%3;
            else
                to = (from+1)%3;
            // Gets the next candidate
            candidate=(t[from].back());
        }
    }
    return 0;
}
