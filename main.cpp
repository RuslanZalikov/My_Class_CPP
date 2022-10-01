#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Node{
    int val;
    Node *l, *r;
    Node(){
        this->val = 0; this->l = nullptr; this->r = nullptr;
    }
};

class BTS{
public:
    Node *root = new Node;
    void fill(vector <int> data){
        this->root->val = data[0];
        for(int i = 1; i < data.size(); i++){
            Node *tmp = new Node;
            tmp->val = data[i];
            RecBTS(tmp, this->root);
        }
    }
    vector <int> out(){
        vector <int> res;
        bts_obhod(this->root, res);
        return res;
    }
private:
    void RecBTS(Node *node, Node *root){
        if (root->l == nullptr and node->val < root->val){
            root->l = node;
        }
        else if (root->r == nullptr and node->val >= root->val){
            root->r = node;
        }
        else if (node->val < root->val){
            RecBTS(node, root->l);
        }
        else if (node->val >= root->val){
            RecBTS(node, root->r);
        }
    }
    void bts_obhod(Node *root, vector<int> &res){
        if(root != nullptr){
            bts_obhod(root->l, res);
            res.push_back(root->val);
            bts_obhod(root->r, res);
        }
    }
};

int main(){
    vector <int> data = {3, 1, 0, 6, 5};
    BTS bts_data;
    bts_data.fill(data);
    vector <int> new_data = bts_data.out();
    for (int i = 0; i < new_data.size(); i++){
        cout << new_data[i] << " ";
    }
}