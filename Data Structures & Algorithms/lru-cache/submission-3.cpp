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
   unordered_map<int, Node*> mp;

    LRUCache(int cap) {
       capacity=cap;
       head= new Node(-1,-1);
       tail= new Node(-1,-1);
       head->next=tail;
       tail->prev=head;

    } 
     void replace(Node *p)
     {
        Node *previous=p->prev;
        Node *next=p->next;
        previous->next=next;
        next->prev=previous;
     }

     void insert(Node *p)
     {
        Node *next=head->next;
        p->next=next;
        p->prev=head;
        head->next=p;
        next->prev=p;
     }

     void dell()
     {
       Node *previous=tail->prev->prev;
       previous->next=tail;
       tail->prev=previous;
     }
    
    int get(int key)
    {
       
      if(mp.find(key)==mp.end()) return -1;

      replace(mp[key]);
      insert(mp[key]);
      return mp[key]->data;
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
          Node *newNode= new Node(key,value);
          mp[key]=newNode;
          insert(newNode);

          if(mp.size()>capacity)
          {
            Node *ans=tail->prev;
            dell();
            mp.erase(ans->key);
          }
          
       }

        
    }
};
