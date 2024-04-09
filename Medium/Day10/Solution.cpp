// Write Yoyur Code here

#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <queue>
#include <algorithm>
#define int long long
#define f first
#define s second
#include <set>
#define pb push_back
using namespace std;
typedef  pair<int,int> pii;
typedef pair<pii,int> piii;

signed main() {

ios_base::sync_with_stdio(false);
cin.tie(0);

int t;
t=1;
while(t--){
    int n,m,k;
cin >> n >> m >> k;

vector<pii> start[n+1];

for(int i=0;i<m;i++){
    int a,b;
    cin >> a>>b;
    if(a>b)
        swap(a,b);
    start[a].push_back({a,b});
    start[b].push_back({b,a});
}

    set<piii> st;
    for(int i=0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        st.insert({{a,b},c});
    }

     queue<pii>q;
     map<pii,pii> prev;

    for(auto it:start[1])
    q.push(it),prev[it]={-1,-1};


    int flag=0;
    pii fin;

    while(!q.empty()){
        pii cur=q.front();
        q.pop();
        if(cur.s==n){
            fin=cur;
            flag=1;
            break;
        }

        for(auto it:start[cur.s]){
            if(st.find({cur,it.s})!=st.end())
                continue;

            if(prev.find(it)!=prev.end())
            continue;
            prev[it]=cur;
            q.push(it);
        }
    }

         if(!flag){
            cout<<-1<<endl;
             continue;
          }


     vector<int> v;

     while(fin.f!=-1){
        v.push_back(fin.s);
        fin=prev[fin];
     }
     v.push_back(1);

     reverse(v.begin(),v.end());


        cout<<v.size()-1<<endl;
        for(auto it: v)
            cout<<it<<" ";
        cout<<endl;

       }
        return 0;
}
