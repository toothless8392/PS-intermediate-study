#include<iostream>
typedef std::string element;
typedef struct _Node{
    element data;
    struct _Node* nextNode;
}Node;

Node* insertFirst(Node* head, element data);
Node* insert(Node* head, element data);
void printDS(Node* head);

int main () {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int N; std::cin >> N;
    std::string input; std::cin >> input;
    Node* head = NULL; head = insertFirst(head, input);
    for(int i = 1; i < N; i++){
        std::cin >> input;
        if(head->data.size() > input.size() || (head->data.size() == input.size() && head->data > input))
            head = insertFirst(head, input);
        else
            head = insert(head, input);             
    }
    printDS(head); return 0;
}

Node* insertFirst(Node* head, element data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->nextNode = head;
    head = newNode;
    return head;
}
Node* insert(Node* head, element data){
    Node* newNode = new Node;
    newNode->data = data;
    Node* cmpNode = head;
    while(cmpNode->nextNode != NULL && (cmpNode->nextNode->data.size() < data.size() || (cmpNode->nextNode->data.size() == data.size() && cmpNode->nextNode->data < data)))
        cmpNode = cmpNode->nextNode;
    newNode->nextNode = cmpNode->nextNode;
    cmpNode->nextNode = newNode;
    return head;
}

void printDS(Node* head){
    Node* printer = head;
    while(printer){
        if(printer->nextNode == NULL){
            std::cout << printer->data << "\n"; return;
        }
        else if(printer->data == printer->nextNode->data) {
            printer = printer->nextNode; continue;
        }
        std::cout << printer->data << "\n";
        printer = printer->nextNode;
    }
}
