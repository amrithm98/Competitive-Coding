#include <bits/stdc++.h>
using namespace std;
 
 
 
class subgroup{
public:
	long long productivity;
	vector<long long> employees;
};
 
class testcase{
public:
	long long n,m;
	vector<subgroup> groups;
};
 
long long get_time(){
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
 
long long randint(long long min, long long max){
	static mt19937 mt(get_time());
	uniform_int_distribution<long long> dist(min,max);
	return dist(mt);
}
 
testcase random_tc(){
	testcase tc;
	tc.n = randint(2,10); //random n
	tc.m = randint(1,20); //random m
 
	for(long long i=0; i<tc.m; i++){
		subgroup g;
		g.productivity = randint(1,1000); //random group productivity
 
		unordered_set<long long> groupset;
 
		unsigned groupsize = randint(2,3);  //random group size (2 or 3)
		if(tc.n == 2){groupsize = 2;}
 
		while(groupset.size() < groupsize){
			groupset.insert(randint(1,tc.n));  //random employee selection
		}
		for(long long guy : groupset){
			g.employees.push_back(guy);
		}
		tc.groups.push_back(g);
	}
	return tc;
}
 
long long brute_force(testcase tc){
	vector<long long> groups;
	vector<long long> group_prod;
	for(subgroup group : tc.groups){
		group_prod.push_back(group.productivity);
		long long mask = 0;
		for(long long guy : group.employees){
			mask |= (1<<(guy-1));
		}
		groups.push_back(mask);
	}
 
	long long best_prod = 0;
	for(long long mask=1; mask<(1<<(tc.n-1)); mask++)
    {
		long long productivity = 0;
		for(unsigned i=0; i<groups.size();i++)
        {
			long long g = groups[i];
			if(((g & mask) == 0) || ((g & mask) == g)){
				productivity += group_prod[i];
			}
            cout << "\nProd : " << groups[i] << " " << productivity << endl;
		}
		best_prod = max(best_prod, productivity);
	}
	return best_prod;
}
 
long long main()
{
    testcase tc;    
    cin >> tc.n >> tc.m;

    for(long long i = 0; i < tc.m; i++)
    {
        subgroup sg;
        long long s,val;
        cin >> s >> val;
        sg.productivity = val;
        for(long long j = 0; j < s; j++)
        {
            long long x;
            cin >> x;
            sg.employees.push_back(x);
        }
        tc.groups.push_back(sg);
    }

    cout << brute_force(tc) << endl;

	return 0;
}