 /*
 build and update range is o(n)
 update node and query is(log n)
 */
 
 void buildtree(int tree[], int a[], int s, int e, int id){
     //base but corner case
     if(s>e){return;}
     //Base Case -> if node is leaf
     if(s==e){tree[id]=a[s]; return;}
     
    //Recursion body
     int mid=(s+e)/2;
     //left subtree
     buildtree(tree,a,s,mid,2*id);
     //right subtree
     buildtree(tree,a,mid+1,e,id*2+1);
     
     //own computation
     int left=tree[2*id];
     int right=tree[2*id+1];
     
     tree[id]=min(left,right);
 }
void updatenode(int tree[], int id, int s, int e, int i, int val){
    if(i<s || i>e){return ;}
    if(s==e){tree[id]=val; return;}
    
    int mid=(s+e)/2;
    updatenode(tree,id*2,s,mid,i,val);
    updatenode(tree,id*2+1,mid+1,e,i,val);
    tree[id]= min(tree[id*2],tree[id*2+1]);
    return;
}
void updaterange(int *tree,int index,int s,int e,int rs,int re,int inc){
		//Out of Bounds
		if(re<s || rs>e){
			return;
		}
		//Leaf nodes
		if(s==e){
			tree[index] += inc;
			return;
		}

		//Rec Case
		int mid = (s+e)/2;
		updaterange(tree,2*index,s,mid,rs,re,inc);
		updaterange(tree,2*index+1,mid+1,e,rs,re,inc);
		tree[index] = min(tree[2*index],tree[2*index+1]);
		return;

}
int query(int tree[],int id,int s,int e,int qs,int qe){
    //no overlap
    if(qs>e || qe<s){return INT_MAX;}
    //complete overlap
    if(s>=qs && e<=qe){return tree[id];}
    //Partial overlapping
    int mid=(s+e)/2;
    int left=query(tree,2*id,s,mid,qs,qe);
    int right=query(tree,2*id+1,mid+1,e,qs,qe);    
     return min(left,right);   
}

int main() {
    int a[]={1,8,-2,5,6};
    int n=sizeof(a)/sizeof(int);
    
    
//     //build tree array
    int tree[4*n-1];
    buildtree(tree,a,0,n-1,1);
    
  
    cout<<query(tree,1,0,n-1,0,2)<<" ";
      updatenode(tree,1,0,n-1,2,4);
    cout<<query(tree,1,0,n-1,0,n-1)<<" ";
    
    updaterange(tree,1,0,n-1,0,1,3);
    cout<<query(tree,1,0,n-1,0,n-1)<<" ";
    
    
    
    
}