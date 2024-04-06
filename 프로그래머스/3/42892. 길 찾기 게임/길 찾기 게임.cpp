#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int data;
    int x;
    int y;
    Node* left;
    Node* right;
    
    Node(int data, int x, int y):data(data), x(x), y(y), left(nullptr), right(nullptr){}
    
    bool const operator<(Node tmp)const{
        if(y==tmp.y){
            return x<tmp.x;
        }
        return y>tmp.y;
    }
    
};

class BinarySearchTree { 
public:
    Node* root=nullptr;
    vector<int> pre;
    vector<int> post;
    
    void insert(int value, int x, int y)
    {
        if(!root) root = new Node(value, x, y);
        else insert_impl(root, value, x, y);
    }
    
    void preorder(Node* node)
    {
        if(node){
            pre.push_back(node->data);
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void postorder(Node* node)
    {
        if(node){
            postorder(node->left);
            postorder(node->right);
            post.push_back(node->data);
        }
    }
    
private:
    void insert_impl(Node* curr, int value, int x, int y)
    {
        if(y<curr->y){
            if(x<curr->x){
                if(!curr->left) curr->left = new Node(value, x, y);
                else insert_impl(curr->left, value, x, y);
            }
            else{
                if(!curr->right) curr->right = new Node(value, x, y);
                else insert_impl(curr->right, value, x, y);
            }

        }
    }
    
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    BinarySearchTree bst;
    vector<Node> v;
    int data =1;
    for(int i=0;i<nodeinfo.size();i++){
        v.push_back(Node(data, nodeinfo[i][0], nodeinfo[i][1]));
        data+=1;
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<v.size();i++){
        bst.insert(v[i].data, v[i].x, v[i].y);
    }
    vector<vector<int>> answer;
    
    bst.preorder(bst.root);
    bst.postorder(bst.root);
    
    answer.push_back(bst.pre);
    answer.push_back(bst.post);
    return answer;
}