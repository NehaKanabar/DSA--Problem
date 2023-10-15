#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i) //O(logn)
{
     int index=i;
     int largest=index;
     int leftIndex=2*i;
     int rightIndex=2*i+1;

     if(leftIndex<=n && arr[largest]<arr[leftIndex])
     {
         largest=leftIndex;
     }
     if(rightIndex<=n && arr[largest]<arr[rightIndex])
     {
        largest=rightIndex;
     }
     if(index!=largest)
     {
        //left ya right child me se koi > ho gya current node se
        swap(arr[index],arr[largest]);
        index=largest;
        heapify(arr,n,index);
     }
}

//build heap from array so for this 
//(n/2+1) se lekar n tak leafnode hai jisko hapeify karne ki need nahi hai
//so n/2 se lekar 1 tak hum nodes ko heapify karenge
//uske liye n/2 se lekar 1 tak loop chalayenge or usme andar heapify()call karva denge
void buildheap(int arr[],int n) //buildheap ki complexity O(n)
{
    for(int i=n/2;i>=1;i--)
    {
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n)  //O(nlogn)
{
    int index=n;
    while(n!=1)
    {
        //swap or uske bad size--
        swap(arr[1],arr[index]);
        index--;
        n--;

        //heapify
        heapify(arr,n,1);

    }
}
int main()
{
     int arr[]={-1,12,56,43,6,78,87,5,44,3,23,32};
     int n=11;
     buildheap(arr,n); 

     cout<<"printing the haep"<<endl;
     for(int i=0;i<=n;i++)
     {
        cout<<arr[i]<<" ";
     }

     cout<<endl;
     heapSort(arr,n);
     cout<<"printing the haep"<<endl;
     for(int i=0;i<=n;i++)
     {
        cout<<arr[i]<<" ";
     }
     cout<<endl;
}
