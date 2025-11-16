#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class MyHashMap {
private :
    vector< pair<int,int> > mp;
public:
   
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        if( mp.size() == 0){
            mp.push_back( { key, value});
        }
        else{
            for( int i = 0 ; i < mp.size(); i++){
                int k = mp[i].first;
                if( key == k){
                    mp[i].second = value;
                    return;
                }
            }
            mp.push_back( { key, value});
        }

    }
    
    int get(int key) {
        for( auto it : mp){
            if( it.first == key) return it.second;
        }
        return -1;
    }   
    
    void remove(int key) {
        for( int i = 0 ; i < mp.size(); i++){
            if( mp[i].first == key){
                mp[i].first = -1;
                return;
            }
        }
    }
};

