int parent(int val){
    return (val-1)/2;
}
int right(int val){return 2*val+2;}
int left(int val){return 2*val+1;}
/*we assume we have a class with array, size and capacity*/
//min heap in every example
void insert(int val){  
   if(size==cap){return;}
   size++;
   a[size-1]=val;
   for(int i=size-1;i>0 && a[parent(i)]>a[i]){
       swap(a[parent(i)],a[i]);
       i=parent(i);
   }
}
//deacrease key
int decrease(int i,int x){
    a[i]=x;
    while(i!=0 && a[parent(i)]>a[i]){
        swap(a[i],a[parent(i)]);
        i=parent(i);
    }
}

//heapify
void heapify(int i){
    int lt=left(i);
    int rt=right(i);
    int sm=i;
    if(lt<size && a[lt]<a[sm]){sm=lt;}
    if(rt<size && a[rt]<a[sm]){sm=rt;}
    if(sm!=i){
        swap(a[i],a[sm]);
        heapify(sm);
    }
}
//Extract
int extract(){
    if(size==0){return INT_MAX;}
    if(size==1){size--; return a[0];}
    swap(a[0],a[size-1]);
    size--;
    heapify(0);
    return a[size];
}
//delete
decrease(i,INT_MIN);
extract();

//Build Heap
//we need to access last nodes parent that mean last node= (size-1) now its parent is ((size-1)-1)/2;

for(int i=((size-2)/2);i>=0; i--){
   heapify(i);
}