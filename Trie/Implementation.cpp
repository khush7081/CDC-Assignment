#include<iostream>
#include<vector>
using namespace std;
struct node{
    node* links[26];
    bool flag = false;

    bool containsKey( char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, node* temp){
        links[ch - 'a'] = temp;
    }

    node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }

};
class Trie {
private: 
    node* root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node * ptr = root;

        for(int i = 0; i < word.length(); i++){
            if( !ptr->containsKey( word[i])){
                ptr->put(word[i], new node());
            }
            ptr = ptr->get(word[i]);
        }
        ptr->setEnd();        
    }
    
    bool search(string word) {
        node* ptr = root;

        for(int i = 0; i < word.length(); i++){
            if( !ptr->containsKey(word[i])){
                return false;
            }
            ptr = ptr->get(word[i]);
        }

        return ptr->isEnd();
        
    }
    
    bool startsWith(string word) {

        node * ptr = root;
        for(int i = 0; i < word.length(); i++){
            if( !ptr->containsKey( word[i])){
                return false;
            }
            ptr = ptr->get(word[i]);
        }
        return true;
        
    }
};
