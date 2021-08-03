https://whimsical.com/c-stl-XVxuHHof5GTWA4NXZhXQhx
for brief intro
STL: 1.Algorithms    2.Containers

1. Algorithms =>
            a. linear search
            b. sort 
            c. min / max 
            d. lower/upper bound
            e. reverse/rotate
            f. swap

2. Containers =>
        a. sequence container: 
                   i> array
                   ii>vector
                   iii>dequeue
                   iv>list 
                   v>forward list #

        b. Containers adaptors :
                    i> stack
                    ii>queue
                    iii>priority queue

        c. Associate container :
                    i>set 
                    ii>map
                    iii>multi set #
                    iv> multi map #  

        d. Unorder associate :
                      i> unorder set / map
                      ii> unorder multi set/ multi map  #

    // '#' are no need or use very very rare cases

2.a.i> Array (mainly dont use bcz it is static):-  #include<array>
                     intialize: array<datatype,size>name={elements};
               array.size() :return size
               array.at(2) : 2 index a dekhabe normal []-use kora jay
               array.empty(): return boolean value
               array.front(): first element 
               array.back():last eleemnt 

2.a.ii> vector(it is dynamic,size always incease 2x) :- #include<vector>
                 intialize: vector<int> vector_name;
                            vector<int> vector_name2(vector_name1); 2 is a copy of 1  
                            vector<int> vetor_name(5,1): inthat case size 5 and each elements are 1
               vector.size(): base on how many elements 
               vector.capacity(): base on how many memory allocate
               vector.push_back(): push in back
               vector.pop_back(): pop from last
               vector.clear(): only size 0 not capacity
     at(), empty(), front(), back() also work

2.a.iii> Deque [double ended queue] (dynamic):- #include<deque>
                     intialize: deque<datatype>name;   
                name.push_back(element): use for back
                name.push_front(element): use for front
                name.pop_back(element): use for back
                name.pop_front(element): use for front   
                someothers are erase(),begin(),end() - add later those are use iterators just like
                 deque<datatype>::iterator iterator_name= deque.begin();

                at(), empty(), front(), back() all are here         

2.a.iv> List [use doubly linked list] (direct access not possible):- #include<list>
                              intialize: list<datatype>list_name; 
                                         list<int>list_name(5,1):inthat case size 5 and each elements are 1
size(), empty(), front(), back(), erase(), begin(), end(), push_back(), pop_back(), push_front(), pop_front()                                 
                                          
2.b.i> stack[lifo] (dynamic) :- #include<stack>
                                initialize: stack<datatype>stack_name
                            stack.push(): last element pushed
                            stack.pop(): last element poped
                            stack.top(): top element 
             empty(), size() 

2.b.ii> Queue[fifo] (dyanamic):- #include<queue>
                            initialize: queue<datatype>queue_name
                       queue.push(): last element pushed
                       queue.pop(): first element poped
        empty(), size(), front()       

2.b.iii> Priority Queue[max/min-heap type] (dyanamic):- #include<queue>  
       //after push values are store according priority
                  initialize: priority_queue<datatype>priorityqueue_name //max heap
                  priority_queue<datatype,vector<datatype>,greater<datatype>>priorityqueue_name //min heap

                  push() : normal
                  pop() : greter element for max heap and viceversa
                  top() : greter element for max heap and viceversa
                  empty(), size()


2.c.i> Set [ always store unique value, return sorted order, use BST, duplicate value never print] 
           (dynamic):-
           initialize: set<datatype>set_name
                       unorder_set<datatype>set_name
          set.insert(element): push element 
          set.erase(s.begin()+2): erase in that case index 2 or 3rd element delete
          set.count(element): return boolean if element present or not    
          set.find(element) : reference return so use * and use iterator 

        size(), empty()

2.c.ii>map [same key only point one , but multiple keys point same,use bst only for stl normally use hashtable 
                  it is normally ordered unlike unorder map] 
           (dynamic):- #include<map>
           initialize: map<int,string>map_name
                       unorder_map<int,string>map_name
              insertion:-
                   m[1]= "hanuman";
                   m[2]= "shiv";
                   m[13]="durga";   // here int is kay and string is value
                   m.insert({5,"laxmi"});
            for deletion we use erase(key);
             others functions are also work....   



1. Algorithms :- #include<algorithm>
 assume v for a random vector

 1.a> binarysearch: binary_search(v.begin(),v.end(),element): return boolean value

 1.b>max/min: max/min(elements,elements); : return max or min element
 
 1.c>swap : swap(a,b) : swap values between a and b
 
 1.d>reverse: reverse(a.begin(),a.end()) : asssume 'a' is a string 
 
 1.e>rotate: rotate(v.begin(),v.begin()+1,v.end()); :in that case if 'v' is 1367 then rotate is 3671
       // middle is the how many element you want to rotate
 
 1.f> sort: sort(v.begin(),v.end()) : return the sore vector
      // bydefault it is intro sort  the combination of quick sort, heap sort, insertion sort


