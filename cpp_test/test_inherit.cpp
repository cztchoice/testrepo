#include <iostream>

using namespace std;

class Int{
	protected:
	int v;
	public:
	Int(int i = 0){
		v = i;
	}
	bool compare(Int b){
		if(b.v > v){
			return true;
		}
		else{
			return false;
		}
	}
};

class Int2 : public Int{
	public:
	Int2(Int a){
		//this->v = a.v;
	}
	void print(){
		cout<<this->v<<endl;
	}
};
int main(int argc, char *argv[]) {
	Int a(1), b(2);
	cout<<a.compare(b)<<endl;
	Int2 c(a);
	c.print();
}