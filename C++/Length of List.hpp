// Length of List

#include <iostream>
 
typedef int list_t;
 
struct ListNode{
    list_t val;
    ListNode* next;
};
 
ListNode* cons_list(list_t e, ListNode* l){
    ListNode* tmp;
 
    tmp = new ListNode;
 
    tmp->val = e;
    tmp->next = l;
 
    return tmp;
}
 
 // Using recursions
void print_list_rec(ListNode* l){
    if(l != NULL){
        std::cout << l->val << std::endl;
        // we print the first element
        print_list_rec(l->next);
        // then the rest of the list
    }
}
 
void deallocate_list_rec(ListNode* l){
    ListNode* tmp;
    if(l != NULL){
        tmp = l->next;
        delete l;
        deallocate_list_rec(tmp);
    }
}

// Getting the length
int list_length(ListNode* l){
  int len;
  if (l == NULL){
    len = 0; 
  }
  else{
    len = 1 + list_length(l->next);
  }
  return len;
}


 
int main(){
    ListNode* l = NULL;
 
    l = cons_list(1, l);
    l = cons_list(2, l);
    l = cons_list(3, l);
 
    print_list_rec(l);

    std::cout<<"Length: "<<list_length(l);
 
    deallocate_list_rec(l);
}