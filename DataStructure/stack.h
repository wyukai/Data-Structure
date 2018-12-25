/*
’ª
*/


template <typename T>
class MyStack
{
public:
	MyStack();
	~MyStack();
	MyStack(int size);
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(T element);
	bool pop(T &element);
	void stackTraverse(bool isFromButtom);
	int getTop();
	T   getTopElement();
private:
	T *m_pBuffer; //’ªø’º‰÷∏’Î
	int m_iSize; //’ª»›¡ø
	int m_iTop; //’ª∂•

};




template <typename T>
MyStack<T>::MyStack(int size) {
	m_iSize = size;
	m_pBuffer = new T[m_iSize];
	m_iTop = 0;
}
template<typename T>
inline MyStack<T>::MyStack()
{
}
template <typename T>
MyStack<T>::~MyStack() {
	delete[]m_pBuffer;
	m_pBuffer = NULL;
}
template <typename T>
bool MyStack<T>::stackEmpty() {
	if (0 == m_iTop) {
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
bool MyStack<T>::stackFull() {
	if (m_iTop >= m_iSize) {
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
void MyStack<T>::clearStack() {
	m_iTop = 0;
}
template <typename T>
int MyStack<T>::stackLength() {
	return m_iTop;
}
template <typename T>
bool MyStack<T>::push(T element) {
	if (stackFull()) {
		false;
	}
	else
	{
		m_pBuffer[m_iTop] = element;
		m_iTop++;
		return true;
	}
}
template <typename T>
bool MyStack<T>::pop(T &element) {
	if (stackEmpty()) {
		return false;
	}
	else
	{
		m_iTop--;
		element = m_pBuffer[m_iTop];
		return true;
	}
}
template <typename T>
void MyStack<T>::stackTraverse(bool isFromButtom) {

	if (isFromButtom) {
		for (int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i];
			/*m_pBuffer[i].printCoordinate();*/
		}
	}
	else
	{
		for (int i = m_iTop - 1; i >= 0; i--)
		{
			cout << m_pBuffer[i];
			/*m_pBuffer[i].printCoordinate();*/
		}
	}
}
template <typename T>
int MyStack<T>::getTop() {

	return m_iTop;
}

template<typename T>
inline T MyStack<T>::getTopElement()
{	
	if (m_iTop > 0) {
		cout << m_pBuffer[m_iTop-1] << endl;
		return m_pBuffer[m_iTop-1];
	}
	
}

