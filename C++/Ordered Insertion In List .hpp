// Ordered Insertion In List 

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
 
// Printing 
void print_list_rec(ListNode* l){
    if(l != NULL){
        std::cout << l->val << std::endl;
        print_list_rec(l->next);
    }
}

// Deallocating 
void deallocate_list_rec(ListNode* l){
    ListNode* tmp;
    if(l != NULL){
        tmp = l->next;
        delete l;
        deallocate_list_rec(tmp);
    }
}

// Ordered Insertion
ListNode* ordered_insertion_list(list_t e, ListNode* l){
    if(l == NULL){
        return cons_list(e, l);
    }
    else if(e < l->val){
        return cons_list(e, l);
    }
    else{
        l->next = ordered_insertion_list(e, l->next);
        return l;
    }
}
 
int main(){
    ListNode* l = NULL;
 
    l = cons_list(5, l);
    l = cons_list(4, l);
    l = cons_list(2, l);
    l = cons_list(1, l);

    l = ordered_insertion_list(0, l);
    l = ordered_insertion_list(3, l);
 
    print_list_rec(l);

    deallocate_list_rec(l);
}