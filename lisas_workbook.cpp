#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    vector<int> questions(n);
    int n_pages=0;
    for(int i=0;i<n;i++)
    {
        cin>>questions[i];
        int temp=(questions[i]/k);
        if(temp>=0)
            n_pages+=temp;
        if(questions[i]%k>0)
            n_pages+=1;
    }
    vector<int> ques_per_page(n_pages);
    vector<int> first_ques_nos(n_pages);
    int q_count=0;
    for(int i=0;i<n;i++)
    {
        int page_count=0,j;
        int temp=(questions[i]/k);
        int rem=questions[i]%k;
        for(j=0;j<temp;j++)
        {
            ques_per_page[q_count]=(k);
            first_ques_nos[q_count]=j*k+1;
            q_count++;
        }
        if(rem!=0)
        {
            ques_per_page[q_count]=(rem);
            first_ques_nos[q_count]=j*k+1;
            q_count++;
        }
    }
    int special_problem=0;
    for(int i=0;i<n_pages;i++)
    {
        int page_no=i+1;
        int max_question=first_ques_nos[i]+ques_per_page[i]-1;
        if(first_ques_nos[i]<=page_no && page_no<=max_question)
            special_problem++;

    }
    cout<<special_problem;
    return 0;
}
