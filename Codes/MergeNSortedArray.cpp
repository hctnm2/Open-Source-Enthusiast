#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    vector<int> a;
    vector<int>::iterator it;
    int e;
    
    while(t--) {
        while(cin >> e) {
            a.push_back(e);   
            
            sort(a.begin(), a.end());
            it = unique(a.begin(), a.end());
            a.resize(distance(a.begin(), it));
            
            if(cin.get() == '\n')
                break;
        }    
    }
    for(int i = 0; i < a.size(); i++) {
        cout << a.at(i) << " ";
    }    
    
    return 0;
}