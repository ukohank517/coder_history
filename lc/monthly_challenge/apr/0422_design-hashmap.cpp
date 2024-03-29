class MyHashMap {
private:
    map<int, int> mp;
public:
    MyHashMap() {
    }
    
    void put(int key, int value) {
        mp[key] = value + 1;
    }
    
    int get(int key) {
        return mp[key] - 1;        
    }
    
    void remove(int key) {
        mp[key] = 0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
