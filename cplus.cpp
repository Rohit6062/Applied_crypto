#include<iostream>
#include<string>
using namespace std;

class stack{
public:
    int top = -1;
    int size = 100;
    int *arr = (int*)malloc(sizeof(int)*100);
    void push(int val){
        if (top != size){
            this -> top++;
            this -> arr[top] = val;
        }
        else{
            this -> arr =(int*) realloc(arr,2*size);
            this -> push(val);
        }
    }
    void pr(){
        for (int i = 0; i <= top; i++){
            cout << arr[i] << endl;
        }
    }
    int pop(){
            if (top != -1){
                this -> top--;
                return this -> arr[top+1];
            }
            else 
            cout << "empty stack " << endl;
        return -1;    
    }
    
};

int main(){
    stack s;
    s.push(4);
    s.push(6);
    s.push(8);
    s.pr();
    cout << "pop -> "<<s.pop() << endl;
    s.pr();
    return 0;
}
