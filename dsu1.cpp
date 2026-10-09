// Problem Link - https://www.codechef.com/learn/course/trees/TREESPRO/problems/NODESDIST
/* By Shubham Anand */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}


class union_find{

        vector<vector<int>> lists;
        vector<int> loc;
        int n;

    public:
        union_find(int nval){
            n=nval;
            // lists.resize(n+1,vector<int>{}); same thing
            lists.resize(n+1);
            loc.resize(n+1);
            for(int i=1;i<=n;i++){
                loc[i]=i;
                lists[i]={i};
            }

        }


        bool find(int a, int b){
            return loc[a]==loc[b];
        }



        void un(int a, int b){
            if(loc[a]==loc[b]){
                return ;
            }

            if(lists[loc[a]].size()>lists[loc[b]].size())
                swap(a,b);

            int ia=loc[a];
            int ib=loc[b];

            while(lists[ia].size()>0){
                int nm=lists[ia].back();
                lists[ia].pop_back();
                lists[ib].push_back(nm);
                loc[nm]=ib;
            }
        }
};





int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

    union_find dsu(9);

    cout<<dsu.find(4,5)<<endl;
    dsu.un(4,5);
    cout<<dsu.find(4,5)<<endl;
    dsu.un(4,9);
    dsu.un(1,9);
    cout<<dsu.find(2,4)<<endl;




   



	




	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

