#define MAX 100002
class coder{
public:
    int x,y,index;
};
bool compare(coder a, coder b){
    if(a.x==b.x){return b.y>a.y;}
    return b.x>a.x;
}
void update(int y,int* BIT){
    for(;y<=MAX;y+=(y&(-y))){
        BIT[y]++;
    }
}
int query(int y,int* BIT){// this query gives us the coder rating
    int count=0;
    for(;y>0;y-=(y&(-y))){
        count+=BIT[y];
    }
    return count;
}
int main(){
    int n;cin>>n;
    coder* arr=new coder[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
        arr[i].index=i;
    }
    sort(arr,arr+n,compare);
    int* BIT=new int[MAX]();
    int* ans=new int[n];// coder ratings of oringla indexes
    for(int i=0;i<n;){
        int endIndex=i;
        while(endIndex<n && arr[i].x==arr[endIndex].x
              && arr[i].y==arr[endIndex].y){
            endIndex++;
        }
        for(int j=i;j<endIndex;j++){
            ans[arr[j].index]=query(arr[j].y,BIT);
        }
        for(int j=i;j<endIndex;j++){
            update(arr[j].y,BIT);
        }   
        i=endIndex;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }   
    return 0;
}