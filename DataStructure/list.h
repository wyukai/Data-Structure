#ifndef LIST_H
#define LIST_H

template <typename T>
class  List
{
public:
	~ List();  
	List(int size);
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i,T *e);
	int LocateElem(T *e);
	bool PriorElem(T *currentElem, T *preElem);
	bool NextElem(T *currentElem, T *nextElem);
	bool ListInsert(int i, T * e);
	bool ListDelete(int i, T * e);
	void ListTraverse();

private:
	T *m_pList;
	int m_iSize;
	int m_iLength;
};

template <typename T>
List<T>::List(int size) {
	m_iSize = size;
	m_pList = new T[m_iSize];
	m_iLength = 0;
}
template <typename T>
List<T>::~List() {
	delete[]m_pList;
	m_pList = NULL;
}
template <typename T>
void List<T>::ClearList() {
	m_iLength = 0;
}
template <typename T>
bool List<T>::ListEmpty() {
	/*if (m_iLength == 0) {
	return true;
	}
	else
	{
	return false;
	}*/

	return m_iLength == 0 ? true : false;
}
template <typename T>
int List<T>::ListLength() {
	return m_iLength;
}
template <typename T>
bool List<T>::GetElem(int i, T *e) {
	if (i < 0 || i>m_iSize) {
		return false;
	}
	*e = m_pList[i];
	return true;
}
template <typename T>
int List<T>::LocateElem(T *e) {
	for (int i = 0; i < m_iLength; i++)
	{
		if (m_pList[i] == *e) {
			return i;
		}
	}
	return -1;
}

template <typename T>
bool List<T>::PriorElem(T *currentElem, T *preElem) {
	int temp = LocateElem(currentElem);
	if (temp == -1) {
		return false;
	}
	else {
		if (temp == 0) {
			return false;
		}
		else
		{
			*preElem = m_pList[temp - 1];
			return true;
		}
	}
}

template <typename T>
bool List<T>::NextElem(T *currentElem, T *nextElem) {
	int temp = LocateElem(currentElem);
	if (temp == -1) {
		return false;
	}
	else {
		if (temp == m_iLength - 1) {
			return false;
		}
		else
		{
			*nextElem = m_pList[temp + 1];
			return true;
		}
	}
}
template <typename T>
bool List<T>::ListInsert(int i, T * e) {
	if (i<0 || i>m_iLength) {
		return false;
	}

	//元素后移
	for (int k = m_iLength - 1; k >= i; k--)
	{
		m_pList[k + 1] = m_pList[k];
	}
	m_pList[i] = *e;
	m_iLength++;
	return true;
}
template <typename T>
bool List<T>::ListDelete(int i, T * e) {
	if (i<0 || i >= m_iLength) {
		return false;
	}
	*e = m_pList[i];
	//元素前移
	for (int k = i + 1; k < m_iLength; k++)
	{
		m_pList[k - 1] = m_pList[k];
	}
	m_iLength--;
	return true;
}
template <typename T>
void List<T>::ListTraverse() {
	for (int i = 0; i < m_iLength; i++)
	{
		cout << m_pList[i] << endl;
	}
}



#endif // !LIST_H
