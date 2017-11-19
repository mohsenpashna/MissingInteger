#include <iostream>
#include<vector>

using namespace std;
vector<int> A = {1,2,3};

unsigned int solution(vector<int>);
unsigned int sum(vector<int>);
unsigned int max(vector<int>);
void print_vec(vector<int>);
int main() {

//    std::cout << "Hello, World!" << std::endl;
    cout <<solution(A) << endl;
    return 0;
}

unsigned int solution(vector<int> A){
    bool execution_flag = false;
int s = A.size();
int m = max(A);
vector<int> Count (m,0);
Count[0]=1;
    for (int i = 0; i < s; ++i) {
        if(A[i]>0){
            execution_flag = true;
            Count[A[i]]=1;
        }
    }
    unsigned int CS = Count.size();
    for (int j = 1; j < CS; ++j) {
        if(Count[j]==0){
            return j;
        }
    }
    print_vec(Count);
    if(!execution_flag) return 1;
    if(sum(Count)==CS){
        return CS+1;
    }
    return 1;
}

unsigned int sum(vector<int> A){
    unsigned int s =A.size();
    unsigned int SUM = 0;
    for (int i = 0; i < s; ++i) {
        SUM +=A[i];
    }
    return SUM;
}

unsigned int max(vector<int> A){
    int s = A.size();
    int MAX =0;
    for (int i = 0; i < s; ++i) {
        if (MAX<A[i]) MAX = A[i];
    }
    if(MAX>0) return MAX;
    else return 1;
}

void print_vec(vector<int> A){
    unsigned int s =A.size();
//    unsigned int SUM = 0;
    for (int i = 0; i < s; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}