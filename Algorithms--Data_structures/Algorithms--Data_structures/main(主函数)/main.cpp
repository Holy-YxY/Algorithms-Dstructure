//�㷨ͷ�ļ�
#include "Search_algorithm(�����㷨)/Order.h"
#include "Sorting_algorithm(�����㷨)/Bubble.h"
#include "Sorting_algorithm(�����㷨)\Insertion.h"
#include "Sorting_algorithm(�����㷨)/Quick.h"
#include "Sorting_algorithm(�����㷨)/Select.h"


//���ݽṹͷ�ļ�
#include "List(���Ա�)/s_List.h"
#include "List(���Ա�)/l_List.h"
#include "Queue(����)/Queue.h"

using namespace std;

//˳����Ҳ���
void ordertest();
//ð���������
void bubbleTest();
//�����������
void quickTest();
//ѡ���������
void selectTest();

//˳����в���
void listTest();
void queueTest();


int main(void)
{

	std::cout << "Welcome to algorithms and data structures." << std::endl;

	//˳����Ҳ���
	//ordertest();
	//ð���������
	//bubbleTest();
	//�����������
	//quickTest();
	//ѡ���������
	//selectTest();

	//���Ա����
	listTest();
	//���в���
	//queueTest();

	std::cin.get();
}

//˳����Ҳ���
void ordertest()
{
	int arr[5] = { 1, 3, 2, 4, 0 };
	
	cout << order(arr, 5, 0) << endl;
	cout << order(arr, 5, 4) << endl;
	cout << order(arr, 5, 9) << endl;
}
//ð���������
void bubbleTest()
{
	int Arr_i[] = { 3, 1, 4, 2 , 6, 9, 5, 7, 8, 0 };
	double Arr_d[] = { 13.1, 21.3, 31.4, 0.31, 1.43, 6.52, 12.6, 19.75, 50.01, 30.33 };
	//bubble(Arr_i, 10);
	//bubble(Arr_d, 10);
	insertion(Arr_i, 10);

	for (int i = 0; i < 10; i++)
		cout << Arr_i[i] << ", ";
	cout << endl;
}
//�����������
void quickTest()
{
	int high;
	cin >> high;
	int *arr = new int[high];
	for (int i = 0; i < high; i++)
		cin >> arr[i];

	quick(arr, 0, high-1);

	for (int i = 0; i < high; i++)
		cout << arr[i] << ",";
}
//ѡ���������
void selectTest()
{
	int Arr[] = { 3, 1, 4, 2 , 6, 9, 5, 7, 8, 0 };
	select(Arr, 10);
	for (int i = 0; i < 10; i++)
		cout << Arr[i] << ", ";
	cout << endl;

}

//˳�����Ա����
void listTest()
{
	s_List<int> list(-1);
	s_List<double> d_list(8);
	cout << d_list.ListLength() << endl;
	cout << d_list.ListEmpty() << endl;
	cout << d_list.ListInsert(1, 3.2) << endl;
	cout << d_list.ListInsert(2, 5.5) << endl;
	cout << d_list.ListInsert(5, 5.5) << endl;
	cout << d_list.ListInsert(3, 7.9) << endl;
	cout << d_list.ListInsert(3, 0.2) << endl;
	cout << d_list.ListLength() << endl;
	cout << d_list.ListEmpty() << endl;
	cout << d_list.GetElem(1) << endl;
	cout << d_list.GetElem(2) << endl;
	cout << d_list.GetElem(3) << endl;
	cout << d_list.GetElem(4) << endl;
	cout << d_list.LocateElem(2.2) << endl;
	cout << d_list.PriorElem(0.2) << endl;
	cout << d_list.PriorElem(7.2) << endl;
	cout << d_list.NextElem(1.1) << endl;
	cout << d_list.NextElem(5.5) << endl;
	s_List<int> i_list;
	cout << i_list.ListEmpty() << endl;
	cout << i_list.ListLength() << endl;
	cout << i_list.ListInsert(1, 3) << endl;
	cout << i_list.ListInsert(2, 5) << endl;
	cout << i_list.ListLength() << endl;
	cout << i_list.GetElem(1) << endl;

	l_list<int> Llist;
	Llist.ListInsert(3);
	Llist.ListInsert(5);
	Llist.ListInsert(7);

	l_list<double> d_Llist;
	d_Llist.ListInsert(1.12);
	d_Llist.ListInsert(3.12);
	d_Llist.ListInsert(4.12);
	d_Llist.ListInsert(5.12);
	cout << d_Llist.ListInsert(5, 6.3) << endl;
	cout << d_Llist.ListInsert(2, 2.3) << endl;
}

//���в���
void queueTest()
{
	Queue<int> queue_i;
	Queue<double> queue_d(8);
	cout << queue_i.isEmpty() << endl;
	queue_i.push_Q(0);
	cout << "numel:" << queue_i.numel() << endl;
	queue_i.traversal();
	queue_i.push_Q(1);
	cout << queue_i.Front() << endl;
	cout << queue_i.Rear() << endl;
	queue_i.push_Q(2);
	queue_i.push_Q(3);
	cout << "numel:" << queue_i.numel() << endl;
	queue_i.push_Q(4);
	queue_i.push_Q(5);
	queue_i.push_Q(6);
	queue_i.push_Q(7);
	queue_i.traversal();
	cout << "numel:" << queue_i.numel() << endl;
	cout << queue_i.Rear() << endl;
	queue_i.push_Q(8);
	queue_i.push_Q(9);
	cout << queue_i.Rear() << endl;
	cout << queue_i.Front() << endl;
	queue_i.traversal();
	cout << "numel:" << queue_i.numel() << endl;
	queue_i.pop_Q();
	queue_i.push_Q(10);
	cout << queue_i.Rear() << endl;
	cout << queue_i.Front() << endl;
	queue_i.pop_Q();
	queue_i.push_Q(11);
	cout << queue_i.Front() << endl;
	cout << queue_i.Rear() << endl;
	queue_i.traversal();
	cout << "numel:" << queue_i.numel() << endl;
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.push_Q(31);
	queue_i.push_Q(41);
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	cout << queue_i.Rear() << endl;
	cout << queue_i.Front() << endl;
	cout << "numel:" << queue_i.numel() << endl;
	queue_i.traversal();
	queue_i.pop_Q();
	cout << "numel:" << queue_i.numel() << endl;
	cout << queue_i.isEmpty() << endl;
}
