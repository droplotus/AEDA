# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
public:
	StackExt() {};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
private:
    stack<T> values;
    stack<T> min_values;
};

// a alterar
template <class T> 
bool StackExt<T>::empty() const
{
	return values.empty();
}

//a alterar
template <class T> 
T& StackExt<T>::top()
{
    T *novo = &values.top();
    std::cout << novo << std::endl;
    return *novo;
}

//a alterar
template <class T> 
void StackExt<T>::pop()
{
    if(min_values.top()==values.top()) min_values.pop();
    values.pop();
}

//a alterar
template <class T> 
void StackExt<T>::push(const T & val)
{
    values.push(val);
    if(min_values.empty()) min_values.push(val);
    else if(min_values.top()>=val) min_values.push(val);
}

//a alterar
template <class T> 
T& StackExt<T>::findMin()
{
    T *novo = new T(min_values.top());
    return *novo;
}

