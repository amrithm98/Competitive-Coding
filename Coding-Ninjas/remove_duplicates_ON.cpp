#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


vector<int> removeDuplicates(vector<int> input){

    // Write your code here
  unordered_map<int,int> visited;
  vector<int> result;
  for(int i=0;i<input.size();i++)
  {
      if(visited[input[i]]==0)
      {
          result.push_back(input[i]);
          visited[input[i]]=1;
      }
  }
  return result;
}


int main()
{
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++)
        cin>>input[i];
    vector<int> output=removeDuplicates(input);
    cout<<"\nOUTPUT";
    for(int i=0;i<output.size();i++)
        cout<<output[i]<<"\n";
}