#include <iostream>
#include <vector>
#include <fstream>
#include <deque>
#include <algorithm>
 
using namespace std;
 
vector<vector<int> > g;
vector<bool>used;
vector<int>p;
int Cycle1, Cycle2;
 
int main() {
 
    ifstream cin("in.txt");
    ofstream cout("out.txt");
 
    int n;
    cin>>n;
    g.resize(n+1);
    used.resize(n+1, false);
    p.resize(n+1);
    Cycle1 = -1, Cycle2 = -1;
    for(int i=1;i<=n;++i){
        int x = 1;
        while(x != 0){
            cin >> x;
            if(x != 0){
                g[i].push_back(x);
            }
        }
    }
 
    deque<int>q;
    q.push_back(1);
    p[1] = -1;
    while(q.size() > 0){
        int v = q[0];
        used[v] = true;
        q.pop_front();
        for(int i=0;i<g[v].size();++i){
            int to = g[v][i];
            if(to != p[v]){
                if(used[to]){
                    Cycle1 = to;
                    Cycle2 = v;
                }
                else{
                    p[to] = v;
                    q.push_back(to);
                }
            }
        }
    }
 
 
    if(Cycle1 == -1){
        cout << "A\n";
        return 0;
    }
 
    vector<int>C1, C2;
    int d;
    d = Cycle1;
    while(d != -1){
        C1.push_back(d);
        d = p[d];
    }
    d = Cycle2;
    while(d != -1){
        C2.push_back(d);
        d = p[d];
    }
 
    int i1 = C1.size()-1;
    int i2 = C2.size()-1;
    while(C1[i1] == C2[i2]){
        --i1;
        --i2;
    }
    ++i1;
 
    vector<int> ans;
    for(int i=0;i<=i1;++i){
        ans.push_back(C1[i]);
    }
    for(int i=0;i<=i2;++i){
        ans.push_back(C2[i]);
    }
    sort(ans.begin(),ans.end());
 
    cout << "N\n";
    for(int i=0;i<ans.size();++i){
        cout << ans[i] << ' ';
    }
    cout << "\n";
 
}