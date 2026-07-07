#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    unsigned char ch;
    int freq;

    Node *left;
    Node *right;

    Node(unsigned char ch,int freq){
        this->ch=ch;
        this->freq=freq;
        left=NULL;
        right=NULL;
    }
};

class Compare{
public:
    bool operator()(Node *a,Node *b){
        return a->freq>b->freq;
    }
};

class HuffmanTree{
private:

    Node *root;
    unordered_map<unsigned char,string> codes;

    void generateCodes(Node *root,string code){
        if(root==NULL)
            return;

        if(root->left==NULL && root->right==NULL){
            if(code=="")
                code="0";

            codes[root->ch]=code;
            return;
        }

        generateCodes(root->left,code+"0");
        generateCodes(root->right,code+"1");
    }

public:

    HuffmanTree(vector<int> frequency) {
        priority_queue<Node*,vector<Node*>,Compare> pq;

        for(int i=0;i<256;i++){
            if(frequency[i]>0){
                pq.push(new Node((unsigned char)i,frequency[i]));
            }
        }

        if(pq.empty()){
            root=NULL;
            return;
        }

        while(pq.size()>1){
            Node *left=pq.top();
            pq.pop();
            Node *right=pq.top();
            pq.pop();
            Node *parent=new Node('\0',left->freq+right->freq);
            parent->left=left;
            parent->right=right;
            pq.push(parent);
        }
        root=pq.top();
        generateCodes(root,"");
    }

    unordered_map<unsigned char,string> getCodes(){
        return codes;
    }

    void printCodes(){
        cout<<"\nHuffman Codes\n\n";
        for(auto x:codes){
            if(isprint(x.first))
                cout<<"'"<<x.first<<"'"<<" -> "<<x.second<<endl;
            else
                cout<<"ASCII "<<(int)x.first<<" -> "<<x.second<<endl;
        }
    }
};

#endif