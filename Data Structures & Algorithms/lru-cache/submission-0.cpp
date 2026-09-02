struct Node
{
    int key;
    int data;
    Node *prev;
    Node *next;

    Node(int key, int data)
    {
        this->key=key;
        this->data=data;
        this->prev=nullptr;
        this->next=nullptr;
    }
};
class LRUCache {
public:
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int,Node*> mp;

    LRUCache(int cap) {
        capacity=cap;
        head= new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
   void replace(Node *p)
   {
       Node *prev=p->prev;
       Node *next=p->next;
       prev->next=next;
       next->prev=prev;
   }

   void insert(Node *p)
   {
       Node *last=head->next;
       p->next=last;
       last->prev=p;
       head->next=p;
       p->prev=head;
   }
   void dell()
   {
    Node *frst=tail->prev->prev;
    frst->next=tail;
    tail->prev=frst;

   }
    
    
    int get(int key)
    {
       
       if(mp.find(key)==mp.end()) return -1;

       Node *ans=mp[key];
       replace(ans);
       insert(ans);

       return ans->data;

    }

    

    
    void put(int key, int value) {

       if(mp.find(key)!=mp.end())
       {
           mp[key]->data=value;
           replace(mp[key]);
           insert(mp[key]);

       }
     else
       {
            Node *newNode= new Node(key, value);
            mp[key]= newNode;

            insert(mp[key]);

            if(mp.size()>capacity)
            {
               mp.erase(tail->prev->key);
               dell();
            }
       }
        
    }
};
