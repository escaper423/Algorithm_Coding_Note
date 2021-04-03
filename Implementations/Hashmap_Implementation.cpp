#include <optional>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

//Reference: https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
#define TABLE_SIZE 100

using namespace std;

template<typename K>
struct KeyHash{
	unsigned long operator()(const K& key) const {
		return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
	}
};

template<typename K, typename V>
class HashNode {
public:
	HashNode(const K key, const V value):
		key(key), value(value), next(nullptr)
	{}
	K getKey() const{
		return key;
	}
	V getValue() const {
		return value;
	}
	void setValue(V val) {
		value = val;
	}
	HashNode* getNext() const {
		return next;
	}
	void setNext(HashNode* h) {
		next = h;
	}
	
private:
	K key;
	V value;
	HashNode* next;
};

struct MyKeyHash {
	unsigned long operator()(const int& key) const {
		return key % 10;
	}
};

template<typename K, typename V, typename F = KeyHash<K>>
class HashMap {
public:
	HashMap() {
		table = new HashNode<K, V> *[TABLE_SIZE]();
	}
	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			HashNode<K, V> *cur = table[i];
			
			while (cur != nullptr) {
				auto to_delete = cur;
				cur = cur->getNext();
				delete to_delete;
			}
			table[i] = nullptr;
		}
		delete[] table;
	}

	void put(const K& key, const V& value) {
		auto hashVal = HashFunc(key);

		HashNode<K, V> *prev = nullptr;
		HashNode<K, V> *cur = table[hashVal];

		while (cur != nullptr && cur->getKey() != key) {
			prev = cur;
			cur = cur->getNext();
		}
		
		if (cur == nullptr) {
			cur = new HashNode<K, V>(key, value);
			if (prev == nullptr) {
				table[hashVal] = cur;
			}
			else {
				prev->setNext(cur);
			}
		}
		else
			cur->setValue(value);
		
	}
	
	bool get(const K& key, V& value) {
		auto hashVal = HashFunc(key);
		HashNode<K, V> *cur = table[hashVal];
		
		while (cur != nullptr && cur->getKey() != key) {
			cur = cur->getNext();
		}

		if (cur == nullptr)
			return false;
		else {
			value = cur->getValue();
			return true;
		}
	}

	void remove(const K& key) {
		auto hashVal = HashFunc(key);
		HashNode<K, V> *prev = nullptr;
		HashNode<K, V> *cur = table[hashVal];

		while (cur != nullptr && cur->getKey() != key) {
			prev = cur;
			cur = cur->getNext();
		}

		if (cur == nullptr)
			return;
		else{
			if (prev == nullptr) {
				table[hashVal] = cur->getNext();
			}
			else {
				prev->setNext(cur->getNext());
			}
			delete cur;
		}
	}

private:
	HashNode<K,V>** table;
	F HashFunc;
};
int main() {
	HashMap<int, string,MyKeyHash> m;
	m.put(1, "val1");
	m.put(2, "val2");
	m.put(12, "val12");
	m.put(22, "val22");
	m.put(3, "val3");

	string val;
	auto r = m.get(2,val);
	if(r)
		cout << val << endl;

	r = m.get(3,val);
	if (r)
		cout << val << endl;

	m.remove(3);
	r = m.get(3, val);
	if (r)
		cout << val << endl;
	m.remove(12);
	r = m.get(22, val);



	if (r)
		cout << val << endl;
	system("pause");
	return 0;
}
