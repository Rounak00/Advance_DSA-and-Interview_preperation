// given a start and goal number nw to convert how many bits need to flip 

int main(){
  int start=13, goal=23;
  //if we xor both so it will give non macthed as 1 and then just count those 

  int ans=start^goal;
  int cnt=0;
  for(int i=0;i<31;i++){
    if(ans&(1<<i)){
      cnt++;
    }
  }
  return cnt;

}