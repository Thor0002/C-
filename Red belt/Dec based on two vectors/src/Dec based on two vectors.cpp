#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Deque{
public:
	Deque(){};
	bool Empty() const {
		return head.empty() and tail.empty();
	}
	size_t Size() const {
		return head.size() + tail.size();
	}
	T& operator[](const size_t& i) {
			return Get(i);
	}
	const T& operator[](const size_t& i) const{
		return Get(i);
	}
	T& At(const size_t& i) {
		if (i >= Size()) {
			throw out_of_range("");
		} else {return Get(i);}
	}
	const T& At(const size_t& i) const {
		if (i >= Size()) {
			throw out_of_range("");
		} else {return Get(i);}
	}
	T& Front(){
		if (head.empty()) {return tail.front();}
		return head.back();
	}
	T& Back(){
		if (tail.empty()) {return head.front();}
		return tail.back();
	}
	const T& Front() const {
		if (head.empty()) {return tail.front();}
		return head.back();
	}
	const T& Back() const {
		if (tail.empty()) {return head.front();}
		return tail.back();
	}
    void PushFront(const T& x){head.push_back(x);}
    void PushBack(const T& x){tail.push_back(x);}
    void Print(){
    	if (!head.empty()){
    		for(auto it = --end(head); it >= begin(head); it--){
    			cout << *it << " ";
    		}
    	}
    	for(auto x : tail){
    		cout << x << " ";
    	}
    	cout << endl;
    }
private:
	vector<T> head;
	vector<T> tail;
	T& Get(const size_t& i){
		return (i < head.size()) ? head[head.size()- 1 - i] : tail[i - head.size()];
	}
};

int main() {

	Deque<int> deq;
	deq.PushBack(0);
	deq[0]++;
	deq.Print();
	deq.PushBack(3);
	cout << deq.Back() << endl;
	cout << deq.Empty() << " " << deq.Size() << endl;
	deq.Print();
	deq.Back()--;
	deq.Print();
	deq[0] = -1;
	deq[1] = -1;
	deq.Print();
	return 0;
}
