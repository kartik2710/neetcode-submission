class Node
{
   public:
   int data, key;
   Node *next, *prev;

   Node(int key, int data)
   {
      this->key=key;
      this->data=data;
      this->next=nullptr;
       this->prev=nullptr;

   }
};

class LRUCache {
public:
   
   Node *head, *tail;
   unordered_map<int, Node *> mp;
   int capacity=0;
    LRUCache(int cap) {

      head= new Node(-1,-1);
      tail= new Node(-1,-1);

      head->next=tail;
      tail->prev=head;
      capacity=cap;
       
    } 
    void replace(Node *curr)
    {
      Node *previous=curr->prev;
      Node *next=curr->next;
      previous->next=next;
      next->prev=previous;

      
    }

    void insert( Node *curr)
    {
      curr->next=head->next;
      head->next->prev=curr;
      head->next=curr;
      curr->prev=head;
    }
    
    int get(int key)
    {
       if(mp.find(key)==mp.end()) return -1;

       int ans=mp[key]->data;
       replace(mp[key]);
       insert(mp[key]);
       return ans;
     
    }

    
   void dell()
   {
      Node *curr=tail->prev;
      Node *previous=curr->prev;
      previous->next=tail;
      tail->prev=previous;

      mp.erase(curr->key);
   }
    
    void put(int key, int value) {

      if(mp.find(key)!=mp.end())
      {
         mp[key]->data=value;
          replace(mp[key]);
          insert(mp[key]);
          return ;
      }

       Node *t= new Node(key,value);
       mp[key]=t;
        insert(mp[key]);

       if(mp.size()>capacity)
       {
         dell();
       }

      

        
    }
};
