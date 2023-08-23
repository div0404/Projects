// LRU Cache

#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Node{
    public: 
    string key;
    int value;
    Node(string key,int value){
        this->key = key;
        this->value = value;
    }
};

class LRUCache{
    public:
    int maxSize;
    list<Node> l;
    unordered_map<string,list<Node>::iterator> m;

    LRUCache(int maxSize){
        this->maxSize = maxSize > 1 ? maxSize :1;
    }

    void insertKeyValue(string key,int value){
        //2 cases
        //when key is already present
        if(m.count(key)!=0){
            auto it = m[key];
            it->value = value;
        }
        else{
            //when key is not present
            //check if cache is full
            if(l.size()==maxSize){
                Node last = l.back();
                m.erase(last.key);   //removing from hashmap
                l.pop_back();   //removing from the list
            }

            Node n(key,value);
            l.push_front(n);
            m[key] = l.begin();
        }
    }

    int getValue(string key){
        //check if key is present
        if(m.count(key)!=0){
            auto it = m[key];

            int value = it->value;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return value;
        }
        return -1;
    }

    string mostRecent(){
        //most recent key
        return l.front().key;
    }
};

int main(){
    LRUCache lru(3);
    lru.insertKeyValue("Mango",20);
    lru.insertKeyValue("Banana",30);
    lru.insertKeyValue("Apple",50);
    
    lru.insertKeyValue("Mango",40);
    cout<<lru.getValue("Mango")<<endl;
    cout<<lru.mostRecent()<<endl;

    lru.insertKeyValue("Guaua",35);
    cout<<lru.mostRecent()<<endl;

    if(lru.getValue("Apple")==-1){
        cout<<"Apple not present"<<endl;
    }

    if(lru.getValue("Banana")==-1){
        cout<<"Banana not present"<<endl;
    }

    if(lru.getValue("Guaua")==-1){
        cout<<"Guaua not present"<<endl;
    }

    if(lru.getValue("Mango")==-1){
        cout<<"Mango not present"<<endl;
    }

    return 0;
}