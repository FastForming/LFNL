#include<iostream>
#include<vector>
using namespace std;

struct Node{
        int data;
        Node* next;
        Node(int value):data(value),next(NULL) {}
    };

class LinkList{
private:
    Node* head;
public:
    LinkList():head(nullptr) {}
    ~LinkList(){
        Node* cur=head;
        while(cur!=nullptr){
            Node* temp=cur;
            cur=cur->next;
            delete temp;
        }
    }

    void add(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
        }else{
            Node* cur=head;
            while(cur->next!=nullptr){
                cur=cur->next;
            }
            cur->next=newNode;
        }
    }

    void reverse(){
        Node* prev=nullptr;
        Node* cur=head;
        Node* next=nullptr;
        while(cur!=nullptr){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head=prev;
    }

    void create(const vector<int>& vec){
        for (int val : vec) {
            add(val);
        }
    }

    void printList(){
        Node* cur=head;
        while(cur!=NULL){
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }

    void display(){
        cout<<"Before List: ";
        this->printList();
        this->reverse();
        cout<<"After List: ";
        this->printList();
    }
};

int main(){
    vector<int> vector={1,2,3,4,5,6,7,8,9,10};
    LinkList List;
    List.create(vector);
    List.display();

    return 0;
}
