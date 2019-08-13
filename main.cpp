#include <iostream>
#include <vector>
using namespace std;

// array_reverse
/*
void reverse_ (int*, int, int);
void reverse_ (int* A, int n){
    reverse_ (A,0,n-1);
}
void reverse_ (int* A, int lo, int hi){
    if ( lo < hi ){
        swap( A[lo], A[hi]);
        reverse_ ( A, lo + 1, hi -1 );

    }
}


int main()
{
    int a[6] = {1,2,4,5,5,8};
    reverse_(a,6);
    for(int i=0;i<6;i++){
        cout<< *(a+i);
    }
    return 0;
}
*/
// array_sum
/*
int sum(int A[],int len){
    int Sum = 0;
    for(int i = 0; i<len ;i++ ){
        Sum = Sum + A[i];
    }
    return Sum;
}

int main(){
    int a[6] = {1,2,3,4,5,6};
    cout<< sum(a,6) ;
    return 0;
}
*/
//array_sum_recursion
/*
int sum( int A[], int len){
    if( len < 1 )
        return 0;
    else
        return sum(  A,  len - 1 ) + A[len-1];

}

int main(){
    int a[] = {1,2,3,4,5};
    cout << sum(a,5) ;
    return 0;
}
*/
// heap_sort
/*
void max_heapity(int a[], int pos, int len){
    //给定子节点，计算其左右孩子节点
    int left = 2 * pos;
    int right = 2 * pos + 1;
    int largest = pos;
    if (left <= len && a[ left-1 ] > a[ pos - 1 ])
        largest = left;
    if (right <= len && a[right - 1] > a[largest - 1])
        largest = right;
    if (largest != pos)
    {
        swap(a[pos-1],a[largest-1]);
        max_heapity(a,largest,len);//递归调用维护最大堆的性质
    }
}

void build_max_heap(int a[], int n){
    for(int i=n/2; i>0; i--){
        //从第一个非叶子结点去为维护一个堆，若数组长度为len,则第一个非叶子结点是 len/2
        max_heapity(a,i,n);
    }
}

void heap_sort(int a[],int len){
    build_max_heap(a,len);//第一次建立一个堆
    for(int i=len;i>=2;i--){
        swap(a[0],a[i-1]); //交换根节点和最后一个叶子结点的数值
        max_heapity(a,1,i-1);//交换后违背了最大堆的性质，从根节点去维护让它继续成立一个最大堆，注意，交换后，维护一个堆的范围变成了a[0]-a[n-2],所以长度要减1
    }
}
int main(){
    int a[] = {1,4,4,3,5,9,8};
    int len = sizeof(a) / 4;
    heap_sort(a,len);
    for(int i=0;i<len;i++){
        cout << a[i] <<" ";
    }
    cout << endl;
    return 0;
}
*/
//quick_sort
/*
int partion(int a[],int p, int r){
    int i = p-1;
    int x = a[r-1];
    for(int j=p;j<=r-1;j++){
        if (a[j-1] <= x){
            i = i+1;
            swap(a[i-1],a[j-1]);
        }
    }
    swap(a[i],a[r-1]);
    return i+1;
}
void quick_sort(int a[],int p, int r){
    if (p < r){
        int q = partion(a,p,r);
        //cout << q;
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }

}


int main(){
    int a[] = {1,4,7,8,5,46,8};
    quick_sort(a,1,7);
    for(int i=0;i<=6;i++){
        cout <<a[i]<<" ";
        cout <<endl;
    }
    return 0;
}
*/

//TOP-K
/*
int partion(vector<int> &a,int left,int right){
    int i = left - 1;
    int x = a[right-1];
    int p = left;
    for(int j = p;j<right;j++ ){
        if(a[j-1] < x){
            i = i + 1;
            swap(a[i-1],a[j-1]);
        }
    }
    swap(a[i],a[right-1]);
    return i+1;
}

int topk(vector<int> &a,int left, int right, int k){
    int index = -1;
    if(left < right){
        int pos = partion(a,left,right);
        int len = right - pos+1;
        if(len == k)
            index = pos;
        else if (len < k){
            index = topk(a,left,pos-1,k-len);
        }
        else {
        index = topk(a,pos+1,right,k);
        }
    }
    return index;
}

int main(){
    int b[] = {1,8,5,9,6};
    vector<int> a(b,b+5);
    int l = a.size();
    int k =4;
    cout << "原数组为：";
    for(int i=0;i<l;i++){
        cout << a[i] <<" ";
    }
    cout << endl;
    int inde = topk(a,1,l,k);
    cout << "TOP-K 为：";
    for (int i=inde;i<=l;i++){
        cout << a[i-1] <<" ";
    }
    cout <<endl;
}
*/

//insert_sort

void insert_sort(int a[],int len){

    for(int i=1;i<len;i++){
        int insertvalue = a[i];
        int j = i-1;
        while(j>=0&&insertvalue<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = insertvalue;
    }
}

int main(){
    int a[] = {4,5,8,1,2,3};
    int len = sizeof(a)/sizeof(a[0]);
    insert_sort(a,len);
    for(int i=0;i<len;i++){
        cout << a[i] <<" ";
    }
    cout << endl;
    return 0;
}


