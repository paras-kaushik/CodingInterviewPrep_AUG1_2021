
#include<iostream>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
#include<string>
#include<climits>
#include<vector>
#include<unordered_set>
#include<cmath>
#include<utility>
#include<bitset>
typedef unsigned long long  ull;
typedef long long ll;
#define MOD 1000000007
using namespace std;
int minSwaps(vector<int>&nums)
{
    int n=nums.size();
    pair<int,int>* originalPositions=new pair<int, int>[n];
    for(int i=0;i<n;i++){
        originalPositions[i].first=nums[i];
        originalPositions[i].second=i;
    }
    sort(originalPositions, originalPositions+n);
    int count =0;
    unordered_set<int> indexesCoveredByCycle;
    for(int i=0;i<n;i++){
        if(indexesCoveredByCycle.count(i)>0)continue;
        int valueprovidingIndex=originalPositions[i].second;
        if(valueprovidingIndex!=i){ //3!=1
            unordered_set<int> cylicIndexes;
            cylicIndexes.insert(i);//1
            indexesCoveredByCycle.insert(i);
            while(cylicIndexes.count(valueprovidingIndex)==0){//3 not present,2 not present,4 not present, 1 present
                cylicIndexes.insert(valueprovidingIndex); //{1 ,3},{1 ,3,2}, {1 ,3,2,4}
                indexesCoveredByCycle.insert(valueprovidingIndex);
                valueprovidingIndex=originalPositions[valueprovidingIndex].second;//2,4,1
            }
            count+=cylicIndexes.size()-1;
        }
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
