//
// NPR= (n!)/ (n-r)!

solve(vector<int> box, int fi, int ri ) // guess here 1 and 2 two elements, fi-first items, ri-riten items
{
    if(fi<=ri){
        for(int i=0;i<box.size();i++){
            if(box[i]==0){
                box[i]=fi;
                solve(box,fi+1,ri);
                box[i]=0;
            }
        }
    }
    else{
        print(box);
    }
}
