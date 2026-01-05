class Node{
public:
   int data;
   Node*next;
   Node(int val){  //constructor
    data = val;
    next = NULL;
   }
};


class MyLinkedList {
public:
      Node* head;
      Node* tail;
      int size;
    MyLinkedList() {
        
        head = tail = NULL;
        size = 0;
    }
    
    int get(int index) {
       if(index<0 || index>=size){
        return -1;
       }
       if(index == 0){
        return head->data;
       }
       if(index == size -1){
        return tail->data;
       }
        Node* temp = head;
        for(int i = 0;i<index;i++){
            temp = temp->next;
        }
        return temp->data;

        
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        if(size == 0)
        {                            //Empty LinkedList Case
          head = tail = newnode;
        }
        else{
        newnode->next = head;
        head = newnode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* newnode = new Node(val);
         if(size == 0){                     // For Empty LinkedList
            head =  tail = newnode;
        }else{
        tail->next = newnode;               // LinkedList is already Present
        tail = newnode;
        }
       
        size++;
    }
    
    void addAtIndex(int index, int val) {

    //case 1: invalid position
     if(index<0 || index>size)
     {
        return;
     }
     //Case 2: insert First
     if(index == 0)
     {
        addAtHead(val);
        return;
     }
     // Case3 : Insert last
     if(index == size){
        addAtTail(val);
        return;
     }

     Node* newnode = new Node(val);
     Node* temp = head;
     for(int i = 0;i<index-1;i++){
        temp = temp->next;
     }                           //Traversed to position one node before to the node to be added
     newnode->next =temp->next;        
     temp->next = newnode;       //New Node added at respective position
      size++;   
    }
    
    void deleteAtIndex(int index) {
    if(index<0 || index>=size)
     {
        return;
     }
     if(index == 0) //case2: delete at head
     {
        Node*temp = head;
        head = head->next;
        delete temp;
        if(size == 1) tail = NULL;      // Edge Case
     }
     else{  
          Node* temp = head;
          for(int i = 0;i<index-1;i++){
            temp=temp->next;
          }
        Node*remove = temp->next;        //deleting element Stored
          temp->next = temp->next->next; //temp->next connected to the next of deleting node
          delete remove;                 // deleted
          if(index == size-1) tail = temp;   //tail adjusted
     }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */