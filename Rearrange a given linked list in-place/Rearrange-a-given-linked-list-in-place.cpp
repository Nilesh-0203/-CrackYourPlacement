Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
void rearrange(Node** head, Node* last)
{
    if (!last)
        return;
   
    rearrange(head, last->next);
   
    if (!(*head)->next)
        return;
 
    if ((*head) != last && (*head)->next != last) {
        Node* tmp = (*head)->next;
        (*head)->next = last;
        last->next = tmp;
        *head = tmp;
    }
    else {
        if ((*head) != last)
            *head = (*head)->next;
        (*head)->next = NULL;
    }
}
