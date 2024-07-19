void push(node** head_ref, int new_data)
{
    node* new_Node = (node*)malloc(sizeof(node));
    new_Node->data = new_data;
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
 
node* zigzag(node* head, bool flag)
{
    if (!head || !head->next)
        return head;
    if (flag == 1) {
        if (head->data > head->next->data)
            swap(head->data, head->next->data);
        return zigzag(head->next, !flag);
    }
    else {
        if (head->data < head->next->data)
            swap(head->data, head->next->data);
        return zigzag(head->next, !flag);
    }
}
