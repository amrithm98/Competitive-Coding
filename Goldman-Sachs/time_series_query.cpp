#include <bits/stdc++.h>

using namespace std;

long searchInsert(vector<long>& nums, long target) {
        /// return index of first one that comp(item,target)==true, or nums.size() if not found
		/// comp is greater or equal to for lower_bound
		/// comp is greater for upper_bound
        long first=0, last=nums.size(), mid;
        while (first<last) {
            mid=first+((last-first)>>1); // first<=mid, mid<last
			/// if comp(item,target)==false, advance first
			// if(nums[mid]<=target) // for upper_bound
			if (nums[mid]<target) // for lower_bound
				first=mid+1; // first always increases
			else /// else recede last
				last=mid; // last always decreases (even last-first==1)
        }
        return first;
}

int main() 
{
    long n;
    long q;
    cin >> n >> q;
    long arr[2][n];
    vector<vector<long>> times(2,vector<long>(n));
    for(long t_i = 0; t_i < n; t_i++){
        cin >> times[0][t_i];
    }

    for(long p_i = 0; p_i < n; p_i++){
       cin >> times[1][p_i];
    }

    for(long a0 = 0; a0 < q; a0++){
        long _type;
        long v;
        long result;
        cin >> _type >> v;

        if(_type==1)
        {
             long val=-1;
            for(long i=0;i<n;i++)
            {   
                if(times[1][i]>=v)
                {
                    val=times[0][i];
                    break;
                }
            }
            if(val==-1)
                cout<< -1<<endl;
            else cout<<val<<endl;
        }
        else   
        {
                long val=0,pos=0,i=0,j=0;
                // i=(upper_bound(times[0].begin(),times[0].end(),v))-times[0].begin();
                i=searchInsert(times[0],v);
                // cout<<"I:"<<i<<"\n";
                if(i>=n || i<0)
                    cout<<-1<<endl;
                else
                {
                    long max=-1;
                    for(j=i;j<n;j++)
                    {
                        if(times[1][j]>max)
                        {
                            max=times[1][j];
                        }
                    }
                    if(max==-1)
                        cout<<-1<<endl;
                    else
                        cout<<max<<endl;
                }
        }
    }
    return 0;
}
