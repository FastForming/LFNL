//设待排序的记录序列用单链表作存储结构，编写直接插入排序的程序
#include<iostream>
#include<vector>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int value):data(value),next(NULL) {}
};

class InsertionSort{
private:
    ListNode* head;

    void insert(ListNode*& sortedHead,ListNode* newNode){
        if(sortedHead==NULL || sortedHead->data>newNode->data){
            newNode->next=sortedHead;
            sortedHead=newNode;
        }else{
            ListNode* current=sortedHead;
            while(current->next!=NULL && current->next->data<newNode->data){
                current=current->next;
            }
            newNode->next=current->next;
            current->next=newNode;
        }
    }

public:
    InsertionSort():head(NULL) {}

    void insert(int value){
        ListNode* newNode=new ListNode(value);
        insert(head,newNode);
    }

    void sort(){
        if(head==NULL || head->next==NULL){
            return;
        }

        ListNode* sorted=NULL;
        ListNode* current=head;
        
    }

};