#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename KeyType, typename DataType, typename Hasher = std::hash<KeyType>>
class hashmap_ll{
    private:
        Hasher hasher;
        class Node{
            private:
                friend class hashmap_ll;
                Node * next;
                DataType value;
                KeyType key;
            public:
                Node(const KeyType &key, const DataType &value){
                    next = nullptr;
                    this->value = value;
                    this->key = key;
                }
        };
        int num_buckets = 20;
        int num_buckets_in_use = 0;
        vector<Node *> buckets;
    public:
        hashmap_ll(){
            buckets.resize(20);
        }   
        bool insert(const KeyType &key, const DataType &val){
            int index = hasher(key) % num_buckets;
            if (buckets[index] == nullptr){
                //If this bucket has no previous value
                num_buckets_in_use++;
                buckets[index] = new Node(key, val);
                return true;
            }
            else{
                Node * lastItem = buckets[index];
                while (lastItem->next != nullptr){
                    if (lastItem->key == key){
                        return false;
                    }
                    lastItem = lastItem->next;
                }
                if (lastItem->key == key){
                    return false;
                }
                //If we've made it to here, we're on the last item and the item doesn't exist
                lastItem->next = new Node(key, val);
                return true;
            }
        }
};