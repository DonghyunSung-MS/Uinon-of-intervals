#include <stdio.h>


const int MAX=10000;
int n;
double i;
int bounds[MAX][2];

double check(int point,int arr[][2],double target){
  double index=0;
  for(int k=0;k<n;k++){
    //e값이 mid 작으면 , 5면 4까지
    if(arr[k][1]<point) index+=arr[k][1]-arr[k][0]+1;
    //s값보다 크고 e보다 작을때
    else if(arr[k][0]<point&&arr[k][1]>=point) index+=point-arr[k][0];
  }
  return index;
}

void BS(int s,int e,int arr[][2],double target){
  if(s>e) return;
  else{
    int mid=(s+e)/2;
    double inx=check(mid,arr,target);
    //check left or right.
    if(target<inx)  BS(s,mid-1,arr,target);
    else if(target==inx){
      printf("%d",mid);
      return;//끝끝.
    }
    else{
      if(target<check(mid+1,arr,target)){
        printf("%d",mid);
        return;
      }
      else{
        BS(mid+1,e,arr,target);
      }
    }
    
    
  }
  // 0    ~ ~ ~ ~ ~ ~ maxslen
  // min               max
  // mid=(min+max)/2;--> 넌 몇번째니
  // 
  // mid가 i 번째 보다 작으면 min~~mid-1
  // ex) i=10일때,  mid=5 일때 경계가 8 mid+1 일때 9 그럼 mid+2 체크 12면
  // e=10    mid=7 12
  // mid+1 이 원하는 수
}

int main() {
  //3       n
  //1 3
  //2 10
  //1 8
  //5       i

  double maxslen=0;//S이 총길이
  int min=1000000000;
  int max=0;
  //inputs
  scanf("%d",&n);
  for(int k=0;k<n;k++){
    scanf("%d %d",&bounds[k][0],&bounds[k][1]); //[0]-> s값 [1]->e값
    maxslen+=bounds[k][1]-bounds[k][0]+1;
    if(min>bounds[k][0]) min=bounds[k][0];
    if(max<bounds[k][1]) max=bounds[k][1];
  }
  scanf("%lf",&i);
  //i가 전체 길이로 주어지면 끝
  if(i==maxslen-1){
    printf("%d",max);
    return 0;
  }
  //i 가 첫번째로 주어지면 끝-> 문제 조건에 1보다 크다고해서 무의미.
  //printf("max: %d min: %d maxslen: %lf\n",max,min,maxslen);
  
  
  //binary search
  BS(min,max,bounds,i);


  //Please Enter Your Code Here

  return 0;
}
